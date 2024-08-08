#pragma once

#include <unordered_map>

#include "serialization.h"
#include "serialization/detail/maps.h"

namespace serialization {

template <typename Key, typename T, typename Hash, typename Pred, typename Allocator>
SerializationStream &operator<<(SerializationStream &ss, const std::unordered_map<Key, T, Hash, Pred, Allocator> &m) {
    detail::serializeMap(ss, m);
    return ss;
}

template <typename Key, typename T, typename Hash, typename Pred, typename Allocator>
DeserializationStream &operator>>(DeserializationStream &ds, std::unordered_map<Key, T, Hash, Pred, Allocator> &m) {
    detail::deserializeMap(ds, m);
    return ds;
}

template <typename Key, typename T, typename Hash, typename Pred, typename Allocator>
SerializationStream &operator<<(SerializationStream &ss, const std::unordered_multimap<Key, T, Hash, Pred, Allocator> &m) {
    detail::serializeMap(ss, m);
    return ss;
}

template <typename Key, typename T, typename Hash, typename Pred, typename Allocator>
DeserializationStream &operator>>(DeserializationStream &ds, std::unordered_multimap<Key, T, Hash, Pred, Allocator> &m) {
    detail::deserializeMap(ds, m);
    return ds;
}

} // namespace serialization
