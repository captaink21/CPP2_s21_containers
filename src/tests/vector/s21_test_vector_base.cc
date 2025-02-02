#include "../s21_test.h"

/*

Ctor default

*/

TEST(VecCtorDefaultBase, ordinary1) {
  s21::VectorBase<int> v;
  EXPECT_EQ(v.first, nullptr);
  EXPECT_EQ(v.extra, nullptr);
  EXPECT_EQ(v.outside, nullptr);

  s21::VectorBase<unsigned long long> v_un;
  EXPECT_EQ(v_un.first, nullptr);
  EXPECT_EQ(v_un.extra, nullptr);
  EXPECT_EQ(v_un.outside, nullptr);

  s21::VectorBase<std::string> arr_string;
  EXPECT_EQ(arr_string.first, nullptr);
  EXPECT_EQ(arr_string.extra, nullptr);
  EXPECT_EQ(arr_string.outside, nullptr);

  s21::VectorBase<std::vector<int>> arr_vectors;
  EXPECT_EQ(arr_vectors.first, nullptr);
  EXPECT_EQ(arr_vectors.extra, nullptr);
  EXPECT_EQ(arr_vectors.outside, nullptr);

  s21::VectorBase<s21::vector<int>> arr_arr;
  EXPECT_EQ(arr_arr.first, nullptr);
  EXPECT_EQ(arr_arr.extra, nullptr);
  EXPECT_EQ(arr_arr.outside, nullptr);
}

/*

Ctor param

*/

TEST(VecCtorParamBase, ordinary1) {
  s21::VectorBase<int> v(2);
  EXPECT_NE(v.first, nullptr);
  EXPECT_EQ(v.extra, v.first);
  EXPECT_EQ(v.outside, v.first + 2);

  s21::VectorBase<unsigned long long> v_un(1);
  EXPECT_NE(v_un.first, nullptr);
  EXPECT_EQ(v_un.extra, v_un.first);
  EXPECT_EQ(v_un.outside, v_un.first + 1);

  s21::VectorBase<std::string> arr_string(100);
  EXPECT_NE(arr_string.first, nullptr);
  EXPECT_EQ(arr_string.extra, arr_string.first);
  EXPECT_EQ(arr_string.outside, arr_string.first + 100);

  s21::VectorBase<std::vector<int>> arr_vectors(2);
  EXPECT_NE(arr_vectors.first, nullptr);
  EXPECT_EQ(arr_vectors.extra, arr_vectors.first);
  EXPECT_EQ(arr_vectors.outside, arr_vectors.first + 2);

  s21::VectorBase<s21::vector<int>> arr_arr(23);
  EXPECT_NE(arr_arr.first, nullptr);
  EXPECT_EQ(arr_arr.extra, arr_arr.first);
  EXPECT_EQ(arr_arr.outside, arr_arr.first + 23);
}

TEST(VecCtorParamBase, ordinary2) {
  s21::VectorBase<int> v(0);
  EXPECT_EQ(v.first, nullptr);
  EXPECT_EQ(v.extra, nullptr);
  EXPECT_EQ(v.outside, nullptr);

  s21::VectorBase<unsigned long long> v_un(0);
  EXPECT_EQ(v_un.first, nullptr);
  EXPECT_EQ(v_un.extra, nullptr);
  EXPECT_EQ(v_un.outside, nullptr);

  s21::VectorBase<std::string> arr_string(0);
  EXPECT_EQ(arr_string.first, nullptr);
  EXPECT_EQ(arr_string.extra, nullptr);
  EXPECT_EQ(arr_string.outside, nullptr);

  s21::VectorBase<std::vector<int>> arr_vectors(0);
  EXPECT_EQ(arr_vectors.first, nullptr);
  EXPECT_EQ(arr_vectors.extra, nullptr);
  EXPECT_EQ(arr_vectors.outside, nullptr);

  s21::VectorBase<s21::vector<int>> arr_arr(0);
  EXPECT_EQ(arr_arr.first, nullptr);
  EXPECT_EQ(arr_arr.extra, nullptr);
  EXPECT_EQ(arr_arr.outside, nullptr);
}

/*

Ctor move

*/

TEST(VecCtorMoveBase, ordinary1) {
  s21::VectorBase<int> v1(3);
  s21::VectorBase<int> v2(std::move(v1));
  EXPECT_EQ(v1.first, nullptr);
  EXPECT_EQ(v1.extra, nullptr);
  EXPECT_EQ(v1.outside, nullptr);

  EXPECT_NE(v2.first, nullptr);
  EXPECT_EQ(v2.extra, v2.first);
  EXPECT_EQ(v2.outside, v2.first + 3);
}

TEST(VecCtorMoveBase, ordinary2) {
  s21::VectorBase<std::string> v1(3);
  s21::VectorBase<std::string> v2(std::move(v1));
  EXPECT_EQ(v1.first, nullptr);
  EXPECT_EQ(v1.extra, nullptr);
  EXPECT_EQ(v1.outside, nullptr);

  EXPECT_NE(v2.first, nullptr);
  EXPECT_EQ(v2.extra, v2.first);
  EXPECT_EQ(v2.outside, v2.first + 3);
}

/*

Assign move

*/

TEST(VecAssignMoveBase, ordinary1) {
  s21::VectorBase<int> v1(3);
  s21::VectorBase<int> v2(4);

  EXPECT_NE(v1.first, nullptr);
  EXPECT_EQ(v1.extra, v1.first);
  EXPECT_EQ(v1.outside, v1.first + 3);

  EXPECT_NE(v2.first, nullptr);
  EXPECT_EQ(v2.extra, v2.first);
  EXPECT_EQ(v2.outside, v2.first + 4);

  v2 = (std::move(v1));

  EXPECT_NE(v2.first, nullptr);
  EXPECT_EQ(v2.extra, v2.first);
  EXPECT_EQ(v2.outside, v2.first + 3);

  EXPECT_NE(v1.first, nullptr);
  EXPECT_EQ(v1.extra, v1.first);
  EXPECT_EQ(v1.outside, v1.first + 4);
}