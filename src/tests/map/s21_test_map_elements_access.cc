#include "../s21_test.h"

/*

At

*/
#if 1
TEST(MapAt, ordinary1) {
  s21::map<int, int> m;
  m.insert(1, 10);
  EXPECT_EQ(10, m.at(1));
}

TEST(MapAt, ordinary2) {
  s21::map<int, int> m;
  m.insert(1, 10);
  m.insert(2, 20);
  EXPECT_EQ(10, m.at(1));
  EXPECT_EQ(20, m.at(2));
}

TEST(MapAt, ordinary3) {
  s21::map<int, int> m;
  m.insert(1, 10);
  m.insert(2, 20);
  m.insert(3, 30);
  EXPECT_EQ(10, m.at(1));
  EXPECT_EQ(20, m.at(2));
  EXPECT_EQ(30, m.at(3));
}

TEST(MapAt, ordinary4) {
  std::vector<int> v = {1, 2, 3};
  s21::map<int, std::vector<int>> m;
  m.insert({1, v});
  EXPECT_EQ(1, m.at(1)[0]);
  EXPECT_EQ(2, m.at(1)[1]);
  EXPECT_EQ(3, m.at(1)[2]);
}

TEST(MapAt, throw1) {
  s21::map<int, int> m;
  m.insert(1, 10);
  m.insert(2, 20);
  m.insert(3, 30);

  EXPECT_THROW({ m.at(4); }, std::out_of_range);
  EXPECT_THROW({ m.at(0); }, std::out_of_range);
  EXPECT_THROW({ m.at(-1); }, std::out_of_range);
}

/*

operator []

*/

TEST(MapOperatorAccess, ordinary1) {
  s21::map<int, int> m;
  m.insert(1, 10);
  EXPECT_EQ(10, m[1]);
}

TEST(MapOperatorAccess, ordinary2) {
  s21::map<int, int> m;
  m.insert(1, 10);
  m.insert(2, 20);
  EXPECT_EQ(10, m[1]);
  EXPECT_EQ(20, m[2]);
}

TEST(MapOperatorAccess, ordinary3) {
  s21::map<int, int> m;
  m.insert(1, 10);
  m.insert(2, 20);
  m.insert(3, 30);
  EXPECT_EQ(10, m[1]);
  EXPECT_EQ(20, m[2]);
  EXPECT_EQ(30, m[3]);
}

TEST(MapOperatorAccess, ordinary4) {
  s21::map<int, int> m;
  m.insert(1, 10);
  m.insert(2, 20);
  EXPECT_EQ(0, m[5]);
  EXPECT_EQ(0, m[-2]);
}

TEST(MapOperatorAccess, ordinary5) {
  s21::map<std::string, std::string> m;
  m.insert("Hello", "World");
  EXPECT_EQ("World", m["Hello"]);
  EXPECT_EQ("", m["WTF"]);
}

TEST(MapOperatorAccess, ordinary6) {
  s21::map<std::string, s21::vector<int>> m;
  s21::vector<int> vec = m["Hello"];
  EXPECT_EQ(true, vec.empty());
}

#endif