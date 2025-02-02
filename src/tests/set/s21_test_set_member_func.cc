#include "../s21_test.h"

/*

Ctor default

*/
#if 1
TEST(SetCtorDefault, ordinary1) {
  s21::set<std::string> m;
  EXPECT_EQ(m.size(), 0);
  EXPECT_EQ(m.begin(), nullptr);
  EXPECT_EQ(m.end(), nullptr);
  EXPECT_EQ(m.empty(), true);
}

/*

InitList ctor

*/

TEST(SetInitListCtor, ordinary1) {
  s21::set<int> m{1, 2, 3};
  EXPECT_EQ(m.size(), 3);
  EXPECT_EQ(*m.begin(), 1);
  auto it_end = m.end();
  EXPECT_EQ(*(--it_end), 3);
  EXPECT_EQ(m.empty(), false);
  EXPECT_EQ(m.GetRoot()->data.first, 2);
}

TEST(SetInitListCtor, ordinary2) {
  s21::set<int> m{3, 1, 2};
  EXPECT_EQ(m.size(), 3);
  EXPECT_EQ(*m.begin(), 1);
  auto it_end = m.end();
  EXPECT_EQ(*(--it_end), 3);
  EXPECT_EQ(m.empty(), false);
  EXPECT_EQ(m.GetRoot()->data.first, 2);
}

TEST(SetInitListCtor, ordinary3) {
  s21::set<int> set{13, 8, 17, 1, 11, 6, 15, 25, 22, 27};
  std::set<int> std_set{13, 8, 17, 1, 11, 6, 15, 25, 22, 27};

  auto it = set.begin();
  auto std_it = std_set.begin();

  for (; it != set.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
    EXPECT_EQ(*it, *std_it);
    // std::cout << it->first << " " << std_it->first << std::endl;
  }

  it = set.begin();
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
  EXPECT_EQ(set.GetRoot()->data.first, 13);
}

TEST(SetInitListCtor, ordinary4) {
  s21::set<std::string> m{"Hello", "World"};
  EXPECT_EQ(m.size(), 2);
  EXPECT_NE(m.begin(), nullptr);
  EXPECT_NE(m.end(), nullptr);
  EXPECT_EQ(m.empty(), false);
}

TEST(SetInitListCtor, ordinary5) {
  s21::set<std::string> m{"first", "second"};
  EXPECT_EQ(m.size(), 2);
  EXPECT_NE(m.begin(), nullptr);
  EXPECT_NE(m.end(), nullptr);
  EXPECT_EQ(m.empty(), false);

  s21::set<bool> m2{false, true, false};

  EXPECT_EQ(m2.size(), 2);
  EXPECT_NE(m2.begin(), nullptr);
  EXPECT_NE(m2.end(), nullptr);
  EXPECT_EQ(m2.empty(), false);

  std::vector<int> v1{1, 2, 3, 4, 5};
  std::vector<int> v2{6, 7, 8, 9, 10};
  std::vector<int> v3{11, 12, 13, 14, 15};

  s21::set<std::vector<int>> m3{v1, v2, v3};

  EXPECT_EQ(m3.size(), 3);
  EXPECT_NE(m3.begin(), nullptr);
  EXPECT_NE(m3.end(), nullptr);
  EXPECT_EQ(m3.empty(), false);
}

/*

Set(const set &m)

 */

TEST(SetCopyCtor, ordinary1) {
  s21::set<std::string> set{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};

  s21::set<std::string> set2(set);

  EXPECT_EQ(set.size(), 10);
  EXPECT_EQ(*set.begin(), "a");

  auto it_end = set.end();
  EXPECT_EQ(*(--it_end), "j");

  EXPECT_EQ(set2.size(), 10);
  EXPECT_EQ(*set2.begin(), "a");

  auto it_end2 = set2.end();

  EXPECT_EQ(*(--it_end2), "j");

  EXPECT_EQ(*set2.begin(), *set.begin());
  EXPECT_EQ(*(--(set2.end())), *(--(set.end())));
}

/*

set(set &&m)

 */

TEST(SetMoveCtor, ordinary1) {
  s21::set<int> set{13, 8, 17, 1, 11, 6, 15, 25, 22, 27};
  std::set<int> std_set{13, 8, 17, 1, 11, 6, 15, 25, 22, 27};

  EXPECT_EQ(set.size(), 10);
  EXPECT_EQ(*set.begin(), 1);
  auto it_end = set.end();

  EXPECT_EQ(*(--it_end), 27);
  auto begin_to_cmpr = set.begin();

  s21::set<int> set2(std::move(set));

  EXPECT_EQ(set.size(), 0);
  EXPECT_EQ(set.begin(), nullptr);

  EXPECT_EQ(set2.size(), 10);
  EXPECT_EQ(*set2.begin(), 1);
  EXPECT_EQ(set2.begin(), begin_to_cmpr);

  auto it_end2 = set2.end();

  EXPECT_EQ(*(--it_end2), 27);
  auto std_it = std_set.begin();

  for (auto set2_it = set2.begin(); set2_it != set2.end(); ++set2_it) {
    EXPECT_EQ(*set2_it, *std_it);
    ++std_it;
  }
}

/*

operator=(set &&m)

*/

TEST(SetMoveAssignment, ordinary1) {
  s21::set<int> set{13, 8, 17, 1, 11, 6, 15, 25, 22, 27};
  std::set<int> std_set{13, 8, 17, 1, 11, 6, 15, 25, 22, 27};

  EXPECT_EQ(set.size(), 10);
  EXPECT_EQ(*set.begin(), 1);

  auto it_end = set.end();
  EXPECT_EQ(*(--it_end), 27);

  auto begin_to_cmpr = set.begin();

  s21::set<int> set2;

  std::swap(set2, set);

  EXPECT_EQ(set.size(), 0);
  EXPECT_EQ(set.begin(), nullptr);

  EXPECT_EQ(set2.size(), 10);
  EXPECT_EQ(*set2.begin(), 1);
  EXPECT_EQ(set2.begin(), begin_to_cmpr);

  auto it_end2 = set2.end();
  EXPECT_EQ(*(--it_end2), 27);

  auto std_it = std_set.begin();
  for (auto set2_it = set2.begin(); set2_it != set2.end(); ++set2_it) {
    EXPECT_EQ(*set2_it, *std_it);
    ++std_it;
  }
}
#endif