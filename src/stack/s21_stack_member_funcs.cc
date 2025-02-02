#ifndef S21_STACK_MEMBER_FUNCS_CC
#define S21_STACK_MEMBER_FUNCS_CC

#include "s21_stack.h"

namespace s21 {

template <typename T, typename C>
stack<T, C>::stack() : stack_() {}

template <typename T, typename C>
stack<T, C>::stack(std::initializer_list<value_type> const &items)
    : stack_(items) {}

template <typename T, typename C>
stack<T, C>::stack(const stack &s) : stack_(s.stack_) {}

template <typename T, typename C>
stack<T, C>::stack(stack &&s) : stack_(std::move(s.stack_)) {}

template <typename T, typename C>
stack<T, C>::~stack() {}

template <typename T, typename C>
stack<T, C> &stack<T, C>::operator=(stack &&s) {
  if (this != &s) {
    stack_ = std::move(s.stack_);
  }
  return *this;
}

}  // namespace s21

#endif