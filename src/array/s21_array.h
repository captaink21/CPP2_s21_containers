#ifndef S21_ARRAY_H
#define S21_ARRAY_H

#include <initializer_list>  // For std::initializer_list
#include <memory>            // For std::uninitialized_copy
#include <stdexcept>         // For exceptions

namespace s21 {

template <typename T, size_t N>
class array final {
 private:
  std::size_t size_ = N;
  T data_[N];

 public:
  // Member types
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = value_type*;
  using const_iterator = const value_type*;
  using size_type = std::size_t;

  // Member functions
  array();
  array(std::initializer_list<value_type> const& items);
  array(const array& a);
  array(array&& a) noexcept;
  ~array();
  array<value_type, N>& operator=(array&& a) noexcept;

  // Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  value_type operator[](size_type pos)
      const;  // для оператора присваивания при константной ссылке
  const_reference front();
  const_reference back();
  iterator data();

  // Iterators
  iterator begin();
  iterator end();

  // Capacity
  bool empty() const;
  size_type size() const;
  size_type max_size();

  // Modifiers
  void swap(array& other);
  void fill(const_reference value);
};

}  // namespace s21

#include "s21_array_capacity.cc"
#include "s21_array_element_access.cc"
#include "s21_array_iterators.cc"
#include "s21_array_member_func.cc"
#include "s21_array_modifiers.cc"

#endif