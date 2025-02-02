#include "../s21_test.h"

/*

At

*/
#if 1
TEST(VecAt, ordinary1) {
  s21::vector<std::string> v;
  v.push_back("hello");
  EXPECT_EQ(v.at(0), "hello");

  v.push_back("world");
  EXPECT_EQ(v.at(0), "hello");
  EXPECT_EQ(v.at(1), "world");
}

TEST(VecAt, throw1) {
  s21::vector<std::string> v;
  EXPECT_THROW({ v.at(-1); }, std::out_of_range);
  EXPECT_THROW({ v.at(0); }, std::out_of_range);
  EXPECT_THROW({ v.at(1); }, std::out_of_range);
}

/*

Operator []

*/

TEST(VecOperatorBracket, ordinary1) {
  s21::vector<std::string> v;
  v.push_back("hello");
  EXPECT_EQ(v[0], "hello");
  v.push_back("world");
  EXPECT_EQ(v[0], "hello");
  EXPECT_EQ(v[1], "world");
}

/*

Front

*/

TEST(VecFront, ordinary1) {
  s21::vector<std::string> v;
  v.push_back("hello");
  EXPECT_EQ(v.front(), "hello");
  v.push_back("world");
  EXPECT_EQ(v.front(), "hello");
  v.push_back("!");
  EXPECT_EQ(v.front(), "hello");
  v.erase(v.begin());
  EXPECT_EQ(v.front(), "world");
}

TEST(VecFront, ordinary2) {
  s21::vector<int> v;
  v.push_back(1);
  EXPECT_EQ(v.front(), 1);
  v.push_back(2);
  EXPECT_EQ(v.front(), 1);
  v.push_back(3);
  EXPECT_EQ(v.front(), 1);
  v.erase(v.begin());
  EXPECT_EQ(v.front(), 2);
}

/*

Back

*/

TEST(VecBack, ordinary1) {
  s21::vector<std::string> v;
  v.push_back("hello");
  EXPECT_EQ(v.back(), "hello");
  v.push_back("world");
  EXPECT_EQ(v.back(), "world");
  v.push_back("!");
  EXPECT_EQ(v.back(), "!");
  v.erase(v.begin());
  EXPECT_EQ(v.back(), "!");
}

TEST(VecBack, ordinary2) {
  s21::vector<int> v;
  v.push_back(1);
  EXPECT_EQ(v.back(), 1);
  v.push_back(2);
  EXPECT_EQ(v.back(), 2);
  v.push_back(3);
  EXPECT_EQ(v.back(), 3);
  v.erase(v.begin());
  EXPECT_EQ(v.back(), 3);
}

/*

Data

*/

TEST(VecData, ordinary1) {
  s21::vector<std::string> v;
  v.push_back("hello");
  EXPECT_EQ(*v.data(), "hello");
  v.push_back("world");
  EXPECT_EQ(*v.data(), "hello");
  v.push_back("!");
  EXPECT_EQ(*v.data(), "hello");
  v.erase(v.begin());
  EXPECT_EQ(*v.data(), "world");
}

TEST(VecData, ordinary2) {
  s21::vector<int> v;
  v.push_back(1);
  EXPECT_EQ(*(v.data()), 1);
  v.push_back(2);
  EXPECT_EQ(*(v.data()), 1);
  v.push_back(3);
  EXPECT_EQ(*(v.data()), 1);
  v.erase(v.begin());
  EXPECT_EQ(*(v.data()), 2);
}

#endif