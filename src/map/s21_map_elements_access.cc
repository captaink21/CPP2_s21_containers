#ifndef S21_MAP_ELEMENTS_ACCESS_CC
#define S21_MAP_ELEMENTS_ACCESS_CC

#include "s21_map.h"

namespace s21 {

template <typename Key, typename T, typename Compare>
T& map<Key, T, Compare>::at(const Key& key) {
  auto [it, is_found] = Find(key);
  if (!is_found) {
    throw std::out_of_range("Key not found");
  }
  return static_cast<Node*>(it)->data.second;
}

template <typename Key, typename T, typename Compare>
T& map<Key, T, Compare>::operator[](const Key& key) {
  value_type pair(key, T());
  auto [it, _] = Insert(pair);
  return static_cast<Node*>(it)->data.second;
}

}  // namespace s21

#endif