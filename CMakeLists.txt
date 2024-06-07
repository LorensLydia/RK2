cmake_minimum_required(VERSION 3.10)

project(SOLID)

# Добавляем основные файлы проекта
add_library(SOLIDLib SHARED
    Spider.cpp
    EnemyPool.cpp
    Spider.h
    EnemyPool.h
    )


add_executable(SOLIDProject
    Program.cpp
)

target_link_libraries(Object Pool Design PatternProject PRIVATE Object Pool Design PatternLib)

# Добавляем Google Test с использованием FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Добавляем тестируемый исполняемый файл
add_executable(Object Pool Design PatternTests
    tests/dip_test.cpp
)

# Линкуем библиотеки Google Test
target_link_libraries(Object Pool Design PatternTests
    PRIVATE
    SOLIDLib
    gtest
    gtest_main
)

enable_testing()
add_test(NAME Object Pool Design PatternTests COMMAND Object Pool Design PatternTests)
