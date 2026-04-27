#pragma once
#include <string>
#include <string_view>
#include <span>
#include "raylib.h"

namespace RaylibStd {


    /**
    * @brief System/Window config flags
    */
    enum class ConfigFlags : int {
        FLAG_VSYNC_HINT = 64, // Set to try enabling V-Sync on GPU
        FLAG_FULLSCREEN_MODE = 2, // Set to run program in fullscreen
        FLAG_WINDOW_RESIZABLE = 4, // Set to allow resizable window
        FLAG_WINDOW_UNDECORATED = 8, // Set to disable window decoration (frame and buttons)
        FLAG_WINDOW_HIDDEN = 128, // Set to hide window
        FLAG_WINDOW_MINIMIZED = 512, // Set to minimize window (iconify)
        FLAG_WINDOW_MAXIMIZED = 1024, // Set to maximize window (expanded to monitor)
        FLAG_WINDOW_UNFOCUSED = 2048, // Set to window non focused
        FLAG_WINDOW_TOPMOST = 4096, // Set to window always on top
        FLAG_WINDOW_ALWAYS_RUN = 256, // Set to allow windows running while minimized
        FLAG_WINDOW_TRANSPARENT = 16, // Set to allow transparent framebuffer
        FLAG_WINDOW_HIGHDPI = 8192, // Set to support HighDPI
        FLAG_WINDOW_MOUSE_PASSTHROUGH = 16384, // Set to support mouse passthrough, only supported when FLAG_WINDOW_UNDECORATED
        FLAG_BORDERLESS_WINDOWED_MODE = 32768, // Set to run program in borderless windowed mode
        FLAG_MSAA_4X_HINT = 32, // Set to try enabling MSAA 4X
        FLAG_INTERLACED_HINT = 65536, // Set to try enabling interlaced video format (for V3D)
    };

    /**
    * @brief Trace log level
    */
    enum class TraceLogLevel : int {
        LOG_ALL = 0, // Display all logs
        LOG_TRACE = 1, // Trace logging, intended for internal use only
        LOG_DEBUG = 2, // Debug logging, used for internal debugging, it should be disabled on release builds
        LOG_INFO = 3, // Info logging, used for program execution info
        LOG_WARNING = 4, // Warning logging, used on recoverable failures
        LOG_ERROR = 5, // Error logging, used on unrecoverable failures
        LOG_FATAL = 6, // Fatal logging, used to abort program: exit(EXIT_FAILURE)
        LOG_NONE = 7, // Disable logging
    };

    /**
    * @brief Keyboard keys (US keyboard layout)
    */
    enum class KeyboardKey : int {
        KEY_NULL = 0, // Key: NULL, used for no key pressed
        KEY_APOSTROPHE = 39, // Key: '
        KEY_COMMA = 44, // Key: ,
        KEY_MINUS = 45, // Key: -
        KEY_PERIOD = 46, // Key: .
        KEY_SLASH = 47, // Key: /
        KEY_ZERO = 48, // Key: 0
        KEY_ONE = 49, // Key: 1
        KEY_TWO = 50, // Key: 2
        KEY_THREE = 51, // Key: 3
        KEY_FOUR = 52, // Key: 4
        KEY_FIVE = 53, // Key: 5
        KEY_SIX = 54, // Key: 6
        KEY_SEVEN = 55, // Key: 7
        KEY_EIGHT = 56, // Key: 8
        KEY_NINE = 57, // Key: 9
        KEY_SEMICOLON = 59, // Key: ;
        KEY_EQUAL = 61, // Key: =
        KEY_A = 65, // Key: A | a
        KEY_B = 66, // Key: B | b
        KEY_C = 67, // Key: C | c
        KEY_D = 68, // Key: D | d
        KEY_E = 69, // Key: E | e
        KEY_F = 70, // Key: F | f
        KEY_G = 71, // Key: G | g
        KEY_H = 72, // Key: H | h
        KEY_I = 73, // Key: I | i
        KEY_J = 74, // Key: J | j
        KEY_K = 75, // Key: K | k
        KEY_L = 76, // Key: L | l
        KEY_M = 77, // Key: M | m
        KEY_N = 78, // Key: N | n
        KEY_O = 79, // Key: O | o
        KEY_P = 80, // Key: P | p
        KEY_Q = 81, // Key: Q | q
        KEY_R = 82, // Key: R | r
        KEY_S = 83, // Key: S | s
        KEY_T = 84, // Key: T | t
        KEY_U = 85, // Key: U | u
        KEY_V = 86, // Key: V | v
        KEY_W = 87, // Key: W | w
        KEY_X = 88, // Key: X | x
        KEY_Y = 89, // Key: Y | y
        KEY_Z = 90, // Key: Z | z
        KEY_LEFT_BRACKET = 91, // Key: [
        KEY_BACKSLASH = 92, // Key: '\'
        KEY_RIGHT_BRACKET = 93, // Key: ]
        KEY_GRAVE = 96, // Key: `
        KEY_SPACE = 32, // Key: Space
        KEY_ESCAPE = 256, // Key: Esc
        KEY_ENTER = 257, // Key: Enter
        KEY_TAB = 258, // Key: Tab
        KEY_BACKSPACE = 259, // Key: Backspace
        KEY_INSERT = 260, // Key: Ins
        KEY_DELETE = 261, // Key: Del
        KEY_RIGHT = 262, // Key: Cursor right
        KEY_LEFT = 263, // Key: Cursor left
        KEY_DOWN = 264, // Key: Cursor down
        KEY_UP = 265, // Key: Cursor up
        KEY_PAGE_UP = 266, // Key: Page up
        KEY_PAGE_DOWN = 267, // Key: Page down
        KEY_HOME = 268, // Key: Home
        KEY_END = 269, // Key: End
        KEY_CAPS_LOCK = 280, // Key: Caps lock
        KEY_SCROLL_LOCK = 281, // Key: Scroll down
        KEY_NUM_LOCK = 282, // Key: Num lock
        KEY_PRINT_SCREEN = 283, // Key: Print screen
        KEY_PAUSE = 284, // Key: Pause
        KEY_F1 = 290, // Key: F1
        KEY_F2 = 291, // Key: F2
        KEY_F3 = 292, // Key: F3
        KEY_F4 = 293, // Key: F4
        KEY_F5 = 294, // Key: F5
        KEY_F6 = 295, // Key: F6
        KEY_F7 = 296, // Key: F7
        KEY_F8 = 297, // Key: F8
        KEY_F9 = 298, // Key: F9
        KEY_F10 = 299, // Key: F10
        KEY_F11 = 300, // Key: F11
        KEY_F12 = 301, // Key: F12
        KEY_LEFT_SHIFT = 340, // Key: Shift left
        KEY_LEFT_CONTROL = 341, // Key: Control left
        KEY_LEFT_ALT = 342, // Key: Alt left
        KEY_LEFT_SUPER = 343, // Key: Super left
        KEY_RIGHT_SHIFT = 344, // Key: Shift right
        KEY_RIGHT_CONTROL = 345, // Key: Control right
        KEY_RIGHT_ALT = 346, // Key: Alt right
        KEY_RIGHT_SUPER = 347, // Key: Super right
        KEY_KB_MENU = 348, // Key: KB menu
        KEY_KP_0 = 320, // Key: Keypad 0
        KEY_KP_1 = 321, // Key: Keypad 1
        KEY_KP_2 = 322, // Key: Keypad 2
        KEY_KP_3 = 323, // Key: Keypad 3
        KEY_KP_4 = 324, // Key: Keypad 4
        KEY_KP_5 = 325, // Key: Keypad 5
        KEY_KP_6 = 326, // Key: Keypad 6
        KEY_KP_7 = 327, // Key: Keypad 7
        KEY_KP_8 = 328, // Key: Keypad 8
        KEY_KP_9 = 329, // Key: Keypad 9
        KEY_KP_DECIMAL = 330, // Key: Keypad .
        KEY_KP_DIVIDE = 331, // Key: Keypad /
        KEY_KP_MULTIPLY = 332, // Key: Keypad *
        KEY_KP_SUBTRACT = 333, // Key: Keypad -
        KEY_KP_ADD = 334, // Key: Keypad +
        KEY_KP_ENTER = 335, // Key: Keypad Enter
        KEY_KP_EQUAL = 336, // Key: Keypad =
        KEY_BACK = 4, // Key: Android back button
        KEY_MENU = 5, // Key: Android menu button
        KEY_VOLUME_UP = 24, // Key: Android volume up button
        KEY_VOLUME_DOWN = 25, // Key: Android volume down button
    };

    /**
    * @brief Mouse buttons
    */
    enum class MouseButton : int {
        MOUSE_BUTTON_LEFT = 0, // Mouse button left
        MOUSE_BUTTON_RIGHT = 1, // Mouse button right
        MOUSE_BUTTON_MIDDLE = 2, // Mouse button middle (pressed wheel)
        MOUSE_BUTTON_SIDE = 3, // Mouse button side (advanced mouse device)
        MOUSE_BUTTON_EXTRA = 4, // Mouse button extra (advanced mouse device)
        MOUSE_BUTTON_FORWARD = 5, // Mouse button forward (advanced mouse device)
        MOUSE_BUTTON_BACK = 6, // Mouse button back (advanced mouse device)
    };

    /**
    * @brief Mouse cursor
    */
    enum class MouseCursor : int {
        MOUSE_CURSOR_DEFAULT = 0, // Default pointer shape
        MOUSE_CURSOR_ARROW = 1, // Arrow shape
        MOUSE_CURSOR_IBEAM = 2, // Text writing cursor shape
        MOUSE_CURSOR_CROSSHAIR = 3, // Cross shape
        MOUSE_CURSOR_POINTING_HAND = 4, // Pointing hand cursor
        MOUSE_CURSOR_RESIZE_EW = 5, // Horizontal resize/move arrow shape
        MOUSE_CURSOR_RESIZE_NS = 6, // Vertical resize/move arrow shape
        MOUSE_CURSOR_RESIZE_NWSE = 7, // Top-left to bottom-right diagonal resize/move arrow shape
        MOUSE_CURSOR_RESIZE_NESW = 8, // The top-right to bottom-left diagonal resize/move arrow shape
        MOUSE_CURSOR_RESIZE_ALL = 9, // The omnidirectional resize/move cursor shape
        MOUSE_CURSOR_NOT_ALLOWED = 10, // The operation-not-allowed shape
    };

    /**
    * @brief Gamepad buttons
    */
    enum class GamepadButton : int {
        GAMEPAD_BUTTON_UNKNOWN = 0, // Unknown button, for error checking
        GAMEPAD_BUTTON_LEFT_FACE_UP = 1, // Gamepad left DPAD up button
        GAMEPAD_BUTTON_LEFT_FACE_RIGHT = 2, // Gamepad left DPAD right button
        GAMEPAD_BUTTON_LEFT_FACE_DOWN = 3, // Gamepad left DPAD down button
        GAMEPAD_BUTTON_LEFT_FACE_LEFT = 4, // Gamepad left DPAD left button
        GAMEPAD_BUTTON_RIGHT_FACE_UP = 5, // Gamepad right button up (i.e. PS3: Triangle, Xbox: Y)
        GAMEPAD_BUTTON_RIGHT_FACE_RIGHT = 6, // Gamepad right button right (i.e. PS3: Circle, Xbox: B)
        GAMEPAD_BUTTON_RIGHT_FACE_DOWN = 7, // Gamepad right button down (i.e. PS3: Cross, Xbox: A)
        GAMEPAD_BUTTON_RIGHT_FACE_LEFT = 8, // Gamepad right button left (i.e. PS3: Square, Xbox: X)
        GAMEPAD_BUTTON_LEFT_TRIGGER_1 = 9, // Gamepad top/back trigger left (first), it could be a trailing button
        GAMEPAD_BUTTON_LEFT_TRIGGER_2 = 10, // Gamepad top/back trigger left (second), it could be a trailing button
        GAMEPAD_BUTTON_RIGHT_TRIGGER_1 = 11, // Gamepad top/back trigger right (first), it could be a trailing button
        GAMEPAD_BUTTON_RIGHT_TRIGGER_2 = 12, // Gamepad top/back trigger right (second), it could be a trailing button
        GAMEPAD_BUTTON_MIDDLE_LEFT = 13, // Gamepad center buttons, left one (i.e. PS3: Select)
        GAMEPAD_BUTTON_MIDDLE = 14, // Gamepad center buttons, middle one (i.e. PS3: PS, Xbox: XBOX)
        GAMEPAD_BUTTON_MIDDLE_RIGHT = 15, // Gamepad center buttons, right one (i.e. PS3: Start)
        GAMEPAD_BUTTON_LEFT_THUMB = 16, // Gamepad joystick pressed button left
        GAMEPAD_BUTTON_RIGHT_THUMB = 17, // Gamepad joystick pressed button right
    };

    /**
    * @brief Gamepad axes
    */
    enum class GamepadAxis : int {
        GAMEPAD_AXIS_LEFT_X = 0, // Gamepad left stick X axis
        GAMEPAD_AXIS_LEFT_Y = 1, // Gamepad left stick Y axis
        GAMEPAD_AXIS_RIGHT_X = 2, // Gamepad right stick X axis
        GAMEPAD_AXIS_RIGHT_Y = 3, // Gamepad right stick Y axis
        GAMEPAD_AXIS_LEFT_TRIGGER = 4, // Gamepad back trigger left, pressure level: [1..-1]
        GAMEPAD_AXIS_RIGHT_TRIGGER = 5, // Gamepad back trigger right, pressure level: [1..-1]
    };

    /**
    * @brief Material map index
    */
    enum class MaterialMapIndex : int {
        MATERIAL_MAP_ALBEDO = 0, // Albedo material (same as: MATERIAL_MAP_DIFFUSE)
        MATERIAL_MAP_METALNESS = 1, // Metalness material (same as: MATERIAL_MAP_SPECULAR)
        MATERIAL_MAP_NORMAL = 2, // Normal material
        MATERIAL_MAP_ROUGHNESS = 3, // Roughness material
        MATERIAL_MAP_OCCLUSION = 4, // Ambient occlusion material
        MATERIAL_MAP_EMISSION = 5, // Emission material
        MATERIAL_MAP_HEIGHT = 6, // Heightmap material
        MATERIAL_MAP_CUBEMAP = 7, // Cubemap material (NOTE: Uses GL_TEXTURE_CUBE_MAP)
        MATERIAL_MAP_IRRADIANCE = 8, // Irradiance material (NOTE: Uses GL_TEXTURE_CUBE_MAP)
        MATERIAL_MAP_PREFILTER = 9, // Prefilter material (NOTE: Uses GL_TEXTURE_CUBE_MAP)
        MATERIAL_MAP_BRDF = 10, // Brdf material
    };

    /**
    * @brief Shader location index
    */
    enum class ShaderLocationIndex : int {
        SHADER_LOC_VERTEX_POSITION = 0, // Shader location: vertex attribute: position
        SHADER_LOC_VERTEX_TEXCOORD01 = 1, // Shader location: vertex attribute: texcoord01
        SHADER_LOC_VERTEX_TEXCOORD02 = 2, // Shader location: vertex attribute: texcoord02
        SHADER_LOC_VERTEX_NORMAL = 3, // Shader location: vertex attribute: normal
        SHADER_LOC_VERTEX_TANGENT = 4, // Shader location: vertex attribute: tangent
        SHADER_LOC_VERTEX_COLOR = 5, // Shader location: vertex attribute: color
        SHADER_LOC_MATRIX_MVP = 6, // Shader location: matrix uniform: model-view-projection
        SHADER_LOC_MATRIX_VIEW = 7, // Shader location: matrix uniform: view (camera transform)
        SHADER_LOC_MATRIX_PROJECTION = 8, // Shader location: matrix uniform: projection
        SHADER_LOC_MATRIX_MODEL = 9, // Shader location: matrix uniform: model (transform)
        SHADER_LOC_MATRIX_NORMAL = 10, // Shader location: matrix uniform: normal
        SHADER_LOC_VECTOR_VIEW = 11, // Shader location: vector uniform: view
        SHADER_LOC_COLOR_DIFFUSE = 12, // Shader location: vector uniform: diffuse color
        SHADER_LOC_COLOR_SPECULAR = 13, // Shader location: vector uniform: specular color
        SHADER_LOC_COLOR_AMBIENT = 14, // Shader location: vector uniform: ambient color
        SHADER_LOC_MAP_ALBEDO = 15, // Shader location: sampler2d texture: albedo (same as: SHADER_LOC_MAP_DIFFUSE)
        SHADER_LOC_MAP_METALNESS = 16, // Shader location: sampler2d texture: metalness (same as: SHADER_LOC_MAP_SPECULAR)
        SHADER_LOC_MAP_NORMAL = 17, // Shader location: sampler2d texture: normal
        SHADER_LOC_MAP_ROUGHNESS = 18, // Shader location: sampler2d texture: roughness
        SHADER_LOC_MAP_OCCLUSION = 19, // Shader location: sampler2d texture: occlusion
        SHADER_LOC_MAP_EMISSION = 20, // Shader location: sampler2d texture: emission
        SHADER_LOC_MAP_HEIGHT = 21, // Shader location: sampler2d texture: heightmap
        SHADER_LOC_MAP_CUBEMAP = 22, // Shader location: samplerCube texture: cubemap
        SHADER_LOC_MAP_IRRADIANCE = 23, // Shader location: samplerCube texture: irradiance
        SHADER_LOC_MAP_PREFILTER = 24, // Shader location: samplerCube texture: prefilter
        SHADER_LOC_MAP_BRDF = 25, // Shader location: sampler2d texture: brdf
        SHADER_LOC_VERTEX_BONEIDS = 26, // Shader location: vertex attribute: bone indices
        SHADER_LOC_VERTEX_BONEWEIGHTS = 27, // Shader location: vertex attribute: bone weights
        SHADER_LOC_MATRIX_BONETRANSFORMS = 28, // Shader location: matrix attribute: bone transforms (animation)
        SHADER_LOC_VERTEX_INSTANCETRANSFORM = 29, // Shader location: vertex attribute: instance transforms
    };

    /**
    * @brief Shader uniform data type
    */
    enum class ShaderUniformDataType : int {
        SHADER_UNIFORM_FLOAT = 0, // Shader uniform type: float
        SHADER_UNIFORM_VEC2 = 1, // Shader uniform type: vec2 (2 float)
        SHADER_UNIFORM_VEC3 = 2, // Shader uniform type: vec3 (3 float)
        SHADER_UNIFORM_VEC4 = 3, // Shader uniform type: vec4 (4 float)
        SHADER_UNIFORM_INT = 4, // Shader uniform type: int
        SHADER_UNIFORM_IVEC2 = 5, // Shader uniform type: ivec2 (2 int)
        SHADER_UNIFORM_IVEC3 = 6, // Shader uniform type: ivec3 (3 int)
        SHADER_UNIFORM_IVEC4 = 7, // Shader uniform type: ivec4 (4 int)
        SHADER_UNIFORM_UINT = 8, // Shader uniform type: unsigned int
        SHADER_UNIFORM_UIVEC2 = 9, // Shader uniform type: uivec2 (2 unsigned int)
        SHADER_UNIFORM_UIVEC3 = 10, // Shader uniform type: uivec3 (3 unsigned int)
        SHADER_UNIFORM_UIVEC4 = 11, // Shader uniform type: uivec4 (4 unsigned int)
        SHADER_UNIFORM_SAMPLER2D = 12, // Shader uniform type: sampler2d
    };

