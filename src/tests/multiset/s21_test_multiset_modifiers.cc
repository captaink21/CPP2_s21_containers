#include "../s21_test.h"

/*
void clear()
*/
TEST(MultsetClear, ordinary1) {
  s21::multiset<int> m;

  m.insert(4);
  m.insert(6);
  m.insert(8);
  m.insert(5);
  m.insert(7);

  auto it = m.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(m.GetRoot()->data.first, 6);

  m.clear();
  auto afte_clear_it = m.begin();
  EXPECT_EQ(m.size(), 0);
  EXPECT_EQ(afte_clear_it, nullptr);
}

/*
iterator insert(const value_type& value)
*/
TEST(MultsetInsert, ordinary1) {
  s21::multiset<int> m;

  m.insert(4);
  m.insert(6);
  m.insert(8);
  m.insert(5);
  m.insert(7);

  auto it = m.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(m.GetRoot()->data.first, 6);

  m.insert(6);
  it = m.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);
  EXPECT_EQ(m.GetRoot()->data.first, 6);

  //   for (it = m.begin(); it != m.end(); ++it) {
  //     std::cout << *it << " - " << it.IsRed() << std::endl;
  //   }

  m.clear();
  auto afte_clear_it = m.begin();
  EXPECT_EQ(m.size(), 0);
  EXPECT_EQ(afte_clear_it, nullptr);
}

TEST(MultsetInsert, ordinary2) {
  s21::multiset<int> ma{1, 5, 10, 2, 4, 8};

  auto it = ma.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);

  it = ma.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it++, 8);
  EXPECT_EQ(*it, 10);
}

/*
void erase(iterator pos)
*/
TEST(MultisetErase, ordinary1) {
  s21::multiset<int> set2 = {1, 2, 2, 3, 3, 3};
  std::multiset<int> std_set = {1, 2, 2, 3, 3, 3};

  auto it = set2.begin();
  auto std_it = std_set.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  it = set2.begin();
  std_it = std_set.begin();

  set2.erase(++it);
  std_set.erase(++std_it);
  it = set2.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);

  it = set2.begin();
  std_it = std_set.begin();
  for (; it != set2.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
  }
}

/*
void swap(multiset& other)
*/

TEST(MultisetSwap, ordinary1) {
  s21::multiset<int> m1 = {4, 6, 6, 5, 7, 7};
  s21::multiset<int> m2 = {1, 6, 4, 4};

  auto it1 = m1.begin();
  auto it2 = m2.begin();
  EXPECT_EQ(m1.size(), 6);
  EXPECT_EQ(m2.size(), 4);
  EXPECT_EQ(*it1, 4);
  EXPECT_EQ(*it2, 1);

  m1.swap(m2);
  auto new_it1 = m1.begin();
  auto new_it2 = m2.begin();
  EXPECT_EQ(*new_it1++, 1);
  EXPECT_EQ(*new_it1++, 4);
  EXPECT_EQ(*new_it1++, 4);
  EXPECT_EQ(*new_it1, 6);

  EXPECT_EQ(*new_it2++, 4);
  EXPECT_EQ(*new_it2++, 5);
  EXPECT_EQ(*new_it2++, 6);
  EXPECT_EQ(*new_it2++, 6);
  EXPECT_EQ(*new_it2++, 7);
  EXPECT_EQ(*new_it2, 7);
  EXPECT_EQ(m1.size(), 4);
  EXPECT_EQ(m2.size(), 6);
}

/*

insert many

*/

TEST(MultsetInsertMany, ordinary1) {
  s21::multiset<int> m;

  m.insert_many(4, 6, 8, 5, 7);

  auto it = m.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(m.GetRoot()->data.first, 6);

  m.insert(6);
  it = m.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);
  EXPECT_EQ(m.GetRoot()->data.first, 6);

  //   for (it = m.begin(); it != m.end(); ++it) {
  //     std::cout << *it << " - " << it.IsRed() << std::endl;
  //   }

  m.clear();
  auto afte_clear_it = m.begin();
  EXPECT_EQ(m.size(), 0);
  EXPECT_EQ(afte_clear_it, nullptr);
}

TEST(MultsetInsertMany, ordinary2) {
  s21::multiset<int> m;
  int a = 4, b = 6, c = 8, d = 5, e = 7;
  m.insert_many(a, b, c, d, e);

  auto it = m.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(m.GetRoot()->data.first, 6);

  m.insert(6);
  it = m.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);
  EXPECT_EQ(m.GetRoot()->data.first, 6);

  //   for (it = m.begin(); it != m.end(); ++it) {
  //     std::cout << *it << " - " << it.IsRed() << std::endl;
  //   }

  m.clear();
  auto afte_clear_it = m.begin();
  EXPECT_EQ(m.size(), 0);
  EXPECT_EQ(afte_clear_it, nullptr);
}

TEST(MultsetInsertMany, ordinary3) {
  s21::multiset<int> m1;

  m1.insert_many();
  EXPECT_EQ(m1.size(), 0);
  EXPECT_EQ(m1.empty(), true);
}

/*

Merge

*/

TEST(MultsetMerge, ordinary1) {
  s21::multiset<int> m1 = {2, 3, 3, 4, 6, 7};
  s21::multiset<int> m2 = {1, 3, 3, 4};

  auto it = m1.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  it = m2.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  m1.merge(m2);

  it = m1.begin();

  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);

  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);

  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
}

TEST(MultiSetMerge, ordinary2) {
  s21::multiset<int> ma{1, 5, 10};
  s21::multiset<int> mb{2, 4, 8};

  s21::multiset<int> u;
  u.merge(ma);

  EXPECT_EQ(u.size(), 3);
  EXPECT_EQ(ma.size(), 0);
  auto it = u.begin();

  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it, 10);

  it = u.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  u.merge(mb);
  EXPECT_EQ(u.size(), 6);
  EXPECT_EQ(mb.size(), 0);

  it = u.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);

  it = u.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it++, 8);
  EXPECT_EQ(*it, 10);
}

TEST(MultiSetMerge, ordinary3) {
  s21::multiset<int> ma{1, 5, 10};
  s21::multiset<int> mb{2};

  s21::multiset<int> u;
  u.merge(ma);

  EXPECT_EQ(u.size(), 3);
  EXPECT_EQ(ma.size(), 0);
  auto it = u.begin();

  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it, 10);

  it = u.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);
  u.merge(mb);
}
