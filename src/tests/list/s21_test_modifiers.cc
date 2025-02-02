#include "../s21_test.h"

/*
Clear
*/
#if 1
TEST(ListClear, ordinary1) {
  s21::list<std::string> list = {"hello", "world", "!"};
  list.clear();
  EXPECT_EQ(list.empty(), true);
}

TEST(ListClear, ordinary2) {
  s21::list<int> list = {1, 2, 3};
  list.clear();
  EXPECT_EQ(list.empty(), true);
}

TEST(ListClear, ordinary3) {
  s21::list<std::vector<int>> list = {{1, 2, 3}, {4, 5}, {6}};
  EXPECT_EQ(list.front()[0], 1);
  EXPECT_EQ(list.back()[0], 6);
  list.clear();
  EXPECT_EQ(list.empty(), true);
}

/*
iterator insert(iterator pos, const_reference value)
*/

TEST(ListInsert, ordinary1) {
  s21::list<std::string> list = {"hello", "world", "!"};
  std::string str = "s21";
  list.insert(++list.begin(), str);
  EXPECT_EQ(*(++list.begin()), str);
}

TEST(ListInsert, ordinary2) {
  s21::list<int> list = {1, 2, 3};
  list.insert(--list.end(), 9);
  EXPECT_EQ(*(--(--list.end())), 9);
}

TEST(ListInsert, ordinary3) {
  s21::list<std::vector<int>> list = {{1, 2, 3}, {4, 5}, {6}};
  list.insert(list.end(), {87, 88});
  EXPECT_EQ(list.back()[0], 87);
}

/*
void erase(iterator pos)
*/

TEST(ListErase, ordinary1) {
  s21::list<std::string> list = {"hello", "world", "!"};
  list.erase(list.begin());
  EXPECT_EQ(*(list.begin()), "world");
  EXPECT_EQ(list.size(), 2);
}

TEST(ListErase, ordinary2) {
  s21::list<int> list = {1, 2, 3};
  list.erase(--list.end());
  EXPECT_EQ(list.back(), 2);
}

TEST(ListErase, ordinary3) {
  s21::list<std::vector<int>> list = {{1, 2, 3}, {4, 5}, {6}};
  list.erase(--list.end());
  EXPECT_EQ(list.back()[0], 4);
}

/*
void push_back(const_reference value)
*/

TEST(ListPushBack, ordinary1) {
  s21::list<std::string> list;
  EXPECT_EQ(list.size(), 0);
  list.push_back("hello");
  EXPECT_EQ(list.front(), "hello");
  EXPECT_EQ(list.size(), 1);
}

TEST(ListPushBack, ordinary2) {
  s21::list<int> list = {1, 2, 3};
  list.push_back(4);
  EXPECT_EQ(list.back(), 4);
}

TEST(ListPushBack, ordinary3) {
  s21::list<std::vector<int>> list = {{1, 2, 3}, {4, 5}, {6}};
  list.push_back({87, 88});
  EXPECT_EQ(list.back()[0], 87);
}

/*
void pop_back()
*/

TEST(ListPopBack, ordinary1) {
  s21::list<std::string> list = {"hello"};
  EXPECT_EQ(list.size(), 1);
  list.pop_back();
  EXPECT_EQ(list.size(), 0);
}

TEST(ListPopBack, ordinary2) {
  s21::list<int> list = {1, 2, 3};
  EXPECT_EQ(list.back(), 3);
  EXPECT_EQ(list.size(), 3);
  list.pop_back();
  EXPECT_EQ(list.back(), 2);
  EXPECT_EQ(list.size(), 2);
}

TEST(ListPopBack, ordinary3) {
  s21::list<std::vector<int>> list = {{1, 2, 3}, {4, 5}, {6}};
  EXPECT_EQ(list.back()[0], 6);
  EXPECT_EQ(list.size(), 3);
  list.pop_back();
  EXPECT_EQ(list.back()[0], 4);
  EXPECT_EQ(list.size(), 2);
}

/*
void push_front(const_reference value)
*/

TEST(ListPushFront, ordinary1) {
  s21::list<std::string> list;
  EXPECT_EQ(list.size(), 0);
  list.push_front("hello");
  EXPECT_EQ(list.front(), "hello");
  EXPECT_EQ(list.size(), 1);
}

