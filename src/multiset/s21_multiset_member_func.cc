#ifndef S21_MULTISET_MEMBER_FUNC_CC
#define S21_MULTISET_MEMBER_FUNC_CC

#include "s21_multiset.h"

namespace s21 {

template <typename Key, typename Compare>
s21::multiset<Key, Compare>::multiset() : set<Key, Compare>() {}

template <typename Key, typename Compare>
s21::multiset<Key, Compare>::multiset(
    std::initializer_list<value_type> const &items) {
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
multiset<Key, Compare>::multiset(const multiset &ms) : set<Key, Compare>(ms) {}

template <typename Key, typename Compare>
multiset<Key, Compare>::multiset(multiset &&ms) noexcept
    : set<Key, Compare>(std::move(ms)) {}

template <typename Key, typename Compare>
multiset<Key, Compare> &multiset<Key, Compare>::operator=(
    multiset &&ms) noexcept {
  set<Key, Compare>::operator=(std::move(ms));
  return *this;
}

template <typename Key, typename Compare>
multiset<Key, Compare>::~multiset() {}

}  // namespace s21

#endif