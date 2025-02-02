#include "../s21_test.h"

#if 1
/*
void clear()
*/
TEST(MapClear, ordinary1) {
  s21::map<int, std::string> m;

  m.insert(std::pair<int, std::string>(4, "four"));
  m.insert(std::pair<int, std::string>(6, "six"));
  m.insert(std::pair<int, std::string>(8, "eight"));
  m.insert(std::pair<int, std::string>(5, "five"));
  m.insert(std::pair<int, std::string>(7, "seven"));

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
std::pair<iterator, bool> insert(const value_type& value)
*/

TEST(MapInsertV1, ordinary1) {
  s21::map<int, std::string> m;
  std::map<int, std::string> std_map;

  m.insert(std::pair<int, std::string>(4, "four"));
  m.insert(std::pair<int, std::string>(6, "six"));
  m.insert(std::pair<int, std::string>(8, "eight"));
  m.insert(std::pair<int, std::string>(5, "five"));
  m.insert(std::pair<int, std::string>(7, "seven"));

  std_map.insert(std::pair<int, std::string>(4, "four"));
  std_map.insert(std::pair<int, std::string>(6, "six"));
  std_map.insert(std::pair<int, std::string>(8, "eight"));
  std_map.insert(std::pair<int, std::string>(5, "five"));
  std_map.insert(std::pair<int, std::string>(7, "seven"));

  auto it = m.begin();
  auto std_it = std_map.begin();

  for (; it != m.end(); ++it, ++std_it) {
    EXPECT_EQ(it->first, std_it->first);
    EXPECT_EQ(it->second, std_it->second);
  }
  it = m.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(m.GetRoot()->data.first, 6);
}

TEST(MapInsertV1, ordinary2) {
  s21::map<int, std::string> m1;
  m1.insert(std::pair<int, std::string>(4, "4"));
  m1.insert(std::pair<int, std::string>(5, "5"));
  m1.insert(std::pair<int, std::string>(9, "9"));
  m1.insert(std::pair<int, std::string>(7, "7"));
  m1.insert(std::pair<int, std::string>(6, "6"));
  m1.insert(std::pair<int, std::string>(1, "1"));
  m1.insert(std::pair<int, std::string>(1, "1"));
  m1.insert(std::pair<int, std::string>(8, "8"));

  std::map<int, std::string> std_map;
  std_map.insert(std::pair<int, std::string>(4, "4"));
  std_map.insert(std::pair<int, std::string>(5, "5"));
  std_map.insert(std::pair<int, std::string>(9, "9"));
  std_map.insert(std::pair<int, std::string>(7, "7"));
  std_map.insert(std::pair<int, std::string>(6, "6"));
  std_map.insert(std::pair<int, std::string>(1, "1"));
  std_map.insert(std::pair<int, std::string>(1, "1"));
  std_map.insert(std::pair<int, std::string>(8, "8"));

  auto it = m1.begin();
  auto std_it = std_map.begin();

  for (; it != m1.end(); ++it, ++std_it) {
    EXPECT_EQ(it->first, std_it->first);
    EXPECT_EQ(it->second, std_it->second);
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

TEST(MapInsertV1, ordinary3) {
  s21::map<int, std::string> map2;
  map2.insert(std::pair<int, std::string>(13, "13"));
  map2.insert(std::pair<int, std::string>(8, "8"));
  map2.insert(std::pair<int, std::string>(17, "17"));
  map2.insert(std::pair<int, std::string>(1, "1"));
  map2.insert(std::pair<int, std::string>(11, "11"));
  map2.insert(std::pair<int, std::string>(6, "6"));
  map2.insert(std::pair<int, std::string>(15, "15"));
  map2.insert(std::pair<int, std::string>(25, "25"));
  map2.insert(std::pair<int, std::string>(22, "22"));
  map2.insert(std::pair<int, std::string>(27, "27"));

  std::map<int, std::string> std_map;
  std_map.insert(std::pair<int, std::string>(13, "13"));
  std_map.insert(std::pair<int, std::string>(8, "8"));
  std_map.insert(std::pair<int, std::string>(17, "17"));
  std_map.insert(std::pair<int, std::string>(1, "1"));
  std_map.insert(std::pair<int, std::string>(11, "11"));
  std_map.insert(std::pair<int, std::string>(6, "6"));
  std_map.insert(std::pair<int, std::string>(15, "15"));
  std_map.insert(std::pair<int, std::string>(25, "25"));
  std_map.insert(std::pair<int, std::string>(22, "22"));
  std_map.insert(std::pair<int, std::string>(27, "27"));

  auto it = map2.begin();
  auto std_it = std_map.begin();

  for (; it != map2.end(); ++it, ++std_it) {
    EXPECT_EQ(it->first, std_it->first);
    EXPECT_EQ(it->second, std_it->second);
    // std::cout << it->first << " " << std_it->first << std::endl;
  }
  it = map2.begin();
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
  EXPECT_EQ(map2.GetRoot()->data.first, 13);
}

TEST(MapInsertV1, ordinary4) {
  s21::map<int, std::string> map7;
  map7.insert(std::pair<int, std::string>(61, "61"));
  map7.insert(std::pair<int, std::string>(52, "52"));
  map7.insert(std::pair<int, std::string>(85, "85"));
  map7.insert(std::pair<int, std::string>(20, "20"));
  map7.insert(std::pair<int, std::string>(55, "55"));
  map7.insert(std::pair<int, std::string>(76, "76"));
  map7.insert(std::pair<int, std::string>(93, "93"));
  map7.insert(std::pair<int, std::string>(16, "16"));
  map7.insert(std::pair<int, std::string>(71, "71"));
  map7.insert(std::pair<int, std::string>(81, "81"));
  map7.insert(std::pair<int, std::string>(90, "90"));
  map7.insert(std::pair<int, std::string>(101, "101"));
  map7.insert(std::pair<int, std::string>(65, "65"));

  std::map<int, std::string> std_map;
  std_map.insert(std::pair<int, std::string>(61, "61"));
  std_map.insert(std::pair<int, std::string>(52, "52"));
  std_map.insert(std::pair<int, std::string>(85, "85"));
  std_map.insert(std::pair<int, std::string>(20, "20"));
  std_map.insert(std::pair<int, std::string>(55, "55"));
  std_map.insert(std::pair<int, std::string>(76, "76"));
  std_map.insert(std::pair<int, std::string>(93, "93"));
  std_map.insert(std::pair<int, std::string>(16, "16"));
  std_map.insert(std::pair<int, std::string>(71, "71"));
  std_map.insert(std::pair<int, std::string>(81, "81"));
  std_map.insert(std::pair<int, std::string>(90, "90"));
  std_map.insert(std::pair<int, std::string>(101, "101"));
  std_map.insert(std::pair<int, std::string>(65, "65"));

  auto it = map7.begin();
  auto std_it = std_map.begin();

  for (; it != map7.end(); ++it, ++std_it) {
    EXPECT_EQ(it->first, std_it->first);
    EXPECT_EQ(it->second, std_it->second);
    // std::cout << it->first << " " << std_it->first << std::endl;
  }

  it = map7.begin();
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
  EXPECT_EQ(map7.GetRoot()->data.first, 61);
}

/*
std::pair<iterator, bool> insert(const Key& key, const T& obj)
*/

TEST(MapInsertV2, ordinary1) {
  s21::map<int, std::string> m;
  std::map<int, std::string> std_map;

  m.insert(4, "four");
  m.insert(6, "six");
  m.insert(8, "eight");
  m.insert(5, "five");
  m.insert(7, "seven");

  std_map.insert(std::pair<int, std::string>(4, "four"));
  std_map.insert(std::pair<int, std::string>(6, "six"));
  std_map.insert(std::pair<int, std::string>(8, "eight"));
  std_map.insert(std::pair<int, std::string>(5, "five"));
  std_map.insert(std::pair<int, std::string>(7, "seven"));

  auto it = m.begin();
  auto std_it = std_map.begin();

  for (; it != m.end(); ++it, ++std_it) {
    EXPECT_EQ(it->first, std_it->first);
    EXPECT_EQ(it->second, std_it->second);
    // std::cout << it->first << " " << std_it->first << " " << it.IsRed()
    //           << std::endl;
  }
  it = m.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(m.GetRoot()->data.first, 6);
}

TEST(MapInsertV2, ordinary2) {
  s21::map<int, std::string> m1;
  m1.insert(4, "4");
  m1.insert(5, "5");
  m1.insert(9, "9");
  m1.insert(7, "7");
  m1.insert(6, "6");
  m1.insert(1, "1");
  m1.insert(1, "1");
  m1.insert(8, "8");

  std::map<int, std::string> std_map;
  std_map.insert(std::pair<int, std::string>(4, "4"));
  std_map.insert(std::pair<int, std::string>(5, "5"));
  std_map.insert(std::pair<int, std::string>(9, "9"));
  std_map.insert(std::pair<int, std::string>(7, "7"));
  std_map.insert(std::pair<int, std::string>(6, "6"));
  std_map.insert(std::pair<int, std::string>(1, "1"));
  std_map.insert(std::pair<int, std::string>(1, "1"));
  std_map.insert(std::pair<int, std::string>(8, "8"));

  auto it = m1.begin();
  auto std_it = std_map.begin();

  for (; it != m1.end(); ++it, ++std_it) {
    EXPECT_EQ(it->first, std_it->first);
    EXPECT_EQ(it->second, std_it->second);
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

TEST(MapInsertV2, ordinary3) {
  s21::map<int, std::string> map2;
  map2.insert(13, "13");
  map2.insert(8, "8");
  map2.insert(17, "17");
  map2.insert(1, "1");
  map2.insert(11, "11");
  map2.insert(6, "6");
  map2.insert(15, "15");
  map2.insert(25, "25");
  map2.insert(22, "22");
  map2.insert(27, "27");

  std::map<int, std::string> std_map;
  std_map.insert(std::pair<int, std::string>(13, "13"));
  std_map.insert(std::pair<int, std::string>(8, "8"));
  std_map.insert(std::pair<int, std::string>(17, "17"));
  std_map.insert(std::pair<int, std::string>(1, "1"));
  std_map.insert(std::pair<int, std::string>(11, "11"));
  std_map.insert(std::pair<int, std::string>(6, "6"));
  std_map.insert(std::pair<int, std::string>(15, "15"));
  std_map.insert(std::pair<int, std::string>(25, "25"));
  std_map.insert(std::pair<int, std::string>(22, "22"));
  std_map.insert(std::pair<int, std::string>(27, "27"));

  auto it = map2.begin();
  auto std_it = std_map.begin();

  for (; it != map2.end(); ++it, ++std_it) {
    EXPECT_EQ(it->first, std_it->first);
    EXPECT_EQ(it->second, std_it->second);
    // std::cout << it->first << " " << std_it->first << std::endl;
  }
  it = map2.begin();
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
  EXPECT_EQ(map2.GetRoot()->data.first, 13);
}

TEST(MapInsertV2, ordinary4) {
  s21::map<int, std::string> map7;
  map7.insert(61, "61");
  map7.insert(52, "52");
  map7.insert(85, "85");
  map7.insert(20, "20");
  map7.insert(55, "55");
  map7.insert(76, "76");
  map7.insert(93, "93");
  map7.insert(16, "16");
  map7.insert(71, "71");
  map7.insert(81, "81");
  map7.insert(90, "90");
  map7.insert(101, "101");
  map7.insert(65, "65");

  std::map<int, std::string> std_map;
  std_map.insert(std::pair<int, std::string>(61, "61"));
  std_map.insert(std::pair<int, std::string>(52, "52"));
  std_map.insert(std::pair<int, std::string>(85, "85"));
  std_map.insert(std::pair<int, std::string>(20, "20"));
  std_map.insert(std::pair<int, std::string>(55, "55"));
  std_map.insert(std::pair<int, std::string>(76, "76"));
  std_map.insert(std::pair<int, std::string>(93, "93"));
  std_map.insert(std::pair<int, std::string>(16, "16"));
  std_map.insert(std::pair<int, std::string>(71, "71"));
  std_map.insert(std::pair<int, std::string>(81, "81"));
  std_map.insert(std::pair<int, std::string>(90, "90"));
  std_map.insert(std::pair<int, std::string>(101, "101"));
  std_map.insert(std::pair<int, std::string>(65, "65"));

  auto it = map7.begin();
  auto std_it = std_map.begin();

  for (; it != map7.end(); ++it, ++std_it) {
    EXPECT_EQ(it->first, std_it->first);
    EXPECT_EQ(it->second, std_it->second);
    // std::cout << it->first << " " << std_it->first << std::endl;
  }

  it = map7.begin();
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
  EXPECT_EQ(map7.GetRoot()->data.first, 61);
}

/*
std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
*/

TEST(MapInsertV3, ordinary1) {
  s21::map<int, std::string> m;
  std::map<int, std::string> std_map;

  m.insert_or_assign(4, "four");
  m.insert_or_assign(6, "six");
  m.insert_or_assign(8, "eight");
  m.insert_or_assign(5, "five");
  m.insert_or_assign(7, "seven");
  m.insert_or_assign(5, "new five");

  std_map.insert_or_assign(4, "four");
  std_map.insert_or_assign(6, "six");
  std_map.insert_or_assign(8, "eight");
  std_map.insert_or_assign(5, "five");
  std_map.insert_or_assign(7, "seven");
  std_map.insert_or_assign(5, "new five");

  auto it = m.begin();
  auto std_it = std_map.begin();

  for (; it != m.end(); ++it, ++std_it) {
    EXPECT_EQ(it->first, std_it->first);
    EXPECT_EQ(it->second, std_it->second);
  }
  it = m.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(m.GetRoot()->data.first, 6);
  EXPECT_EQ(m.size(), std_map.size());
  it = m.begin();
  ++it;
  EXPECT_EQ(it->second, "new five");
}

TEST(MapInsertV3, ordinary2) {
  s21::map<int, std::string> map2;
  map2.insert_or_assign(13, "13");
  map2.insert_or_assign(8, "8");
  map2.insert_or_assign(17, "17");
  map2.insert_or_assign(1, "1");
  map2.insert_or_assign(11, "11");
  map2.insert_or_assign(6, "6");
  map2.insert_or_assign(15, "15");
  map2.insert_or_assign(25, "25");
  map2.insert_or_assign(22, "22");
  map2.insert_or_assign(27, "27");
  map2.insert_or_assign(13, "root new second value");

  std::map<int, std::string> std_map;
  std_map.insert_or_assign(13, "13");
  std_map.insert_or_assign(8, "8");
  std_map.insert_or_assign(17, "17");
  std_map.insert_or_assign(1, "1");
  std_map.insert_or_assign(11, "11");
  std_map.insert_or_assign(6, "6");
  std_map.insert_or_assign(15, "15");
  std_map.insert_or_assign(25, "25");
  std_map.insert_or_assign(22, "22");
  std_map.insert_or_assign(27, "27");
  std_map.insert_or_assign(13, "root new second value");

  auto it = map2.begin();
  auto std_it = std_map.begin();

  for (; it != map2.end(); ++it, ++std_it) {
    EXPECT_EQ(it->first, std_it->first);
    EXPECT_EQ(it->second, std_it->second);
  }
  it = map2.begin();
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
  EXPECT_EQ(map2.GetRoot()->data.first, 13);
  EXPECT_EQ(map2.GetRoot()->data.second, "root new second value");
}

/*

Erase

*/

TEST(MapErase, ordinary1) {
  s21::map<int, std::string> map2;
  std::map<int, std::string> std_map;

  map2.insert({1, "first"});
  map2.insert({2, "second"});
  map2.insert({3, "third"});
  map2.insert({4, "fourth"});
  map2.insert({5, "fifth"});
  map2.insert({6, "sixth"});

  std_map.insert({1, "first"});
  std_map.insert({2, "second"});
  std_map.insert({3, "third"});
  std_map.insert({4, "fourth"});
  std_map.insert({5, "fifth"});
  std_map.insert({6, "sixth"});

  auto it = map2.begin();
  auto std_it = std_map.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  it = map2.begin();
  std_it = std_map.begin();

  map2.erase(++it);
  std_map.erase(++std_it);
  it = map2.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);

  it = map2.begin();
  std_it = std_map.begin();
  for (int i = 0; i != 2; ++i, ++it, ++std_it) {
  }

  map2.erase(it);
  std_map.erase(std_it);
  it = map2.begin();
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  it = map2.begin();
  std_it = std_map.begin();

  for (; it != map2.end(); ++it, ++std_it) {
    EXPECT_EQ(it->first, std_it->first);
    EXPECT_EQ(it->second, std_it->second);
  }
}

TEST(MapErase, ordinary2) {
  s21::map<int, std::string> map2;

  map2.insert({1, "first"});
  auto it = map2.begin();
  EXPECT_EQ(it.IsRed(), 0);

  map2.insert({2, "second"});
  it = map2.begin();
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  map2.insert({3, "third"});

  it = map2.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  it = map2.begin();
  map2.erase(it);
  it = map2.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  map2.insert({5, "fifth"});
  map2.insert({6, "sixth"});
  map2.insert({7, "seventh"});
  map2.insert({8, "eighth"});
  map2.insert({9, "ninth"});

  it = map2.end();
  --it;  // 9
  --it;  // 8
  --it;  // 7
  --it;  // 6
  --it;  // 5
  map2.erase(it);

  it = map2.begin();

  EXPECT_EQ(it++.IsRed(), 0);  // 2
  EXPECT_EQ(it++.IsRed(), 0);  // 3
  EXPECT_EQ(it++.IsRed(), 0);  // 6
  EXPECT_EQ(it++.IsRed(), 1);  // 7
  EXPECT_EQ(it++.IsRed(), 1);  // 8
  EXPECT_EQ(it++.IsRed(), 0);  // 9
}

TEST(MapErase, ordinary3) {
  s21::map<int, std::string> map2;

  map2.insert({1, "first"});
  auto it = map2.begin();
  EXPECT_EQ(it.IsRed(), 0);

  map2.insert({2, "second"});
  it = map2.begin();
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  map2.insert({3, "third"});

  it = map2.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  it = map2.begin();
  ++it;
  map2.erase(++it);
  it = map2.begin();

  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);

  map2.insert({5, "fifth"});
  map2.insert({6, "sixth"});
  map2.insert({7, "seventh"});
  map2.insert({8, "eighth"});
  map2.insert({9, "ninth"});

  it = map2.begin();
  ++it;  // 2
  map2.erase(it);

  it = map2.begin();

  EXPECT_EQ(it++.IsRed(), 0);  // 1
  EXPECT_EQ(it++.IsRed(), 0);  // 5
  EXPECT_EQ(it++.IsRed(), 0);  // 6
  EXPECT_EQ(it++.IsRed(), 1);  // 7
  EXPECT_EQ(it++.IsRed(), 1);  // 8
  EXPECT_EQ(it++.IsRed(), 0);  // 9
}

TEST(MapErase, ordinary4) {
  s21::map<int, std::string> map2;

  map2.insert({1, "first"});
  auto it = map2.begin();
  EXPECT_EQ(it.IsRed(), 0);

  map2.erase(it);

  EXPECT_EQ(map2.empty(), true);
  EXPECT_EQ(map2.size(), 0);
  map2.insert({1, "first"});
  it = map2.begin();
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(map2.empty(), false);
  EXPECT_EQ(map2.size(), 1);
}

/*

void swap(map& other)

*/
TEST(MapSwap, ordinary1) {
  s21::map<int, std::string> m1;

  m1.insert(std::pair<int, std::string>(4, "four"));
  m1.insert(std::pair<int, std::string>(6, "six"));
  m1.insert(std::pair<int, std::string>(8, "eight"));
  m1.insert(std::pair<int, std::string>(5, "five"));
  m1.insert(std::pair<int, std::string>(7, "seven"));

  s21::map<int, std::string> m2;
  m2.insert(std::pair<int, std::string>(1, "four"));
  m2.insert(std::pair<int, std::string>(6, "six"));
  m2.insert(std::pair<int, std::string>(5, "eight"));
  m2.insert(std::pair<int, std::string>(4, "five"));

  auto it1 = m1.begin();
  auto it2 = m2.begin();
  EXPECT_EQ(m1.size(), 5);
  EXPECT_EQ(m2.size(), 4);
  EXPECT_EQ(it1->first, 4);
  EXPECT_EQ(it2->first, 1);

  m1.swap(m2);
  auto new_it1 = m1.begin();
  auto new_it2 = m2.begin();
  EXPECT_EQ(new_it1++->first, 1);
  EXPECT_EQ(new_it1++->first, 4);
  EXPECT_EQ(new_it1++->first, 5);
  EXPECT_EQ(new_it1->first, 6);

  EXPECT_EQ(new_it2++->first, 4);
  EXPECT_EQ(new_it2++->first, 5);
  EXPECT_EQ(new_it2++->first, 6);
  EXPECT_EQ(new_it2++->first, 7);
  EXPECT_EQ(new_it2->first, 8);
  EXPECT_EQ(m1.size(), 4);
  EXPECT_EQ(m2.size(), 5);
}

TEST(MapMerge, ordinary1) {
  s21::map<int, std::string> ma{{1, "apple"}, {5, "pear"}, {10, "banana"}};
  s21::map<int, std::string> mb{
      {2, "zorro"}, {4, "batman"}, {5, "X"}, {8, "alpaca"}};
  auto it = mb.begin();
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  s21::map<int, std::string> u;
  u.merge(ma);
  EXPECT_EQ(u.size(), 3);
  EXPECT_EQ(ma.size(), 0);
  EXPECT_EQ(u[1], "apple");
  EXPECT_EQ(u[5], "pear");
  EXPECT_EQ(u[10], "banana");

  it = u.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  u.merge(mb);
  EXPECT_EQ(u.size(), 6);
  EXPECT_EQ(mb.size(), 1);
  EXPECT_EQ(mb.at(5), "X");

  it = mb.begin();
  EXPECT_EQ(it.IsRed(), 0);

  it = u.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);

  EXPECT_EQ(u[1], "apple");
  EXPECT_EQ(u[5], "pear");
  EXPECT_EQ(u[2], "zorro");
  EXPECT_EQ(u[4], "batman");
  EXPECT_EQ(u[8], "alpaca");
  EXPECT_EQ(u[10], "banana");
}

TEST(MapMerge, ordinary2) {
  s21::map<int, std::string> ma{{1, "apple"}, {5, "pear"},   {10, "banana"},
                                {2, "zorro"}, {4, "batman"}, {8, "alpaca"}};
  s21::map<int, std::string> mb{};

  s21::map<int, std::string> u;
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

  EXPECT_EQ(u[1], "apple");
  EXPECT_EQ(u[5], "pear");
  EXPECT_EQ(u[2], "zorro");
  EXPECT_EQ(u[4], "batman");
  EXPECT_EQ(u[8], "alpaca");
  EXPECT_EQ(u[10], "banana");

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

  EXPECT_EQ(u[1], "apple");
  EXPECT_EQ(u[5], "pear");
  EXPECT_EQ(u[2], "zorro");
  EXPECT_EQ(u[4], "batman");
  EXPECT_EQ(u[8], "alpaca");
  EXPECT_EQ(u[10], "banana");
}

TEST(MapMerge, ordinary3) {
  s21::map<int, std::string> ma{{1, "apple"}, {5, "pear"},   {10, "banana"},
                                {2, "zorro"}, {4, "batman"}, {8, "alpaca"}};
  s21::map<int, std::string> mb{};

  s21::map<int, std::string> u;
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

  EXPECT_EQ(u[1], "apple");
  EXPECT_EQ(u[5], "pear");
  EXPECT_EQ(u[2], "zorro");
  EXPECT_EQ(u[4], "batman");
  EXPECT_EQ(u[8], "alpaca");
  EXPECT_EQ(u[10], "banana");
}

TEST(MapMerge, ordinary4) {
  s21::map<int, std::string> ma{{1, "apple"}, {5, "pear"}, {10, "banana"}};
  s21::map<int, std::string> mb{
      {2, "zorro"}, {4, "batman"}, {5, "X"}, {8, "alpaca"}};
  auto it = mb.begin();
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it.IsRed(), 1);

  ma.merge(mb);
  EXPECT_EQ(ma.size(), 6);
  EXPECT_EQ(mb.size(), 1);
  EXPECT_EQ(mb.at(5), "X");

  it = mb.begin();
  EXPECT_EQ(it.IsRed(), 0);

  it = ma.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);

  EXPECT_EQ(ma[1], "apple");
  EXPECT_EQ(ma[5], "pear");
  EXPECT_EQ(ma[2], "zorro");
  EXPECT_EQ(ma[4], "batman");
  EXPECT_EQ(ma[8], "alpaca");
  EXPECT_EQ(ma[10], "banana");
}

