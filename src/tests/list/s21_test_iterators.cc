#include "../s21_test.h"

/*
Begin
*/

TEST(begin, ordinary1) {
  s21::list<int> lst1 = {5, 8};
  EXPECT_EQ(*(lst1.begin()), 5);
}

TEST(begin, ordinary2) {
  s21::list<int> empty_lst;
  EXPECT_EQ(empty_lst.begin(), empty_lst.end());
}

TEST(begin, ordinary3) {
  s21::list<std::string> list_string = {"hello", "world"};
  EXPECT_EQ(*(list_string.begin()), "hello");
}

TEST(begin, ordinary4) {
  const s21::list<std::string> list_string = {"hello", "world"};
  s21::list<std::string>::const_iterator it;
  it = list_string.begin();
  EXPECT_EQ(it != list_string.end(), true);
  EXPECT_EQ(*(it++), "hello");
}

/*
End
*/

TEST(end, ordinary1) {
  s21::list<int> lst1 = {5, 8};
  EXPECT_EQ(*(--lst1.end()), 8);
}

TEST(end, ordinary2) {
  s21::list<int> empty_lst;
  EXPECT_EQ(empty_lst.begin(), empty_lst.end());
}

TEST(end, ordinary3) {
  s21::list<std::string> list_string = {"hello", "world"};
  EXPECT_EQ(*(--list_string.end()), "world");
  s21::list<std::string>::iterator it;
  it = list_string.end();
  it--;
  EXPECT_EQ(*(--it), "hello");
}

TEST(end, ordinary4) {
  const s21::list<std::string> list_string = {"hello", "world"};
  s21::list<std::string>::const_iterator it;
  it = list_string.end();
  it--;
  EXPECT_EQ(it == list_string.begin(), false);
  EXPECT_EQ(*it, "world");
}

/*
iterator operations
*/

TEST(IteratorOperations, ordinary1) {
  s21::list<int> lst1 = {5, 8};
  EXPECT_EQ(*(lst1.begin()), 5);
  EXPECT_EQ(*(++lst1.begin()), 8);
  EXPECT_EQ(*(--lst1.end()), 8);
  EXPECT_EQ(lst1.end() != lst1.begin(), 1);
}

TEST(IteratorOperations, ordinary2) {
  s21::list<int> lst1;
  EXPECT_EQ(lst1.begin() == lst1.end(), 1);
}

/*
const_iterator operations
*/

TEST(ConstIteratorOperations, ordinary1) {
  s21::list<int> lst1 = {5, 8};
  s21::list<int>::const_iterator it = lst1.cbegin();
  s21::list<int>::const_iterator it_end = lst1.cend();
  EXPECT_EQ(*(it), 5);
  EXPECT_EQ(*(++it), 8);
  EXPECT_EQ(*(--it_end), 8);
  EXPECT_EQ(lst1.cbegin() != lst1.cend(), 1);
}

TEST(ConstIteratorOperations, ordinary2) {
  s21::list<int> lst1;
  s21::list<int>::const_iterator it = lst1.cbegin();
  s21::list<int>::const_iterator it_end = lst1.cend();
  EXPECT_EQ(it == it_end, 1);
}