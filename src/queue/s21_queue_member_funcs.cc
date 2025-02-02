#ifndef S21_QUEUE_MEMBER_FUNCS_CC
#define S21_QUEUE_MEMBER_FUNCS_CC

#include "s21_queue.h"

namespace s21 {

template <typename T, typename C>
queue<T, C>::queue() : queue_() {}

template <typename T, typename C>
queue<T, C>::queue(std::initializer_list<value_type> const &items)
    : queue_(items) {}

template <typename T, typename C>
queue<T, C>::queue(const queue &q) : queue_(q.queue_) {}

template <typename T, typename C>
queue<T, C>::queue(queue &&q) : queue_(std::move(q.queue_)) {}

template <typename T, typename C>
queue<T, C>::~queue() {}

template <typename T, typename C>
queue<T, C> &queue<T, C>::operator=(queue &&q) {
  if (this != &q) {
    queue_ = std::move(q.queue_);
  }
  return *this;
}

}  // namespace s21

#endif