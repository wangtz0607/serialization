#pragma once

#include <cstddef>
#include <exception>
#include <span>
#include <utility>
#include <vector>

namespace serialization {

class UnserializableException : public std::exception {
public:
    const char *what() const noexcept override {
        return "serialization::UnserializableException";
    }
};

class EOFException : public std::exception {
public:
    const char *what() const noexcept override {
        return "serialization::EOFException";
    }
};

class SerializationStream {
public:
    SerializationStream &write(const std::byte *src, size_t size) {
        buf_.insert(buf_.end(), src, src + size);
        return *this;
    }

    const std::vector<std::byte> &data() const {
        return buf_;
    }

    std::vector<std::byte> takeData() {
        return std::move(buf_);
    }

private:
    std::vector<std::byte> buf_;
};

class DeserializationStream {
public:
    explicit DeserializationStream(std::span<const std::byte> buf) : buf_(buf) {
        cur_ = buf_.data();
    }

    DeserializationStream &read(std::byte *dst, size_t size) {
        if (cur_ + size > buf_.data() + buf_.size()) {
            throw EOFException();
        }
        for (size_t i = 0; i < size; ++i) {
            *dst++ = *cur_++;
        }
        return *this;
    }

private:
    std::span<const std::byte> buf_;
    const std::byte *cur_;
};

template <typename T>
std::vector<std::byte> serialize(const T &value) {
    SerializationStream ss;
    ss << value;
    return ss.takeData();
}

template <typename T>
T deserialize(std::span<const std::byte> buf) {
    DeserializationStream ds(buf);
    T value;
    ds >> value;
    return value;
}

} // namespace serialization
