
#include "../s21_test.h"

/*

Ctor default

*/
#if 1
TEST(VecCtorDefault, ordinary1) {
  s21::vector<int> v;
  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.capacity(), 0);
  EXPECT_EQ(v.empty(), true);

  s21::vector<unsigned long long> v_un;
  EXPECT_EQ(v_un.size(), 0);
  EXPECT_EQ(v_un.capacity(), 0);
  EXPECT_EQ(v_un.empty(), true);

  s21::vector<std::string> arr_string;
  EXPECT_EQ(arr_string.size(), 0);
  EXPECT_EQ(arr_string.capacity(), 0);
  EXPECT_EQ(arr_string.empty(), true);

  s21::vector<std::vector<int>> arr_vectors;
  EXPECT_EQ(arr_vectors.size(), 0);
  EXPECT_EQ(arr_vectors.capacity(), 0);
  EXPECT_EQ(arr_vectors.empty(), true);

  s21::vector<s21::vector<int>> arr_arr;
  EXPECT_EQ(arr_arr.size(), 0);
  EXPECT_EQ(arr_arr.capacity(), 0);
  EXPECT_EQ(arr_arr.empty(), true);
}

/*

Ctor param

*/

TEST(VecCtorParam, ordinary1) {
  s21::vector<int> v(123132);
  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.capacity(), 123132);
  EXPECT_EQ(v.empty(), true);

  s21::vector<unsigned long long> v_un(1);
  EXPECT_EQ(v_un.size(), 0);
  EXPECT_EQ(v_un.capacity(), 1);
  EXPECT_EQ(v_un.empty(), true);

  s21::vector<std::string> arr_string(100);
  EXPECT_EQ(arr_string.size(), 0);
  EXPECT_EQ(arr_string.capacity(), 100);
  EXPECT_EQ(arr_string.empty(), true);

  s21::vector<std::vector<int>> arr_vectors(2);
  EXPECT_EQ(arr_vectors.size(), 0);
  EXPECT_EQ(arr_vectors.capacity(), 2);
  EXPECT_EQ(arr_vectors.empty(), true);

  s21::vector<s21::vector<int>> arr_arr(23);
  EXPECT_EQ(arr_arr.size(), 0);
  EXPECT_EQ(arr_arr.capacity(), 23);
  EXPECT_EQ(arr_arr.empty(), true);
}

TEST(VecCtorParam, ordinary2) {
  s21::vector<int> v(0);
  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.capacity(), 0);
  EXPECT_EQ(v.empty(), true);

  s21::vector<unsigned long long> v_un(0);
  EXPECT_EQ(v_un.size(), 0);
  EXPECT_EQ(v_un.capacity(), 0);
  EXPECT_EQ(v_un.empty(), true);

  s21::vector<std::string> arr_string(0);
  EXPECT_EQ(arr_string.size(), 0);
  EXPECT_EQ(arr_string.capacity(), 0);
  EXPECT_EQ(arr_string.empty(), true);

  s21::vector<std::vector<int>> arr_vectors(0);
  EXPECT_EQ(arr_vectors.size(), 0);
  EXPECT_EQ(arr_vectors.capacity(), 0);
  EXPECT_EQ(arr_vectors.empty(), true);

  s21::vector<s21::vector<int>> arr_arr(0);
  EXPECT_EQ(arr_arr.size(), 0);
  EXPECT_EQ(arr_arr.capacity(), 0);
  EXPECT_EQ(arr_arr.empty(), true);
}

TEST(VecCtorParam, throw1) {
  EXPECT_THROW({ s21::vector<int> v(std::numeric_limits<std::size_t>::max()); },
               std::out_of_range);
  EXPECT_THROW(
      {
        s21::vector<unsigned long long> v_un(
            std::numeric_limits<std::size_t>::max() - 100);
      },
      std::out_of_range);
  EXPECT_THROW(
      {
        s21::vector<std::string> arr_string(
            std::numeric_limits<std::size_t>::max() - 5);
      },
      std::out_of_range);
  EXPECT_THROW(
      {
        s21::vector<std::vector<int>> arr_vectors(
            std::numeric_limits<std::size_t>::max());
      },
      std::out_of_range);
  EXPECT_THROW(
      {
        s21::vector<s21::vector<int>> arr_arr(
            std::numeric_limits<std::size_t>::max());
      },
      std::out_of_range);
}

/*

Ctor initializer_list

*/

TEST(VecCtorInitializerList, ordinary1) {
  s21::vector<int> v{1, 2, 3, 4, 5};
  EXPECT_EQ(v.size(), 5);
  EXPECT_EQ(v.capacity(), 5);
  EXPECT_EQ(v.empty(), false);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[3], 4);
  EXPECT_EQ(v[4], 5);
}

TEST(VecCtorInitializerList, ordinary2) {
  s21::vector<std::string> v{"Hello", "World!"};
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.capacity(), 2);
  EXPECT_EQ(v[0], "Hello");
  EXPECT_EQ(v[1], "World!");
}

