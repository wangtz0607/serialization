#pragma once

#include <list>

#include "serialization.h"
#include "serialization/detail/containers.h"

namespace serialization {

template <typename T, typename Allocator>
SerializationStream &operator<<(SerializationStream &ss, const std::list<T, Allocator> &l) {
    detail::serializeContainer(ss, l);
    return ss;
}

template <typename T, typename Allocator>
DeserializationStream &operator>>(DeserializationStream &ds, std::list<T, Allocator> &l) {
    detail::deserializeContainer(ds, l);
    return ds;
}

} // namespace serialization
