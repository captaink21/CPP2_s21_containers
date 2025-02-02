#ifndef S21_SET_MODIFIERS_CC
#define S21_SET_MODIFIERS_CC

#include "s21_set.h"

namespace s21 {

template <typename Key, typename Compare>
std::pair<typename set<Key, Compare>::iterator, bool> set<Key, Compare>::insert(
    const_reference value) {
  std::pair<const key_type, stub> pair{value, nullptr};
  auto [it, is_inserted] = Insert(pair);
  return std::pair<iterator, bool>(static_cast<SetIterator>(it), is_inserted);
}

template <typename Key, typename Compare>
template <typename... Args>
vector<std::pair<typename tree<Key, stub, Compare>::iterator, bool>>
set<Key, Compare>::insert_many(Args&&... args) {
  vector<std::pair<typename tree<Key, stub, Compare>::iterator, bool>> res;
  (res.push_back(
       Insert(std::pair<Key, stub>(std::forward<Args>(args), nullptr))),
   ...);
  return res;
}

}  // namespace s21

#endif