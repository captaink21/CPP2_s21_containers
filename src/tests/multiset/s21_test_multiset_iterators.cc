#include "../s21_test.h"

/*
iterator begin()
*/
#if 1
TEST(MultisetBegin, ordinary1) {
  s21::multiset<int> s;

  s.insert(4);
  s.insert(6);
  s.insert(8);
  s.insert(5);
  s.insert(7);
  s.insert(6);
  s.insert(4);

  auto it = s.begin();
  auto it_end = s.end();
  it == --it_end;
  it != ++it_end;
  EXPECT_EQ(*(++it), 4);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ((*++it), 6);
  it++;
  EXPECT_EQ(*it++, 7);
  EXPECT_EQ(*it++, 8);
  EXPECT_EQ(it, s.end());
}

TEST(MultisetBegin, ordinary2) {
  s21::multiset<int> s{4, 6, 8, 5, 7, 8, 8};

  auto it = s.begin();
  EXPECT_EQ(*it, 4);
  EXPECT_EQ(*++it, 5);
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it++, 6);
  EXPECT_EQ(*++it, 8);
  EXPECT_EQ(*++it, 8);
  EXPECT_EQ(*++it, 8);
  it++;
  EXPECT_EQ(it, s.end());
}

TEST(MultisetEnd, ordinary1) {
  s21::multiset<int> s{4, 6, 8, 5, 7};

  auto it = s.end();
  EXPECT_EQ(*(--it), 8);
  EXPECT_EQ(*(it--), 8);
  EXPECT_EQ(*(it--), 7);
  EXPECT_EQ(*(it--), 6);
  EXPECT_EQ(*(it--), 5);
  EXPECT_EQ(*it, 4);
  EXPECT_EQ(*it, *s.begin());
  EXPECT_EQ(*it, 4);
}

/*

++

*/

TEST(MultiSetOperatorpp, ordinary1) {
  s21::multiset<int> s{1, 1, 2, 3, 3};

  auto it = s.begin();

  EXPECT_EQ(*it, 1);
  EXPECT_EQ(*(++it), 1);
  EXPECT_EQ(*(++it), 2);
  EXPECT_EQ(*(++it), 3);
  EXPECT_EQ(*(++it), 3);
  it = s.begin();
  EXPECT_EQ((it++).IsRed(), 0);
  EXPECT_EQ((it++).IsRed(), 0);
  EXPECT_EQ((it++).IsRed(), 1);
  EXPECT_EQ((it++).IsRed(), 0);
  EXPECT_EQ((it++).IsRed(), 1);

  it = --s.end();
  s.erase(it);
  it = --s.end();
  EXPECT_EQ((it).IsRed(), 0);
  EXPECT_EQ(*(it), 3);
  EXPECT_EQ(*(--it), 2);
  EXPECT_EQ((it).IsRed(), 1);
}
#endif