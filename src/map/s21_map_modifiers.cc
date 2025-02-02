
#ifndef S21_MAP_MODIFIERS_CC
#define S21_MAP_MODIFIERS_CC

#include "s21_map.h"

namespace s21 {

template <typename Key, typename T, typename Compare>
std::pair<typename map<Key, T, Compare>::iterator, bool>
map<Key, T, Compare>::insert(const Key& key, const T& obj) {
  value_type pair(key, obj);
  return Insert(pair);
}

template <typename Key, typename T, typename Compare>
std::pair<typename map<Key, T, Compare>::iterator, bool>
map<Key, T, Compare>::insert(const_reference value) {
  return Insert(value);
}

template <typename Key, typename T, typename Compare>
std::pair<typename map<Key, T, Compare>::iterator, bool>
map<Key, T, Compare>::insert_or_assign(const Key& key, const T& obj) {
  value_type pair(key, obj);
  auto [it, is_inserted] = Insert(pair);
  if (!is_inserted) {
    static_cast<Node*>(it)->data.second = obj;
  }
  return std::pair<iterator, bool>(it, is_inserted);
}

}  // namespace s21

#endif