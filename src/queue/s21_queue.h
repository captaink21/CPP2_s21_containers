#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include "../list/s21_list.h"

namespace s21 {
template <typename T, typename C = list<T>>
class queue final {
  C queue_;

 public:
  // Queue Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // Queue Member functions
  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);
  ~queue();

  queue &operator=(queue &&q);

  // Queue Element access
  const_reference front() const;
  const_reference back() const;

  // Queue Capacity
  bool empty() const;
  size_type size() const;

  // Queue Modifiers
  void push(const_reference value);
  void pop();
  void swap(queue &other) noexcept;

  template <typename... Args>
  void insert_many_back(Args &&...args);
};

}  // namespace s21

#include "s21_queue_capacity.cc"
#include "s21_queue_element_access.cc"
#include "s21_queue_member_funcs.cc"
#include "s21_queue_modifiers.cc"

#endif