#include <catch2/catch_all.hpp>
#include "raylib-std.hpp"
#include <string>

TEST_CASE("Text and string operations", "[text]") {

    SECTION("String View bridging") {
        std::string myStr = "Raylib-Std Framework";
        std::string_view view(myStr);
        
        REQUIRE(RaylibStd::TextLength(view) == 20);
        REQUIRE(RaylibStd::TextIsEqual(view, "Raylib-Std Framework") == true);
    }

    SECTION("Text format manipulations") {
        // Note: Some text functions in raylib return internal static buffers.
        // It's good to capture them in a std::string for safe comparison.
        
        std::string_view lower = "hello world";
        std::string upperStr = RaylibStd::TextToUpper(lower);
        REQUIRE(upperStr == "HELLO WORLD");

        std::string_view mixed = "HeLlO WoRlD";
        std::string lowerStr = RaylibStd::TextToLower(mixed);
        REQUIRE(lowerStr == "hello world");
    }

    SECTION("Text parsing") {
        std::string_view numberStr = "42";
        REQUIRE(RaylibStd::TextToInteger(numberStr) == 42);

        std::string_view floatStr = "3.14159";
        REQUIRE_THAT(RaylibStd::TextToFloat(floatStr), Catch::Matchers::WithinAbs(3.14159f, 0.0001f));
    }
}