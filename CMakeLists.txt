cmake_minimum_required(VERSION 3.5.0)

project(serialization VERSION 0.1.0 LANGUAGES CXX)

option(SERIALIZATION_TESTS "Build tests." OFF)

add_library(serialization INTERFACE)
target_compile_features(serialization INTERFACE cxx_std_20)
target_include_directories(serialization INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)
add_library(serialization::serialization ALIAS serialization)

install(TARGETS serialization EXPORT serializationTargets)
install(DIRECTORY include/ DESTINATION include)
install(EXPORT serializationTargets
        FILE serializationTargets.cmake
        NAMESPACE serialization::
        DESTINATION lib/cmake/serialization)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/serializationConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/serializationConfig.cmake"
    INSTALL_DESTINATION lib/cmake/serialization
)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/serializationConfigVersion.cmake"
    VERSION "${PROJECT_VERSION}"
    COMPATIBILITY AnyNewerVersion
)
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/serializationConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/serializationConfigVersion.cmake"
    DESTINATION lib/cmake/serialization
)

export(EXPORT serializationTargets
       FILE "${CMAKE_CURRENT_BINARY_DIR}/serializationTargets.cmake"
       NAMESPACE serialization::)

if(SERIALIZATION_TESTS)
    add_subdirectory(third_party/googletest EXCLUDE_FROM_ALL SYSTEM)
    enable_testing()
    add_subdirectory(tests)
endif()
