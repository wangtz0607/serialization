#include <unordered_map>

#include <gtest/gtest.h>

#include "serialization.h"
#include "serialization/fundamental.h"
#include "serialization/unordered_map.h"

using namespace serialization;

TEST(UnorderedMapTest, unordered_map) {
    std::unordered_map<int, int> original{{1, 2}, {3, 4}}, deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.vector());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}

TEST(UnorderedMapTest, unordered_multimap) {
    std::unordered_multimap<int, int> original{{1, 2}, {3, 4}, {3, 5}}, deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.vector());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}
