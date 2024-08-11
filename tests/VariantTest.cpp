#include <exception>
#include <variant>

#include <gtest/gtest.h>

#include "serialization.h"
#include "serialization/fundamental.h"
#include "serialization/variant.h"

using namespace serialization;

TEST(VariantTest, variant_first_alternative) {
    std::variant<int, double> original(42), deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.data());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}

TEST(VariantTest, variant_second_alternative) {
    std::variant<int, double> original(3.14), deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.data());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}

namespace {

class Throwing {
public:
    Throwing() {
        throw std::exception();
    }

    Throwing(const Throwing &) {
        throw std::exception();
    }
};

inline SerializationStream &operator<<(SerializationStream &ss, const Throwing &) {
    return ss;
}

} // namespace

TEST(VariantTest, variant_valueless) {
    std::variant<std::monostate, Throwing> original;

    try {
        original.emplace<Throwing>();
    } catch (const std::exception &) {}

    ASSERT_TRUE(original.valueless_by_exception());

    SerializationStream ss;

    EXPECT_THROW(ss << original, UnserializableException);
}
