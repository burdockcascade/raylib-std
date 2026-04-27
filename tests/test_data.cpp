#include <catch2/catch_all.hpp>
#include "raylib-std.hpp"
#include <cstring>

TEST_CASE("Data encoding and hashing", "[data]") {

    SECTION("Base64 Encoding and Decoding") {
        const char* originalText = "Raylib-Std Framework";
        int dataSize = static_cast<int>(std::strlen(originalText));

        // Encode
        int encodedSize = 0;
        std::string encoded = RaylibStd::encode_data_base_64(
            reinterpret_cast<const unsigned char*>(originalText),
            dataSize,
            &encodedSize
        );

        REQUIRE(encoded.length() == encodedSize - 1);
        REQUIRE(encoded != originalText);

        // Decode
        int decodedSize = 0;
        unsigned char* decoded = RaylibStd::decode_data_base_64(encoded, &decodedSize);

        REQUIRE(decoded != nullptr);
        REQUIRE(decodedSize == dataSize);

        // Verify the content is perfectly restored
        REQUIRE(std::memcmp(originalText, decoded, dataSize) == 0);

    }

    SECTION("CRC32 Hashing consistency") {
        unsigned char data[] = "test";
        // Raylib/Zlib standard CRC32 for "test" should reliably be 0xD87F7E0C
        unsigned int hash = RaylibStd::compute_crc_32(data, 4);

        REQUIRE(hash == 0xD87F7E0C);
    }
}