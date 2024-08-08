#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>
#include <concepts>

#include "serialization.h"

namespace serialization {

namespace detail {

template <typename T>
    requires std::integral<T>
T byteswap(T value) {
    T result = 0;
    for (size_t i = 0; i < sizeof(T); ++i) {
        result <<= 8;
        result |= value & 0xff;
        value >>= 8;
    }
    return result;
}

} // namespace detail

template <typename T>
    requires std::integral<T>
SerializationStream &operator<<(SerializationStream &ss, T value) {
    if constexpr (std::endian::native == std::endian::big) {
        value = detail::byteswap(value);
    }
    ss.write(reinterpret_cast<const std::byte *>(&value), sizeof(value));
    return ss;
}

template <typename T>
    requires std::integral<T>
DeserializationStream &operator>>(DeserializationStream &ds, T &value) {
    ds.read(reinterpret_cast<std::byte *>(&value), sizeof(value));
    if constexpr (std::endian::native == std::endian::big) {
        value = detail::byteswap(value);
    }
    return ds;
}

inline SerializationStream &operator<<(SerializationStream &ss, float value) {
    return ss << std::bit_cast<uint32_t>(value);
}

inline DeserializationStream &operator>>(DeserializationStream &ds, float &value) {
    uint32_t result;
    ds >> result;
    value = std::bit_cast<float>(result);
    return ds;
}

inline SerializationStream &operator<<(SerializationStream &ss, double value) {
    return ss << std::bit_cast<uint64_t>(value);
}

inline DeserializationStream &operator>>(DeserializationStream &ds, double &value) {
    uint64_t result;
    ds >> result;
    value = std::bit_cast<double>(result);
    return ds;
}

} // namespace serialization
