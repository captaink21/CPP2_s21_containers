#ifndef S21_ARRAY_MODIFIERS_CC
#define S21_ARRAY_MODIFIERS_CC

#include "s21_array.h"

namespace s21 {

template <typename T, std::size_t N>
void array<T, N>::swap(array& other) {
  if (this != &other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
  }
}

template <typename T, std::size_t N>
void array<T, N>::fill(const_reference value) {
  for (size_t i = 0; i < this->size_; ++i) {
    data_[i] = value;
  }
}

}  // namespace s21

#endif