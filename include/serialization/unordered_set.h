#pragma once

#include <unordered_set>

#include "serialization.h"
#include "serialization/detail/containers.h"

namespace serialization {

template <typename Key, typename Hash, typename Pred, typename Allocator>
SerializationStream &operator<<(SerializationStream &ss, const std::unordered_set<Key, Hash, Pred, Allocator> &s) {
    detail::serializeContainer(ss, s);
    return ss;
}

template <typename Key, typename Hash, typename Pred, typename Allocator>
DeserializationStream &operator>>(DeserializationStream &ds, std::unordered_set<Key, Hash, Pred, Allocator> &s) {
    detail::deserializeContainer(ds, s);
    return ds;
}

template <typename Key, typename Hash, typename Pred, typename Allocator>
SerializationStream &operator<<(SerializationStream &ss, const std::unordered_multiset<Key, Hash, Pred, Allocator> &s) {
    detail::serializeContainer(ss, s);
    return ss;
}

template <typename Key, typename Hash, typename Pred, typename Allocator>
DeserializationStream &operator>>(DeserializationStream &ds, std::unordered_multiset<Key, Hash, Pred, Allocator> &s) {
    detail::deserializeContainer(ds, s);
    return ds;
}

} // namespace serialization