TEST(MapMerge, ordinary5) {
  s21::map<int, std::string> ma{{1, "apple"}, {5, "pear"}, {10, "banana"}};
  s21::map<int, std::string> mb{
      {2, "zorro"}, {4, "batman"}, {5, "X"}, {8, "alpaca"}};

  mb.merge(ma);
  EXPECT_EQ(mb.size(), 6);
  EXPECT_EQ(ma.size(), 1);
  EXPECT_EQ(ma.at(5), "pear");

  auto it = ma.begin();
  EXPECT_EQ(it.IsRed(), 0);

  it = mb.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);

  EXPECT_EQ(mb[1], "apple");
  EXPECT_EQ(mb[5], "X");
  EXPECT_EQ(mb[2], "zorro");
  EXPECT_EQ(mb[4], "batman");
  EXPECT_EQ(mb[8], "alpaca");
  EXPECT_EQ(mb[10], "banana");
}

TEST(MapMerge, ordinary6) {
  s21::map<int, std::string> ma{{1, "apple"}, {5, "pear"}, {10, "banana"}};
  s21::map<int, std::string> mb{{2, "zorro"}, {4, "batman"}, {8, "alpaca"}};

  mb.merge(ma);
  EXPECT_EQ(mb.size(), 6);
  EXPECT_EQ(ma.size(), 0);

  auto it = mb.begin();
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);

  EXPECT_EQ(mb[1], "apple");
  EXPECT_EQ(mb[5], "pear");
  EXPECT_EQ(mb[2], "zorro");
  EXPECT_EQ(mb[4], "batman");
  EXPECT_EQ(mb[8], "alpaca");
  EXPECT_EQ(mb[10], "banana");
}

