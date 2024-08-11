#include <utility>

#include <gtest/gtest.h>

#include "serialization.h"
#include "serialization/fundamental.h"
#include "serialization/utility.h"

using namespace serialization;

TEST(UtilityTest, pair) {
    std::pair<int, int> original{42, 43}, deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.data());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}
