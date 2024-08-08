#pragma once

#include <utility>

#include "serialization.h"
#include "serialization/fundamental.h" // IWYU pragma: keep

namespace serialization::detail {

template <typename M>
void serializeMap(SerializationStream &ss, const M &m) {
    ss << m.size();
    for (auto &&[key, mapped] : m) {
        ss << key << mapped;
    }
}

template <typename M>
void deserializeMap(DeserializationStream &ds, M &m) {
    M result;
    typename M::size_type size;
    ds >> size;
    while (size--) {
        typename M::key_type key;
        typename M::mapped_type mapped;
        ds >> key >> mapped;
        result.insert(std::pair(std::move(key), std::move(mapped)));
    }
    m = std::move(result);
}

} // namespace serialization::detail