TEST(ListPushFront, ordinary2) {
  s21::list<int> list = {1, 2, 3};
  EXPECT_EQ(list.size(), 3);
  list.push_front(4);
  EXPECT_EQ(list.front(), 4);
  EXPECT_EQ(*(++list.begin()), 1);
  EXPECT_EQ(list.size(), 4);
}

TEST(ListPushFront, ordinary3) {
  s21::list<std::vector<int>> list = {{1, 2, 3}, {4, 5}, {6}};
  EXPECT_EQ(list.front()[0], 1);
  EXPECT_EQ(list.size(), 3);
  list.push_front({87, 88});
  EXPECT_EQ(list.front()[0], 87);
  EXPECT_EQ(list.size(), 4);
}

/*
void pop_front()
*/

TEST(ListPopFront, ordinary1) {
  s21::list<std::string> list = {"hello"};
  EXPECT_EQ(list.size(), 1);
  list.pop_front();
  EXPECT_EQ(list.size(), 0);
}

TEST(ListPopFront, ordinary2) {
  s21::list<int> list = {1, 2, 3};
  EXPECT_EQ(list.front(), 1);
  EXPECT_EQ(list.size(), 3);
  list.pop_front();
  EXPECT_EQ(list.front(), 2);
  EXPECT_EQ(list.size(), 2);
}

TEST(ListPopFront, ordinary3) {
  s21::list<std::vector<int>> list = {{1, 2, 3}, {4, 5}, {6}};
  EXPECT_EQ(list.front()[0], 1);
  EXPECT_EQ(list.size(), 3);
  list.pop_front();
  EXPECT_EQ(list.front()[0], 4);
  EXPECT_EQ(list.size(), 2);
}

/*
void swap(list& other)
*/

TEST(ListSwap, ordinary1) {
  s21::list<std::string> list1;
  list1.swap(list1);
  EXPECT_EQ(list1.size(), 0);
}

TEST(ListSwap, ordinary2) {
  s21::list<std::string> list1 = {"hello", "world"};
  s21::list<std::string> list2 = {"school", "21", "!"};
  EXPECT_EQ(list1.size(), 2);
  EXPECT_EQ(list2.size(), 3);
  EXPECT_EQ(list1.front(), "hello");
  EXPECT_EQ(list1.back(), "world");
  EXPECT_EQ(list2.front(), "school");
  EXPECT_EQ(*(++(list2.begin())), "21");
  EXPECT_EQ(list2.back(), "!");

  list1.swap(list2);

  EXPECT_EQ(list1.front(), "school");
  EXPECT_EQ(*(++(list1.begin())), "21");
  EXPECT_EQ(list1.back(), "!");
  EXPECT_EQ(list2.front(), "hello");
  EXPECT_EQ(list2.back(), "world");
  EXPECT_EQ(list1.size(), 3);
  EXPECT_EQ(list2.size(), 2);
}

TEST(ListSwap, ordinary3) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2 = {6, 5};
  EXPECT_EQ(list1.size(), 3);
  EXPECT_EQ(list1.front(), 1);
  EXPECT_EQ(list1.back(), 3);

  EXPECT_EQ(list2.size(), 2);
  EXPECT_EQ(list2.front(), 6);
  EXPECT_EQ(list2.back(), 5);
  list1.swap(list2);
  EXPECT_EQ(list2.size(), 3);
  EXPECT_EQ(list2.front(), 1);
  EXPECT_EQ(list2.back(), 3);

  EXPECT_EQ(list1.size(), 2);
  EXPECT_EQ(list1.front(), 6);
  EXPECT_EQ(list1.back(), 5);
}

TEST(ListSwap, ordinary4) {
  s21::list<std::vector<int>> list1 = {{1, 2, 3}, {4, 5}, {6}};
  s21::list<std::vector<int>> list2 = {{9}, {6, 10}};
  EXPECT_EQ(list1.front()[0], 1);
  EXPECT_EQ(list1.back()[0], 6);
  EXPECT_EQ(list1.size(), 3);

  EXPECT_EQ(list2.front()[0], 9);
  EXPECT_EQ(list2.back()[0], 6);
  EXPECT_EQ(list2.size(), 2);

  list1.swap(list2);

  EXPECT_EQ(list2.front()[0], 1);
  EXPECT_EQ(list2.back()[0], 6);
  EXPECT_EQ(list2.size(), 3);

  EXPECT_EQ(list1.front()[0], 9);
  EXPECT_EQ(list1.back()[0], 6);
  EXPECT_EQ(list1.size(), 2);
}

