#pragma once

#include <set>

#include "serialization.h"
#include "serialization/detail/containers.h"

namespace serialization {

template <typename Key, typename Compare, typename Allocator>
SerializationStream &operator<<(SerializationStream &ss, const std::set<Key, Compare, Allocator> &s) {
    detail::serializeContainer(ss, s);
    return ss;
}

template <typename Key, typename Compare, typename Allocator>
DeserializationStream &operator>>(DeserializationStream &ds, std::set<Key, Compare, Allocator> &s) {
    detail::deserializeContainer(ds, s);
    return ds;
}

template <typename Key, typename Compare, typename Allocator>
SerializationStream &operator<<(SerializationStream &ss, const std::multiset<Key, Compare, Allocator> &s) {
    detail::serializeContainer(ss, s);
    return ss;
}

template <typename Key, typename Compare, typename Allocator>
DeserializationStream &operator>>(DeserializationStream &ds, std::multiset<Key, Compare, Allocator> &s) {
    detail::deserializeContainer(ds, s);
    return ds;
}

} // namespace serialization
