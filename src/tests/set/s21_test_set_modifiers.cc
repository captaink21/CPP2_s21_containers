#include "../s21_test.h"

/*
void clear()
*/
#if 1
TEST(SetClear, ordinary1) {
  s21::set<int> s;

  s.insert(4);
  s.insert(6);
  s.insert(8);
  s.insert(5);
  s.insert(7);

  auto it = s.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(s.GetRoot()->data.first, 6);

  s.clear();
  auto after_clear_it = s.begin();
  EXPECT_EQ(s.size(), 0);
  EXPECT_EQ(after_clear_it, nullptr);
}

/*
std::pair<iterator, bool> insert(const value_type& value)
*/

TEST(SetInsertV1, ordinary1) {
  s21::set<std::string> s;
  std::set<std::string> std_set;

  s.insert("four");   // 3
  s.insert("six");    // 5
  s.insert("eight");  // 1
  s.insert("five");   // 2
  s.insert("seven");  // 4

  std_set.insert("four");
  std_set.insert("six");
  std_set.insert("eight");
  std_set.insert("five");
  std_set.insert("seven");

  auto it = s.begin();
  auto std_it = std_set.begin();

  for (; it != s.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
  }
  it = s.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(s.GetRoot()->data.first, "four");
}

TEST(SetInsertV1, ordinary2) {
  s21::set<int> m1;
  m1.insert(4);
  m1.insert(5);
  m1.insert(9);
  m1.insert(7);
  m1.insert(6);
  m1.insert(1);
  m1.insert(1);
  m1.insert(8);

  std::set<int> std_set;
  std_set.insert(4);
  std_set.insert(5);
  std_set.insert(9);
  std_set.insert(7);
  std_set.insert(6);
  std_set.insert(1);
  std_set.insert(1);
  std_set.insert(8);

  auto it = m1.begin();
  auto std_it = std_set.begin();

  for (; it != m1.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
    // std::cout << it->first << " " << std_it->first << std::endl;
  }

  it = m1.begin();

  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(m1.GetRoot()->data.first, 5);
}

TEST(SetInsertV1, ordinary3) {
  s21::set<int> set2;
  set2.insert(13);
  set2.insert(8);
  set2.insert(17);
  set2.insert(1);
  set2.insert(11);
  set2.insert(6);
  set2.insert(15);
  set2.insert(25);
  set2.insert(22);
  set2.insert(27);

  std::set<int> std_set;
  std_set.insert(13);
  std_set.insert(8);
  std_set.insert(17);
  std_set.insert(1);
  std_set.insert(11);
  std_set.insert(6);
  std_set.insert(15);
  std_set.insert(25);
  std_set.insert(22);
  std_set.insert(27);

  auto it = set2.begin();
  auto std_it = std_set.begin();

  for (; it != set2.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
    // std::cout << it->first << " " << std_it->first << std::endl;
  }
  it = set2.begin();
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
  EXPECT_EQ(set2.GetRoot()->data.first, 13);
}

TEST(SetInsertV1, ordinary4) {
  s21::set<int> set7 = {61, 52, 85, 20, 55, 76, 93, 16, 71, 81, 90, 101, 65};
  std::set<int> std_set = {61, 52, 85, 20, 55, 76, 93, 16, 71, 81, 90, 101, 65};

  auto it = set7.begin();
  auto std_it = std_set.begin();

  for (; it != set7.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
    // std::cout << it->first << " " << std_it->first << std::endl;
  }

  it = set7.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);
  EXPECT_EQ(set7.GetRoot()->data.first, 61);
}

/*
std::pair<iterator, bool> insert(const Key& key, const T& obj)
*/

TEST(SetInsertV2, ordinary1) {
  s21::set<int> s;
  std::set<int> std_set = {4, 6, 8, 5, 7};

  s.insert(4);
  s.insert(6);
  s.insert(8);
  s.insert(5);
  s.insert(7);

  auto it = s.begin();
  auto std_it = std_set.begin();

  for (; it != s.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
    // std::cout << it->first << " " << std_it->first << " " << it.IsRed()
    //           << std::endl;
  }
  it = s.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(s.GetRoot()->data.first, 6);
}

