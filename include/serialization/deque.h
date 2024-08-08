#pragma once

#include <deque>

#include "serialization.h"
#include "serialization/detail/containers.h"

namespace serialization {

template <typename T, typename Allocator>
SerializationStream &operator<<(SerializationStream &ss, const std::deque<T, Allocator> &d) {
    detail::serializeContainer(ss, d);
    return ss;
}

template <typename T, typename Allocator>
DeserializationStream &operator>>(DeserializationStream &ds, std::deque<T, Allocator> &d) {
    detail::deserializeContainer(ds, d);
    return ds;
}

} // namespace serialization
