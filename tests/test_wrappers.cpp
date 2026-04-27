#include <catch2/catch_all.hpp>
#include "raylib-std.hpp"

TEST_CASE("Color utilities functionality", "[color]") {
    SECTION("Fade applies alpha correctly") {
        Color base = { 255, 0, 0, 255 }; // Red
        Color faded = RaylibStd::Fade(base, 0.5f);
        
        REQUIRE(faded.a == 127);
        REQUIRE(faded.r == 255);
    }

    SECTION("Color conversion") {
        Color col = RaylibStd::GetColor(0xFF0000FF);
        REQUIRE(col.r == 255);
        REQUIRE(col.a == 255);
    }
}

TEST_CASE("Text processing wrappers", "[text]") {
    SECTION("TextLength handles std::string_view") {
        std::string_view myText = "Hello Raylib";
        unsigned int length = RaylibStd::TextLength(myText);
        REQUIRE(length == 12);
    }

    SECTION("TextIsEqual compares correctly") {
        REQUIRE(RaylibStd::TextIsEqual("test", "test") == true);
        REQUIRE(RaylibStd::TextIsEqual("test", "diff") == false);
    }
}

TEST_CASE("Collision detection wrappers", "[collision]") {
    SECTION("Rectangle collision") {
        Rectangle r1 = { 0, 0, 10, 10 };
        Rectangle r2 = { 5, 5, 10, 10 };
        REQUIRE(RaylibStd::CheckCollisionRecs(r1, r2) == true);
    }
}