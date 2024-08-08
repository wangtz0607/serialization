#include <unordered_set>

#include <gtest/gtest.h>

#include "serialization.h"
#include "serialization/fundamental.h"
#include "serialization/unordered_set.h"

using namespace serialization;

TEST(UnorderedSetTest, unordered_set) {
    std::unordered_set<int> original{5, 2, 4, 6, 1, 3}, deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.vector());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}

TEST(UnorderedSetTest, unordered_multiset) {
    std::unordered_multiset<int> original{5, 2, 4, 6, 1, 3, 3}, deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.vector());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}
