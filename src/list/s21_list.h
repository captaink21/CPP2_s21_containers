#ifndef S21_LIST_H
#define S21_LIST_H

#include <cstddef>           // For std::size_t
#include <initializer_list>  // For std::initializer_list
#include <stdexcept>         // For exceptions
#include <utility>           // For std::move & std::swap

namespace s21 {
template <typename T>
class list final {
  struct BaseNode {
    BaseNode *prev_;
    BaseNode *next_;
  };

  struct Node : BaseNode {
    T data_;
  };

  BaseNode fake_node_;
  std::size_t size_;

  // List Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  class ListIterator final {
    Node *ptr_;

   public:
    ListIterator();
    ListIterator(Node *node);

    reference operator*() const;
    value_type *operator->() const;
    ListIterator &operator++();
    ListIterator operator++(int);
    ListIterator &operator--();
    ListIterator operator--(int);
    bool operator==(const ListIterator &other) const;
    bool operator!=(const ListIterator &other) const;

    Node *get_node() const;
  };

  class ListConstIterator final {
    const Node *ptr_;

   public:
    ListConstIterator();
    ListConstIterator(const Node *node);

    const_reference operator*() const;
    const value_type *operator->() const;
    ListConstIterator &operator++();
    ListConstIterator operator++(int);
    ListConstIterator &operator--();
    ListConstIterator operator--(int);
    bool operator==(const ListConstIterator &other) const;
    bool operator!=(const ListConstIterator &other) const;

    const Node *get_node() const;
  };

  // Helpers
  ListIterator insert_connect(ListIterator pos, Node *node);

 public:
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;

  // List Functions
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l) noexcept;
  ~list();
  list &operator=(list &&l) noexcept;

  // List Element access
  const_reference front() const;
  const_reference back() const;

  //  List Iterators
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  const_iterator cbegin() const;
  const_iterator cend() const;

  // List Capacity
  [[nodiscard]] bool empty() const;
  size_type size() const;
  size_type max_size() const;

  // List Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  iterator insert(iterator pos, T &&value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  iterator merge_sublists(iterator lhs, iterator rhs);
  iterator merge_sort(iterator begin, iterator it_end);
  void sort();

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);
  template <typename... Args>
  void insert_many_front(Args &&...args);

  // Public Helper
  // BaseNode *get_fake_node();
};
}  // namespace s21

#include "s21_list.cc"

#endif