#include "../s21_test.h"

/*
void push(const_reference value)
*/

TEST(StackPush, ordinary1) {
  s21::stack<std::string> stack;
  EXPECT_EQ(stack.size(), 0);
  stack.push("hello");
  EXPECT_EQ(stack.top(), "hello");
  EXPECT_EQ(stack.size(), 1);
}

TEST(StackPush, ordinary2) {
  s21::stack<int> stack = {1, 2, 3};
  EXPECT_EQ(stack.top(), 3);
  EXPECT_EQ(stack.size(), 3);
  stack.push(4);
  EXPECT_EQ(stack.size(), 4);
  EXPECT_EQ(stack.top(), 4);
}

TEST(StackPush, ordinary3) {
  s21::stack<std::vector<int>> stack = {{1, 2, 3}, {4, 5}, {6}};
  EXPECT_EQ(stack.size(), 3);
  EXPECT_EQ(stack.top()[0], 6);
  stack.push({87, 88});
  EXPECT_EQ(stack.size(), 4);
  EXPECT_EQ(stack.top()[0], 87);
}

/*
void pop()
*/

TEST(StackPop, ordinary1) {
  s21::stack<std::string> stack = {"hello"};
  EXPECT_EQ(stack.size(), 1);
  stack.pop();
  EXPECT_EQ(stack.size(), 0);
}

TEST(StackPop, ordinary2) {
  s21::stack<int> stack = {1, 2, 3};
  EXPECT_EQ(stack.top(), 3);
  EXPECT_EQ(stack.size(), 3);
  stack.pop();
  EXPECT_EQ(stack.top(), 2);
  EXPECT_EQ(stack.size(), 2);
}

TEST(StackPop, ordinary3) {
  s21::stack<std::vector<int>> stack = {{1, 2, 3}, {4, 5}, {6}};
  EXPECT_EQ(stack.top()[0], 6);
  EXPECT_EQ(stack.size(), 3);
  stack.pop();
  EXPECT_EQ(stack.top()[0], 4);
  EXPECT_EQ(stack.top()[1], 5);
  EXPECT_EQ(stack.size(), 2);
}

/*
void swap(list& other)
*/

TEST(StackSwap, ordinary1) {
  s21::stack<std::string> stack;
  stack.swap(stack);
  EXPECT_EQ(stack.size(), 0);
}

TEST(StackSwap, ordinary2) {
  s21::stack<std::string> stack1 = {"hello", "world"};
  s21::stack<std::string> stack2 = {"school", "21", "!"};
  EXPECT_EQ(stack1.size(), 2);
  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack1.top(), "world");
  EXPECT_EQ(stack2.top(), "!");

  stack1.swap(stack2);

  EXPECT_EQ(stack1.top(), "!");
  EXPECT_EQ(stack2.top(), "world");
  EXPECT_EQ(stack1.size(), 3);
  EXPECT_EQ(stack2.size(), 2);
}

TEST(StackSwap, ordinary3) {
  s21::stack<int> stack1 = {1, 2, 3};
  s21::stack<int> stack2 = {6, 5};
  EXPECT_EQ(stack1.size(), 3);
  EXPECT_EQ(stack1.top(), 3);

  EXPECT_EQ(stack2.size(), 2);
  EXPECT_EQ(stack2.top(), 5);
  stack1.swap(stack2);
  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), 3);

  EXPECT_EQ(stack1.size(), 2);
  EXPECT_EQ(stack1.top(), 5);
}

TEST(StackSwap, ordinary4) {
  s21::stack<int> stack1 = {1, 2, 3};
  s21::stack<int> stack2;
  EXPECT_EQ(stack1.size(), 3);
  EXPECT_EQ(stack1.top(), 3);

  EXPECT_EQ(stack2.size(), 0);
  stack1.swap(stack2);
  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), 3);

  EXPECT_EQ(stack1.size(), 0);
}

TEST(StackSwap, ordinary5) {
  s21::stack<int> stack2 = {1, 2, 3};
  s21::stack<int> stack1;
  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), 3);

  EXPECT_EQ(stack1.size(), 0);
  stack1.swap(stack2);
  EXPECT_EQ(stack1.size(), 3);
  EXPECT_EQ(stack1.top(), 3);

  EXPECT_EQ(stack2.size(), 0);
}

TEST(StackSwap, ordinary6) {
  s21::stack<std::vector<int>> stack1 = {{1, 2, 3}, {4, 5}, {6}};
  s21::stack<std::vector<int>> stack2 = {{9}, {7, 10}};
  EXPECT_EQ(stack1.top()[0], 6);
  EXPECT_EQ(stack1.size(), 3);

  EXPECT_EQ(stack2.top()[0], 7);
  EXPECT_EQ(stack2.size(), 2);

  stack1.swap(stack2);

  EXPECT_EQ(stack2.top()[0], 6);
  EXPECT_EQ(stack2.size(), 3);

  EXPECT_EQ(stack1.top()[0], 7);
  EXPECT_EQ(stack1.size(), 2);
}

/*
void insert_many_back(Args&&... args)
*/
TEST(StackInsertMany, ordinary1) {
  s21::stack<int> stack = {1, 2, 6, 11};
  stack.insert_many_back(3, 4, 6);

  EXPECT_EQ(stack.size(), 7);
  EXPECT_EQ(stack.top(), 6);
  stack.pop();
  EXPECT_EQ(stack.top(), 4);
  stack.pop();
  EXPECT_EQ(stack.top(), 3);
  stack.pop();
  EXPECT_EQ(stack.top(), 11);
  stack.pop();
  EXPECT_EQ(stack.top(), 6);
  stack.pop();
  EXPECT_EQ(stack.top(), 2);
  stack.pop();
  EXPECT_EQ(stack.size(), 1);
}