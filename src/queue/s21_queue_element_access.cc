#ifndef S21_QUEUE_ELEMENT_ACCESS_CC
#define S21_QUEUE_ELEMENT_ACCESS_CC

#include "s21_queue.h"

namespace s21 {

template <typename T, typename C>
typename queue<T, C>::const_reference queue<T, C>::front() const {
  return queue_.front();
}

template <typename T, typename C>
typename queue<T, C>::const_reference queue<T, C>::back() const {
  return queue_.back();
}

}  // namespace s21

#endif