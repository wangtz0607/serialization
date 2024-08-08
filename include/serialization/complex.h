#pragma once

#include <complex>

#include "serialization.h"

namespace serialization {

template <typename T>
SerializationStream &operator<<(SerializationStream &ss, const std::complex<T> &z) {
    return ss << z.real() << z.imag();
}

template <typename T>
DeserializationStream &operator>>(DeserializationStream &ds, std::complex<T> &z) {
    T real, imag;
    ds >> real >> imag;
    z = std::complex(real, imag);
    return ds;
}

} // namespace serialization
