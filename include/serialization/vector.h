#pragma once

#include <vector>

#include "serialization.h"
#include "serialization/detail/containers.h"

namespace serialization {

template <typename T, typename Allocator>
SerializationStream &operator<<(SerializationStream &ss, const std::vector<T, Allocator> &v) {
    detail::serializeContainer(ss, v);
    return ss;
}

template <typename T, typename Allocator>
DeserializationStream &operator>>(DeserializationStream &ds, std::vector<T, Allocator> &v) {
    detail::deserializeContainer(ds, v);
    return ds;
}

} // namespace serialization
