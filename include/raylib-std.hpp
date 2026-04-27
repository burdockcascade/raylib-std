#pragma once
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
    inline void InitWindow(int width, int height, std::string_view title) {
        ::InitWindow(width, height, title.data());
    }
/**
     * @brief Close window and unload OpenGL context
     */
    inline void CloseWindow() {
        ::CloseWindow();
    }
/**
     * @brief Check if application should close (KEY_ESCAPE pressed or windows close icon clicked)
     */
    [[nodiscard]] inline bool WindowShouldClose() {
        return ::WindowShouldClose();
    }
/**
     * @brief Check if window has been initialized successfully
     */
    [[nodiscard]] inline bool IsWindowReady() {
        return ::IsWindowReady();
    }
/**
     * @brief Check if window is currently fullscreen
     */
    [[nodiscard]] inline bool IsWindowFullscreen() {
        return ::IsWindowFullscreen();
    }
/**
     * @brief Check if window is currently hidden
     */
    [[nodiscard]] inline bool IsWindowHidden() {
        return ::IsWindowHidden();
    }
/**
     * @brief Check if window is currently minimized
     */
    [[nodiscard]] inline bool IsWindowMinimized() {
        return ::IsWindowMinimized();
    }
/**
     * @brief Check if window is currently maximized
     */
    [[nodiscard]] inline bool IsWindowMaximized() {
        return ::IsWindowMaximized();
    }
/**
     * @brief Check if window is currently focused
     */
    [[nodiscard]] inline bool IsWindowFocused() {
        return ::IsWindowFocused();
    }
/**
     * @brief Check if window has been resized last frame
     */
    [[nodiscard]] inline bool IsWindowResized() {
        return ::IsWindowResized();
    }
/**
     * @brief Check if one specific window flag is enabled
     */
    [[nodiscard]] inline bool IsWindowState(unsigned int flag) {
        return ::IsWindowState(flag);
    }
/**
     * @brief Set window configuration state using flags
     */
    inline void SetWindowState(unsigned int flags) {
        ::SetWindowState(flags);
    }
/**
     * @brief Clear window configuration state flags
     */
    inline void ClearWindowState(unsigned int flags) {
        ::ClearWindowState(flags);
    }
/**
     * @brief Toggle window state: fullscreen/windowed, resizes monitor to match window resolution
     */
    inline void ToggleFullscreen() {
        ::ToggleFullscreen();
    }
/**
     * @brief Toggle window state: borderless windowed, resizes window to match monitor resolution
     */
    inline void ToggleBorderlessWindowed() {
        ::ToggleBorderlessWindowed();
    }
/**
     * @brief Set window state: maximized, if resizable
     */
    inline void MaximizeWindow() {
        ::MaximizeWindow();
    }
/**
     * @brief Set window state: minimized, if resizable
     */
    inline void MinimizeWindow() {
        ::MinimizeWindow();
    }
/**
     * @brief Restore window from being minimized/maximized
     */
    inline void RestoreWindow() {
        ::RestoreWindow();
    }
/**
     * @brief Set icon for window (single image, RGBA 32bit)
     */
    inline void SetWindowIcon(Image image) {
        ::SetWindowIcon(image);
    }
/**
     * @brief Set icon for window (multiple images, RGBA 32bit)
     */
    inline void SetWindowIcons(std::span<Image> images) {
        ::SetWindowIcons(images.data(), static_cast<int>(images.size()));
    }
/**
     * @brief Set title for window
     */
    inline void SetWindowTitle(std::string_view title) {
        ::SetWindowTitle(title.data());
    }
/**
     * @brief Set window position on screen
     */
    inline void SetWindowPosition(int x, int y) {
        ::SetWindowPosition(x, y);
    }
/**
     * @brief Set monitor for the current window
     */
    inline void SetWindowMonitor(int monitor) {
        ::SetWindowMonitor(monitor);
    }
/**
     * @brief Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
     */
    inline void SetWindowMinSize(int width, int height) {
        ::SetWindowMinSize(width, height);
    }
/**
     * @brief Set window maximum dimensions (for FLAG_WINDOW_RESIZABLE)
     */
    inline void SetWindowMaxSize(int width, int height) {
        ::SetWindowMaxSize(width, height);
    }
/**
     * @brief Set window dimensions
     */
    inline void SetWindowSize(int width, int height) {
        ::SetWindowSize(width, height);
    }
/**
     * @brief Set window opacity [0.0f..1.0f]
     */
    inline void SetWindowOpacity(float opacity) {
        ::SetWindowOpacity(opacity);
    }
/**
     * @brief Set window focused
     */
    inline void SetWindowFocused() {
        ::SetWindowFocused();
    }
/**
     * @brief Get native window handle
     */
    inline void * GetWindowHandle() {
        return ::GetWindowHandle();
    }
/**
     * @brief Get current screen width
     */
    inline int GetScreenWidth() {
        return ::GetScreenWidth();
    }
/**
     * @brief Get current screen height
     */
    inline int GetScreenHeight() {
        return ::GetScreenHeight();
    }
/**
     * @brief Get current render width (it considers HiDPI)
     */
    inline int GetRenderWidth() {
        return ::GetRenderWidth();
    }
/**
     * @brief Get current render height (it considers HiDPI)
     */
    inline int GetRenderHeight() {
        return ::GetRenderHeight();
    }
/**
     * @brief Get number of connected monitors
     */
    inline int GetMonitorCount() {
        return ::GetMonitorCount();
    }
/**
     * @brief Get current monitor where window is placed
     */
    inline int GetCurrentMonitor() {
        return ::GetCurrentMonitor();
    }
/**
     * @brief Get specified monitor position
     */
    inline Vector2 GetMonitorPosition(int monitor) {
        return ::GetMonitorPosition(monitor);
    }
/**
     * @brief Get specified monitor width (current video mode used by monitor)
     */
    inline int GetMonitorWidth(int monitor) {
        return ::GetMonitorWidth(monitor);
    }
/**
     * @brief Get specified monitor height (current video mode used by monitor)
     */
    inline int GetMonitorHeight(int monitor) {
        return ::GetMonitorHeight(monitor);
    }
/**
     * @brief Get specified monitor physical width in millimetres
     */
    inline int GetMonitorPhysicalWidth(int monitor) {
        return ::GetMonitorPhysicalWidth(monitor);
    }
/**
     * @brief Get specified monitor physical height in millimetres
     */
    inline int GetMonitorPhysicalHeight(int monitor) {
        return ::GetMonitorPhysicalHeight(monitor);
    }
/**
     * @brief Get specified monitor refresh rate
     */
    inline int GetMonitorRefreshRate(int monitor) {
        return ::GetMonitorRefreshRate(monitor);
    }
/**
     * @brief Get window position XY on monitor
     */
    inline Vector2 GetWindowPosition() {
        return ::GetWindowPosition();
    }
/**
     * @brief Get window scale DPI factor
     */
    inline Vector2 GetWindowScaleDPI() {
        return ::GetWindowScaleDPI();
    }
/**
     * @brief Get the human-readable, UTF-8 encoded name of the specified monitor
     */
    inline const char * GetMonitorName(int monitor) {
        return ::GetMonitorName(monitor);
    }
/**
     * @brief Set clipboard text content
     */
    inline void SetClipboardText(std::string_view text) {
        ::SetClipboardText(text.data());
    }
/**
     * @brief Get clipboard text content
     */
    inline const char * GetClipboardText() {
        return ::GetClipboardText();
    }
/**
     * @brief Get clipboard image content
     */
    inline Image GetClipboardImage() {
        return ::GetClipboardImage();
    }
/**
     * @brief Enable waiting for events on EndDrawing(), no automatic event polling
     */
    inline void EnableEventWaiting() {
        ::EnableEventWaiting();
    }
/**
     * @brief Disable waiting for events on EndDrawing(), automatic events polling
     */
    inline void DisableEventWaiting() {
        ::DisableEventWaiting();
    }
/**
     * @brief Shows cursor
     */
    inline void ShowCursor() {
        ::ShowCursor();
    }
/**
     * @brief Hides cursor
     */
    inline void HideCursor() {
        ::HideCursor();
    }
/**
     * @brief Check if cursor is not visible
     */
    [[nodiscard]] inline bool IsCursorHidden() {
        return ::IsCursorHidden();
    }
/**
     * @brief Enables cursor (unlock cursor)
     */
    inline void EnableCursor() {
        ::EnableCursor();
    }
/**
     * @brief Disables cursor (lock cursor)
     */
    inline void DisableCursor() {
        ::DisableCursor();
    }
/**
     * @brief Check if cursor is on the screen
     */
    [[nodiscard]] inline bool IsCursorOnScreen() {
        return ::IsCursorOnScreen();
    }
/**
     * @brief Set background color (framebuffer clear color)
     */
    inline void ClearBackground(Color color) {
        ::ClearBackground(color);
    }
/**
     * @brief Setup canvas (framebuffer) to start drawing
     */
    inline void BeginDrawing() {
        ::BeginDrawing();
    }
/**
     * @brief End canvas drawing and swap buffers (double buffering)
     */
    inline void EndDrawing() {
        ::EndDrawing();
    }
/**
     * @brief Begin 2D mode with custom camera (2D)
     */
    inline void BeginMode2D(Camera2D camera) {
        ::BeginMode2D(camera);
    }
/**
     * @brief Ends 2D mode with custom camera
     */
    inline void EndMode2D() {
        ::EndMode2D();
    }
/**
     * @brief Begin 3D mode with custom camera (3D)
     */
    inline void BeginMode3D(Camera3D camera) {
        ::BeginMode3D(camera);
    }
/**
     * @brief Ends 3D mode and returns to default 2D orthographic mode
     */
    inline void EndMode3D() {
        ::EndMode3D();
    }
/**
     * @brief Begin drawing to render texture
     */
    inline void BeginTextureMode(RenderTexture2D target) {
        ::BeginTextureMode(target);
    }
/**
     * @brief Ends drawing to render texture
     */
    inline void EndTextureMode() {
        ::EndTextureMode();
    }
/**
     * @brief Begin custom shader drawing
     */
    inline void BeginShaderMode(Shader shader) {
        ::BeginShaderMode(shader);
    }
/**
     * @brief End custom shader drawing (use default shader)
     */
    inline void EndShaderMode() {
        ::EndShaderMode();
    }
/**
     * @brief Begin blending mode (alpha, additive, multiplied, subtract, custom)
     */
    inline void BeginBlendMode(int mode) {
        ::BeginBlendMode(mode);
    }
/**
     * @brief End blending mode (reset to default: alpha blending)
     */
    inline void EndBlendMode() {
        ::EndBlendMode();
    }
/**
     * @brief Begin scissor mode (define screen area for following drawing)
     */
    inline void BeginScissorMode(int x, int y, int width, int height) {
        ::BeginScissorMode(x, y, width, height);
    }
/**
     * @brief End scissor mode
     */
    inline void EndScissorMode() {
        ::EndScissorMode();
    }
/**
     * @brief Begin stereo rendering (requires VR simulator)
     */
    inline void BeginVrStereoMode(VrStereoConfig config) {
        ::BeginVrStereoMode(config);
    }
/**
     * @brief End stereo rendering (requires VR simulator)
     */
    inline void EndVrStereoMode() {
        ::EndVrStereoMode();
    }
/**
     * @brief Load VR stereo config for VR simulator device parameters
     */
    inline VrStereoConfig LoadVrStereoConfig(VrDeviceInfo device) {
        return ::LoadVrStereoConfig(device);
    }
/**
     * @brief Unload VR stereo config
     */
    inline void UnloadVrStereoConfig(VrStereoConfig config) {
        ::UnloadVrStereoConfig(config);
    }
/**
     * @brief Load shader from files and bind default locations
     */
    inline Shader LoadShader(std::string_view vsFileName, std::string_view fsFileName) {
        return ::LoadShader(vsFileName.data(), fsFileName.data());
    }
/**
     * @brief Load shader from code strings and bind default locations
     */
    inline Shader LoadShaderFromMemory(std::string_view vsCode, std::string_view fsCode) {
        return ::LoadShaderFromMemory(vsCode.data(), fsCode.data());
    }
/**
     * @brief Check if a shader is valid (loaded on GPU)
     */
    [[nodiscard]] inline bool IsShaderValid(Shader shader) {
        return ::IsShaderValid(shader);
    }
/**
     * @brief Get shader uniform location
     */
    inline int GetShaderLocation(Shader shader, std::string_view uniformName) {
        return ::GetShaderLocation(shader, uniformName.data());
    }
/**
     * @brief Get shader attribute location
     */
    inline int GetShaderLocationAttrib(Shader shader, std::string_view attribName) {
        return ::GetShaderLocationAttrib(shader, attribName.data());
    }
/**
     * @brief Set shader uniform value
     */
    inline void SetShaderValue(Shader shader, int locIndex, const void * value, int uniformType) {
        ::SetShaderValue(shader, locIndex, value, uniformType);
    }
/**
     * @brief Set shader uniform value vector
     */
    inline void SetShaderValueV(Shader shader, int locIndex, const void * value, int uniformType, int count) {
        ::SetShaderValueV(shader, locIndex, value, uniformType, count);
    }
/**
     * @brief Set shader uniform value (matrix 4x4)
     */
    inline void SetShaderValueMatrix(Shader shader, int locIndex, Matrix mat) {
        ::SetShaderValueMatrix(shader, locIndex, mat);
    }
/**
     * @brief Set shader uniform value and bind the texture (sampler2d)
     */
    inline void SetShaderValueTexture(Shader shader, int locIndex, Texture2D texture) {
        ::SetShaderValueTexture(shader, locIndex, texture);
    }
/**
     * @brief Unload shader from GPU memory (VRAM)
     */
    inline void UnloadShader(Shader shader) {
        ::UnloadShader(shader);
    }
/**
     * @brief Get a ray trace from screen position (i.e mouse)
     */
    inline Ray GetScreenToWorldRay(Vector2 position, Camera camera) {
        return ::GetScreenToWorldRay(position, camera);
    }
/**
     * @brief Get a ray trace from screen position (i.e mouse) in a viewport
     */
    inline Ray GetScreenToWorldRayEx(Vector2 position, Camera camera, int width, int height) {
        return ::GetScreenToWorldRayEx(position, camera, width, height);
    }
/**
     * @brief Get the screen space position for a 3d world space position
     */
    inline Vector2 GetWorldToScreen(Vector3 position, Camera camera) {
        return ::GetWorldToScreen(position, camera);
    }
/**
     * @brief Get size position for a 3d world space position
     */
    inline Vector2 GetWorldToScreenEx(Vector3 position, Camera camera, int width, int height) {
        return ::GetWorldToScreenEx(position, camera, width, height);
    }
/**
     * @brief Get the screen space position for a 2d camera world space position
     */
    inline Vector2 GetWorldToScreen2D(Vector2 position, Camera2D camera) {
        return ::GetWorldToScreen2D(position, camera);
    }
