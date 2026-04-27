#include <catch2/catch_all.hpp>
#include "raylib-std.hpp"

TEST_CASE("Spline point evaluation", "[math][splines]") {

    SECTION("Linear Spline Point") {
        Vector2 start = { 0.0f, 0.0f };
        Vector2 end = { 10.0f, 10.0f };

        // Evaluate exactly halfway (t = 0.5)
        Vector2 mid = RaylibStd::get_spline_point_linear(start, end, 0.5f);

        REQUIRE_THAT(mid.x, Catch::Matchers::WithinAbs(5.0f, 0.001f));
        REQUIRE_THAT(mid.y, Catch::Matchers::WithinAbs(5.0f, 0.001f));
    }

    SECTION("Quadratic Bezier Curve Point") {
        Vector2 p1 = { 0.0f, 0.0f };      // Start
        Vector2 c2 = { 5.0f, 10.0f };     // Control point pulling the curve up
        Vector2 p3 = { 10.0f, 0.0f };     // End

        // Evaluate halfway (t = 0.5)
        Vector2 mid = RaylibStd::get_spline_point_bezier_quad(p1, c2, p3, 0.5f);

        // Based on Bezier math: (1-t)^2*P0 + 2(1-t)t*P1 + t^2*P2
        REQUIRE_THAT(mid.x, Catch::Matchers::WithinAbs(5.0f, 0.001f));
        REQUIRE_THAT(mid.y, Catch::Matchers::WithinAbs(5.0f, 0.001f));
    }
}