cmake_minimum_required(VERSION 3.4)
project(Object_Pool_Design_Pattern)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)
set(VERSION_TWEAK 0)
set(VERSION${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}.${VERSION_TWEAK})
set(VERSION_STRING "v${VERSION}")

option(BUILD_TESTS "Build tests" OFF)

add_executable(Object_Pool_Design_Pattern main.cpp)

if(BUILD_TESTS)
    enable_testing()

    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
    )
    FetchContent_MakeAvailable(googletest)

    file(GLOB tests "tests/*.cpp")
    foreach(test ${tests})
         add_executable(${test}_test ${test})
         target_link_libraries(${test}_test gtest_main gmock_main)
         add_test(NAME ${test}_test COMMAND ${test}_test)
    endforeach()
endif()

if(EXISTS "${CMAKE_SOURCE_DIR}/CPackConfig.cmake")
    include(CPackConfig.cmake)
endif()