/**
     * @brief Get the world space position for a 2d camera screen space position
     */
    inline Vector2 GetScreenToWorld2D(Vector2 position, Camera2D camera) {
        return ::GetScreenToWorld2D(position, camera);
    }
/**
     * @brief Get camera transform matrix (view matrix)
     */
    inline Matrix GetCameraMatrix(Camera camera) {
        return ::GetCameraMatrix(camera);
    }
/**
     * @brief Get camera 2d transform matrix
     */
    inline Matrix GetCameraMatrix2D(Camera2D camera) {
        return ::GetCameraMatrix2D(camera);
    }
/**
     * @brief Set target FPS (maximum)
     */
    inline void SetTargetFPS(int fps) {
        ::SetTargetFPS(fps);
    }
/**
     * @brief Get time in seconds for last frame drawn (delta time)
     */
    inline float GetFrameTime() {
        return ::GetFrameTime();
    }
/**
     * @brief Get elapsed time in seconds since InitWindow()
     */
    inline double GetTime() {
        return ::GetTime();
    }
/**
     * @brief Get current FPS
     */
    inline int GetFPS() {
        return ::GetFPS();
    }
/**
     * @brief Swap back buffer with front buffer (screen drawing)
     */
    inline void SwapScreenBuffer() {
        ::SwapScreenBuffer();
    }
/**
     * @brief Register all input events
     */
    inline void PollInputEvents() {
        ::PollInputEvents();
    }
/**
     * @brief Wait for some time (halt program execution)
     */
    inline void WaitTime(double seconds) {
        ::WaitTime(seconds);
    }
/**
     * @brief Set the seed for the random number generator
     */
    inline void SetRandomSeed(unsigned int seed) {
        ::SetRandomSeed(seed);
    }
/**
     * @brief Get a random value between min and max (both included)
     */
    inline int GetRandomValue(int min, int max) {
        return ::GetRandomValue(min, max);
    }
/**
     * @brief Load random values sequence, no values repeated
     */
    inline int * LoadRandomSequence(unsigned int count, int min, int max) {
        return ::LoadRandomSequence(count, min, max);
    }
/**
     * @brief Unload random values sequence
     */
    inline void UnloadRandomSequence(int * sequence) {
        ::UnloadRandomSequence(sequence);
    }
/**
     * @brief Takes a screenshot of current screen (filename extension defines format)
     */
    inline void TakeScreenshot(std::string_view fileName) {
        ::TakeScreenshot(fileName.data());
    }
/**
     * @brief Setup init configuration flags (view FLAGS)
     */
    inline void SetConfigFlags(unsigned int flags) {
        ::SetConfigFlags(flags);
    }
/**
     * @brief Open URL with default system browser (if available)
     */
    inline void OpenURL(std::string_view url) {
        ::OpenURL(url.data());
    }
/**
     * @brief Set the current threshold (minimum) log level
     */
    inline void SetTraceLogLevel(int logLevel) {
        ::SetTraceLogLevel(logLevel);
    }
/**
     * @brief Show trace log messages (LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR...)
     */
    template <typename... Args>
    inline void TraceLog(int logLevel, std::string_view text, Args... args) {
        ::TraceLog(logLevel, text.data(), args...);
    }
/**
     * @brief Set custom trace log
     */
    inline void SetTraceLogCallback(TraceLogCallback callback) {
        ::SetTraceLogCallback(callback);
    }
/**
     * @brief Internal memory allocator
     */
    inline void * MemAlloc(unsigned int size) {
        return ::MemAlloc(size);
    }
/**
     * @brief Internal memory reallocator
     */
    inline void * MemRealloc(void * ptr, unsigned int size) {
        return ::MemRealloc(ptr, size);
    }
/**
     * @brief Internal memory free
     */
    inline void MemFree(void * ptr) {
        ::MemFree(ptr);
    }
/**
     * @brief Load file data as byte array (read)
     */
    inline unsigned char * LoadFileData(std::string_view fileName, int * dataSize) {
        return ::LoadFileData(fileName.data(), dataSize);
    }
/**
     * @brief Unload file data allocated by LoadFileData()
     */
    inline void UnloadFileData(unsigned char * data) {
        ::UnloadFileData(data);
    }
/**
     * @brief Save data to file from byte array (write), returns true on success
     */
    [[nodiscard]] inline bool SaveFileData(std::string_view fileName, void * data, int dataSize) {
        return ::SaveFileData(fileName.data(), data, dataSize);
    }
/**
     * @brief Export data to code (.h), returns true on success
     */
    [[nodiscard]] inline bool ExportDataAsCode(const unsigned char * data, int dataSize, std::string_view fileName) {
        return ::ExportDataAsCode(data, dataSize, fileName.data());
    }
/**
     * @brief Load text data from file (read), returns a '\0' terminated string
     */
    inline char * LoadFileText(std::string_view fileName) {
        return ::LoadFileText(fileName.data());
    }
/**
     * @brief Unload file text data allocated by LoadFileText()
     */
    inline void UnloadFileText(char * text) {
        ::UnloadFileText(text);
    }
/**
     * @brief Save text data to file (write), string must be '\0' terminated, returns true on success
     */
    [[nodiscard]] inline bool SaveFileText(std::string_view fileName, std::string_view text) {
        return ::SaveFileText(fileName.data(), text.data());
    }
/**
     * @brief Set custom file binary data loader
     */
    inline void SetLoadFileDataCallback(LoadFileDataCallback callback) {
        ::SetLoadFileDataCallback(callback);
    }
/**
     * @brief Set custom file binary data saver
     */
    inline void SetSaveFileDataCallback(SaveFileDataCallback callback) {
        ::SetSaveFileDataCallback(callback);
    }
/**
     * @brief Set custom file text data loader
     */
    inline void SetLoadFileTextCallback(LoadFileTextCallback callback) {
        ::SetLoadFileTextCallback(callback);
    }
/**
     * @brief Set custom file text data saver
     */
    inline void SetSaveFileTextCallback(SaveFileTextCallback callback) {
        ::SetSaveFileTextCallback(callback);
    }
/**
     * @brief Rename file (if exists)
     */
    inline int FileRename(std::string_view fileName, std::string_view fileRename) {
        return ::FileRename(fileName.data(), fileRename.data());
    }
/**
     * @brief Remove file (if exists)
     */
    inline int FileRemove(std::string_view fileName) {
        return ::FileRemove(fileName.data());
    }
/**
     * @brief Copy file from one path to another, dstPath created if it doesn't exist
     */
    inline int FileCopy(std::string_view srcPath, std::string_view dstPath) {
        return ::FileCopy(srcPath.data(), dstPath.data());
    }
/**
     * @brief Move file from one directory to another, dstPath created if it doesn't exist
     */
    inline int FileMove(std::string_view srcPath, std::string_view dstPath) {
        return ::FileMove(srcPath.data(), dstPath.data());
    }
/**
     * @brief Replace text in an existing file
     */
    inline int FileTextReplace(std::string_view fileName, std::string_view search, std::string_view replacement) {
        return ::FileTextReplace(fileName.data(), search.data(), replacement.data());
    }
/**
     * @brief Find text in existing file
     */
    inline int FileTextFindIndex(std::string_view fileName, std::string_view search) {
        return ::FileTextFindIndex(fileName.data(), search.data());
    }
/**
     * @brief Check if file exists
     */
    [[nodiscard]] inline bool FileExists(std::string_view fileName) {
        return ::FileExists(fileName.data());
    }
/**
     * @brief Check if a directory path exists
     */
    [[nodiscard]] inline bool DirectoryExists(std::string_view dirPath) {
        return ::DirectoryExists(dirPath.data());
    }
/**
     * @brief Check file extension (recommended include point: .png, .wav)
     */
    [[nodiscard]] inline bool IsFileExtension(std::string_view fileName, std::string_view ext) {
        return ::IsFileExtension(fileName.data(), ext.data());
    }
/**
     * @brief Get file length in bytes (NOTE: GetFileSize() conflicts with windows.h)
     */
    inline int GetFileLength(std::string_view fileName) {
        return ::GetFileLength(fileName.data());
    }
/**
     * @brief Get file modification time (last write time)
     */
    inline long GetFileModTime(std::string_view fileName) {
        return ::GetFileModTime(fileName.data());
    }
/**
     * @brief Get pointer to extension for a filename string (includes dot: '.png')
     */
    inline const char * GetFileExtension(std::string_view fileName) {
        return ::GetFileExtension(fileName.data());
    }
/**
     * @brief Get pointer to filename for a path string
     */
    inline const char * GetFileName(std::string_view filePath) {
        return ::GetFileName(filePath.data());
    }
/**
     * @brief Get filename string without extension (uses static string)
     */
    inline const char * GetFileNameWithoutExt(std::string_view filePath) {
        return ::GetFileNameWithoutExt(filePath.data());
    }
/**
     * @brief Get full path for a given fileName with path (uses static string)
     */
    inline const char * GetDirectoryPath(std::string_view filePath) {
        return ::GetDirectoryPath(filePath.data());
    }
/**
     * @brief Get previous directory path for a given path (uses static string)
     */
    inline const char * GetPrevDirectoryPath(std::string_view dirPath) {
        return ::GetPrevDirectoryPath(dirPath.data());
    }
/**
     * @brief Get current working directory (uses static string)
     */
    inline const char * GetWorkingDirectory() {
        return ::GetWorkingDirectory();
    }
/**
     * @brief Get the directory of the running application (uses static string)
     */
    inline const char * GetApplicationDirectory() {
        return ::GetApplicationDirectory();
    }
/**
     * @brief Create directories (including full path requested), returns 0 on success
     */
    inline int MakeDirectory(std::string_view dirPath) {
        return ::MakeDirectory(dirPath.data());
    }
/**
     * @brief Change working directory, return true on success
     */
    [[nodiscard]] inline bool ChangeDirectory(std::string_view dirPath) {
        return ::ChangeDirectory(dirPath.data());
    }
/**
     * @brief Check if a given path is a file or a directory
     */
    [[nodiscard]] inline bool IsPathFile(std::string_view path) {
        return ::IsPathFile(path.data());
    }
/**
     * @brief Check if fileName is valid for the platform/OS
     */
    [[nodiscard]] inline bool IsFileNameValid(std::string_view fileName) {
        return ::IsFileNameValid(fileName.data());
    }
/**
     * @brief Load directory filepaths, files and directories, no subdirs scan
     */
    inline FilePathList LoadDirectoryFiles(std::string_view dirPath) {
        return ::LoadDirectoryFiles(dirPath.data());
    }
/**
     * @brief Load directory filepaths with extension filtering and subdir scan; some filters available
     */
    inline FilePathList LoadDirectoryFilesEx(std::string_view basePath, std::string_view filter, bool scanSubdirs) {
        return ::LoadDirectoryFilesEx(basePath.data(), filter.data(), scanSubdirs);
    }
/**
     * @brief Unload filepaths
     */
    inline void UnloadDirectoryFiles(FilePathList files) {
        ::UnloadDirectoryFiles(files);
    }
/**
     * @brief Check if a file has been dropped into window
     */
    [[nodiscard]] inline bool IsFileDropped() {
        return ::IsFileDropped();
    }
/**
     * @brief Load dropped filepaths
     */
    inline FilePathList LoadDroppedFiles() {
        return ::LoadDroppedFiles();
    }
/**
     * @brief Unload dropped filepaths
     */
    inline void UnloadDroppedFiles(FilePathList files) {
        ::UnloadDroppedFiles(files);
    }
/**
     * @brief Get the file count in a directory
     */
    inline unsigned int GetDirectoryFileCount(std::string_view dirPath) {
        return ::GetDirectoryFileCount(dirPath.data());
    }
/**
     * @brief Get the file count in a directory with extension filtering and recursive directory scan. Use 'DIR' in the filter string to include directories in the result
     */
    inline unsigned int GetDirectoryFileCountEx(std::string_view basePath, std::string_view filter, bool scanSubdirs) {
        return ::GetDirectoryFileCountEx(basePath.data(), filter.data(), scanSubdirs);
    }
/**
     * @brief Compress data (DEFLATE algorithm), memory must be MemFree()
     */
    inline unsigned char * CompressData(const unsigned char * data, int dataSize, int * compDataSize) {
        return ::CompressData(data, dataSize, compDataSize);
    }
/**
     * @brief Decompress data (DEFLATE algorithm), memory must be MemFree()
     */
    inline unsigned char * DecompressData(const unsigned char * compData, int compDataSize, int * dataSize) {
        return ::DecompressData(compData, compDataSize, dataSize);
    }
/**
     * @brief Encode data to Base64 string (includes NULL terminator), memory must be MemFree()
     */
    inline char * EncodeDataBase64(const unsigned char * data, int dataSize, int * outputSize) {
        return ::EncodeDataBase64(data, dataSize, outputSize);
    }
/**
     * @brief Decode Base64 string (expected NULL terminated), memory must be MemFree()
     */
    inline unsigned char * DecodeDataBase64(std::string_view text, int * outputSize) {
        return ::DecodeDataBase64(text.data(), outputSize);
    }
/**
     * @brief Compute CRC32 hash code
     */
    inline unsigned int ComputeCRC32(unsigned char * data, int dataSize) {
        return ::ComputeCRC32(data, dataSize);
    }
/**
     * @brief Compute MD5 hash code, returns static int[4] (16 bytes)
     */
    inline unsigned int * ComputeMD5(unsigned char * data, int dataSize) {
        return ::ComputeMD5(data, dataSize);
    }
/**
     * @brief Compute SHA1 hash code, returns static int[5] (20 bytes)
     */
    inline unsigned int * ComputeSHA1(unsigned char * data, int dataSize) {
        return ::ComputeSHA1(data, dataSize);
    }
/**
     * @brief Compute SHA256 hash code, returns static int[8] (32 bytes)
     */
    inline unsigned int * ComputeSHA256(unsigned char * data, int dataSize) {
        return ::ComputeSHA256(data, dataSize);
    }
/**
     * @brief Load automation events list from file, NULL for empty list, capacity = MAX_AUTOMATION_EVENTS
     */
    inline AutomationEventList LoadAutomationEventList(std::string_view fileName) {
        return ::LoadAutomationEventList(fileName.data());
    }
/**
     * @brief Unload automation events list from file
     */
    inline void UnloadAutomationEventList(AutomationEventList list) {
        ::UnloadAutomationEventList(list);
    }
/**
     * @brief Export automation events list as text file
     */
    [[nodiscard]] inline bool ExportAutomationEventList(AutomationEventList list, std::string_view fileName) {
        return ::ExportAutomationEventList(list, fileName.data());
    }
/**
     * @brief Set automation event list to record to
     */
    inline void SetAutomationEventList(AutomationEventList * list) {
        ::SetAutomationEventList(list);
    }
