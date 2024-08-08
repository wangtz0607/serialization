#pragma once

#include <utility>

#include "serialization.h"
#include "serialization/fundamental.h" // IWYU pragma: keep

namespace serialization::detail {

template <typename C>
void serializeContainer(SerializationStream &ss, const C &c) {
    ss << c.size();
    for (auto &&value : c) {
        ss << value;
    }
}

template <typename C>
void deserializeContainer(DeserializationStream &ds, C &c) {
    C result;
    typename C::size_type size;
    ds >> size;
    while (size--) {
        typename C::value_type value;
        ds >> value;
        result.insert(result.end(), std::move(value));
    }
    c = std::move(result);
}

} // namespace serialization::detail
