#include "../s21_test.h"

/*

Ctor default

*/
#if 1
TEST(MultiSetCtorDefault, ordinary1) {
  s21::multiset<std::string> m;
  EXPECT_EQ(m.size(), 0);
  EXPECT_EQ(m.begin(), nullptr);
  EXPECT_EQ(m.end(), nullptr);
  EXPECT_EQ(m.empty(), true);
}

/*

InitList ctor

*/

TEST(MultiSetInitListCtor, ordinary1) {
  s21::multiset<int> m{1, 2, 3, 3};
  EXPECT_EQ(m.size(), 4);
  EXPECT_EQ(*m.begin(), 1);
  auto it_end = m.end();
  EXPECT_EQ(*(--it_end), 3);
  EXPECT_EQ(m.empty(), false);
  EXPECT_EQ(m.GetRoot()->data.first, 2);
}

TEST(MultiSetInitListCtor, ordinary2) {
  s21::multiset<int> m{3, 1, 2, 2};
  EXPECT_EQ(m.size(), 4);
  EXPECT_EQ(*m.begin(), 1);
  auto it_end = m.end();
  EXPECT_EQ(*(--it_end), 3);
  EXPECT_EQ(m.empty(), false);
  EXPECT_EQ(m.GetRoot()->data.first, 2);
}

TEST(MultiSetInitListCtor, ordinary3) {
  s21::multiset<int> multiset{13, 8, 17, 1, 11, 6, 15, 25, 22, 27};
  std::multiset<int> std_multiset{13, 8, 17, 1, 11, 6, 15, 25, 22, 27};

  auto it = multiset.begin();
  auto std_it = std_multiset.begin();

  for (; it != multiset.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
    EXPECT_EQ(*it, *std_it);
    // std::cout << it->first << " " << std_it->first << std::endl;
  }

  it = multiset.begin();
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
  EXPECT_EQ(multiset.GetRoot()->data.first, 13);
}

TEST(MultiSetInitListCtor, ordinary4) {
  s21::multiset<std::string> m{"Hello", "World"};
  EXPECT_EQ(m.size(), 2);
  EXPECT_NE(m.begin(), nullptr);
  EXPECT_NE(m.end(), nullptr);
  EXPECT_EQ(m.empty(), false);
}

TEST(MultiSetInitListCtor, ordinary5) {
  s21::multiset<std::string> m{"first", "second"};
  EXPECT_EQ(m.size(), 2);
  EXPECT_NE(m.begin(), nullptr);
  EXPECT_NE(m.end(), nullptr);
  EXPECT_EQ(m.empty(), false);

  s21::multiset<bool> m2{false, true, false};

  EXPECT_EQ(m2.size(), 3);
  EXPECT_NE(m2.begin(), nullptr);
  EXPECT_NE(m2.end(), nullptr);
  EXPECT_EQ(m2.empty(), false);

  std::vector<int> v1{1, 2, 3, 4, 5};
  std::vector<int> v2{6, 7, 8, 9, 10};
  std::vector<int> v3{11, 12, 13, 14, 15};

  s21::multiset<std::vector<int>> m3{v1, v2, v3};

  EXPECT_EQ(m3.size(), 3);
  EXPECT_NE(m3.begin(), nullptr);
  EXPECT_NE(m3.end(), nullptr);
  EXPECT_EQ(m3.empty(), false);
}

/*

MultiSet(const multiset &m)

 */

TEST(MultiSetCopyCtor, ordinary1) {
  s21::multiset<std::string> multiset{"a", "a", "b", "c", "d", "e",
                                      "f", "g", "h", "i", "j"};

  s21::multiset<std::string> multiset2(multiset);

  EXPECT_EQ(multiset.size(), 11);
  EXPECT_EQ(*multiset.begin(), "a");

  auto it_end = multiset.end();
  EXPECT_EQ(*(--it_end), "j");

  EXPECT_EQ(multiset2.size(), 11);
  EXPECT_EQ(*multiset2.begin(), "a");

  auto it_end2 = multiset2.end();

  EXPECT_EQ(*(--it_end2), "j");

  EXPECT_EQ(*multiset2.begin(), *multiset.begin());
  EXPECT_EQ(*(--(multiset2.end())), *(--(multiset.end())));
}

/*

multiset(multiset &&m)

 */

TEST(MultiSetMoveCtor, ordinary1) {
  s21::multiset<int> multiset{13, 8, 17, 1, 11, 6, 15, 25, 22, 27};
  std::multiset<int> std_multiset{13, 8, 17, 1, 11, 6, 15, 25, 22, 27};

  EXPECT_EQ(multiset.size(), 10);
  EXPECT_EQ(*multiset.begin(), 1);
  auto it_end = multiset.end();

  EXPECT_EQ(*(--it_end), 27);
  auto begin_to_cmpr = multiset.begin();

  s21::multiset<int> multiset2(std::move(multiset));

  EXPECT_EQ(multiset.size(), 0);
  EXPECT_EQ(multiset.begin(), nullptr);

  EXPECT_EQ(multiset2.size(), 10);
  EXPECT_EQ(*multiset2.begin(), 1);
  EXPECT_EQ(multiset2.begin(), begin_to_cmpr);

  auto it_end2 = multiset2.end();

  EXPECT_EQ(*(--it_end2), 27);
  auto std_it = std_multiset.begin();

  for (auto multiset2_it = multiset2.begin(); multiset2_it != multiset2.end();
       ++multiset2_it) {
    EXPECT_EQ(*multiset2_it, *std_it);
    ++std_it;
  }
}

/*

operator=(multiset &&m)

*/

TEST(MultiSetMoveAssignment, ordinary1) {
  s21::multiset<int> multiset{13, 8, 17, 1, 11, 6, 15, 25, 22, 27};
  std::multiset<int> std_multiset{13, 8, 17, 1, 11, 6, 15, 25, 22, 27};

  EXPECT_EQ(multiset.size(), 10);
  EXPECT_EQ(*multiset.begin(), 1);

  auto it_end = multiset.end();
  EXPECT_EQ(*(--it_end), 27);

  auto begin_to_cmpr = multiset.begin();

  s21::multiset<int> multiset2;

  std::swap(multiset2, multiset);

  EXPECT_EQ(multiset.size(), 0);
  EXPECT_EQ(multiset.begin(), nullptr);

  EXPECT_EQ(multiset2.size(), 10);
  EXPECT_EQ(*multiset2.begin(), 1);
  EXPECT_EQ(multiset2.begin(), begin_to_cmpr);

  auto it_end2 = multiset2.end();
  EXPECT_EQ(*(--it_end2), 27);

  auto std_it = std_multiset.begin();
  for (auto multiset2_it = multiset2.begin(); multiset2_it != multiset2.end();
       ++multiset2_it) {
    EXPECT_EQ(*multiset2_it, *std_it);
    ++std_it;
  }
}
#endif