#pragma once

#include <utility>
#include <variant>

#include "serialization.h"
#include "serialization/fundamental.h"

namespace serialization {

namespace detail {

template <size_t I, typename V>
void deserializeVariant(DeserializationStream &, size_t i, V &) {}

template <size_t I, typename V>
    requires (I < std::variant_size_v<V>)
void deserializeVariant(DeserializationStream &ds, size_t i, V &v) {
    if (I == i) {
        std::variant_alternative_t<I, V> value;
        ds >> value;
        v = std::move(value);
    } else {
        deserializeVariant<I + 1>(ds, i, v);
    }
}

} // namespace detail

template <typename... Types>
SerializationStream &operator<<(SerializationStream &ss, const std::variant<Types...> &v) {
    if (v.valueless_by_exception()) {
        throw UnserializableException();
    }
    ss << v.index();
    std::visit([&ss](auto &&value) { ss << value; }, v);
    return ss;
}

template <typename... Types>
DeserializationStream &operator>>(DeserializationStream &ds, std::variant<Types...> &v) {
    size_t i;
    ds >> i;
    detail::deserializeVariant<0>(ds, i, v);
    return ds;
}

inline SerializationStream &operator<<(SerializationStream &ss, const std::monostate &) {
    return ss;
}

inline DeserializationStream &operator>>(DeserializationStream &ds, std::monostate &) {
    return ds;
}

} // namespace serialization
