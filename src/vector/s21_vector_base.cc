#ifndef S21_VECTOR_BASE_CC
#define S21_VECTOR_BASE_CC

#include "s21_vector_base.h"

namespace s21 {

template <typename T>
T* VectorBase<T>::Allocation(std::size_t num) {
  if (num == 0) {
    return nullptr;
  }
  return static_cast<T*>(::operator new(sizeof(T) * num));
}

template <typename T>
void VectorBase<T>::Deallocation() {
  ::operator delete(first);
}

template <typename T>
VectorBase<T>::VectorBase(std::size_t num)
    : first(Allocation(num)), extra(first), outside(first + num){};

template <typename T>
VectorBase<T>::VectorBase(VectorBase<T>&& other) noexcept
    : first(other.first), extra(other.extra), outside(other.outside) {
  other.first = other.extra = other.outside = nullptr;
}

template <typename T>
VectorBase<T>& VectorBase<T>::operator=(VectorBase<T>&& other) noexcept {
  if (this != &other) {
    std::swap(first, other.first);
    std::swap(extra, other.extra);
    std::swap(outside, other.outside);
  }
  return *this;
}

template <typename T>
VectorBase<T>::~VectorBase() {
  Deallocation();
}

}  // namespace s21

#endif