/*

insert many

*/

TEST(MapInsertMany, ordinary1) {
  s21::map<int, std::string> m;
  std::map<int, std::string> std_map;

  m.insert_many(std::pair<int, std::string>(4, "four"),
                std::pair<int, std::string>(6, "six"),
                std::pair<int, std::string>(8, "eight"),
                std::pair<int, std::string>(5, "five"),
                std::pair<int, std::string>(7, "seven"));

  std_map.insert(std::pair<int, std::string>(4, "four"));
  std_map.insert(std::pair<int, std::string>(6, "six"));
  std_map.insert(std::pair<int, std::string>(8, "eight"));
  std_map.insert(std::pair<int, std::string>(5, "five"));
  std_map.insert(std::pair<int, std::string>(7, "seven"));

  auto it = m.begin();
  auto std_it = std_map.begin();

  for (; it != m.end(); ++it, ++std_it) {
    EXPECT_EQ(it->first, std_it->first);
    EXPECT_EQ(it->second, std_it->second);
    // std::cout << it->first << " " << std_it->first << " " << it.IsRed()
    //           << std::endl;
  }
  it = m.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(m.GetRoot()->data.first, 6);
}

TEST(MapInsertMany, ordinary2) {
  s21::map<int, std::string> m;
  std::map<int, std::string> std_map;

  std::pair<int, std::string> a(4, "four");
  std::pair<int, std::string> b(6, "six");
  std::pair<int, std::string> c(8, "eight");
  std::pair<int, std::string> d(5, "five");
  std::pair<int, std::string> e(7, "seven");

  m.insert_many(a, b, c, d, e);

  std_map.insert(std::pair<int, std::string>(4, "four"));
  std_map.insert(std::pair<int, std::string>(6, "six"));
  std_map.insert(std::pair<int, std::string>(8, "eight"));
  std_map.insert(std::pair<int, std::string>(5, "five"));
  std_map.insert(std::pair<int, std::string>(7, "seven"));

  a.first = 8;

  auto it = m.begin();
  auto std_it = std_map.begin();

  for (; it != m.end(); ++it, ++std_it) {
    EXPECT_EQ(it->first, std_it->first);
    EXPECT_EQ(it->second, std_it->second);
    // std::cout << it->first << " " << std_it->first << " " << it.IsRed()
    //           << std::endl;
  }
  it = m.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(m.GetRoot()->data.first, 6);
}

