#ifndef S21_SET_MEMBER_FUNC_CC
#define S21_SET_MEMBER_FUNC_CC

#include "s21_set.h"

namespace s21 {

template <typename Key, typename Compare>
set<Key, Compare>::set() : tree<Key, stub, Compare>() {}

template <typename Key, typename Compare>
set<Key, Compare>::set(std::initializer_list<value_type> const &items) {
  try {
    for (const auto &key : items) {
      std::pair<value_type, stub> pair(key, nullptr);
      Insert(pair);
    }
  } catch (...) {
    clear();
    throw;
  }
}

template <typename Key, typename Compare>
set<Key, Compare>::set(const set &s) : tree<Key, stub, Compare>(s) {}

template <typename Key, typename Compare>
set<Key, Compare>::set(set &&s) noexcept
    : tree<Key, stub, Compare>(std::move(s)) {}

template <typename Key, typename Compare>
set<Key, Compare> &set<Key, Compare>::operator=(set &&s) noexcept {
  tree<Key, stub, Compare>::operator=(std::move(s));
  return *this;
}

template <typename Key, typename Compare>
set<Key, Compare>::~set() {}

}  // namespace s21

#endif