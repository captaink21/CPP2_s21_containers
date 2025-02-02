#include "../s21_test.h"

/*
void push(const_reference value)
*/

TEST(QueuePush, ordinary1) {
  s21::queue<std::string> queue;
  EXPECT_EQ(queue.size(), 0);
  queue.push("hello");
  EXPECT_EQ(queue.front(), "hello");
  EXPECT_EQ(queue.size(), 1);
}

TEST(QueuePush, ordinary2) {
  s21::queue<int> queue = {1, 2, 3};
  EXPECT_EQ(queue.size(), 3);
  queue.push(4);
  EXPECT_EQ(queue.size(), 4);
  EXPECT_EQ(queue.front(), 1);
  EXPECT_EQ(queue.back(), 4);
}

TEST(QueuePush, ordinary3) {
  s21::queue<std::vector<int>> queue = {{1, 2, 3}, {4, 5}, {6}};
  EXPECT_EQ(queue.size(), 3);
  queue.push({87, 88});
  EXPECT_EQ(queue.size(), 4);
  EXPECT_EQ(queue.front()[0], 1);
  EXPECT_EQ(queue.back()[0], 87);
}

/*
void pop()
*/

TEST(QueuePop, ordinary1) {
  s21::queue<std::string> queue = {"hello"};
  EXPECT_EQ(queue.size(), 1);
  queue.pop();
  EXPECT_EQ(queue.size(), 0);
}

TEST(QueuePop, ordinary2) {
  s21::queue<int> queue = {1, 2, 3};
  EXPECT_EQ(queue.front(), 1);
  EXPECT_EQ(queue.size(), 3);
  queue.pop();
  EXPECT_EQ(queue.front(), 2);
  EXPECT_EQ(queue.back(), 3);
  EXPECT_EQ(queue.size(), 2);
}

TEST(QueuePop, ordinary3) {
  s21::queue<std::vector<int>> queue = {{1, 2, 3}, {4, 5}, {6}};
  EXPECT_EQ(queue.front()[0], 1);
  EXPECT_EQ(queue.front()[1], 2);
  EXPECT_EQ(queue.front()[2], 3);
  EXPECT_EQ(queue.size(), 3);
  queue.pop();
  EXPECT_EQ(queue.front()[0], 4);
  EXPECT_EQ(queue.front()[1], 5);
  EXPECT_EQ(queue.size(), 2);
}

/*
void swap(list& other)
*/

TEST(QueueSwap, ordinary1) {
  s21::queue<std::string> queue;
  queue.swap(queue);
  EXPECT_EQ(queue.size(), 0);
}

TEST(QueueSwap, ordinary2) {
  s21::queue<std::string> queue1 = {"hello", "world"};
  s21::queue<std::string> queue2 = {"school", "21", "!"};
  EXPECT_EQ(queue1.size(), 2);
  EXPECT_EQ(queue2.size(), 3);
  EXPECT_EQ(queue1.front(), "hello");
  EXPECT_EQ(queue1.back(), "world");
  EXPECT_EQ(queue2.front(), "school");
  EXPECT_EQ(queue2.back(), "!");

  queue1.swap(queue2);

  EXPECT_EQ(queue1.front(), "school");
  EXPECT_EQ(queue1.back(), "!");
  EXPECT_EQ(queue2.front(), "hello");
  EXPECT_EQ(queue2.back(), "world");
  EXPECT_EQ(queue1.size(), 3);
  EXPECT_EQ(queue2.size(), 2);
}

TEST(QueueSwap, ordinary3) {
  s21::queue<int> queue1 = {1, 2, 3};
  s21::queue<int> queue2 = {6, 5};
  EXPECT_EQ(queue1.size(), 3);
  EXPECT_EQ(queue1.front(), 1);
  EXPECT_EQ(queue1.back(), 3);

  EXPECT_EQ(queue2.size(), 2);
  EXPECT_EQ(queue2.front(), 6);
  EXPECT_EQ(queue2.back(), 5);
  queue1.swap(queue2);
  EXPECT_EQ(queue2.size(), 3);
  EXPECT_EQ(queue2.front(), 1);
  EXPECT_EQ(queue2.back(), 3);

  EXPECT_EQ(queue1.size(), 2);
  EXPECT_EQ(queue1.front(), 6);
  EXPECT_EQ(queue1.back(), 5);
}

TEST(QueueSwap, ordinary4) {
  s21::queue<int> queue1 = {1, 2, 3};
  s21::queue<int> queue2;
  EXPECT_EQ(queue1.size(), 3);
  EXPECT_EQ(queue1.front(), 1);
  EXPECT_EQ(queue1.back(), 3);

  EXPECT_EQ(queue2.size(), 0);
  queue1.swap(queue2);
  EXPECT_EQ(queue2.size(), 3);
  EXPECT_EQ(queue2.front(), 1);
  EXPECT_EQ(queue2.back(), 3);

  EXPECT_EQ(queue1.size(), 0);
}

TEST(QueueSwap, ordinary5) {
  s21::queue<int> queue2 = {1, 2, 3};
  s21::queue<int> queue1;
  EXPECT_EQ(queue2.size(), 3);
  EXPECT_EQ(queue2.front(), 1);
  EXPECT_EQ(queue2.back(), 3);

  EXPECT_EQ(queue1.size(), 0);
  queue1.swap(queue2);
  EXPECT_EQ(queue1.size(), 3);
  EXPECT_EQ(queue1.front(), 1);
  EXPECT_EQ(queue1.back(), 3);

  EXPECT_EQ(queue2.size(), 0);
}

TEST(QueueSwap, ordinary6) {
  s21::queue<std::vector<int>> queue1 = {{1, 2, 3}, {4, 5}, {6}};
  s21::queue<std::vector<int>> queue2 = {{9}, {6, 10}};
  EXPECT_EQ(queue1.front()[0], 1);
  EXPECT_EQ(queue1.back()[0], 6);
  EXPECT_EQ(queue1.size(), 3);

  EXPECT_EQ(queue2.front()[0], 9);
  EXPECT_EQ(queue2.back()[0], 6);
  EXPECT_EQ(queue2.size(), 2);

  queue1.swap(queue2);

  EXPECT_EQ(queue2.front()[0], 1);
  EXPECT_EQ(queue2.back()[0], 6);
  EXPECT_EQ(queue2.size(), 3);

  EXPECT_EQ(queue1.front()[0], 9);
  EXPECT_EQ(queue1.back()[0], 6);
  EXPECT_EQ(queue1.size(), 2);
}

/*
void insert_many_back(Args&&... args)
*/

TEST(QueueInsertMany, ordinary1) {
  s21::queue<int> queue = {1, 2, 6, 11};
  queue.insert_many_back(3, 4, 6);

  EXPECT_EQ(queue.size(), 7);
  EXPECT_EQ(queue.front(), 1);
  queue.pop();
  EXPECT_EQ(queue.front(), 2);
  queue.pop();
  EXPECT_EQ(queue.front(), 6);
  queue.pop();
  EXPECT_EQ(queue.front(), 11);
  queue.pop();
  EXPECT_EQ(queue.front(), 3);
  queue.pop();
  EXPECT_EQ(queue.front(), 4);
  queue.pop();
  EXPECT_EQ(queue.front(), 6);
  EXPECT_EQ(queue.size(), 1);
}