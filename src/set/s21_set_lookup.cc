#ifndef S21_SET_LOOKUP_CC
#define S21_SET_LOOKUP_CC

#include "s21_set.h"

namespace s21 {

template <typename Key, typename Compare>
typename set<Key, Compare>::iterator set<Key, Compare>::find(const Key& key) {
  auto [it, is_found] = Find(key);

  return static_cast<iterator>(it);
}

}  // namespace s21

#endif