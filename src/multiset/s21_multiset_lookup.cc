#ifndef S21_MULTISET_LOOKUP_CC
#define S21_MULTISET_LOOKUP_CC

#include "s21_multiset.h"

namespace s21 {

template <typename Key, typename Compare>
typename multiset<Key, Compare>::size_type multiset<Key, Compare>::count(
    const Key& key) {
  size_type count = 0;
  iterator it = lower_bound(key);
  iterator end = upper_bound(key);
  while (it != fake_node_ && it != end) {
    ++count;
    ++it;
  }
  return count;
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::iterator multiset<Key, Compare>::find(
    const Key& key) {
  auto [it, is_found] = Find(key);

  return static_cast<iterator>(it);
}

template <typename Key, typename Compare>
std::pair<typename multiset<Key, Compare>::iterator,
          typename multiset<Key, Compare>::iterator>
multiset<Key, Compare>::equal_range(const Key& key) {
  if (multiset<Key, Compare>::empty()) {
    return std::make_pair(static_cast<Node*>(fake_node_),
                          static_cast<Node*>(fake_node_));
  }
  auto start_range = lower_bound(key);
  auto end_range = upper_bound(key);
  return std::make_pair(start_range, end_range);
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::iterator multiset<Key, Compare>::lower_bound(
    const Key& key) {
  if (multiset<Key, Compare>::empty()) {
    return static_cast<Node*>(fake_node_);
  }
  Node* curr_node = fake_node_->left;
  Node* lower_bound = curr_node;
  while (curr_node != fake_node_) {
    if (comp_(key, curr_node->data.first)) {
      lower_bound = curr_node;
      curr_node = curr_node->left;
    } else {
      if (key == curr_node->data.first) {
        return curr_node;
      }
      curr_node = curr_node->right;
    }
  }
  return (comp_(lower_bound->data.first, key) ? static_cast<Node*>(fake_node_)
                                              : lower_bound);
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::iterator multiset<Key, Compare>::upper_bound(
    const Key& key) {
  if (multiset<Key, Compare>::empty()) {
    return static_cast<Node*>(fake_node_);
  }
  iterator it = lower_bound(key);
  while (it != fake_node_ && !comp_(key, *it)) {
    ++it;
  }
  return it;
}

template <typename Key, typename Compare>
typename multiset<Key, Compare>::Node*
multiset<Key, Compare>::parent_for_insert(const Key& value) {
  Node* node = fake_node_->left;
  Node* last = node;
  while (node != fake_node_) {
    last = node;
    if (comp_(value, node->data.first)) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  return last;
}

}  // namespace s21

#endif