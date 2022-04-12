#include <gtest/gtest.h>

#include "../flower_vector.h"
#include "../flower_vector.cpp"

TEST(Constructors, OneArgumentConstructor)
{
  Flower_Vector<int> vec(1);

  EXPECT_EQ(1, vec.flower_size());
}

TEST(Constructors, InitListConstructor)
{
  Flower_Vector<int> vec {1, 2, 3, 4};

  EXPECT_EQ(4, vec.flower_size());

  // capacity + capacity if there is not enough space 
  EXPECT_EQ(4, vec.flower_capacity());
}

TEST(Constructors, CopyConstructor)
{
  Flower_Vector<int> vec {1, 2, 3, 4};

  Flower_Vector<int> vec_to_test = vec;

  EXPECT_EQ(4, vec_to_test.flower_size());
}

TEST(Constructors, MoveConstructor)
{
  Flower_Vector<int> vec {1, 2, 3, 4};

  std::size_t tmp_size = vec.flower_size();
  std::size_t tmp_cap = vec.flower_size();

  Flower_Vector<int> vec_to_test = std::move(vec);

  EXPECT_EQ(tmp_size, vec_to_test.flower_size());
  EXPECT_EQ(tmp_cap, vec_to_test.flower_capacity());
}

class VectorTest : public ::testing::Test 
{

protected:
  void SetUp() override
  {
    v1 = {5, 3, 2, 4};
    v2 = {1, 2, 3};
    v3 = {5, 3, 2, 4};
  }

  Flower_Vector<int> v0;
  Flower_Vector<int> v1;
  Flower_Vector<int> v2;
  Flower_Vector<int> v3;
};

TEST_F(VectorTest, IsEmptyInitially)
{
  EXPECT_EQ(v0.flower_size(), 0);
}

TEST_F(VectorTest, Size)
{
  EXPECT_EQ(v1.flower_size(), 4);
}

TEST_F(VectorTest, Capacity)
{
  EXPECT_EQ(v0.flower_capacity(), 2);
}

TEST_F(VectorTest, End)
{
  EXPECT_FALSE(v1.flower_empty());
}

TEST_F(VectorTest, CopyAssignmentOperator)
{
  v0 = v1;
  EXPECT_EQ(v0.flower_size(), v1.flower_size());
}

TEST_F(VectorTest, CompareOperator)
{
  EXPECT_EQ(v1, v3);
}

TEST_F(VectorTest, IteratorBegin)
{
  EXPECT_EQ(*(v2.begin()), 1);
}

TEST_F(VectorTest, ConstIteratorBegin)
{
  EXPECT_EQ(*(v2.const_begin()), 1);
}

TEST_F(VectorTest, IteratorEnd)
{
  EXPECT_EQ(*(v2.end() - 1), 3);
}

TEST_F(VectorTest, ConstIteratorEnd)
{
  EXPECT_EQ(*(v2.const_end() - 1), 3);
}

TEST_F(VectorTest, Reserve)
{
  v2.flower_reserve(20);
  EXPECT_EQ(v2.flower_capacity(), 20);
}

TEST_F(VectorTest, Shrink)
{
  EXPECT_FALSE(v2.flower_size() == v2.flower_capacity());
  v2.shrink_to_fit();
  EXPECT_EQ(v2.flower_size(), v2.flower_capacity());
}

TEST_F(VectorTest, SingleElementPushBack)
{
  int tmp = v2.flower_size();
  v2.flower_push_back(90);
  EXPECT_EQ(v2.flower_size(), tmp+1);
}

TEST_F(VectorTest, InitListPushBack)
{
  int tmp = v2.flower_size();
  v2.flower_push_back({1, 2, 3, 4});
  EXPECT_EQ(v2.flower_size(), tmp+4);
}

TEST_F(VectorTest, PopBack)
{
  int tmp = v2.flower_size();
  v2.flower_pop_back();
  EXPECT_EQ(v2.flower_size(), tmp-1);
}

TEST_F(VectorTest, Clear)
{
  EXPECT_FALSE(v2.flower_empty());
  v2.flower_clear();
  EXPECT_TRUE(v2.flower_empty());
}

TEST_F(VectorTest, Erase)
{
  int tmp = v3[2];
  v3.erase(v3.const_begin() + 2);
  EXPECT_FALSE(v3[2] == tmp);
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
