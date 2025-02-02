#ifndef S21_MAP_MEMBER_FUNC_CC
#define S21_MAP_MEMBER_FUNC_CC

#include "s21_map.h"

namespace s21 {

template <typename Key, typename T, typename Compare>
map<Key, T, Compare>::map() : tree<Key, T, Compare>() {}

template <typename Key, typename T, typename Compare>
map<Key, T, Compare>::map(std::initializer_list<value_type> const &items)
    : tree<Key, T, Compare>(items) {}

template <typename Key, typename T, typename Compare>
map<Key, T, Compare>::map(const map &m) : tree<Key, T, Compare>(m) {}

template <typename Key, typename T, typename Compare>
map<Key, T, Compare>::map(map &&m) noexcept
    : tree<Key, T, Compare>(std::move(m)) {}

template <typename Key, typename T, typename Compare>
map<Key, T, Compare> &map<Key, T, Compare>::operator=(map &&m) noexcept {
  tree<Key, T, Compare>::operator=(std::move(m));
  return *this;
}

}  // namespace s21

#endif