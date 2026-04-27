#include <raylib-std.hpp>

int main() {
    // 1. Initialize the window
    // Uses std::string_view for the title
    RaylibStd::init_window(800, 450, "raylib-std [hello world]");

    // 2. Set the target frames per second
    RaylibStd::set_target_fps(60);

    // 3. Main game loop
    // window_should_close() checks for ESC key or close icon
    while (!RaylibStd::window_should_close()) {

        // 4. Drawing block
        RaylibStd::begin_drawing();

        // Clear the background to white
        RaylibStd::clear_background(RAYWHITE);

        // Draw text using the C++ wrapper
        // Note: Colors like VIOLET and RAYWHITE are provided by the underlying raylib.h
        RaylibStd::draw_text("Hello, Raylib-Std!", 190, 200, 40, VIOLET);

        RaylibStd::end_drawing();
    }

    // 5. De-Initialization
    RaylibStd::close_window();

    return 0;
}