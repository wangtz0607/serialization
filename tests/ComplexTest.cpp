#include <complex>

#include <gtest/gtest.h>

#include "serialization.h"
#include "serialization/complex.h"
#include "serialization/fundamental.h"

using namespace serialization;

TEST(ComplexTest, complex) {
    std::complex<double> original(3.14, 2.72), deserialized;

    SerializationStream ss;
    ss << original;

    DeserializationStream ds(ss.vector());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}
