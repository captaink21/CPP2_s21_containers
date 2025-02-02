#ifndef S21_STACK_ELEMENT_ACCESS_CC
#define S21_STACK_ELEMENT_ACCESS_CC

#include "s21_stack.h"

namespace s21 {

template <typename T, typename C>
typename stack<T, C>::const_reference stack<T, C>::top() const {
  return stack_.back();
}

}  // namespace s21

#endif