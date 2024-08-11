#include <vector>

#include <gtest/gtest.h>

#include "serialization.h"
#include "serialization/vector.h"
#include "serialization/fundamental.h"

using namespace serialization;

TEST(VectorTest, vector) {
    std::vector<int> original{5, 2, 4, 6, 1, 3}, deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.takeData());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}
