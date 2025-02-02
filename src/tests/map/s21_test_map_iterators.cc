#include "../s21_test.h"

/*
iterator begin()
*/
#if 1
TEST(MapBegin, ordinary1) {
  s21::map<int, std::string> m;

  m.insert(4, "four");
  m.insert(6, "six");
  m.insert(8, "eight");
  m.insert(5, "five");
  m.insert(7, "seven");

  auto it = m.begin();
  auto it_end = m.end();
  it == --it_end;
  it != ++it_end;
  EXPECT_EQ((++it)->first, 5);
  EXPECT_EQ(it++->first, 5);
  EXPECT_EQ(it++->first, 6);
  EXPECT_EQ((++it)->first, 8);
  it++;
  EXPECT_EQ(it, m.end());
}

TEST(MapBegin, ordinary2) {
  s21::map<int, std::string> m;

  m.insert(4, "four");
  m.insert(6, "six");
  m.insert(8, "eight");
  m.insert(5, "five");
  m.insert(7, "seven");

  auto it = m.begin();
  EXPECT_EQ((*it).first, 4);
  EXPECT_EQ((++it)->first, 5);
  EXPECT_EQ(it++->first, 5);
  EXPECT_EQ(it++->first, 6);
  EXPECT_EQ((++it)->first, 8);
  it++;
  EXPECT_EQ(it, m.end());
}

TEST(MapConstBegin, ordinary2) {
  const s21::map<int, std::string> m{
      {4, "four"}, {6, "six"}, {8, "eight"}, {5, "five"}, {7, "seven"}};
  ;
  s21::map<int, std::string>::const_iterator it;
  it = m.begin();
  EXPECT_EQ((*it).first, 4);
  EXPECT_EQ((++it)->first, 5);
  EXPECT_EQ(it++->first, 5);
  EXPECT_EQ(it++->first, 6);
  EXPECT_EQ((++it)->first, 8);
  it++;
  EXPECT_EQ(it == m.end(), 1);
  EXPECT_EQ(it != m.begin(), 1);
  --it;
  EXPECT_EQ(it.IsRed(), false);
}

TEST(MapEnd, ordinary1) {
  s21::map<int, std::string> m;

  m.insert(4, "four");
  m.insert(6, "six");
  m.insert(8, "eight");
  m.insert(5, "five");
  m.insert(7, "seven");

  auto it = m.end();
  EXPECT_EQ((--it)->first, 8);
  EXPECT_EQ((it--)->first, 8);
  EXPECT_EQ((it--)->first, 7);
  EXPECT_EQ((it--)->first, 6);
  EXPECT_EQ((it--)->first, 5);
  EXPECT_EQ(it->first, 4);
  EXPECT_EQ(it, m.begin());
  EXPECT_EQ((*it).first, 4);
}

TEST(MapConstEnd, ordinary1) {
  const s21::map<int, std::string> m{
      {4, "four"}, {6, "six"}, {8, "eight"}, {5, "five"}, {7, "seven"}};

  s21::map<int, std::string>::const_iterator it;
  it = m.end();
  EXPECT_EQ((--it)->first, 8);
  EXPECT_EQ((it--)->first, 8);
  EXPECT_EQ((it--)->first, 7);
  EXPECT_EQ((it--)->first, 6);
  EXPECT_EQ((it--)->first, 5);
  EXPECT_EQ(it->first, 4);
  EXPECT_EQ(it, m.begin());
  EXPECT_EQ((*it).first, 4);
}

/*

++

*/

TEST(MapOperatorpp, ordinary1) {
  s21::map<int, std::string> m;

  m.insert(1, "1");
  m.insert(2, "2");
  m.insert(3, "3");

  auto it = m.begin();

  EXPECT_EQ(it->first, 1);
  EXPECT_EQ((++it)->first, 2);
  EXPECT_EQ((++it)->first, 3);

  it = m.begin();
  m.erase(it);
  it = m.begin();
  EXPECT_EQ((it)->first, 2);
  EXPECT_EQ((it).IsRed(), 0);
  EXPECT_EQ((++it)->first, 3);
  EXPECT_EQ((it).IsRed(), 1);
}
#endif