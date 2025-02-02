#ifndef S21_QUEUE_CAPACITY_CC
#define S21_QUEUE_CAPACITY_CC

#include "s21_queue.h"

namespace s21 {

template <typename T, typename C>
bool queue<T, C>::empty() const {
  return queue_.empty();
}

template <typename T, typename C>
typename queue<T, C>::size_type queue<T, C>::size() const {
  return queue_.size();
}

}  // namespace s21

#endif