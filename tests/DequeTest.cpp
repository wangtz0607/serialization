#include <deque>

#include <gtest/gtest.h>

#include "serialization.h"
#include "serialization/deque.h"
#include "serialization/fundamental.h"

using namespace serialization;

TEST(DequeTest, deque) {
    std::deque<int> original{5, 2, 4, 6, 1, 3}, deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.data());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}