TEST(MapInsertMany, ordinary3) {
  s21::map<int, std::string> m{std::pair<int, std::string>(4, "four")};
  std::map<int, std::string> std_map{std::pair<int, std::string>(4, "four")};

  std::pair<int, std::string> a(4, "four");
  std::pair<int, std::string> b(6, "six");
  std::pair<int, std::string> c(8, "eight");
  std::pair<int, std::string> d(5, "five");
  std::pair<int, std::string> e(7, "seven");

  m.insert_many(a, b, c, d, e);

  std_map.insert(std::pair<int, std::string>(4, "four"));
  std_map.insert(std::pair<int, std::string>(6, "six"));
  std_map.insert(std::pair<int, std::string>(8, "eight"));
  std_map.insert(std::pair<int, std::string>(5, "five"));
  std_map.insert(std::pair<int, std::string>(7, "seven"));

  auto it = m.begin();
  auto std_it = std_map.begin();

  for (; it != m.end(); ++it, ++std_it) {
    EXPECT_EQ(it->first, std_it->first);
    EXPECT_EQ(it->second, std_it->second);
    // std::cout << it->first << " " << std_it->first << " " << it.IsRed()
    //           << std::endl;
  }
  it = m.begin();

  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it++.IsRed(), 0);
  EXPECT_EQ(it++.IsRed(), 1);
  EXPECT_EQ(it.IsRed(), 0);
  EXPECT_EQ(m.GetRoot()->data.first, 6);
}

