#include <queue>

#include "../s21_test.h"
/*
Ctor default
*/

TEST(QueueDefaultCntr, ordinary1) {
  s21::queue<int> queue1;
  EXPECT_EQ(queue1.size(), 0);

  s21::queue<unsigned long long> queue2;
  EXPECT_EQ(queue2.size(), 0);

  s21::queue<std::string> queue3;
  EXPECT_EQ(queue3.size(), 0);

  s21::queue<std::vector<int>> queue4;
  EXPECT_EQ(queue4.size(), 0);
}

/*
initializer list constructor
*/
TEST(QueueInitializerListCntr, ordinary1) {
  s21::queue<int> queue = {1, 3, 4};
  EXPECT_EQ(queue.size(), 3);
  EXPECT_EQ(queue.front(), 1);
  EXPECT_EQ(queue.back(), 4);

  s21::queue<std::string> queue_string = {"first", "second", "third"};
  EXPECT_EQ(queue_string.size(), 3);
  EXPECT_EQ(queue_string.front(), "first");
  EXPECT_EQ(queue_string.back(), "third");
}

/*
Ctor copy
*/

TEST(QueueCopyCtor, ordinary1) {
  s21::queue<int> queue1 = {3, 2, 5};
  s21::queue<int> queue2(queue1);
  EXPECT_EQ(queue1.size(), 3);
  EXPECT_EQ(queue1.front(), 3);
  EXPECT_EQ(queue1.back(), 5);

  EXPECT_EQ(queue2.size(), 3);
  EXPECT_EQ(queue2.front(), 3);
  EXPECT_EQ(queue2.back(), 5);

  s21::queue<std::string> queue_string1 = {"first", "second", "third"};
  s21::queue<std::string> queue_string2(queue_string1);
  EXPECT_EQ(queue_string1.size(), 3);
  EXPECT_EQ(queue_string1.front(), "first");
  EXPECT_EQ(queue_string1.back(), "third");

  EXPECT_EQ(queue_string2.size(), 3);
  EXPECT_EQ(queue_string2.front(), "first");
  EXPECT_EQ(queue_string2.back(), "third");
}

/*
Ctor move
*/

TEST(QueueMoveCtor, ordinary1) {
  s21::queue<std::string> queue1 = {"first", "second", "third"};
  s21::queue<std::string> queue2(std::move(queue1));
  EXPECT_EQ(queue1.size(), 0);

  EXPECT_EQ(queue2.size(), 3);
  EXPECT_EQ(queue2.front(), "first");
  EXPECT_EQ(queue2.back(), "third");
}

TEST(QueueMoveCtor, ordinary2) {
  std::vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = {4, 5};
  s21::queue<std::vector<int>> queue1 = {vec1, vec2};
  s21::queue<std::vector<int>> queue2(std::move(queue1));
  EXPECT_EQ(queue1.size(), 0);

  EXPECT_EQ(queue2.size(), 2);
  EXPECT_EQ(queue2.front()[0], 1);
  EXPECT_EQ(queue2.back()[1], 5);
}

/*
Assign move
*/

TEST(QueueAssignMoveOperator, ordinary1) {
  s21::queue<int> queue1 = {2, 5, 7};
  s21::queue<int> queue2;

  EXPECT_EQ(queue1.size(), 3);
  EXPECT_EQ(queue1.front(), 2);
  EXPECT_EQ(queue1.back(), 7);

  EXPECT_EQ(queue2.size(), 0);

  queue2 = std::move(queue1);

  EXPECT_EQ(queue1.size(), 0);

  EXPECT_EQ(queue2.size(), 3);
  EXPECT_EQ(queue2.front(), 2);
  EXPECT_EQ(queue2.back(), 7);

  s21::list<std::string> queue_string_1 = {"first", "second", "third"};
  s21::list<std::string> queue_string_2;

  EXPECT_EQ(queue_string_1.size(), 3);
  EXPECT_EQ(queue_string_1.front(), "first");
  EXPECT_EQ(queue_string_1.back(), "third");

  EXPECT_EQ(queue_string_2.size(), 0);

  queue_string_2 = std::move(queue_string_1);

  EXPECT_EQ(queue_string_1.size(), 0);
  EXPECT_EQ(queue_string_2.size(), 3);
  EXPECT_EQ(queue_string_2.front(), "first");
  EXPECT_EQ(queue_string_2.back(), "third");
  EXPECT_EQ(queue_string_2.back(), "third");
}

TEST(QueueAssignMoveOperator, ordinary2) {
  s21::queue<int> queue1;
  s21::queue<int> queue2 = {2, 5, 7};

  EXPECT_EQ(queue2.size(), 3);
  EXPECT_EQ(queue2.front(), 2);
  EXPECT_EQ(queue2.back(), 7);

  EXPECT_EQ(queue1.size(), 0);

  queue1 = std::move(queue2);

  EXPECT_EQ(queue2.size(), 0);

  EXPECT_EQ(queue1.size(), 3);
  EXPECT_EQ(queue1.front(), 2);
  EXPECT_EQ(queue1.back(), 7);

  s21::list<std::string> queue_string_1 = {"first", "second", "third"};
  s21::list<std::string> queue_string_2;

  EXPECT_EQ(queue_string_1.size(), 3);
  EXPECT_EQ(queue_string_1.front(), "first");
  EXPECT_EQ(queue_string_1.back(), "third");

  EXPECT_EQ(queue_string_2.size(), 0);

  std::swap(queue_string_2, queue_string_1);

  EXPECT_EQ(queue_string_1.size(), 0);
  EXPECT_EQ(queue_string_2.size(), 3);
  EXPECT_EQ(queue_string_2.front(), "first");
  EXPECT_EQ(queue_string_2.back(), "third");
  EXPECT_EQ(queue_string_2.back(), "third");
}

TEST(QueueAssignMoveOperator, ordinary3) {
  s21::queue<int> queue1;
  s21::queue<int> queue2 = {2, 5, 7};

  EXPECT_EQ(queue2.size(), 3);
  EXPECT_EQ(queue2.front(), 2);
  EXPECT_EQ(queue2.back(), 7);

  EXPECT_EQ(queue1.size(), 0);

  std::swap(queue1, queue2);

  EXPECT_EQ(queue2.size(), 0);

  EXPECT_EQ(queue1.size(), 3);
  EXPECT_EQ(queue1.front(), 2);
  EXPECT_EQ(queue1.back(), 7);
}

TEST(QueueAssignMoveOperator, ordinary4) {
  s21::queue<int> queue1;
  s21::queue<int> queue2 = {2, 5, 7};

  EXPECT_EQ(queue2.size(), 3);
  EXPECT_EQ(queue2.front(), 2);
  EXPECT_EQ(queue2.back(), 7);

  EXPECT_EQ(queue1.size(), 0);

  std::swap(queue2, queue1);

  EXPECT_EQ(queue2.size(), 0);

  EXPECT_EQ(queue1.size(), 3);
  EXPECT_EQ(queue1.front(), 2);
  EXPECT_EQ(queue1.back(), 7);
}