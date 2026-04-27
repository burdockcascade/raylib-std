# Raylib-Std
Raylib-Std is a modern C++20 header-only wrapper for the raylib game programming library. It provides a more idiomatic C++ developer experience while maintaining the simplicity and performance of the original C API.

## Key Features
- Idiomatic C++ Interfaces: Replaces raw C pointers and character arrays with modern alternatives like std::string_view, std::string, and std::span for safer and more flexible data handling.
- Header-Only: Easy to integrate into any project by simply including the single raylib-std.hpp header.
- Type-Safe Enums: Converts raylib’s global #define constants into scoped enum class types (e.g., KeyboardKey, ConfigFlags, MouseButton), improving code clarity and reducing namespace pollution.
- Namespace Protection: All wrapper functions and types are contained within the RaylibStd namespace to prevent naming conflicts.
- Modern Build Support: Includes out-of-the-box support for xmake and CMake, targeting the C++20 standard.

## Example
```cpp
#include <raylib-std.hpp>

int main() {
    // Uses std::string_view for the title
    RaylibStd::init_window(800, 450, "raylib-std [hello world]");
    RaylibStd::set_target_fps(60);

    while (!RaylibStd::window_should_close()) {
        RaylibStd::begin_drawing();
        RaylibStd::clear_background(RAYWHITE);
        
        // Modern C++ wrapper for drawing text
        RaylibStd::draw_text("Hello, Raylib-Std!", 190, 200, 40, VIOLET);
        
        RaylibStd::end_drawing();
    }

    RaylibStd::close_window();
    return 0;
}
```