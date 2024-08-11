#include <optional>

#include <gtest/gtest.h>

#include "serialization.h"
#include "serialization/fundamental.h"
#include "serialization/optional.h"

using namespace serialization;

TEST(OptionalTest, optional_engaged) {
    std::optional<int> original(42), deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.data());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}

TEST(OptionalTest, optional_disengaged) {
    std::optional<int> original, deserialized(42);

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.data());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}
