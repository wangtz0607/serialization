# Serialization

C++20 header-only serialization library.

## Examples

```cpp
#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

#include "serialization.h"
#include "serialization/fundamental.h"
#include "serialization/string.h"
#include "serialization/unordered_map.h"

using namespace serialization;

int main() {
    std::unordered_map<std::string, int> original{
        {"one", 1},
        {"two", 2},
        {"three", 3},
    };

    SerializationStream ss;
    ss << original;

    std::unordered_map<std::string, int> deserialized;

    DeserializationStream ds(ss.vector());
    ds >> deserialized;

    assert(deserialized == original);
    return 0;
}
```

```cpp
#include <cassert>
#include <string>

#include "serialization.h"
#include "serialization/fundamental.h"
#include "serialization/string.h"

using namespace serialization;

struct Person {
    std::string name;
    int age;
};

bool operator==(const Person &lhs, const Person &rhs) {
    return lhs.name == rhs.name && lhs.age == rhs.age;
}

SerializationStream &operator<<(SerializationStream &ss, const Person &person) {
    return ss << person.name << person.age;
}

DeserializationStream &operator>>(DeserializationStream &ds, Person &person) {
    return ds >> person.name >> person.age;
}

int main() {
    Person original{"Alice", 18};

    SerializationStream ss;
    ss << original;

    Person deserialized;

    DeserializationStream ds(ss.vector());
    ds >> deserialized;

    assert(deserialized == original);
    return 0;
}
```

## API

### `serialization.h`

Definition of `SerializationStream`, `DeserializationStream`, and related exceptions.

### `serialization/fundamental.h`

Serialization and deserialization support for integral and floating-point types.

### `serialization/compound.h`

Serialization and deserialization support for C-style arrays.

### `serialization/*.h`

Serialization and deserialization support for STL types.

| STL Types | Header |
| - | - |
| `std::array` | `serialization/array.h` |
| `std::basic_string` | `serialization/string.h` |
| `std::vector` | `serialization/vector.h` |
| `std::deque` | `serialization/deque.h` |
| `std::list` | `serialization/list.h` |
| `std::set`, `std::multiset` | `serialization/set.h` |
| `std::map`, `std::multimap` | `serialization/map.h` |
| `std::unordered_set`, `std::unordered_multiset` | `serialization/unordered_set.h` |
| `std::unordered_map`, `std::unordered_multimap` | `serialization/unordered_map.h` |
| `std::pair` | `serialization/utility.h` |
| `std::tuple` | `serialization/tuple.h` |
| `std::complex` | `serialization/complex.h` |
| `std::optional` | `serialization/optional.h` |
| `std::variant` | `serialization/variant.h` |

## Integration

Simply add `include` to the compiler's include path.

Alternatively, use CMake:

```cmake
find_package(serialization CONFIG REQUIRED)
target_link_libraries(your_target PRIVATE serialization::serialization)
```

## License

Serialization is licensed under the [MIT license](https://opensource.org/license/MIT).
