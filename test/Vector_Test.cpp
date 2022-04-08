#include <gtest/gtest.h>

#include "../flower_vector.h"
#include "../flower_vector.cpp"
  
TEST(Constructor_Test, IsVectorEmptyAtInit)
{
  Flower_Vector<int> vec;

  EXPECT_EQ(0, vec.flower_size());
  EXPECT_EQ(2, vec.flower_capacity());
}

TEST(Constructors, OneArgumentConstructor)
{
  Flower_Vector<int> vec(1);

  EXPECT_EQ(1, vec.flower_size());
  EXPECT_EQ(2, vec.flower_capacity());
}

TEST(Constructors, InitListConstructor)
{
  Flower_Vector<int> vec {1, 2, 3, 4};

  EXPECT_EQ(4, vec.flower_size());

  /* capacity + capacity if there is not enough space */
  EXPECT_EQ(4, vec.flower_capacity());
}

TEST(Constructors, MoveConstructor)
{
  Flower_Vector<int> vec {1, 2, 3, 4};

  Flower_Vector<int> vec_to_test = std::move(vec);

  EXPECT_EQ(4, vec_to_test.flower_size());
}

TEST(Constructors, CopyConstructor)
{
  Flower_Vector<int> vec {1, 2, 3, 4};

  Flower_Vector<int> vec_to_test = vec;

  EXPECT_EQ(4, vec_to_test.flower_size());
  EXPECT_EQ(4, vec_to_test.flower_capacity());
}

TEST(AddingElements, SingleElementPushBack)
{
  Flower_Vector<int> vec;

  vec.flower_push_back(12);

  EXPECT_EQ(1, vec.flower_size());
  EXPECT_EQ(2, vec.flower_capacity());
}

TEST(AddingElements, MultipleElementsPushBack)
{
  Flower_Vector<int> vec;

  vec.flower_push_back({1, 2, 3});
  
  EXPECT_EQ(3, vec.flower_size());
}

TEST(AddingElements, MultipleElementsEmplaceBack)
{
  Flower_Vector<int> vec;

  vec.flower_emplace_back({1, 2, 3});
  
  EXPECT_EQ(3, vec.flower_size());
}

TEST(RemovingElements, PopBack)
{
  Flower_Vector<int> vec({1, 2, 3, 4});
 
  EXPECT_EQ(4, vec.flower_size());

  vec.flower_pop_back();

  EXPECT_EQ(3, vec.flower_size());
}

TEST(RemovingElements, Clear)
{
  Flower_Vector<int> vec({1, 2, 3, 4});

  vec.flower_clear();
  
  EXPECT_TRUE(vec.flower_empty());
}

TEST(RemovingElements, SingleElementErase)
{
  Flower_Vector<int> vec({1, 2, 3, 4});
  
  EXPECT_EQ(4, vec.flower_size());

  vec.erase(vec.const_begin() + 2);

  EXPECT_EQ(3, vec.flower_size());
}

TEST(RemovingElements, Shrink)
{
  Flower_Vector<int> vec(1);
  
  EXPECT_FALSE(vec.flower_size() == vec.flower_capacity());

  vec.shrink_to_fit();

  EXPECT_EQ(vec.flower_size(), vec.flower_capacity());
}

TEST(Operators, SquareBracketsOperator)
{
  Flower_Vector<int> vec({1, 2, 3, 4});

  EXPECT_EQ(2, vec[1]);
}

TEST(Operators, CompareOperator)
{
  Flower_Vector<int> vec1({1, 2, 3, 4, 5});
  Flower_Vector<int> vec2({1, 2, 3, 4});

  vec1.flower_pop_back();

  EXPECT_TRUE(vec1 == vec2);
}

TEST(Operators, CopyAssignmentOperator)
{
  Flower_Vector<int> vec1({1, 2, 3, 4, 5});

  Flower_Vector<int> vec2;

  vec1 = vec2;

  EXPECT_EQ(vec1.flower_size(), vec2.flower_size());
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
