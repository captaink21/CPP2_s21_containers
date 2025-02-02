#include "../s21_test.h"
/*
Ctor default
*/

TEST(StackDefaultCntr, ordinary1) {
  s21::stack<int> stack1;
  EXPECT_EQ(stack1.size(), 0);

  s21::stack<unsigned long long> stack2;
  EXPECT_EQ(stack2.size(), 0);

  s21::stack<std::string> stack3;
  EXPECT_EQ(stack3.size(), 0);

  s21::stack<std::vector<int>> stack4;
  EXPECT_EQ(stack4.size(), 0);
}

/*
initializer list constructor
*/
TEST(StackInitializerListCntr, ordinary1) {
  s21::stack<int> stack = {1, 3, 4};
  EXPECT_EQ(stack.size(), 3);
  EXPECT_EQ(stack.top(), 4);

  s21::stack<std::string> stack_string = {"first", "second", "third"};
  EXPECT_EQ(stack_string.size(), 3);
  EXPECT_EQ(stack_string.top(), "third");
}

/*
Ctor copy
*/

TEST(StackCopyCtor, ordinary1) {
  s21::stack<int> stack1 = {3, 2, 5};
  s21::stack<int> stack2(stack1);
  EXPECT_EQ(stack1.size(), 3);
  EXPECT_EQ(stack1.top(), 5);

  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), 5);

  s21::stack<std::string> stack_string1 = {"first", "second", "third"};
  s21::stack<std::string> stack_string2(stack_string1);
  EXPECT_EQ(stack_string1.size(), 3);
  EXPECT_EQ(stack_string1.top(), "third");

  EXPECT_EQ(stack_string2.size(), 3);
  EXPECT_EQ(stack_string2.top(), "third");
}

/*
Ctor move
*/

TEST(StackMoveCtor, ordinary1) {
  s21::stack<std::string> stack1 = {"first", "second", "third"};
  s21::stack<std::string> stack2(std::move(stack1));
  EXPECT_EQ(stack1.size(), 0);

  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), "third");
}

TEST(StackMoveCtor, ordinary2) {
  std::vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = {4, 5};
  s21::stack<std::vector<int>> stack1 = {vec1, vec2};
  s21::stack<std::vector<int>> stack2(std::move(stack1));
  EXPECT_EQ(stack1.size(), 0);

  EXPECT_EQ(stack2.size(), 2);
  EXPECT_EQ(stack2.top()[1], 5);
}

/*
Assign move
*/

TEST(StackAssignMoveOperator, ordinary1) {
  s21::stack<int> stack1 = {2, 5, 7};
  s21::stack<int> stack2;

  EXPECT_EQ(stack1.size(), 3);
  EXPECT_EQ(stack1.top(), 7);

  EXPECT_EQ(stack2.size(), 0);

  stack2 = std::move(stack1);

  EXPECT_EQ(stack1.size(), 0);

  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), 7);

  s21::stack<std::string> stack_string_1 = {"first", "second", "third"};
  s21::stack<std::string> stack_string_2;

  EXPECT_EQ(stack_string_1.size(), 3);
  EXPECT_EQ(stack_string_1.top(), "third");

  EXPECT_EQ(stack_string_2.size(), 0);

  stack_string_2 = std::move(stack_string_1);

  EXPECT_EQ(stack_string_1.size(), 0);
  EXPECT_EQ(stack_string_2.size(), 3);
  EXPECT_EQ(stack_string_2.top(), "third");
}

TEST(StackAssignMoveOperator, ordinary2) {
  s21::stack<int> stack1;
  s21::stack<int> stack2 = {2, 5, 7};

  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), 7);

  EXPECT_EQ(stack1.size(), 0);

  stack1 = std::move(stack2);

  EXPECT_EQ(stack2.size(), 0);

  EXPECT_EQ(stack1.size(), 3);
  EXPECT_EQ(stack1.top(), 7);

  s21::stack<std::string> stack_string_1 = {"first", "second", "third"};
  s21::stack<std::string> stack_string_2;

  EXPECT_EQ(stack_string_1.size(), 3);
  EXPECT_EQ(stack_string_1.top(), "third");

  EXPECT_EQ(stack_string_2.size(), 0);

  std::swap(stack_string_2, stack_string_1);

  EXPECT_EQ(stack_string_1.size(), 0);
  EXPECT_EQ(stack_string_2.size(), 3);
  EXPECT_EQ(stack_string_2.top(), "third");
  EXPECT_EQ(stack_string_2.top(), "third");
}

TEST(StackAssignMoveOperator, ordinary3) {
  s21::stack<int> stack1;
  s21::stack<int> stack2 = {2, 5, 7};

  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), 7);

  EXPECT_EQ(stack1.size(), 0);

  std::swap(stack1, stack2);

  EXPECT_EQ(stack2.size(), 0);

  EXPECT_EQ(stack1.size(), 3);
  EXPECT_EQ(stack1.top(), 7);
}

TEST(StackAssignMoveOperator, ordinary4) {
  s21::stack<int> stack1;
  s21::stack<int> stack2 = {2, 5, 7};

  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), 7);

  EXPECT_EQ(stack1.size(), 0);

  std::swap(stack2, stack1);

  EXPECT_EQ(stack2.size(), 0);

  EXPECT_EQ(stack1.size(), 3);
  EXPECT_EQ(stack1.top(), 7);
}