#ifndef S21_ARRAY_ELEMENT_ACCESS_CC
#define S21_ARRAY_ELEMENT_ACCESS_CC

#include "s21_array.h"

namespace s21 {

template <typename T, std::size_t N>
T& array<T, N>::at(size_type pos) {
  if (pos >= size()) {
    throw std::out_of_range("array::at index out of range");
  }
  return (*this)[pos];
}

template <typename T, std::size_t N>
T& array<T, N>::operator[](std::size_t pos) {
  return *(data_ + pos);
}

template <typename T, std::size_t N>
T array<T, N>::operator[](std::size_t pos) const {
  return *(data_ + pos);
}

template <typename T, std::size_t N>
const T& array<T, N>::front() {
  return *(data_);
}

template <typename T, std::size_t N>
const T& array<T, N>::back() {
  return (*this)[size() - 1];
}

template <typename T, std::size_t N>
T* array<T, N>::data() {
  return this->data_;
}

#if 0
template <typename T, std::size_t N>
void print_array(s21::array<T, N> a) {
  size_t s = a.size();
  std::cout << "-----------our------------" << std::endl;
  for (size_t i = 0; i < s; ++i) std::cout << a[i] << "/ ";
  std::cout << std::endl << "--------------------------" << std::endl;
}

template <typename T, std::size_t N>
void print_orig(std::array<T, N> a) {
  size_t s = a.size();
  std::cout << "-----------original------------" << std::endl;
  for (size_t i = 0; i < s; ++i) std::cout << a[i] << "/ ";
  std::cout << std::endl << "-------------------------------" << std::endl;
}
#endif

}  // namespace s21

#endif