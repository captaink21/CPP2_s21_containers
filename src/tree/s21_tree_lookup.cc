#ifndef S21_TREE_LOOKUP_CC
#define S21_TREE_LOOKUP_CC

#include "s21_tree.h"

namespace s21 {

template <typename Key, typename T, typename Compare>
std::pair<typename tree<Key, T, Compare>::iterator, bool>
tree<Key, T, Compare>::Find(const key_type& key) {
  assert(fake_node_ != nullptr);
  Node* curr_node = fake_node_->left;
  Node* last_exist_parent = curr_node;
  while (curr_node != fake_node_) {
    if (comp_(key, curr_node->data.first)) {
      last_exist_parent = curr_node;
      curr_node = curr_node->left;
    } else {
      if (key == curr_node->data.first) {
        return std::pair<iterator, bool>(curr_node, true);
      }
      last_exist_parent = curr_node;
      curr_node = curr_node->right;
    }
  }
  return std::pair<iterator, bool>(last_exist_parent, false);
}

template <typename Key, typename T, typename Compare>
bool tree<Key, T, Compare>::contains(const Key& key) {
  auto [it, is_found] = Find(key);
  return is_found;
}

}  // namespace s21

#endif