/*
void merge(list& other)
*/

TEST(ListMerge, ordinary1) {
  s21::list<std::string> list1;
  list1.merge(list1);
  EXPECT_EQ(list1.size(), 0);
}

TEST(ListMerge, ordinary2) {
  s21::list<std::string> list1 = {"abc", "fd"};
  s21::list<std::string> list2 = {"At", "bd", "cd"};
  EXPECT_EQ(list1.size(), 2);
  EXPECT_EQ(list2.size(), 3);

  list1.merge(list2);

  // for (auto i : list1) {
  //   std::cout << i << std::endl;
  // }
  // std::cout << std::endl;
  EXPECT_EQ(list1.front(), "At");
  EXPECT_EQ(*(++list1.begin()), "abc");
  EXPECT_EQ(*(++(++list1.begin())), "bd");
  EXPECT_EQ(*(++(++(++list1.begin()))), "cd");
  EXPECT_EQ(list1.back(), "fd");
  EXPECT_EQ(list1.size(), 5);
  EXPECT_EQ(list2.size(), 0);
}

TEST(ListMerge, ordinary3) {
  s21::list<std::string> list1 = {"abc", "cd"};
  s21::list<std::string> list2 = {"At", "bd", "fd"};
  EXPECT_EQ(list1.size(), 2);
  EXPECT_EQ(list2.size(), 3);

  list1.merge(list2);

  // for (auto i : list1) {
  //   std::cout << i << std::endl;
  // }
  // std::cout << std::endl;
  EXPECT_EQ(list1.front(), "At");
  EXPECT_EQ(*(++list1.begin()), "abc");
  EXPECT_EQ(*(++(++list1.begin())), "bd");
  EXPECT_EQ(*(++(++(++list1.begin()))), "cd");
  EXPECT_EQ(list1.back(), "fd");
  EXPECT_EQ(list1.size(), 5);
  EXPECT_EQ(list2.size(), 0);
}

TEST(ListMerge, ordinary4) {
  s21::list<std::string> list1 = {"At", "bd", "cd"};
  s21::list<std::string> list2 = {"abc", "fd"};
  EXPECT_EQ(list1.size(), 3);
  EXPECT_EQ(list2.size(), 2);

  list1.merge(list2);

  // for (auto i : list1) {
  //   std::cout << i << std::endl;
  // }
  // std::cout << std::endl;
  EXPECT_EQ(list1.front(), "At");
  EXPECT_EQ(*(++list1.begin()), "abc");
  EXPECT_EQ(*(++(++list1.begin())), "bd");
  EXPECT_EQ(*(++(++(++list1.begin()))), "cd");
  EXPECT_EQ(list1.back(), "fd");
  EXPECT_EQ(list1.size(), 5);
  EXPECT_EQ(list2.size(), 0);
}

TEST(ListMerge, ordinary5) {
  s21::list<std::string> list1 = {"At", "bd", "fd"};
  s21::list<std::string> list2 = {"abc", "cd"};
  EXPECT_EQ(list1.size(), 3);
  EXPECT_EQ(list2.size(), 2);

  list1.merge(list2);

  // for (auto i : list1) {
  //   std::cout << i << std::endl;
  // }
  // std::cout << std::endl;
  EXPECT_EQ(list1.front(), "At");
  EXPECT_EQ(*(++list1.begin()), "abc");
  EXPECT_EQ(*(++(++list1.begin())), "bd");
  EXPECT_EQ(*(++(++(++list1.begin()))), "cd");
  EXPECT_EQ(list1.back(), "fd");
  EXPECT_EQ(list1.size(), 5);
  EXPECT_EQ(list2.size(), 0);
}
// at abc bd cd fd
TEST(ListMerge, ordinary6) {
  s21::list<std::string> list1 = {"At", "bd", "cd", "de"};
  s21::list<std::string> list2 = {"abc", "fd"};
  EXPECT_EQ(list1.size(), 4);
  EXPECT_EQ(list2.size(), 2);

  list1.merge(list2);

  // for (auto i : list1) {
  //   std::cout << i << std::endl;
  // }
  // std::cout << std::endl;
  EXPECT_EQ(list1.front(), "At");
  EXPECT_EQ(*(++list1.begin()), "abc");
  EXPECT_EQ(*(++(++list1.begin())), "bd");
  EXPECT_EQ(*(++(++(++list1.begin()))), "cd");
  EXPECT_EQ(*(++(++(++(++list1.begin())))), "de");
  EXPECT_EQ(list1.back(), "fd");
  EXPECT_EQ(list1.size(), 6);
  EXPECT_EQ(list2.size(), 0);
}

