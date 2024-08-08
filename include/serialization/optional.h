#pragma once

#include <optional>
#include <utility>

#include "serialization.h"
#include "serialization/fundamental.h" // IWYU pragma: keep

namespace serialization {

template <typename T>
SerializationStream &operator<<(SerializationStream &ss, const std::optional<T> &o) {
    ss << o.has_value();
    if (o.has_value()) {
        ss << o.value();
    }
    return ss;
}

template <typename T>
DeserializationStream &operator>>(DeserializationStream &ds, std::optional<T> &o) {
    bool hasValue;
    ds >> hasValue;
    if (hasValue) {
        T value;
        ds >> value;
        o = std::move(value);
    } else {
        o = std::nullopt;
    }
    return ds;
}

inline SerializationStream &operator<<(SerializationStream &ss, const std::nullopt_t &) {
    return ss;
}

inline DeserializationStream &operator>>(DeserializationStream &ds, std::nullopt_t &) {
    return ds;
}

} // namespace serialization
