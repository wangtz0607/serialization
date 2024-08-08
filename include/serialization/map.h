#pragma once

#include <map>

#include "serialization.h"
#include "serialization/detail/maps.h"

namespace serialization {

template <typename Key, typename T, typename Compare, typename Allocator>
SerializationStream &operator<<(SerializationStream &ss, const std::map<Key, T, Compare, Allocator> &m) {
    detail::serializeMap(ss, m);
    return ss;
}

template <typename Key, typename T, typename Compare, typename Allocator>
DeserializationStream &operator>>(DeserializationStream &ds, std::map<Key, T, Compare, Allocator> &m) {
    detail::deserializeMap(ds, m);
    return ds;
}

template <typename Key, typename T, typename Compare, typename Allocator>
SerializationStream &operator<<(SerializationStream &ss, const std::multimap<Key, T, Compare, Allocator> &m) {
    detail::serializeMap(ss, m);
    return ss;
}

template <typename Key, typename T, typename Compare, typename Allocator>
DeserializationStream &operator>>(DeserializationStream &ds, std::multimap<Key, T, Compare, Allocator> &m) {
    detail::deserializeMap(ds, m);
    return ds;
}

} // namespace serialization
