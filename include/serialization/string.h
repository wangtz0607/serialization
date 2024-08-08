#pragma once

#include <string>

#include "serialization.h"
#include "serialization/detail/containers.h"

namespace serialization {

template <typename CharT, typename Traits, typename Allocator>
SerializationStream &operator<<(SerializationStream &ss, const std::basic_string<CharT, Traits, Allocator> &s) {
    detail::serializeContainer(ss, s);
    return ss;
}

template <typename CharT, typename Traits, typename Allocator>
DeserializationStream &operator>>(DeserializationStream &ds, std::basic_string<CharT, Traits, Allocator> &s) {
    detail::deserializeContainer(ds, s);
    return ds;
}

} // namespace serialization
