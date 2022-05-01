#include <gtest/gtest.h>

#include "../include/flower_heap.h"
#include "../src/flower_heap.cpp"

TEST(Constructor, OneArgumentConstructor)
{
  Flower_Max_Heap heap(40);

  EXPECT_EQ(heap.get_capacity(), 40);
}

class HeapTest: public ::testing::Test 
{

protected:
  void SetUp() override
  {
    heap1 = {0, 1, 2, 3, 4, 5};
  }

  Flower_Max_Heap heap1;
  Flower_Max_Heap heap2;
};

TEST_F(HeapTest, IsEmpty)
{
  EXPECT_FALSE(heap1.flower_is_empty());
  EXPECT_TRUE(heap2.flower_is_empty());
}

TEST_F(HeapTest, GetSize)
{
  EXPECT_EQ(6, heap1.get_size());
}
