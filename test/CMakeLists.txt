cmake_minimum_required(VERSION 3.1)

set(This Tests)

set (Sources Vector_Test.cpp)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
  gtest_main
  main
)

add_test(
  NAME ${This}
  COMMAND ${This}
)
