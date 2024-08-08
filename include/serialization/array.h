#pragma once

#include <array>

#include "serialization.h"
#include "serialization/detail/arrays.h"

namespace serialization {

template <typename T, size_t N>
SerializationStream &operator<<(SerializationStream &ss, const std::array<T, N> &a) {
    detail::serializeArray(ss, a.data(), a.size());
    return ss;
}

template <typename T, size_t N>
DeserializationStream &operator>>(DeserializationStream &ds, std::array<T, N> &a) {
    detail::deserializeArray(ds, a.data(), a.size());
    return ds;
}

} // namespace serialization
