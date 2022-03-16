#include <ios>
#include <iostream>

#include "include/flower_vector.h"
#include "src/flower_vector.cpp"

int main()
{
  Flower_Vector<int> vec1 {1, 2, 3, 4};
  Flower_Vector<std::string> vec2("kek");

  std::cout << vec2 << '\n';
}

