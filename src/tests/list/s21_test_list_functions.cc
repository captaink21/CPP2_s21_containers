#include <list>

#include "../s21_test.h"
/*
Ctor default
*/

TEST(ListDefaultCntr, ordinary1) {
  s21::list<int> l;
  EXPECT_EQ(l.size(), 0);
  EXPECT_EQ(l.begin(), l.end());

  s21::list<unsigned long long> l_un;
  EXPECT_EQ(l_un.size(), 0);
  EXPECT_EQ(l_un.begin(), l_un.end());

  s21::list<std::string> l_string;
  EXPECT_EQ(l_string.size(), 0);
  EXPECT_EQ(l_string.begin(), l_string.end());

  s21::list<std::vector<int>> l_vectors;
  EXPECT_EQ(l_vectors.size(), 0);
  EXPECT_EQ(l_vectors.begin(), l_vectors.end());
}

/*
Ctor param
*/

TEST(ListParamCntr, ordinary1) {
  s21::list<int> l(2);
  EXPECT_EQ(l.size(), 2);
  EXPECT_EQ(l.begin().get_node()->prev_, (++l.begin()).get_node()->next_);

  s21::list<unsigned long long> l_un(1);
  EXPECT_EQ(l_un.size(), 1);
  EXPECT_EQ(l_un.begin().get_node()->prev_, l_un.begin().get_node()->next_);

  s21::list<std::string> l_string(100);
  EXPECT_EQ(l_string.size(), 100);
  int i = 0;
  for (auto it = l_string.begin(); it != l_string.end(); ++it, i++) {
  }
  EXPECT_EQ(i, 100);
}

/*
initializer list constructor
*/
TEST(ListInitializerListCntr, ordinary1) {
  s21::list<int> l = {1, 3, 4};
  EXPECT_EQ(l.size(), 3);
  EXPECT_EQ(l.front(), 1);
  EXPECT_EQ(l.back(), 4);

  std::list<std::string> list_string = {"first", "second", "third"};
  EXPECT_EQ(list_string.size(), 3);
  EXPECT_EQ(list_string.front(), "first");
  EXPECT_EQ(list_string.back(), "third");
}

TEST(ListInitializerListCntr, ordinary2) {
  s21::list<std::vector<int>> l = {{1, 2, 3}, {4, 5, 6}};
  EXPECT_EQ(l.size(), 2);
  EXPECT_EQ(l.front()[0], 1);
  EXPECT_EQ(l.back()[0], 4);
}

/*
Ctor copy
*/

TEST(ListCopyCtor, ordinary1) {
  s21::list<int> l1 = {3, 2, 5};
  s21::list<int> l2(l1);
  EXPECT_EQ(l1.size(), 3);
  EXPECT_EQ(l1.front(), 3);
  EXPECT_EQ(l1.back(), 5);

  EXPECT_EQ(l2.size(), 3);
  EXPECT_EQ(l2.front(), 3);
  EXPECT_EQ(l2.back(), 5);

  s21::list<std::string> l3 = {"first", "second", "third"};
  s21::list<std::string> l4(l3);
  EXPECT_EQ(l3.size(), 3);
  EXPECT_EQ(l3.front(), "first");
  EXPECT_EQ(l3.back(), "third");

  EXPECT_EQ(l4.size(), 3);
  EXPECT_EQ(l4.front(), "first");
  EXPECT_EQ(l4.back(), "third");
}

/*
Ctor move
*/

TEST(ListMoveCtor, ordinary1) {
  s21::list<std::string> l1 = {"first", "second", "third"};
  s21::list<std::string> l2(std::move(l1));
  EXPECT_EQ(l1.size(), 0);
  EXPECT_EQ(l1.begin(), l1.end());

  EXPECT_EQ(l2.size(), 3);
  EXPECT_EQ(l2.front(), "first");
  EXPECT_EQ(l2.back(), "third");
}

TEST(ListMoveCtor, ordinary2) {
  std::vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = {4, 5};
  s21::list<std::vector<int>> l3 = {vec1, vec2};
  s21::list<std::vector<int>> l4(std::move(l3));
  EXPECT_EQ(l3.size(), 0);
  EXPECT_EQ(l3.begin(), l3.end());

  EXPECT_EQ(l4.size(), 2);
  EXPECT_EQ(l4.front()[0], 1);
  EXPECT_EQ(l4.back()[1], 5);
}

/*
Assign move
*/

