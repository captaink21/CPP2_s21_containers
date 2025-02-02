

#include "../s21_test.h"

namespace s21 {

TEST(Constructor, Default) {
  s21::array<int, 8> v;
  std::array<int, 8> test;

  s21::array<int, 1> v_em;
  // std::array<int, 0> v_em_test;

  EXPECT_EQ(0, v.empty());
  EXPECT_EQ(0, v_em.empty());

  EXPECT_EQ(v.empty(), test.empty());
  // EXPECT_EQ(v_em.empty(), v_em_test.empty());
  EXPECT_EQ(v.size(), test.size());
}

TEST(Constructor, List) {
  s21::array<int, 5> v{1, 2, 3};
  std::array<int, 5> test{1, 2, 3};

  EXPECT_EQ(v.size(), test.size());
  EXPECT_EQ(v.empty(), test.empty());

  EXPECT_EQ(v.at(1), test.at(1));
  EXPECT_EQ(v[0], test[0]);
  EXPECT_EQ(v[3], test[3]);
  EXPECT_EQ(v.front(), test.front());
  EXPECT_EQ(v.back(), test.back());
  EXPECT_EQ(v.begin()[0], test.begin()[0]);
  EXPECT_EQ(v.end()[-1], test.end()[-1]);
}

TEST(Constructor, List2) {
  s21::array<std::string, 2> v{"Hello", "World"};
  std::array<std::string, 2> test{"Hello", "World"};

  EXPECT_EQ(v.size(), test.size());
  EXPECT_EQ(v.empty(), test.empty());

  EXPECT_EQ(v.at(1), test.at(1));
  EXPECT_EQ(v[0], test[0]);
  EXPECT_EQ(v[1], test[1]);
  EXPECT_EQ(v.front(), test.front());
  EXPECT_EQ(v.back(), test.back());
  EXPECT_EQ(v.begin()[0], test.begin()[0]);
  EXPECT_EQ(v.end()[-1], test.end()[-1]);
}

TEST(Constructor, ArrayReference) {
  s21::array<int, 5> a{1, 2, 3};

  s21::array<int, 5> v(a);
  std::array<int, 5> t{1, 2, 3};
  std::array<int, 5> test(t);

  EXPECT_EQ(v.size(), test.size());
  EXPECT_EQ(v.empty(), test.empty());
  EXPECT_EQ(v.at(1), test.at(1));
  EXPECT_EQ(v[0], test[0]);
  EXPECT_EQ(v[3], test[3]);
  EXPECT_EQ(v.front(), test.front());
  EXPECT_EQ(v.back(), test.back());
}

TEST(Constructor, ArrayMove) {
  s21::array<int, 5> a{1, 2, 3};
  s21::array<int, 5> v(std::move(a));
  std::array<int, 5> t{1, 2, 3};
  std::array<int, 5> test(std::move(t));
  EXPECT_EQ(v.size(), test.size());
  EXPECT_EQ(v.empty(), test.empty());
  EXPECT_EQ(v.at(1), test.at(1));
  EXPECT_EQ(v[0], test[0]);
  EXPECT_EQ(a[0], t[0]);
  EXPECT_EQ(v[3], test[3]);
  EXPECT_EQ(v.front(), test.front());
  EXPECT_EQ(v.back(), test.back());
  EXPECT_EQ(a.max_size(), t.max_size());
  EXPECT_EQ(v.max_size(), test.max_size());
}

TEST(Modifiers, swap) {
  s21::array<int, 5> swap_1{1, 2, 3};
  s21::array<int, 5> swap_2{4, 5, 6};
  s21::array<int, 5> swap_3{7, 8, 9};
  swap_1.swap(swap_2);
  swap_2.swap(swap_3);
  std::array<int, 5> swap_1orig{1, 2, 3};
  std::array<int, 5> swap_2orig{4, 5, 6};
  std::array<int, 5> swap_3orig{7, 8, 9};
  swap_1orig.swap(swap_2orig);
  swap_2orig.swap(swap_3orig);
  EXPECT_EQ(swap_1[0], swap_1orig[0]);
  EXPECT_EQ(swap_1[0], 4);
  EXPECT_EQ(swap_2[0], swap_2orig[0]);
  EXPECT_EQ(swap_2[0], 7);
}

TEST(Modifiers, fill) {
  s21::array<int, 5> v{1, 2, 3};
  v.fill(7);
  std::array<int, 5> test{4, 5, 6};
  test.fill(7);
  EXPECT_EQ(v[0], test[0]);
  EXPECT_EQ(v[4], test[4]);
  EXPECT_EQ(7, test[4]);
}

TEST(Member_func, operatar_eq) {
  s21::array<int, 5> v{1, 2, 3};
  s21::array<int, 5> v2{4, 5, 6};
  v = std::move(v2);
  EXPECT_EQ(v2[0], 4);
  EXPECT_EQ(v[0], 4);

  std::array<int, 5> test{1, 2, 3};
  std::array<int, 5> test2{4, 5, 6};
  test = std::move(test2);
  EXPECT_EQ(test2[0], 4);
  EXPECT_EQ(test[0], 4);
  EXPECT_EQ(v[0], test[0]);
  EXPECT_EQ(v2[0], test2[0]);
}

TEST(at, throw) {
  s21::array<int, 5> v{1, 2, 3};
  std::array<int, 5> test{1, 2, 3};

  EXPECT_THROW(v.at(5), std::out_of_range);
  EXPECT_THROW(test.at(5), std::out_of_range);

  EXPECT_EQ(v.size(), test.size());
}

TEST(element_access, throw) {
  s21::array<int, 5> v{1, 2, 3};
  std::array<int, 5> test{1, 2, 3};

  EXPECT_EQ(v[2], test[2]);
  EXPECT_EQ(v.at(1), test.at(1));
  EXPECT_EQ(v.front(), test.front());
  EXPECT_EQ(v.back(), test.back());
  EXPECT_EQ(*v.data(), *test.data());

  EXPECT_EQ(v.size(), test.size());
}

TEST(general, all_char) {
  s21::array<char, 5> v{'a', 'b', 'c'};
  std::array<char, 5> test{'a', 'b', 'c'};
  // print_orig(test);
  EXPECT_EQ(5, v.size());
  EXPECT_EQ(5, test.size());

  EXPECT_EQ(v[2], test[2]);
  EXPECT_EQ(v.at(1), test.at(1));
  EXPECT_EQ(v.front(), test.front());
  EXPECT_EQ(v.back(), test.back());
  EXPECT_EQ(*v.data(), *test.data());

  EXPECT_EQ(v.empty(), test.empty());
  EXPECT_EQ(v.size(), test.size());
  EXPECT_EQ(v.max_size(), test.max_size());

  EXPECT_EQ(v.begin()[0], test.begin()[0]);
  EXPECT_EQ(v.end()[-1], test.end()[-1]);
}

TEST(general, all) {
  s21::array<double, 5> v{1., 2., 3.};
  std::array<double, 5> test{1., 2., 3.};

  EXPECT_EQ(5, v.size());
  EXPECT_EQ(5, test.size());

  EXPECT_EQ(v[2], test[2]);
  EXPECT_EQ(v.at(1), test.at(1));
  EXPECT_EQ(v.front(), test.front());
  EXPECT_EQ(v.back(), test.back());
  EXPECT_EQ(*v.data(), *test.data());

  EXPECT_EQ(v.empty(), test.empty());
  EXPECT_EQ(v.size(), test.size());
  EXPECT_EQ(v.max_size(), test.max_size());

  EXPECT_EQ(v.begin()[0], test.begin()[0]);
  EXPECT_EQ(v.end()[-1], test.end()[-1]);
}

}  // namespace s21