TEST(MapInsertMany, ordinary4) {
  s21::map<int, s21::vector<int>> m;
  // std::cout << "Start" << std::endl;
  m.insert_many(std::pair<int, s21::vector<int>>{1, {1, 2, 3, 4}},
                std::pair<int, s21::vector<int>>{2, {1, 3, 3, 4}},
                std::pair<int, s21::vector<int>>{3, {1, 2, 3, 4}},
                std::pair<int, s21::vector<int>>{4, {1, 2, 3, 4}},
                std::pair<int, s21::vector<int>>{5, {1, 4, 3, 4}});

  EXPECT_EQ(m.size(), 5);
  EXPECT_EQ(m.GetRoot()->data.first, 2);
  EXPECT_EQ(m.GetRoot()->data.second[1], 3);
  EXPECT_EQ(m.begin().IsRed(), 0);

  EXPECT_EQ((--(--m.end())).IsRed(), 0);
  EXPECT_EQ((--m.end()).IsRed(), 1);
  EXPECT_EQ((*(--m.end())).second[1], 4);
}

TEST(MapInsertMany, ordinary5) {
  s21::map<int, s21::vector<int>> m;

  std::pair<int, s21::vector<int>> a{1, {1, 2, 3, 4}};
  std::pair<int, s21::vector<int>> b{2, {1, 3, 3, 4}};
  std::pair<int, s21::vector<int>> c{3, {1, 2, 3, 4}};
  std::pair<int, s21::vector<int>> d{4, {1, 2, 3, 4}};
  std::pair<int, s21::vector<int>> e{5, {1, 4, 3, 4}};
  // std::cout << "Start" << std::endl;
  m.insert_many(a, b, c, d, e);
  EXPECT_EQ(m.size(), 5);
  EXPECT_EQ(m.GetRoot()->data.first, 2);
  EXPECT_EQ(m.GetRoot()->data.second[1], 3);
  EXPECT_EQ(m.begin().IsRed(), 0);

  EXPECT_EQ((--(--m.end())).IsRed(), 0);
  EXPECT_EQ((--m.end()).IsRed(), 1);
  EXPECT_EQ((*(--m.end())).second[1], 4);
}