/**
     * @brief Set automation event internal base frame to start recording
     */
    inline void SetAutomationEventBaseFrame(int frame) {
        ::SetAutomationEventBaseFrame(frame);
    }
/**
     * @brief Start recording automation events (AutomationEventList must be set)
     */
    inline void StartAutomationEventRecording() {
        ::StartAutomationEventRecording();
    }
/**
     * @brief Stop recording automation events
     */
    inline void StopAutomationEventRecording() {
        ::StopAutomationEventRecording();
    }
/**
     * @brief Play a recorded automation event
     */
    inline void PlayAutomationEvent(AutomationEvent event) {
        ::PlayAutomationEvent(event);
    }
/**
     * @brief Check if a key has been pressed once
     */
    [[nodiscard]] inline bool IsKeyPressed(int key) {
        return ::IsKeyPressed(key);
    }
/**
     * @brief Check if a key has been pressed again
     */
    [[nodiscard]] inline bool IsKeyPressedRepeat(int key) {
        return ::IsKeyPressedRepeat(key);
    }
/**
     * @brief Check if a key is being pressed
     */
    [[nodiscard]] inline bool IsKeyDown(int key) {
        return ::IsKeyDown(key);
    }
/**
     * @brief Check if a key has been released once
     */
    [[nodiscard]] inline bool IsKeyReleased(int key) {
        return ::IsKeyReleased(key);
    }
/**
     * @brief Check if a key is NOT being pressed
     */
    [[nodiscard]] inline bool IsKeyUp(int key) {
        return ::IsKeyUp(key);
    }
/**
     * @brief Get key pressed (keycode), call it multiple times for keys queued, returns 0 when the queue is empty
     */
    inline int GetKeyPressed() {
        return ::GetKeyPressed();
    }
/**
     * @brief Get char pressed (unicode), call it multiple times for chars queued, returns 0 when the queue is empty
     */
    inline int GetCharPressed() {
        return ::GetCharPressed();
    }
/**
     * @brief Get name of a QWERTY key on the current keyboard layout (eg returns string 'q' for KEY_A on an AZERTY keyboard)
     */
    inline const char * GetKeyName(int key) {
        return ::GetKeyName(key);
    }
/**
     * @brief Set a custom key to exit program (default is ESC)
     */
    inline void SetExitKey(int key) {
        ::SetExitKey(key);
    }
/**
     * @brief Check if a gamepad is available
     */
    [[nodiscard]] inline bool IsGamepadAvailable(int gamepad) {
        return ::IsGamepadAvailable(gamepad);
    }
/**
     * @brief Get gamepad internal name id
     */
    inline const char * GetGamepadName(int gamepad) {
        return ::GetGamepadName(gamepad);
    }
/**
     * @brief Check if a gamepad button has been pressed once
     */
    [[nodiscard]] inline bool IsGamepadButtonPressed(int gamepad, int button) {
        return ::IsGamepadButtonPressed(gamepad, button);
    }
/**
     * @brief Check if a gamepad button is being pressed
     */
    [[nodiscard]] inline bool IsGamepadButtonDown(int gamepad, int button) {
        return ::IsGamepadButtonDown(gamepad, button);
    }
/**
     * @brief Check if a gamepad button has been released once
     */
    [[nodiscard]] inline bool IsGamepadButtonReleased(int gamepad, int button) {
        return ::IsGamepadButtonReleased(gamepad, button);
    }
/**
     * @brief Check if a gamepad button is NOT being pressed
     */
    [[nodiscard]] inline bool IsGamepadButtonUp(int gamepad, int button) {
        return ::IsGamepadButtonUp(gamepad, button);
    }
/**
     * @brief Get the last gamepad button pressed
     */
    inline int GetGamepadButtonPressed() {
        return ::GetGamepadButtonPressed();
    }
/**
     * @brief Get axis count for a gamepad
     */
    inline int GetGamepadAxisCount(int gamepad) {
        return ::GetGamepadAxisCount(gamepad);
    }
/**
     * @brief Get movement value for a gamepad axis
     */
    inline float GetGamepadAxisMovement(int gamepad, int axis) {
        return ::GetGamepadAxisMovement(gamepad, axis);
    }
/**
     * @brief Set internal gamepad mappings (SDL_GameControllerDB)
     */
    inline int SetGamepadMappings(std::string_view mappings) {
        return ::SetGamepadMappings(mappings.data());
    }
/**
     * @brief Set gamepad vibration for both motors (duration in seconds)
     */
    inline void SetGamepadVibration(int gamepad, float leftMotor, float rightMotor, float duration) {
        ::SetGamepadVibration(gamepad, leftMotor, rightMotor, duration);
    }
/**
     * @brief Check if a mouse button has been pressed once
     */
    [[nodiscard]] inline bool IsMouseButtonPressed(int button) {
        return ::IsMouseButtonPressed(button);
    }
/**
     * @brief Check if a mouse button is being pressed
     */
    [[nodiscard]] inline bool IsMouseButtonDown(int button) {
        return ::IsMouseButtonDown(button);
    }
/**
     * @brief Check if a mouse button has been released once
     */
    [[nodiscard]] inline bool IsMouseButtonReleased(int button) {
        return ::IsMouseButtonReleased(button);
    }
/**
     * @brief Check if a mouse button is NOT being pressed
     */
    [[nodiscard]] inline bool IsMouseButtonUp(int button) {
        return ::IsMouseButtonUp(button);
    }
/**
     * @brief Get mouse position X
     */
    inline int GetMouseX() {
        return ::GetMouseX();
    }
/**
     * @brief Get mouse position Y
     */
    inline int GetMouseY() {
        return ::GetMouseY();
    }
/**
     * @brief Get mouse position XY
     */
    inline Vector2 GetMousePosition() {
        return ::GetMousePosition();
    }
/**
     * @brief Get mouse delta between frames
     */
    inline Vector2 GetMouseDelta() {
        return ::GetMouseDelta();
    }
/**
     * @brief Set mouse position XY
     */
    inline void SetMousePosition(int x, int y) {
        ::SetMousePosition(x, y);
    }
/**
     * @brief Set mouse offset
     */
    inline void SetMouseOffset(int offsetX, int offsetY) {
        ::SetMouseOffset(offsetX, offsetY);
    }
/**
     * @brief Set mouse scaling
     */
    inline void SetMouseScale(float scaleX, float scaleY) {
        ::SetMouseScale(scaleX, scaleY);
    }
/**
     * @brief Get mouse wheel movement for X or Y, whichever is larger
     */
    inline float GetMouseWheelMove() {
        return ::GetMouseWheelMove();
    }
/**
     * @brief Get mouse wheel movement for both X and Y
     */
    inline Vector2 GetMouseWheelMoveV() {
        return ::GetMouseWheelMoveV();
    }
/**
     * @brief Set mouse cursor
     */
    inline void SetMouseCursor(int cursor) {
        ::SetMouseCursor(cursor);
    }
/**
     * @brief Get touch position X for touch point 0 (relative to screen size)
     */
    inline int GetTouchX() {
        return ::GetTouchX();
    }
/**
     * @brief Get touch position Y for touch point 0 (relative to screen size)
     */
    inline int GetTouchY() {
        return ::GetTouchY();
    }
/**
     * @brief Get touch position XY for a touch point index (relative to screen size)
     */
    inline Vector2 GetTouchPosition(int index) {
        return ::GetTouchPosition(index);
    }
/**
     * @brief Get touch point identifier for given index
     */
    inline int GetTouchPointId(int index) {
        return ::GetTouchPointId(index);
    }
/**
     * @brief Get number of touch points
     */
    inline int GetTouchPointCount() {
        return ::GetTouchPointCount();
    }
/**
     * @brief Enable a set of gestures using flags
     */
    inline void SetGesturesEnabled(unsigned int flags) {
        ::SetGesturesEnabled(flags);
    }
/**
     * @brief Check if a gesture have been detected
     */
    [[nodiscard]] inline bool IsGestureDetected(unsigned int gesture) {
        return ::IsGestureDetected(gesture);
    }
/**
     * @brief Get latest detected gesture
     */
    inline int GetGestureDetected() {
        return ::GetGestureDetected();
    }
/**
     * @brief Get gesture hold time in seconds
     */
    inline float GetGestureHoldDuration() {
        return ::GetGestureHoldDuration();
    }
/**
     * @brief Get gesture drag vector
     */
    inline Vector2 GetGestureDragVector() {
        return ::GetGestureDragVector();
    }
/**
     * @brief Get gesture drag angle
     */
    inline float GetGestureDragAngle() {
        return ::GetGestureDragAngle();
    }
/**
     * @brief Get gesture pinch delta
     */
    inline Vector2 GetGesturePinchVector() {
        return ::GetGesturePinchVector();
    }
/**
     * @brief Get gesture pinch angle
     */
    inline float GetGesturePinchAngle() {
        return ::GetGesturePinchAngle();
    }
/**
     * @brief Update camera position for selected mode
     */
    inline void UpdateCamera(Camera * camera, int mode) {
        ::UpdateCamera(camera, mode);
    }
/**
     * @brief Update camera movement/rotation
     */
    inline void UpdateCameraPro(Camera * camera, Vector3 movement, Vector3 rotation, float zoom) {
        ::UpdateCameraPro(camera, movement, rotation, zoom);
    }
/**
     * @brief Set texture and rectangle to be used on shapes drawing
     */
    inline void SetShapesTexture(Texture2D texture, Rectangle source) {
        ::SetShapesTexture(texture, source);
    }
/**
     * @brief Get texture that is used for shapes drawing
     */
    inline Texture2D GetShapesTexture() {
        return ::GetShapesTexture();
    }
/**
     * @brief Get texture source rectangle that is used for shapes drawing
     */
    inline Rectangle GetShapesTextureRectangle() {
        return ::GetShapesTextureRectangle();
    }
/**
     * @brief Draw a pixel using geometry [Can be slow, use with care]
     */
    inline void DrawPixel(int posX, int posY, Color color) {
        ::DrawPixel(posX, posY, color);
    }
/**
     * @brief Draw a pixel using geometry (Vector version) [Can be slow, use with care]
     */
    inline void DrawPixelV(Vector2 position, Color color) {
        ::DrawPixelV(position, color);
    }
/**
     * @brief Draw a line
     */
    inline void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color) {
        ::DrawLine(startPosX, startPosY, endPosX, endPosY, color);
    }
/**
     * @brief Draw a line (using gl lines)
     */
    inline void DrawLineV(Vector2 startPos, Vector2 endPos, Color color) {
        ::DrawLineV(startPos, endPos, color);
    }
/**
     * @brief Draw a line (using triangles/quads)
     */
    inline void DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color) {
        ::DrawLineEx(startPos, endPos, thick, color);
    }
/**
     * @brief Draw lines sequence (using gl lines)
     */
    inline void DrawLineStrip(std::span<const Vector2> points, Color color) {
        ::DrawLineStrip(points.data(), static_cast<int>(points.size()), color);
    }
/**
     * @brief Draw line segment cubic-bezier in-out interpolation
     */
    inline void DrawLineBezier(Vector2 startPos, Vector2 endPos, float thick, Color color) {
        ::DrawLineBezier(startPos, endPos, thick, color);
    }
/**
     * @brief Draw a dashed line
     */
    inline void DrawLineDashed(Vector2 startPos, Vector2 endPos, int dashSize, int spaceSize, Color color) {
        ::DrawLineDashed(startPos, endPos, dashSize, spaceSize, color);
    }
/**
     * @brief Draw a color-filled circle
     */
    inline void DrawCircle(int centerX, int centerY, float radius, Color color) {
        ::DrawCircle(centerX, centerY, radius, color);
    }
/**
     * @brief Draw a color-filled circle (Vector version)
     */
    inline void DrawCircleV(Vector2 center, float radius, Color color) {
        ::DrawCircleV(center, radius, color);
    }
/**
     * @brief Draw a gradient-filled circle
     */
    inline void DrawCircleGradient(Vector2 center, float radius, Color inner, Color outer) {
        ::DrawCircleGradient(center, radius, inner, outer);
    }
/**
     * @brief Draw a piece of a circle
     */
    inline void DrawCircleSector(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color) {
        ::DrawCircleSector(center, radius, startAngle, endAngle, segments, color);
    }
/**
     * @brief Draw circle sector outline
     */
    inline void DrawCircleSectorLines(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color) {
        ::DrawCircleSectorLines(center, radius, startAngle, endAngle, segments, color);
    }
/**
     * @brief Draw circle outline
     */
    inline void DrawCircleLines(int centerX, int centerY, float radius, Color color) {
        ::DrawCircleLines(centerX, centerY, radius, color);
    }
/**
     * @brief Draw circle outline (Vector version)
     */
    inline void DrawCircleLinesV(Vector2 center, float radius, Color color) {
        ::DrawCircleLinesV(center, radius, color);
    }
/**
     * @brief Draw ellipse
     */
    inline void DrawEllipse(int centerX, int centerY, float radiusH, float radiusV, Color color) {
        ::DrawEllipse(centerX, centerY, radiusH, radiusV, color);
    }
/**
     * @brief Draw ellipse (Vector version)
     */
    inline void DrawEllipseV(Vector2 center, float radiusH, float radiusV, Color color) {
        ::DrawEllipseV(center, radiusH, radiusV, color);
    }
/**
     * @brief Draw ellipse outline
     */
    inline void DrawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, Color color) {
        ::DrawEllipseLines(centerX, centerY, radiusH, radiusV, color);
    }
/**
     * @brief Draw ellipse outline (Vector version)
     */
    inline void DrawEllipseLinesV(Vector2 center, float radiusH, float radiusV, Color color) {
        ::DrawEllipseLinesV(center, radiusH, radiusV, color);
    }
/**
     * @brief Draw ring
     */
    inline void DrawRing(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color) {
        ::DrawRing(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
    }
/**
     * @brief Draw ring outline
     */
    inline void DrawRingLines(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color) {
        ::DrawRingLines(center, innerRadius, outerRadius, startAngle, endAngle, segments, color);
    }
/**
     * @brief Draw a color-filled rectangle
     */
    inline void DrawRectangle(int posX, int posY, int width, int height, Color color) {
        ::DrawRectangle(posX, posY, width, height, color);
    }
/**
     * @brief Draw a color-filled rectangle (Vector version)
     */
    inline void DrawRectangleV(Vector2 position, Vector2 size, Color color) {
        ::DrawRectangleV(position, size, color);
    }
/**
     * @brief Draw a color-filled rectangle
     */
    inline void DrawRectangleRec(Rectangle rec, Color color) {
        ::DrawRectangleRec(rec, color);
    }
/**
     * @brief Draw a color-filled rectangle with pro parameters
     */
    inline void DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color) {
        ::DrawRectanglePro(rec, origin, rotation, color);
    }
