#include <string>

#include <gtest/gtest.h>

#include "serialization.h"
#include "serialization/string.h"

using namespace serialization;

TEST(StringTest, string) {
    std::string original = "Hello, world!", deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.data());
    ds >> deserialized;

    EXPECT_EQ(original, deserialized);
}

TEST(StringTest, wstring) {
    std::wstring original = L"Hello, world!", deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.data());
    ds >> deserialized;

    EXPECT_EQ(original, deserialized);
}

TEST(StringTest, u8string) {
    std::u8string original = u8"Hello, world!", deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.data());
    ds >> deserialized;

    EXPECT_TRUE(original == deserialized); // workaround
}

TEST(StringTest, u16string) {
    std::u16string original = u"Hello, world!", deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.data());
    ds >> deserialized;

    EXPECT_EQ(original, deserialized);
}

TEST(StringTest, u32string) {
    std::u32string original = U"Hello, world!", deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.data());
    ds >> deserialized;

    EXPECT_EQ(original, deserialized);
}
