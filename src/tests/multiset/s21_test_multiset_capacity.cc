#include "../s21_test.h"

/*

Empty

*/
#if 1
TEST(MultisetEmpty, ordinary1) {
  s21::multiset<std::string> s;
  EXPECT_EQ(s.empty(), true);
  auto it = s.insert("first");
  EXPECT_EQ(s.empty(), false);
  s.erase(it);
  EXPECT_EQ(s.empty(), true);
}

/*

Size

*/

TEST(MultisetSize, ordinary1) {
  s21::multiset<std::string> s;
  EXPECT_EQ(s.size(), 0);

  s21::multiset<std::string>::iterator it1, it2, it3, it4;

  it1 = s.insert("first");
  EXPECT_EQ(s.size(), 1);
  it2 = s.insert("second");
  EXPECT_EQ(s.size(), 2);
  it3 = s.insert("third");
  EXPECT_EQ(s.size(), 3);
  it4 = s.insert("fourth");
  EXPECT_EQ(s.size(), 4);

  s.erase(it1);
  EXPECT_EQ(s.size(), 3);
  s.erase(it2);
  EXPECT_EQ(s.size(), 2);
  s.erase(it3);
  EXPECT_EQ(s.size(), 1);
  s.erase(it4);
  EXPECT_EQ(s.size(), 0);
}

/*

Max Size

*/

TEST(MultisetMaxSize, ordinary1) {
  s21::multiset<std::vector<std::string>> s;
  std::multiset<std::vector<std::string>> a;

  EXPECT_NE(s.max_size(), a.max_size());
  std::vector<std::string> temp{"opa", "tl"};

  s.insert(temp);
  a.insert(temp);

  EXPECT_NE(s.max_size(), a.max_size());
}

TEST(MultisetMaxSize, ordinary2) {
  s21::multiset<int> s;
  std::multiset<int> a;

  EXPECT_NE(s.max_size(), a.max_size());
  int temp{1};

  s.insert(temp);
  a.insert(temp);

  EXPECT_NE(s.max_size(), a.max_size());
}

#endif