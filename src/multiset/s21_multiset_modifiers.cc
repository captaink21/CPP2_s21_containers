#ifndef S21_MULTISET_MODIFIERS_CC
#define S21_MULTISET_MODIFIERS_CC

#include "s21_multiset.h"

namespace s21 {

template <typename Key, typename Compare>
std::pair<typename tree<Key, stub, Compare>::iterator, bool>
multiset<Key, Compare>::Insert(
    typename tree<Key, stub, Compare>::const_reference value) {
  if (fake_node_ == nullptr) {
    fake_node_ = AllocBaseNode();
    try {
      fake_node_->MakeChild(value, Dir::kLeft);
      begin_ = fake_node_->left;
      fake_node_->left->red = false;
    } catch (...) {
      delete (fake_node_);
      fake_node_ = nullptr;
    }
    size_ = 1;
    return std::pair<iterator, bool>(fake_node_->left, true);
  }
  Node* node = parent_for_insert(value.first);
  if (comp_(value.first, node->data.first)) {
    node = node->MakeChild(value, Dir::kLeft);
    if (node->parent == begin_) {
      begin_ = node;
    }
  } else {
    node = node->MakeChild(value, Dir::kRight);
  }
  BalanceTree(node);
  ++size_;
  return std::pair<iterator, bool>(node, true);
}

template <typename Key, typename Compare>
std::pair<typename tree<Key, stub, Compare>::iterator, bool>
multiset<Key, Compare>::Insert(
    typename tree<Key, stub, Compare>::value_type&& value) {
  if (fake_node_ == nullptr) {
    fake_node_ = AllocBaseNode();
    try {
      fake_node_->MakeChild(std::move(value), Dir::kLeft);
      begin_ = fake_node_->left;
      fake_node_->left->red = false;
    } catch (...) {
      delete (fake_node_);
      fake_node_ = nullptr;
    }
    size_ = 1;
    return std::pair<iterator, bool>(fake_node_->left, true);
  }
  Node* node = parent_for_insert(value.first);
  if (comp_(value.first, node->data.first)) {
    node = node->MakeChild(std::move(value), Dir::kLeft);
    if (node->parent == begin_) {
      begin_ = node;
    }
  } else {
    node = node->MakeChild(std::move(value), Dir::kRight);
  }
  BalanceTree(node);
  ++size_;
  return std::pair<iterator, bool>(node, true);
}

template <typename Key, typename Compare>
typename s21::multiset<Key, Compare>::iterator multiset<Key, Compare>::insert(
    const value_type& value) {
  std::pair<const key_type, stub> pair{value, nullptr};
  auto [it, is_inserted] = Insert(pair);

  return static_cast<iterator>(it);
}

template <typename Key, typename Compare>
void multiset<Key, Compare>::merge(multiset& other) {
  if (empty()) {
    swap(other);
    return;
  }
  iterator it(other.begin_);
  Node* node = other.begin_;
  while (other.fake_node_ != nullptr && node != other.fake_node_) {
    auto cur_it = it++;
    other.Erase(cur_it, false);
    Node* parent = parent_for_insert(node->data.first);
    node->red = true;
    node->parent = parent;
    node->left = node->right = static_cast<Node*>(fake_node_);
    if (comp_(node->data.first, parent->data.first)) {
      parent->SetChild(node, Dir::kLeft);
      if (parent == begin_) {
        begin_ = node;
      }
    } else {
      parent->SetChild(node, Dir::kRight);
    }
    BalanceTree(node);
    ++size_;
    node = it;
  }
}

}  // namespace s21

#endif