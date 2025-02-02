#ifndef S21_STACK_H
#define S21_STACK_H

#include "../list/s21_list.h"

namespace s21 {
template <typename T, typename C = list<T>>
class stack final {
  C stack_;

 public:
  // Stack Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // Stack Member functions
  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s);
  ~stack();

  stack &operator=(stack &&q);

  // Stack Element access
  const_reference top() const;

  // Stack Capacity
  bool empty() const;
  size_type size() const;

  // Stack Modifiers
  void push(const_reference value);
  void pop();
  void swap(stack &other) noexcept;
  template <typename... Args>
  void insert_many_back(Args &&...args);
};

}  // namespace s21

#include "s21_stack_capacity.cc"
#include "s21_stack_element_access.cc"
#include "s21_stack_member_funcs.cc"
#include "s21_stack_modifiers.cc"

#endif