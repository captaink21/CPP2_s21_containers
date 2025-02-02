#include "../s21_test.h"

/*
bool empty()
*/

TEST(QueueEmpty, ordinary1) {
  s21::queue<int> queue;
  EXPECT_EQ(queue.empty(), true);
  queue.push(1);
  EXPECT_EQ(queue.empty(), false);
  queue.pop();
  EXPECT_EQ(queue.empty(), true);
}

TEST(QueueEmpty, ordinary2) {
  s21::queue<std::string> queue = {"hello", "world"};
  EXPECT_EQ(queue.empty(), false);
  queue.pop();
  queue.pop();
  EXPECT_EQ(queue.empty(), true);
}

/*
Size
*/

TEST(QueueSize, ordinary1) {
  s21::queue<int> queue;
  EXPECT_EQ(queue.size(), 0);
  queue.push(77);
  EXPECT_EQ(queue.size(), 1);
  queue.push(3);
  queue.push(1);
  EXPECT_EQ(queue.size(), 3);
  queue.pop();
  queue.pop();
  queue.pop();
  EXPECT_EQ(queue.size(), 0);
}

TEST(QueueSize, ordinary2) {
  s21::queue<std::string> queue = {"hello", "world"};
  EXPECT_EQ(queue.size(), 2);
  queue.pop();
  queue.pop();
  EXPECT_EQ(queue.size(), 0);
}
