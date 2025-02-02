#include "../s21_test.h"

/*
bool empty()
*/

TEST(ListEmpty, ordinary1) {
  s21::list<int> list;
  EXPECT_EQ(list.empty(), true);
  list.push_back(1);
  EXPECT_EQ(list.empty(), false);
  list.pop_back();
  EXPECT_EQ(list.empty(), true);
}

TEST(ListEmpty, ordinary2) {
  s21::list<std::string> list = {"hello", "world"};
  EXPECT_EQ(list.empty(), false);
  list.pop_back();
  list.pop_back();
  EXPECT_EQ(list.empty(), true);
}

/*
Size
*/

TEST(ListSize, ordinary1) {
  s21::list<int> list;
  EXPECT_EQ(list.size(), 0);
  list.push_back(77);
  EXPECT_EQ(list.size(), 1);
  list.push_back(3);
  list.push_back(1);
  EXPECT_EQ(list.size(), 3);
  list.clear();
  EXPECT_EQ(list.size(), 0);
}

TEST(ListSize, ordinary2) {
  s21::list<std::string> list = {"hello", "world"};
  EXPECT_EQ(list.size(), 2);
  list.clear();
  EXPECT_EQ(list.size(), 0);
}

/*
Max Size
*/

TEST(ListMaxSize, ordinary1) {
  s21::vector<s21::vector<int>> s21_list;
  std::vector<s21::vector<int>> std_list;

  EXPECT_EQ(s21_list.max_size(), std_list.max_size());
  s21::vector<int> temp(1);

  s21_list.push_back(temp);
  std_list.push_back(temp);

  EXPECT_EQ(s21_list.max_size(), std_list.max_size());
}

TEST(ListMaxSize, ordinary2) {
  s21::vector<char> s21_list;
  std::vector<char> std_list;

  EXPECT_EQ(s21_list.max_size(), std_list.max_size());
  int temp(1);

  s21_list.push_back(temp);
  std_list.push_back(temp);

  EXPECT_EQ(s21_list.max_size(), std_list.max_size());
}