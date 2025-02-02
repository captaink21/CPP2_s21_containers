#include <list>

#include "../s21_test.h"

/*
const_reference front()
*/

TEST(front, ordinary1) {
  s21::list<std::string> lst1 = {"hello", "bye"};
  EXPECT_EQ(lst1.front(), "hello");
}

TEST(front, ordinary2) {
  s21::list<double> lst1 = {2.02, 3.14};
  EXPECT_EQ(lst1.front(), 2.02);
}

/*
const_reference back()
*/

TEST(back, ordinary1) {
  s21::list<std::string> lst1 = {"hello", "bye"};
  EXPECT_EQ(lst1.back(), "bye");
}

TEST(back, ordinary2) {
  s21::list<double> lst1 = {2.02, 3.14};
  EXPECT_EQ(lst1.back(), 3.14);
}