#ifndef S21_TREE_MEMBER_FUNC_CC
#define S21_TREE_MEMBER_FUNC_CC

#include "s21_tree.h"

namespace s21 {

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::BaseNode*
tree<Key, T, Compare>::AllocBaseNode() {
  BaseNode* base = new BaseNode();
  base->left = base->parent = static_cast<Node*>(base);
  base->right = nullptr;
  return base;
}

template <typename Key, typename T, typename Compare>
tree<Key, T, Compare>::tree()
    : fake_node_(nullptr), begin_(nullptr), size_(0) {}

template <typename Key, typename T, typename Compare>
tree<Key, T, Compare>::tree(std::initializer_list<value_type> const& items)
    : tree() {
  try {
    for (const auto& pair : items) {
      Insert(pair);
    }
  } catch (...) {
    clear();
    throw;
  }
}

template <typename Key, typename T, typename Compare>
tree<Key, T, Compare>::tree(const tree& m)
    : fake_node_(nullptr), begin_(nullptr), size_(m.size()) {
  if (!m.empty()) {
    try {
      fake_node_ = AllocBaseNode();
      Node* child = fake_node_->CopyChild(m.fake_node_->left, Dir::kLeft);
      TreeCopy(child, m.fake_node_->left, m.fake_node_, m.begin_);
    } catch (...) {
      clear();
      throw;
    }
  }
}

template <typename Key, typename T, typename Compare>
tree<Key, T, Compare>::tree(tree&& m) noexcept
    : fake_node_(m.fake_node_),
      begin_(m.begin_),
      size_(m.size_),
      comp_(m.comp_) {
  m.fake_node_ = m.begin_ = nullptr;
  m.size_ = 0;
}

template <typename Key, typename T, typename Compare>
tree<Key, T, Compare>::~tree() {
  clear();
}

template <typename Key, typename T, typename Compare>
tree<Key, T, Compare>& tree<Key, T, Compare>::operator=(tree&& m) noexcept {
  if (this != &m) {
    swap(m);
  }
  return *this;
}

template <typename Key, typename T, typename Compare>
void tree<Key, T, Compare>::TreeCopy(BaseNode* curr_root, BaseNode* other_root,
                                     const BaseNode* other_fn,
                                     const BaseNode* other_begin) {
  if (other_root == other_begin) {
    begin_ = static_cast<Node*>(curr_root);
  }
  if (other_root->left != other_fn) {
    Node* child = curr_root->MakeChild(other_root->left->data, Dir::kLeft);

    TreeCopy(child, other_root->left, other_fn, other_begin);
  }
  if (other_root->right != other_fn) {
    Node* child = curr_root->MakeChild(other_root->right->data, Dir::kRight);
    TreeCopy(child, other_root->right, other_fn, other_begin);
  }
}

}  // namespace s21

#endif