TEST(ListMerge, ordinary7) {
  s21::list<std::string> list1 = {"At", "bd", "cd", "ef"};
  s21::list<std::string> list2 = {"abc", "dd"};
  EXPECT_EQ(list1.size(), 4);
  EXPECT_EQ(list2.size(), 2);

  list1.merge(list2);

  // for (auto i : list1) {
  //   std::cout << i << std::endl;
  // }
  // std::cout << std::endl;
  EXPECT_EQ(list1.front(), "At");
  EXPECT_EQ(*(++list1.begin()), "abc");
  EXPECT_EQ(*(++(++list1.begin())), "bd");
  EXPECT_EQ(*(++(++(++list1.begin()))), "cd");
  EXPECT_EQ(*(++(++(++(++list1.begin())))), "dd");
  EXPECT_EQ(list1.back(), "ef");
  EXPECT_EQ(list1.size(), 6);
  EXPECT_EQ(list2.size(), 0);
}

/*
1
1 2 3
4 10
4 10
5 6
6
9
*/
TEST(ListMerge, ordinary8) {
  s21::list<std::vector<int>> list1 = {{1, 2, 3}, {4, 10}, {5, 6}, {6}};
  s21::list<std::vector<int>> list2 = {{1}, {4, 10}, {9}};
  EXPECT_EQ(list1.size(), 4);
  EXPECT_EQ(list2.size(), 3);

  std::list<std::vector<int>> std_list1 = {{1, 2, 3}, {4, 10}, {5, 6}, {6}};
  std::list<std::vector<int>> std_list2 = {{1}, {4, 10}, {9}};

  list1.merge(list2);
  std_list1.merge(std_list2);

  auto std_it = std_list1.begin();
  for (const auto& vec : list1) {
    EXPECT_EQ(vec.size(), std_it->size());
    for (size_t j = 0; j < vec.size(); j++) {
      EXPECT_EQ(vec[j], (*std_it)[j]);
    }
    ++std_it;
  }

  EXPECT_EQ(list1.size(), 7);
  EXPECT_EQ(list2.size(), 0);
}

/*
void splice(const_iterator pos, list& other)
*/

TEST(ListSplice, ordinary2) {
  std::list<std::string> std_list1 = {"abc", "fd"};
  std::list<std::string> std_list2 = {"At", "bd", "cd"};

  auto std_it = std_list1.begin();
  std::advance(std_it, 1);
  std_list1.splice(std_it, std_list2);

  s21::list<std::string> list1 = {"abc", "fd"};
  s21::list<std::string> list2 = {"At", "bd", "cd"};
  auto it = list1.cbegin();
  list1.splice(++it, list2);

  auto st_std = std_list1.begin();
  auto st = list1.begin();
  while (st_std != std_list1.end() && st != list1.end()) {
    // std::cout << *st << *st_std << std::endl;
    EXPECT_EQ(*st, *st_std);
    ++st;
    ++st_std;
  }
}

TEST(ListSplice, ordinary3) {
  std::list<std::string> std_list1 = {"abc", "fd"};
  std::list<std::string> std_list2 = {"At", "bd", "cd"};

  auto std_it = std_list1.begin();
  std::advance(std_it, 0);
  std_list1.splice(std_it, std_list2);

  s21::list<std::string> list1 = {"abc", "fd"};
  s21::list<std::string> list2 = {"At", "bd", "cd"};
  auto it = list1.cbegin();
  list1.splice(it, list2);

  auto st_std = std_list1.begin();
  auto st = list1.begin();
  while (st_std != std_list1.end() && st != list1.end()) {
    // std::cout << *st << *st_std << std::endl;
    EXPECT_EQ(*st, *st_std);
    ++st;
    ++st_std;
  }
}

