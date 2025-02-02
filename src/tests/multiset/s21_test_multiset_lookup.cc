#include "../s21_test.h"

/*
size_type count(const Key& key)
*/

TEST(MultisetCount, ordinary1) {
  s21::multiset<int> multiset{6, 3, 7, 3};
  EXPECT_EQ(multiset.count(3), 2);
  EXPECT_EQ(multiset.count(6), 1);
  EXPECT_EQ(multiset.count(7), 1);
  EXPECT_EQ(multiset.count(1), 0);
}

TEST(MultisetCount, ordinary2) {
  s21::multiset<int> multiset{6, 3, 2, 7, 2, 3, 3};
  EXPECT_EQ(multiset.count(3), 3);
  EXPECT_EQ(multiset.count(6), 1);
  EXPECT_EQ(multiset.count(2), 2);
  EXPECT_EQ(multiset.count(7), 1);
  EXPECT_EQ(multiset.count(90), 0);
}

/*
iterator find(const Key& key)
*/

TEST(MultisetFind, ordinary1) {
  s21::multiset<int> multiset{6, 3, 7, 3};
  EXPECT_EQ(multiset.find(3), multiset.begin());
  EXPECT_EQ(multiset.find(6), ++(++multiset.begin()));
  EXPECT_EQ(multiset.find(7), --multiset.end());
}

TEST(MultisetFind, ordinary2) {
  s21::multiset<int> multiset{6, 3, 2, 7, 2, 3, 3};
  EXPECT_EQ(multiset.find(3), ++(++multiset.begin()));
  EXPECT_EQ(multiset.find(2), +multiset.begin());
  EXPECT_EQ(multiset.find(7), --multiset.end());
}

/*
bool contains(const Key& key)
*/

TEST(MultisetContains, ordinary1) {
  s21::multiset<int> multiset{6, 3, 7, 3};
  EXPECT_EQ(multiset.contains(3), 1);
  EXPECT_EQ(multiset.contains(6), 1);
  EXPECT_EQ(multiset.contains(7), 1);
  EXPECT_EQ(multiset.contains(0), 0);
  EXPECT_EQ(multiset.contains(99), 0);
}

TEST(MultisetContains, ordinary2) {
  s21::multiset<int> multiset{6, 3, 2, 7, 2, 3, 3};
  EXPECT_EQ(multiset.contains(3), 1);
  EXPECT_EQ(multiset.contains(6), 1);
  EXPECT_EQ(multiset.contains(7), 1);
  EXPECT_EQ(multiset.contains(2), 1);
  EXPECT_EQ(multiset.contains(0), 0);
  EXPECT_EQ(multiset.contains(99), 0);
}

/*
std::pair<iterator,iterator> equal_range(const Key& key)
*/
TEST(MultisetEqualRange, ordinary1) {
  s21::multiset<int> multiset{6, 3, 7, 3};
  std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator> range =
      multiset.equal_range(3);
  EXPECT_EQ(range.first, multiset.begin());
  EXPECT_EQ(range.second, ++(++multiset.begin()));
}

TEST(MultisetEqualRange, ordinary2) {
  s21::multiset<int> multiset{6, 3, 7, 3};
  std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator> range =
      multiset.equal_range(4);
  EXPECT_EQ(range.first, --(--multiset.end()));
  EXPECT_EQ(range.second, --(--multiset.end()));
}

TEST(MultisetEqualRange, ordinary3) {
  s21::multiset<int> multiset{6, 3, 7, 3};
  std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator> range =
      multiset.equal_range(8);
  EXPECT_EQ(range.first, multiset.end());
  EXPECT_EQ(range.second, multiset.end());
}

TEST(MultisetEqualRange, ordinary4) {
  s21::multiset<int> multiset{6, 3, 7, 3, 3};
  std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator> range =
      multiset.equal_range(8);
  EXPECT_EQ(range.first, multiset.end());
  EXPECT_EQ(range.second, multiset.end());
}

