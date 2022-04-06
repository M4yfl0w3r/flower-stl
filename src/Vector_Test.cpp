#include <gtest/gtest.h>

#include "../include/flower_vector.h"
#include "flower_vector.cpp"
  
TEST(constructor_test, is_vector_empty_at_init)
{
  Flower_Vector<int> vec;

  EXPECT_EQ(0, vec.flower_size());
  EXPECT_EQ(2, vec.flower_capacity());

  vec.flower_push_back(12);

  EXPECT_EQ(1, vec.flower_size());
  EXPECT_EQ(2, vec.flower_capacity());
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
