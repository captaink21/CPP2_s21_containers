#ifndef S21_ARRAY_MEMBER_FUNC_CC
#define S21_ARRAY_MEMBER_FUNC_CC

#include "s21_array.h"

namespace s21 {

template <typename T, std::size_t N>
array<T, N>::array() : size_(N) {}

template <typename T, std::size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) : size_(N) {
  std::size_t s = std::min(static_cast<size_t>(items.size()), N);

  for (size_t i = 0; i < s; ++i) {
    data_[i] = items.begin()[i];
  }
  for (size_t i = s; i < N; ++i) {
    data_[i] = T();
  }
}

template <typename T, std::size_t N>
array<T, N>::array(const array &a) : size_(N) {
  std::size_t s = std::min(a.size(), N);
  for (size_t i = 0; i < s; ++i) {
    data_[i] = a[i];
  }
}

template <typename T, std::size_t N>
array<T, N>::array(array &&a) noexcept : size_(N) {
  std::size_t s = std::min(a.size(), N);
  for (size_t i = 0; i < s; ++i) {
    data_[i] = a[i];
  }
};

template <typename T, size_t N>
array<T, N>::~array() {}

template <typename T, size_t N>
array<T, N> &array<T, N>::operator=(array &&a) noexcept {
  std::size_t s = std::min(a.size(), N);
  if (this != &a) {
    for (size_t i = 0; i < s; ++i) {
      data_[i] = a[i];
    }
  }
  return *this;
}

}  // namespace s21

#endif