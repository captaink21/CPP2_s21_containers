#include "../s21_test.h"

/*

Clear

*/
#if 1
TEST(VecClear, ordinary1) {
  s21::vector<std::string> v;
  v.push_back("hello");
  v.push_back("world");
  v.push_back("!");
  EXPECT_EQ(v.empty(), false);
  v.clear();
  EXPECT_EQ(v.empty(), true);
}

TEST(VecClear, ordinary2) {
  s21::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  EXPECT_EQ(v.empty(), false);
  v.clear();
  EXPECT_EQ(v.empty(), true);
}

/*

Insert

*/

TEST(VecInsert, ordinary1) {
  s21::vector<std::string> v;

  EXPECT_EQ(*(v.insert(v.begin(), "hello")), "hello");
  EXPECT_EQ(*(v.insert(v.begin(), "world")), "world");
  EXPECT_EQ(*(v.insert(v.end(), "my")), "my");

  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v.capacity(), 4);
  EXPECT_EQ(v[0], "world");
  EXPECT_EQ(v[1], "hello");
  EXPECT_EQ(v[2], "my");

  EXPECT_EQ(*(v.insert(v.end(), "name")), "name");
  EXPECT_EQ(*(v.insert(v.begin() + 1, "funny")), "funny");
  EXPECT_EQ(*(v.insert(v.end() - 1, "is")), "is");

  EXPECT_EQ(v[0], "world");
  EXPECT_EQ(v[1], "funny");
  EXPECT_EQ(v[2], "hello");
  EXPECT_EQ(v[3], "my");
  EXPECT_EQ(v[4], "is");
  EXPECT_EQ(v[5], "name");

  EXPECT_EQ(v.size(), 6);
  EXPECT_EQ(v.capacity(), 8);
}

TEST(VecInsert, ordinary2) {
  s21::vector<std::string> v;
  EXPECT_EQ(*(v.insert(v.end(), "world")), "world");
  EXPECT_EQ(v[0], "world");
  EXPECT_EQ(*(v.insert(v.begin(), "hello")), "hello");

  EXPECT_EQ(v[0], "hello");
  EXPECT_EQ(v[1], "world");
}

/*

Push_back

*/

TEST(VecPushBack, ordinary1) {
  s21::vector<std::string> v;
  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.capacity(), 0);

  v.push_back("1");
  EXPECT_EQ(v[0], "1");
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.capacity(), 1);

  v.push_back("2");
  EXPECT_EQ(v[0], "1");
  EXPECT_EQ(v[1], "2");
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.capacity(), 2);

  v.push_back("3");
  EXPECT_EQ(v[0], "1");
  EXPECT_EQ(v[1], "2");
  EXPECT_EQ(v[2], "3");
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v.capacity(), 4);

  v.push_back("4");
  EXPECT_EQ(v[0], "1");
  EXPECT_EQ(v[1], "2");
  EXPECT_EQ(v[2], "3");
  EXPECT_EQ(v[3], "4");
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v.capacity(), 4);

  v.push_back("5");
  EXPECT_EQ(v[0], "1");
  EXPECT_EQ(v[1], "2");
  EXPECT_EQ(v[2], "3");
  EXPECT_EQ(v[3], "4");
  EXPECT_EQ(v[4], "5");
  EXPECT_EQ(v.size(), 5);
  EXPECT_EQ(v.capacity(), 8);
}

TEST(VecPushBack, ordinary2) {
  s21::vector<int> v;
  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.capacity(), 0);

  v.push_back(1);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.capacity(), 1);

  v.push_back(2);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.capacity(), 2);

  v.push_back(3);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v.capacity(), 4);
}

/*

Erase

*/

