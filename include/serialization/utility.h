#pragma once

#include <utility>

#include "serialization.h"

namespace serialization {

template <typename T1, typename T2>
SerializationStream &operator<<(SerializationStream &ss, const std::pair<T1, T2> &p) {
    return ss << p.first << p.second;
}

template <typename T1, typename T2>
DeserializationStream &operator>>(DeserializationStream &ds, std::pair<T1, T2> &p) {
    return ds >> p.first >> p.second;
}

} // namespace serialization
