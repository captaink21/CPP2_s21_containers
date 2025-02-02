#ifndef S21_VECTOR_MEMBER_FUNC_CC
#define S21_VECTOR_MEMBER_FUNC_CC

#include "s21_vector.h"

namespace s21 {

template <typename T>
void vector<T>::DestroyerElements() {
  DestroyerElements(vb_.first, vb_.extra);
  vb_.extra = vb_.first;
}

template <typename T>
void vector<T>::DestroyerElements(iterator left, iterator right) {
  for (; left != right; ++left) {
    left->~value_type();
  }
}

template <typename T>
vector<T>::vector() : vb_(){};

template <typename T>
vector<T>::vector(size_type n) : vb_() {
  if (n > max_size()) {
    throw std::out_of_range("Number of elements more than max_size");
  } else if (n != 0) {
    VectorBase<value_type> new_vb(n);
    std::swap(vb_, new_vb);
  }
}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items)
    : vb_(items.size()) {
  std::uninitialized_copy(items.begin(), items.end(), vb_.first);
  vb_.extra = vb_.first + items.size();
}

template <typename T>
vector<T>::vector(const vector &v) : vb_(v.capacity()) {
  std::uninitialized_copy(v.begin(), v.end(), vb_.first);
  vb_.extra = vb_.first + v.size();
}

template <typename T>
vector<T>::vector(vector &&v) noexcept : vb_(std::move(v.vb_)){};

template <typename T>
vector<T>::~vector() {
  DestroyerElements();
}

template <typename T>
vector<T> &vector<T>::operator=(const vector &v) {
  vector tmp(v);
  swap(tmp);
  return *this;
}

template <typename T>
vector<T> &vector<T>::operator=(vector &&v) noexcept {
  if (this != &v) {
    swap(v);
  }
  return *this;
}

}  // namespace s21

#endif