    /**
    * @brief Shader attribute data types
    */
    enum class ShaderAttributeDataType : int {
        SHADER_ATTRIB_FLOAT = 0, // Shader attribute type: float
        SHADER_ATTRIB_VEC2 = 1, // Shader attribute type: vec2 (2 float)
        SHADER_ATTRIB_VEC3 = 2, // Shader attribute type: vec3 (3 float)
        SHADER_ATTRIB_VEC4 = 3, // Shader attribute type: vec4 (4 float)
    };

    /**
    * @brief Pixel formats
    */
    enum class PixelFormat : int {
        PIXELFORMAT_UNCOMPRESSED_GRAYSCALE = 1, // 8 bit per pixel (no alpha)
        PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA = 2, // 8*2 bpp (2 channels)
        PIXELFORMAT_UNCOMPRESSED_R5G6B5 = 3, // 16 bpp
        PIXELFORMAT_UNCOMPRESSED_R8G8B8 = 4, // 24 bpp
        PIXELFORMAT_UNCOMPRESSED_R5G5B5A1 = 5, // 16 bpp (1 bit alpha)
        PIXELFORMAT_UNCOMPRESSED_R4G4B4A4 = 6, // 16 bpp (4 bit alpha)
        PIXELFORMAT_UNCOMPRESSED_R8G8B8A8 = 7, // 32 bpp
        PIXELFORMAT_UNCOMPRESSED_R32 = 8, // 32 bpp (1 channel - float)
        PIXELFORMAT_UNCOMPRESSED_R32G32B32 = 9, // 32*3 bpp (3 channels - float)
        PIXELFORMAT_UNCOMPRESSED_R32G32B32A32 = 10, // 32*4 bpp (4 channels - float)
        PIXELFORMAT_UNCOMPRESSED_R16 = 11, // 16 bpp (1 channel - half float)
        PIXELFORMAT_UNCOMPRESSED_R16G16B16 = 12, // 16*3 bpp (3 channels - half float)
        PIXELFORMAT_UNCOMPRESSED_R16G16B16A16 = 13, // 16*4 bpp (4 channels - half float)
        PIXELFORMAT_COMPRESSED_DXT1_RGB = 14, // 4 bpp (no alpha)
        PIXELFORMAT_COMPRESSED_DXT1_RGBA = 15, // 4 bpp (1 bit alpha)
        PIXELFORMAT_COMPRESSED_DXT3_RGBA = 16, // 8 bpp
        PIXELFORMAT_COMPRESSED_DXT5_RGBA = 17, // 8 bpp
        PIXELFORMAT_COMPRESSED_ETC1_RGB = 18, // 4 bpp
        PIXELFORMAT_COMPRESSED_ETC2_RGB = 19, // 4 bpp
        PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA = 20, // 8 bpp
        PIXELFORMAT_COMPRESSED_PVRT_RGB = 21, // 4 bpp
        PIXELFORMAT_COMPRESSED_PVRT_RGBA = 22, // 4 bpp
        PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA = 23, // 8 bpp
        PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA = 24, // 2 bpp
    };

    /**
    * @brief Texture parameters: filter mode
    */
    enum class TextureFilter : int {
        TEXTURE_FILTER_POINT = 0, // No filter, pixel approximation
        TEXTURE_FILTER_BILINEAR = 1, // Linear filtering
        TEXTURE_FILTER_TRILINEAR = 2, // Trilinear filtering (linear with mipmaps)
        TEXTURE_FILTER_ANISOTROPIC_4X = 3, // Anisotropic filtering 4x
        TEXTURE_FILTER_ANISOTROPIC_8X = 4, // Anisotropic filtering 8x
        TEXTURE_FILTER_ANISOTROPIC_16X = 5, // Anisotropic filtering 16x
    };

    /**
    * @brief Texture parameters: wrap mode
    */
    enum class TextureWrap : int {
        TEXTURE_WRAP_REPEAT = 0, // Repeats texture in tiled mode
        TEXTURE_WRAP_CLAMP = 1, // Clamps texture to edge pixel in tiled mode
        TEXTURE_WRAP_MIRROR_REPEAT = 2, // Mirrors and repeats the texture in tiled mode
        TEXTURE_WRAP_MIRROR_CLAMP = 3, // Mirrors and clamps to border the texture in tiled mode
    };

    /**
    * @brief Cubemap layouts
    */
    enum class CubemapLayout : int {
        CUBEMAP_LAYOUT_AUTO_DETECT = 0, // Automatically detect layout type
        CUBEMAP_LAYOUT_LINE_VERTICAL = 1, // Layout is defined by a vertical line with faces
        CUBEMAP_LAYOUT_LINE_HORIZONTAL = 2, // Layout is defined by a horizontal line with faces
        CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR = 3, // Layout is defined by a 3x4 cross with cubemap faces
        CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE = 4, // Layout is defined by a 4x3 cross with cubemap faces
    };

    /**
    * @brief Font type, defines generation method
    */
    enum class FontType : int {
        FONT_DEFAULT = 0, // Default font generation, anti-aliased
        FONT_BITMAP = 1, // Bitmap font generation, no anti-aliasing
        FONT_SDF = 2, // SDF font generation, requires external shader
    };

    /**
    * @brief Color blending modes (pre-defined)
    */
    enum class BlendMode : int {
        BLEND_ALPHA = 0, // Blend textures considering alpha (default)
        BLEND_ADDITIVE = 1, // Blend textures adding colors
        BLEND_MULTIPLIED = 2, // Blend textures multiplying colors
        BLEND_ADD_COLORS = 3, // Blend textures adding colors (alternative)
        BLEND_SUBTRACT_COLORS = 4, // Blend textures subtracting colors (alternative)
        BLEND_ALPHA_PREMULTIPLY = 5, // Blend premultiplied textures considering alpha
        BLEND_CUSTOM = 6, // Blend textures using custom src/dst factors (use rlSetBlendFactors())
        BLEND_CUSTOM_SEPARATE = 7, // Blend textures using custom rgb/alpha separate src/dst factors (use rlSetBlendFactorsSeparate())
    };

    /**
    * @brief Gesture
    */
    enum class Gesture : int {
        GESTURE_NONE = 0, // No gesture
        GESTURE_TAP = 1, // Tap gesture
        GESTURE_DOUBLETAP = 2, // Double tap gesture
        GESTURE_HOLD = 4, // Hold gesture
        GESTURE_DRAG = 8, // Drag gesture
        GESTURE_SWIPE_RIGHT = 16, // Swipe right gesture
        GESTURE_SWIPE_LEFT = 32, // Swipe left gesture
        GESTURE_SWIPE_UP = 64, // Swipe up gesture
        GESTURE_SWIPE_DOWN = 128, // Swipe down gesture
        GESTURE_PINCH_IN = 256, // Pinch in gesture
        GESTURE_PINCH_OUT = 512, // Pinch out gesture
    };

    /**
    * @brief Camera system modes
    */
    enum class CameraMode : int {
        CAMERA_CUSTOM = 0, // Camera custom, controlled by user (UpdateCamera() does nothing)
        CAMERA_FREE = 1, // Camera free mode
        CAMERA_ORBITAL = 2, // Camera orbital, around target, zoom supported
        CAMERA_FIRST_PERSON = 3, // Camera first person
        CAMERA_THIRD_PERSON = 4, // Camera third person
    };

    /**
    * @brief Camera projection
    */
    enum class CameraProjection : int {
        CAMERA_PERSPECTIVE = 0, // Perspective projection
        CAMERA_ORTHOGRAPHIC = 1, // Orthographic projection
    };

    /**
    * @brief N-patch layout
    */
    enum class NPatchLayout : int {
        NPATCH_NINE_PATCH = 0, // Npatch layout: 3x3 tiles
        NPATCH_THREE_PATCH_VERTICAL = 1, // Npatch layout: 1x3 tiles
        NPATCH_THREE_PATCH_HORIZONTAL = 2, // Npatch layout: 3x1 tiles
    };



    /**
     * @brief Initialize window and OpenGL context
     */
    inline void init_window(int width, int height, std::string_view title) {
        ::InitWindow(width, height, title.data());
    }

    /**
     * @brief Close window and unload OpenGL context
     */
    inline void close_window() {
        ::CloseWindow();
    }

    /**
     * @brief Check if application should close (KEY_ESCAPE pressed or windows close icon clicked)
     */
    [[nodiscard]] inline bool window_should_close() {
        return ::WindowShouldClose();
    }

    /**
     * @brief Check if window has been initialized successfully
     */
    [[nodiscard]] inline bool is_window_ready() {
        return ::IsWindowReady();
    }

    /**
     * @brief Check if window is currently fullscreen
     */
    [[nodiscard]] inline bool is_window_fullscreen() {
        return ::IsWindowFullscreen();
    }

    /**
     * @brief Check if window is currently hidden
     */
    [[nodiscard]] inline bool is_window_hidden() {
        return ::IsWindowHidden();
    }

    /**
     * @brief Check if window is currently minimized
     */
    [[nodiscard]] inline bool is_window_minimized() {
        return ::IsWindowMinimized();
    }

    /**
     * @brief Check if window is currently maximized
     */
    [[nodiscard]] inline bool is_window_maximized() {
        return ::IsWindowMaximized();
    }

    /**
     * @brief Check if window is currently focused
     */
    [[nodiscard]] inline bool is_window_focused() {
        return ::IsWindowFocused();
    }

    /**
     * @brief Check if window has been resized last frame
     */
    [[nodiscard]] inline bool is_window_resized() {
        return ::IsWindowResized();
    }

    /**
     * @brief Check if one specific window flag is enabled
     */
    [[nodiscard]] inline bool is_window_state(unsigned int flag) {
        return ::IsWindowState(flag);
    }

    /**
     * @brief Set window configuration state using flags
     */
    inline void set_window_state(unsigned int flags) {
        ::SetWindowState(flags);
    }

    /**
     * @brief Clear window configuration state flags
     */
    inline void clear_window_state(unsigned int flags) {
        ::ClearWindowState(flags);
    }

    /**
     * @brief Toggle window state: fullscreen/windowed, resizes monitor to match window resolution
     */
    inline void toggle_fullscreen() {
        ::ToggleFullscreen();
    }

    /**
     * @brief Toggle window state: borderless windowed, resizes window to match monitor resolution
     */
    inline void toggle_borderless_windowed() {
        ::ToggleBorderlessWindowed();
    }

    /**
     * @brief Set window state: maximized, if resizable
     */
    inline void maximize_window() {
        ::MaximizeWindow();
    }

    /**
     * @brief Set window state: minimized, if resizable
     */
    inline void minimize_window() {
        ::MinimizeWindow();
    }

    /**
     * @brief Restore window from being minimized/maximized
     */
    inline void restore_window() {
        ::RestoreWindow();
    }

    /**
     * @brief Set icon for window (single image, RGBA 32bit)
     */
    inline void set_window_icon(Image image) {
        ::SetWindowIcon(image);
    }

    /**
     * @brief Set icon for window (multiple images, RGBA 32bit)
     */
    inline void set_window_icons(std::span<Image> images) {
        ::SetWindowIcons(images.data(), static_cast<int>(images.size()));
    }

    /**
     * @brief Set title for window
     */
    inline void set_window_title(std::string_view title) {
        ::SetWindowTitle(title.data());
    }

    /**
     * @brief Set window position on screen
     */
    inline void set_window_position(int x, int y) {
        ::SetWindowPosition(x, y);
    }

    /**
     * @brief Set monitor for the current window
     */
    inline void set_window_monitor(int monitor) {
        ::SetWindowMonitor(monitor);
    }

    /**
     * @brief Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
     */
    inline void set_window_min_size(int width, int height) {
        ::SetWindowMinSize(width, height);
    }

    /**
     * @brief Set window maximum dimensions (for FLAG_WINDOW_RESIZABLE)
     */
    inline void set_window_max_size(int width, int height) {
        ::SetWindowMaxSize(width, height);
    }

    /**
     * @brief Set window dimensions
     */
    inline void set_window_size(int width, int height) {
        ::SetWindowSize(width, height);
    }

    /**
     * @brief Set window opacity [0.0f..1.0f]
     */
    inline void set_window_opacity(float opacity) {
        ::SetWindowOpacity(opacity);
    }

    /**
     * @brief Set window focused
     */
    inline void set_window_focused() {
        ::SetWindowFocused();
    }

    /**
     * @brief Get native window handle
     */
    [[nodiscard]] inline void * get_window_handle() {
        return ::GetWindowHandle();
    }

    /**
     * @brief Get current screen width
     */
    [[nodiscard]] inline int get_screen_width() {
        return ::GetScreenWidth();
    }

    /**
     * @brief Get current screen height
     */
    [[nodiscard]] inline int get_screen_height() {
        return ::GetScreenHeight();
    }

    /**
     * @brief Get current render width (it considers HiDPI)
     */
    [[nodiscard]] inline int get_render_width() {
        return ::GetRenderWidth();
    }

    /**
     * @brief Get current render height (it considers HiDPI)
     */
    [[nodiscard]] inline int get_render_height() {
        return ::GetRenderHeight();
    }

    /**
     * @brief Get number of connected monitors
     */
    [[nodiscard]] inline int get_monitor_count() {
        return ::GetMonitorCount();
    }

    /**
     * @brief Get current monitor where window is placed
     */
    [[nodiscard]] inline int get_current_monitor() {
        return ::GetCurrentMonitor();
    }

    /**
     * @brief Get specified monitor position
     */
    [[nodiscard]] inline Vector2 get_monitor_position(int monitor) {
        return ::GetMonitorPosition(monitor);
    }

    /**
     * @brief Get specified monitor width (current video mode used by monitor)
     */
    [[nodiscard]] inline int get_monitor_width(int monitor) {
        return ::GetMonitorWidth(monitor);
    }

    /**
     * @brief Get specified monitor height (current video mode used by monitor)
     */
    [[nodiscard]] inline int get_monitor_height(int monitor) {
        return ::GetMonitorHeight(monitor);
    }

    /**
     * @brief Get specified monitor physical width in millimetres
     */
    [[nodiscard]] inline int get_monitor_physical_width(int monitor) {
        return ::GetMonitorPhysicalWidth(monitor);
    }

    /**
     * @brief Get specified monitor physical height in millimetres
     */
    [[nodiscard]] inline int get_monitor_physical_height(int monitor) {
        return ::GetMonitorPhysicalHeight(monitor);
    }

    /**
     * @brief Get specified monitor refresh rate
     */
    [[nodiscard]] inline int get_monitor_refresh_rate(int monitor) {
        return ::GetMonitorRefreshRate(monitor);
    }

    /**
     * @brief Get window position XY on monitor
     */
    [[nodiscard]] inline Vector2 get_window_position() {
        return ::GetWindowPosition();
    }

    /**
     * @brief Get window scale DPI factor
     */
    [[nodiscard]] inline Vector2 get_window_scale_d_p_i() {
        return ::GetWindowScaleDPI();
    }

