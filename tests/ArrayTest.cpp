#include <array>

#include <gtest/gtest.h>

#include "serialization.h"
#include "serialization/array.h"
#include "serialization/fundamental.h"

using namespace serialization;

TEST(ArrayTest, array) {
    std::array<int, 6> original{5, 2, 4, 6, 1, 3}, deserialized{};

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.takeData());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}
