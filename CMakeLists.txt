cmake_minimum_required(VERSION 3.10)
project(ConceptualExample)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=maybe-uninitialized")

add_executable(ConceptualExample Program.cpp ConceptualExample.cpp)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

add_executable(runTests tests.cpp)

target_link_libraries(runTests gtest_main)

include(GoogleTest)
gtest_discover_tests(runTests)

set(EXECUTABLE_ARTIFACT "${CMAKE_BINARY_DIR}/ConceptualExample")

add_custom_command(
    TARGET ConceptualExample
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:ConceptualExample>
    ${EXECUTABLE_ARTIFACT}
    COMMENT "Copying executable to artifacts directory"
)
