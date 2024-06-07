cmake_minimum_required(VERSION 3.4)
project(Cpp-Software-Design)
option(BUILD_TESTS "Build tests" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(BUILD_TESTS)
    include_directories(.)
    enable_testing()
    add_subdirectory(third-party/gtest)
    file(GLOB tests "tests/*.cpp")
    foreach(test ${tests})
         get_filename_component(test_name ${test} NAME_WE)
         add_executable(check ${test})
         target_link_libraries(check gtest_main gmock_main)
         add_test(NAME check COMMAND check)
    endforeach(test)
else()
    set(SOURCES
        main.cpp
        EnemyPool.cpp
        Spider.cpp
    )
    add_executable(Cpp-Software-Design ${SOURCES})
endif()