TEST(MapInsertMany, ordinary6) {
  s21::map<int, s21::vector<int>> m;

  std::pair<int, s21::vector<int>> a{1, {1, 2, 3, 4}};
  std::pair<int, s21::vector<int>> b{2, {1, 3, 3, 4}};
  std::pair<int, s21::vector<int>> c{3, {1, 2, 3, 4}};
  std::pair<int, s21::vector<int>> d{4, {1, 2, 3, 4}};
  std::pair<int, s21::vector<int>> e{5, {1, 4, 3, 4}};
  // std::cout << "Start" << std::endl;
  m.insert_many(std::move(a), std::move(b), std::move(c), std::move(d),
                std::move(e));
  EXPECT_EQ(m.size(), 5);
  EXPECT_EQ(m.GetRoot()->data.first, 2);
  EXPECT_EQ(m.GetRoot()->data.second[1], 3);
  EXPECT_EQ(m.begin().IsRed(), 0);

  EXPECT_EQ((--(--m.end())).IsRed(), 0);
  EXPECT_EQ((--m.end()).IsRed(), 1);
  EXPECT_EQ((*(--m.end())).second[1], 4);
}

TEST(MapInsertMany, ordinary7) {
  s21::map<int, s21::vector<int>> m;

  std::pair<int, s21::vector<int>> a{1, {1, 2, 3, 4}};
  std::pair<int, s21::vector<int>> b{2, {1, 3, 3, 4}};
  std::pair<int, s21::vector<int>> c{3, {1, 2, 3, 4}};
  std::pair<int, s21::vector<int>> d{4, {1, 2, 3, 4}};
  std::pair<int, s21::vector<int>> e{5, {1, 4, 3, 4}};
  // std::cout << "Start" << std::endl;
  m.insert_many(std::move(a), std::move(b), std::move(c), std::move(d),
                std::move(e));
  EXPECT_EQ(m.size(), 5);
  EXPECT_EQ(m.GetRoot()->data.first, 2);
  EXPECT_EQ(m.GetRoot()->data.second[1], 3);
  EXPECT_EQ(m.begin().IsRed(), 0);

  EXPECT_EQ((--(--m.end())).IsRed(), 0);
  EXPECT_EQ((--m.end()).IsRed(), 1);
  EXPECT_EQ((*(--m.end())).second[1], 4);
}

