#include "../s21_test.h"
#if 1
/*

Ctor default

*/

TEST(MapCtorDefault, ordinary2) {
  s21::map<std::string, std::vector<int>> m;
  EXPECT_EQ(m.size(), 0);
  EXPECT_EQ(m.begin(), nullptr);
  EXPECT_EQ(m.end(), nullptr);
  EXPECT_EQ(m.empty(), true);
}

/*

InitList ctor

*/

TEST(MapInitListCtor, ordinary1) {
  s21::map<int, std::string> m{std::pair<int, std::string>(1, "first"),
                               std::pair<int, std::string>(2, "second"),
                               std::pair<int, std::string>(3, "third")};
  EXPECT_EQ(m.size(), 3);
  EXPECT_EQ(m.begin()->first, 1);
  auto it_end = m.end();
  EXPECT_EQ((--it_end)->first, 3);
  EXPECT_EQ(m.empty(), false);
  EXPECT_EQ(m.GetRoot()->data.first, 2);
}

TEST(MapInitListCtor, ordinary2) {
  s21::map<int, std::string> m{std::pair<int, std::string>(3, "first"),
                               std::pair<int, std::string>(1, "second"),
                               std::pair<int, std::string>(2, "third")};
  EXPECT_EQ(m.size(), 3);
  EXPECT_EQ(m.begin()->first, 1);
  auto it_end = m.end();
  EXPECT_EQ((--it_end)->first, 3);
  EXPECT_EQ(m.empty(), false);
  EXPECT_EQ(m.GetRoot()->data.first, 2);
}

TEST(MapInitListCtor, ordinary3) {
  s21::map<int, std::string> map{
      std::pair<int, std::string>(13, "13"),
      std::pair<int, std::string>(8, "8"),
      std::pair<int, std::string>(17, "17"),
      std::pair<int, std::string>(1, "1"),
      std::pair<int, std::string>(11, "11"),
      std::pair<int, std::string>(6, "6"),
      std::pair<int, std::string>(15, "15"),
      std::pair<int, std::string>(25, "25"),
      std::pair<int, std::string>(22, "22"),
      std::pair<int, std::string>(27, "27"),

  };
  std::map<int, std::string> std_map{
      std::pair<int, std::string>(13, "13"),
      std::pair<int, std::string>(8, "8"),
      std::pair<int, std::string>(17, "17"),
      std::pair<int, std::string>(1, "1"),
      std::pair<int, std::string>(11, "11"),
      std::pair<int, std::string>(6, "6"),
      std::pair<int, std::string>(15, "15"),
      std::pair<int, std::string>(25, "25"),
      std::pair<int, std::string>(22, "22"),
      std::pair<int, std::string>(27, "27"),

  };
  auto it = map.begin();
  auto std_it = std_map.begin();

  for (; it != map.end(); ++it, ++std_it) {
    EXPECT_EQ(it->first, std_it->first);
    EXPECT_EQ(it->second, std_it->second);
    // std::cout << it->first << " " << std_it->first << std::endl;
  }
  it = map.begin();
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);
  EXPECT_EQ(map.GetRoot()->data.first, 13);
}

TEST(MapInitListCtor, ordinary4) {
  s21::map<std::string, std::string> m{
      std::pair<std::string, std::string>("Hello", "World")};
  EXPECT_EQ(m.size(), 1);
  EXPECT_NE(m.begin(), nullptr);
  EXPECT_NE(m.end(), nullptr);
  EXPECT_EQ(m.empty(), false);
}

TEST(MapInitListCtor, ordinary5) {
  s21::map<int, std::string> m{std::pair<int, std::string>(1, "first"),
                               std::pair<int, std::string>(2, "second")};
  EXPECT_EQ(m.size(), 2);
  EXPECT_NE(m.begin(), nullptr);
  EXPECT_NE(m.end(), nullptr);
  EXPECT_EQ(m.empty(), false);

  s21::map<int, bool> m2{std::pair<int, bool>(1, false),
                         std::pair<int, bool>(2, true),
                         std::pair<int, bool>(3, false)};

  EXPECT_EQ(m2.size(), 3);
  EXPECT_NE(m2.begin(), nullptr);
  EXPECT_NE(m2.end(), nullptr);
  EXPECT_EQ(m2.empty(), false);

  std::vector<int> v1{1, 2, 3, 4, 5};
  std::vector<int> v2{6, 7, 8, 9, 10};
  std::vector<int> v3{11, 12, 13, 14, 15};

  s21::map<std::string, std::vector<int>> m3{
      std::pair<std::string, std::vector<int>>("first", v1),
      std::pair<std::string, std::vector<int>>("second", v2),
      std::pair<std::string, std::vector<int>>("third", v3)};

  EXPECT_EQ(m3.size(), 3);
  EXPECT_NE(m3.begin(), nullptr);
  EXPECT_NE(m3.end(), nullptr);
  EXPECT_EQ(m3.empty(), false);
}

/*
map(const map &m)
 */