/**
     * @brief Draw a vertical-gradient-filled rectangle
     */
    inline void DrawRectangleGradientV(int posX, int posY, int width, int height, Color top, Color bottom) {
        ::DrawRectangleGradientV(posX, posY, width, height, top, bottom);
    }
/**
     * @brief Draw a horizontal-gradient-filled rectangle
     */
    inline void DrawRectangleGradientH(int posX, int posY, int width, int height, Color left, Color right) {
        ::DrawRectangleGradientH(posX, posY, width, height, left, right);
    }
/**
     * @brief Draw a gradient-filled rectangle with custom vertex colors
     */
    inline void DrawRectangleGradientEx(Rectangle rec, Color topLeft, Color bottomLeft, Color bottomRight, Color topRight) {
        ::DrawRectangleGradientEx(rec, topLeft, bottomLeft, bottomRight, topRight);
    }
/**
     * @brief Draw rectangle outline
     */
    inline void DrawRectangleLines(int posX, int posY, int width, int height, Color color) {
        ::DrawRectangleLines(posX, posY, width, height, color);
    }
/**
     * @brief Draw rectangle outline with extended parameters
     */
    inline void DrawRectangleLinesEx(Rectangle rec, float lineThick, Color color) {
        ::DrawRectangleLinesEx(rec, lineThick, color);
    }
/**
     * @brief Draw rectangle with rounded edges
     */
    inline void DrawRectangleRounded(Rectangle rec, float roundness, int segments, Color color) {
        ::DrawRectangleRounded(rec, roundness, segments, color);
    }
/**
     * @brief Draw rectangle lines with rounded edges
     */
    inline void DrawRectangleRoundedLines(Rectangle rec, float roundness, int segments, Color color) {
        ::DrawRectangleRoundedLines(rec, roundness, segments, color);
    }
/**
     * @brief Draw rectangle with rounded edges outline
     */
    inline void DrawRectangleRoundedLinesEx(Rectangle rec, float roundness, int segments, float lineThick, Color color) {
        ::DrawRectangleRoundedLinesEx(rec, roundness, segments, lineThick, color);
    }
/**
     * @brief Draw a color-filled triangle (vertex in counter-clockwise order!)
     */
    inline void DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color) {
        ::DrawTriangle(v1, v2, v3, color);
    }
/**
     * @brief Draw triangle outline (vertex in counter-clockwise order!)
     */
    inline void DrawTriangleLines(Vector2 v1, Vector2 v2, Vector2 v3, Color color) {
        ::DrawTriangleLines(v1, v2, v3, color);
    }
/**
     * @brief Draw a triangle fan defined by points (first vertex is the center)
     */
    inline void DrawTriangleFan(std::span<const Vector2> points, Color color) {
        ::DrawTriangleFan(points.data(), static_cast<int>(points.size()), color);
    }
/**
     * @brief Draw a triangle strip defined by points
     */
    inline void DrawTriangleStrip(std::span<const Vector2> points, Color color) {
        ::DrawTriangleStrip(points.data(), static_cast<int>(points.size()), color);
    }
/**
     * @brief Draw a regular polygon (Vector version)
     */
    inline void DrawPoly(Vector2 center, int sides, float radius, float rotation, Color color) {
        ::DrawPoly(center, sides, radius, rotation, color);
    }
/**
     * @brief Draw a polygon outline of n sides
     */
    inline void DrawPolyLines(Vector2 center, int sides, float radius, float rotation, Color color) {
        ::DrawPolyLines(center, sides, radius, rotation, color);
    }
/**
     * @brief Draw a polygon outline of n sides with extended parameters
     */
    inline void DrawPolyLinesEx(Vector2 center, int sides, float radius, float rotation, float lineThick, Color color) {
        ::DrawPolyLinesEx(center, sides, radius, rotation, lineThick, color);
    }
/**
     * @brief Draw spline: Linear, minimum 2 points
     */
    inline void DrawSplineLinear(std::span<const Vector2> points, float thick, Color color) {
        ::DrawSplineLinear(points.data(), static_cast<int>(points.size()), thick, color);
    }
/**
     * @brief Draw spline: B-Spline, minimum 4 points
     */
    inline void DrawSplineBasis(std::span<const Vector2> points, float thick, Color color) {
        ::DrawSplineBasis(points.data(), static_cast<int>(points.size()), thick, color);
    }
/**
     * @brief Draw spline: Catmull-Rom, minimum 4 points
     */
    inline void DrawSplineCatmullRom(std::span<const Vector2> points, float thick, Color color) {
        ::DrawSplineCatmullRom(points.data(), static_cast<int>(points.size()), thick, color);
    }
/**
     * @brief Draw spline: Quadratic Bezier, minimum 3 points (1 control point): [p1, c2, p3, c4...]
     */
    inline void DrawSplineBezierQuadratic(std::span<const Vector2> points, float thick, Color color) {
        ::DrawSplineBezierQuadratic(points.data(), static_cast<int>(points.size()), thick, color);
    }
/**
     * @brief Draw spline: Cubic Bezier, minimum 4 points (2 control points): [p1, c2, c3, p4, c5, c6...]
     */
    inline void DrawSplineBezierCubic(std::span<const Vector2> points, float thick, Color color) {
        ::DrawSplineBezierCubic(points.data(), static_cast<int>(points.size()), thick, color);
    }
/**
     * @brief Draw spline segment: Linear, 2 points
     */
    inline void DrawSplineSegmentLinear(Vector2 p1, Vector2 p2, float thick, Color color) {
        ::DrawSplineSegmentLinear(p1, p2, thick, color);
    }
/**
     * @brief Draw spline segment: B-Spline, 4 points
     */
    inline void DrawSplineSegmentBasis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color) {
        ::DrawSplineSegmentBasis(p1, p2, p3, p4, thick, color);
    }
/**
     * @brief Draw spline segment: Catmull-Rom, 4 points
     */
    inline void DrawSplineSegmentCatmullRom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color) {
        ::DrawSplineSegmentCatmullRom(p1, p2, p3, p4, thick, color);
    }
/**
     * @brief Draw spline segment: Quadratic Bezier, 2 points, 1 control point
     */
    inline void DrawSplineSegmentBezierQuadratic(Vector2 p1, Vector2 c2, Vector2 p3, float thick, Color color) {
        ::DrawSplineSegmentBezierQuadratic(p1, c2, p3, thick, color);
    }
/**
     * @brief Draw spline segment: Cubic Bezier, 2 points, 2 control points
     */
    inline void DrawSplineSegmentBezierCubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float thick, Color color) {
        ::DrawSplineSegmentBezierCubic(p1, c2, c3, p4, thick, color);
    }
/**
     * @brief Get (evaluate) spline point: Linear
     */
    inline Vector2 GetSplinePointLinear(Vector2 startPos, Vector2 endPos, float t) {
        return ::GetSplinePointLinear(startPos, endPos, t);
    }
/**
     * @brief Get (evaluate) spline point: B-Spline
     */
    inline Vector2 GetSplinePointBasis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t) {
        return ::GetSplinePointBasis(p1, p2, p3, p4, t);
    }
/**
     * @brief Get (evaluate) spline point: Catmull-Rom
     */
    inline Vector2 GetSplinePointCatmullRom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t) {
        return ::GetSplinePointCatmullRom(p1, p2, p3, p4, t);
    }
/**
     * @brief Get (evaluate) spline point: Quadratic Bezier
     */
    inline Vector2 GetSplinePointBezierQuad(Vector2 p1, Vector2 c2, Vector2 p3, float t) {
        return ::GetSplinePointBezierQuad(p1, c2, p3, t);
    }
/**
     * @brief Get (evaluate) spline point: Cubic Bezier
     */
    inline Vector2 GetSplinePointBezierCubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float t) {
        return ::GetSplinePointBezierCubic(p1, c2, c3, p4, t);
    }
/**
     * @brief Check collision between two rectangles
     */
    [[nodiscard]] inline bool CheckCollisionRecs(Rectangle rec1, Rectangle rec2) {
        return ::CheckCollisionRecs(rec1, rec2);
    }
/**
     * @brief Check collision between two circles
     */
    [[nodiscard]] inline bool CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2) {
        return ::CheckCollisionCircles(center1, radius1, center2, radius2);
    }
/**
     * @brief Check collision between circle and rectangle
     */
    [[nodiscard]] inline bool CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec) {
        return ::CheckCollisionCircleRec(center, radius, rec);
    }
/**
     * @brief Check if circle collides with a line created betweeen two points [p1] and [p2]
     */
    [[nodiscard]] inline bool CheckCollisionCircleLine(Vector2 center, float radius, Vector2 p1, Vector2 p2) {
        return ::CheckCollisionCircleLine(center, radius, p1, p2);
    }
/**
     * @brief Check if point is inside rectangle
     */
    [[nodiscard]] inline bool CheckCollisionPointRec(Vector2 point, Rectangle rec) {
        return ::CheckCollisionPointRec(point, rec);
    }
/**
     * @brief Check if point is inside circle
     */
    [[nodiscard]] inline bool CheckCollisionPointCircle(Vector2 point, Vector2 center, float radius) {
        return ::CheckCollisionPointCircle(point, center, radius);
    }
/**
     * @brief Check if point is inside a triangle
     */
    [[nodiscard]] inline bool CheckCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3) {
        return ::CheckCollisionPointTriangle(point, p1, p2, p3);
    }
/**
     * @brief Check if point belongs to line created between two points [p1] and [p2] with defined margin in pixels [threshold]
     */
    [[nodiscard]] inline bool CheckCollisionPointLine(Vector2 point, Vector2 p1, Vector2 p2, int threshold) {
        return ::CheckCollisionPointLine(point, p1, p2, threshold);
    }
/**
     * @brief Check if point is within a polygon described by array of vertices
     */
    [[nodiscard]] inline bool CheckCollisionPointPoly(Vector2 point, std::span<const Vector2> points) {
        return ::CheckCollisionPointPoly(point, points.data(), static_cast<int>(points.size()));
    }
/**
     * @brief Check the collision between two lines defined by two points each, returns collision point by reference
     */
    [[nodiscard]] inline bool CheckCollisionLines(Vector2 startPos1, Vector2 endPos1, Vector2 startPos2, Vector2 endPos2, Vector2 * collisionPoint) {
        return ::CheckCollisionLines(startPos1, endPos1, startPos2, endPos2, collisionPoint);
    }
/**
     * @brief Get collision rectangle for two rectangles collision
     */
    inline Rectangle GetCollisionRec(Rectangle rec1, Rectangle rec2) {
        return ::GetCollisionRec(rec1, rec2);
    }
/**
     * @brief Load image from file into CPU memory (RAM)
     */
    inline Image LoadImage(std::string_view fileName) {
        return ::LoadImage(fileName.data());
    }
/**
     * @brief Load image from RAW file data
     */
    inline Image LoadImageRaw(std::string_view fileName, int width, int height, int format, int headerSize) {
        return ::LoadImageRaw(fileName.data(), width, height, format, headerSize);
    }
/**
     * @brief Load image sequence from file (frames appended to image.data)
     */
    inline Image LoadImageAnim(std::string_view fileName, int * frames) {
        return ::LoadImageAnim(fileName.data(), frames);
    }
/**
     * @brief Load image sequence from memory buffer
     */
    inline Image LoadImageAnimFromMemory(std::string_view fileType, const unsigned char * fileData, int dataSize, int * frames) {
        return ::LoadImageAnimFromMemory(fileType.data(), fileData, dataSize, frames);
    }
/**
     * @brief Load image from memory buffer, fileType refers to extension: i.e. '.png'
     */
    inline Image LoadImageFromMemory(std::string_view fileType, const unsigned char * fileData, int dataSize) {
        return ::LoadImageFromMemory(fileType.data(), fileData, dataSize);
    }
/**
     * @brief Load image from GPU texture data
     */
    inline Image LoadImageFromTexture(Texture2D texture) {
        return ::LoadImageFromTexture(texture);
    }
/**
     * @brief Load image from screen buffer and (screenshot)
     */
    inline Image LoadImageFromScreen() {
        return ::LoadImageFromScreen();
    }
/**
     * @brief Check if an image is valid (data and parameters)
     */
    [[nodiscard]] inline bool IsImageValid(Image image) {
        return ::IsImageValid(image);
    }
/**
     * @brief Unload image from CPU memory (RAM)
     */
    inline void UnloadImage(Image image) {
        ::UnloadImage(image);
    }
/**
     * @brief Export image data to file, returns true on success
     */
    [[nodiscard]] inline bool ExportImage(Image image, std::string_view fileName) {
        return ::ExportImage(image, fileName.data());
    }
/**
     * @brief Export image to memory buffer, memory must be MemFree()
     */
    inline unsigned char * ExportImageToMemory(Image image, std::string_view fileType, int * fileSize) {
        return ::ExportImageToMemory(image, fileType.data(), fileSize);
    }
/**
     * @brief Export image as code file defining an array of bytes, returns true on success
     */
    [[nodiscard]] inline bool ExportImageAsCode(Image image, std::string_view fileName) {
        return ::ExportImageAsCode(image, fileName.data());
    }
/**
     * @brief Generate image: plain color
     */
    inline Image GenImageColor(int width, int height, Color color) {
        return ::GenImageColor(width, height, color);
    }
/**
     * @brief Generate image: linear gradient, direction in degrees [0..360], 0=Vertical gradient
     */
    inline Image GenImageGradientLinear(int width, int height, int direction, Color start, Color end) {
        return ::GenImageGradientLinear(width, height, direction, start, end);
    }
/**
     * @brief Generate image: radial gradient
     */
    inline Image GenImageGradientRadial(int width, int height, float density, Color inner, Color outer) {
        return ::GenImageGradientRadial(width, height, density, inner, outer);
    }
/**
     * @brief Generate image: square gradient
     */
    inline Image GenImageGradientSquare(int width, int height, float density, Color inner, Color outer) {
        return ::GenImageGradientSquare(width, height, density, inner, outer);
    }
/**
     * @brief Generate image: checked
     */
    inline Image GenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2) {
        return ::GenImageChecked(width, height, checksX, checksY, col1, col2);
    }
/**
     * @brief Generate image: white noise
     */
    inline Image GenImageWhiteNoise(int width, int height, float factor) {
        return ::GenImageWhiteNoise(width, height, factor);
    }
/**
     * @brief Generate image: perlin noise
     */
    inline Image GenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale) {
        return ::GenImagePerlinNoise(width, height, offsetX, offsetY, scale);
    }
/**
     * @brief Generate image: cellular algorithm, bigger tileSize means bigger cells
     */
    inline Image GenImageCellular(int width, int height, int tileSize) {
        return ::GenImageCellular(width, height, tileSize);
    }
/**
     * @brief Generate image: grayscale image from text data
     */
    inline Image GenImageText(int width, int height, std::string_view text) {
        return ::GenImageText(width, height, text.data());
    }
