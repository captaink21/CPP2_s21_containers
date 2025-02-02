#include "../s21_test.h"

/*

Empty

*/
#if 1
TEST(SetEmpty, ordinary1) {
  s21::set<std::string> s;
  EXPECT_EQ(s.empty(), true);
  auto [it, unused] = s.insert("first");
  EXPECT_EQ(s.empty(), false);
  s.erase(it);
  EXPECT_EQ(s.empty(), true);
}

/*

Size

*/

TEST(SetSize, ordinary1) {
  s21::set<std::string> s;
  EXPECT_EQ(s.size(), 0);

  std::pair<s21::set<std::string>::iterator, bool> pair1, pair2, pair3, pair4;

  pair1 = s.insert("first");
  EXPECT_EQ(s.size(), 1);
  pair2 = s.insert("second");
  EXPECT_EQ(s.size(), 2);
  pair3 = s.insert("third");
  EXPECT_EQ(s.size(), 3);
  pair4 = s.insert("fourth");
  EXPECT_EQ(s.size(), 4);

  s.erase(pair1.first);
  EXPECT_EQ(s.size(), 3);
  s.erase(pair2.first);
  EXPECT_EQ(s.size(), 2);
  s.erase(pair3.first);
  EXPECT_EQ(s.size(), 1);
  s.erase(pair4.first);
  EXPECT_EQ(s.size(), 0);
}

/*

Max Size

*/

TEST(SetMaxSize, ordinary1) {
  s21::set<std::vector<std::string>> s;
  std::set<std::vector<std::string>> a;

  EXPECT_NE(s.max_size(), a.max_size());
  std::vector<std::string> temp{"opa", "tl"};

  s.insert(temp);
  a.insert(temp);

  EXPECT_NE(s.max_size(), a.max_size());
}

TEST(SetMaxSize, ordinary2) {
  s21::set<int> s;
  std::set<int> a;

  EXPECT_NE(s.max_size(), a.max_size());
  int temp{1};

  s.insert(temp);
  a.insert(temp);

  EXPECT_NE(s.max_size(), a.max_size());
}

#endif