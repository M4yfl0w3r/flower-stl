#include <gtest/gtest.h>

#include "../include/flower_vector.h"
#include "flower_vector.cpp"
  
TEST(Constructor_Test, is_vector_empty_at_init)
{
  Flower_Vector<int> vec;

  EXPECT_EQ(0, vec.flower_size());
  EXPECT_EQ(2, vec.flower_capacity());
}

TEST(Constructor_Test, is_one_argument_constructor_working)
{
  Flower_Vector<int> vec(1);

  EXPECT_EQ(1, vec.flower_size());
  EXPECT_EQ(2, vec.flower_capacity());
}

TEST(Constructor_Test, is_init_list_constructor_working)
{
  Flower_Vector<int> vec {1, 2, 3, 4};

  EXPECT_EQ(4, vec.flower_size());

  /* capacity + capacity if there is not enough space */
  EXPECT_EQ(4, vec.flower_capacity());
}

/*
TEST(Constructor_Test, is_move_constructor_working)
{
  Flower_Vector<int> vec {1, 2, 3, 4};

  Flower_Vector<int> vec_to_test = std::move(vec);

  EXPECT_EQ(4, vec_to_test.flower_size());
  EXPECT_EQ(4, vec_to_test.flower_capacity());
}

TEST(Constructor_Test, is_copy_constructor_working)
{
  Flower_Vector<int> vec {1, 2, 3, 4};

  Flower_Vector<int> vec_to_test = vec;

  EXPECT_EQ(4, vec_to_test.flower_size());
  EXPECT_EQ(4, vec_to_test.flower_capacity());
}
*/

TEST(Add_Element_Test, is_single_element_push_back_working)
{
  Flower_Vector<int> vec;

  vec.flower_push_back(12);

  EXPECT_EQ(1, vec.flower_size());
  EXPECT_EQ(2, vec.flower_capacity());
  EXPECT_FALSE(vec.flower_empty());
}

TEST(Add_Element_Test, is_init_list_push_back_working)
{
  Flower_Vector<int> vec;

  vec.flower_push_back({1, 2, 3});
  
  EXPECT_EQ(3, vec.flower_size());
  EXPECT_EQ(4, vec.flower_capacity());
  EXPECT_FALSE(vec.flower_empty());
}

/*
TEST(Add_Element_Test, is_init_list_emplace_back_working)
{
  Flower_Vector<int> vec;

  vec.flower_emplace_back({1, 2, 3});
  
  EXPECT_EQ(3, vec.flower_size());
  EXPECT_EQ(4, vec.flower_capacity());
  EXPECT_FALSE(vec.flower_empty());
}
*/

TEST(Removing_elements, is_pop_back_working)
{
  Flower_Vector<int> vec({1, 2, 3, 4});
 
  EXPECT_EQ(4, vec.flower_size());

  vec.flower_pop_back();

  EXPECT_EQ(3, vec.flower_size());
}

/*
TEST(Removing_elements, is_clear_working)
{
  Flower_Vector<int> vec({1, 2, 3, 4});

  vec.flower_clear();
  
  EXPECT_EQ(0, vec.flower_size());
}
*/

TEST(Removing_elements, is_erase_working)
{
  Flower_Vector<int> vec({1, 2, 3, 4});
  
  EXPECT_EQ(4, vec.flower_size());

  vec.erase(vec.const_begin() + 2);

  EXPECT_EQ(3, vec.flower_size());
}

TEST(Operators, is_brackets_operator_working)
{
  Flower_Vector<int> vec({1, 2, 3, 4});

  EXPECT_EQ(2, vec[1]);
}

TEST(Operators, is_compare_operator_working)
{
  Flower_Vector<int> vec1({1, 2, 3, 4, 5});
  Flower_Vector<int> vec2({1, 2, 3, 4});

  vec1.flower_pop_back();

  EXPECT_TRUE(vec1 == vec2);
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
