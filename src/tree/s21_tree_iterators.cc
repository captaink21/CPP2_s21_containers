#ifndef S21_TREE_ITERATORS_CC
#define S21_TREE_ITERATORS_CC

#include "s21_tree.h"

namespace s21 {

/*

TreeIterator

*/

template <typename Key, typename T, typename Compare>
tree<Key, T, Compare>::iterator::TreeIterator() : ptr_(nullptr){};

template <typename Key, typename T, typename Compare>
tree<Key, T, Compare>::iterator::TreeIterator(Node *node) : ptr_(node){};

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::reference
tree<Key, T, Compare>::iterator::operator*() const {
  return ptr_->data;
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::value_type *
tree<Key, T, Compare>::iterator::operator->() const {
  return &(ptr_->data);
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::TreeIterator &
tree<Key, T, Compare>::iterator::operator++() {
  return Next();
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::TreeIterator
tree<Key, T, Compare>::iterator::operator++(int) {
  TreeIterator old_itr = *this;
  ++(*this);
  return old_itr;
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::TreeIterator &
tree<Key, T, Compare>::iterator::operator--() {
  return Prev();
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::TreeIterator
tree<Key, T, Compare>::iterator::operator--(int) {
  TreeIterator old_itr = *this;
  --(*this);
  return old_itr;
}

template <typename Key, typename T, typename Compare>
bool tree<Key, T, Compare>::iterator::operator==(
    const TreeIterator &other) const {
  return ptr_ == other.ptr_;
}

template <typename Key, typename T, typename Compare>
bool tree<Key, T, Compare>::iterator::operator!=(
    const TreeIterator &other) const {
  return ptr_ != other.ptr_;
}

template <typename Key, typename T, typename Compare>
bool tree<Key, T, Compare>::iterator::IsRed() const {
  return ptr_->red;
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::TreeIterator &
tree<Key, T, Compare>::iterator::Next() {
  if (ptr_->right->right == nullptr) {
    while (ptr_->Side() == Dir::kRight) {
      ptr_ = ptr_->parent;
    }
    ptr_ = ptr_->parent;
  } else {
    ptr_ = ptr_->right;
    while (ptr_->left->right != nullptr) {
      ptr_ = ptr_->left;
    }
  }
  return *this;
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::TreeIterator &
tree<Key, T, Compare>::iterator::Prev() {
  if (ptr_->left->right == nullptr) {
    while (ptr_->Side() == Dir::kLeft) {
      ptr_ = ptr_->parent;
    }
    ptr_ = ptr_->parent;
  } else {
    ptr_ = ptr_->left;
    while (ptr_->right->right != nullptr) {
      ptr_ = ptr_->right;
    }
  }
  return *this;
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::iterator tree<Key, T, Compare>::begin() {
  return iterator(begin_);
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::iterator tree<Key, T, Compare>::end() {
  return iterator(static_cast<Node *>(fake_node_));
}

template <typename Key, typename T, typename Compare>
tree<Key, T, Compare>::TreeIterator::operator Node *() {
  return ptr_;
}

/*

TreeConstIterator

*/

template <typename Key, typename T, typename Compare>
tree<Key, T, Compare>::const_iterator::TreeConstIterator() : ptr_(nullptr){};

template <typename Key, typename T, typename Compare>
tree<Key, T, Compare>::const_iterator::TreeConstIterator(const Node *node)
    : ptr_(node){};

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::const_reference
tree<Key, T, Compare>::const_iterator::operator*() const {
  return ptr_->data;
}

template <typename Key, typename T, typename Compare>
const typename tree<Key, T, Compare>::value_type *
tree<Key, T, Compare>::const_iterator::operator->() const {
  return &(ptr_->data);
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::TreeConstIterator &
tree<Key, T, Compare>::const_iterator::operator++() {
  return Next();
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::TreeConstIterator
tree<Key, T, Compare>::const_iterator::operator++(int) {
  TreeConstIterator old_itr = *this;
  ++(*this);
  return old_itr;
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::TreeConstIterator &
tree<Key, T, Compare>::const_iterator::operator--() {
  return Prev();
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::TreeConstIterator
tree<Key, T, Compare>::const_iterator::operator--(int) {
  TreeConstIterator old_itr = *this;
  --(*this);
  return old_itr;
}

template <typename Key, typename T, typename Compare>
bool tree<Key, T, Compare>::const_iterator::operator==(
    const TreeConstIterator &other) const {
  return ptr_ == other.ptr_;
}

template <typename Key, typename T, typename Compare>
bool tree<Key, T, Compare>::const_iterator::operator!=(
    const TreeConstIterator &other) const {
  return ptr_ != other.ptr_;
}

template <typename Key, typename T, typename Compare>
bool tree<Key, T, Compare>::const_iterator::IsRed() const {
  return ptr_->red;
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::TreeConstIterator &
tree<Key, T, Compare>::const_iterator::Next() {
  if (ptr_->right->right == nullptr) {
    while (ptr_->Side() == Dir::kRight) {
      ptr_ = ptr_->parent;
    }
    ptr_ = ptr_->parent;
  } else {
    ptr_ = ptr_->right;
    while (ptr_->left->right != nullptr) {
      ptr_ = ptr_->left;
    }
  }
  return *this;
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::TreeConstIterator &
tree<Key, T, Compare>::const_iterator::Prev() {
  if (ptr_->left->right == nullptr) {
    while (ptr_->Side() == Dir::kLeft) {
      ptr_ = ptr_->parent;
    }
    ptr_ = ptr_->parent;
  } else {
    ptr_ = ptr_->left;
    while (ptr_->right->right != nullptr) {
      ptr_ = ptr_->right;
    }
  }
  return *this;
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::const_iterator tree<Key, T, Compare>::begin()
    const {
  return const_iterator(begin_);
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::const_iterator tree<Key, T, Compare>::end()
    const {
  return const_iterator(static_cast<const Node *>(fake_node_));
}

template <typename Key, typename T, typename Compare>
tree<Key, T, Compare>::TreeConstIterator::operator const Node *() {
  return ptr_;
}

}  // namespace s21

#endif