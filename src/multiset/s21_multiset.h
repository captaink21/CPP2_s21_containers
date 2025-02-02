#ifndef S21_MULTISET_H
#define S21_MULTISET_H

#include "../set/s21_set.h"
// #include "../tree/s21_tree.h"

namespace s21 {

using stub = std::nullptr_t;

template <typename Key, typename Compare = std::less<Key>>
class multiset final : public set<Key, Compare> {
 private:
  using typename tree<Key, stub, Compare>::Node;

  using set<Key, Compare>::fake_node_;
  using set<Key, Compare>::begin_;
  using set<Key, Compare>::size_;
  using set<Key, Compare>::comp_;
  using typename set<Key, Compare>::Dir;

  // using set<Key, Compare>::Insert;
  using set<Key, Compare>::Find;
  using set<Key, Compare>::AllocBaseNode;
  using set<Key, Compare>::BalanceTree;
  Node *parent_for_insert(const Key &key);

 public:
  // Forward declarations
  class MultisetIterator;
  class MultisetConstIterator;
  // Multiset member types
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;
  using iterator = typename set<Key, Compare>::iterator;
  using const_iterator = typename set<Key, Compare>::const_iterator;

  // Multiset Member functions
  multiset();
  multiset(std::initializer_list<value_type> const &items);
  multiset(const multiset &ms);
  multiset(multiset &&ms) noexcept;
  multiset &operator=(multiset &&ms) noexcept;
  ~multiset();

  // Multiset Modifiers

  std::pair<typename tree<Key, stub, Compare>::iterator, bool> Insert(
      typename tree<Key, stub, Compare>::const_reference value) override;
  std::pair<typename tree<Key, stub, Compare>::iterator, bool> Insert(
      typename tree<Key, stub, Compare>::value_type &&value) override;
  iterator insert(const value_type &value);
  using tree<Key, stub, Compare>::clear;
  using tree<Key, stub, Compare>::empty;
  using tree<Key, stub, Compare>::swap;
  void merge(multiset &other);

  // Multiset Lookup
  size_type count(const Key &key);
  iterator find(const Key &key);
  iterator lower_bound(const Key &key);
  iterator upper_bound(const Key &key);
  std::pair<iterator, iterator> equal_range(const Key &key);
};

}  // namespace s21

#include "s21_multiset_lookup.cc"
#include "s21_multiset_member_func.cc"
#include "s21_multiset_modifiers.cc"

#endif