/**
     * @brief Create an image duplicate (useful for transformations)
     */
    inline Image ImageCopy(Image image) {
        return ::ImageCopy(image);
    }
/**
     * @brief Create an image from another image piece
     */
    inline Image ImageFromImage(Image image, Rectangle rec) {
        return ::ImageFromImage(image, rec);
    }
/**
     * @brief Create an image from a selected channel of another image (GRAYSCALE)
     */
    inline Image ImageFromChannel(Image image, int selectedChannel) {
        return ::ImageFromChannel(image, selectedChannel);
    }
/**
     * @brief Create an image from text (default font)
     */
    inline Image ImageText(std::string_view text, int fontSize, Color color) {
        return ::ImageText(text.data(), fontSize, color);
    }
/**
     * @brief Create an image from text (custom sprite font)
     */
    inline Image ImageTextEx(Font font, std::string_view text, float fontSize, float spacing, Color tint) {
        return ::ImageTextEx(font, text.data(), fontSize, spacing, tint);
    }
/**
     * @brief Convert image data to desired format
     */
    inline void ImageFormat(Image * image, int newFormat) {
        ::ImageFormat(image, newFormat);
    }
/**
     * @brief Convert image to POT (power-of-two)
     */
    inline void ImageToPOT(Image * image, Color fill) {
        ::ImageToPOT(image, fill);
    }
/**
     * @brief Crop an image to a defined rectangle
     */
    inline void ImageCrop(Image * image, Rectangle crop) {
        ::ImageCrop(image, crop);
    }
/**
     * @brief Crop image depending on alpha value
     */
    inline void ImageAlphaCrop(Image * image, float threshold) {
        ::ImageAlphaCrop(image, threshold);
    }
/**
     * @brief Clear alpha channel to desired color
     */
    inline void ImageAlphaClear(Image * image, Color color, float threshold) {
        ::ImageAlphaClear(image, color, threshold);
    }
/**
     * @brief Apply alpha mask to image
     */
    inline void ImageAlphaMask(Image * image, Image alphaMask) {
        ::ImageAlphaMask(image, alphaMask);
    }
/**
     * @brief Premultiply alpha channel
     */
    inline void ImageAlphaPremultiply(Image * image) {
        ::ImageAlphaPremultiply(image);
    }
/**
     * @brief Apply Gaussian blur using a box blur approximation
     */
    inline void ImageBlurGaussian(std::span<Image> image) {
        ::ImageBlurGaussian(image.data(), static_cast<int>(image.size()));
    }
/**
     * @brief Apply custom square convolution kernel to image
     */
    inline void ImageKernelConvolution(Image * image, std::span<const float> kernel) {
        ::ImageKernelConvolution(image, kernel.data(), static_cast<int>(kernel.size()));
    }
/**
     * @brief Resize image (Bicubic scaling algorithm)
     */
    inline void ImageResize(Image * image, int newWidth, int newHeight) {
        ::ImageResize(image, newWidth, newHeight);
    }
/**
     * @brief Resize image (Nearest-Neighbor scaling algorithm)
     */
    inline void ImageResizeNN(Image * image, int newWidth, int newHeight) {
        ::ImageResizeNN(image, newWidth, newHeight);
    }
/**
     * @brief Resize canvas and fill with color
     */
    inline void ImageResizeCanvas(Image * image, int newWidth, int newHeight, int offsetX, int offsetY, Color fill) {
        ::ImageResizeCanvas(image, newWidth, newHeight, offsetX, offsetY, fill);
    }
/**
     * @brief Compute all mipmap levels for a provided image
     */
    inline void ImageMipmaps(Image * image) {
        ::ImageMipmaps(image);
    }
/**
     * @brief Dither image data to 16bpp or lower (Floyd-Steinberg dithering)
     */
    inline void ImageDither(Image * image, int rBpp, int gBpp, int bBpp, int aBpp) {
        ::ImageDither(image, rBpp, gBpp, bBpp, aBpp);
    }
/**
     * @brief Flip image vertically
     */
    inline void ImageFlipVertical(Image * image) {
        ::ImageFlipVertical(image);
    }
/**
     * @brief Flip image horizontally
     */
    inline void ImageFlipHorizontal(Image * image) {
        ::ImageFlipHorizontal(image);
    }
/**
     * @brief Rotate image by input angle in degrees (-359 to 359)
     */
    inline void ImageRotate(Image * image, int degrees) {
        ::ImageRotate(image, degrees);
    }
/**
     * @brief Rotate image clockwise 90deg
     */
    inline void ImageRotateCW(Image * image) {
        ::ImageRotateCW(image);
    }
/**
     * @brief Rotate image counter-clockwise 90deg
     */
    inline void ImageRotateCCW(Image * image) {
        ::ImageRotateCCW(image);
    }
/**
     * @brief Modify image color: tint
     */
    inline void ImageColorTint(Image * image, Color color) {
        ::ImageColorTint(image, color);
    }
/**
     * @brief Modify image color: invert
     */
    inline void ImageColorInvert(Image * image) {
        ::ImageColorInvert(image);
    }
/**
     * @brief Modify image color: grayscale
     */
    inline void ImageColorGrayscale(Image * image) {
        ::ImageColorGrayscale(image);
    }
/**
     * @brief Modify image color: contrast (-100 to 100)
     */
    inline void ImageColorContrast(Image * image, float contrast) {
        ::ImageColorContrast(image, contrast);
    }
/**
     * @brief Modify image color: brightness (-255 to 255)
     */
    inline void ImageColorBrightness(Image * image, int brightness) {
        ::ImageColorBrightness(image, brightness);
    }
/**
     * @brief Modify image color: replace color
     */
    inline void ImageColorReplace(Image * image, Color color, Color replace) {
        ::ImageColorReplace(image, color, replace);
    }
/**
     * @brief Load color data from image as a Color array (RGBA - 32bit)
     */
    inline Color * LoadImageColors(Image image) {
        return ::LoadImageColors(image);
    }
/**
     * @brief Load colors palette from image as a Color array (RGBA - 32bit)
     */
    inline Color * LoadImagePalette(Image image, int maxPaletteSize, int * colorCount) {
        return ::LoadImagePalette(image, maxPaletteSize, colorCount);
    }
/**
     * @brief Unload color data loaded with LoadImageColors()
     */
    inline void UnloadImageColors(Color * colors) {
        ::UnloadImageColors(colors);
    }
/**
     * @brief Unload colors palette loaded with LoadImagePalette()
     */
    inline void UnloadImagePalette(Color * colors) {
        ::UnloadImagePalette(colors);
    }
/**
     * @brief Get image alpha border rectangle
     */
    inline Rectangle GetImageAlphaBorder(Image image, float threshold) {
        return ::GetImageAlphaBorder(image, threshold);
    }
/**
     * @brief Get image pixel color at (x, y) position
     */
    inline Color GetImageColor(Image image, int x, int y) {
        return ::GetImageColor(image, x, y);
    }
/**
     * @brief Clear image background with given color
     */
    inline void ImageClearBackground(Image * dst, Color color) {
        ::ImageClearBackground(dst, color);
    }
/**
     * @brief Draw pixel within an image
     */
    inline void ImageDrawPixel(Image * dst, int posX, int posY, Color color) {
        ::ImageDrawPixel(dst, posX, posY, color);
    }
/**
     * @brief Draw pixel within an image (Vector version)
     */
    inline void ImageDrawPixelV(Image * dst, Vector2 position, Color color) {
        ::ImageDrawPixelV(dst, position, color);
    }
/**
     * @brief Draw line within an image
     */
    inline void ImageDrawLine(Image * dst, int startPosX, int startPosY, int endPosX, int endPosY, Color color) {
        ::ImageDrawLine(dst, startPosX, startPosY, endPosX, endPosY, color);
    }
/**
     * @brief Draw line within an image (Vector version)
     */
    inline void ImageDrawLineV(Image * dst, Vector2 start, Vector2 end, Color color) {
        ::ImageDrawLineV(dst, start, end, color);
    }
/**
     * @brief Draw a line defining thickness within an image
     */
    inline void ImageDrawLineEx(Image * dst, Vector2 start, Vector2 end, int thick, Color color) {
        ::ImageDrawLineEx(dst, start, end, thick, color);
    }
/**
     * @brief Draw a filled circle within an image
     */
    inline void ImageDrawCircle(Image * dst, int centerX, int centerY, int radius, Color color) {
        ::ImageDrawCircle(dst, centerX, centerY, radius, color);
    }
/**
     * @brief Draw a filled circle within an image (Vector version)
     */
    inline void ImageDrawCircleV(Image * dst, Vector2 center, int radius, Color color) {
        ::ImageDrawCircleV(dst, center, radius, color);
    }
/**
     * @brief Draw circle outline within an image
     */
    inline void ImageDrawCircleLines(Image * dst, int centerX, int centerY, int radius, Color color) {
        ::ImageDrawCircleLines(dst, centerX, centerY, radius, color);
    }
/**
     * @brief Draw circle outline within an image (Vector version)
     */
    inline void ImageDrawCircleLinesV(Image * dst, Vector2 center, int radius, Color color) {
        ::ImageDrawCircleLinesV(dst, center, radius, color);
    }
/**
     * @brief Draw rectangle within an image
     */
    inline void ImageDrawRectangle(Image * dst, int posX, int posY, int width, int height, Color color) {
        ::ImageDrawRectangle(dst, posX, posY, width, height, color);
    }
/**
     * @brief Draw rectangle within an image (Vector version)
     */
    inline void ImageDrawRectangleV(Image * dst, Vector2 position, Vector2 size, Color color) {
        ::ImageDrawRectangleV(dst, position, size, color);
    }
/**
     * @brief Draw rectangle within an image
     */
    inline void ImageDrawRectangleRec(Image * dst, Rectangle rec, Color color) {
        ::ImageDrawRectangleRec(dst, rec, color);
    }
/**
     * @brief Draw rectangle lines within an image
     */
    inline void ImageDrawRectangleLines(Image * dst, Rectangle rec, int thick, Color color) {
        ::ImageDrawRectangleLines(dst, rec, thick, color);
    }
/**
     * @brief Draw triangle within an image
     */
    inline void ImageDrawTriangle(Image * dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color) {
        ::ImageDrawTriangle(dst, v1, v2, v3, color);
    }
/**
     * @brief Draw triangle with interpolated colors within an image
     */
    inline void ImageDrawTriangleEx(Image * dst, Vector2 v1, Vector2 v2, Vector2 v3, Color c1, Color c2, Color c3) {
        ::ImageDrawTriangleEx(dst, v1, v2, v3, c1, c2, c3);
    }
/**
     * @brief Draw triangle outline within an image
     */
    inline void ImageDrawTriangleLines(Image * dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color) {
        ::ImageDrawTriangleLines(dst, v1, v2, v3, color);
    }
/**
     * @brief Draw a triangle fan defined by points within an image (first vertex is the center)
     */
    inline void ImageDrawTriangleFan(Image * dst, std::span<const Vector2> points, Color color) {
        ::ImageDrawTriangleFan(dst, points.data(), static_cast<int>(points.size()), color);
    }
/**
     * @brief Draw a triangle strip defined by points within an image
     */
    inline void ImageDrawTriangleStrip(Image * dst, std::span<const Vector2> points, Color color) {
        ::ImageDrawTriangleStrip(dst, points.data(), static_cast<int>(points.size()), color);
    }
/**
     * @brief Draw a source image within a destination image (tint applied to source)
     */
    inline void ImageDraw(Image * dst, Image src, Rectangle srcRec, Rectangle dstRec, Color tint) {
        ::ImageDraw(dst, src, srcRec, dstRec, tint);
    }
/**
     * @brief Draw text (using default font) within an image (destination)
     */
    inline void ImageDrawText(Image * dst, std::string_view text, int posX, int posY, int fontSize, Color color) {
        ::ImageDrawText(dst, text.data(), posX, posY, fontSize, color);
    }
/**
     * @brief Draw text (custom sprite font) within an image (destination)
     */
    inline void ImageDrawTextEx(Image * dst, Font font, std::string_view text, Vector2 position, float fontSize, float spacing, Color tint) {
        ::ImageDrawTextEx(dst, font, text.data(), position, fontSize, spacing, tint);
    }
/**
     * @brief Load texture from file into GPU memory (VRAM)
     */
    inline Texture2D LoadTexture(std::string_view fileName) {
        return ::LoadTexture(fileName.data());
    }
/**
     * @brief Load texture from image data
     */
    inline Texture2D LoadTextureFromImage(Image image) {
        return ::LoadTextureFromImage(image);
    }
/**
     * @brief Load cubemap from image, multiple image cubemap layouts supported
     */
    inline TextureCubemap LoadTextureCubemap(Image image, int layout) {
        return ::LoadTextureCubemap(image, layout);
    }
/**
     * @brief Load texture for rendering (framebuffer)
     */
    inline RenderTexture2D LoadRenderTexture(int width, int height) {
        return ::LoadRenderTexture(width, height);
    }
/**
     * @brief Check if a texture is valid (loaded in GPU)
     */
    [[nodiscard]] inline bool IsTextureValid(Texture2D texture) {
        return ::IsTextureValid(texture);
    }
/**
     * @brief Unload texture from GPU memory (VRAM)
     */
    inline void UnloadTexture(Texture2D texture) {
        ::UnloadTexture(texture);
    }
/**
     * @brief Check if a render texture is valid (loaded in GPU)
     */
    [[nodiscard]] inline bool IsRenderTextureValid(RenderTexture2D target) {
        return ::IsRenderTextureValid(target);
    }
/**
     * @brief Unload render texture from GPU memory (VRAM)
     */
    inline void UnloadRenderTexture(RenderTexture2D target) {
        ::UnloadRenderTexture(target);
    }
/**
     * @brief Update GPU texture with new data (pixels should be able to fill texture)
     */
    inline void UpdateTexture(Texture2D texture, const void * pixels) {
        ::UpdateTexture(texture, pixels);
    }
/**
     * @brief Update GPU texture rectangle with new data (pixels and rec should fit in texture)
     */
    inline void UpdateTextureRec(Texture2D texture, Rectangle rec, const void * pixels) {
        ::UpdateTextureRec(texture, rec, pixels);
    }
/**
     * @brief Generate GPU mipmaps for a texture
     */
    inline void GenTextureMipmaps(Texture2D * texture) {
        ::GenTextureMipmaps(texture);
    }
/**
     * @brief Set texture scaling filter mode
     */
    inline void SetTextureFilter(Texture2D texture, int filter) {
        ::SetTextureFilter(texture, filter);
    }
/**
     * @brief Set texture wrapping mode
     */
    inline void SetTextureWrap(Texture2D texture, int wrap) {
        ::SetTextureWrap(texture, wrap);
    }
/**
     * @brief Draw a Texture2D
     */
    inline void DrawTexture(Texture2D texture, int posX, int posY, Color tint) {
        ::DrawTexture(texture, posX, posY, tint);
    }
