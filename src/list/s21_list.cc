#include "s21_list.h"

namespace s21 {

template <typename T>
// ListIterator
list<T>::iterator::ListIterator() : ptr_(nullptr){};

template <typename T>
list<T>::iterator::ListIterator(Node* node) : ptr_(node){};

template <typename T>
typename list<T>::reference list<T>::iterator::operator*() const {
  return ptr_->data_;
}

template <typename T>
typename list<T>::value_type* list<T>::iterator::operator->() const {
  return &ptr_->data_;
}

template <typename T>
typename list<T>::ListIterator& list<T>::iterator::operator++() {
  ptr_ = static_cast<Node*>(ptr_->next_);
  return *this;
}

template <typename T>
typename list<T>::ListIterator list<T>::iterator::operator++(int) {
  ListIterator old_itr = *this;
  ++(*this);
  return old_itr;
}

template <typename T>
typename list<T>::ListIterator& list<T>::iterator::operator--() {
  ptr_ = static_cast<Node*>(ptr_->prev_);
  return *this;
}

template <typename T>
typename list<T>::ListIterator list<T>::iterator::operator--(int) {
  ListIterator old_itr = *this;
  --(*this);
  return old_itr;
}

template <typename T>
bool list<T>::iterator::operator==(const ListIterator& other) const {
  return ptr_ == other.ptr_;
}

template <typename T>
bool list<T>::iterator::operator!=(const ListIterator& other) const {
  return ptr_ != other.ptr_;
}

template <typename T>
typename list<T>::Node* list<T>::iterator::get_node() const {
  return ptr_;
}

// ListConstIterator
template <typename T>
list<T>::const_iterator::ListConstIterator() : ptr_(nullptr){};

template <typename T>
list<T>::const_iterator::ListConstIterator(const Node* node) : ptr_(node){};

template <typename T>
typename list<T>::const_reference list<T>::const_iterator::operator*() const {
  return ptr_->data_;
}

template <typename T>
const typename list<T>::value_type* list<T>::const_iterator::operator->()
    const {
  return &ptr_->data_;
}

template <typename T>
typename list<T>::ListConstIterator& list<T>::const_iterator::operator++() {
  ptr_ = static_cast<const Node*>(ptr_->next_);
  return *this;
}

template <typename T>
typename list<T>::ListConstIterator list<T>::const_iterator::operator++(int) {
  const_iterator old_itr = *this;
  ++(*this);
  return old_itr;
}

template <typename T>
typename list<T>::ListConstIterator& list<T>::const_iterator::operator--() {
  ptr_ = static_cast<const Node*>(ptr_->prev_);
  return *this;
}

template <typename T>
typename list<T>::ListConstIterator list<T>::const_iterator::operator--(int) {
  const_iterator old_itr = *this;
  --(*this);
  return old_itr;
}

template <typename T>
bool list<T>::const_iterator::operator==(const ListConstIterator& other) const {
  return ptr_ == other.ptr_;
}

template <typename T>
bool list<T>::const_iterator::operator!=(const ListConstIterator& other) const {
  return ptr_ != other.ptr_;
}

template <typename T>
const typename list<T>::Node* list<T>::const_iterator::get_node() const {
  return ptr_;
}

// List Element access
template <typename T>
typename list<T>::const_reference list<T>::front() const {
  return static_cast<Node*>(fake_node_.next_)->data_;
}

template <typename T>
typename list<T>::const_reference list<T>::back() const {
  return static_cast<Node*>(fake_node_.prev_)->data_;
}

// List Iterators
template <typename T>
typename list<T>::iterator list<T>::begin() {
  return iterator(static_cast<Node*>(fake_node_.next_));
}

template <typename T>
typename list<T>::const_iterator list<T>::begin() const {
  return const_iterator(static_cast<Node*>(fake_node_.next_));
}

template <typename T>
typename list<T>::const_iterator list<T>::cbegin() const {
  return const_iterator(static_cast<Node*>(fake_node_.next_));
}

template <typename T>
typename list<T>::iterator list<T>::end() {
  return iterator(static_cast<Node*>(&fake_node_));
}

template <typename T>
typename list<T>::const_iterator list<T>::end() const {
  return const_iterator(static_cast<const Node*>(&fake_node_));
}

template <typename T>
typename list<T>::const_iterator list<T>::cend() const {
  return const_iterator(static_cast<const Node*>(&fake_node_));
}

// List Functions / cnstrtrs
template <typename T>
list<T>::list() : fake_node_{&fake_node_, &fake_node_}, size_(0) {}

template <typename T>
list<T>::list(size_type n) : fake_node_{&fake_node_, &fake_node_}, size_(0) {
  try {
    for (size_type i = 0; i < n; i++) {
      push_back(value_type());
    }
  } catch (const std::bad_alloc&) {
    clear();
    throw;
  }
}

template <typename T>
list<T>::list(std::initializer_list<value_type> const& items)
    : fake_node_{&fake_node_, &fake_node_}, size_(0) {
  try {
    for (const auto& item : items) {
      push_back(item);
    }
  } catch (const std::bad_alloc&) {
    clear();
    throw;
  }
}

template <typename T>
list<T>::list(const list& l) : fake_node_{&fake_node_, &fake_node_}, size_(0) {
  try {
    for (const auto& node : l) {
      push_back(node);
    }
  } catch (const std::bad_alloc&) {
    clear();
    throw;
  }
}

template <typename T>
list<T>::list(list&& l) noexcept
    : fake_node_{&fake_node_, &fake_node_}, size_(l.size_) {
  if (l.size_ > 0) {
    fake_node_.next_ = l.fake_node_.next_;
    fake_node_.prev_ = l.fake_node_.prev_;
    l.fake_node_.prev_->next_ = l.fake_node_.next_->prev_ = &fake_node_;
    l.fake_node_.prev_ = l.fake_node_.next_ = &l.fake_node_;
    l.size_ = 0;
  }
}

template <typename T>
list<T>::~list() {
  clear();
}

template <typename T>
list<T>& list<T>::operator=(list&& l) noexcept {
  if (this != &l) {
    swap(l);
  }

  return *this;
}

// List Capacity
template <typename T>
[[nodiscard]] bool list<T>::empty() const {
  return begin() == end();
}

template <typename T>
typename list<T>::size_type list<T>::size() const {
  return size_;
}

template <typename T>
typename list<T>::size_type list<T>::max_size() const {
  return std::allocator<Node>().max_size();
}

// List Modifiers
template <typename T>
void list<T>::clear() {
  for (iterator i = begin(); i != end();) {
    Node* cur = i.get_node();
    cur->data_.~T();
    ++i;
    ::operator delete(cur);
  }
  size_ = 0;
  fake_node_.prev_ = fake_node_.next_ = &fake_node_;
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  Node* node = static_cast<Node*>(::operator new(sizeof(Node)));
  try {
    ::new (&node->data_) T(value);
  } catch (...) {
    ::operator delete(node);
    throw;
  }
  return insert_connect(pos, node);
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos, T&& value) {
  Node* node = static_cast<Node*>(::operator new(sizeof(Node)));
  try {
    ::new (&node->data_) T(std::move(value));
  } catch (...) {
    ::operator delete(node);
    throw;
  }
  return insert_connect(pos, node);
}

template <typename T>
typename list<T>::iterator list<T>::insert_connect(iterator pos, Node* node) {
  Node* pos_node = pos.get_node();
  Node* prev_pos_node = static_cast<Node*>(pos_node->prev_);
  prev_pos_node->next_ = pos_node->prev_ = node;
  node->prev_ = prev_pos_node;
  node->next_ = pos_node;
  ++size_;
  return node;
}

template <typename T>
void list<T>::erase(iterator pos) {
  Node* node_to_erase = pos.get_node();
  BaseNode* prev_node = node_to_erase->prev_;
  BaseNode* next_node = node_to_erase->next_;
  prev_node->next_ = next_node;
  next_node->prev_ = prev_node;
  node_to_erase->data_.~T();
  ::operator delete(node_to_erase);
  size_--;
}

template <typename T>
void list<T>::push_back(const_reference value) {
  insert(end(), value);
}

template <typename T>
void list<T>::pop_back() {
  erase(--end());
}

template <typename T>
void list<T>::push_front(const_reference value) {
  insert(begin(), value);
}

template <typename T>
void list<T>::pop_front() {
  erase(begin());
}

template <typename T>
void list<T>::swap(list& other) {
  BaseNode* other_first = other.fake_node_.next_;
  BaseNode* other_last = other.fake_node_.prev_;
  BaseNode* cur_first = fake_node_.next_;
  BaseNode* cur_last = fake_node_.prev_;
  other_first->prev_ = other_last->next_ = &fake_node_;
  cur_first->prev_ = cur_last->next_ = &other.fake_node_;
  std::swap(fake_node_, other.fake_node_);
  std::swap(size_, other.size_);
}

template <typename T>
void list<T>::merge(list& other) {
  if (other.begin() == begin()) {
    return;
  }
  Node* fake_node = static_cast<Node*>(&fake_node_);
  iterator curr_list_it = begin();
  iterator other_list_it = other.begin();
  Node* current_tail = fake_node;

  while (curr_list_it != end() && other_list_it != other.end()) {
    Node* node_to_add = nullptr;
    if (std::less<>{}(*curr_list_it, *other_list_it)) {
      node_to_add = curr_list_it.get_node();
      ++curr_list_it;
    } else {
      node_to_add = other_list_it.get_node();
      ++other_list_it;
    }

    node_to_add->prev_ = current_tail;
    current_tail->next_ = node_to_add;
    current_tail = node_to_add;
  }

  Node* new_end = (--end()).get_node();
  if (other_list_it != other.end()) {
    curr_list_it = other_list_it;
    new_end = (--other.end()).get_node();
  }

  current_tail->next_ = curr_list_it.get_node();
  curr_list_it.get_node()->prev_ = current_tail;

  size_ += other.size_;
  other.size_ = 0;

  fake_node->prev_ = new_end;
  new_end->next_ = fake_node;
  other.fake_node_.prev_ = other.fake_node_.next_ = &other.fake_node_;
}

#if 0
template <typename T>
typename list<T>::BaseNode* list<T>::get_fake_node() {
  return &fake_node_;
}
#endif

template <typename T>
void list<T>::splice(const_iterator pos, list& other) {
  if (this == &other) {
    return;
  }

  Node* node_to_splice = const_cast<Node*>(pos.get_node());

  node_to_splice->prev_->next_ = other.fake_node_.next_;
  other.fake_node_.next_->prev_ = node_to_splice->prev_;
  other.fake_node_.prev_->next_ = node_to_splice;
  node_to_splice->prev_ = other.fake_node_.prev_;

  other.fake_node_.next_ = other.fake_node_.prev_ = &other.fake_node_;

  size_ += other.size_;
  other.size_ = 0;
}

template <typename T>
void list<T>::reverse() {
  for (iterator it = begin(); it != end();) {
    std::swap(it.get_node()->prev_, it.get_node()->next_);
    it = static_cast<Node*>(it.get_node()->prev_);
  }
  std::swap(fake_node_.next_, fake_node_.prev_);
}

template <typename T>
void list<T>::unique() {
  for (iterator left = begin(), right = ++begin(); right != end();) {
    iterator tmp = right;
    ++tmp;
    if (*left == *right) {
      erase(right);
    } else {
      left = right;
    }
    right = tmp;
  }
}

template <typename T>
typename list<T>::iterator list<T>::merge_sublists(iterator lhs, iterator rhs) {
  Node* fake_node = static_cast<Node*>(&fake_node_);
  Node* current_tail = fake_node;

  while (lhs != fake_node && rhs != fake_node) {
    Node* node_to_add = nullptr;
    if (*lhs < *rhs) {
      node_to_add = lhs.get_node();
      ++lhs;
    } else {
      node_to_add = rhs.get_node();
      ++rhs;
    }
    current_tail->next_ = node_to_add;
    node_to_add->prev_ = current_tail;
    current_tail = node_to_add;
  }

  if (lhs != fake_node) {
    rhs = lhs;
  }
  Node* rhs_node = rhs.get_node();
  current_tail->next_ = rhs_node;
  rhs_node->prev_ = current_tail;

  while (rhs.get_node()->next_ != fake_node) {
    ++rhs;
  }
  fake_node->prev_ = rhs.get_node();

  return iterator(static_cast<Node*>(fake_node->next_));
}

template <typename T>
typename list<T>::iterator list<T>::merge_sort(iterator begin,
                                               iterator it_end) {
  iterator it_middle = begin, it_last = begin;
  Node* end_node = it_end.get_node();
  if (it_middle.get_node()->next_ == end_node) {
    it_middle.get_node()->next_ = &fake_node_;
    return it_middle;
  }

  while (it_last.get_node() != end_node &&
         it_last.get_node()->next_ != end_node) {
    ++it_middle, ++(++it_last);
  }

  iterator lhs = merge_sort(begin, it_middle);
  iterator rhs = merge_sort(it_middle, it_end);
  iterator new_begin = merge_sublists(lhs, rhs);

  return new_begin;
}

template <typename T>
void list<T>::sort() {
  merge_sort(begin(), end());
}

template <typename T>
template <typename... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args&&... args) {
  iterator it_pos = const_cast<Node*>(pos.get_node());
  size_type insert_count = 0;

  try {
    (insert(it_pos, std::forward<Args>(args)), ..., ++insert_count);
  } catch (...) {
    iterator del_pos = it_pos;
    while (insert_count--) {
      erase(--del_pos);
    }
    throw;
  }

  return it_pos;
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_back(Args&&... args) {
  insert_many(cend(), std::forward<Args>(args)...);
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_front(Args&&... args) {
  insert_many(cbegin(), std::forward<Args>(args)...);
}

}  // namespace s21