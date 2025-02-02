#ifndef S21_VECTOR_CAPACITY_CC
#define S21_VECTOR_CAPACITY_CC

#include "s21_vector.h"

namespace s21 {

template <typename T>
[[nodiscard]] bool vector<T>::empty() const {
  return vb_.first == vb_.extra;
}

template <typename T>
std::size_t vector<T>::size() const {
  return empty() ? 0 : vb_.extra - vb_.first;
}

template <typename T>
std::size_t vector<T>::max_size() const {
  return std::allocator<T>().max_size();
}

template <typename T>
void vector<T>::reserve(size_type new_size) {
  if (new_size > size()) {
    if (new_size > max_size()) {
      throw std::out_of_range("Number of elements more than max_size");
    }
    VectorBase<value_type> new_vb(new_size);
    if constexpr (std::is_nothrow_move_constructible<T>::value) {
      std::uninitialized_move(vb_.first, vb_.extra, new_vb.first);
    } else {
      std::uninitialized_copy(vb_.first, vb_.extra, new_vb.first);
    }
    new_vb.extra = new_vb.first + size();
    DestroyerElements();
    std::swap(vb_, new_vb);
  }
}

template <typename T>
std::size_t vector<T>::capacity() const {
  return (vb_.outside == nullptr) ? 0 : vb_.outside - vb_.first;
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (vb_.extra != vb_.outside) {
    VectorBase<value_type> new_vb(size());
    if constexpr (std::is_nothrow_move_constructible<T>::value) {
      std::uninitialized_move(vb_.first, vb_.extra, new_vb.first);
    } else {
      std::uninitialized_copy(vb_.first, vb_.extra, new_vb.first);
    }
    DestroyerElements();
    new_vb.extra = new_vb.outside;
    std::swap(vb_, new_vb);
  }
}

}  // namespace s21

#endif