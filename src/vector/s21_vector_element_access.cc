#ifndef S21_VECTOR_ELEMENT_ACCESS_CC
#define S21_VECTOR_ELEMENT_ACCESS_CC

#include "s21_vector.h"

namespace s21 {

template <typename T>
T& vector<T>::at(size_type pos) {
  if (pos >= size()) {
    throw std::out_of_range("vector::at index out of range");
  }
  return (*this)[pos];
}

template <typename T>
T& vector<T>::operator[](size_type pos) {
  return *(data() + pos);
}

template <typename T>
const T& vector<T>::front() {
  return *(data());
}

template <typename T>
const T& vector<T>::back() {
  return (*this)[size() - 1];
}

template <typename T>
T* vector<T>::data() {
  return vb_.first;
}

#if 0
template <typename T>
void print_vector(s21::vector<T> v) {
  size_t s = v.size();
  std::cout << "-----------vector------------" << std::endl;
  for (size_t i = 0; i < s; ++i) std::cout << v[i] << "/ ";
  std::cout << std::endl << "--------------------------" << std::endl;
}
#endif

}  // namespace s21

#endif