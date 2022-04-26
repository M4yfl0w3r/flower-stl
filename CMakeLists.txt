cmake_minimum_required(VERSION 3.22.3)

set(This main)

project (${This} CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")
set(PROJECT_LINK_DIRECTORY ${PROJECT_SOURCE_DIR})

add_compile_options(${CMAKE_CXX_FLAGS})

enable_testing()

add_subdirectory(/usr/src/googletest build)

set (Headers 
  include/flower_vector.h
  include/flower_stack.h
  include/flower_heap.h
)
set (Sources 
  src/flower_vector.cpp
  src/flower_stack.cpp
  src/flower_heap.cpp
)

add_library(${PROJECT_NAME} STATIC ${Sources} ${Headers})

add_subdirectory(test)