TEST(ListSplice, ordinary4) {
  std::list<std::string> std_list1 = {"abc", "fd"};
  std::list<std::string> std_list2 = {"At", "bd", "cd"};

  auto std_it = std_list1.begin();
  std::advance(std_it, 2);
  std_list1.splice(std_it, std_list2);

  s21::list<std::string> list1 = {"abc", "fd"};
  s21::list<std::string> list2 = {"At", "bd", "cd"};
  auto it = list1.cend();
  list1.splice(it, list2);

  auto st_std = std_list1.begin();
  auto st = list1.begin();
  while (st_std != std_list1.end() && st != list1.end()) {
    // std::cout << *st << *st_std << std::endl;
    EXPECT_EQ(*st, *st_std);
    ++st;
    ++st_std;
  }
}

TEST(ListSplice, ordinary5) {
  std::list<int> std_list1{1, 2, 3, 4, 5};
  std::list<int> std_list2{10, 20, 30, 40, 50};
  auto std_it = std_list1.begin();
  std::advance(std_it, 2);
  std_list1.splice(std_it, std_list2);

  s21::list<int> list1{1, 2, 3, 4, 5};
  s21::list<int> list2{10, 20, 30, 40, 50};
  auto it = list1.cbegin();
  list1.splice(++(++it), list2);

  auto st_std = std_list1.begin();
  auto st = list1.begin();
  while (st_std != std_list1.end() && st != list1.end()) {
    EXPECT_EQ(*st, *st_std);
    ++st;
    ++st_std;
  }
}

TEST(ListSplice, ordinary6) {
  std::list<int> std_list1{1, 2, 3, 4, 5};
  std::list<int> std_list2{10, 20, 30, 40, 50};
  auto std_it = std_list1.begin();
  std::advance(std_it, 0);
  std_list1.splice(std_it, std_list2);

  s21::list<int> list1{1, 2, 3, 4, 5};
  s21::list<int> list2{10, 20, 30, 40, 50};
  auto it = list1.cbegin();
  list1.splice(it, list2);

  auto st_std = std_list1.begin();
  auto st = list1.begin();
  while (st_std != std_list1.end() && st != list1.end()) {
    EXPECT_EQ(*st, *st_std);
    ++st;
    ++st_std;
  }
}

/*
void reverse()
*/

TEST(ListReverse, ordinary1) {
  s21::list<std::string> list1 = {"abc", "fd", "mda"};
  EXPECT_EQ(list1.size(), 3);
  list1.reverse();
  EXPECT_EQ(list1.size(), 3);
  EXPECT_EQ(list1.front(), "mda");
  EXPECT_EQ(*(++list1.begin()), "fd");
  EXPECT_EQ(list1.back(), "abc");
}

TEST(ListReverse, ordinary2) {
  s21::list<std::vector<int>> list1 = {{1, 2}, {3, 4}};
  EXPECT_EQ(list1.size(), 2);
  list1.reverse();
  EXPECT_EQ(list1.size(), 2);
  EXPECT_EQ(list1.front()[0], 3);
  EXPECT_EQ(list1.back()[0], 1);
}

/*
void unique()
*/

TEST(ListUnique, ordinary1) {
  s21::list<std::string> list1 = {"abc", "fd", "mda"};
  EXPECT_EQ(list1.size(), 3);
  list1.unique();
  EXPECT_EQ(list1.size(), 3);
  EXPECT_EQ(list1.front(), "abc");
  EXPECT_EQ(*(++list1.begin()), "fd");
  EXPECT_EQ(list1.back(), "mda");
}

TEST(ListUnique, ordinary2) {
  s21::list<std::string> list1 = {"abc", "fd", "mda", "mda"};
  EXPECT_EQ(list1.size(), 4);
  list1.unique();
  EXPECT_EQ(list1.size(), 3);
  EXPECT_EQ(list1.front(), "abc");
  EXPECT_EQ(*(++list1.begin()), "fd");
  EXPECT_EQ(list1.back(), "mda");
}