TEST(SetInsertV2, ordinary2) {
  s21::set<int> m1 = {4, 5, 9, 7, 6, 1, 8};
  std::set<int> std_set = {4, 5, 9, 7, 6, 1, 8};

  auto it = m1.begin();
  auto std_it = std_set.begin();

  for (; it != m1.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
    // std::cout << it->first << " " << std_it->first << std::endl;
  }

  it = m1.begin();

  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(m1.GetRoot()->data.first, 5);
}

TEST(SetInsertV2, ordinary3) {
  s21::set<int> set2 = {13, 8, 17, 1, 11, 6, 15, 25, 22, 27};
  std::set<int> std_set = {13, 8, 17, 1, 11, 6, 15, 25, 22, 27};

  auto it = set2.begin();
  auto std_it = std_set.begin();

  for (; it != set2.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
    // std::cout << it->first << " " << std_it->first << std::endl;
  }
  it = set2.begin();
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
  EXPECT_EQ(set2.GetRoot()->data.first, 13);
}

TEST(SetInsertV2, ordinary4) {
  s21::set<int> set7 = {61, 52, 85, 20, 55, 76, 93, 16, 71, 81, 90, 101, 65};
  std::set<int> std_set = {61, 52, 85, 20, 55, 76, 93, 16, 71, 81, 90, 101, 65};

  auto it = set7.begin();
  auto std_it = std_set.begin();

  for (; it != set7.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
    // std::cout << it->first << " " << std_it->first << std::endl;
  }

  it = set7.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);
  EXPECT_EQ(set7.GetRoot()->data.first, 61);
}

/*
std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
*/

TEST(SetInsertV3, ordinary1) {
  s21::set<int> s = {4, 6, 8, 5, 7, 5};
  std::set<int> std_set = {4, 6, 8, 5, 7, 5};

  auto it = s.begin();
  auto std_it = std_set.begin();

  for (; it != s.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
  }
  it = s.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(s.GetRoot()->data.first, 6);
  EXPECT_EQ(s.size(), std_set.size());
}

TEST(SetInsertV3, ordinary2) {
  s21::set<int> set2 = {13, 8, 17, 1, 11, 6, 15, 25, 22, 27, 13};
  std::set<int> std_set = {13, 8, 17, 1, 11, 6, 15, 25, 22, 27, 13};

  auto it = set2.begin();
  auto std_it = std_set.begin();

  for (; it != set2.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
  }

  it = set2.begin();
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
  EXPECT_EQ(set2.GetRoot()->data.first, 13);
}

/*

Erase

*/

TEST(SetErase, ordinary1) {
  s21::set<int> set2 = {1, 2, 3, 4, 5, 6};
  std::set<int> std_set = {1, 2, 3, 4, 5, 6};

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
  for (int i = 0; i != 2; ++i, ++it, ++std_it) {
  }

  set2.erase(it);
  std_set.erase(std_it);
  it = set2.begin();
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  it = set2.begin();
  std_it = std_set.begin();

  for (; it != set2.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
  }
}

TEST(SetErase, ordinary2) {
  s21::set<int> set2;

  set2.insert(1);
  auto it = set2.begin();
  EXPECT_EQ(it.IsRed(), 0);

  set2.insert(2);
  it = set2.begin();
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  set2.insert(3);

  it = set2.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  it = set2.begin();
  set2.erase(it);
  it = set2.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  set2.insert(5);
  set2.insert(6);
  set2.insert(7);
  set2.insert(8);
  set2.insert(9);

  it = set2.end();
  --it;  // 9
  --it;  // 8
  --it;  // 7
  --it;  // 6
  --it;  // 5
  set2.erase(it);

  it = set2.begin();

  EXPECT_EQ(it++.IsRed(), 0);  // 2
  EXPECT_EQ(it++.IsRed(), 0);  // 3
  EXPECT_EQ(it++.IsRed(), 0);  // 6
  EXPECT_EQ(it++.IsRed(), 1);  // 7
  EXPECT_EQ(it++.IsRed(), 1);  // 8
  EXPECT_EQ(it++.IsRed(), 0);  // 9
}

