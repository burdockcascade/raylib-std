add_rules("mode.debug", "mode.release")

set_languages("c++20")

add_requires("raylib 6.0")
add_requires("catch2")

target("raylib-std")
    set_kind("headeronly")
    add_includedirs("include")
    add_headerfiles("include/raylib-std.hpp")
    add_packages("raylib")

target("tests")
    set_kind("binary")
    add_packages("catch2", "raylib")
    add_includedirs("include")
    add_files("tests/*.cpp")
    add_rules("mode.debug", "mode.release")