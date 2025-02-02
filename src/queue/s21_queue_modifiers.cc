#ifndef S21_QUEUE_MODIFIERS_CC
#define S21_QUEUE_MODIFIERS_CC

#include "s21_queue.h"

namespace s21 {

template <typename T, typename C>
void queue<T, C>::push(const_reference value) {
  queue_.push_back(value);
}

template <typename T, typename C>
void queue<T, C>::pop() {
  queue_.pop_front();
}

template <typename T, typename C>
void queue<T, C>::swap(queue &other) noexcept {
  using std::swap;
  swap(queue_, other.queue_);
}

template <typename T, typename C>
template <typename... Args>
void queue<T, C>::insert_many_back(Args &&...args) {
  queue_.insert_many_back(std::forward<Args>(args)...);
}

}  // namespace s21

#endif