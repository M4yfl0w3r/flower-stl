cmake_minimum_required(VERSION 3.13)

project(flower-stl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")

include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0)
FetchContent_GetProperties(googletest)

if (NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

add_library(flower_stl STATIC src/flower_vector.cpp src/flower_stack.cpp src/flower_heap.cpp)

add_executable(Tests tst/Vector_Test.cpp tst/Stack_Test.cpp tst/Heap_Test.cpp)
target_link_libraries(Tests flower_stl gtest_main gmock_main)

add_executable(vector_tst tst/Vector_Test.cpp)
add_executable(heap_tst tst/Heap_Test.cpp)
add_executable(stack_tst tst/Stack_Test.cpp)

target_link_libraries(vector_tst flower_stl gtest_main gmock_main)
target_link_libraries(heap_tst flower_stl gtest_main gmock_main)
target_link_libraries(stack_tst flower_stl gtest_main gmock_main)

