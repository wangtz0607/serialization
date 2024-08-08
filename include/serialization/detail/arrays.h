#pragma once

#include <utility>

#include "serialization.h"

namespace serialization::detail {

template <typename T>
void serializeArray(SerializationStream &ss, const T *data, size_t size) {
    for (const T *p = data; p < data + size; ++p) {
        ss << *p;
    }
}

template <typename T>
void deserializeArray(DeserializationStream &ds, T *data, size_t size) {
    for (T *p = data; p < data + size; ++p) {
        T value;
        ds >> value;
        *p = std::move(value);
    }
}

} // namespace serialization::detail
