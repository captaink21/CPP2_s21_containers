#include "../s21_test.h"

/*
iterator begin()
*/
#if 1
TEST(SetBegin, ordinary1) {
  s21::set<int> s;

  s.insert(4);
  s.insert(6);
  s.insert(8);
  s.insert(5);
  s.insert(7);

  auto it = s.begin();
  auto it_end = s.end();
  it == --it_end;
  it != ++it_end;
  EXPECT_EQ(*(++it), 5);
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it++, 6);
  EXPECT_EQ((*++it), 8);
  it++;
  EXPECT_EQ(it, s.end());
}

TEST(SetBegin, ordinary2) {
  s21::set<int> s{4, 6, 8, 5, 7};

  auto it = s.begin();
  EXPECT_EQ(*it, 4);
  EXPECT_EQ(*++it, 5);
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it++, 6);
  EXPECT_EQ(*++it, 8);
  it++;
  EXPECT_EQ(it, s.end());
}

TEST(SetConstBegin, ordinary1) {
  int a = 6;
  const s21::set<int> s{4, a, 8, 5, 7};

  s21::set<int>::const_iterator it;
  it = s.begin();
  EXPECT_EQ(*it, 4);
  EXPECT_EQ(*++it, 5);
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it++, 6);
  EXPECT_EQ(*++it, 8);
  it++;
  EXPECT_EQ(it, s.end());
}

/*
iterator end()
*/

TEST(SetEnd, ordinary1) {
  s21::set<int> s{4, 6, 8, 5, 7};

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

TEST(SetConstEnd, ordinary1) {
  const s21::set<int> s{4, 6, 8, 5, 7};

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

TEST(SetOperatorpp, ordinary1) {
  s21::set<int> s{1, 2, 3};

  auto it = s.begin();

  EXPECT_EQ(*it, 1);
  EXPECT_EQ(*(++it), 2);
  EXPECT_EQ(*(++it), 3);

  it = s.begin();
  s.erase(it);
  it = s.begin();
  EXPECT_EQ(*(it), 2);
  EXPECT_EQ((it).IsRed(), 0);
  EXPECT_EQ(*(++it), 3);
  EXPECT_EQ((it).IsRed(), 1);
}

#endif