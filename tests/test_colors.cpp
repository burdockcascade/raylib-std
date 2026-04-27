#include <catch2/catch_all.hpp>
#include "raylib-std.hpp"

TEST_CASE("Color manipulation and conversion", "[color]") {

    SECTION("Color comparison") {
        Color col1 = { 255, 128, 64, 255 };
        Color col2 = { 255, 128, 64, 255 };
        Color col3 = { 0, 0, 0, 255 };

        REQUIRE(RaylibStd::color_is_equal(col1, col2) == true);
        REQUIRE(RaylibStd::color_is_equal(col1, col3) == false);
    }

    SECTION("Color to Integer conversion") {
        Color red = { 255, 0, 0, 255 };
        int hexValue = RaylibStd::color_to_int(red);
        
        // 0xFF0000FF in decimal is 4278190335
        REQUIRE(hexValue == 0xFF0000FF); 
    }

    SECTION("Color normalization") {
        Color halfWhite = { 127, 127, 127, 255 };
        Vector4 norm = RaylibStd::color_normalize(halfWhite);
        
        // 127 / 255.0f is approximately 0.498f
        REQUIRE_THAT(norm.x, Catch::Matchers::WithinAbs(0.498f, 0.01f));
        REQUIRE_THAT(norm.y, Catch::Matchers::WithinAbs(0.498f, 0.01f));
        REQUIRE_THAT(norm.z, Catch::Matchers::WithinAbs(0.498f, 0.01f));
        REQUIRE_THAT(norm.w, Catch::Matchers::WithinAbs(1.0f, 0.01f));
    }

    SECTION("Alpha blending") {
        Color dst = { 255, 0, 0, 255 };   // Solid Red
        Color src = { 0, 0, 255, 127 };   // 50% Transparent Blue
        Color tint = { 255, 255, 255, 255 }; // No tint alteration

        Color blended = RaylibStd::color_alpha_blend(dst, src, tint);
        
        // Result should be a mix of red and blue
        REQUIRE(blended.r < 255);
        REQUIRE(blended.b > 0);
        REQUIRE(blended.a == 255);
    }
}