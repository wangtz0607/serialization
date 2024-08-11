#include <map>

#include <gtest/gtest.h>

#include "serialization.h"
#include "serialization/map.h"
#include "serialization/fundamental.h"

using namespace serialization;

TEST(MapTest, map) {
    std::map<int, int> original{{1, 2}, {3, 4}}, deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.takeData());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}

TEST(MapTest, multimap) {
    std::multimap<int, int> original{{1, 2}, {3, 4}, {3, 5}}, deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.takeData());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}
