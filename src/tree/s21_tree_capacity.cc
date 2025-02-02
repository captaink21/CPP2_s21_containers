#ifndef S21_TREE_CAPACITY_CC
#define S21_TREE_CAPACITY_CC

#include "s21_tree.h"

namespace s21 {

template <typename Key, typename T, typename Compare>
[[nodiscard]] bool tree<Key, T, Compare>::empty() const {
  return fake_node_ == nullptr;
}

template <typename Key, typename T, typename Compare>
std::size_t tree<Key, T, Compare>::size() const {
  return size_;
}

template <typename Key, typename T, typename Compare>
std::size_t tree<Key, T, Compare>::max_size() const {
  return std::allocator<Node>().max_size();
}

}  // namespace s21

#endif