TEST(SetErase, ordinary3) {
  s21::set<int> set2;

  set2.insert(1);
  auto it = set2.begin();
  EXPECT_EQ(it.IsRed(), 0);

  set2.insert(2);
  it = set2.begin();
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  set2.insert(3);

  it = set2.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  it = set2.begin();
  ++it;
  set2.erase(++it);
  it = set2.begin();

  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);

  set2.insert(5);
  set2.insert(6);
  set2.insert(7);
  set2.insert(8);
  set2.insert(9);

  it = set2.begin();
  ++it;  // 2
  set2.erase(it);

  it = set2.begin();

  EXPECT_EQ(it++.IsRed(), 0);  // 1
  EXPECT_EQ(it++.IsRed(), 0);  // 5
  EXPECT_EQ(it++.IsRed(), 0);  // 6
  EXPECT_EQ(it++.IsRed(), 1);  // 7
  EXPECT_EQ(it++.IsRed(), 1);  // 8
  EXPECT_EQ(it++.IsRed(), 0);  // 9
}

TEST(SetErase, ordinary4) {
  s21::set<int> set2;

  set2.insert({1});
  auto it = set2.begin();
  EXPECT_EQ(it.IsRed(), 0);

  set2.erase(it);

  EXPECT_EQ(set2.empty(), true);
  EXPECT_EQ(set2.size(), 0);
  set2.insert(1);
  it = set2.begin();
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(set2.empty(), false);
  EXPECT_EQ(set2.size(), 1);
}

TEST(SetErase, ordinary5) {
  s21::set<std::string> set2 = {"1", "2", "3", "4", "5", "6"};
  std::set<std::string> std_set = {"1", "2", "3", "4", "5", "6"};

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
  for (int i = 0; i != 2; ++i, ++it, ++std_it) {
  }

  set2.erase(it);
  std_set.erase(std_it);
  it = set2.begin();
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  it = set2.begin();
  std_it = std_set.begin();

  for (; it != set2.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
  }
}

TEST(SetErase, ordinary6) {
  s21::set<std::string> set2;

  set2.insert("1");
  auto it = set2.begin();
  EXPECT_EQ(it.IsRed(), 0);

  set2.insert("2");
  it = set2.begin();
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  set2.insert("3");

  it = set2.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  it = set2.begin();
  set2.erase(it);
  it = set2.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  set2.insert("5");
  set2.insert("6");
  set2.insert("7");
  set2.insert("8");
  set2.insert("9");

  it = set2.end();
  --it;  // 9
  --it;  // 8
  --it;  // 7
  --it;  // 6
  --it;  // 5
  set2.erase(it);

  it = set2.begin();

  EXPECT_EQ(it++.IsRed(), 0);  // 2
  EXPECT_EQ(it++.IsRed(), 0);  // 3
  EXPECT_EQ(it++.IsRed(), 0);  // 6
  EXPECT_EQ(it++.IsRed(), 1);  // 7
  EXPECT_EQ(it++.IsRed(), 1);  // 8
  EXPECT_EQ(it++.IsRed(), 0);  // 9
}

/*

void swap(set& other)

*/

TEST(SetSwap, ordinary1) {
  s21::set<int> m1 = {4, 6, 8, 5, 7};
  s21::set<int> m2 = {1, 6, 5, 4};

  auto it1 = m1.begin();
  auto it2 = m2.begin();
  EXPECT_EQ(m1.size(), 5);
  EXPECT_EQ(m2.size(), 4);
  EXPECT_EQ(*it1, 4);
  EXPECT_EQ(*it2, 1);

  m1.swap(m2);
  auto new_it1 = m1.begin();
  auto new_it2 = m2.begin();
  EXPECT_EQ(*new_it1++, 1);
  EXPECT_EQ(*new_it1++, 4);
  EXPECT_EQ(*new_it1++, 5);
  EXPECT_EQ(*new_it1, 6);

  EXPECT_EQ(*new_it2++, 4);
  EXPECT_EQ(*new_it2++, 5);
  EXPECT_EQ(*new_it2++, 6);
  EXPECT_EQ(*new_it2++, 7);
  EXPECT_EQ(*new_it2, 8);
  EXPECT_EQ(m1.size(), 4);
  EXPECT_EQ(m2.size(), 5);
}

/*

Merge

*/

