#include <algorithm>

#include <gtest/gtest.h>

#include "serialization.h"
#include "serialization/compound.h"
#include "serialization/fundamental.h"

using namespace serialization;

TEST(CompoundTest, array) {
    int original[6] = {5, 2, 4, 6, 1, 3}, deserialized[6] = {};

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.data());
    ds >> deserialized;

    EXPECT_TRUE(std::equal(deserialized, deserialized + 6, original));
}