/**
     * @brief Draw a Texture2D with position defined as Vector2
     */
    inline void DrawTextureV(Texture2D texture, Vector2 position, Color tint) {
        ::DrawTextureV(texture, position, tint);
    }
/**
     * @brief Draw a Texture2D with extended parameters
     */
    inline void DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint) {
        ::DrawTextureEx(texture, position, rotation, scale, tint);
    }
/**
     * @brief Draw a part of a texture defined by a rectangle
     */
    inline void DrawTextureRec(Texture2D texture, Rectangle source, Vector2 position, Color tint) {
        ::DrawTextureRec(texture, source, position, tint);
    }
/**
     * @brief Draw a part of a texture defined by a rectangle with 'pro' parameters
     */
    inline void DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint) {
        ::DrawTexturePro(texture, source, dest, origin, rotation, tint);
    }
/**
     * @brief Draws a texture (or part of it) that stretches or shrinks nicely
     */
    inline void DrawTextureNPatch(Texture2D texture, NPatchInfo nPatchInfo, Rectangle dest, Vector2 origin, float rotation, Color tint) {
        ::DrawTextureNPatch(texture, nPatchInfo, dest, origin, rotation, tint);
    }
/**
     * @brief Check if two colors are equal
     */
    [[nodiscard]] inline bool ColorIsEqual(Color col1, Color col2) {
        return ::ColorIsEqual(col1, col2);
    }
/**
     * @brief Get color with alpha applied, alpha goes from 0.0f to 1.0f
     */
    inline Color Fade(Color color, float alpha) {
        return ::Fade(color, alpha);
    }
/**
     * @brief Get hexadecimal value for a Color (0xRRGGBBAA)
     */
    inline int ColorToInt(Color color) {
        return ::ColorToInt(color);
    }
/**
     * @brief Get Color normalized as float [0..1]
     */
    inline Vector4 ColorNormalize(Color color) {
        return ::ColorNormalize(color);
    }
/**
     * @brief Get Color from normalized values [0..1]
     */
    inline Color ColorFromNormalized(Vector4 normalized) {
        return ::ColorFromNormalized(normalized);
    }
/**
     * @brief Get HSV values for a Color, hue [0..360], saturation/value [0..1]
     */
    inline Vector3 ColorToHSV(Color color) {
        return ::ColorToHSV(color);
    }
/**
     * @brief Get a Color from HSV values, hue [0..360], saturation/value [0..1]
     */
    inline Color ColorFromHSV(float hue, float saturation, float value) {
        return ::ColorFromHSV(hue, saturation, value);
    }
/**
     * @brief Get color multiplied with another color
     */
    inline Color ColorTint(Color color, Color tint) {
        return ::ColorTint(color, tint);
    }
/**
     * @brief Get color with brightness correction, brightness factor goes from -1.0f to 1.0f
     */
    inline Color ColorBrightness(Color color, float factor) {
        return ::ColorBrightness(color, factor);
    }
/**
     * @brief Get color with contrast correction, contrast values between -1.0f and 1.0f
     */
    inline Color ColorContrast(Color color, float contrast) {
        return ::ColorContrast(color, contrast);
    }
/**
     * @brief Get color with alpha applied, alpha goes from 0.0f to 1.0f
     */
    inline Color ColorAlpha(Color color, float alpha) {
        return ::ColorAlpha(color, alpha);
    }
/**
     * @brief Get src alpha-blended into dst color with tint
     */
    inline Color ColorAlphaBlend(Color dst, Color src, Color tint) {
        return ::ColorAlphaBlend(dst, src, tint);
    }
/**
     * @brief Get color lerp interpolation between two colors, factor [0.0f..1.0f]
     */
    inline Color ColorLerp(Color color1, Color color2, float factor) {
        return ::ColorLerp(color1, color2, factor);
    }
/**
     * @brief Get Color structure from hexadecimal value
     */
    inline Color GetColor(unsigned int hexValue) {
        return ::GetColor(hexValue);
    }
/**
     * @brief Get Color from a source pixel pointer of certain format
     */
    inline Color GetPixelColor(void * srcPtr, int format) {
        return ::GetPixelColor(srcPtr, format);
    }
/**
     * @brief Set color formatted into destination pixel pointer
     */
    inline void SetPixelColor(void * dstPtr, Color color, int format) {
        ::SetPixelColor(dstPtr, color, format);
    }
/**
     * @brief Get pixel data size in bytes for certain format
     */
    inline int GetPixelDataSize(int width, int height, int format) {
        return ::GetPixelDataSize(width, height, format);
    }
/**
     * @brief Get the default Font
     */
    inline Font GetFontDefault() {
        return ::GetFontDefault();
    }
/**
     * @brief Load font from file into GPU memory (VRAM)
     */
    inline Font LoadFont(std::string_view fileName) {
        return ::LoadFont(fileName.data());
    }
/**
     * @brief Load font from file with extended parameters, use NULL for codepoints and 0 for codepointCount to load the default character set, font size is provided in pixels height
     */
    inline Font LoadFontEx(std::string_view fileName, int fontSize, std::span<const int> codepoints) {
        return ::LoadFontEx(fileName.data(), fontSize, codepoints.data(), static_cast<int>(codepoints.size()));
    }
/**
     * @brief Load font from Image (XNA style)
     */
    inline Font LoadFontFromImage(Image image, Color key, int firstChar) {
        return ::LoadFontFromImage(image, key, firstChar);
    }
/**
     * @brief Load font from memory buffer, fileType refers to extension: i.e. '.ttf'
     */
    inline Font LoadFontFromMemory(std::string_view fileType, const unsigned char * fileData, int dataSize, int fontSize, std::span<const int> codepoints) {
        return ::LoadFontFromMemory(fileType.data(), fileData, dataSize, fontSize, codepoints.data(), static_cast<int>(codepoints.size()));
    }
/**
     * @brief Check if a font is valid (font data loaded, WARNING: GPU texture not checked)
     */
    [[nodiscard]] inline bool IsFontValid(Font font) {
        return ::IsFontValid(font);
    }
/**
     * @brief Load font data for further use
     */
    inline GlyphInfo * LoadFontData(const unsigned char * fileData, int dataSize, int fontSize, std::span<const int> codepoints, int type, int * glyphCount) {
        return ::LoadFontData(fileData, dataSize, fontSize, codepoints.data(), static_cast<int>(codepoints.size()), type, glyphCount);
    }
/**
     * @brief Generate image font atlas using chars info
     */
    inline Image GenImageFontAtlas(const GlyphInfo * glyphs, std::span<Rectangle *> glyphRecs, int fontSize, int padding, int packMethod) {
        return ::GenImageFontAtlas(glyphs, glyphRecs.data(), static_cast<int>(glyphRecs.size()), fontSize, padding, packMethod);
    }
/**
     * @brief Unload font chars info data (RAM)
     */
    inline void UnloadFontData(std::span<GlyphInfo> glyphs) {
        ::UnloadFontData(glyphs.data(), static_cast<int>(glyphs.size()));
    }
/**
     * @brief Unload font from GPU memory (VRAM)
     */
    inline void UnloadFont(Font font) {
        ::UnloadFont(font);
    }
/**
     * @brief Export font as code file, returns true on success
     */
    [[nodiscard]] inline bool ExportFontAsCode(Font font, std::string_view fileName) {
        return ::ExportFontAsCode(font, fileName.data());
    }
/**
     * @brief Draw current FPS
     */
    inline void DrawFPS(int posX, int posY) {
        ::DrawFPS(posX, posY);
    }
/**
     * @brief Draw text (using default font)
     */
    inline void DrawText(std::string_view text, int posX, int posY, int fontSize, Color color) {
        ::DrawText(text.data(), posX, posY, fontSize, color);
    }
/**
     * @brief Draw text using font and additional parameters
     */
    inline void DrawTextEx(Font font, std::string_view text, Vector2 position, float fontSize, float spacing, Color tint) {
        ::DrawTextEx(font, text.data(), position, fontSize, spacing, tint);
    }
/**
     * @brief Draw text using Font and pro parameters (rotation)
     */
    inline void DrawTextPro(Font font, std::string_view text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint) {
        ::DrawTextPro(font, text.data(), position, origin, rotation, fontSize, spacing, tint);
    }
/**
     * @brief Draw one character (codepoint)
     */
    inline void DrawTextCodepoint(Font font, int codepoint, Vector2 position, float fontSize, Color tint) {
        ::DrawTextCodepoint(font, codepoint, position, fontSize, tint);
    }
/**
     * @brief Draw multiple character (codepoint)
     */
    inline void DrawTextCodepoints(Font font, std::span<const int> codepoints, Vector2 position, float fontSize, float spacing, Color tint) {
        ::DrawTextCodepoints(font, codepoints.data(), static_cast<int>(codepoints.size()), position, fontSize, spacing, tint);
    }
/**
     * @brief Set vertical line spacing when drawing with line-breaks
     */
    inline void SetTextLineSpacing(int spacing) {
        ::SetTextLineSpacing(spacing);
    }
/**
     * @brief Measure string width for default font
     */
    inline int MeasureText(std::string_view text, int fontSize) {
        return ::MeasureText(text.data(), fontSize);
    }
/**
     * @brief Measure string size for Font
     */
    inline Vector2 MeasureTextEx(Font font, std::string_view text, float fontSize, float spacing) {
        return ::MeasureTextEx(font, text.data(), fontSize, spacing);
    }
/**
     * @brief Measure string size for an existing array of codepoints for Font
     */
    inline Vector2 MeasureTextCodepoints(Font font, std::span<const int> codepoints, float fontSize, float spacing) {
        return ::MeasureTextCodepoints(font, codepoints.data(), static_cast<int>(codepoints.size()), fontSize, spacing);
    }
/**
     * @brief Get glyph index position in font for a codepoint (unicode character), fallback to '?' if not found
     */
    inline int GetGlyphIndex(Font font, int codepoint) {
        return ::GetGlyphIndex(font, codepoint);
    }
/**
     * @brief Get glyph font info data for a codepoint (unicode character), fallback to '?' if not found
     */
    inline GlyphInfo GetGlyphInfo(Font font, int codepoint) {
        return ::GetGlyphInfo(font, codepoint);
    }
/**
     * @brief Get glyph rectangle in font atlas for a codepoint (unicode character), fallback to '?' if not found
     */
    inline Rectangle GetGlyphAtlasRec(Font font, int codepoint) {
        return ::GetGlyphAtlasRec(font, codepoint);
    }
/**
     * @brief Load UTF-8 text encoded from codepoints array
     */
    inline char * LoadUTF8(std::span<const int> codepoints) {
        return ::LoadUTF8(codepoints.data(), static_cast<int>(codepoints.size()));
    }
/**
     * @brief Unload UTF-8 text encoded from codepoints array
     */
    inline void UnloadUTF8(char * text) {
        ::UnloadUTF8(text);
    }
/**
     * @brief Load all codepoints from a UTF-8 text string, codepoints count returned by parameter
     */
    inline int * LoadCodepoints(std::string_view text, int * count) {
        return ::LoadCodepoints(text.data(), count);
    }
/**
     * @brief Unload codepoints data from memory
     */
    inline void UnloadCodepoints(int * codepoints) {
        ::UnloadCodepoints(codepoints);
    }
/**
     * @brief Get total number of codepoints in a UTF-8 encoded string
     */
    inline int GetCodepointCount(std::string_view text) {
        return ::GetCodepointCount(text.data());
    }
/**
     * @brief Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
     */
    inline int GetCodepoint(std::string_view text, int * codepointSize) {
        return ::GetCodepoint(text.data(), codepointSize);
    }
/**
     * @brief Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
     */
    inline int GetCodepointNext(std::string_view text, int * codepointSize) {
        return ::GetCodepointNext(text.data(), codepointSize);
    }
/**
     * @brief Get previous codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
     */
    inline int GetCodepointPrevious(std::string_view text, int * codepointSize) {
        return ::GetCodepointPrevious(text.data(), codepointSize);
    }
/**
     * @brief Encode one codepoint into UTF-8 byte array (array length returned as parameter)
     */
    inline const char * CodepointToUTF8(int codepoint, int * utf8Size) {
        return ::CodepointToUTF8(codepoint, utf8Size);
    }
/**
     * @brief Load text as separate lines ('\n')
     */
    inline char ** LoadTextLines(std::string_view text, int * count) {
        return ::LoadTextLines(text.data(), count);
    }
/**
     * @brief Unload text lines
     */
    inline void UnloadTextLines(char ** text, int lineCount) {
        ::UnloadTextLines(text, lineCount);
    }
/**
     * @brief Copy one string to another, returns bytes copied
     */
    inline int TextCopy(char * dst, std::string_view src) {
        return ::TextCopy(dst, src.data());
    }
/**
     * @brief Check if two text string are equal
     */
    [[nodiscard]] inline bool TextIsEqual(std::string_view text1, std::string_view text2) {
        return ::TextIsEqual(text1.data(), text2.data());
    }
/**
     * @brief Get text length, checks for '\0' ending
     */
    inline unsigned int TextLength(std::string_view text) {
        return ::TextLength(text.data());
    }
/**
     * @brief Text formatting with variables (sprintf() style)
     */
    template <typename... Args>
    inline const char * TextFormat(std::string_view text, Args... args) {
        return ::TextFormat(text.data(), args...);
    }
/**
     * @brief Get a piece of a text string
     */
    inline const char * TextSubtext(std::string_view text, int position, int length) {
        return ::TextSubtext(text.data(), position, length);
    }
/**
     * @brief Remove text spaces, concat words
     */
    inline const char * TextRemoveSpaces(std::string_view text) {
        return ::TextRemoveSpaces(text.data());
    }
/**
     * @brief Get text between two strings
     */
    inline char * GetTextBetween(std::string_view text, std::string_view begin, std::string_view end) {
        return ::GetTextBetween(text.data(), begin.data(), end.data());
    }
/**
     * @brief Replace text string with new string
     */
    inline char * TextReplace(std::string_view text, std::string_view search, std::string_view replacement) {
        return ::TextReplace(text.data(), search.data(), replacement.data());
    }
/**
     * @brief Replace text string with new string, memory must be MemFree()
     */
    inline char * TextReplaceAlloc(std::string_view text, std::string_view search, std::string_view replacement) {
        return ::TextReplaceAlloc(text.data(), search.data(), replacement.data());
    }
/**
     * @brief Replace text between two specific strings
     */
    inline char * TextReplaceBetween(std::string_view text, std::string_view begin, std::string_view end, std::string_view replacement) {
        return ::TextReplaceBetween(text.data(), begin.data(), end.data(), replacement.data());
    }
/**
     * @brief Replace text between two specific strings, memory must be MemFree()
     */
    inline char * TextReplaceBetweenAlloc(std::string_view text, std::string_view begin, std::string_view end, std::string_view replacement) {
        return ::TextReplaceBetweenAlloc(text.data(), begin.data(), end.data(), replacement.data());
    }