/*

Ctor copy

*/

TEST(VecCtorCopy, ordinary1) {
  s21::vector<int> v1(3);
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  s21::vector<int> v2(v1);
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(v1[i], v2[i]);
  }
  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.capacity(), v2.capacity());
  EXPECT_EQ(v1.empty(), v2.empty());
}

TEST(VecCtorCopy, ordinary2) {
  s21::vector<std::string> v1(1);
  v1.push_back("Hello World!");
  s21::vector<std::string> v2(v1);
  for (int i = 0; i < 1; i++) {
    EXPECT_EQ(v1[i], v2[i]);
  }
  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.capacity(), v2.capacity());
  EXPECT_EQ(v1.empty(), v2.empty());
}

TEST(VecCtorCopy, ordinary3) {
  s21::vector<int> v1(5);
  s21::vector<int> v2(v1);
  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.capacity(), v2.capacity());
  EXPECT_EQ(v1.empty(), v2.empty());
}

TEST(VecCtorCopy, ordinary4) {
  s21::vector<std::string> v1(1);
  v1.push_back("Hello World!");
  v1.push_back("Hello World2!");
  s21::vector<std::string> v2(v1);
  for (int i = 0; i < 2; i++) {
    EXPECT_EQ(v1[i], v2[i]);
  }
  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.capacity(), v2.capacity());
  EXPECT_EQ(v1.empty(), v2.empty());
}

/*

Assign copy

*/

TEST(VecAssignCopy, ordinary1) {
  s21::vector<int> v1(3);
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);

  s21::vector<int> v2(2);
  v2.push_back(4);
  v2.push_back(5);
  v2 = v1;

  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(v1[i], v2[i]);
  }
  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.capacity(), v2.capacity());
  EXPECT_EQ(v1.empty(), v2.empty());
}

TEST(VecAssignCopy, ordinary2) {
  s21::vector<std::string> v1(3);
  v1.push_back("My");
  v1.push_back("name");
  v1.push_back("is");
  s21::vector<std::string> v2(2);
  v2.push_back("Dont");
  v2.push_back("remember");
  v2 = v1;

  v2[0] = "My";
  v2[1] = "name";
  v2[2] = "is";

  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.capacity(), v2.capacity());
  EXPECT_EQ(v1.empty(), v2.empty());
}

/*

Ctor move

*/

TEST(VecCtorMove, ordinary1) {
  s21::vector<int> v1(3);
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  s21::vector<int> v2(std::move(v1));
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(i + 1, v2[i]);
  }
  EXPECT_EQ(3, v2.size());
  EXPECT_EQ(3, v2.capacity());
  EXPECT_EQ(false, v2.empty());

  EXPECT_EQ(0, v1.size());
  EXPECT_EQ(0, v1.capacity());
  EXPECT_EQ(true, v1.empty());
}

TEST(VecCtorMove, ordinary2) {
  s21::vector<std::string> v1(3);
  v1.push_back("My");
  v1.push_back("name");
  v1.push_back("is");
  s21::vector<std::string> v2(std::move(v1));

  v2[0] = "My";
  v2[1] = "name";
  v2[2] = "is";

  EXPECT_EQ(3, v2.size());
  EXPECT_EQ(3, v2.capacity());
  EXPECT_EQ(false, v2.empty());

  EXPECT_EQ(0, v1.size());
  EXPECT_EQ(0, v1.capacity());
  EXPECT_EQ(true, v1.empty());
}

/*

Assign move

*/

TEST(VecAssignMove, ordinary1) {
  s21::vector<int> v1(3);
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  s21::vector<int> v2(2);
  v2.push_back(4);
  v2.push_back(5);
  v2 = std::move(v1);

  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(i + 1, v2[i]);
  }
  EXPECT_EQ(3, v2.size());
  EXPECT_EQ(3, v2.capacity());
  EXPECT_EQ(false, v2.empty());

  for (int i = 0; i < 2; i++) {
    EXPECT_EQ(4 + i, v1[i]);
  }
  EXPECT_EQ(2, v1.size());
  EXPECT_EQ(2, v1.capacity());
  EXPECT_EQ(false, v1.empty());
}

TEST(VecAssignMove, ordinary2) {
  s21::vector<std::string> v1(3);
  v1.push_back("My");
  v1.push_back("name");
  v1.push_back("is");
  s21::vector<std::string> v2(2);
  v2.push_back("Dont");
  v2.push_back("remember");
  v2 = std::move(v1);

  v2[0] = "My";
  v2[1] = "name";
  v2[2] = "is";
  v1[0] = "Dont";
  v1[1] = "remember";

  EXPECT_EQ(3, v2.size());
  EXPECT_EQ(3, v2.capacity());
  EXPECT_EQ(false, v2.empty());

  EXPECT_EQ(2, v1.size());
  EXPECT_EQ(2, v1.capacity());
  EXPECT_EQ(false, v1.empty());
}
#endif