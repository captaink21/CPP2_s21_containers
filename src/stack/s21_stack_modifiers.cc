#ifndef S21_STACK_MODIFIERS_CC
#define S21_STACK_MODIFIERS_CC

#include "s21_stack.h"

namespace s21 {

template <typename T, typename C>
void stack<T, C>::push(const_reference value) {
  stack_.push_back(value);
}

template <typename T, typename C>
void stack<T, C>::pop() {
  stack_.pop_back();
}

template <typename T, typename C>
void stack<T, C>::swap(stack &other) noexcept {
  using std::swap;
  swap(stack_, other.stack_);
}

template <typename T, typename C>
template <typename... Args>
void stack<T, C>::insert_many_back(Args &&...args) {
  stack_.insert_many_back(std::forward<Args>(args)...);
}

}  // namespace s21

#endif