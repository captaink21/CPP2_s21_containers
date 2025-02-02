#ifndef S21_MAP_H
#define S21_MAP_H

#include "../tree/s21_tree.h"

namespace s21 {
template <typename Key, typename T, typename Compare = std::less<Key>>
class map final : public tree<Key, T, Compare> {
 private:
  using Node = typename tree<Key, T, Compare>::Node;
  using tree<Key, T, Compare>::Insert;
  using tree<Key, T, Compare>::Find;
  using tree<Key, T, Compare>::fake_node_;
  using tree<Key, T, Compare>::begin_;

 public:
  // Map Member types
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;
  using iterator = typename tree<Key, T, Compare>::iterator;
  using const_iterator = typename tree<Key, T, Compare>::const_iterator;

  // Map Member functions
  map();
  map(std::initializer_list<value_type> const &items);
  map(const map &m);
  map(map &&m) noexcept;
  map &operator=(map &&m) noexcept;

  // Map Modifiers
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);
  std::pair<iterator, bool> insert(const value_type &value);
  std::pair<iterator, bool> insert(const Key &key, const T &obj);

  // Map Element access
  T &at(const Key &key);
  T &operator[](const Key &key);
};

}  // namespace s21

#include "s21_map_elements_access.cc"
#include "s21_map_member_func.cc"
#include "s21_map_modifiers.cc"

#endif