cmake_minimum_required(VERSION 3.1)

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
  flower_vector.h
)

set (Sources 
  flower_vector.cpp
  main.cpp
)

add_library(${PROJECT_NAME} STATIC ${Sources} ${Headers})

add_subdirectory(test)