TEST(VecErase, ordinary1) {
  s21::vector<std::string> v;
  v.insert(v.end(), "3");
  v.insert(v.begin(), "1");
  v.insert(v.begin() + 1, "2");
  EXPECT_EQ(v[0], "1");
  EXPECT_EQ(v[1], "2");
  EXPECT_EQ(v[2], "3");
  EXPECT_EQ(v.size(), 3);

  v.erase(v.begin());
  EXPECT_EQ(v[0], "2");
  EXPECT_EQ(v[1], "3");
  EXPECT_EQ(v.size(), 2);
  v.insert(v.end(), "4");

  v.erase(v.begin() + 1);
  EXPECT_EQ(v[0], "2");
  EXPECT_EQ(v[1], "4");
  EXPECT_EQ(v.size(), 2);
  v.insert(v.end(), "5");
  v.insert(v.end(), "6");
  EXPECT_EQ(v[0], "2");
  EXPECT_EQ(v[1], "4");
  EXPECT_EQ(v[2], "5");
  EXPECT_EQ(v[3], "6");
  EXPECT_EQ(v.size(), 4);

  v.erase(v.end() - 1);
  EXPECT_EQ(v[0], "2");
  EXPECT_EQ(v[1], "4");
  EXPECT_EQ(v[2], "5");

  EXPECT_EQ(v.size(), 3);

  v.insert(v.end(), "6");
  EXPECT_EQ(v.size(), 4);
  v.erase(v.end() - 2);
  EXPECT_EQ(v.size(), 3);

  EXPECT_EQ(v[0], "2");
  EXPECT_EQ(v[1], "4");
  EXPECT_EQ(v[2], "6");
}

TEST(VecErase, ordinary2) {
  s21::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);

  EXPECT_EQ(v.size(), 4);

  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[3], 4);

  v.erase(v.begin());

  EXPECT_EQ(v[0], 2);
  EXPECT_EQ(v[1], 3);
  EXPECT_EQ(v[2], 4);
  EXPECT_EQ(v.size(), 3);
}

/*

Pop_back

*/

TEST(VecPopBack, ordinary1) {
  s21::vector<std::string> v;

  v.push_back("1");
  v.push_back("2");
  v.push_back("3");
  v.push_back("4");
  v.push_back("5");
  EXPECT_EQ(v[0], "1");
  EXPECT_EQ(v[1], "2");
  EXPECT_EQ(v[2], "3");
  EXPECT_EQ(v[3], "4");
  EXPECT_EQ(v[4], "5");
  EXPECT_EQ(v.size(), 5);
  EXPECT_EQ(v.capacity(), 8);

  v.pop_back();
  EXPECT_EQ(v[0], "1");
  EXPECT_EQ(v[1], "2");
  EXPECT_EQ(v[2], "3");
  EXPECT_EQ(v[3], "4");
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v.capacity(), 8);

  v.pop_back();
  EXPECT_EQ(v[0], "1");
  EXPECT_EQ(v[1], "2");
  EXPECT_EQ(v[2], "3");
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v.capacity(), 8);

  v.pop_back();
  EXPECT_EQ(v[0], "1");
  EXPECT_EQ(v[1], "2");
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.capacity(), 8);

  v.pop_back();
  EXPECT_EQ(v[0], "1");
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.capacity(), 8);

  v.pop_back();
  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.capacity(), 8);
}

TEST(VecPopBack, ordinary2) {
  s21::vector<int> v;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v.capacity(), 4);

  v.pop_back();
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.capacity(), 4);

  v.pop_back();
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.capacity(), 4);

  v.pop_back();
  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.capacity(), 4);
}

/*

Swap

*/

TEST(VecSwap, ordinary1) {
  s21::vector<std::string> v;
  v.push_back("1");
  v.push_back("2");
  v.push_back("3");

  s21::vector<std::string> v2;
  v2.push_back("10");
  v2.push_back("20");
  v2.push_back("30");

  v.swap(v2);
  EXPECT_EQ(v[0], "10");
  EXPECT_EQ(v[1], "20");
  EXPECT_EQ(v[2], "30");

  EXPECT_EQ(v2[0], "1");
  EXPECT_EQ(v2[1], "2");
  EXPECT_EQ(v2[2], "3");
}

TEST(VecSwap, ordinary2) {
  s21::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  s21::vector<int> v2;
  v2.push_back(10);
  v2.push_back(20);
  v2.push_back(30);

  v.swap(v2);
  EXPECT_EQ(v[0], 10);
  EXPECT_EQ(v[1], 20);
  EXPECT_EQ(v[2], 30);

  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[1], 2);
  EXPECT_EQ(v2[2], 3);
}

/*

insert_many

*/