/**
     * @brief Insert text in a defined byte position
     */
    inline char * TextInsert(std::string_view text, std::string_view insert, int position) {
        return ::TextInsert(text.data(), insert.data(), position);
    }
/**
     * @brief Insert text in a defined byte position, memory must be MemFree()
     */
    inline char * TextInsertAlloc(std::string_view text, std::string_view insert, int position) {
        return ::TextInsertAlloc(text.data(), insert.data(), position);
    }
/**
     * @brief Join text strings with delimiter
     */
    inline char * TextJoin(char ** textList, int count, std::string_view delimiter) {
        return ::TextJoin(textList, count, delimiter.data());
    }
/**
     * @brief Split text into multiple strings, using MAX_TEXTSPLIT_COUNT static strings
     */
    inline char ** TextSplit(std::string_view text, char delimiter, int * count) {
        return ::TextSplit(text.data(), delimiter, count);
    }
/**
     * @brief Append text at specific position and move cursor
     */
    inline void TextAppend(char * text, std::string_view append, int * position) {
        ::TextAppend(text, append.data(), position);
    }
/**
     * @brief Find first text occurrence within a string, -1 if not found
     */
    inline int TextFindIndex(std::string_view text, std::string_view search) {
        return ::TextFindIndex(text.data(), search.data());
    }
/**
     * @brief Get upper case version of provided string
     */
    inline char * TextToUpper(std::string_view text) {
        return ::TextToUpper(text.data());
    }
/**
     * @brief Get lower case version of provided string
     */
    inline char * TextToLower(std::string_view text) {
        return ::TextToLower(text.data());
    }
/**
     * @brief Get Pascal case notation version of provided string
     */
    inline char * TextToPascal(std::string_view text) {
        return ::TextToPascal(text.data());
    }
/**
     * @brief Get Snake case notation version of provided string
     */
    inline char * TextToSnake(std::string_view text) {
        return ::TextToSnake(text.data());
    }
/**
     * @brief Get Camel case notation version of provided string
     */
    inline char * TextToCamel(std::string_view text) {
        return ::TextToCamel(text.data());
    }
/**
     * @brief Get integer value from text
     */
    inline int TextToInteger(std::string_view text) {
        return ::TextToInteger(text.data());
    }
/**
     * @brief Get float value from text
     */
    inline float TextToFloat(std::string_view text) {
        return ::TextToFloat(text.data());
    }
/**
     * @brief Draw a line in 3D world space
     */
    inline void DrawLine3D(Vector3 startPos, Vector3 endPos, Color color) {
        ::DrawLine3D(startPos, endPos, color);
    }
/**
     * @brief Draw a point in 3D space, actually a small line
     */
    inline void DrawPoint3D(Vector3 position, Color color) {
        ::DrawPoint3D(position, color);
    }
/**
     * @brief Draw a circle in 3D world space
     */
    inline void DrawCircle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color) {
        ::DrawCircle3D(center, radius, rotationAxis, rotationAngle, color);
    }
/**
     * @brief Draw a color-filled triangle (vertex in counter-clockwise order!)
     */
    inline void DrawTriangle3D(Vector3 v1, Vector3 v2, Vector3 v3, Color color) {
        ::DrawTriangle3D(v1, v2, v3, color);
    }
/**
     * @brief Draw a triangle strip defined by points
     */
    inline void DrawTriangleStrip3D(std::span<const Vector3> points, Color color) {
        ::DrawTriangleStrip3D(points.data(), static_cast<int>(points.size()), color);
    }
/**
     * @brief Draw cube
     */
    inline void DrawCube(Vector3 position, float width, float height, float length, Color color) {
        ::DrawCube(position, width, height, length, color);
    }
/**
     * @brief Draw cube (Vector version)
     */
    inline void DrawCubeV(Vector3 position, Vector3 size, Color color) {
        ::DrawCubeV(position, size, color);
    }
/**
     * @brief Draw cube wires
     */
    inline void DrawCubeWires(Vector3 position, float width, float height, float length, Color color) {
        ::DrawCubeWires(position, width, height, length, color);
    }
/**
     * @brief Draw cube wires (Vector version)
     */
    inline void DrawCubeWiresV(Vector3 position, Vector3 size, Color color) {
        ::DrawCubeWiresV(position, size, color);
    }
/**
     * @brief Draw sphere
     */
    inline void DrawSphere(Vector3 centerPos, float radius, Color color) {
        ::DrawSphere(centerPos, radius, color);
    }
/**
     * @brief Draw sphere with extended parameters
     */
    inline void DrawSphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color) {
        ::DrawSphereEx(centerPos, radius, rings, slices, color);
    }
/**
     * @brief Draw sphere wires
     */
    inline void DrawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color) {
        ::DrawSphereWires(centerPos, radius, rings, slices, color);
    }
/**
     * @brief Draw a cylinder/cone
     */
    inline void DrawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color) {
        ::DrawCylinder(position, radiusTop, radiusBottom, height, slices, color);
    }
/**
     * @brief Draw a cylinder with base at startPos and top at endPos
     */
    inline void DrawCylinderEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color) {
        ::DrawCylinderEx(startPos, endPos, startRadius, endRadius, sides, color);
    }
/**
     * @brief Draw a cylinder/cone wires
     */
    inline void DrawCylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color) {
        ::DrawCylinderWires(position, radiusTop, radiusBottom, height, slices, color);
    }
/**
     * @brief Draw a cylinder wires with base at startPos and top at endPos
     */
    inline void DrawCylinderWiresEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color) {
        ::DrawCylinderWiresEx(startPos, endPos, startRadius, endRadius, sides, color);
    }
/**
     * @brief Draw a capsule with the center of its sphere caps at startPos and endPos
     */
    inline void DrawCapsule(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color) {
        ::DrawCapsule(startPos, endPos, radius, slices, rings, color);
    }
/**
     * @brief Draw capsule wireframe with the center of its sphere caps at startPos and endPos
     */
    inline void DrawCapsuleWires(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color) {
        ::DrawCapsuleWires(startPos, endPos, radius, slices, rings, color);
    }
/**
     * @brief Draw a plane XZ
     */
    inline void DrawPlane(Vector3 centerPos, Vector2 size, Color color) {
        ::DrawPlane(centerPos, size, color);
    }
/**
     * @brief Draw a ray line
     */
    inline void DrawRay(Ray ray, Color color) {
        ::DrawRay(ray, color);
    }
/**
     * @brief Draw a grid (centered at (0, 0, 0))
     */
    inline void DrawGrid(int slices, float spacing) {
        ::DrawGrid(slices, spacing);
    }
/**
     * @brief Load model from files (meshes and materials)
     */
    inline Model LoadModel(std::string_view fileName) {
        return ::LoadModel(fileName.data());
    }
/**
     * @brief Load model from generated mesh (default material)
     */
    inline Model LoadModelFromMesh(Mesh mesh) {
        return ::LoadModelFromMesh(mesh);
    }
/**
     * @brief Check if a model is valid (loaded in GPU, VAO/VBOs)
     */
    [[nodiscard]] inline bool IsModelValid(Model model) {
        return ::IsModelValid(model);
    }
/**
     * @brief Unload model (including meshes) from memory (RAM and/or VRAM)
     */
    inline void UnloadModel(Model model) {
        ::UnloadModel(model);
    }
/**
     * @brief Compute model bounding box limits (considers all meshes)
     */
    inline BoundingBox GetModelBoundingBox(Model model) {
        return ::GetModelBoundingBox(model);
    }
/**
     * @brief Draw a model (with texture if set)
     */
    inline void DrawModel(Model model, Vector3 position, float scale, Color tint) {
        ::DrawModel(model, position, scale, tint);
    }
/**
     * @brief Draw a model with extended parameters
     */
    inline void DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint) {
        ::DrawModelEx(model, position, rotationAxis, rotationAngle, scale, tint);
    }
/**
     * @brief Draw a model wires (with texture if set)
     */
    inline void DrawModelWires(Model model, Vector3 position, float scale, Color tint) {
        ::DrawModelWires(model, position, scale, tint);
    }
/**
     * @brief Draw a model wires (with texture if set) with extended parameters
     */
    inline void DrawModelWiresEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint) {
        ::DrawModelWiresEx(model, position, rotationAxis, rotationAngle, scale, tint);
    }
/**
     * @brief Draw bounding box (wires)
     */
    inline void DrawBoundingBox(BoundingBox box, Color color) {
        ::DrawBoundingBox(box, color);
    }
/**
     * @brief Draw a billboard texture
     */
    inline void DrawBillboard(Camera camera, Texture2D texture, Vector3 position, float scale, Color tint) {
        ::DrawBillboard(camera, texture, position, scale, tint);
    }
/**
     * @brief Draw a billboard texture defined by source
     */
    inline void DrawBillboardRec(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector2 size, Color tint) {
        ::DrawBillboardRec(camera, texture, source, position, size, tint);
    }
/**
     * @brief Draw a billboard texture defined by source and rotation
     */
    inline void DrawBillboardPro(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector3 up, Vector2 size, Vector2 origin, float rotation, Color tint) {
        ::DrawBillboardPro(camera, texture, source, position, up, size, origin, rotation, tint);
    }
/**
     * @brief Upload mesh vertex data in GPU and provide VAO/VBO ids
     */
    inline void UploadMesh(Mesh * mesh, bool dynamic) {
        ::UploadMesh(mesh, dynamic);
    }
/**
     * @brief Update mesh vertex data in GPU for a specific buffer index
     */
    inline void UpdateMeshBuffer(Mesh mesh, int index, const void * data, int dataSize, int offset) {
        ::UpdateMeshBuffer(mesh, index, data, dataSize, offset);
    }
/**
     * @brief Unload mesh data from CPU and GPU
     */
    inline void UnloadMesh(Mesh mesh) {
        ::UnloadMesh(mesh);
    }
/**
     * @brief Draw a 3d mesh with material and transform
     */
    inline void DrawMesh(Mesh mesh, Material material, Matrix transform) {
        ::DrawMesh(mesh, material, transform);
    }
/**
     * @brief Draw multiple mesh instances with material and different transforms
     */
    inline void DrawMeshInstanced(Mesh mesh, Material material, const Matrix * transforms, int instances) {
        ::DrawMeshInstanced(mesh, material, transforms, instances);
    }
/**
     * @brief Compute mesh bounding box limits
     */
    inline BoundingBox GetMeshBoundingBox(Mesh mesh) {
        return ::GetMeshBoundingBox(mesh);
    }
/**
     * @brief Compute mesh tangents
     */
    inline void GenMeshTangents(Mesh * mesh) {
        ::GenMeshTangents(mesh);
    }
/**
     * @brief Export mesh data to file, returns true on success
     */
    [[nodiscard]] inline bool ExportMesh(Mesh mesh, std::string_view fileName) {
        return ::ExportMesh(mesh, fileName.data());
    }
/**
     * @brief Export mesh as code file (.h) defining multiple arrays of vertex attributes
     */
    [[nodiscard]] inline bool ExportMeshAsCode(Mesh mesh, std::string_view fileName) {
        return ::ExportMeshAsCode(mesh, fileName.data());
    }
/**
     * @brief Generate polygonal mesh
     */
    inline Mesh GenMeshPoly(int sides, float radius) {
        return ::GenMeshPoly(sides, radius);
    }
/**
     * @brief Generate plane mesh (with subdivisions)
     */
    inline Mesh GenMeshPlane(float width, float length, int resX, int resZ) {
        return ::GenMeshPlane(width, length, resX, resZ);
    }
/**
     * @brief Generate cuboid mesh
     */
    inline Mesh GenMeshCube(float width, float height, float length) {
        return ::GenMeshCube(width, height, length);
    }
/**
     * @brief Generate sphere mesh (standard sphere)
     */
    inline Mesh GenMeshSphere(float radius, int rings, int slices) {
        return ::GenMeshSphere(radius, rings, slices);
    }
/**
     * @brief Generate half-sphere mesh (no bottom cap)
     */
    inline Mesh GenMeshHemiSphere(float radius, int rings, int slices) {
        return ::GenMeshHemiSphere(radius, rings, slices);
    }
/**
     * @brief Generate cylinder mesh
     */
    inline Mesh GenMeshCylinder(float radius, float height, int slices) {
        return ::GenMeshCylinder(radius, height, slices);
    }
/**
     * @brief Generate cone/pyramid mesh
     */
    inline Mesh GenMeshCone(float radius, float height, int slices) {
        return ::GenMeshCone(radius, height, slices);
    }
/**
     * @brief Generate torus mesh
     */
    inline Mesh GenMeshTorus(float radius, float size, int radSeg, int sides) {
        return ::GenMeshTorus(radius, size, radSeg, sides);
    }
/**
     * @brief Generate trefoil knot mesh
     */
    inline Mesh GenMeshKnot(float radius, float size, int radSeg, int sides) {
        return ::GenMeshKnot(radius, size, radSeg, sides);
    }
/**
     * @brief Generate heightmap mesh from image data
     */
    inline Mesh GenMeshHeightmap(Image heightmap, Vector3 size) {
        return ::GenMeshHeightmap(heightmap, size);
    }
/**
     * @brief Generate cubes-based map mesh from image data
     */
    inline Mesh GenMeshCubicmap(Image cubicmap, Vector3 cubeSize) {
        return ::GenMeshCubicmap(cubicmap, cubeSize);
    }
/**
     * @brief Load materials from model file
     */
    inline Material * LoadMaterials(std::string_view fileName, int * materialCount) {
        return ::LoadMaterials(fileName.data(), materialCount);
    }
/**
     * @brief Load default material (Supports: DIFFUSE, SPECULAR, NORMAL maps)
     */
    inline Material LoadMaterialDefault() {
        return ::LoadMaterialDefault();
    }
/**
     * @brief Check if a material is valid (shader assigned, map textures loaded in GPU)
     */
    [[nodiscard]] inline bool IsMaterialValid(Material material) {
        return ::IsMaterialValid(material);
    }
/**
     * @brief Unload material from GPU memory (VRAM)
     */
    inline void UnloadMaterial(Material material) {
        ::UnloadMaterial(material);
    }
/**
     * @brief Set texture for a material map type (MATERIAL_MAP_DIFFUSE, MATERIAL_MAP_SPECULAR...)
     */
    inline void SetMaterialTexture(Material * material, int mapType, Texture2D texture) {
        ::SetMaterialTexture(material, mapType, texture);
    }
/**
     * @brief Set material for a mesh
     */
    inline void SetModelMeshMaterial(Model * model, int meshId, int materialId) {
        ::SetModelMeshMaterial(model, meshId, materialId);
    }
/**
     * @brief Load model animations from file
     */
    inline ModelAnimation * LoadModelAnimations(std::string_view fileName, int * animCount) {
        return ::LoadModelAnimations(fileName.data(), animCount);
    }
