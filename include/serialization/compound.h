#pragma once

#include <cstddef>

#include "serialization.h"
#include "serialization/detail/arrays.h"

namespace serialization {

template <typename T, size_t N>
SerializationStream &operator<<(SerializationStream &ss, const T (&a)[N]) {
    detail::serializeArray(ss, a, N);
    return ss;
}

template <typename T, size_t N>
DeserializationStream &operator>>(DeserializationStream &ds, T (&a)[N]) {
    detail::deserializeArray(ds, a, N);
    return ds;
}

} // namespace serialization
