#include <catch2/catch_all.hpp>
#include "raylib-std.hpp"

TEST_CASE("Random generation utilities", "[random]") {

    SECTION("GetRandomValue stays within bounds") {
        // Set a seed for predictable, deterministic tests
        RaylibStd::set_random_seed(12345);

        for (int i = 0; i < 50; i++) {
            int val = RaylibStd::get_random_value(5, 10);
            REQUIRE(val >= 5);
            REQUIRE(val <= 10);
        }
    }

    SECTION("LoadRandomSequence generates unique values within range") {
        const unsigned int count = 10;
        const int minLimit = 1;
        const int maxLimit = 20;

        // Load a sequence of non-repeating random numbers
        int* sequence = RaylibStd::load_random_sequence(count, minLimit, maxLimit);
        REQUIRE(sequence != nullptr);

        // Verify boundaries and uniqueness
        for (unsigned int i = 0; i < count; i++) {
            REQUIRE(sequence[i] >= minLimit);
            REQUIRE(sequence[i] <= maxLimit);

            // Check against previous numbers to ensure no duplicates
            for (unsigned int j = 0; j < i; j++) {
                REQUIRE(sequence[i] != sequence[j]);
            }
        }

        // Clean up
        RaylibStd::unload_random_sequence(sequence);
    }
}