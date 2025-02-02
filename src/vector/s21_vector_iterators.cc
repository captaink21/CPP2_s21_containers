#ifndef S21_VECTOR_ITERATORS_CC
#define S21_VECTOR_ITERATORS_CC

#include "s21_vector.h"

namespace s21 {

template <typename T>
T* vector<T>::begin() const {
  return vb_.first;
}

template <typename T>
T* vector<T>::end() const {
  return vb_.extra;
}

}  // namespace s21

#endif