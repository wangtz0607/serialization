#include <tuple>

#include <gtest/gtest.h>

#include "serialization.h"
#include "serialization/fundamental.h"
#include "serialization/tuple.h"

using namespace serialization;

TEST(TupleTest, tuple) {
    std::tuple<int, int, int> original{42, 43, 44}, deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.vector());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}
