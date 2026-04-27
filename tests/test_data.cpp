#include <catch2/catch_all.hpp>
#include "raylib-std.hpp"
#include <cstring>

TEST_CASE("Data encoding and hashing", "[data]") {

    SECTION("Base64 Encoding and Decoding") {
        const char* originalText = "Raylib-Std Framework";
        int dataSize = static_cast<int>(std::strlen(originalText));

        // Encode
        int encodedSize = 0;
        char* encoded = RaylibStd::EncodeDataBase64(
            reinterpret_cast<const unsigned char*>(originalText),
            dataSize,
            &encodedSize
        );

        REQUIRE(encoded != nullptr);
        REQUIRE(encodedSize > 0);

        // Decode
        int decodedSize = 0;
        unsigned char* decoded = RaylibStd::DecodeDataBase64(encoded, &decodedSize);

        REQUIRE(decoded != nullptr);
        REQUIRE(decodedSize == dataSize);

        // Verify the content is perfectly restored
        REQUIRE(std::memcmp(originalText, decoded, dataSize) == 0);

        // Clean up raylib-allocated memory
        RaylibStd::MemFree(encoded);
        RaylibStd::MemFree(decoded);
    }

    SECTION("CRC32 Hashing consistency") {
        unsigned char data[] = "test";
        // Raylib/Zlib standard CRC32 for "test" should reliably be 0xD87F7E0C
        unsigned int hash = RaylibStd::ComputeCRC32(data, 4);

        REQUIRE(hash == 0xD87F7E0C);
    }
}