#include <list>

#include <gtest/gtest.h>

#include "serialization.h"
#include "serialization/list.h"
#include "serialization/fundamental.h"

using namespace serialization;

TEST(ListTest, list) {
    std::list<int> original{5, 2, 4, 6, 1, 3}, deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.data());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}
