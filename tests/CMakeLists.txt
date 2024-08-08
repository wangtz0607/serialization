add_executable(serialization_tests
    ArrayTest.cpp
    ComplexTest.cpp
    CompoundTest.cpp
    DequeTest.cpp
    EnumTest.cpp
    FundamentalTest.cpp
    ListTest.cpp
    MapTest.cpp
    OptionalTest.cpp
    SetTest.cpp
    StringTest.cpp
    TupleTest.cpp
    UnorderedMapTest.cpp
    UnorderedSetTest.cpp
    UtilityTest.cpp
    VariantTest.cpp
    VectorTest.cpp
)
target_compile_features(serialization_tests PRIVATE cxx_std_20)
target_link_libraries(serialization_tests PRIVATE serialization PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(serialization_tests)
