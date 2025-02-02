#include "../s21_test.h"

/*
bool empty()
*/

TEST(StackEmpty, ordinary1) {
  s21::stack<int> stack;
  EXPECT_EQ(stack.empty(), true);
  stack.push(1);
  EXPECT_EQ(stack.empty(), false);
  stack.pop();
  EXPECT_EQ(stack.empty(), true);
}

TEST(StackEmpty, ordinary2) {
  s21::stack<std::string> stack = {"hello", "world"};
  EXPECT_EQ(stack.empty(), false);
  stack.pop();
  stack.pop();
  EXPECT_EQ(stack.empty(), true);
}

/*
Size
*/

TEST(StackSize, ordinary1) {
  s21::stack<int> stack;
  EXPECT_EQ(stack.size(), 0);
  stack.push(77);
  EXPECT_EQ(stack.size(), 1);
  stack.push(3);
  stack.push(1);
  EXPECT_EQ(stack.size(), 3);
  stack.pop();
  stack.pop();
  stack.pop();
  EXPECT_EQ(stack.size(), 0);
}

TEST(StackSize, ordinary2) {
  s21::stack<std::string> stack = {"hello", "world"};
  EXPECT_EQ(stack.size(), 2);
  stack.pop();
  stack.pop();
  EXPECT_EQ(stack.size(), 0);
}