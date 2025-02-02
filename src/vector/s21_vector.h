#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <initializer_list>  // For std::initializer_list
#include <memory>            // For std::uninitialized_copy
#include <stdexcept>         // For exceptions

#include "s21_vector_base.h"

namespace s21 {

template <typename T>
class vector final {
 private:
  VectorBase<T> vb_;
  void DestroyerElements();
  void DestroyerElements(T* left, T* right);

 public:
  // Member types
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = value_type*;
  using const_iterator = const value_type*;
  using size_type = std::size_t;

  // Member functions
  vector();
  explicit vector(size_type n);
  vector(std::initializer_list<value_type> const& items);
  vector(const vector& v);
  vector(vector&& v) noexcept;
  ~vector();
  vector<value_type>& operator=(const vector& v);
  vector<value_type>& operator=(vector&& v) noexcept;

  // Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  T* data();

  // Iterators
  iterator begin() const;
  iterator end() const;

  // Capacity
  [[nodiscard]] bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type size);
  size_type capacity() const;
  void shrink_to_fit();

  // Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  iterator insert(iterator pos, T&& value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector& other);

  // Modifiers_plus

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args&&... args);
  template <typename... Args>
  void insert_many_back(Args&&... args);
};

}  // namespace s21

#include "s21_vector_capacity.cc"
#include "s21_vector_element_access.cc"
#include "s21_vector_iterators.cc"
#include "s21_vector_member_func.cc"
#include "s21_vector_modifiers.cc"

#endif