TEST(MapInsertMany, ordinary8) {
  s21::map<int, s21::vector<int>> m;

  std::pair<int, s21::vector<int>> a{1, {1, 2, 3, 4}};
  std::pair<int, s21::vector<int>> b{2, {1, 3, 3, 4}};
  std::pair<int, s21::vector<int>> c{3, {1, 2, 3, 4}};
  std::pair<int, s21::vector<int>> d{4, {1, 2, 3, 4}};
  std::pair<int, s21::vector<int>> e{5, {1, 4, 3, 4}};
  // std::cout << "Start" << std::endl;
  m.insert_many(std::move(a), std::move(b), std::move(c), std::move(d),
                std::move(e));
  m.insert_many();
  EXPECT_EQ(m.size(), 5);
  EXPECT_EQ(m.GetRoot()->data.first, 2);
  EXPECT_EQ(m.GetRoot()->data.second[1], 3);
  EXPECT_EQ(m.begin().IsRed(), 0);

  EXPECT_EQ((--(--m.end())).IsRed(), 0);
  EXPECT_EQ((--m.end()).IsRed(), 1);
  EXPECT_EQ((*(--m.end())).second[1], 4);
}

TEST(MapInsertMany, ordinary9) {
  s21::map<int, s21::vector<int>> m;
  m.insert_many();
  EXPECT_EQ(m.size(), 0);
  EXPECT_EQ(m.empty(), true);
}

#endif