TEST(ListUnique, ordinary3) {
  s21::list<std::string> list1 = {"abc", "abc", "fd", "mda", "mda"};
  EXPECT_EQ(list1.size(), 5);
  list1.unique();
  EXPECT_EQ(list1.size(), 3);
  EXPECT_EQ(list1.front(), "abc");
  EXPECT_EQ(*(++list1.begin()), "fd");
  EXPECT_EQ(list1.back(), "mda");
}

TEST(ListUnique, ordinary4) {
  s21::list<std::string> list1 = {"abc", "abc", "fd", "mda", "fd", "mda"};
  EXPECT_EQ(list1.size(), 6);
  list1.unique();
  EXPECT_EQ(list1.size(), 5);
  EXPECT_EQ(list1.front(), "abc");
  EXPECT_EQ(*(++list1.begin()), "fd");
  EXPECT_EQ(list1.back(), "mda");
}

TEST(ListUnique, ordinary5) {
  s21::list<std::vector<int>> list1 = {{1, 2}, {3, 4}, {3, 4},
                                       {5, 6}, {3, 4}, {5, 6}};
  EXPECT_EQ(list1.size(), 6);
  list1.unique();
  EXPECT_EQ(list1.size(), 5);
  EXPECT_EQ(list1.front()[0], 1);
  EXPECT_EQ(list1.front()[1], 2);
  EXPECT_EQ(list1.back()[0], 5);
  EXPECT_EQ(list1.back()[1], 6);
}

/*
void sort()
*/

TEST(ListSort, ordinary1) {
  s21::list<std::string> list1 = {"abc", "fd", "mda"};
  EXPECT_EQ(list1.size(), 3);
  list1.sort();
  EXPECT_EQ(list1.size(), 3);
  EXPECT_EQ(list1.front(), "abc");
  EXPECT_EQ(*(++list1.begin()), "fd");
  EXPECT_EQ(list1.back(), "mda");
}

TEST(ListSort, ordinary2) {
  s21::list<std::string> list1 = {"b", "a", "ad", "c", "ab"};
  std::list<std::string> std_list1 = {"b", "a", "ad", "c", "ab"};
  EXPECT_EQ(list1.size(), 5);
  list1.sort();
  std_list1.sort();
  EXPECT_EQ(list1.size(), 5);
  auto std = std_list1.begin();
  auto it = list1.begin();
  while (std != std_list1.end() && it != list1.end()) {
    // std::cout << *std << *it << std::endl;
    EXPECT_EQ(*std, *it);
    ++std;
    ++it;
  }
}

TEST(ListSort, ordinary3) {
  s21::list<std::string> list1 = {"b"};
  std::list<std::string> std_list1 = {"b"};
  EXPECT_EQ(list1.size(), 1);
  list1.sort();
  std_list1.sort();
  EXPECT_EQ(list1.size(), 1);
  auto std = std_list1.begin();
  auto it = list1.begin();
  while (std != std_list1.end() && it != list1.end()) {
    EXPECT_EQ(*std, *it);
    ++std;
    ++it;
  }
}

TEST(ListSort, ordinary4) {
  s21::list<std::string> list1 = {"a", "b"};
  std::list<std::string> std_list1 = {"a", "b"};
  EXPECT_EQ(list1.size(), 2);
  list1.sort();
  std_list1.sort();
  EXPECT_EQ(list1.size(), 2);
  auto std = std_list1.begin();
  auto it = list1.begin();
  while (std != std_list1.end() && it != list1.end()) {
    EXPECT_EQ(*std, *it);
    ++std;
    ++it;
  }
}

TEST(ListSort, ordinary5) {
  s21::list<std::vector<int>> list1 = {{5, 5}, {1, 3}, {1}, {5, 4}, {10}};
  std::list<std::vector<int>> std_list1 = {{5, 5}, {1, 3}, {1}, {5, 4}, {10}};
  EXPECT_EQ(list1.size(), 5);
  list1.sort();
  std_list1.sort();
  EXPECT_EQ(list1.size(), 5);
  auto std = std_list1.begin();
  for (auto& vec : list1) {
    for (size_t i = 0; i < vec.size(); i++) {
      // std::cout << vec[i] << (*std)[i] << std::endl;
      EXPECT_EQ(vec[i], (*std)[i]);
    }
    ++std;
  }
}