TEST(MapCopyCtor, ordinary1) {
  s21::map<int, std::string> map{
      std::pair<int, std::string>(13, "13"),
      std::pair<int, std::string>(8, "8"),
      std::pair<int, std::string>(17, "17"),
      std::pair<int, std::string>(1, "1"),
      std::pair<int, std::string>(11, "11"),
      std::pair<int, std::string>(6, "6"),
      std::pair<int, std::string>(15, "15"),
      std::pair<int, std::string>(25, "25"),
      std::pair<int, std::string>(22, "22"),
      std::pair<int, std::string>(27, "27"),

  };
  s21::map<int, std::string> map2(map);
  EXPECT_EQ(map.size(), 10);
  EXPECT_EQ(map.begin()->first, 1);
  auto it_end = map.end();
  EXPECT_EQ((--it_end)->first, 27);
  EXPECT_EQ(map2.size(), 10);
  EXPECT_EQ(map2.begin()->first, 1);
  auto it_end2 = map2.end();
  EXPECT_EQ((--it_end2)->first, 27);
  EXPECT_EQ(map2.begin()->first, map.begin()->first);
  it_end = map.end();
  --it_end;
  it_end2 = map2.end();
  --it_end2;
  EXPECT_EQ(it_end2->first, it_end->first);
}

/*
map(map &&m)
 */

TEST(MapMoveCtor, ordinary1) {
  s21::map<int, std::string> map{
      std::pair<int, std::string>(13, "13"),
      std::pair<int, std::string>(8, "8"),
      std::pair<int, std::string>(17, "17"),
      std::pair<int, std::string>(1, "1"),
      std::pair<int, std::string>(11, "11"),
      std::pair<int, std::string>(6, "6"),
      std::pair<int, std::string>(15, "15"),
      std::pair<int, std::string>(25, "25"),
      std::pair<int, std::string>(22, "22"),
      std::pair<int, std::string>(27, "27"),

  };
  std::map<int, std::string> std_map{
      std::pair<int, std::string>(13, "13"),
      std::pair<int, std::string>(8, "8"),
      std::pair<int, std::string>(17, "17"),
      std::pair<int, std::string>(1, "1"),
      std::pair<int, std::string>(11, "11"),
      std::pair<int, std::string>(6, "6"),
      std::pair<int, std::string>(15, "15"),
      std::pair<int, std::string>(25, "25"),
      std::pair<int, std::string>(22, "22"),
      std::pair<int, std::string>(27, "27"),

  };
  EXPECT_EQ(map.size(), 10);
  EXPECT_EQ(map.begin()->first, 1);
  auto it_end = map.end();
  EXPECT_EQ((--it_end)->first, 27);
  auto begin_to_cmpr = map.begin();
  s21::map<int, std::string> map2(std::move(map));
  EXPECT_EQ(map.size(), 0);
  EXPECT_EQ(map.begin(), nullptr);

  EXPECT_EQ(map2.size(), 10);
  EXPECT_EQ(map2.begin()->first, 1);
  EXPECT_EQ(map2.begin(), begin_to_cmpr);
  auto it_end2 = map2.end();
  EXPECT_EQ((--it_end2)->first, 27);
  auto std_it = std_map.begin();
  for (auto map2_it = map2.begin(); map2_it != map2.end(); ++map2_it) {
    EXPECT_EQ(map2_it->first, std_it->first);
    EXPECT_EQ(map2_it->second, std_it->second);
    ++std_it;
  }
}

/*
operator=(map &&m)
*/

TEST(MapMoveAssignment, ordinary1) {
  s21::map<int, std::string> map{
      std::pair<int, std::string>(13, "13"),
      std::pair<int, std::string>(8, "8"),
      std::pair<int, std::string>(17, "17"),
      std::pair<int, std::string>(1, "1"),
      std::pair<int, std::string>(11, "11"),
      std::pair<int, std::string>(6, "6"),
      std::pair<int, std::string>(15, "15"),
      std::pair<int, std::string>(25, "25"),
      std::pair<int, std::string>(22, "22"),
      std::pair<int, std::string>(27, "27"),

  };
  std::map<int, std::string> std_map{
      std::pair<int, std::string>(13, "13"),
      std::pair<int, std::string>(8, "8"),
      std::pair<int, std::string>(17, "17"),
      std::pair<int, std::string>(1, "1"),
      std::pair<int, std::string>(11, "11"),
      std::pair<int, std::string>(6, "6"),
      std::pair<int, std::string>(15, "15"),
      std::pair<int, std::string>(25, "25"),
      std::pair<int, std::string>(22, "22"),
      std::pair<int, std::string>(27, "27"),

  };
  EXPECT_EQ(map.size(), 10);
  EXPECT_EQ(map.begin()->first, 1);
  auto it_end = map.end();
  EXPECT_EQ((--it_end)->first, 27);
  auto begin_to_cmpr = map.begin();
  s21::map<int, std::string> map2;
  std::swap(map2, map);
  EXPECT_EQ(map.size(), 0);
  EXPECT_EQ(map.begin(), nullptr);

  EXPECT_EQ(map2.size(), 10);
  EXPECT_EQ(map2.begin()->first, 1);
  EXPECT_EQ(map2.begin(), begin_to_cmpr);
  auto it_end2 = map2.end();
  EXPECT_EQ((--it_end2)->first, 27);
  auto std_it = std_map.begin();
  for (auto map2_it = map2.begin(); map2_it != map2.end(); ++map2_it) {
    EXPECT_EQ(map2_it->first, std_it->first);
    EXPECT_EQ(map2_it->second, std_it->second);
    ++std_it;
  }
}
#endif