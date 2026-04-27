import json
from jinja2 import Environment, FileSystemLoader

def generate_wrapper(json_path, template_path, output_path):
    # Load the raylib metadata
    with open(json_path, 'r') as f:
        data = json.load(f)
    
    # Setup Jinja2 environment to load from the current directory
    env = Environment(loader=FileSystemLoader('.'))


    try:
        # Correct way to load the template file
        jt2_template = env.get_template(template_path)
        
        # Render the template using the 'functions' list from the JSON
        output = jt2_template.render(
            functions=data.get('functions', []),
            ems=data.get('enums', []) 
        )
        
        # Write the final C++ header
        with open(output_path, 'w') as f:
            f.write(output)
        
        print(f"Successfully generated {output_path}")
        
    except Exception as e:
        print(f"Error during generation: {e}")

if __name__ == "__main__":
    # Ensure these paths match your actual directory structure
    generate_wrapper('autogen/raylib6.json', 'autogen/raylib-std.hpp.jt2', 'include/raylib-std.hpp')