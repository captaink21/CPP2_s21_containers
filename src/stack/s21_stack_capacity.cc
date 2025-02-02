#ifndef S21_STACK_CAPACITY_CC
#define S21_STACK_CAPACITY_CC

#include "s21_stack.h"

namespace s21 {

template <typename T, typename C>
bool stack<T, C>::empty() const {
  return stack_.empty();
}

template <typename T, typename C>
typename stack<T, C>::size_type stack<T, C>::size() const {
  return stack_.size();
}

}  // namespace s21

#endif