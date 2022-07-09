#include <gtest/gtest.h>

#include "../src/flower_stack.h"

TEST(CreateStack, IsEmptyInitially)
{
  Stack<int> stack;
  EXPECT_TRUE(stack.stack_empty());
}

class StackTest: public ::testing::Test 
{

protected:
  Stack<int> stack;

  void SetUp() override
  {
    stack.push(50);
  }
};

TEST_F(StackTest, AddValue)
{
  EXPECT_FALSE(stack.stack_empty());
}

TEST_F(StackTest, GetTop)
{
  EXPECT_EQ(stack.get_top(), 50);
}

TEST_F(StackTest, Pop)
{
  stack.pop();

  EXPECT_TRUE(stack.stack_empty());
}


