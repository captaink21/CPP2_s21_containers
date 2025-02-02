#ifndef S21_SET_H
#define S21_SET_H

#include "../tree/s21_tree.h"
#if 1
namespace s21 {

using stub = std::nullptr_t;

template <typename Key, typename Compare = std::less<Key>>
class set : public tree<Key, stub, Compare> {
 protected:
  using typename tree<Key, stub, Compare>::Node;

  using tree<Key, stub, Compare>::fake_node_;
  using tree<Key, stub, Compare>::begin_;
  using tree<Key, stub, Compare>::size_;

  using tree<Key, stub, Compare>::Insert;
  using tree<Key, stub, Compare>::Find;

 public:
  // Forward declarations
  class SetIterator;
  class SetConstIterator;
  // Set member types
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;
  using iterator = SetIterator;
  using const_iterator = SetConstIterator;

  // SetIterator
  class SetIterator final : public tree<Key, stub, Compare>::TreeIterator {
   private:
    using tree<Key, stub, Compare>::TreeIterator::ptr_;
    using tree<Key, stub, Compare>::TreeIterator::Next;
    using tree<Key, stub, Compare>::TreeIterator::Prev;

   public:
    SetIterator();
    SetIterator(Node *node);
    const_reference operator*() const;
    key_type *operator->() const;
    SetIterator &operator++();
    SetIterator operator++(int);
    SetIterator &operator--();
    SetIterator operator--(int);
  };

  // SetConstIterator
  class SetConstIterator final
      : public tree<Key, stub, Compare>::TreeConstIterator {
   private:
    using tree<Key, stub, Compare>::TreeConstIterator::ptr_;
    using tree<Key, stub, Compare>::TreeConstIterator::Next;
    using tree<Key, stub, Compare>::TreeConstIterator::Prev;

   public:
    SetConstIterator();
    SetConstIterator(const Node *node);
    const_reference operator*() const;
    const key_type *operator->() const;
    SetConstIterator &operator++();
    SetConstIterator operator++(int);
    SetConstIterator &operator--();
    SetConstIterator operator--(int);
  };

  // Set Iterators
  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

  // Set Member functions
  set();
  set(std::initializer_list<value_type> const &items);
  set(const set &s);
  set(set &&s) noexcept;
  set &operator=(set &&s) noexcept;
  virtual ~set();

  // Set Modifiers
  std::pair<iterator, bool> insert(const value_type &value);
  using tree<Key, stub, Compare>::clear;

  template <typename... Args>
  vector<std::pair<typename tree<Key, stub, Compare>::iterator, bool>>
  insert_many(Args &&...args);

  // Set Lookup
  iterator find(const Key &key);
};

}  // namespace s21

#include "s21_set_iterators.cc"
#include "s21_set_lookup.cc"
#include "s21_set_member_func.cc"
#include "s21_set_modifiers.cc"

#endif
#endif