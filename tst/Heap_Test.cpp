#include <gtest/gtest.h>

#include "../src/flower_heap.h"
#include "../src/flower_heap.cpp"

TEST(Constructor, OneArgumentConstructor)
{
  Flower_Max_Heap heap(40);

  EXPECT_EQ(heap.get_capacity(), 40);
}

TEST(Constructor, InitListConstructor)
{
  Flower_Max_Heap heap {40, 20, 30, 50};

  EXPECT_EQ(heap.get_size(), 4);
}

class HeapTest: public ::testing::Test 
{

protected:
  void SetUp() override
  {
    heap1 = {0, 1, 2, 3, 4, 5};
    heap_to_sort = {5, 9, 2, 1, 8, 17, 3};
  }

  Flower_Max_Heap heap1;
  Flower_Max_Heap heap2;
  Flower_Max_Heap heap_to_sort;
};

TEST_F(HeapTest, IsEmpty)
{
  EXPECT_FALSE(heap1.flower_is_empty());
  EXPECT_TRUE(heap2.flower_is_empty());
}

TEST_F(HeapTest, GetSize)
{
  EXPECT_EQ(6, heap1.get_size());
  EXPECT_EQ(0, heap2.get_size());
}

TEST_F(HeapTest, GetMax)
{
  EXPECT_EQ(5, heap1.flower_extract_max());
}

TEST_F(HeapTest, HeapSort)
{
  std::vector<int> sorted = {17, 9, 8, 5, 3, 2, 1};

  EXPECT_TRUE(sorted == heap_to_sort.flower_heap_sort());
}

TEST_F(HeapTest, DISABLED_Searching)
{
  // EXPECT_EQ(heap1.flower_search(3), );
}

TEST_F(HeapTest, DISABLED_GetItem)
{
  // EXPECT_EQ(heap1.flower_get_item(3), );
}