TEST(SetMerge, ordinary1) {
  s21::set<int> ma{1, 5, 10};
  s21::set<int> mb{2, 4, 5, 8};
  auto it = mb.begin();
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  s21::set<int> u;
  u.merge(ma);

  EXPECT_EQ(u.size(), 3);
  EXPECT_EQ(ma.size(), 0);
  it = u.begin();

  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it, 10);

  it = u.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  u.merge(mb);
  EXPECT_EQ(u.size(), 6);
  EXPECT_EQ(mb.size(), 1);
  it = mb.end();
  EXPECT_EQ(*(--it), 5);

  EXPECT_EQ(it.IsRed(), 0);

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

TEST(SetMerge, ordinary2) {
  s21::set<int> ma{1, 5, 10, 2, 4, 8};
  s21::set<int> mb{};

  s21::set<int> u;
  u.merge(ma);
  EXPECT_EQ(u.size(), 6);
  EXPECT_EQ(ma.size(), 0);
  auto it = u.begin();

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

  u.merge(mb);
  EXPECT_EQ(u.size(), 6);
  EXPECT_EQ(mb.size(), 0);

  it = u.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);

  it = u.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it++, 8);
  EXPECT_EQ(*it, 10);
}

TEST(SetMerge, ordinary3) {
  s21::set<int> ma{1, 5, 10, 2, 4, 8};
  s21::set<int> mb{};

  s21::set<int> u;
  u.merge(mb);
  EXPECT_EQ(u.size(), 0);
  EXPECT_EQ(mb.size(), 0);
  auto it = u.begin();

  u.merge(ma);
  EXPECT_EQ(u.size(), 6);
  EXPECT_EQ(ma.size(), 0);

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

TEST(SetMerge, ordinary4) {
  s21::set<int> ma{1, 5, 10};
  s21::set<int> mb{2, 4, 5, 8};

  auto it = mb.begin();
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  ma.merge(mb);
  EXPECT_EQ(ma.size(), 6);
  EXPECT_EQ(mb.size(), 1);
  it = mb.end();
  EXPECT_EQ(*--it, 5);

  it = mb.begin();
  EXPECT_EQ(it.IsRed(), 0);

  it = ma.begin();
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

TEST(SetMerge, ordinary5) {
  s21::set<int> ma{1, 5, 10};
  s21::set<int> mb{2, 4, 5, 8};

  mb.merge(ma);
  EXPECT_EQ(mb.size(), 6);
  EXPECT_EQ(ma.size(), 1);
  auto it = ma.end();
  EXPECT_EQ(*--it, 5);

  it = ma.begin();
  EXPECT_EQ(it.IsRed(), 0);

  it = mb.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);

  it = mb.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it++, 8);
  EXPECT_EQ(*it, 10);
}

TEST(SetInsertMany, ordinary1) {
  s21::set<int> m1;

  m1.insert_many(4, 5, 9, 7, 6, 1, 1, 8);

  std::set<int> std_set;
  std_set.insert(4);
  std_set.insert(5);
  std_set.insert(9);
  std_set.insert(7);
  std_set.insert(6);
  std_set.insert(1);
  std_set.insert(1);
  std_set.insert(8);

  auto it = m1.begin();
  auto std_it = std_set.begin();

  for (; it != m1.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
    // std::cout << it->first << " " << std_it->first << std::endl;
  }

  it = m1.begin();

  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(m1.GetRoot()->data.first, 5);
}

TEST(SetInsertMany, ordinary2) {
  s21::set<int> m1;
  int a = 4, b = 5, c = 9, d = 7, e = 6, f = 1, g = 1, h = 8;
  m1.insert_many(a, b, c, d, e, f, g, h);

  std::set<int> std_set;
  std_set.insert(4);
  std_set.insert(5);
  std_set.insert(9);
  std_set.insert(7);
  std_set.insert(6);
  std_set.insert(1);
  std_set.insert(1);
  std_set.insert(8);

  auto it = m1.begin();
  auto std_it = std_set.begin();

  for (; it != m1.end(); ++it, ++std_it) {
    EXPECT_EQ(*it, *std_it);
    // std::cout << it->first << " " << std_it->first << std::endl;
  }

  it = m1.begin();

  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(m1.GetRoot()->data.first, 5);
}

TEST(SetInsertMany, ordinary3) {
  s21::set<int> m1;

  m1.insert_many();
  EXPECT_EQ(m1.size(), 0);
  EXPECT_EQ(m1.empty(), true);
}

#endif