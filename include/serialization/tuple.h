#pragma once

#include <tuple>

#include "serialization.h"

namespace serialization {

namespace detail {

template <size_t I, typename T>
void serializeTuple(SerializationStream &, const T &) {}

template <size_t I, typename T>
    requires (I < std::tuple_size_v<T>)
void serializeTuple(SerializationStream &ss, const T &t) {
    ss << std::get<I>(t);
    serializeTuple<I + 1>(ss, t);
}

template <size_t I, typename T>
void deserializeTuple(DeserializationStream &, T &) {}

template <size_t I, typename T>
    requires (I < std::tuple_size_v<T>)
void deserializeTuple(DeserializationStream &ds, T &t) {
    ds >> std::get<I>(t);
    deserializeTuple<I + 1>(ds, t);
}

} // namespace detail

template <typename... Types>
SerializationStream &operator<<(SerializationStream &ss, const std::tuple<Types...> &t) {
    detail::serializeTuple<0>(ss, t);
    return ss;
}

template <typename... Types>
DeserializationStream &operator>>(DeserializationStream &ds, std::tuple<Types...> &t) {
    detail::deserializeTuple<0>(ds, t);
    return ds;
}

} // namespace serialization
