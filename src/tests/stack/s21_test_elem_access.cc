#include "../s21_test.h"

/*
const_reference top()
*/

TEST(StackTop, ordinary1) {
  s21::stack<std::string> stack1 = {"hello", "bye"};
  EXPECT_EQ(stack1.top(), "bye");
}

TEST(StackTop, ordinary2) {
  s21::stack<double> stack2 = {2.02, 3.14};
  EXPECT_EQ(stack2.top(), 3.14);
}