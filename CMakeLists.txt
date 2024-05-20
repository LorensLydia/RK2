cmake_minimum_required(VERSION 3.4)
project(Object_Pool_Design_Pattern)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)
set(VERSION_TWEAK 0)
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}.${VERSION_TWEAK}")
set(VERSION_STRING "v${VERSION}")

option(BUILD_TESTS "Build tests" OFF)

add_executable(Object_Pool_Design_Pattern main.cpp)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(third-party/gtest)

    file(GLOB test_sources "tests/*.cpp")
    add_executable(tests ${test_sources})
    target_link_libraries(tests gtest_main gmock_main)

    add_test(NAME SpiderTest_Initialization COMMAND tests --gtest_filter=SpiderTest.Initialization)
    add_test(NAME SpiderTest_Attack COMMAND tests --gtest_filter=SpiderTest.Attack)
    add_test(NAME SpiderTest_GetDamage COMMAND tests --gtest_filter=SpiderTest.GetDamage)
endif()

include(CPackConfig.cmake)
