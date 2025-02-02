#ifndef S21_ARRAY_CAPACITY_CC
#define S21_ARRAY_CAPACITY_CC

#include "s21_array.h"

namespace s21 {

template <typename T, std::size_t N>
bool array<T, N>::empty() const {
  return this->size_ == 0;
}

template <typename T, std::size_t N>
std::size_t array<T, N>::size() const {
  return this->size_;
}

template <typename T, std::size_t N>
std::size_t array<T, N>::max_size() {
  return this->size_;
}

}  // namespace s21

#endif