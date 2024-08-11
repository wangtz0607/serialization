#include <bit>
#include <cstdint>
#include <limits>

#include <gtest/gtest.h>

#include "serialization.h"
#include "serialization/fundamental.h"

using namespace serialization;

namespace {

template <typename T>
void test(T original) {
    SerializationStream ss;
    ss << original;

    T deserialized;

    DeserializationStream ds(ss.data());
    ds >> deserialized;

    EXPECT_EQ(deserialized, original);
}

template <typename T, typename Integer>
void testFloating(T original) {
    SerializationStream ss;
    ss << original;

    T deserialized;

    DeserializationStream ds(ss.data());
    ds >> deserialized;

    EXPECT_EQ(std::bit_cast<Integer>(deserialized), std::bit_cast<Integer>(original));
}

} // namespace

TEST(FundamentalTest, bool) {
    test<bool>(true);
    test<bool>(false);
}

TEST(FundamentalTest, char) {
    test<char>(0);
    test<char>('x');
}

TEST(FundamentalTest, signed_char) {
    test<signed char>(0);
    test<signed char>(std::numeric_limits<signed char>::min());
    test<signed char>(std::numeric_limits<signed char>::max());
}

TEST(FundamentalTest, short) {
    test<short>(0);
    test<short>(std::numeric_limits<short>::min());
    test<short>(std::numeric_limits<short>::max());
}

TEST(FundamentalTest, int) {
    test<int>(0);
    test<int>(std::numeric_limits<int>::min());
    test<int>(std::numeric_limits<int>::max());
}

TEST(FundamentalTest, long) {
    test<long>(0);
    test<long>(std::numeric_limits<long>::min());
    test<long>(std::numeric_limits<long>::max());
}

TEST(FundamentalTest, long_long) {
    test<long long>(0);
    test<long long>(std::numeric_limits<long long>::min());
    test<long long>(std::numeric_limits<long long>::max());
}

TEST(FundamentalTest, unsigned_char) {
    test<unsigned char>(0);
    test<unsigned char>(std::numeric_limits<unsigned char>::max());
}

TEST(FundamentalTest, unsigned_short) {
    test<unsigned short>(0);
    test<unsigned short>(std::numeric_limits<unsigned short>::max());
}

TEST(FundamentalTest, unsigned_int) {
    test<unsigned int>(0);
    test<unsigned int>(std::numeric_limits<unsigned int>::max());
}

TEST(FundamentalTest, unsigned_long) {
    test<unsigned long>(0);
    test<unsigned long>(std::numeric_limits<unsigned long>::max());
}

TEST(FundamentalTest, unsigned_long_long) {
    test<unsigned long long>(0);
    test<unsigned long long>(std::numeric_limits<unsigned long long>::max());
}

TEST(FundamentalTest, char8_t) {
    test<char8_t>(0);
    test<char8_t>(std::numeric_limits<char8_t>::max());
}

TEST(FundamentalTest, char16_t) {
    test<char16_t>(0);
    test<char16_t>(std::numeric_limits<char16_t>::max());
}

TEST(FundamentalTest, char32_t) {
    test<char32_t>(0);
    test<char32_t>(std::numeric_limits<char32_t>::max());
}

TEST(FundamentalTest, float) {
    testFloating<float, uint32_t>(std::bit_cast<float>((uint32_t)0x4048f5c3)); // 3.14
    testFloating<float, uint32_t>(std::bit_cast<float>((uint32_t)0x00000000)); // 0.0
    testFloating<float, uint32_t>(std::bit_cast<float>((uint32_t)0x80000000)); // -0.0
    testFloating<float, uint32_t>(std::bit_cast<float>((uint32_t)0x7f800000)); // inf
    testFloating<float, uint32_t>(std::bit_cast<float>((uint32_t)0xff800000)); // -inf
    testFloating<float, uint32_t>(std::bit_cast<float>((uint32_t)0x7fffffff)); // nan
    testFloating<float, uint32_t>(std::bit_cast<float>((uint32_t)0xffffffff)); // nan
}

TEST(FundamentalTest, double) {
    testFloating<double, uint64_t>(std::bit_cast<double>((uint64_t)0x40091eb851eb851f)); // 3.14
    testFloating<double, uint64_t>(std::bit_cast<double>((uint64_t)0x8000000000000000)); // -0.0
    testFloating<double, uint64_t>(std::bit_cast<double>((uint64_t)0x7ff0000000000000)); // inf
    testFloating<double, uint64_t>(std::bit_cast<double>((uint64_t)0xfff0000000000000)); // -inf
    testFloating<double, uint64_t>(std::bit_cast<double>((uint64_t)0x7fffffffffffffff)); // nan
    testFloating<double, uint64_t>(std::bit_cast<double>((uint64_t)0xffffffffffffffff)); // nan
}