/**
     * @brief Update model animation pose (vertex buffers and bone matrices)
     */
    inline void UpdateModelAnimation(Model model, ModelAnimation anim, float frame) {
        ::UpdateModelAnimation(model, anim, frame);
    }
/**
     * @brief Update model animation pose, blending two animations
     */
    inline void UpdateModelAnimationEx(Model model, ModelAnimation animA, float frameA, ModelAnimation animB, float frameB, float blend) {
        ::UpdateModelAnimationEx(model, animA, frameA, animB, frameB, blend);
    }
/**
     * @brief Unload animation array data
     */
    inline void UnloadModelAnimations(std::span<ModelAnimation> animations) {
        ::UnloadModelAnimations(animations.data(), static_cast<int>(animations.size()));
    }
/**
     * @brief Check model animation skeleton match
     */
    [[nodiscard]] inline bool IsModelAnimationValid(Model model, ModelAnimation anim) {
        return ::IsModelAnimationValid(model, anim);
    }
/**
     * @brief Check collision between two spheres
     */
    [[nodiscard]] inline bool CheckCollisionSpheres(Vector3 center1, float radius1, Vector3 center2, float radius2) {
        return ::CheckCollisionSpheres(center1, radius1, center2, radius2);
    }
/**
     * @brief Check collision between two bounding boxes
     */
    [[nodiscard]] inline bool CheckCollisionBoxes(BoundingBox box1, BoundingBox box2) {
        return ::CheckCollisionBoxes(box1, box2);
    }
/**
     * @brief Check collision between box and sphere
     */
    [[nodiscard]] inline bool CheckCollisionBoxSphere(BoundingBox box, Vector3 center, float radius) {
        return ::CheckCollisionBoxSphere(box, center, radius);
    }
/**
     * @brief Get collision info between ray and sphere
     */
    inline RayCollision GetRayCollisionSphere(Ray ray, Vector3 center, float radius) {
        return ::GetRayCollisionSphere(ray, center, radius);
    }
/**
     * @brief Get collision info between ray and box
     */
    inline RayCollision GetRayCollisionBox(Ray ray, BoundingBox box) {
        return ::GetRayCollisionBox(ray, box);
    }
/**
     * @brief Get collision info between ray and mesh
     */
    inline RayCollision GetRayCollisionMesh(Ray ray, Mesh mesh, Matrix transform) {
        return ::GetRayCollisionMesh(ray, mesh, transform);
    }
/**
     * @brief Get collision info between ray and triangle
     */
    inline RayCollision GetRayCollisionTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3) {
        return ::GetRayCollisionTriangle(ray, p1, p2, p3);
    }
/**
     * @brief Get collision info between ray and quad
     */
    inline RayCollision GetRayCollisionQuad(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4) {
        return ::GetRayCollisionQuad(ray, p1, p2, p3, p4);
    }
/**
     * @brief Initialize audio device and context
     */
    inline void InitAudioDevice() {
        ::InitAudioDevice();
    }
/**
     * @brief Close the audio device and context
     */
    inline void CloseAudioDevice() {
        ::CloseAudioDevice();
    }
/**
     * @brief Check if audio device has been initialized successfully
     */
    [[nodiscard]] inline bool IsAudioDeviceReady() {
        return ::IsAudioDeviceReady();
    }
/**
     * @brief Set master volume (listener)
     */
    inline void SetMasterVolume(float volume) {
        ::SetMasterVolume(volume);
    }
/**
     * @brief Get master volume (listener)
     */
    inline float GetMasterVolume() {
        return ::GetMasterVolume();
    }
/**
     * @brief Load wave data from file
     */
    inline Wave LoadWave(std::string_view fileName) {
        return ::LoadWave(fileName.data());
    }
/**
     * @brief Load wave from memory buffer, fileType refers to extension: i.e. '.wav'
     */
    inline Wave LoadWaveFromMemory(std::string_view fileType, const unsigned char * fileData, int dataSize) {
        return ::LoadWaveFromMemory(fileType.data(), fileData, dataSize);
    }
/**
     * @brief Checks if wave data is valid (data loaded and parameters)
     */
    [[nodiscard]] inline bool IsWaveValid(Wave wave) {
        return ::IsWaveValid(wave);
    }
/**
     * @brief Load sound from file
     */
    inline Sound LoadSound(std::string_view fileName) {
        return ::LoadSound(fileName.data());
    }
/**
     * @brief Load sound from wave data
     */
    inline Sound LoadSoundFromWave(Wave wave) {
        return ::LoadSoundFromWave(wave);
    }
/**
     * @brief Create a new sound that shares the same sample data as the source sound, does not own the sound data
     */
    inline Sound LoadSoundAlias(Sound source) {
        return ::LoadSoundAlias(source);
    }
/**
     * @brief Checks if a sound is valid (data loaded and buffers initialized)
     */
    [[nodiscard]] inline bool IsSoundValid(Sound sound) {
        return ::IsSoundValid(sound);
    }
/**
     * @brief Update sound buffer with new data (default data format: 32 bit float, stereo)
     */
    inline void UpdateSound(Sound sound, const void * data, int sampleCount) {
        ::UpdateSound(sound, data, sampleCount);
    }
/**
     * @brief Unload wave data
     */
    inline void UnloadWave(Wave wave) {
        ::UnloadWave(wave);
    }
/**
     * @brief Unload sound
     */
    inline void UnloadSound(Sound sound) {
        ::UnloadSound(sound);
    }
/**
     * @brief Unload a sound alias (does not deallocate sample data)
     */
    inline void UnloadSoundAlias(Sound alias) {
        ::UnloadSoundAlias(alias);
    }
/**
     * @brief Export wave data to file, returns true on success
     */
    [[nodiscard]] inline bool ExportWave(Wave wave, std::string_view fileName) {
        return ::ExportWave(wave, fileName.data());
    }
/**
     * @brief Export wave sample data to code (.h), returns true on success
     */
    [[nodiscard]] inline bool ExportWaveAsCode(Wave wave, std::string_view fileName) {
        return ::ExportWaveAsCode(wave, fileName.data());
    }
/**
     * @brief Play a sound
     */
    inline void PlaySound(Sound sound) {
        ::PlaySound(sound);
    }
/**
     * @brief Stop playing a sound
     */
    inline void StopSound(Sound sound) {
        ::StopSound(sound);
    }
/**
     * @brief Pause a sound
     */
    inline void PauseSound(Sound sound) {
        ::PauseSound(sound);
    }
/**
     * @brief Resume a paused sound
     */
    inline void ResumeSound(Sound sound) {
        ::ResumeSound(sound);
    }
/**
     * @brief Check if a sound is currently playing
     */
    [[nodiscard]] inline bool IsSoundPlaying(Sound sound) {
        return ::IsSoundPlaying(sound);
    }
/**
     * @brief Set volume for a sound (1.0 is max level)
     */
    inline void SetSoundVolume(Sound sound, float volume) {
        ::SetSoundVolume(sound, volume);
    }
/**
     * @brief Set pitch for a sound (1.0 is base level)
     */
    inline void SetSoundPitch(Sound sound, float pitch) {
        ::SetSoundPitch(sound, pitch);
    }
/**
     * @brief Set pan for a sound (-1.0 left, 0.0 center, 1.0 right)
     */
    inline void SetSoundPan(Sound sound, float pan) {
        ::SetSoundPan(sound, pan);
    }
/**
     * @brief Copy a wave to a new wave
     */
    inline Wave WaveCopy(Wave wave) {
        return ::WaveCopy(wave);
    }
/**
     * @brief Crop a wave to defined frames range
     */
    inline void WaveCrop(Wave * wave, int initFrame, int finalFrame) {
        ::WaveCrop(wave, initFrame, finalFrame);
    }
/**
     * @brief Convert wave data to desired format
     */
    inline void WaveFormat(Wave * wave, int sampleRate, int sampleSize, int channels) {
        ::WaveFormat(wave, sampleRate, sampleSize, channels);
    }
/**
     * @brief Load samples data from wave as a 32bit float data array
     */
    inline float * LoadWaveSamples(Wave wave) {
        return ::LoadWaveSamples(wave);
    }
/**
     * @brief Unload samples data loaded with LoadWaveSamples()
     */
    inline void UnloadWaveSamples(float * samples) {
        ::UnloadWaveSamples(samples);
    }
/**
     * @brief Load music stream from file
     */
    inline Music LoadMusicStream(std::string_view fileName) {
        return ::LoadMusicStream(fileName.data());
    }
/**
     * @brief Load music stream from data
     */
    inline Music LoadMusicStreamFromMemory(std::string_view fileType, const unsigned char * data, int dataSize) {
        return ::LoadMusicStreamFromMemory(fileType.data(), data, dataSize);
    }
/**
     * @brief Checks if a music stream is valid (context and buffers initialized)
     */
    [[nodiscard]] inline bool IsMusicValid(Music music) {
        return ::IsMusicValid(music);
    }
/**
     * @brief Unload music stream
     */
    inline void UnloadMusicStream(Music music) {
        ::UnloadMusicStream(music);
    }
/**
     * @brief Start music playing
     */
    inline void PlayMusicStream(Music music) {
        ::PlayMusicStream(music);
    }
/**
     * @brief Check if music is playing
     */
    [[nodiscard]] inline bool IsMusicStreamPlaying(Music music) {
        return ::IsMusicStreamPlaying(music);
    }
/**
     * @brief Updates buffers for music streaming
     */
    inline void UpdateMusicStream(Music music) {
        ::UpdateMusicStream(music);
    }
/**
     * @brief Stop music playing
     */
    inline void StopMusicStream(Music music) {
        ::StopMusicStream(music);
    }
/**
     * @brief Pause music playing
     */
    inline void PauseMusicStream(Music music) {
        ::PauseMusicStream(music);
    }
/**
     * @brief Resume playing paused music
     */
    inline void ResumeMusicStream(Music music) {
        ::ResumeMusicStream(music);
    }
/**
     * @brief Seek music to a position (in seconds)
     */
    inline void SeekMusicStream(Music music, float position) {
        ::SeekMusicStream(music, position);
    }
/**
     * @brief Set volume for music (1.0 is max level)
     */
    inline void SetMusicVolume(Music music, float volume) {
        ::SetMusicVolume(music, volume);
    }
/**
     * @brief Set pitch for a music (1.0 is base level)
     */
    inline void SetMusicPitch(Music music, float pitch) {
        ::SetMusicPitch(music, pitch);
    }
/**
     * @brief Set pan for a music (-1.0 left, 0.0 center, 1.0 right)
     */
    inline void SetMusicPan(Music music, float pan) {
        ::SetMusicPan(music, pan);
    }
/**
     * @brief Get music time length (in seconds)
     */
    inline float GetMusicTimeLength(Music music) {
        return ::GetMusicTimeLength(music);
    }
/**
     * @brief Get current music time played (in seconds)
     */
    inline float GetMusicTimePlayed(Music music) {
        return ::GetMusicTimePlayed(music);
    }
/**
     * @brief Load audio stream (to stream raw audio pcm data)
     */
    inline AudioStream LoadAudioStream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels) {
        return ::LoadAudioStream(sampleRate, sampleSize, channels);
    }
/**
     * @brief Checks if an audio stream is valid (buffers initialized)
     */
    [[nodiscard]] inline bool IsAudioStreamValid(AudioStream stream) {
        return ::IsAudioStreamValid(stream);
    }
/**
     * @brief Unload audio stream and free memory
     */
    inline void UnloadAudioStream(AudioStream stream) {
        ::UnloadAudioStream(stream);
    }
/**
     * @brief Update audio stream buffers with data
     */
    inline void UpdateAudioStream(AudioStream stream, const void * data, int frameCount) {
        ::UpdateAudioStream(stream, data, frameCount);
    }
/**
     * @brief Check if any audio stream buffers requires refill
     */
    [[nodiscard]] inline bool IsAudioStreamProcessed(AudioStream stream) {
        return ::IsAudioStreamProcessed(stream);
    }
/**
     * @brief Play audio stream
     */
    inline void PlayAudioStream(AudioStream stream) {
        ::PlayAudioStream(stream);
    }
/**
     * @brief Pause audio stream
     */
    inline void PauseAudioStream(AudioStream stream) {
        ::PauseAudioStream(stream);
    }
/**
     * @brief Resume audio stream
     */
    inline void ResumeAudioStream(AudioStream stream) {
        ::ResumeAudioStream(stream);
    }
/**
     * @brief Check if audio stream is playing
     */
    [[nodiscard]] inline bool IsAudioStreamPlaying(AudioStream stream) {
        return ::IsAudioStreamPlaying(stream);
    }
/**
     * @brief Stop audio stream
     */
    inline void StopAudioStream(AudioStream stream) {
        ::StopAudioStream(stream);
    }
/**
     * @brief Set volume for audio stream (1.0 is max level)
     */
    inline void SetAudioStreamVolume(AudioStream stream, float volume) {
        ::SetAudioStreamVolume(stream, volume);
    }
/**
     * @brief Set pitch for audio stream (1.0 is base level)
     */
    inline void SetAudioStreamPitch(AudioStream stream, float pitch) {
        ::SetAudioStreamPitch(stream, pitch);
    }
/**
     * @brief Set pan for audio stream (-1.0 to 1.0 range, 0.0 is centered)
     */
    inline void SetAudioStreamPan(AudioStream stream, float pan) {
        ::SetAudioStreamPan(stream, pan);
    }
/**
     * @brief Default size for new audio streams
     */
    inline void SetAudioStreamBufferSizeDefault(int size) {
        ::SetAudioStreamBufferSizeDefault(size);
    }
/**
     * @brief Audio thread callback to request new data
     */
    inline void SetAudioStreamCallback(AudioStream stream, AudioCallback callback) {
        ::SetAudioStreamCallback(stream, callback);
    }
/**
     * @brief Attach audio stream processor to stream, receives frames x 2 samples as 'float' (stereo)
     */
    inline void AttachAudioStreamProcessor(AudioStream stream, AudioCallback processor) {
        ::AttachAudioStreamProcessor(stream, processor);
    }
/**
     * @brief Detach audio stream processor from stream
     */
    inline void DetachAudioStreamProcessor(AudioStream stream, AudioCallback processor) {
        ::DetachAudioStreamProcessor(stream, processor);
    }
/**
     * @brief Attach audio stream processor to the entire audio pipeline, receives frames x 2 samples as 'float' (stereo)
     */
    inline void AttachAudioMixedProcessor(AudioCallback processor) {
        ::AttachAudioMixedProcessor(processor);
    }
/**
     * @brief Detach audio stream processor from the entire audio pipeline
     */
    inline void DetachAudioMixedProcessor(AudioCallback processor) {
        ::DetachAudioMixedProcessor(processor);
    }


} // namespace RaylibStd