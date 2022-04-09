#include <gtest/gtest.h>

#include "../flower_vector.h"
#include "../flower_vector.cpp"

class VectorTest : public ::testing::Test 
{

protected:
  void SetUp() override
  {
    v1 = {5, 3, 2, 4};
    v2 = {1, 2, 3};
  }

  Flower_Vector<int> v0;
  Flower_Vector<int> v1;
  Flower_Vector<int> v2;
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

TEST_F(VectorTest, CopyAssignmentOperator)
{
  v0 = v1;
  EXPECT_EQ(v0.flower_size(), v1.flower_size());
}

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

  Flower_Vector<int> vec_to_test = std::move(vec);

  EXPECT_EQ(4, vec_to_test.flower_size());
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
