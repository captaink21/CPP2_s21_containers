#include "../s21_test.h"

/*
bool contains(const Key& key)
*/
#if 1
TEST(MapContains, ordinary1) {
  s21::map<int, std::string> map{
      std::pair<int, std::string>(13, "13"),
      std::pair<int, std::string>(8, "8"),
      std::pair<int, std::string>(17, "17"),
      std::pair<int, std::string>(1, "1"),
      std::pair<int, std::string>(11, "11"),
      std::pair<int, std::string>(6, "6"),
      std::pair<int, std::string>(15, "15"),
      std::pair<int, std::string>(25, "25"),
      std::pair<int, std::string>(22, "22"),
      std::pair<int, std::string>(27, "27"),
  };

  EXPECT_TRUE(map.contains(13));
  EXPECT_TRUE(map.contains(8));
  EXPECT_TRUE(map.contains(17));
  EXPECT_TRUE(map.contains(1));
  EXPECT_TRUE(map.contains(11));
  EXPECT_TRUE(map.contains(6));
  EXPECT_TRUE(map.contains(15));
  EXPECT_TRUE(map.contains(25));
  EXPECT_TRUE(map.contains(22));
  EXPECT_TRUE(map.contains(27));

  EXPECT_FALSE(map.contains(2));
}
#endif