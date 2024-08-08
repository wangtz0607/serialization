#include <gtest/gtest.h>

#include "serialization.h"
#include "serialization/enum.h"

using namespace serialization;

namespace {

enum class ScopedColor {
    kRed,
    kGreen,
    kBlue,
};

enum UnscopedColor {
    Color_Red,
    Color_Green,
    Color_Blue,
};

} // namespace

TEST(EnumTest, enum_scoped) {
    ScopedColor original = ScopedColor::kGreen, deserialized = ScopedColor::kRed;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.vector());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}

TEST(EnumTest, enum_unscoped) {
    UnscopedColor original = Color_Green, deserialized = Color_Red;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.vector());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}
