#include "../s21_test.h"

/*
const_reference front()
*/

TEST(QueueFront, ordinary1) {
  s21::queue<std::string> queue1 = {"hello", "bye"};
  EXPECT_EQ(queue1.front(), "hello");
}

TEST(QueueFront, ordinary2) {
  s21::queue<double> queue2 = {2.02, 3.14};
  EXPECT_EQ(queue2.front(), 2.02);
}

/*
const_reference back()
*/

TEST(QueueBack, ordinary1) {
  s21::queue<std::string> queue1 = {"hello", "bye"};
  EXPECT_EQ(queue1.back(), "bye");
}

TEST(QueueBack, ordinary2) {
  s21::queue<double> queue2 = {2.02, 3.14};
  EXPECT_EQ(queue2.back(), 3.14);
}