TEST(ListAssignMoveOperator, ordinary1) {
  s21::list<int> lst1 = {2, 5, 7};
  s21::list<int> lst2;

  EXPECT_EQ(lst1.size(), 3);
  EXPECT_EQ(lst1.front(), 2);
  EXPECT_EQ(lst1.back(), 7);

  EXPECT_EQ(lst2.size(), 0);
  EXPECT_EQ(lst2.begin(), lst2.end());

  lst2 = (std::move(lst1));

  EXPECT_EQ(lst1.size(), 0);
  EXPECT_EQ(lst1.begin(), lst1.end());

  // for (auto& elem : lst2) {
  //   std::cout << elem << " - " << lst2.size() << std::endl;
  // }
  EXPECT_EQ(lst2.size(), 3);
  EXPECT_EQ(lst2.front(), 2);
  // std::cout << lst2.front() << std::endl;
  // std::cout << lst2.back() << std::endl;
  EXPECT_EQ(lst2.back(), 7);

  s21::list<std::string> l1 = {"first", "second", "third"};
  s21::list<std::string> l2;

  EXPECT_EQ(l1.size(), 3);
  EXPECT_EQ(l1.front(), "first");
  EXPECT_EQ(l1.back(), "third");

  EXPECT_EQ(l2.size(), 0);
  EXPECT_EQ(l2.begin(), l2.end());

  l2 = std::move(l1);

  EXPECT_EQ(l1.size(), 0);
  EXPECT_EQ(l1.begin(), l1.end());
  // for (auto& elem : l2) {
  //   std::cout << elem << " - " << l2.size() << std::endl;
  // }
  EXPECT_EQ(l2.size(), 3);
  EXPECT_EQ(l2.front(), "first");
  // std::cout << l2.front() << std::endl;
  // std::cout << l2.back() << std::endl;
  EXPECT_EQ(l2.back(), "third");
  // EXPECT_EQ(l2.begin(), ++(++(++(++l2.begin()))));
  // std::cout << *(++(++l2.begin())) << std::endl;
  EXPECT_EQ(l2.back(), "third");
}

TEST(ListAssignMoveOperator, ordinary2) {
  s21::list<int> lst1 = {2, 5, 7};
  s21::list<int> lst2;

  EXPECT_EQ(lst1.size(), 3);
  EXPECT_EQ(lst1.front(), 2);
  EXPECT_EQ(lst1.back(), 7);

  EXPECT_EQ(lst2.size(), 0);
  EXPECT_EQ(lst2.begin(), lst2.end());

  lst2 = (std::move(lst1));

  EXPECT_EQ(lst1.size(), 0);
  EXPECT_EQ(lst1.begin(), lst1.end());

  // for (auto& elem : lst2) {
  //   std::cout << elem << " - " << lst2.size() << std::endl;
  // }
  EXPECT_EQ(lst2.size(), 3);
  EXPECT_EQ(lst2.front(), 2);
  // std::cout << lst2.front() << std::endl;
  // std::cout << lst2.back() << std::endl;
  EXPECT_EQ(lst2.back(), 7);

  s21::list<std::string> l1 = {"first", "second", "third"};
  s21::list<std::string> l2;

  EXPECT_EQ(l1.size(), 3);
  EXPECT_EQ(l1.front(), "first");
  EXPECT_EQ(l1.back(), "third");

  EXPECT_EQ(l2.size(), 0);
  EXPECT_EQ(l2.begin(), l2.end());

  l1.swap(l2);

  EXPECT_EQ(l1.size(), 0);
  EXPECT_EQ(l1.begin(), l1.end());
  // for (auto& elem : l2) {
  //   std::cout << elem << " - " << l2.size() << std::endl;
  // }
  EXPECT_EQ(l2.size(), 3);
  EXPECT_EQ(l2.front(), "first");
  // std::cout << l2.front() << std::endl;
  // std::cout << l2.back() << std::endl;
  EXPECT_EQ(l2.back(), "third");
  EXPECT_EQ(l2.begin(), ++(++(++(++l2.begin()))));
  // std::cout << *(++(++l2.begin())) << std::endl;
  EXPECT_EQ(l2.back(), "third");
}

TEST(ListAssignMoveOperator, ordinary3) {
  s21::list<int> lst1 = {2, 5, 7};
  s21::list<int> lst2;

  EXPECT_EQ(lst1.size(), 3);
  EXPECT_EQ(lst1.front(), 2);
  EXPECT_EQ(lst1.back(), 7);

  EXPECT_EQ(lst2.size(), 0);
  EXPECT_EQ(lst2.begin(), lst2.end());

  std::swap(lst2, lst1);

  EXPECT_EQ(lst1.size(), 0);
  EXPECT_EQ(lst1.begin(), lst1.end());

  EXPECT_EQ(lst2.size(), 3);
  EXPECT_EQ(lst2.front(), 2);
  EXPECT_EQ(lst2.back(), 7);
}