/*

list insert many

*/

TEST(ListInsertMany, ordinary1) {
  s21::list<int> list_int = {1, 2, 6, 11};
  list_int.insert_many(list_int.cbegin(), 3, 4, 5);

  EXPECT_EQ(list_int.size(), 7);
  auto it = list_int.begin();
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 6);
  EXPECT_EQ(*it++, 11);

  it = list_int.begin();
  for (; it != list_int.end(); ++it) {
    // std::cout << *it << std::endl;
  }
}

TEST(ListInsertMany, ordinary2) {
  s21::list<int> list_int = {1, 2, 6, 11};
  list_int.insert_many(list_int.cend(), 3, 4, 6);

  EXPECT_EQ(list_int.size(), 7);
  auto it = list_int.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 6);
  EXPECT_EQ(*it++, 11);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 6);

  it = list_int.begin();
  for (; it != list_int.end(); ++it) {
    // std::cout << *it << std::endl;
  }
}

TEST(ListInsertMany, ordinary3) {
  s21::list<int> list_int = {1, 2, 6, 11};
  s21::list<int>::const_iterator it = list_int.cbegin();
  it++;
  it++;
  list_int.insert_many(it, 3, 4, 6);

  EXPECT_EQ(list_int.size(), 7);
  it = list_int.cbegin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 6);
  EXPECT_EQ(*it++, 6);
  EXPECT_EQ(*it++, 11);

  it = list_int.cbegin();
  for (; it != list_int.cend(); ++it) {
    // std::cout << *it << std::endl;
  }
}

TEST(ListInsertMany, ordinary4) {
  s21::list<int> list_int = {1, 2, 6, 11};
  s21::list<int>::const_iterator it = list_int.cbegin();
  it++;
  it++;
  int a = 3, b = 4, c = 6;
  list_int.insert_many(it, a, b, c);

  EXPECT_EQ(list_int.size(), 7);
  it = list_int.cbegin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 6);
  EXPECT_EQ(*it++, 6);
  EXPECT_EQ(*it++, 11);

  it = list_int.cbegin();
  for (; it != list_int.cend(); ++it) {
    // std::cout << *it << std::endl;
  }
}

TEST(ListInsertMany, ordinary5) {
  s21::list<s21::vector<int>> list_int{s21::vector<int>{1, 2, 6, 11}};
  s21::list<s21::vector<int>>::const_iterator it = list_int.cbegin();

  s21::vector<int> a = {3, 4, 6};

  list_int.insert_many(it, std::move(a), s21::vector<int>{5, 6, 7});
}

TEST(ListInsertMany, ordinary6) {
  s21::list<s21::vector<int>> list_int{s21::vector<int>{1, 2, 6, 11}};
  s21::list<s21::vector<int>>::const_iterator it = list_int.cbegin();

  s21::vector<int> a = {3, 4, 6};
  s21::vector<int> b{5, 6, 7};

  list_int.insert_many(it, a, b);
}

TEST(ListInsertMany, ordinary7) {
  s21::list<int> list_int = {1, 2, 6, 11};
  s21::list<int>::const_iterator it = list_int.cbegin();
  it++;
  it++;
  int c = 6;
  list_int.insert_many(it, 3, 4, c);

  EXPECT_EQ(list_int.size(), 7);
  it = list_int.cbegin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 6);
  EXPECT_EQ(*it++, 6);
  EXPECT_EQ(*it++, 11);

  it = list_int.cbegin();
  for (; it != list_int.cend(); ++it) {
    // std::cout << *it << std::endl;
  }
}

/*

list insert many back

*/

TEST(ListInsertManyBack, ordinary1) {
  s21::list<int> list_int = {1, 2, 6, 11};
  list_int.insert_many_back(3, 4, 6);

  EXPECT_EQ(list_int.size(), 7);
  auto it = list_int.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 6);
  EXPECT_EQ(*it++, 11);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 6);

  it = list_int.begin();
  for (; it != list_int.end(); ++it) {
    // std::cout << *it << std::endl;
  }
}

