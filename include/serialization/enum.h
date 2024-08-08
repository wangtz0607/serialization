#pragma once

#include <type_traits>

#include "serialization.h"
#include "serialization/fundamental.h" // IWYU pragma: keep

namespace serialization {

template <typename E>
    requires std::is_enum_v<E>
SerializationStream &operator<<(SerializationStream &ss, E e) {
    return ss << static_cast<std::underlying_type_t<E>>(e);
}

template <typename E>
    requires std::is_enum_v<E>
DeserializationStream &operator>>(DeserializationStream &ds, E &e) {
    std::underlying_type_t<E> underlying;
    ds >> underlying;
    e = static_cast<E>(underlying);
    return ds;
}

} // namespace serialization