TEST(insert_many, ordinary12) {
  s21::vector<int> v{1, 2, 3, 7};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[3], 7);
  s21::vector<int>::const_iterator pos = v.begin() + 3;
  v.insert_many(pos, 4, 5, 6);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[3], 4);
  EXPECT_EQ(v[4], 5);
  EXPECT_EQ(v[5], 6);
  EXPECT_EQ(v[6], 7);
}

/*

insert_many_back

*/

TEST(insert_many_back, ordinary1) {
  s21::vector<int> v{1, 2, 3, 7};

  v.insert_many_back(8, 9, 10);

  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[6], 10);
}

TEST(Insert, rvalue_1) {
  s21::vector<int> v{1, 2, 3, 7};
  std::vector<int> test{1, 2, 3, 7};

  v.insert(v.begin() + 3, 4);
  test.insert(test.begin() + 3, 4);
  EXPECT_EQ(v[0], test[0]);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], test[1]);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], test[2]);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[3], test[3]);
  EXPECT_EQ(v[3], 4);
  EXPECT_EQ(v[4], test[4]);
  EXPECT_EQ(v[4], 7);

  s21::vector<std::string> v_2{"abcd", "efg", "h"};
  std::vector<std::string> test_2{"abcd", "efg", "h"};
  v_2.insert(v_2.begin() + 1, "y");
  test_2.insert(test_2.begin() + 1, "y");
  EXPECT_EQ(v_2[0], test_2[0]);
  EXPECT_EQ(v_2[1], test_2[1]);
  EXPECT_EQ(v_2[1], "y");
  EXPECT_EQ(v_2[2], test_2[2]);
  EXPECT_EQ(v_2[2], "efg");
  EXPECT_EQ(v_2[3], test_2[3]);
  EXPECT_EQ(v_2[3], "h");

  // EXPECT_EQ(*(v.insert(v.begin(), "hello")), "hello");
  // EXPECT_EQ(*(v.insert(v.begin(), "world")), "world");
  // EXPECT_EQ(*(v.insert(v.end(), "my")), "my");

  // EXPECT_EQ(v.size(), 3);
  // EXPECT_EQ(v.capacity(), 4);
  // EXPECT_EQ(v[0], "world");
  // EXPECT_EQ(v[1], "hello");
  // EXPECT_EQ(v[2], "my");

  // EXPECT_EQ(*(v.insert(v.end(), "name")), "name");
  // EXPECT_EQ(*(v.insert(v.begin() + 1, "funny")), "funny");
  // EXPECT_EQ(*(v.insert(v.end() - 1, "is")), "is");

  // EXPECT_EQ(v[0], "world");
  // EXPECT_EQ(v[1], "funny");
  // EXPECT_EQ(v[2], "hello");
  // EXPECT_EQ(v[3], "my");
  // EXPECT_EQ(v[4], "is");
  // EXPECT_EQ(v[5], "name");

  // EXPECT_EQ(v.size(), 6);
  // EXPECT_EQ(v.capacity(), 8);
}

TEST(Insert, lvalue_1) {
  s21::vector<int> v{1, 2, 3, 7};
  std::vector<int> test{1, 2, 3, 7};

  int arg = 4;

  v.insert(v.begin() + 3, arg);
  test.insert(test.begin() + 3, arg);
  EXPECT_EQ(v[0], test[0]);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], test[1]);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], test[2]);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[3], test[3]);
  EXPECT_EQ(v[3], 4);
  EXPECT_EQ(v[4], test[4]);
  EXPECT_EQ(v[4], 7);

  s21::vector<std::string> v_2{"abcd", "efg", "h"};
  std::vector<std::string> test_2{"abcd", "efg", "h"};
  std::string arg_2 = "y";
  v_2.insert(v_2.begin() + 1, arg_2);
  test_2.insert(test_2.begin() + 1, arg_2);
  EXPECT_EQ(v_2[0], test_2[0]);
  EXPECT_EQ(v_2[1], test_2[1]);
  EXPECT_EQ(v_2[1], "y");
  EXPECT_EQ(v_2[2], test_2[2]);
  EXPECT_EQ(v_2[2], "efg");
  EXPECT_EQ(v_2[3], test_2[3]);
  EXPECT_EQ(v_2[3], "h");
}
#endif