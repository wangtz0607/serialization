#include <set>

#include <gtest/gtest.h>

#include "serialization.h"
#include "serialization/set.h"
#include "serialization/fundamental.h"

using namespace serialization;

TEST(SetTest, set) {
    std::set<int> original{5, 2, 4, 6, 1, 3}, deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.data());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}

TEST(SetTest, multiset) {
    std::multiset<int> original{5, 2, 4, 6, 1, 3, 3}, deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.data());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}
