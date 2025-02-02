#ifndef S21_TREE_H
#define S21_TREE_H

#include <cassert>           // For assert
#include <cstddef>           // For std::size_t
#include <functional>        // For std::less
#include <initializer_list>  // For std::initializer_list
#include <utility>           // For std::pair

#include "../vector/s21_vector.h"

namespace s21 {
template <typename Key, typename T, typename Compare>
class tree {
 public:
  // Forward declarations
  class TreeIterator;
  class TreeConstIterator;
  // Tree member types
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;
  using iterator = TreeIterator;
  using const_iterator = TreeConstIterator;

 protected:
  enum class Dir { kLeft, kRight };

  struct Node;

  struct BaseNode {
    Node *left;
    Node *right;
    Node *parent;

    Dir Side() const;
    Node *GetChild(const Dir side) const;
    void SetChild(Node *, const Dir side);
    Node *CopyChild(const BaseNode *src, const Dir side);
    Node *MakeChild(const_reference value, const Dir side);
    Node *MakeChild(value_type &&value, const Dir side);
  };

  struct Node : BaseNode {
    value_type data;
    bool red;
    bool IsBlack();
  };

  // Member objects
  BaseNode *fake_node_;
  Node *begin_;
  size_type size_;
  Compare comp_;

  // Helpers
  BaseNode *AllocBaseNode();

  Node *LeftRotate(Node *node);
  Node *RightRotate(Node *node);
  Node *RotateDirRoot(Node *node, Dir side);

  void DeleteTree(BaseNode *root);
  void BalanceTree(Node *inserted);
  void BalanceDeleteTree(Node *deleted);
  void TreeCopy(BaseNode *curr_root, BaseNode *other_root,
                const BaseNode *other_fn, const BaseNode *other_begin);

  std::pair<iterator, bool> Find(const key_type &key);
  Dir ReverseSide(Dir side);
  void ReplaceNode(Node *lhs, Node *rhs);

  virtual std::pair<iterator, bool> Insert(const value_type &value);
  virtual std::pair<iterator, bool> Insert(value_type &&value);
  void Erase(iterator pos, bool is_delete = true);

 public:
  // TreeIterator
  class TreeIterator {
   protected:
    Node *ptr_;
    TreeIterator &Next();
    TreeIterator &Prev();

   public:
    TreeIterator();
    TreeIterator(Node *node);
    virtual ~TreeIterator(){};

    reference operator*() const;
    value_type *operator->() const;
    TreeIterator &operator++();
    TreeIterator operator++(int);
    TreeIterator &operator--();
    TreeIterator operator--(int);
    bool operator==(const TreeIterator &other) const;
    bool operator!=(const TreeIterator &other) const;
    bool IsRed() const;

    operator Node *();
  };

  // TreeConstIterator
  class TreeConstIterator {
   protected:
    const Node *ptr_;
    TreeConstIterator &Next();
    TreeConstIterator &Prev();

   public:
    TreeConstIterator();
    TreeConstIterator(const Node *node);
    virtual ~TreeConstIterator(){};

    const_reference operator*() const;
    const value_type *operator->() const;
    TreeConstIterator &operator++();
    TreeConstIterator operator++(int);
    TreeConstIterator &operator--();
    TreeConstIterator operator--(int);
    bool operator==(const TreeConstIterator &other) const;
    bool operator!=(const TreeConstIterator &other) const;
    bool IsRed() const;

    operator const Node *();
  };

  // Tree Iterators
  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

  // Tree Member functions
  tree();
  tree(std::initializer_list<value_type> const &items);
  tree(const tree &m);
  tree(tree &&m) noexcept;
  virtual ~tree() = 0;
  tree &operator=(tree &&m) noexcept;

  // Tree Capacity
  [[nodiscard]] bool empty() const;
  size_type size() const;
  size_type max_size() const;

  // Tree Modifiers
  void clear();
  void erase(iterator pos);
  void swap(tree &other);
  void merge(tree &other);

  template <typename... Args>
  vector<std::pair<iterator, bool>> insert_many(Args &&...args);

  // Tree Lookup
  bool contains(const Key &key);

  // Public Helpers
  void PrintTree(Node *root);
  Node *GetRoot();
};

}  // namespace s21

#include "s21_tree_additional.cc"
#include "s21_tree_capacity.cc"
#include "s21_tree_iterators.cc"
#include "s21_tree_lookup.cc"
#include "s21_tree_member_func.cc"
#include "s21_tree_modifiers.cc"

#endif