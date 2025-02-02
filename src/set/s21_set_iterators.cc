#ifndef S21_SET_ITERATORS_CC
#define S21_SET_ITERATORS_CC

#include "s21_set.h"

namespace s21 {

template <typename Key, typename Compare>
set<Key, Compare>::iterator::SetIterator()
    : tree<Key, stub, Compare>::iterator(){};

template <typename Key, typename Compare>
set<Key, Compare>::iterator::SetIterator(Node *node)
    : tree<Key, stub, Compare>::iterator(node){};

template <typename Key, typename Compare>
typename set<Key, Compare>::const_reference
set<Key, Compare>::iterator::operator*() const {
  return ptr_->data.first;
}

template <typename Key, typename Compare>
typename set<Key, Compare>::key_type *set<Key, Compare>::iterator::operator->()
    const {
  return &(ptr_->data.first);
}

template <typename Key, typename Compare>
typename set<Key, Compare>::SetIterator &
set<Key, Compare>::iterator::operator++() {
  Next();
  return *this;
}

template <typename Key, typename Compare>
typename set<Key, Compare>::SetIterator set<Key, Compare>::iterator::operator++(
    int) {
  iterator old_itr = *this;
  ++(*this);
  return old_itr;
}

template <typename Key, typename Compare>
typename set<Key, Compare>::SetIterator &
set<Key, Compare>::iterator::operator--() {
  Prev();
  return *this;
}

template <typename Key, typename Compare>
typename set<Key, Compare>::SetIterator set<Key, Compare>::iterator::operator--(
    int) {
  iterator old_itr = *this;
  --(*this);
  return old_itr;
}

template <typename Key, typename Compare>
typename set<Key, Compare>::iterator set<Key, Compare>::begin() {
  return iterator(begin_);
}

template <typename Key, typename Compare>
typename set<Key, Compare>::iterator set<Key, Compare>::end() {
  return iterator(static_cast<Node *>(fake_node_));
}

template <typename Key, typename Compare>
set<Key, Compare>::const_iterator::SetConstIterator()
    : tree<Key, stub, Compare>::TreeConstIterator(){};

template <typename Key, typename Compare>
set<Key, Compare>::const_iterator::SetConstIterator(const Node *node)
    : tree<Key, stub, Compare>::TreeConstIterator(node){};

template <typename Key, typename Compare>
typename set<Key, Compare>::const_reference
set<Key, Compare>::const_iterator::operator*() const {
  return ptr_->data.first;
}

template <typename Key, typename Compare>
const typename set<Key, Compare>::key_type *
set<Key, Compare>::const_iterator::operator->() const {
  return &(ptr_->data.first);
}

template <typename Key, typename Compare>
typename set<Key, Compare>::SetConstIterator &
set<Key, Compare>::const_iterator::operator++() {
  Next();
  return *this;
}

template <typename Key, typename Compare>
typename set<Key, Compare>::SetConstIterator
set<Key, Compare>::const_iterator::operator++(int) {
  const_iterator old_itr = *this;
  ++(*this);
  return old_itr;
}

template <typename Key, typename Compare>
typename set<Key, Compare>::SetConstIterator &
set<Key, Compare>::const_iterator::operator--() {
  Prev();
  return *this;
}

template <typename Key, typename Compare>
typename set<Key, Compare>::SetConstIterator
set<Key, Compare>::const_iterator::operator--(int) {
  const_iterator old_itr = *this;
  --(*this);
  return old_itr;
}

template <typename Key, typename Compare>
typename set<Key, Compare>::const_iterator set<Key, Compare>::begin() const {
  return const_iterator(begin_);
}

template <typename Key, typename Compare>
typename set<Key, Compare>::const_iterator set<Key, Compare>::end() const {
  return const_iterator(static_cast<const Node *>(fake_node_));
}

}  // namespace s21

#endif