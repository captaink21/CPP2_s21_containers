#include "../s21_test.h"

/*

Empty

*/
#if 1
TEST(MapEmpty, ordinary1) {
  s21::map<int, std::string> m;
  EXPECT_EQ(m.empty(), true);
  auto [it, unused] = m.insert(1, "first");
  EXPECT_EQ(m.empty(), false);
  m.erase(it);
  EXPECT_EQ(m.empty(), true);
}

/*

Size

*/

TEST(MapSize, ordinary1) {
  s21::map<int, std::string> m;
  EXPECT_EQ(m.size(), 0);

  std::pair<s21::map<int, std::string>::iterator, bool> pair1, pair2, pair3,
      pair4;

  pair1 = m.insert(1, "first");
  EXPECT_EQ(m.size(), 1);
  pair2 = m.insert(2, "second");
  EXPECT_EQ(m.size(), 2);
  pair3 = m.insert(3, "third");
  EXPECT_EQ(m.size(), 3);
  pair4 = m.insert(4, "fourth");
  EXPECT_EQ(m.size(), 4);

  m.erase(pair1.first);
  EXPECT_EQ(m.size(), 3);
  m.erase(pair2.first);
  EXPECT_EQ(m.size(), 2);
  m.erase(pair3.first);
  EXPECT_EQ(m.size(), 1);
  m.erase(pair4.first);
  EXPECT_EQ(m.size(), 0);
}

/*

Max Size

*/

TEST(MapMaxSize, ordinary1) {
  s21::map<int, s21::vector<std::string>> m;
  std::map<int, s21::vector<std::string>> a;

  EXPECT_EQ(m.max_size(), a.max_size());
  s21::vector<std::string> temp{"opa", "tl"};

  m.insert({1, temp});
  a.insert({1, temp});

  EXPECT_EQ(m.max_size(), a.max_size());
}

TEST(MapMaxSize, ordinary2) {
  s21::map<std::string, int> m;
  std::map<std::string, int> a;

  EXPECT_EQ(m.max_size(), a.max_size());
  std::pair<std::string, int> temp{"opa", 1};

  m.insert(temp);
  a.insert(temp);

  EXPECT_EQ(m.max_size(), a.max_size());
}

#endif