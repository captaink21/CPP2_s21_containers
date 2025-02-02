#ifndef S21_ARRAY_ITERATORS_CC
#define S21_ARRAY_ITERATORS_CC

#include "s21_array.h"

namespace s21 {

template <typename T, std::size_t N>
T* array<T, N>::begin() {
  return data_;
}

template <typename T, std::size_t N>
T* array<T, N>::end() {
  return (this->data_ + this->size_);
}

}  // namespace s21

#endif