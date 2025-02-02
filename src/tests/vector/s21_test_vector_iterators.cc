#include "../s21_test.h"

/*

Begin

*/
#if 1
TEST(VecBegin, ordinary1) {
  s21::vector<s21::vector<int>> v;
  EXPECT_EQ(v.begin(), nullptr);
  v.reserve(1);
  EXPECT_NE(v.begin(), nullptr);
  EXPECT_EQ(v.begin(), v.end());

  s21::vector<int> temp(1);
  v.push_back(temp);

  EXPECT_NE(v.begin(), nullptr);
  EXPECT_EQ(v.begin(), v.end() - 1);
}

TEST(VecBegin, ordinary2) {
  s21::vector<int> v;
  EXPECT_EQ(v.begin(), nullptr);

  int temp(1);
  v.push_back(temp);

  EXPECT_EQ(*v.begin(), 1);
  EXPECT_EQ(*v.begin(), *(v.end() - 1));
  EXPECT_EQ(v.begin(), v.end() - 1);
  temp = 2;
  v.push_back(temp);

  EXPECT_EQ(*v.begin(), 1);
  EXPECT_EQ(v.begin(), v.end() - 2);
}

/*

End

*/

TEST(VecEnd, ordinary1) {
  s21::vector<s21::vector<int>> v;
  EXPECT_EQ(v.end(), nullptr);
  v.reserve(1);
  EXPECT_NE(v.end(), nullptr);

  s21::vector<int> temp(1);
  v.push_back(temp);

  EXPECT_NE(v.end(), nullptr);
}

TEST(VecEnd, ordinary2) {
  s21::vector<int> v;
  EXPECT_EQ(v.end(), nullptr);

  int temp(1);
  v.push_back(temp);

  EXPECT_EQ(*(v.end() - 1), 1);
  temp = 2;
  v.push_back(temp);

  EXPECT_EQ(*(v.end() - 1), 2);
  EXPECT_EQ(*(v.end() - 2), 1);
}
#endif