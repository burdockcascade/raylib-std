import json
import re  # New import for regex
from jinja2 import Environment, FileSystemLoader

def to_snake_case_raylib(name):
    s = re.sub(r'(?<!^)(?=[A-Z])|(?<=[a-zA-Z])(?=\d)', '_', name).lower()
    s = (s.replace("2_d", "2d")
            .replace("3_d", "3d")
            .replace("f_p_s", "fps")
            .replace("v_r", "vr")
            .replace("c_r_c", "crc")
         )

    return s

def process_functions(raw_functions, enums):
    enum_names = {em['name'] for em in enums}
    processed_functions = []

    for func in raw_functions:
        params = func.get('params', [])
        mapped_params = []
        call_args = []
        has_varargs = False

        # ... (keep existing parameter processing logic) ...
        i = 0
        while i < len(params):
            param = params[i]
            ptype = param['type']
            pname = param['name']
            if ptype == "...":
                mapped_params.append("Args... args")
                call_args.append("args...")
                has_varargs = True
                i += 1
            elif ptype == "const char *":
                mapped_params.append(f"std::string_view {pname}")
                call_args.append(f"{pname}.data()")
                i += 1
            elif ptype in enum_names:
                mapped_params.append(f"{ptype} {pname}")
                call_args.append(f"std::to_underlying({pname})")
                i += 1
            else:
                is_span = False
                if i + 1 < len(params):
                    next_param = params[i + 1]
                    if "*" in ptype and "char" not in ptype and "void" not in ptype:
                        next_name_lower = next_param['name'].lower()
                        if next_param['type'] in ["int", "unsigned int"] and any(kw in next_name_lower for kw in ["count", "size", "length"]):
                            is_span = True
                if is_span:
                    next_param = params[i + 1]
                    base_type = ptype.replace("*", "", 1).strip()
                    mapped_params.append(f"std::span<{base_type}> {pname}")
                    call_args.append(f"{pname}.data()")
                    call_args.append(f"static_cast<{next_param['type']}>({pname}.size())")
                    i += 2
                else:
                    mapped_params.append(f"{ptype} {pname}")
                    call_args.append(pname)
                    i += 1

        raw_rtype = func['returnType']
        cpp_rtype = raw_rtype
        returns_string = False
        returns_enum = raw_rtype in enum_names

        if raw_rtype in ["const char *", "char *"]:
            cpp_rtype = "std::string"
            returns_string = True

        processed_functions.append({
            'name': to_snake_case_raylib(func['name']),
            'original_name': func['name'],
            'description': func.get('description', ''),
            'returnType': cpp_rtype,
            'raw_returnType': raw_rtype,
            'mapped_params': ", ".join(mapped_params),
            'call_args': ", ".join(call_args),
            'has_varargs': has_varargs,
            'is_nodiscard': cpp_rtype != "void",
            'returns_string': returns_string,
            'returns_enum': returns_enum
        })

    return processed_functions

def generate_wrapper(json_path, template_path, output_path):
    # Load the raylib metadata
    with open(json_path, 'r') as f:
        data = json.load(f)

    # Setup Jinja2 environment to load from the current directory
    env = Environment(loader=FileSystemLoader('.'))

    try:
        jt2_template = env.get_template(template_path)

        enums = data.get('enums', [])
        raw_functions = data.get('functions', [])

        # Process logic in python before passing to jinja
        processed_functions = process_functions(raw_functions, enums)

        # Render the template using the simplified lists
        output = jt2_template.render(
            functions=processed_functions,
            ems=enums
        )

        # Write the final C++ header
        with open(output_path, 'w') as f:
            f.write(output)

        print(f"Successfully generated {output_path}")

    except Exception as e:
        print(f"Error during generation: {e}")

if __name__ == "__main__":
    generate_wrapper('autogen/raylib6.json', 'autogen/raylib-std.hpp.jt2', 'include/raylib-std.hpp')