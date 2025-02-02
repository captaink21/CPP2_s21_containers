#include "../s21_test.h"

/*

Empty

*/
#if 1
TEST(VecEmpty, ordinary1) {
  s21::vector<int> v;
  EXPECT_EQ(v.empty(), true);
  // v.empty();
  v.push_back(1);
  EXPECT_EQ(v.empty(), false);
  v.pop_back();
  EXPECT_EQ(v.empty(), true);
}

TEST(VecEmpty, ordinary2) {
  s21::vector<int> v;
  EXPECT_EQ(v.empty(), true);
  v.reserve(20);
  EXPECT_EQ(v.empty(), true);
  v.shrink_to_fit();
  EXPECT_EQ(v.empty(), true);
}

TEST(VecEmpty, ordinary3) {
  s21::vector<std::string> v;
  EXPECT_EQ(v.empty(), true);
  v.push_back("HI");
  EXPECT_EQ(v.empty(), false);
  v.pop_back();
  EXPECT_EQ(v.empty(), true);
}

TEST(VecEmpty, ordinary4) {
  s21::vector<std::string> v;
  EXPECT_EQ(v.empty(), true);
  v.reserve(20);
  EXPECT_EQ(v.empty(), true);
  v.shrink_to_fit();
  EXPECT_EQ(v.empty(), true);
}

/*

Size

*/

TEST(VecSize, ordinary1) {
  s21::vector<s21::vector<int>> v;
  EXPECT_EQ(v.size(), 0);
  v.reserve(20);
  EXPECT_EQ(v.size(), 0);

  s21::vector<int> temp(1);
  v.push_back(temp);

  EXPECT_EQ(v.size(), 1);

  v.shrink_to_fit();
  EXPECT_EQ(v.size(), 1);
  v.push_back(temp);
  EXPECT_EQ(v.size(), 2);
  v.pop_back();
  EXPECT_EQ(v.size(), 1);
  v.pop_back();
  EXPECT_EQ(v.size(), 0);
}

/*

Max Size

*/

TEST(VecMaxSize, ordinary1) {
  s21::vector<s21::vector<int>> v;
  std::vector<s21::vector<int>> a;

  EXPECT_EQ(v.max_size(), a.max_size());
  s21::vector<int> temp(1);

  v.push_back(temp);
  a.push_back(temp);

  EXPECT_EQ(v.max_size(), a.max_size());
}

TEST(VecMaxSize, ordinary2) {
  s21::vector<char> v;
  std::vector<char> a;

  EXPECT_EQ(v.max_size(), a.max_size());
  int temp(1);

  v.push_back(temp);
  a.push_back(temp);

  EXPECT_EQ(v.max_size(), a.max_size());
}

/*

Reserve

*/

TEST(VecReserve, ordinary1) {
  s21::vector<s21::vector<int>> v;
  v.reserve(1);

  EXPECT_EQ(v.size(), 0);
  s21::vector<int> temp(1);

  v.push_back(temp);
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.capacity(), 1);
  v.push_back(temp);
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.capacity(), 2);
  v.push_back(temp);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v.capacity(), 4);

  v.reserve(7);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v.capacity(), 7);
}

TEST(VecReserve, throw1) {
  s21::vector<s21::vector<int>> v;
  EXPECT_THROW({ v.reserve(std::numeric_limits<std::size_t>::max()); },
               std::out_of_range);

  EXPECT_THROW({ v.reserve(std::numeric_limits<std::size_t>::max() - 100000); },
               std::out_of_range);
}

/*

Shrink

*/

TEST(VecShrink, ordinary1) {
  s21::vector<s21::vector<int>> v;
  v.reserve(20);

  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.capacity(), 20);
  v.shrink_to_fit();

  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.capacity(), 0);
  v.reserve(20);
  s21::vector<int> temp(1);

  v.push_back(temp);
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.capacity(), 20);
  v.push_back(temp);
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.capacity(), 20);
  v.push_back(temp);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v.capacity(), 20);

  v.shrink_to_fit();
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v.capacity(), 3);
}
#endif