TEST(ListInsertManyBack, ordinary2) {
  s21::list<int> list_int;
  list_int.insert_many_back(3, 4, 6);

  EXPECT_EQ(list_int.size(), 3);
  auto it = list_int.begin();
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 6);

  it = list_int.begin();
  for (; it != list_int.end(); ++it) {
    // std::cout << *it << std::endl;
  }
}

TEST(ListInsertManyBack, ordinary3) {
  s21::list<std::string> list_int;
  list_int.insert_many_back("3", "4", "6");

  EXPECT_EQ(list_int.size(), 3);
  auto it = list_int.begin();
  EXPECT_EQ(*it++, "3");
  EXPECT_EQ(*it++, "4");
  EXPECT_EQ(*it++, "6");

  it = list_int.begin();
  for (; it != list_int.end(); ++it) {
    // std::cout << *it << std::endl;
  }
}

TEST(ListInsertManyBack, ordinary4) {
  s21::list<std::string> list_int;
  std::string a = "3", b = "4", c = "6";
  list_int.insert_many_back(a, b, c);

  EXPECT_EQ(list_int.size(), 3);
  auto it = list_int.begin();
  EXPECT_EQ(*it++, "3");
  EXPECT_EQ(*it++, "4");
  EXPECT_EQ(*it++, "6");

  it = list_int.begin();
  for (; it != list_int.end(); ++it) {
    // std::cout << *it << std::endl;
  }
}

/*

list insert many front

*/

TEST(ListInsertManyFront, ordinary1) {
  s21::list<int> list_int = {1, 2, 6, 11};
  list_int.insert_many_front(3, 4, 6);

  EXPECT_EQ(list_int.size(), 7);
  auto it = list_int.begin();
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 6);
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 6);
  EXPECT_EQ(*it++, 11);

  it = list_int.begin();
  for (; it != list_int.end(); ++it) {
    // std::cout << *it << std::endl;
  }
}

TEST(ListInsertManyFront, ordinary2) {
  s21::list<int> list_int;
  list_int.insert_many_front(3, 4, 6);

  EXPECT_EQ(list_int.size(), 3);
  auto it = list_int.begin();
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 6);

  it = list_int.begin();
  for (; it != list_int.end(); ++it) {
    // std::cout << *it << std::endl;
  }
}

TEST(ListInsertManyFront, ordinary3) {
  s21::list<int> list_int;
  int a = 3, b = 4, c = 6;

  list_int.insert_many_front(a, b, c);

  EXPECT_EQ(list_int.size(), 3);
  auto it = list_int.begin();
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 6);

  it = list_int.begin();
  for (; it != list_int.end(); ++it) {
    // std::cout << *it << std::endl;
  }
}

TEST(ListInsertManyFront, ordinary4) {
  s21::list<int> list_int;
  int a = 3, b = 4, c = 6;

  list_int.insert_many_front(a, b, c);

  EXPECT_EQ(list_int.size(), 3);
  auto it = list_int.begin();
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 6);

  it = list_int.begin();
  for (; it != list_int.end(); ++it) {
    // std::cout << *it << std::endl;
  }
}

TEST(ListInsertManyFront, ordinary5) {
  s21::list<s21::vector<int>> list_int{s21::vector<int>{0, 1, 2}};
  s21::vector<int> a = {3, 4, 6};
  // s21::vector<int> b = {5, 6, 7};

  list_int.insert_many_front(std::move(a), s21::vector<int>{5, 6, 7});

  EXPECT_EQ(list_int.size(), 3);
  auto it = list_int.begin();
  EXPECT_EQ((*it)[0], 3);
  EXPECT_EQ((*it)[1], 4);
  ++it;
  EXPECT_EQ((*it)[2], 7);
  ++it;
  EXPECT_EQ((*it)[1], 1);
}

TEST(ListInsertManyFront, ordinary6) {
  s21::list<s21::vector<int>> list_int;
  s21::vector<int> a = {3, 4, 6};
  s21::vector<int> b = {5, 6, 7};

  list_int.insert_many_front(a, b);

  EXPECT_EQ(list_int.size(), 2);
  auto it = list_int.begin();
  EXPECT_EQ((*it)[0], 3);
  EXPECT_EQ((*it)[1], 4);
  ++it;
  EXPECT_EQ((*it)[2], 7);
}

#endif