    /**
     * @brief Get the human-readable, UTF-8 encoded name of the specified monitor
     */
    [[nodiscard]] inline std::string get_monitor_name(int monitor) {
        const char* _ret = ::GetMonitorName(monitor);
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Set clipboard text content
     */
    inline void set_clipboard_text(std::string_view text) {
        ::SetClipboardText(text.data());
    }

    /**
     * @brief Get clipboard text content
     */
    [[nodiscard]] inline std::string get_clipboard_text() {
        const char* _ret = ::GetClipboardText();
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Get clipboard image content
     */
    [[nodiscard]] inline Image get_clipboard_image() {
        return ::GetClipboardImage();
    }

    /**
     * @brief Enable waiting for events on EndDrawing(), no automatic event polling
     */
    inline void enable_event_waiting() {
        ::EnableEventWaiting();
    }

    /**
     * @brief Disable waiting for events on EndDrawing(), automatic events polling
     */
    inline void disable_event_waiting() {
        ::DisableEventWaiting();
    }

    /**
     * @brief Shows cursor
     */
    inline void show_cursor() {
        ::ShowCursor();
    }

    /**
     * @brief Hides cursor
     */
    inline void hide_cursor() {
        ::HideCursor();
    }

    /**
     * @brief Check if cursor is not visible
     */
    [[nodiscard]] inline bool is_cursor_hidden() {
        return ::IsCursorHidden();
    }

    /**
     * @brief Enables cursor (unlock cursor)
     */
    inline void enable_cursor() {
        ::EnableCursor();
    }

    /**
     * @brief Disables cursor (lock cursor)
     */
    inline void disable_cursor() {
        ::DisableCursor();
    }

    /**
     * @brief Check if cursor is on the screen
     */
    [[nodiscard]] inline bool is_cursor_on_screen() {
        return ::IsCursorOnScreen();
    }

    /**
     * @brief Set background color (framebuffer clear color)
     */
    inline void clear_background(Color color) {
        ::ClearBackground(color);
    }

    /**
     * @brief Setup canvas (framebuffer) to start drawing
     */
    inline void begin_drawing() {
        ::BeginDrawing();
    }

    /**
     * @brief End canvas drawing and swap buffers (double buffering)
     */
    inline void end_drawing() {
        ::EndDrawing();
    }

    /**
     * @brief Begin 2D mode with custom camera (2D)
     */
    inline void begin_mode_2d(Camera2D camera) {
        ::BeginMode2D(camera);
    }

    /**
     * @brief Ends 2D mode with custom camera
     */
    inline void end_mode_2d() {
        ::EndMode2D();
    }

    /**
     * @brief Begin 3D mode with custom camera (3D)
     */
    inline void begin_mode_3d(Camera3D camera) {
        ::BeginMode3D(camera);
    }

    /**
     * @brief Ends 3D mode and returns to default 2D orthographic mode
     */
    inline void end_mode_3d() {
        ::EndMode3D();
    }

    /**
     * @brief Begin drawing to render texture
     */
    inline void begin_texture_mode(RenderTexture2D target) {
        ::BeginTextureMode(target);
    }

    /**
     * @brief Ends drawing to render texture
     */
    inline void end_texture_mode() {
        ::EndTextureMode();
    }

    /**
     * @brief Begin custom shader drawing
     */
    inline void begin_shader_mode(Shader shader) {
        ::BeginShaderMode(shader);
    }

    /**
     * @brief End custom shader drawing (use default shader)
     */
    inline void end_shader_mode() {
        ::EndShaderMode();
    }

    /**
     * @brief Begin blending mode (alpha, additive, multiplied, subtract, custom)
     */
    inline void begin_blend_mode(int mode) {
        ::BeginBlendMode(mode);
    }

    /**
     * @brief End blending mode (reset to default: alpha blending)
     */
    inline void end_blend_mode() {
        ::EndBlendMode();
    }

    /**
     * @brief Begin scissor mode (define screen area for following drawing)
     */
    inline void begin_scissor_mode(int x, int y, int width, int height) {
        ::BeginScissorMode(x, y, width, height);
    }

    /**
     * @brief End scissor mode
     */
    inline void end_scissor_mode() {
        ::EndScissorMode();
    }

    /**
     * @brief Begin stereo rendering (requires VR simulator)
     */
    inline void begin_vr_stereo_mode(VrStereoConfig config) {
        ::BeginVrStereoMode(config);
    }

    /**
     * @brief End stereo rendering (requires VR simulator)
     */
    inline void end_vr_stereo_mode() {
        ::EndVrStereoMode();
    }

    /**
     * @brief Load VR stereo config for VR simulator device parameters
     */
    [[nodiscard]] inline VrStereoConfig load_vr_stereo_config(VrDeviceInfo device) {
        return ::LoadVrStereoConfig(device);
    }

    /**
     * @brief Unload VR stereo config
     */
    inline void unload_vr_stereo_config(VrStereoConfig config) {
        ::UnloadVrStereoConfig(config);
    }

    /**
     * @brief Load shader from files and bind default locations
     */
    [[nodiscard]] inline Shader load_shader(std::string_view vsFileName, std::string_view fsFileName) {
        return ::LoadShader(vsFileName.data(), fsFileName.data());
    }

    /**
     * @brief Load shader from code strings and bind default locations
     */
    [[nodiscard]] inline Shader load_shader_from_memory(std::string_view vsCode, std::string_view fsCode) {
        return ::LoadShaderFromMemory(vsCode.data(), fsCode.data());
    }

    /**
     * @brief Check if a shader is valid (loaded on GPU)
     */
    [[nodiscard]] inline bool is_shader_valid(Shader shader) {
        return ::IsShaderValid(shader);
    }

    /**
     * @brief Get shader uniform location
     */
    [[nodiscard]] inline int get_shader_location(Shader shader, std::string_view uniformName) {
        return ::GetShaderLocation(shader, uniformName.data());
    }

    /**
     * @brief Get shader attribute location
     */
    [[nodiscard]] inline int get_shader_location_attrib(Shader shader, std::string_view attribName) {
        return ::GetShaderLocationAttrib(shader, attribName.data());
    }

    /**
     * @brief Set shader uniform value
     */
    inline void set_shader_value(Shader shader, int locIndex, const void * value, int uniformType) {
        ::SetShaderValue(shader, locIndex, value, uniformType);
    }

    /**
     * @brief Set shader uniform value vector
     */
    inline void set_shader_value_v(Shader shader, int locIndex, const void * value, int uniformType, int count) {
        ::SetShaderValueV(shader, locIndex, value, uniformType, count);
    }

    /**
     * @brief Set shader uniform value (matrix 4x4)
     */
    inline void set_shader_value_matrix(Shader shader, int locIndex, Matrix mat) {
        ::SetShaderValueMatrix(shader, locIndex, mat);
    }

    /**
     * @brief Set shader uniform value and bind the texture (sampler2d)
     */
    inline void set_shader_value_texture(Shader shader, int locIndex, Texture2D texture) {
        ::SetShaderValueTexture(shader, locIndex, texture);
    }

    /**
     * @brief Unload shader from GPU memory (VRAM)
     */
    inline void unload_shader(Shader shader) {
        ::UnloadShader(shader);
    }

    /**
     * @brief Get a ray trace from screen position (i.e mouse)
     */
    [[nodiscard]] inline Ray get_screen_to_world_ray(Vector2 position, Camera camera) {
        return ::GetScreenToWorldRay(position, camera);
    }

    /**
     * @brief Get a ray trace from screen position (i.e mouse) in a viewport
     */
    [[nodiscard]] inline Ray get_screen_to_world_ray_ex(Vector2 position, Camera camera, int width, int height) {
        return ::GetScreenToWorldRayEx(position, camera, width, height);
    }

    /**
     * @brief Get the screen space position for a 3d world space position
     */
    [[nodiscard]] inline Vector2 get_world_to_screen(Vector3 position, Camera camera) {
        return ::GetWorldToScreen(position, camera);
    }

    /**
     * @brief Get size position for a 3d world space position
     */
    [[nodiscard]] inline Vector2 get_world_to_screen_ex(Vector3 position, Camera camera, int width, int height) {
        return ::GetWorldToScreenEx(position, camera, width, height);
    }

    /**
     * @brief Get the screen space position for a 2d camera world space position
     */
    [[nodiscard]] inline Vector2 get_world_to_screen_2d(Vector2 position, Camera2D camera) {
        return ::GetWorldToScreen2D(position, camera);
    }

    /**
     * @brief Get the world space position for a 2d camera screen space position
     */
    [[nodiscard]] inline Vector2 get_screen_to_world_2d(Vector2 position, Camera2D camera) {
        return ::GetScreenToWorld2D(position, camera);
    }

    /**
     * @brief Get camera transform matrix (view matrix)
     */
    [[nodiscard]] inline Matrix get_camera_matrix(Camera camera) {
        return ::GetCameraMatrix(camera);
    }

    /**
     * @brief Get camera 2d transform matrix
     */
    [[nodiscard]] inline Matrix get_camera_matrix_2d(Camera2D camera) {
        return ::GetCameraMatrix2D(camera);
    }

    /**
     * @brief Set target FPS (maximum)
     */
    inline void set_target_fps(int fps) {
        ::SetTargetFPS(fps);
    }

    /**
     * @brief Get time in seconds for last frame drawn (delta time)
     */
    [[nodiscard]] inline float get_frame_time() {
        return ::GetFrameTime();
    }

    /**
     * @brief Get elapsed time in seconds since InitWindow()
     */
    [[nodiscard]] inline double get_time() {
        return ::GetTime();
    }

    /**
     * @brief Get current FPS
     */
    [[nodiscard]] inline int get_fps() {
        return ::GetFPS();
    }

    /**
     * @brief Swap back buffer with front buffer (screen drawing)
     */
    inline void swap_screen_buffer() {
        ::SwapScreenBuffer();
    }

    /**
     * @brief Register all input events
     */
    inline void poll_input_events() {
        ::PollInputEvents();
    }

    /**
     * @brief Wait for some time (halt program execution)
     */
    inline void wait_time(double seconds) {
        ::WaitTime(seconds);
    }

    /**
     * @brief Set the seed for the random number generator
     */
    inline void set_random_seed(unsigned int seed) {
        ::SetRandomSeed(seed);
    }

    /**
     * @brief Get a random value between min and max (both included)
     */
    [[nodiscard]] inline int get_random_value(int min, int max) {
        return ::GetRandomValue(min, max);
    }

    /**
     * @brief Load random values sequence, no values repeated
     */
    [[nodiscard]] inline int * load_random_sequence(unsigned int count, int min, int max) {
        return ::LoadRandomSequence(count, min, max);
    }

    /**
     * @brief Unload random values sequence
     */
    inline void unload_random_sequence(int * sequence) {
        ::UnloadRandomSequence(sequence);
    }

    /**
     * @brief Takes a screenshot of current screen (filename extension defines format)
     */
    inline void take_screenshot(std::string_view fileName) {
        ::TakeScreenshot(fileName.data());
    }

    /**
     * @brief Setup init configuration flags (view FLAGS)
     */
    inline void set_config_flags(unsigned int flags) {
        ::SetConfigFlags(flags);
    }

    /**
     * @brief Open URL with default system browser (if available)
     */
    inline void open_u_r_l(std::string_view url) {
        ::OpenURL(url.data());
    }

    /**
     * @brief Set the current threshold (minimum) log level
     */
    inline void set_trace_log_level(int logLevel) {
        ::SetTraceLogLevel(logLevel);
    }

    /**
     * @brief Show trace log messages (LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR...)
     */
     template <typename... Args> inline void trace_log(int logLevel, std::string_view text, Args... args) {
        ::TraceLog(logLevel, text.data(), args...);
    }

    /**
     * @brief Set custom trace log
     */
    inline void set_trace_log_callback(TraceLogCallback callback) {
        ::SetTraceLogCallback(callback);
    }

    /**
     * @brief Internal memory allocator
     */
    [[nodiscard]] inline void * mem_alloc(unsigned int size) {
        return ::MemAlloc(size);
    }

    /**
     * @brief Internal memory reallocator
     */
    [[nodiscard]] inline void * mem_realloc(void * ptr, unsigned int size) {
        return ::MemRealloc(ptr, size);
    }

    /**
     * @brief Internal memory free
     */
    inline void mem_free(void * ptr) {
        ::MemFree(ptr);
    }

    /**
     * @brief Load file data as byte array (read)
     */
    [[nodiscard]] inline unsigned char * load_file_data(std::string_view fileName, int * dataSize) {
        return ::LoadFileData(fileName.data(), dataSize);
    }

    /**
     * @brief Unload file data allocated by LoadFileData()
     */
    inline void unload_file_data(unsigned char * data) {
        ::UnloadFileData(data);
    }

    /**
     * @brief Save data to file from byte array (write), returns true on success
     */
    [[nodiscard]] inline bool save_file_data(std::string_view fileName, void * data, int dataSize) {
        return ::SaveFileData(fileName.data(), data, dataSize);
    }

    /**
     * @brief Export data to code (.h), returns true on success
     */
    [[nodiscard]] inline bool export_data_as_code(const unsigned char * data, int dataSize, std::string_view fileName) {
        return ::ExportDataAsCode(data, dataSize, fileName.data());
    }

    /**
     * @brief Load text data from file (read), returns a '\0' terminated string
     */
    [[nodiscard]] inline std::string load_file_text(std::string_view fileName) {
        const char* _ret = ::LoadFileText(fileName.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Unload file text data allocated by LoadFileText()
     */
    inline void unload_file_text(char * text) {
        ::UnloadFileText(text);
    }

    /**
     * @brief Save text data to file (write), string must be '\0' terminated, returns true on success
     */
    [[nodiscard]] inline bool save_file_text(std::string_view fileName, std::string_view text) {
        return ::SaveFileText(fileName.data(), text.data());
    }

    /**
     * @brief Set custom file binary data loader
     */
    inline void set_load_file_data_callback(LoadFileDataCallback callback) {
        ::SetLoadFileDataCallback(callback);
    }

    /**
     * @brief Set custom file binary data saver
     */
    inline void set_save_file_data_callback(SaveFileDataCallback callback) {
        ::SetSaveFileDataCallback(callback);
    }

    /**
     * @brief Set custom file text data loader
     */
    inline void set_load_file_text_callback(LoadFileTextCallback callback) {
        ::SetLoadFileTextCallback(callback);
    }

    /**
     * @brief Set custom file text data saver
     */
    inline void set_save_file_text_callback(SaveFileTextCallback callback) {
        ::SetSaveFileTextCallback(callback);
    }

    /**
     * @brief Rename file (if exists)
     */
    [[nodiscard]] inline int file_rename(std::string_view fileName, std::string_view fileRename) {
        return ::FileRename(fileName.data(), fileRename.data());
    }

    /**
     * @brief Remove file (if exists)
     */
    [[nodiscard]] inline int file_remove(std::string_view fileName) {
        return ::FileRemove(fileName.data());
    }

    /**
     * @brief Copy file from one path to another, dstPath created if it doesn't exist
     */
    [[nodiscard]] inline int file_copy(std::string_view srcPath, std::string_view dstPath) {
        return ::FileCopy(srcPath.data(), dstPath.data());
    }

    /**
     * @brief Move file from one directory to another, dstPath created if it doesn't exist
     */
    [[nodiscard]] inline int file_move(std::string_view srcPath, std::string_view dstPath) {
        return ::FileMove(srcPath.data(), dstPath.data());
    }

    /**
     * @brief Replace text in an existing file
     */
    [[nodiscard]] inline int file_text_replace(std::string_view fileName, std::string_view search, std::string_view replacement) {
        return ::FileTextReplace(fileName.data(), search.data(), replacement.data());
    }

    /**
     * @brief Find text in existing file
     */
    [[nodiscard]] inline int file_text_find_index(std::string_view fileName, std::string_view search) {
        return ::FileTextFindIndex(fileName.data(), search.data());
    }

    /**
     * @brief Check if file exists
     */
    [[nodiscard]] inline bool file_exists(std::string_view fileName) {
        return ::FileExists(fileName.data());
    }

    /**
     * @brief Check if a directory path exists
     */
    [[nodiscard]] inline bool directory_exists(std::string_view dirPath) {
        return ::DirectoryExists(dirPath.data());
    }

    /**
     * @brief Check file extension (recommended include point: .png, .wav)
     */
    [[nodiscard]] inline bool is_file_extension(std::string_view fileName, std::string_view ext) {
        return ::IsFileExtension(fileName.data(), ext.data());
    }

    /**
     * @brief Get file length in bytes (NOTE: GetFileSize() conflicts with windows.h)
     */
    [[nodiscard]] inline int get_file_length(std::string_view fileName) {
        return ::GetFileLength(fileName.data());
    }

    /**
     * @brief Get file modification time (last write time)
     */
    [[nodiscard]] inline long get_file_mod_time(std::string_view fileName) {
        return ::GetFileModTime(fileName.data());
    }

    /**
     * @brief Get pointer to extension for a filename string (includes dot: '.png')
     */
    [[nodiscard]] inline std::string get_file_extension(std::string_view fileName) {
        const char* _ret = ::GetFileExtension(fileName.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Get pointer to filename for a path string
     */
    [[nodiscard]] inline std::string get_file_name(std::string_view filePath) {
        const char* _ret = ::GetFileName(filePath.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Get filename string without extension (uses static string)
     */
    [[nodiscard]] inline std::string get_file_name_without_ext(std::string_view filePath) {
        const char* _ret = ::GetFileNameWithoutExt(filePath.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Get full path for a given fileName with path (uses static string)
     */
    [[nodiscard]] inline std::string get_directory_path(std::string_view filePath) {
        const char* _ret = ::GetDirectoryPath(filePath.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Get previous directory path for a given path (uses static string)
     */
    [[nodiscard]] inline std::string get_prev_directory_path(std::string_view dirPath) {
        const char* _ret = ::GetPrevDirectoryPath(dirPath.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Get current working directory (uses static string)
     */
    [[nodiscard]] inline std::string get_working_directory() {
        const char* _ret = ::GetWorkingDirectory();
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Get the directory of the running application (uses static string)
     */
    [[nodiscard]] inline std::string get_application_directory() {
        const char* _ret = ::GetApplicationDirectory();
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Create directories (including full path requested), returns 0 on success
     */
    [[nodiscard]] inline int make_directory(std::string_view dirPath) {
        return ::MakeDirectory(dirPath.data());
    }

    /**
     * @brief Change working directory, return true on success
     */
    [[nodiscard]] inline bool change_directory(std::string_view dirPath) {
        return ::ChangeDirectory(dirPath.data());
    }

    /**
     * @brief Check if a given path is a file or a directory
     */
    [[nodiscard]] inline bool is_path_file(std::string_view path) {
        return ::IsPathFile(path.data());
    }

    /**
     * @brief Check if fileName is valid for the platform/OS
     */
    [[nodiscard]] inline bool is_file_name_valid(std::string_view fileName) {
        return ::IsFileNameValid(fileName.data());
    }

    /**
     * @brief Load directory filepaths, files and directories, no subdirs scan
     */
    [[nodiscard]] inline FilePathList load_directory_files(std::string_view dirPath) {
        return ::LoadDirectoryFiles(dirPath.data());
    }

    /**
     * @brief Load directory filepaths with extension filtering and subdir scan; some filters available
     */
    [[nodiscard]] inline FilePathList load_directory_files_ex(std::string_view basePath, std::string_view filter, bool scanSubdirs) {
        return ::LoadDirectoryFilesEx(basePath.data(), filter.data(), scanSubdirs);
    }

    /**
     * @brief Unload filepaths
     */
    inline void unload_directory_files(FilePathList files) {
        ::UnloadDirectoryFiles(files);
    }

    /**
     * @brief Check if a file has been dropped into window
     */
    [[nodiscard]] inline bool is_file_dropped() {
        return ::IsFileDropped();
    }

    /**
     * @brief Load dropped filepaths
     */
    [[nodiscard]] inline FilePathList load_dropped_files() {
        return ::LoadDroppedFiles();
    }

    /**
     * @brief Unload dropped filepaths
     */
    inline void unload_dropped_files(FilePathList files) {
        ::UnloadDroppedFiles(files);
    }

    /**
     * @brief Get the file count in a directory
     */
    [[nodiscard]] inline unsigned int get_directory_file_count(std::string_view dirPath) {
        return ::GetDirectoryFileCount(dirPath.data());
    }

    /**
     * @brief Get the file count in a directory with extension filtering and recursive directory scan. Use 'DIR' in the filter string to include directories in the result
     */
    [[nodiscard]] inline unsigned int get_directory_file_count_ex(std::string_view basePath, std::string_view filter, bool scanSubdirs) {
        return ::GetDirectoryFileCountEx(basePath.data(), filter.data(), scanSubdirs);
    }

    /**
     * @brief Compress data (DEFLATE algorithm), memory must be MemFree()
     */
    [[nodiscard]] inline unsigned char * compress_data(const unsigned char * data, int dataSize, int * compDataSize) {
        return ::CompressData(data, dataSize, compDataSize);
    }

    /**
     * @brief Decompress data (DEFLATE algorithm), memory must be MemFree()
     */
    [[nodiscard]] inline unsigned char * decompress_data(const unsigned char * compData, int compDataSize, int * dataSize) {
        return ::DecompressData(compData, compDataSize, dataSize);
    }

    /**
     * @brief Encode data to Base64 string (includes NULL terminator), memory must be MemFree()
     */
    [[nodiscard]] inline std::string encode_data_base_64(const unsigned char * data, int dataSize, int * outputSize) {
        const char* _ret = ::EncodeDataBase64(data, dataSize, outputSize);
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Decode Base64 string (expected NULL terminated), memory must be MemFree()
     */
    [[nodiscard]] inline unsigned char * decode_data_base_64(std::string_view text, int * outputSize) {
        return ::DecodeDataBase64(text.data(), outputSize);
    }

    /**
     * @brief Compute CRC32 hash code
     */
    [[nodiscard]] inline unsigned int compute_crc_32(unsigned char * data, int dataSize) {
        return ::ComputeCRC32(data, dataSize);
    }

    /**
     * @brief Compute MD5 hash code, returns static int[4] (16 bytes)
     */
    [[nodiscard]] inline unsigned int * compute_m_d_5(unsigned char * data, int dataSize) {
        return ::ComputeMD5(data, dataSize);
    }

    /**
     * @brief Compute SHA1 hash code, returns static int[5] (20 bytes)
     */
    [[nodiscard]] inline unsigned int * compute_s_h_a_1(unsigned char * data, int dataSize) {
        return ::ComputeSHA1(data, dataSize);
    }

    /**
     * @brief Compute SHA256 hash code, returns static int[8] (32 bytes)
     */
    [[nodiscard]] inline unsigned int * compute_s_h_a_256(unsigned char * data, int dataSize) {
        return ::ComputeSHA256(data, dataSize);
    }

    /**
     * @brief Load automation events list from file, NULL for empty list, capacity = MAX_AUTOMATION_EVENTS
     */
    [[nodiscard]] inline AutomationEventList load_automation_event_list(std::string_view fileName) {
        return ::LoadAutomationEventList(fileName.data());
    }

    /**
     * @brief Unload automation events list from file
     */
    inline void unload_automation_event_list(AutomationEventList list) {
        ::UnloadAutomationEventList(list);
    }

    /**
     * @brief Export automation events list as text file
     */
    [[nodiscard]] inline bool export_automation_event_list(AutomationEventList list, std::string_view fileName) {
        return ::ExportAutomationEventList(list, fileName.data());
    }

    /**
     * @brief Set automation event list to record to
     */
    inline void set_automation_event_list(AutomationEventList * list) {
        ::SetAutomationEventList(list);
    }

    /**
     * @brief Set automation event internal base frame to start recording
     */
    inline void set_automation_event_base_frame(int frame) {
        ::SetAutomationEventBaseFrame(frame);
    }

    /**
     * @brief Start recording automation events (AutomationEventList must be set)
     */
    inline void start_automation_event_recording() {
        ::StartAutomationEventRecording();
    }

    /**
     * @brief Stop recording automation events
     */
    inline void stop_automation_event_recording() {
        ::StopAutomationEventRecording();
    }

    /**
     * @brief Play a recorded automation event
     */
    inline void play_automation_event(AutomationEvent event) {
        ::PlayAutomationEvent(event);
    }

    /**
     * @brief Check if a key has been pressed once
     */
    [[nodiscard]] inline bool is_key_pressed(int key) {
        return ::IsKeyPressed(key);
    }

    /**
     * @brief Check if a key has been pressed again
     */
    [[nodiscard]] inline bool is_key_pressed_repeat(int key) {
        return ::IsKeyPressedRepeat(key);
    }

    /**
     * @brief Check if a key is being pressed
     */
    [[nodiscard]] inline bool is_key_down(int key) {
        return ::IsKeyDown(key);
    }

    /**
     * @brief Check if a key has been released once
     */
    [[nodiscard]] inline bool is_key_released(int key) {
        return ::IsKeyReleased(key);
    }

    /**
     * @brief Check if a key is NOT being pressed
     */
    [[nodiscard]] inline bool is_key_up(int key) {
        return ::IsKeyUp(key);
    }

    /**
     * @brief Get key pressed (keycode), call it multiple times for keys queued, returns 0 when the queue is empty
     */
    [[nodiscard]] inline int get_key_pressed() {
        return ::GetKeyPressed();
    }

    /**
     * @brief Get char pressed (unicode), call it multiple times for chars queued, returns 0 when the queue is empty
     */
    [[nodiscard]] inline int get_char_pressed() {
        return ::GetCharPressed();
    }

    /**
     * @brief Get name of a QWERTY key on the current keyboard layout (eg returns string 'q' for KEY_A on an AZERTY keyboard)
     */
    [[nodiscard]] inline std::string get_key_name(int key) {
        const char* _ret = ::GetKeyName(key);
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Set a custom key to exit program (default is ESC)
     */
    inline void set_exit_key(int key) {
        ::SetExitKey(key);
    }

    /**
     * @brief Check if a gamepad is available
     */
    [[nodiscard]] inline bool is_gamepad_available(int gamepad) {
        return ::IsGamepadAvailable(gamepad);
    }

    /**
     * @brief Get gamepad internal name id
     */
    [[nodiscard]] inline std::string get_gamepad_name(int gamepad) {
        const char* _ret = ::GetGamepadName(gamepad);
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Check if a gamepad button has been pressed once
     */
    [[nodiscard]] inline bool is_gamepad_button_pressed(int gamepad, int button) {
        return ::IsGamepadButtonPressed(gamepad, button);
    }

    /**
     * @brief Check if a gamepad button is being pressed
     */
    [[nodiscard]] inline bool is_gamepad_button_down(int gamepad, int button) {
        return ::IsGamepadButtonDown(gamepad, button);
    }

    /**
     * @brief Check if a gamepad button has been released once
     */
    [[nodiscard]] inline bool is_gamepad_button_released(int gamepad, int button) {
        return ::IsGamepadButtonReleased(gamepad, button);
    }

    /**
     * @brief Check if a gamepad button is NOT being pressed
     */
    [[nodiscard]] inline bool is_gamepad_button_up(int gamepad, int button) {
        return ::IsGamepadButtonUp(gamepad, button);
    }

    /**
     * @brief Get the last gamepad button pressed
     */
    [[nodiscard]] inline int get_gamepad_button_pressed() {
        return ::GetGamepadButtonPressed();
    }

    /**
     * @brief Get axis count for a gamepad
     */
    [[nodiscard]] inline int get_gamepad_axis_count(int gamepad) {
        return ::GetGamepadAxisCount(gamepad);
    }

    /**
     * @brief Get movement value for a gamepad axis
     */
    [[nodiscard]] inline float get_gamepad_axis_movement(int gamepad, int axis) {
        return ::GetGamepadAxisMovement(gamepad, axis);
    }

    /**
     * @brief Set internal gamepad mappings (SDL_GameControllerDB)
     */
    [[nodiscard]] inline int set_gamepad_mappings(std::string_view mappings) {
        return ::SetGamepadMappings(mappings.data());
    }

    /**
     * @brief Set gamepad vibration for both motors (duration in seconds)
     */
    inline void set_gamepad_vibration(int gamepad, float leftMotor, float rightMotor, float duration) {
        ::SetGamepadVibration(gamepad, leftMotor, rightMotor, duration);
    }

    /**
     * @brief Check if a mouse button has been pressed once
     */
    [[nodiscard]] inline bool is_mouse_button_pressed(int button) {
        return ::IsMouseButtonPressed(button);
    }

    /**
     * @brief Check if a mouse button is being pressed
     */
    [[nodiscard]] inline bool is_mouse_button_down(int button) {
        return ::IsMouseButtonDown(button);
    }

    /**
     * @brief Check if a mouse button has been released once
     */
    [[nodiscard]] inline bool is_mouse_button_released(int button) {
        return ::IsMouseButtonReleased(button);
    }

    /**
     * @brief Check if a mouse button is NOT being pressed
     */
    [[nodiscard]] inline bool is_mouse_button_up(int button) {
        return ::IsMouseButtonUp(button);
    }

    /**
     * @brief Get mouse position X
     */
    [[nodiscard]] inline int get_mouse_x() {
        return ::GetMouseX();
    }

    /**
     * @brief Get mouse position Y
     */
    [[nodiscard]] inline int get_mouse_y() {
        return ::GetMouseY();
    }

    /**
     * @brief Get mouse position XY
     */
    [[nodiscard]] inline Vector2 get_mouse_position() {
        return ::GetMousePosition();
    }

    /**
     * @brief Get mouse delta between frames
     */
    [[nodiscard]] inline Vector2 get_mouse_delta() {
        return ::GetMouseDelta();
    }

    /**
     * @brief Set mouse position XY
     */
    inline void set_mouse_position(int x, int y) {
        ::SetMousePosition(x, y);
    }

    /**
     * @brief Set mouse offset
     */
    inline void set_mouse_offset(int offsetX, int offsetY) {
        ::SetMouseOffset(offsetX, offsetY);
    }

    /**
     * @brief Set mouse scaling
     */
    inline void set_mouse_scale(float scaleX, float scaleY) {
        ::SetMouseScale(scaleX, scaleY);
    }

    /**
     * @brief Get mouse wheel movement for X or Y, whichever is larger
     */
    [[nodiscard]] inline float get_mouse_wheel_move() {
        return ::GetMouseWheelMove();
    }

    /**
     * @brief Get mouse wheel movement for both X and Y
     */
    [[nodiscard]] inline Vector2 get_mouse_wheel_move_v() {
        return ::GetMouseWheelMoveV();
    }

    /**
     * @brief Set mouse cursor
     */
    inline void set_mouse_cursor(int cursor) {
        ::SetMouseCursor(cursor);
    }

    /**
     * @brief Get touch position X for touch point 0 (relative to screen size)
     */
    [[nodiscard]] inline int get_touch_x() {
        return ::GetTouchX();
    }

    /**
     * @brief Get touch position Y for touch point 0 (relative to screen size)
     */
    [[nodiscard]] inline int get_touch_y() {
        return ::GetTouchY();
    }

    /**
     * @brief Get touch position XY for a touch point index (relative to screen size)
     */
    [[nodiscard]] inline Vector2 get_touch_position(int index) {
        return ::GetTouchPosition(index);
    }

    /**
     * @brief Get touch point identifier for given index
     */
    [[nodiscard]] inline int get_touch_point_id(int index) {
        return ::GetTouchPointId(index);
    }

    /**
     * @brief Get number of touch points
     */
    [[nodiscard]] inline int get_touch_point_count() {
        return ::GetTouchPointCount();
    }

    /**
     * @brief Enable a set of gestures using flags
     */
    inline void set_gestures_enabled(unsigned int flags) {
        ::SetGesturesEnabled(flags);
    }

    /**
     * @brief Check if a gesture have been detected
     */
    [[nodiscard]] inline bool is_gesture_detected(unsigned int gesture) {
        return ::IsGestureDetected(gesture);
    }

    /**
     * @brief Get latest detected gesture
     */
    [[nodiscard]] inline int get_gesture_detected() {
        return ::GetGestureDetected();
    }

    /**
     * @brief Get gesture hold time in seconds
     */
    [[nodiscard]] inline float get_gesture_hold_duration() {
        return ::GetGestureHoldDuration();
    }

    /**
     * @brief Get gesture drag vector
     */
    [[nodiscard]] inline Vector2 get_gesture_drag_vector() {
        return ::GetGestureDragVector();
    }

    /**
     * @brief Get gesture drag angle
     */
    [[nodiscard]] inline float get_gesture_drag_angle() {
        return ::GetGestureDragAngle();
    }

    /**
     * @brief Get gesture pinch delta
     */
    [[nodiscard]] inline Vector2 get_gesture_pinch_vector() {
        return ::GetGesturePinchVector();
    }

    /**
     * @brief Get gesture pinch angle
     */
    [[nodiscard]] inline float get_gesture_pinch_angle() {
        return ::GetGesturePinchAngle();
    }

    /**
     * @brief Update camera position for selected mode
     */
    inline void update_camera(Camera * camera, int mode) {
        ::UpdateCamera(camera, mode);
    }

    /**
     * @brief Update camera movement/rotation
     */
    inline void update_camera_pro(Camera * camera, Vector3 movement, Vector3 rotation, float zoom) {
        ::UpdateCameraPro(camera, movement, rotation, zoom);
    }

    /**
     * @brief Set texture and rectangle to be used on shapes drawing
     */
    inline void set_shapes_texture(Texture2D texture, Rectangle source) {
        ::SetShapesTexture(texture, source);
    }

    /**
     * @brief Get texture that is used for shapes drawing
     */
    [[nodiscard]] inline Texture2D get_shapes_texture() {
        return ::GetShapesTexture();
    }

    /**
     * @brief Get texture source rectangle that is used for shapes drawing
     */
    [[nodiscard]] inline Rectangle get_shapes_texture_rectangle() {
        return ::GetShapesTextureRectangle();
    }

    /**
     * @brief Draw a pixel using geometry [Can be slow, use with care]
     */
    inline void draw_pixel(int posX, int posY, Color color) {
        ::DrawPixel(posX, posY, color);
    }

    /**
     * @brief Draw a pixel using geometry (Vector version) [Can be slow, use with care]
     */
    inline void draw_pixel_v(Vector2 position, Color color) {
        ::DrawPixelV(position, color);
    }

    /**
     * @brief Draw a line
     */
    inline void draw_line(int startPosX, int startPosY, int endPosX, int endPosY, Color color) {
        ::DrawLine(startPosX, startPosY, endPosX, endPosY, color);
    }

    /**
     * @brief Draw a line (using gl lines)
     */
    inline void draw_line_v(Vector2 startPos, Vector2 endPos, Color color) {
        ::DrawLineV(startPos, endPos, color);
    }

    /**
     * @brief Draw a line (using triangles/quads)
     */
    inline void draw_line_ex(Vector2 startPos, Vector2 endPos, float thick, Color color) {
        ::DrawLineEx(startPos, endPos, thick, color);
    }

    /**
     * @brief Draw lines sequence (using gl lines)
     */
    inline void draw_line_strip(std::span<const Vector2> points, Color color) {
        ::DrawLineStrip(points.data(), static_cast<int>(points.size()), color);
    }

    /**
     * @brief Draw line segment cubic-bezier in-out interpolation
     */
    inline void draw_line_bezier(Vector2 startPos, Vector2 endPos, float thick, Color color) {
        ::DrawLineBezier(startPos, endPos, thick, color);
    }

    /**
     * @brief Draw a dashed line
     */
    inline void draw_line_dashed(Vector2 startPos, Vector2 endPos, int dashSize, int spaceSize, Color color) {
        ::DrawLineDashed(startPos, endPos, dashSize, spaceSize, color);
    }

    /**
     * @brief Draw a color-filled circle
     */
    inline void draw_circle(int centerX, int centerY, float radius, Color color) {
        ::DrawCircle(centerX, centerY, radius, color);
    }

    /**
     * @brief Draw a color-filled circle (Vector version)
     */
    inline void draw_circle_v(Vector2 center, float radius, Color color) {
        ::DrawCircleV(center, radius, color);
    }

    /**
     * @brief Draw a gradient-filled circle
     */
    inline void draw_circle_gradient(Vector2 center, float radius, Color inner, Color outer) {
        ::DrawCircleGradient(center, radius, inner, outer);
    }

    /**
     * @brief Draw a piece of a circle
     */
    inline void draw_circle_sector(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color) {
        ::DrawCircleSector(center, radius, startAngle, endAngle, segments, color);
    }

    /**
     * @brief Draw circle sector outline
     */
    inline void draw_circle_sector_lines(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color) {
        ::DrawCircleSectorLines(center, radius, startAngle, endAngle, segments, color);
    }

    /**
     * @brief Draw circle outline
     */
    inline void draw_circle_lines(int centerX, int centerY, float radius, Color color) {
        ::DrawCircleLines(centerX, centerY, radius, color);
    }

    /**
     * @brief Draw circle outline (Vector version)
     */
    inline void draw_circle_lines_v(Vector2 center, float radius, Color color) {
        ::DrawCircleLinesV(center, radius, color);
    }

    /**
     * @brief Draw ellipse
     */
    inline void draw_ellipse(int centerX, int centerY, float radiusH, float radiusV, Color color) {
        ::DrawEllipse(centerX, centerY, radiusH, radiusV, color);
    }

    /**
     * @brief Draw ellipse (Vector version)
     */
    inline void draw_ellipse_v(Vector2 center, float radiusH, float radiusV, Color color) {
        ::DrawEllipseV(center, radiusH, radiusV, color);
    }

    /**
     * @brief Draw ellipse outline
     */
    inline void draw_ellipse_lines(int centerX, int centerY, float radiusH, float radiusV, Color color) {
        ::DrawEllipseLines(centerX, centerY, radiusH, radiusV, color);
    }

    /**
     * @brief Draw ellipse outline (Vector version)
     */
    inline void draw_ellipse_lines_v(Vector2 center, float radiusH, float radiusV, Color color) {
        ::DrawEllipseLinesV(center, radiusH, radiusV, color);
    }

    /**
     * @brief Draw ring
     */
    inline void draw_ring(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color) {
        ::DrawRing(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
    }

    /**
     * @brief Draw ring outline
     */
    inline void draw_ring_lines(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color) {
        ::DrawRingLines(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
    }

    /**
     * @brief Draw a color-filled rectangle
     */
    inline void draw_rectangle(int posX, int posY, int width, int height, Color color) {
        ::DrawRectangle(posX, posY, width, height, color);
    }

    /**
     * @brief Draw a color-filled rectangle (Vector version)
     */
    inline void draw_rectangle_v(Vector2 position, Vector2 size, Color color) {
        ::DrawRectangleV(position, size, color);
    }

    /**
     * @brief Draw a color-filled rectangle
     */
    inline void draw_rectangle_rec(Rectangle rec, Color color) {
        ::DrawRectangleRec(rec, color);
    }

    /**
     * @brief Draw a color-filled rectangle with pro parameters
     */
    inline void draw_rectangle_pro(Rectangle rec, Vector2 origin, float rotation, Color color) {
        ::DrawRectanglePro(rec, origin, rotation, color);
    }

    /**
     * @brief Draw a vertical-gradient-filled rectangle
     */
    inline void draw_rectangle_gradient_v(int posX, int posY, int width, int height, Color top, Color bottom) {
        ::DrawRectangleGradientV(posX, posY, width, height, top, bottom);
    }

    /**
     * @brief Draw a horizontal-gradient-filled rectangle
     */
    inline void draw_rectangle_gradient_h(int posX, int posY, int width, int height, Color left, Color right) {
        ::DrawRectangleGradientH(posX, posY, width, height, left, right);
    }

    /**
     * @brief Draw a gradient-filled rectangle with custom vertex colors
     */
    inline void draw_rectangle_gradient_ex(Rectangle rec, Color topLeft, Color bottomLeft, Color bottomRight, Color topRight) {
        ::DrawRectangleGradientEx(rec, topLeft, bottomLeft, bottomRight, topRight);
    }

    /**
     * @brief Draw rectangle outline
     */
    inline void draw_rectangle_lines(int posX, int posY, int width, int height, Color color) {
        ::DrawRectangleLines(posX, posY, width, height, color);
    }

    /**
     * @brief Draw rectangle outline with extended parameters
     */
    inline void draw_rectangle_lines_ex(Rectangle rec, float lineThick, Color color) {
        ::DrawRectangleLinesEx(rec, lineThick, color);
    }

    /**
     * @brief Draw rectangle with rounded edges
     */
    inline void draw_rectangle_rounded(Rectangle rec, float roundness, int segments, Color color) {
        ::DrawRectangleRounded(rec, roundness, segments, color);
    }

    /**
     * @brief Draw rectangle lines with rounded edges
     */
    inline void draw_rectangle_rounded_lines(Rectangle rec, float roundness, int segments, Color color) {
        ::DrawRectangleRoundedLines(rec, roundness, segments, color);
    }

    /**
     * @brief Draw rectangle with rounded edges outline
     */
    inline void draw_rectangle_rounded_lines_ex(Rectangle rec, float roundness, int segments, float lineThick, Color color) {
        ::DrawRectangleRoundedLinesEx(rec, roundness, segments, lineThick, color);
    }

    /**
     * @brief Draw a color-filled triangle (vertex in counter-clockwise order!)
     */
    inline void draw_triangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color) {
        ::DrawTriangle(v1, v2, v3, color);
    }

    /**
     * @brief Draw triangle outline (vertex in counter-clockwise order!)
     */
    inline void draw_triangle_lines(Vector2 v1, Vector2 v2, Vector2 v3, Color color) {
        ::DrawTriangleLines(v1, v2, v3, color);
    }

    /**
     * @brief Draw a triangle fan defined by points (first vertex is the center)
     */
    inline void draw_triangle_fan(std::span<const Vector2> points, Color color) {
        ::DrawTriangleFan(points.data(), static_cast<int>(points.size()), color);
    }

    /**
     * @brief Draw a triangle strip defined by points
     */
    inline void draw_triangle_strip(std::span<const Vector2> points, Color color) {
        ::DrawTriangleStrip(points.data(), static_cast<int>(points.size()), color);
    }

    /**
     * @brief Draw a regular polygon (Vector version)
     */
    inline void draw_poly(Vector2 center, int sides, float radius, float rotation, Color color) {
        ::DrawPoly(center, sides, radius, rotation, color);
    }

    /**
     * @brief Draw a polygon outline of n sides
     */
    inline void draw_poly_lines(Vector2 center, int sides, float radius, float rotation, Color color) {
        ::DrawPolyLines(center, sides, radius, rotation, color);
    }

    /**
     * @brief Draw a polygon outline of n sides with extended parameters
     */
    inline void draw_poly_lines_ex(Vector2 center, int sides, float radius, float rotation, float lineThick, Color color) {
        ::DrawPolyLinesEx(center, sides, radius, rotation, lineThick, color);
    }

    /**
     * @brief Draw spline: Linear, minimum 2 points
     */
    inline void draw_spline_linear(std::span<const Vector2> points, float thick, Color color) {
        ::DrawSplineLinear(points.data(), static_cast<int>(points.size()), thick, color);
    }

    /**
     * @brief Draw spline: B-Spline, minimum 4 points
     */
    inline void draw_spline_basis(std::span<const Vector2> points, float thick, Color color) {
        ::DrawSplineBasis(points.data(), static_cast<int>(points.size()), thick, color);
    }

    /**
     * @brief Draw spline: Catmull-Rom, minimum 4 points
     */
    inline void draw_spline_catmull_rom(std::span<const Vector2> points, float thick, Color color) {
        ::DrawSplineCatmullRom(points.data(), static_cast<int>(points.size()), thick, color);
    }

    /**
     * @brief Draw spline: Quadratic Bezier, minimum 3 points (1 control point): [p1, c2, p3, c4...]
     */
    inline void draw_spline_bezier_quadratic(std::span<const Vector2> points, float thick, Color color) {
        ::DrawSplineBezierQuadratic(points.data(), static_cast<int>(points.size()), thick, color);
    }

    /**
     * @brief Draw spline: Cubic Bezier, minimum 4 points (2 control points): [p1, c2, c3, p4, c5, c6...]
     */
    inline void draw_spline_bezier_cubic(std::span<const Vector2> points, float thick, Color color) {
        ::DrawSplineBezierCubic(points.data(), static_cast<int>(points.size()), thick, color);
    }

    /**
     * @brief Draw spline segment: Linear, 2 points
     */
    inline void draw_spline_segment_linear(Vector2 p1, Vector2 p2, float thick, Color color) {
        ::DrawSplineSegmentLinear(p1, p2, thick, color);
    }

    /**
     * @brief Draw spline segment: B-Spline, 4 points
     */
    inline void draw_spline_segment_basis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color) {
        ::DrawSplineSegmentBasis(p1, p2, p3, p4, thick, color);
    }

    /**
     * @brief Draw spline segment: Catmull-Rom, 4 points
     */
    inline void draw_spline_segment_catmull_rom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color) {
        ::DrawSplineSegmentCatmullRom(p1, p2, p3, p4, thick, color);
    }

    /**
     * @brief Draw spline segment: Quadratic Bezier, 2 points, 1 control point
     */
    inline void draw_spline_segment_bezier_quadratic(Vector2 p1, Vector2 c2, Vector2 p3, float thick, Color color) {
        ::DrawSplineSegmentBezierQuadratic(p1, c2, p3, thick, color);
    }

    /**
     * @brief Draw spline segment: Cubic Bezier, 2 points, 2 control points
     */
    inline void draw_spline_segment_bezier_cubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float thick, Color color) {
        ::DrawSplineSegmentBezierCubic(p1, c2, c3, p4, thick, color);
    }

    /**
     * @brief Get (evaluate) spline point: Linear
     */
    [[nodiscard]] inline Vector2 get_spline_point_linear(Vector2 startPos, Vector2 endPos, float t) {
        return ::GetSplinePointLinear(startPos, endPos, t);
    }

    /**
     * @brief Get (evaluate) spline point: B-Spline
     */
    [[nodiscard]] inline Vector2 get_spline_point_basis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t) {
        return ::GetSplinePointBasis(p1, p2, p3, p4, t);
    }

    /**
     * @brief Get (evaluate) spline point: Catmull-Rom
     */
    [[nodiscard]] inline Vector2 get_spline_point_catmull_rom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t) {
        return ::GetSplinePointCatmullRom(p1, p2, p3, p4, t);
    }

    /**
     * @brief Get (evaluate) spline point: Quadratic Bezier
     */
    [[nodiscard]] inline Vector2 get_spline_point_bezier_quad(Vector2 p1, Vector2 c2, Vector2 p3, float t) {
        return ::GetSplinePointBezierQuad(p1, c2, p3, t);
    }

    /**
     * @brief Get (evaluate) spline point: Cubic Bezier
     */
    [[nodiscard]] inline Vector2 get_spline_point_bezier_cubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float t) {
        return ::GetSplinePointBezierCubic(p1, c2, c3, p4, t);
    }

    /**
     * @brief Check collision between two rectangles
     */
    [[nodiscard]] inline bool check_collision_recs(Rectangle rec1, Rectangle rec2) {
        return ::CheckCollisionRecs(rec1, rec2);
    }

    /**
     * @brief Check collision between two circles
     */
    [[nodiscard]] inline bool check_collision_circles(Vector2 center1, float radius1, Vector2 center2, float radius2) {
        return ::CheckCollisionCircles(center1, radius1, center2, radius2);
    }

    /**
     * @brief Check collision between circle and rectangle
     */
    [[nodiscard]] inline bool check_collision_circle_rec(Vector2 center, float radius, Rectangle rec) {
        return ::CheckCollisionCircleRec(center, radius, rec);
    }

    /**
     * @brief Check if circle collides with a line created betweeen two points [p1] and [p2]
     */
    [[nodiscard]] inline bool check_collision_circle_line(Vector2 center, float radius, Vector2 p1, Vector2 p2) {
        return ::CheckCollisionCircleLine(center, radius, p1, p2);
    }

    /**
     * @brief Check if point is inside rectangle
     */
    [[nodiscard]] inline bool check_collision_point_rec(Vector2 point, Rectangle rec) {
        return ::CheckCollisionPointRec(point, rec);
    }

    /**
     * @brief Check if point is inside circle
     */
    [[nodiscard]] inline bool check_collision_point_circle(Vector2 point, Vector2 center, float radius) {
        return ::CheckCollisionPointCircle(point, center, radius);
    }

    /**
     * @brief Check if point is inside a triangle
     */
    [[nodiscard]] inline bool check_collision_point_triangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3) {
        return ::CheckCollisionPointTriangle(point, p1, p2, p3);
    }

    /**
     * @brief Check if point belongs to line created between two points [p1] and [p2] with defined margin in pixels [threshold]
     */
    [[nodiscard]] inline bool check_collision_point_line(Vector2 point, Vector2 p1, Vector2 p2, int threshold) {
        return ::CheckCollisionPointLine(point, p1, p2, threshold);
    }

    /**
     * @brief Check if point is within a polygon described by array of vertices
     */
    [[nodiscard]] inline bool check_collision_point_poly(Vector2 point, std::span<const Vector2> points) {
        return ::CheckCollisionPointPoly(point, points.data(), static_cast<int>(points.size()));
    }

    /**
     * @brief Check the collision between two lines defined by two points each, returns collision point by reference
     */
    [[nodiscard]] inline bool check_collision_lines(Vector2 startPos1, Vector2 endPos1, Vector2 startPos2, Vector2 endPos2, Vector2 * collisionPoint) {
        return ::CheckCollisionLines(startPos1, endPos1, startPos2, endPos2, collisionPoint);
    }

    /**
     * @brief Get collision rectangle for two rectangles collision
     */
    [[nodiscard]] inline Rectangle get_collision_rec(Rectangle rec1, Rectangle rec2) {
        return ::GetCollisionRec(rec1, rec2);
    }

    /**
     * @brief Load image from file into CPU memory (RAM)
     */
    [[nodiscard]] inline Image load_image(std::string_view fileName) {
        return ::LoadImage(fileName.data());
    }

    /**
     * @brief Load image from RAW file data
     */
    [[nodiscard]] inline Image load_image_raw(std::string_view fileName, int width, int height, int format, int headerSize) {
        return ::LoadImageRaw(fileName.data(), width, height, format, headerSize);
    }

    /**
     * @brief Load image sequence from file (frames appended to image.data)
     */
    [[nodiscard]] inline Image load_image_anim(std::string_view fileName, int * frames) {
        return ::LoadImageAnim(fileName.data(), frames);
    }

    /**
     * @brief Load image sequence from memory buffer
     */
    [[nodiscard]] inline Image load_image_anim_from_memory(std::string_view fileType, const unsigned char * fileData, int dataSize, int * frames) {
        return ::LoadImageAnimFromMemory(fileType.data(), fileData, dataSize, frames);
    }

    /**
     * @brief Load image from memory buffer, fileType refers to extension: i.e. '.png'
     */
    [[nodiscard]] inline Image load_image_from_memory(std::string_view fileType, const unsigned char * fileData, int dataSize) {
        return ::LoadImageFromMemory(fileType.data(), fileData, dataSize);
    }

    /**
     * @brief Load image from GPU texture data
     */
    [[nodiscard]] inline Image load_image_from_texture(Texture2D texture) {
        return ::LoadImageFromTexture(texture);
    }

    /**
     * @brief Load image from screen buffer and (screenshot)
     */
    [[nodiscard]] inline Image load_image_from_screen() {
        return ::LoadImageFromScreen();
    }

    /**
     * @brief Check if an image is valid (data and parameters)
     */
    [[nodiscard]] inline bool is_image_valid(Image image) {
        return ::IsImageValid(image);
    }

    /**
     * @brief Unload image from CPU memory (RAM)
     */
    inline void unload_image(Image image) {
        ::UnloadImage(image);
    }

    /**
     * @brief Export image data to file, returns true on success
     */
    [[nodiscard]] inline bool export_image(Image image, std::string_view fileName) {
        return ::ExportImage(image, fileName.data());
    }

    /**
     * @brief Export image to memory buffer, memory must be MemFree()
     */
    [[nodiscard]] inline unsigned char * export_image_to_memory(Image image, std::string_view fileType, int * fileSize) {
        return ::ExportImageToMemory(image, fileType.data(), fileSize);
    }

    /**
     * @brief Export image as code file defining an array of bytes, returns true on success
     */
    [[nodiscard]] inline bool export_image_as_code(Image image, std::string_view fileName) {
        return ::ExportImageAsCode(image, fileName.data());
    }

    /**
     * @brief Generate image: plain color
     */
    [[nodiscard]] inline Image gen_image_color(int width, int height, Color color) {
        return ::GenImageColor(width, height, color);
    }

    /**
     * @brief Generate image: linear gradient, direction in degrees [0..360], 0=Vertical gradient
     */
    [[nodiscard]] inline Image gen_image_gradient_linear(int width, int height, int direction, Color start, Color end) {
        return ::GenImageGradientLinear(width, height, direction, start, end);
    }

    /**
     * @brief Generate image: radial gradient
     */
    [[nodiscard]] inline Image gen_image_gradient_radial(int width, int height, float density, Color inner, Color outer) {
        return ::GenImageGradientRadial(width, height, density, inner, outer);
    }

    /**
     * @brief Generate image: square gradient
     */
    [[nodiscard]] inline Image gen_image_gradient_square(int width, int height, float density, Color inner, Color outer) {
        return ::GenImageGradientSquare(width, height, density, inner, outer);
    }

    /**
     * @brief Generate image: checked
     */
    [[nodiscard]] inline Image gen_image_checked(int width, int height, int checksX, int checksY, Color col1, Color col2) {
        return ::GenImageChecked(width, height, checksX, checksY, col1, col2);
    }

    /**
     * @brief Generate image: white noise
     */
    [[nodiscard]] inline Image gen_image_white_noise(int width, int height, float factor) {
        return ::GenImageWhiteNoise(width, height, factor);
    }

    /**
     * @brief Generate image: perlin noise
     */
    [[nodiscard]] inline Image gen_image_perlin_noise(int width, int height, int offsetX, int offsetY, float scale) {
        return ::GenImagePerlinNoise(width, height, offsetX, offsetY, scale);
    }

    /**
     * @brief Generate image: cellular algorithm, bigger tileSize means bigger cells
     */
    [[nodiscard]] inline Image gen_image_cellular(int width, int height, int tileSize) {
        return ::GenImageCellular(width, height, tileSize);
    }

    /**
     * @brief Generate image: grayscale image from text data
     */
    [[nodiscard]] inline Image gen_image_text(int width, int height, std::string_view text) {
        return ::GenImageText(width, height, text.data());
    }

    /**
     * @brief Create an image duplicate (useful for transformations)
     */
    [[nodiscard]] inline Image image_copy(Image image) {
        return ::ImageCopy(image);
    }

    /**
     * @brief Create an image from another image piece
     */
    [[nodiscard]] inline Image image_from_image(Image image, Rectangle rec) {
        return ::ImageFromImage(image, rec);
    }

    /**
     * @brief Create an image from a selected channel of another image (GRAYSCALE)
     */
    [[nodiscard]] inline Image image_from_channel(Image image, int selectedChannel) {
        return ::ImageFromChannel(image, selectedChannel);
    }

    /**
     * @brief Create an image from text (default font)
     */
    [[nodiscard]] inline Image image_text(std::string_view text, int fontSize, Color color) {
        return ::ImageText(text.data(), fontSize, color);
    }

    /**
     * @brief Create an image from text (custom sprite font)
     */
    [[nodiscard]] inline Image image_text_ex(Font font, std::string_view text, float fontSize, float spacing, Color tint) {
        return ::ImageTextEx(font, text.data(), fontSize, spacing, tint);
    }

    /**
     * @brief Convert image data to desired format
     */
    inline void image_format(Image * image, int newFormat) {
        ::ImageFormat(image, newFormat);
    }

    /**
     * @brief Convert image to POT (power-of-two)
     */
    inline void image_to_p_o_t(Image * image, Color fill) {
        ::ImageToPOT(image, fill);
    }

    /**
     * @brief Crop an image to a defined rectangle
     */
    inline void image_crop(Image * image, Rectangle crop) {
        ::ImageCrop(image, crop);
    }

    /**
     * @brief Crop image depending on alpha value
     */
    inline void image_alpha_crop(Image * image, float threshold) {
        ::ImageAlphaCrop(image, threshold);
    }

    /**
     * @brief Clear alpha channel to desired color
     */
    inline void image_alpha_clear(Image * image, Color color, float threshold) {
        ::ImageAlphaClear(image, color, threshold);
    }

    /**
     * @brief Apply alpha mask to image
     */
    inline void image_alpha_mask(Image * image, Image alphaMask) {
        ::ImageAlphaMask(image, alphaMask);
    }

    /**
     * @brief Premultiply alpha channel
     */
    inline void image_alpha_premultiply(Image * image) {
        ::ImageAlphaPremultiply(image);
    }

    /**
     * @brief Apply Gaussian blur using a box blur approximation
     */
    inline void image_blur_gaussian(std::span<Image> image) {
        ::ImageBlurGaussian(image.data(), static_cast<int>(image.size()));
    }

    /**
     * @brief Apply custom square convolution kernel to image
     */
    inline void image_kernel_convolution(Image * image, std::span<const float> kernel) {
        ::ImageKernelConvolution(image, kernel.data(), static_cast<int>(kernel.size()));
    }

    /**
     * @brief Resize image (Bicubic scaling algorithm)
     */
    inline void image_resize(Image * image, int newWidth, int newHeight) {
        ::ImageResize(image, newWidth, newHeight);
    }

    /**
     * @brief Resize image (Nearest-Neighbor scaling algorithm)
     */
    inline void image_resize_n_n(Image * image, int newWidth, int newHeight) {
        ::ImageResizeNN(image, newWidth, newHeight);
    }

    /**
     * @brief Resize canvas and fill with color
     */
    inline void image_resize_canvas(Image * image, int newWidth, int newHeight, int offsetX, int offsetY, Color fill) {
        ::ImageResizeCanvas(image, newWidth, newHeight, offsetX, offsetY, fill);
    }

    /**
     * @brief Compute all mipmap levels for a provided image
     */
    inline void image_mipmaps(Image * image) {
        ::ImageMipmaps(image);
    }

    /**
     * @brief Dither image data to 16bpp or lower (Floyd-Steinberg dithering)
     */
    inline void image_dither(Image * image, int rBpp, int gBpp, int bBpp, int aBpp) {
        ::ImageDither(image, rBpp, gBpp, bBpp, aBpp);
    }

    /**
     * @brief Flip image vertically
     */
    inline void image_flip_vertical(Image * image) {
        ::ImageFlipVertical(image);
    }

    /**
     * @brief Flip image horizontally
     */
    inline void image_flip_horizontal(Image * image) {
        ::ImageFlipHorizontal(image);
    }

    /**
     * @brief Rotate image by input angle in degrees (-359 to 359)
     */
    inline void image_rotate(Image * image, int degrees) {
        ::ImageRotate(image, degrees);
    }

    /**
     * @brief Rotate image clockwise 90deg
     */
    inline void image_rotate_c_w(Image * image) {
        ::ImageRotateCW(image);
    }

    /**
     * @brief Rotate image counter-clockwise 90deg
     */
    inline void image_rotate_c_c_w(Image * image) {
        ::ImageRotateCCW(image);
    }

    /**
     * @brief Modify image color: tint
     */
    inline void image_color_tint(Image * image, Color color) {
        ::ImageColorTint(image, color);
    }

    /**
     * @brief Modify image color: invert
     */
    inline void image_color_invert(Image * image) {
        ::ImageColorInvert(image);
    }

    /**
     * @brief Modify image color: grayscale
     */
    inline void image_color_grayscale(Image * image) {
        ::ImageColorGrayscale(image);
    }

    /**
     * @brief Modify image color: contrast (-100 to 100)
     */
    inline void image_color_contrast(Image * image, float contrast) {
        ::ImageColorContrast(image, contrast);
    }

    /**
     * @brief Modify image color: brightness (-255 to 255)
     */
    inline void image_color_brightness(Image * image, int brightness) {
        ::ImageColorBrightness(image, brightness);
    }

    /**
     * @brief Modify image color: replace color
     */
    inline void image_color_replace(Image * image, Color color, Color replace) {
        ::ImageColorReplace(image, color, replace);
    }

    /**
     * @brief Load color data from image as a Color array (RGBA - 32bit)
     */
    [[nodiscard]] inline Color * load_image_colors(Image image) {
        return ::LoadImageColors(image);
    }

    /**
     * @brief Load colors palette from image as a Color array (RGBA - 32bit)
     */
    [[nodiscard]] inline Color * load_image_palette(Image image, int maxPaletteSize, int * colorCount) {
        return ::LoadImagePalette(image, maxPaletteSize, colorCount);
    }

    /**
     * @brief Unload color data loaded with LoadImageColors()
     */
    inline void unload_image_colors(Color * colors) {
        ::UnloadImageColors(colors);
    }

    /**
     * @brief Unload colors palette loaded with LoadImagePalette()
     */
    inline void unload_image_palette(Color * colors) {
        ::UnloadImagePalette(colors);
    }

    /**
     * @brief Get image alpha border rectangle
     */
    [[nodiscard]] inline Rectangle get_image_alpha_border(Image image, float threshold) {
        return ::GetImageAlphaBorder(image, threshold);
    }

    /**
     * @brief Get image pixel color at (x, y) position
     */
    [[nodiscard]] inline Color get_image_color(Image image, int x, int y) {
        return ::GetImageColor(image, x, y);
    }

    /**
     * @brief Clear image background with given color
     */
    inline void image_clear_background(Image * dst, Color color) {
        ::ImageClearBackground(dst, color);
    }

    /**
     * @brief Draw pixel within an image
     */
    inline void image_draw_pixel(Image * dst, int posX, int posY, Color color) {
        ::ImageDrawPixel(dst, posX, posY, color);
    }

    /**
     * @brief Draw pixel within an image (Vector version)
     */
    inline void image_draw_pixel_v(Image * dst, Vector2 position, Color color) {
        ::ImageDrawPixelV(dst, position, color);
    }

    /**
     * @brief Draw line within an image
     */
    inline void image_draw_line(Image * dst, int startPosX, int startPosY, int endPosX, int endPosY, Color color) {
        ::ImageDrawLine(dst, startPosX, startPosY, endPosX, endPosY, color);
    }

    /**
     * @brief Draw line within an image (Vector version)
     */
    inline void image_draw_line_v(Image * dst, Vector2 start, Vector2 end, Color color) {
        ::ImageDrawLineV(dst, start, end, color);
    }

    /**
     * @brief Draw a line defining thickness within an image
     */
    inline void image_draw_line_ex(Image * dst, Vector2 start, Vector2 end, int thick, Color color) {
        ::ImageDrawLineEx(dst, start, end, thick, color);
    }

    /**
     * @brief Draw a filled circle within an image
     */
    inline void image_draw_circle(Image * dst, int centerX, int centerY, int radius, Color color) {
        ::ImageDrawCircle(dst, centerX, centerY, radius, color);
    }

    /**
     * @brief Draw a filled circle within an image (Vector version)
     */
    inline void image_draw_circle_v(Image * dst, Vector2 center, int radius, Color color) {
        ::ImageDrawCircleV(dst, center, radius, color);
    }

    /**
     * @brief Draw circle outline within an image
     */
    inline void image_draw_circle_lines(Image * dst, int centerX, int centerY, int radius, Color color) {
        ::ImageDrawCircleLines(dst, centerX, centerY, radius, color);
    }

    /**
     * @brief Draw circle outline within an image (Vector version)
     */
    inline void image_draw_circle_lines_v(Image * dst, Vector2 center, int radius, Color color) {
        ::ImageDrawCircleLinesV(dst, center, radius, color);
    }

    /**
     * @brief Draw rectangle within an image
     */
    inline void image_draw_rectangle(Image * dst, int posX, int posY, int width, int height, Color color) {
        ::ImageDrawRectangle(dst, posX, posY, width, height, color);
    }

    /**
     * @brief Draw rectangle within an image (Vector version)
     */
    inline void image_draw_rectangle_v(Image * dst, Vector2 position, Vector2 size, Color color) {
        ::ImageDrawRectangleV(dst, position, size, color);
    }

    /**
     * @brief Draw rectangle within an image
     */
    inline void image_draw_rectangle_rec(Image * dst, Rectangle rec, Color color) {
        ::ImageDrawRectangleRec(dst, rec, color);
    }

    /**
     * @brief Draw rectangle lines within an image
     */
    inline void image_draw_rectangle_lines(Image * dst, Rectangle rec, int thick, Color color) {
        ::ImageDrawRectangleLines(dst, rec, thick, color);
    }

    /**
     * @brief Draw triangle within an image
     */
    inline void image_draw_triangle(Image * dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color) {
        ::ImageDrawTriangle(dst, v1, v2, v3, color);
    }

    /**
     * @brief Draw triangle with interpolated colors within an image
     */
    inline void image_draw_triangle_ex(Image * dst, Vector2 v1, Vector2 v2, Vector2 v3, Color c1, Color c2, Color c3) {
        ::ImageDrawTriangleEx(dst, v1, v2, v3, c1, c2, c3);
    }

    /**
     * @brief Draw triangle outline within an image
     */
    inline void image_draw_triangle_lines(Image * dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color) {
        ::ImageDrawTriangleLines(dst, v1, v2, v3, color);
    }

    /**
     * @brief Draw a triangle fan defined by points within an image (first vertex is the center)
     */
    inline void image_draw_triangle_fan(Image * dst, std::span<const Vector2> points, Color color) {
        ::ImageDrawTriangleFan(dst, points.data(), static_cast<int>(points.size()), color);
    }

    /**
     * @brief Draw a triangle strip defined by points within an image
     */
    inline void image_draw_triangle_strip(Image * dst, std::span<const Vector2> points, Color color) {
        ::ImageDrawTriangleStrip(dst, points.data(), static_cast<int>(points.size()), color);
    }

    /**
     * @brief Draw a source image within a destination image (tint applied to source)
     */
    inline void image_draw(Image * dst, Image src, Rectangle srcRec, Rectangle dstRec, Color tint) {
        ::ImageDraw(dst, src, srcRec, dstRec, tint);
    }

    /**
     * @brief Draw text (using default font) within an image (destination)
     */
    inline void image_draw_text(Image * dst, std::string_view text, int posX, int posY, int fontSize, Color color) {
        ::ImageDrawText(dst, text.data(), posX, posY, fontSize, color);
    }

    /**
     * @brief Draw text (custom sprite font) within an image (destination)
     */
    inline void image_draw_text_ex(Image * dst, Font font, std::string_view text, Vector2 position, float fontSize, float spacing, Color tint) {
        ::ImageDrawTextEx(dst, font, text.data(), position, fontSize, spacing, tint);
    }

    /**
     * @brief Load texture from file into GPU memory (VRAM)
     */
    [[nodiscard]] inline Texture2D load_texture(std::string_view fileName) {
        return ::LoadTexture(fileName.data());
    }

    /**
     * @brief Load texture from image data
     */
    [[nodiscard]] inline Texture2D load_texture_from_image(Image image) {
        return ::LoadTextureFromImage(image);
    }

    /**
     * @brief Load cubemap from image, multiple image cubemap layouts supported
     */
    [[nodiscard]] inline TextureCubemap load_texture_cubemap(Image image, int layout) {
        return ::LoadTextureCubemap(image, layout);
    }

    /**
     * @brief Load texture for rendering (framebuffer)
     */
    [[nodiscard]] inline RenderTexture2D load_render_texture(int width, int height) {
        return ::LoadRenderTexture(width, height);
    }

    /**
     * @brief Check if a texture is valid (loaded in GPU)
     */
    [[nodiscard]] inline bool is_texture_valid(Texture2D texture) {
        return ::IsTextureValid(texture);
    }

    /**
     * @brief Unload texture from GPU memory (VRAM)
     */
    inline void unload_texture(Texture2D texture) {
        ::UnloadTexture(texture);
    }

    /**
     * @brief Check if a render texture is valid (loaded in GPU)
     */
    [[nodiscard]] inline bool is_render_texture_valid(RenderTexture2D target) {
        return ::IsRenderTextureValid(target);
    }

    /**
     * @brief Unload render texture from GPU memory (VRAM)
     */
    inline void unload_render_texture(RenderTexture2D target) {
        ::UnloadRenderTexture(target);
    }

    /**
     * @brief Update GPU texture with new data (pixels should be able to fill texture)
     */
    inline void update_texture(Texture2D texture, const void * pixels) {
        ::UpdateTexture(texture, pixels);
    }

    /**
     * @brief Update GPU texture rectangle with new data (pixels and rec should fit in texture)
     */
    inline void update_texture_rec(Texture2D texture, Rectangle rec, const void * pixels) {
        ::UpdateTextureRec(texture, rec, pixels);
    }

    /**
     * @brief Generate GPU mipmaps for a texture
     */
    inline void gen_texture_mipmaps(Texture2D * texture) {
        ::GenTextureMipmaps(texture);
    }

    /**
     * @brief Set texture scaling filter mode
     */
    inline void set_texture_filter(Texture2D texture, int filter) {
        ::SetTextureFilter(texture, filter);
    }

    /**
     * @brief Set texture wrapping mode
     */
    inline void set_texture_wrap(Texture2D texture, int wrap) {
        ::SetTextureWrap(texture, wrap);
    }

    /**
     * @brief Draw a Texture2D
     */
    inline void draw_texture(Texture2D texture, int posX, int posY, Color tint) {
        ::DrawTexture(texture, posX, posY, tint);
    }

    /**
     * @brief Draw a Texture2D with position defined as Vector2
     */
    inline void draw_texture_v(Texture2D texture, Vector2 position, Color tint) {
        ::DrawTextureV(texture, position, tint);
    }

    /**
     * @brief Draw a Texture2D with extended parameters
     */
    inline void draw_texture_ex(Texture2D texture, Vector2 position, float rotation, float scale, Color tint) {
        ::DrawTextureEx(texture, position, rotation, scale, tint);
    }

    /**
     * @brief Draw a part of a texture defined by a rectangle
     */
    inline void draw_texture_rec(Texture2D texture, Rectangle source, Vector2 position, Color tint) {
        ::DrawTextureRec(texture, source, position, tint);
    }

    /**
     * @brief Draw a part of a texture defined by a rectangle with 'pro' parameters
     */
    inline void draw_texture_pro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint) {
        ::DrawTexturePro(texture, source, dest, origin, rotation, tint);
    }

    /**
     * @brief Draws a texture (or part of it) that stretches or shrinks nicely
     */
    inline void draw_texture_n_patch(Texture2D texture, NPatchInfo nPatchInfo, Rectangle dest, Vector2 origin, float rotation, Color tint) {
        ::DrawTextureNPatch(texture, nPatchInfo, dest, origin, rotation, tint);
    }

    /**
     * @brief Check if two colors are equal
     */
    [[nodiscard]] inline bool color_is_equal(Color col1, Color col2) {
        return ::ColorIsEqual(col1, col2);
    }

    /**
     * @brief Get color with alpha applied, alpha goes from 0.0f to 1.0f
     */
    [[nodiscard]] inline Color fade(Color color, float alpha) {
        return ::Fade(color, alpha);
    }

    /**
     * @brief Get hexadecimal value for a Color (0xRRGGBBAA)
     */
    [[nodiscard]] inline int color_to_int(Color color) {
        return ::ColorToInt(color);
    }

    /**
     * @brief Get Color normalized as float [0..1]
     */
    [[nodiscard]] inline Vector4 color_normalize(Color color) {
        return ::ColorNormalize(color);
    }

    /**
     * @brief Get Color from normalized values [0..1]
     */
    [[nodiscard]] inline Color color_from_normalized(Vector4 normalized) {
        return ::ColorFromNormalized(normalized);
    }

    /**
     * @brief Get HSV values for a Color, hue [0..360], saturation/value [0..1]
     */
    [[nodiscard]] inline Vector3 color_to_h_s_v(Color color) {
        return ::ColorToHSV(color);
    }

    /**
     * @brief Get a Color from HSV values, hue [0..360], saturation/value [0..1]
     */
    [[nodiscard]] inline Color color_from_h_s_v(float hue, float saturation, float value) {
        return ::ColorFromHSV(hue, saturation, value);
    }

    /**
     * @brief Get color multiplied with another color
     */
    [[nodiscard]] inline Color color_tint(Color color, Color tint) {
        return ::ColorTint(color, tint);
    }

    /**
     * @brief Get color with brightness correction, brightness factor goes from -1.0f to 1.0f
     */
    [[nodiscard]] inline Color color_brightness(Color color, float factor) {
        return ::ColorBrightness(color, factor);
    }

    /**
     * @brief Get color with contrast correction, contrast values between -1.0f and 1.0f
     */
    [[nodiscard]] inline Color color_contrast(Color color, float contrast) {
        return ::ColorContrast(color, contrast);
    }

    /**
     * @brief Get color with alpha applied, alpha goes from 0.0f to 1.0f
     */
    [[nodiscard]] inline Color color_alpha(Color color, float alpha) {
        return ::ColorAlpha(color, alpha);
    }

    /**
     * @brief Get src alpha-blended into dst color with tint
     */
    [[nodiscard]] inline Color color_alpha_blend(Color dst, Color src, Color tint) {
        return ::ColorAlphaBlend(dst, src, tint);
    }

    /**
     * @brief Get color lerp interpolation between two colors, factor [0.0f..1.0f]
     */
    [[nodiscard]] inline Color color_lerp(Color color1, Color color2, float factor) {
        return ::ColorLerp(color1, color2, factor);
    }

    /**
     * @brief Get Color structure from hexadecimal value
     */
    [[nodiscard]] inline Color get_color(unsigned int hexValue) {
        return ::GetColor(hexValue);
    }

    /**
     * @brief Get Color from a source pixel pointer of certain format
     */
    [[nodiscard]] inline Color get_pixel_color(void * srcPtr, int format) {
        return ::GetPixelColor(srcPtr, format);
    }

    /**
     * @brief Set color formatted into destination pixel pointer
     */
    inline void set_pixel_color(void * dstPtr, Color color, int format) {
        ::SetPixelColor(dstPtr, color, format);
    }

    /**
     * @brief Get pixel data size in bytes for certain format
     */
    [[nodiscard]] inline int get_pixel_data_size(int width, int height, int format) {
        return ::GetPixelDataSize(width, height, format);
    }

    /**
     * @brief Get the default Font
     */
    [[nodiscard]] inline Font get_font_default() {
        return ::GetFontDefault();
    }

    /**
     * @brief Load font from file into GPU memory (VRAM)
     */
    [[nodiscard]] inline Font load_font(std::string_view fileName) {
        return ::LoadFont(fileName.data());
    }

    /**
     * @brief Load font from file with extended parameters, use NULL for codepoints and 0 for codepointCount to load the default character set, font size is provided in pixels height
     */
    [[nodiscard]] inline Font load_font_ex(std::string_view fileName, int fontSize, std::span<const int> codepoints) {
        return ::LoadFontEx(fileName.data(), fontSize, codepoints.data(), static_cast<int>(codepoints.size()));
    }

    /**
     * @brief Load font from Image (XNA style)
     */
    [[nodiscard]] inline Font load_font_from_image(Image image, Color key, int firstChar) {
        return ::LoadFontFromImage(image, key, firstChar);
    }

    /**
     * @brief Load font from memory buffer, fileType refers to extension: i.e. '.ttf'
     */
    [[nodiscard]] inline Font load_font_from_memory(std::string_view fileType, const unsigned char * fileData, int dataSize, int fontSize, std::span<const int> codepoints) {
        return ::LoadFontFromMemory(fileType.data(), fileData, dataSize, fontSize, codepoints.data(), static_cast<int>(codepoints.size()));
    }

    /**
     * @brief Check if a font is valid (font data loaded, WARNING: GPU texture not checked)
     */
    [[nodiscard]] inline bool is_font_valid(Font font) {
        return ::IsFontValid(font);
    }

    /**
     * @brief Load font data for further use
     */
    [[nodiscard]] inline GlyphInfo * load_font_data(const unsigned char * fileData, int dataSize, int fontSize, std::span<const int> codepoints, int type, int * glyphCount) {
        return ::LoadFontData(fileData, dataSize, fontSize, codepoints.data(), static_cast<int>(codepoints.size()), type, glyphCount);
    }

    /**
     * @brief Generate image font atlas using chars info
     */
    [[nodiscard]] inline Image gen_image_font_atlas(const GlyphInfo * glyphs, std::span<Rectangle *> glyphRecs, int fontSize, int padding, int packMethod) {
        return ::GenImageFontAtlas(glyphs, glyphRecs.data(), static_cast<int>(glyphRecs.size()), fontSize, padding, packMethod);
    }

    /**
     * @brief Unload font chars info data (RAM)
     */
    inline void unload_font_data(std::span<GlyphInfo> glyphs) {
        ::UnloadFontData(glyphs.data(), static_cast<int>(glyphs.size()));
    }

    /**
     * @brief Unload font from GPU memory (VRAM)
     */
    inline void unload_font(Font font) {
        ::UnloadFont(font);
    }

    /**
     * @brief Export font as code file, returns true on success
     */
    [[nodiscard]] inline bool export_font_as_code(Font font, std::string_view fileName) {
        return ::ExportFontAsCode(font, fileName.data());
    }

    /**
     * @brief Draw current FPS
     */
    inline void draw_fps(int posX, int posY) {
        ::DrawFPS(posX, posY);
    }

    /**
     * @brief Draw text (using default font)
     */
    inline void draw_text(std::string_view text, int posX, int posY, int fontSize, Color color) {
        ::DrawText(text.data(), posX, posY, fontSize, color);
    }

    /**
     * @brief Draw text using font and additional parameters
     */
    inline void draw_text_ex(Font font, std::string_view text, Vector2 position, float fontSize, float spacing, Color tint) {
        ::DrawTextEx(font, text.data(), position, fontSize, spacing, tint);
    }

    /**
     * @brief Draw text using Font and pro parameters (rotation)
     */
    inline void draw_text_pro(Font font, std::string_view text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint) {
        ::DrawTextPro(font, text.data(), position, origin, rotation, fontSize, spacing, tint);
    }

    /**
     * @brief Draw one character (codepoint)
     */
    inline void draw_text_codepoint(Font font, int codepoint, Vector2 position, float fontSize, Color tint) {
        ::DrawTextCodepoint(font, codepoint, position, fontSize, tint);
    }

    /**
     * @brief Draw multiple character (codepoint)
     */
    inline void draw_text_codepoints(Font font, std::span<const int> codepoints, Vector2 position, float fontSize, float spacing, Color tint) {
        ::DrawTextCodepoints(font, codepoints.data(), static_cast<int>(codepoints.size()), position, fontSize, spacing, tint);
    }

    /**
     * @brief Set vertical line spacing when drawing with line-breaks
     */
    inline void set_text_line_spacing(int spacing) {
        ::SetTextLineSpacing(spacing);
    }

    /**
     * @brief Measure string width for default font
     */
    [[nodiscard]] inline int measure_text(std::string_view text, int fontSize) {
        return ::MeasureText(text.data(), fontSize);
    }

    /**
     * @brief Measure string size for Font
     */
    [[nodiscard]] inline Vector2 measure_text_ex(Font font, std::string_view text, float fontSize, float spacing) {
        return ::MeasureTextEx(font, text.data(), fontSize, spacing);
    }

    /**
     * @brief Measure string size for an existing array of codepoints for Font
     */
    [[nodiscard]] inline Vector2 measure_text_codepoints(Font font, std::span<const int> codepoints, float fontSize, float spacing) {
        return ::MeasureTextCodepoints(font, codepoints.data(), static_cast<int>(codepoints.size()), fontSize, spacing);
    }

    /**
     * @brief Get glyph index position in font for a codepoint (unicode character), fallback to '?' if not found
     */
    [[nodiscard]] inline int get_glyph_index(Font font, int codepoint) {
        return ::GetGlyphIndex(font, codepoint);
    }

    /**
     * @brief Get glyph font info data for a codepoint (unicode character), fallback to '?' if not found
     */
    [[nodiscard]] inline GlyphInfo get_glyph_info(Font font, int codepoint) {
        return ::GetGlyphInfo(font, codepoint);
    }

    /**
     * @brief Get glyph rectangle in font atlas for a codepoint (unicode character), fallback to '?' if not found
     */
    [[nodiscard]] inline Rectangle get_glyph_atlas_rec(Font font, int codepoint) {
        return ::GetGlyphAtlasRec(font, codepoint);
    }

    /**
     * @brief Load UTF-8 text encoded from codepoints array
     */
    [[nodiscard]] inline std::string load_u_t_f_8(std::span<const int> codepoints) {
        const char* _ret = ::LoadUTF8(codepoints.data(), static_cast<int>(codepoints.size()));
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Unload UTF-8 text encoded from codepoints array
     */
    inline void unload_u_t_f_8(char * text) {
        ::UnloadUTF8(text);
    }

    /**
     * @brief Load all codepoints from a UTF-8 text string, codepoints count returned by parameter
     */
    [[nodiscard]] inline int * load_codepoints(std::string_view text, int * count) {
        return ::LoadCodepoints(text.data(), count);
    }

    /**
     * @brief Unload codepoints data from memory
     */
    inline void unload_codepoints(int * codepoints) {
        ::UnloadCodepoints(codepoints);
    }

    /**
     * @brief Get total number of codepoints in a UTF-8 encoded string
     */
    [[nodiscard]] inline int get_codepoint_count(std::string_view text) {
        return ::GetCodepointCount(text.data());
    }

    /**
     * @brief Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
     */
    [[nodiscard]] inline int get_codepoint(std::string_view text, int * codepointSize) {
        return ::GetCodepoint(text.data(), codepointSize);
    }

    /**
     * @brief Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
     */
    [[nodiscard]] inline int get_codepoint_next(std::string_view text, int * codepointSize) {
        return ::GetCodepointNext(text.data(), codepointSize);
    }

    /**
     * @brief Get previous codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
     */
    [[nodiscard]] inline int get_codepoint_previous(std::string_view text, int * codepointSize) {
        return ::GetCodepointPrevious(text.data(), codepointSize);
    }

    /**
     * @brief Encode one codepoint into UTF-8 byte array (array length returned as parameter)
     */
    [[nodiscard]] inline std::string codepoint_to_u_t_f_8(int codepoint, int * utf8Size) {
        const char* _ret = ::CodepointToUTF8(codepoint, utf8Size);
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Load text as separate lines ('\n')
     */
    [[nodiscard]] inline char ** load_text_lines(std::string_view text, int * count) {
        return ::LoadTextLines(text.data(), count);
    }

    /**
     * @brief Unload text lines
     */
    inline void unload_text_lines(char ** text, int lineCount) {
        ::UnloadTextLines(text, lineCount);
    }

    /**
     * @brief Copy one string to another, returns bytes copied
     */
    [[nodiscard]] inline int text_copy(char * dst, std::string_view src) {
        return ::TextCopy(dst, src.data());
    }

    /**
     * @brief Check if two text string are equal
     */
    [[nodiscard]] inline bool text_is_equal(std::string_view text1, std::string_view text2) {
        return ::TextIsEqual(text1.data(), text2.data());
    }

    /**
     * @brief Get text length, checks for '\0' ending
     */
    [[nodiscard]] inline unsigned int text_length(std::string_view text) {
        return ::TextLength(text.data());
    }

    /**
     * @brief Text formatting with variables (sprintf() style)
     */
     template <typename... Args> [[nodiscard]] inline std::string text_format(std::string_view text, Args... args) {
        const char* _ret = ::TextFormat(text.data(), args...);
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Get a piece of a text string
     */
    [[nodiscard]] inline std::string text_subtext(std::string_view text, int position, int length) {
        const char* _ret = ::TextSubtext(text.data(), position, length);
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Remove text spaces, concat words
     */
    [[nodiscard]] inline std::string text_remove_spaces(std::string_view text) {
        const char* _ret = ::TextRemoveSpaces(text.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Get text between two strings
     */
    [[nodiscard]] inline std::string get_text_between(std::string_view text, std::string_view begin, std::string_view end) {
        const char* _ret = ::GetTextBetween(text.data(), begin.data(), end.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Replace text string with new string
     */
    [[nodiscard]] inline std::string text_replace(std::string_view text, std::string_view search, std::string_view replacement) {
        const char* _ret = ::TextReplace(text.data(), search.data(), replacement.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Replace text string with new string, memory must be MemFree()
     */
    [[nodiscard]] inline std::string text_replace_alloc(std::string_view text, std::string_view search, std::string_view replacement) {
        const char* _ret = ::TextReplaceAlloc(text.data(), search.data(), replacement.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Replace text between two specific strings
     */
    [[nodiscard]] inline std::string text_replace_between(std::string_view text, std::string_view begin, std::string_view end, std::string_view replacement) {
        const char* _ret = ::TextReplaceBetween(text.data(), begin.data(), end.data(), replacement.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Replace text between two specific strings, memory must be MemFree()
     */
    [[nodiscard]] inline std::string text_replace_between_alloc(std::string_view text, std::string_view begin, std::string_view end, std::string_view replacement) {
        const char* _ret = ::TextReplaceBetweenAlloc(text.data(), begin.data(), end.data(), replacement.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Insert text in a defined byte position
     */
    [[nodiscard]] inline std::string text_insert(std::string_view text, std::string_view insert, int position) {
        const char* _ret = ::TextInsert(text.data(), insert.data(), position);
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Insert text in a defined byte position, memory must be MemFree()
     */
    [[nodiscard]] inline std::string text_insert_alloc(std::string_view text, std::string_view insert, int position) {
        const char* _ret = ::TextInsertAlloc(text.data(), insert.data(), position);
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Join text strings with delimiter
     */
    [[nodiscard]] inline std::string text_join(char ** textList, int count, std::string_view delimiter) {
        const char* _ret = ::TextJoin(textList, count, delimiter.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Split text into multiple strings, using MAX_TEXTSPLIT_COUNT static strings
     */
    [[nodiscard]] inline char ** text_split(std::string_view text, char delimiter, int * count) {
        return ::TextSplit(text.data(), delimiter, count);
    }

    /**
     * @brief Append text at specific position and move cursor
     */
    inline void text_append(char * text, std::string_view append, int * position) {
        ::TextAppend(text, append.data(), position);
    }

    /**
     * @brief Find first text occurrence within a string, -1 if not found
     */
    [[nodiscard]] inline int text_find_index(std::string_view text, std::string_view search) {
        return ::TextFindIndex(text.data(), search.data());
    }

    /**
     * @brief Get upper case version of provided string
     */
    [[nodiscard]] inline std::string text_to_upper(std::string_view text) {
        const char* _ret = ::TextToUpper(text.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Get lower case version of provided string
     */
    [[nodiscard]] inline std::string text_to_lower(std::string_view text) {
        const char* _ret = ::TextToLower(text.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Get Pascal case notation version of provided string
     */
    [[nodiscard]] inline std::string text_to_pascal(std::string_view text) {
        const char* _ret = ::TextToPascal(text.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Get Snake case notation version of provided string
     */
    [[nodiscard]] inline std::string text_to_snake(std::string_view text) {
        const char* _ret = ::TextToSnake(text.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Get Camel case notation version of provided string
     */
    [[nodiscard]] inline std::string text_to_camel(std::string_view text) {
        const char* _ret = ::TextToCamel(text.data());
        return _ret ? std::string(_ret) : std::string();
    }

    /**
     * @brief Get integer value from text
     */
    [[nodiscard]] inline int text_to_integer(std::string_view text) {
        return ::TextToInteger(text.data());
    }

    /**
     * @brief Get float value from text
     */
    [[nodiscard]] inline float text_to_float(std::string_view text) {
        return ::TextToFloat(text.data());
    }

    /**
     * @brief Draw a line in 3D world space
     */
    inline void draw_line_3d(Vector3 startPos, Vector3 endPos, Color color) {
        ::DrawLine3D(startPos, endPos, color);
    }

    /**
     * @brief Draw a point in 3D space, actually a small line
     */
    inline void draw_point_3d(Vector3 position, Color color) {
        ::DrawPoint3D(position, color);
    }

    /**
     * @brief Draw a circle in 3D world space
     */
    inline void draw_circle_3d(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color) {
        ::DrawCircle3D(center, radius, rotationAxis, rotationAngle, color);
    }

    /**
     * @brief Draw a color-filled triangle (vertex in counter-clockwise order!)
     */
    inline void draw_triangle_3d(Vector3 v1, Vector3 v2, Vector3 v3, Color color) {
        ::DrawTriangle3D(v1, v2, v3, color);
    }

    /**
     * @brief Draw a triangle strip defined by points
     */
    inline void draw_triangle_strip_3d(std::span<const Vector3> points, Color color) {
        ::DrawTriangleStrip3D(points.data(), static_cast<int>(points.size()), color);
    }

    /**
     * @brief Draw cube
     */
    inline void draw_cube(Vector3 position, float width, float height, float length, Color color) {
        ::DrawCube(position, width, height, length, color);
    }

    /**
     * @brief Draw cube (Vector version)
     */
    inline void draw_cube_v(Vector3 position, Vector3 size, Color color) {
        ::DrawCubeV(position, size, color);
    }

    /**
     * @brief Draw cube wires
     */
    inline void draw_cube_wires(Vector3 position, float width, float height, float length, Color color) {
        ::DrawCubeWires(position, width, height, length, color);
    }

    /**
     * @brief Draw cube wires (Vector version)
     */
    inline void draw_cube_wires_v(Vector3 position, Vector3 size, Color color) {
        ::DrawCubeWiresV(position, size, color);
    }

    /**
     * @brief Draw sphere
     */
    inline void draw_sphere(Vector3 centerPos, float radius, Color color) {
        ::DrawSphere(centerPos, radius, color);
    }

    /**
     * @brief Draw sphere with extended parameters
     */
    inline void draw_sphere_ex(Vector3 centerPos, float radius, int rings, int slices, Color color) {
        ::DrawSphereEx(centerPos, radius, rings, slices, color);
    }

    /**
     * @brief Draw sphere wires
     */
    inline void draw_sphere_wires(Vector3 centerPos, float radius, int rings, int slices, Color color) {
        ::DrawSphereWires(centerPos, radius, rings, slices, color);
    }

    /**
     * @brief Draw a cylinder/cone
     */
    inline void draw_cylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color) {
        ::DrawCylinder(position, radiusTop, radiusBottom, height, slices, color);
    }

    /**
     * @brief Draw a cylinder with base at startPos and top at endPos
     */
    inline void draw_cylinder_ex(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color) {
        ::DrawCylinderEx(startPos, endPos, startRadius, endRadius, sides, color);
    }

    /**
     * @brief Draw a cylinder/cone wires
     */
    inline void draw_cylinder_wires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color) {
        ::DrawCylinderWires(position, radiusTop, radiusBottom, height, slices, color);
    }

    /**
     * @brief Draw a cylinder wires with base at startPos and top at endPos
     */
    inline void draw_cylinder_wires_ex(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color) {
        ::DrawCylinderWiresEx(startPos, endPos, startRadius, endRadius, sides, color);
    }

    /**
     * @brief Draw a capsule with the center of its sphere caps at startPos and endPos
     */
    inline void draw_capsule(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color) {
        ::DrawCapsule(startPos, endPos, radius, slices, rings, color);
    }

    /**
     * @brief Draw capsule wireframe with the center of its sphere caps at startPos and endPos
     */
    inline void draw_capsule_wires(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color) {
        ::DrawCapsuleWires(startPos, endPos, radius, slices, rings, color);
    }

    /**
     * @brief Draw a plane XZ
     */
    inline void draw_plane(Vector3 centerPos, Vector2 size, Color color) {
        ::DrawPlane(centerPos, size, color);
    }

    /**
     * @brief Draw a ray line
     */
    inline void draw_ray(Ray ray, Color color) {
        ::DrawRay(ray, color);
    }

    /**
     * @brief Draw a grid (centered at (0, 0, 0))
     */
    inline void draw_grid(int slices, float spacing) {
        ::DrawGrid(slices, spacing);
    }

    /**
     * @brief Load model from files (meshes and materials)
     */
    [[nodiscard]] inline Model load_model(std::string_view fileName) {
        return ::LoadModel(fileName.data());
    }

    /**
     * @brief Load model from generated mesh (default material)
     */
    [[nodiscard]] inline Model load_model_from_mesh(Mesh mesh) {
        return ::LoadModelFromMesh(mesh);
    }

    /**
     * @brief Check if a model is valid (loaded in GPU, VAO/VBOs)
     */
    [[nodiscard]] inline bool is_model_valid(Model model) {
        return ::IsModelValid(model);
    }

    /**
     * @brief Unload model (including meshes) from memory (RAM and/or VRAM)
     */
    inline void unload_model(Model model) {
        ::UnloadModel(model);
    }

    /**
     * @brief Compute model bounding box limits (considers all meshes)
     */
    [[nodiscard]] inline BoundingBox get_model_bounding_box(Model model) {
        return ::GetModelBoundingBox(model);
    }

    /**
     * @brief Draw a model (with texture if set)
     */
    inline void draw_model(Model model, Vector3 position, float scale, Color tint) {
        ::DrawModel(model, position, scale, tint);
    }

    /**
     * @brief Draw a model with extended parameters
     */
    inline void draw_model_ex(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint) {
        ::DrawModelEx(model, position, rotationAxis, rotationAngle, scale, tint);
    }

    /**
     * @brief Draw a model wires (with texture if set)
     */
    inline void draw_model_wires(Model model, Vector3 position, float scale, Color tint) {
        ::DrawModelWires(model, position, scale, tint);
    }

    /**
     * @brief Draw a model wires (with texture if set) with extended parameters
     */
    inline void draw_model_wires_ex(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint) {
        ::DrawModelWiresEx(model, position, rotationAxis, rotationAngle, scale, tint);
    }

    /**
     * @brief Draw bounding box (wires)
     */
    inline void draw_bounding_box(BoundingBox box, Color color) {
        ::DrawBoundingBox(box, color);
    }

    /**
     * @brief Draw a billboard texture
     */
    inline void draw_billboard(Camera camera, Texture2D texture, Vector3 position, float scale, Color tint) {
        ::DrawBillboard(camera, texture, position, scale, tint);
    }

    /**
     * @brief Draw a billboard texture defined by source
     */
    inline void draw_billboard_rec(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector2 size, Color tint) {
        ::DrawBillboardRec(camera, texture, source, position, size, tint);
    }

    /**
     * @brief Draw a billboard texture defined by source and rotation
     */
    inline void draw_billboard_pro(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector3 up, Vector2 size, Vector2 origin, float rotation, Color tint) {
        ::DrawBillboardPro(camera, texture, source, position, up, size, origin, rotation, tint);
    }

    /**
     * @brief Upload mesh vertex data in GPU and provide VAO/VBO ids
     */
    inline void upload_mesh(Mesh * mesh, bool dynamic) {
        ::UploadMesh(mesh, dynamic);
    }

    /**
     * @brief Update mesh vertex data in GPU for a specific buffer index
     */
    inline void update_mesh_buffer(Mesh mesh, int index, const void * data, int dataSize, int offset) {
        ::UpdateMeshBuffer(mesh, index, data, dataSize, offset);
    }

    /**
     * @brief Unload mesh data from CPU and GPU
     */
    inline void unload_mesh(Mesh mesh) {
        ::UnloadMesh(mesh);
    }

    /**
     * @brief Draw a 3d mesh with material and transform
     */
    inline void draw_mesh(Mesh mesh, Material material, Matrix transform) {
        ::DrawMesh(mesh, material, transform);
    }

    /**
     * @brief Draw multiple mesh instances with material and different transforms
     */
    inline void draw_mesh_instanced(Mesh mesh, Material material, const Matrix * transforms, int instances) {
        ::DrawMeshInstanced(mesh, material, transforms, instances);
    }

    /**
     * @brief Compute mesh bounding box limits
     */
    [[nodiscard]] inline BoundingBox get_mesh_bounding_box(Mesh mesh) {
        return ::GetMeshBoundingBox(mesh);
    }

    /**
     * @brief Compute mesh tangents
     */
    inline void gen_mesh_tangents(Mesh * mesh) {
        ::GenMeshTangents(mesh);
    }

    /**
     * @brief Export mesh data to file, returns true on success
     */
    [[nodiscard]] inline bool export_mesh(Mesh mesh, std::string_view fileName) {
        return ::ExportMesh(mesh, fileName.data());
    }

    /**
     * @brief Export mesh as code file (.h) defining multiple arrays of vertex attributes
     */
    [[nodiscard]] inline bool export_mesh_as_code(Mesh mesh, std::string_view fileName) {
        return ::ExportMeshAsCode(mesh, fileName.data());
    }

    /**
     * @brief Generate polygonal mesh
     */
    [[nodiscard]] inline Mesh gen_mesh_poly(int sides, float radius) {
        return ::GenMeshPoly(sides, radius);
    }

    /**
     * @brief Generate plane mesh (with subdivisions)
     */
    [[nodiscard]] inline Mesh gen_mesh_plane(float width, float length, int resX, int resZ) {
        return ::GenMeshPlane(width, length, resX, resZ);
    }

    /**
     * @brief Generate cuboid mesh
     */
    [[nodiscard]] inline Mesh gen_mesh_cube(float width, float height, float length) {
        return ::GenMeshCube(width, height, length);
    }

    /**
     * @brief Generate sphere mesh (standard sphere)
     */
    [[nodiscard]] inline Mesh gen_mesh_sphere(float radius, int rings, int slices) {
        return ::GenMeshSphere(radius, rings, slices);
    }

    /**
     * @brief Generate half-sphere mesh (no bottom cap)
     */
    [[nodiscard]] inline Mesh gen_mesh_hemi_sphere(float radius, int rings, int slices) {
        return ::GenMeshHemiSphere(radius, rings, slices);
    }

    /**
     * @brief Generate cylinder mesh
     */
    [[nodiscard]] inline Mesh gen_mesh_cylinder(float radius, float height, int slices) {
        return ::GenMeshCylinder(radius, height, slices);
    }

    /**
     * @brief Generate cone/pyramid mesh
     */
    [[nodiscard]] inline Mesh gen_mesh_cone(float radius, float height, int slices) {
        return ::GenMeshCone(radius, height, slices);
    }

    /**
     * @brief Generate torus mesh
     */
    [[nodiscard]] inline Mesh gen_mesh_torus(float radius, float size, int radSeg, int sides) {
        return ::GenMeshTorus(radius, size, radSeg, sides);
    }

    /**
     * @brief Generate trefoil knot mesh
     */
    [[nodiscard]] inline Mesh gen_mesh_knot(float radius, float size, int radSeg, int sides) {
        return ::GenMeshKnot(radius, size, radSeg, sides);
    }

    /**
     * @brief Generate heightmap mesh from image data
     */
    [[nodiscard]] inline Mesh gen_mesh_heightmap(Image heightmap, Vector3 size) {
        return ::GenMeshHeightmap(heightmap, size);
    }

    /**
     * @brief Generate cubes-based map mesh from image data
     */
    [[nodiscard]] inline Mesh gen_mesh_cubicmap(Image cubicmap, Vector3 cubeSize) {
        return ::GenMeshCubicmap(cubicmap, cubeSize);
    }

    /**
     * @brief Load materials from model file
     */
    [[nodiscard]] inline Material * load_materials(std::string_view fileName, int * materialCount) {
        return ::LoadMaterials(fileName.data(), materialCount);
    }

    /**
     * @brief Load default material (Supports: DIFFUSE, SPECULAR, NORMAL maps)
     */
    [[nodiscard]] inline Material load_material_default() {
        return ::LoadMaterialDefault();
    }

    /**
     * @brief Check if a material is valid (shader assigned, map textures loaded in GPU)
     */
    [[nodiscard]] inline bool is_material_valid(Material material) {
        return ::IsMaterialValid(material);
    }

    /**
     * @brief Unload material from GPU memory (VRAM)
     */
    inline void unload_material(Material material) {
        ::UnloadMaterial(material);
    }

    /**
     * @brief Set texture for a material map type (MATERIAL_MAP_DIFFUSE, MATERIAL_MAP_SPECULAR...)
     */
    inline void set_material_texture(Material * material, int mapType, Texture2D texture) {
        ::SetMaterialTexture(material, mapType, texture);
    }

    /**
     * @brief Set material for a mesh
     */
    inline void set_model_mesh_material(Model * model, int meshId, int materialId) {
        ::SetModelMeshMaterial(model, meshId, materialId);
    }

    /**
     * @brief Load model animations from file
     */
    [[nodiscard]] inline ModelAnimation * load_model_animations(std::string_view fileName, int * animCount) {
        return ::LoadModelAnimations(fileName.data(), animCount);
    }

    /**
     * @brief Update model animation pose (vertex buffers and bone matrices)
     */
    inline void update_model_animation(Model model, ModelAnimation anim, float frame) {
        ::UpdateModelAnimation(model, anim, frame);
    }

    /**
     * @brief Update model animation pose, blending two animations
     */
    inline void update_model_animation_ex(Model model, ModelAnimation animA, float frameA, ModelAnimation animB, float frameB, float blend) {
        ::UpdateModelAnimationEx(model, animA, frameA, animB, frameB, blend);
    }

    /**
     * @brief Unload animation array data
     */
    inline void unload_model_animations(std::span<ModelAnimation> animations) {
        ::UnloadModelAnimations(animations.data(), static_cast<int>(animations.size()));
    }

    /**
     * @brief Check model animation skeleton match
     */
    [[nodiscard]] inline bool is_model_animation_valid(Model model, ModelAnimation anim) {
        return ::IsModelAnimationValid(model, anim);
    }

    /**
     * @brief Check collision between two spheres
     */
    [[nodiscard]] inline bool check_collision_spheres(Vector3 center1, float radius1, Vector3 center2, float radius2) {
        return ::CheckCollisionSpheres(center1, radius1, center2, radius2);
    }

    /**
     * @brief Check collision between two bounding boxes
     */
    [[nodiscard]] inline bool check_collision_boxes(BoundingBox box1, BoundingBox box2) {
        return ::CheckCollisionBoxes(box1, box2);
    }

    /**
     * @brief Check collision between box and sphere
     */
    [[nodiscard]] inline bool check_collision_box_sphere(BoundingBox box, Vector3 center, float radius) {
        return ::CheckCollisionBoxSphere(box, center, radius);
    }

    /**
     * @brief Get collision info between ray and sphere
     */
    [[nodiscard]] inline RayCollision get_ray_collision_sphere(Ray ray, Vector3 center, float radius) {
        return ::GetRayCollisionSphere(ray, center, radius);
    }

    /**
     * @brief Get collision info between ray and box
     */
    [[nodiscard]] inline RayCollision get_ray_collision_box(Ray ray, BoundingBox box) {
        return ::GetRayCollisionBox(ray, box);
    }

    /**
     * @brief Get collision info between ray and mesh
     */
    [[nodiscard]] inline RayCollision get_ray_collision_mesh(Ray ray, Mesh mesh, Matrix transform) {
        return ::GetRayCollisionMesh(ray, mesh, transform);
    }

    /**
     * @brief Get collision info between ray and triangle
     */
    [[nodiscard]] inline RayCollision get_ray_collision_triangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3) {
        return ::GetRayCollisionTriangle(ray, p1, p2, p3);
    }

    /**
     * @brief Get collision info between ray and quad
     */
    [[nodiscard]] inline RayCollision get_ray_collision_quad(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4) {
        return ::GetRayCollisionQuad(ray, p1, p2, p3, p4);
    }

    /**
     * @brief Initialize audio device and context
     */
    inline void init_audio_device() {
        ::InitAudioDevice();
    }

    /**
     * @brief Close the audio device and context
     */
    inline void close_audio_device() {
        ::CloseAudioDevice();
    }

    /**
     * @brief Check if audio device has been initialized successfully
     */
    [[nodiscard]] inline bool is_audio_device_ready() {
        return ::IsAudioDeviceReady();
    }

    /**
     * @brief Set master volume (listener)
     */
    inline void set_master_volume(float volume) {
        ::SetMasterVolume(volume);
    }

    /**
     * @brief Get master volume (listener)
     */
    [[nodiscard]] inline float get_master_volume() {
        return ::GetMasterVolume();
    }

    /**
     * @brief Load wave data from file
     */
    [[nodiscard]] inline Wave load_wave(std::string_view fileName) {
        return ::LoadWave(fileName.data());
    }

    /**
     * @brief Load wave from memory buffer, fileType refers to extension: i.e. '.wav'
     */
    [[nodiscard]] inline Wave load_wave_from_memory(std::string_view fileType, const unsigned char * fileData, int dataSize) {
        return ::LoadWaveFromMemory(fileType.data(), fileData, dataSize);
    }

    /**
     * @brief Checks if wave data is valid (data loaded and parameters)
     */
    [[nodiscard]] inline bool is_wave_valid(Wave wave) {
        return ::IsWaveValid(wave);
    }

    /**
     * @brief Load sound from file
     */
    [[nodiscard]] inline Sound load_sound(std::string_view fileName) {
        return ::LoadSound(fileName.data());
    }

    /**
     * @brief Load sound from wave data
     */
    [[nodiscard]] inline Sound load_sound_from_wave(Wave wave) {
        return ::LoadSoundFromWave(wave);
    }

    /**
     * @brief Create a new sound that shares the same sample data as the source sound, does not own the sound data
     */
    [[nodiscard]] inline Sound load_sound_alias(Sound source) {
        return ::LoadSoundAlias(source);
    }

    /**
     * @brief Checks if a sound is valid (data loaded and buffers initialized)
     */
    [[nodiscard]] inline bool is_sound_valid(Sound sound) {
        return ::IsSoundValid(sound);
    }

    /**
     * @brief Update sound buffer with new data (default data format: 32 bit float, stereo)
     */
    inline void update_sound(Sound sound, const void * data, int sampleCount) {
        ::UpdateSound(sound, data, sampleCount);
    }

    /**
     * @brief Unload wave data
     */
    inline void unload_wave(Wave wave) {
        ::UnloadWave(wave);
    }

    /**
     * @brief Unload sound
     */
    inline void unload_sound(Sound sound) {
        ::UnloadSound(sound);
    }

    /**
     * @brief Unload a sound alias (does not deallocate sample data)
     */
    inline void unload_sound_alias(Sound alias) {
        ::UnloadSoundAlias(alias);
    }

    /**
     * @brief Export wave data to file, returns true on success
     */
    [[nodiscard]] inline bool export_wave(Wave wave, std::string_view fileName) {
        return ::ExportWave(wave, fileName.data());
    }

    /**
     * @brief Export wave sample data to code (.h), returns true on success
     */
    [[nodiscard]] inline bool export_wave_as_code(Wave wave, std::string_view fileName) {
        return ::ExportWaveAsCode(wave, fileName.data());
    }

    /**
     * @brief Play a sound
     */
    inline void play_sound(Sound sound) {
        ::PlaySound(sound);
    }

    /**
     * @brief Stop playing a sound
     */
    inline void stop_sound(Sound sound) {
        ::StopSound(sound);
    }

    /**
     * @brief Pause a sound
     */
    inline void pause_sound(Sound sound) {
        ::PauseSound(sound);
    }

    /**
     * @brief Resume a paused sound
     */
    inline void resume_sound(Sound sound) {
        ::ResumeSound(sound);
    }

    /**
     * @brief Check if a sound is currently playing
     */
    [[nodiscard]] inline bool is_sound_playing(Sound sound) {
        return ::IsSoundPlaying(sound);
    }

    /**
     * @brief Set volume for a sound (1.0 is max level)
     */
    inline void set_sound_volume(Sound sound, float volume) {
        ::SetSoundVolume(sound, volume);
    }

    /**
     * @brief Set pitch for a sound (1.0 is base level)
     */
    inline void set_sound_pitch(Sound sound, float pitch) {
        ::SetSoundPitch(sound, pitch);
    }

    /**
     * @brief Set pan for a sound (-1.0 left, 0.0 center, 1.0 right)
     */
    inline void set_sound_pan(Sound sound, float pan) {
        ::SetSoundPan(sound, pan);
    }

    /**
     * @brief Copy a wave to a new wave
     */
    [[nodiscard]] inline Wave wave_copy(Wave wave) {
        return ::WaveCopy(wave);
    }

    /**
     * @brief Crop a wave to defined frames range
     */
    inline void wave_crop(Wave * wave, int initFrame, int finalFrame) {
        ::WaveCrop(wave, initFrame, finalFrame);
    }

    /**
     * @brief Convert wave data to desired format
     */
    inline void wave_format(Wave * wave, int sampleRate, int sampleSize, int channels) {
        ::WaveFormat(wave, sampleRate, sampleSize, channels);
    }

    /**
     * @brief Load samples data from wave as a 32bit float data array
     */
    [[nodiscard]] inline float * load_wave_samples(Wave wave) {
        return ::LoadWaveSamples(wave);
    }

    /**
     * @brief Unload samples data loaded with LoadWaveSamples()
     */
    inline void unload_wave_samples(float * samples) {
        ::UnloadWaveSamples(samples);
    }

    /**
     * @brief Load music stream from file
     */
    [[nodiscard]] inline Music load_music_stream(std::string_view fileName) {
        return ::LoadMusicStream(fileName.data());
    }

    /**
     * @brief Load music stream from data
     */
    [[nodiscard]] inline Music load_music_stream_from_memory(std::string_view fileType, const unsigned char * data, int dataSize) {
        return ::LoadMusicStreamFromMemory(fileType.data(), data, dataSize);
    }

    /**
     * @brief Checks if a music stream is valid (context and buffers initialized)
     */
    [[nodiscard]] inline bool is_music_valid(Music music) {
        return ::IsMusicValid(music);
    }

    /**
     * @brief Unload music stream
     */
    inline void unload_music_stream(Music music) {
        ::UnloadMusicStream(music);
    }

    /**
     * @brief Start music playing
     */
    inline void play_music_stream(Music music) {
        ::PlayMusicStream(music);
    }

    /**
     * @brief Check if music is playing
     */
    [[nodiscard]] inline bool is_music_stream_playing(Music music) {
        return ::IsMusicStreamPlaying(music);
    }

    /**
     * @brief Updates buffers for music streaming
     */
    inline void update_music_stream(Music music) {
        ::UpdateMusicStream(music);
    }

    /**
     * @brief Stop music playing
     */
    inline void stop_music_stream(Music music) {
        ::StopMusicStream(music);
    }

    /**
     * @brief Pause music playing
     */
    inline void pause_music_stream(Music music) {
        ::PauseMusicStream(music);
    }

    /**
     * @brief Resume playing paused music
     */
    inline void resume_music_stream(Music music) {
        ::ResumeMusicStream(music);
    }

    /**
     * @brief Seek music to a position (in seconds)
     */
    inline void seek_music_stream(Music music, float position) {
        ::SeekMusicStream(music, position);
    }

    /**
     * @brief Set volume for music (1.0 is max level)
     */
    inline void set_music_volume(Music music, float volume) {
        ::SetMusicVolume(music, volume);
    }

    /**
     * @brief Set pitch for a music (1.0 is base level)
     */
    inline void set_music_pitch(Music music, float pitch) {
        ::SetMusicPitch(music, pitch);
    }

    /**
     * @brief Set pan for a music (-1.0 left, 0.0 center, 1.0 right)
     */
    inline void set_music_pan(Music music, float pan) {
        ::SetMusicPan(music, pan);
    }

    /**
     * @brief Get music time length (in seconds)
     */
    [[nodiscard]] inline float get_music_time_length(Music music) {
        return ::GetMusicTimeLength(music);
    }

    /**
     * @brief Get current music time played (in seconds)
     */
    [[nodiscard]] inline float get_music_time_played(Music music) {
        return ::GetMusicTimePlayed(music);
    }

    /**
     * @brief Load audio stream (to stream raw audio pcm data)
     */
    [[nodiscard]] inline AudioStream load_audio_stream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels) {
        return ::LoadAudioStream(sampleRate, sampleSize, channels);
    }

    /**
     * @brief Checks if an audio stream is valid (buffers initialized)
     */
    [[nodiscard]] inline bool is_audio_stream_valid(AudioStream stream) {
        return ::IsAudioStreamValid(stream);
    }

    /**
     * @brief Unload audio stream and free memory
     */
    inline void unload_audio_stream(AudioStream stream) {
        ::UnloadAudioStream(stream);
    }

    /**
     * @brief Update audio stream buffers with data
     */
    inline void update_audio_stream(AudioStream stream, const void * data, int frameCount) {
        ::UpdateAudioStream(stream, data, frameCount);
    }

    /**
     * @brief Check if any audio stream buffers requires refill
     */
    [[nodiscard]] inline bool is_audio_stream_processed(AudioStream stream) {
        return ::IsAudioStreamProcessed(stream);
    }

    /**
     * @brief Play audio stream
     */
    inline void play_audio_stream(AudioStream stream) {
        ::PlayAudioStream(stream);
    }

    /**
     * @brief Pause audio stream
     */
    inline void pause_audio_stream(AudioStream stream) {
        ::PauseAudioStream(stream);
    }

    /**
     * @brief Resume audio stream
     */
    inline void resume_audio_stream(AudioStream stream) {
        ::ResumeAudioStream(stream);
    }

    /**
     * @brief Check if audio stream is playing
     */
    [[nodiscard]] inline bool is_audio_stream_playing(AudioStream stream) {
        return ::IsAudioStreamPlaying(stream);
    }

    /**
     * @brief Stop audio stream
     */
    inline void stop_audio_stream(AudioStream stream) {
        ::StopAudioStream(stream);
    }

    /**
     * @brief Set volume for audio stream (1.0 is max level)
     */
    inline void set_audio_stream_volume(AudioStream stream, float volume) {
        ::SetAudioStreamVolume(stream, volume);
    }

    /**
     * @brief Set pitch for audio stream (1.0 is base level)
     */
    inline void set_audio_stream_pitch(AudioStream stream, float pitch) {
        ::SetAudioStreamPitch(stream, pitch);
    }

    /**
     * @brief Set pan for audio stream (-1.0 to 1.0 range, 0.0 is centered)
     */
    inline void set_audio_stream_pan(AudioStream stream, float pan) {
        ::SetAudioStreamPan(stream, pan);
    }

    /**
     * @brief Default size for new audio streams
     */
    inline void set_audio_stream_buffer_size_default(int size) {
        ::SetAudioStreamBufferSizeDefault(size);
    }

    /**
     * @brief Audio thread callback to request new data
     */
    inline void set_audio_stream_callback(AudioStream stream, AudioCallback callback) {
        ::SetAudioStreamCallback(stream, callback);
    }

    /**
     * @brief Attach audio stream processor to stream, receives frames x 2 samples as 'float' (stereo)
     */
    inline void attach_audio_stream_processor(AudioStream stream, AudioCallback processor) {
        ::AttachAudioStreamProcessor(stream, processor);
    }

    /**
     * @brief Detach audio stream processor from stream
     */
    inline void detach_audio_stream_processor(AudioStream stream, AudioCallback processor) {
        ::DetachAudioStreamProcessor(stream, processor);
    }

    /**
     * @brief Attach audio stream processor to the entire audio pipeline, receives frames x 2 samples as 'float' (stereo)
     */
    inline void attach_audio_mixed_processor(AudioCallback processor) {
        ::AttachAudioMixedProcessor(processor);
    }

    /**
     * @brief Detach audio stream processor from the entire audio pipeline
     */
    inline void detach_audio_mixed_processor(AudioCallback processor) {
        ::DetachAudioMixedProcessor(processor);
    }


} // namespace RaylibStd