#include <catch2/catch_all.hpp>
#include "raylib-std.hpp"

TEST_CASE("Collision detection functions", "[collision][math]") {

    SECTION("Rectangle to Rectangle Collision") {
        Rectangle rec1 = { 10.0f, 10.0f, 50.0f, 50.0f };
        Rectangle rec2 = { 40.0f, 40.0f, 50.0f, 50.0f }; // Overlaps rec1
        Rectangle rec3 = { 100.0f, 100.0f, 10.0f, 10.0f }; // Disjoint

        REQUIRE(RaylibStd::check_collision_recs(rec1, rec2) == true);
        REQUIRE(RaylibStd::check_collision_recs(rec1, rec3) == false);
    }

    SECTION("Get Collision Rectangle Intersection") {
        Rectangle rec1 = { 0.0f, 0.0f, 10.0f, 10.0f };
        Rectangle rec2 = { 5.0f, 5.0f, 10.0f, 10.0f };
        
        Rectangle overlap = RaylibStd::get_collision_rec(rec1, rec2);
        
        REQUIRE(overlap.x == 5.0f);
        REQUIRE(overlap.y == 5.0f);
        REQUIRE(overlap.width == 5.0f);
        REQUIRE(overlap.height == 5.0f);
    }

    SECTION("Point to Rectangle Collision") {
        Rectangle rec = { 20.0f, 20.0f, 40.0f, 40.0f };
        Vector2 pointInside = { 30.0f, 30.0f };
        Vector2 pointOutside = { 10.0f, 10.0f };

        REQUIRE(RaylibStd::check_collision_point_rec(pointInside, rec) == true);
        REQUIRE(RaylibStd::check_collision_point_rec(pointOutside, rec) == false);
    }

    SECTION("Circle to Circle Collision") {
        Vector2 center1 = { 0.0f, 0.0f };
        float radius1 = 10.0f;
        
        Vector2 center2 = { 15.0f, 0.0f };
        float radius2 = 10.0f; // Distance is 15, sum of radii is 20 -> overlaps
        
        Vector2 center3 = { 50.0f, 50.0f };
        float radius3 = 5.0f; // Far away

        REQUIRE(RaylibStd::check_collision_circles(center1, radius1, center2, radius2) == true);
        REQUIRE(RaylibStd::check_collision_circles(center1, radius1, center3, radius3) == false);
    }
}