// TEST(MultisetEqualRange, ordinary5) {
//   std::multiset<int> multiset;
//   auto [start, end] = multiset.equal_range(8);
//   EXPECT_EQ(start, multiset.end());
//   EXPECT_EQ(end, multiset.end());
//   std::cout << multiset.size() << std::endl;
// }

TEST(MultisetEqualRange, ordinary6) {
  s21::multiset<int> multiset;
  std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator> range =
      multiset.equal_range(8);
  EXPECT_EQ(range.first, multiset.end());
  EXPECT_EQ(range.second, multiset.end());
}

/*
iterator lower_bound(const Key& key)
*/

TEST(MultisetLowerBound, ordinary0) {
  s21::multiset<int> multiset;
  EXPECT_EQ(multiset.lower_bound(4), multiset.end());
}

TEST(MultisetLowerBound, ordinary1) {
  s21::multiset<int> multiset{6, 3, 7, 3};
  EXPECT_EQ(*(multiset.lower_bound(4)), 6);
  auto it = multiset.begin();
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  // EXPECT_EQ(it.IsRed(), 0);

  // for (it = multiset.begin(); it != multiset.end(); ++it) {
  //   std::cout << *it << " ";
  // }
  // std::cout << std::endl;
}

TEST(MultisetLowerBound, ordinary2) {
  s21::multiset<int> multiset{6, 3, 7, 2, 3, 3};
  EXPECT_EQ(*(multiset.lower_bound(4)), 6);
  auto it = multiset.begin();
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);

  // EXPECT_EQ(it.IsRed(), 0);

  // for (it = multiset.begin(); it != multiset.end(); ++it) {
  //   std::cout << *it << " ";
  // }
  // std::cout << std::endl;
}

TEST(MultisetLowerBound, ordinary3) {
  s21::multiset<int> multiset{6, 3, 7, 2, 3, 3};
  // EXPECT_EQ(*(multiset.lower_bound(4)), 5);
  auto it = multiset.begin();
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  multiset.insert(3);
  it = multiset.begin();
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 0);

  // for (it = multiset.begin(); it != multiset.end(); ++it) {
  //   std::cout << *it << " ";
  // }
  // std::cout << std::endl;
}

TEST(MultisetLowerBound, ordinary4) {
  s21::multiset<int> multiset{6, 3, 7, 3, 2};
  EXPECT_EQ(*(multiset.lower_bound(3)), 3);
  EXPECT_EQ(*(--multiset.lower_bound(3)), 2);
  auto it = multiset.begin();

  // EXPECT_EQ(it.IsRed(), 0);

  // for (it = multiset.begin(); it != multiset.end(); ++it) {
  //   std::cout << *it << " ";
  // }
  // std::cout << std::endl;
}

TEST(MultisetLowerBound, ordinary5) {
  std::multiset<int> std_multiset{6};
  EXPECT_EQ(std_multiset.lower_bound(7), std_multiset.end());

  s21::multiset<int> multiset{6};
  EXPECT_EQ(multiset.lower_bound(7), multiset.end());
  EXPECT_EQ(multiset.lower_bound(6), multiset.begin());
  EXPECT_EQ(*(multiset.lower_bound(6)), 6);
  std::cout << std::endl;
}

/*
iterator upper_bound(const Key& key)
*/

TEST(MultisetUpperBound, ordinary0) {
  s21::multiset<int> multiset;
  EXPECT_EQ(multiset.upper_bound(4), multiset.end());
}

TEST(MultisetUpperBound, ordinary1) {
  s21::multiset<int> multiset{6, 3, 7, 3, 2};
  EXPECT_EQ(*(multiset.upper_bound(3)), 6);
  EXPECT_EQ(*--multiset.upper_bound(3), 3);
  auto it = multiset.begin();

  // EXPECT_EQ(it.IsRed(), 0);

  // for (it = multiset.begin(); it != multiset.end(); ++it) {
  //   std::cout << *it << " ";
  // }
  // std::cout << std::endl;
}

TEST(MultisetUpperBound, ordinary2) {
  s21::multiset<int> multiset{6};
  EXPECT_EQ(multiset.upper_bound(6), multiset.end());
}