#include "../s21_test.h"

/*
iterator find(const Key& key)
*/
#if 1
TEST(SetFind, ordinary1) {
  s21::set<int> set{13, 8, 17, 1};
  EXPECT_EQ(*(set.begin()), 1);
  EXPECT_EQ(set.find(13), ++(++set.begin()));
  EXPECT_EQ(*set.find(13), 13);
}

TEST(SetFind, ordinary2) {
  s21::set<int> set{2, 8, 3, 11, 20, 5};
  EXPECT_EQ(*(set.begin()), 2);
  EXPECT_EQ(set.find(13), (--set.end()));
  EXPECT_EQ(*(set.find(4)), 5);
}

TEST(SetContains, ordinary1) {
  s21::set<std::string> set{"13", "8",  "17", "1",  "11",
                            "6",  "15", "25", "22", "27"};

  EXPECT_TRUE(set.contains("13"));
  EXPECT_TRUE(set.contains("8"));
  EXPECT_TRUE(set.contains("17"));
  EXPECT_TRUE(set.contains("1"));
  EXPECT_TRUE(set.contains("11"));
  EXPECT_TRUE(set.contains("6"));
  EXPECT_TRUE(set.contains("15"));
  EXPECT_TRUE(set.contains("25"));
  EXPECT_TRUE(set.contains("22"));
  EXPECT_TRUE(set.contains("27"));

  EXPECT_FALSE(set.contains("2"));
}

TEST(SetContains, ordinary2) {
  s21::set<int> set{13, 8, 17, 1, 11, 6, 15, 25, 22, 27};

  EXPECT_TRUE(set.contains(13));
  EXPECT_TRUE(set.contains(8));
  EXPECT_TRUE(set.contains(17));
  EXPECT_TRUE(set.contains(1));
  EXPECT_TRUE(set.contains(11));
  EXPECT_TRUE(set.contains(6));
  EXPECT_TRUE(set.contains(15));
  EXPECT_TRUE(set.contains(25));
  EXPECT_TRUE(set.contains(22));
  EXPECT_TRUE(set.contains(27));

  EXPECT_FALSE(set.contains(2));
}
#endif