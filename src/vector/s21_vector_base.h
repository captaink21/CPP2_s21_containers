#ifndef S21_VECTOR_BASE_H
#define S21_VECTOR_BASE_H

#include <cstddef>  // For std::size_t
#include <utility>  // For std::move & std::swap

namespace s21 {

template <typename T>
struct VectorBase final {
  // Attributes
  T* first;
  T* extra;
  T* outside;

  T* Allocation(std::size_t num);
  void Deallocation();

  VectorBase(std::size_t num = 0);
  VectorBase(const VectorBase<T>& other) = delete;
  VectorBase(VectorBase<T>&& other) noexcept;

  VectorBase& operator=(const VectorBase<T>& other) = delete;
  VectorBase& operator=(VectorBase<T>&& other) noexcept;

  ~VectorBase();
};

}  // namespace s21

#include "s21_vector_base.cc"

#endif