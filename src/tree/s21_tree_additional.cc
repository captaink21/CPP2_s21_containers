#ifndef S21_TREE_ADDITIONAL_CC
#define S21_TREE_ADDITIONAL_CC

#include "s21_tree.h"

namespace s21 {

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::Dir tree<Key, T, Compare>::BaseNode::Side()
    const {
  assert(parent != nullptr);
  return (this == parent->left) ? Dir::kLeft : Dir::kRight;
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::Dir tree<Key, T, Compare>::ReverseSide(
    Dir side) {
  if (side == Dir::kLeft) {
    return Dir::kRight;
  }
  return Dir::kLeft;
}

template <typename Key, typename T, typename Compare>
bool tree<Key, T, Compare>::Node::IsBlack() {
  if (this->right == nullptr || !red) {
    return true;
  }
  return false;
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::Node* tree<Key, T, Compare>::BaseNode::GetChild(
    const Dir side) const {
  if (side == Dir::kLeft) {
    return left;
  }
  return right;
}

template <typename Key, typename T, typename Compare>
void tree<Key, T, Compare>::BaseNode::SetChild(Node* child, const Dir side) {
  if (side == Dir::kLeft) {
    left = child;
  } else {
    right = child;
  }
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::Node*
tree<Key, T, Compare>::BaseNode::MakeChild(const_reference value,
                                           const Dir side) {
  Node* new_node = static_cast<Node*>(::operator new(sizeof(Node)));
  try {
    ::new (&new_node->data) value_type(value);
    new_node->red = true;
    new_node->parent = static_cast<Node*>(this);
    if (side == Dir::kLeft) {
      new_node->left = new_node->right = left;
      left = new_node;
    } else {
      new_node->left = new_node->right = right;
      right = new_node;
    }
  } catch (...) {
    ::operator delete(new_node);
    throw;
  }
  return new_node;
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::Node*
tree<Key, T, Compare>::BaseNode::MakeChild(value_type&& value, const Dir side) {
  Node* new_node = static_cast<Node*>(::operator new(sizeof(Node)));
  try {
    ::new (&new_node->data) value_type(std::move(value));
    new_node->red = true;
    new_node->parent = static_cast<Node*>(this);
    if (side == Dir::kLeft) {
      new_node->left = new_node->right = left;
      left = new_node;
    } else {
      new_node->left = new_node->right = right;
      right = new_node;
    }
  } catch (...) {
    ::operator delete(new_node);
    throw;
  }
  return new_node;
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::Node*
tree<Key, T, Compare>::BaseNode::CopyChild(const BaseNode* src,
                                           const Dir side) {
  const Node* src_node = static_cast<const Node*>(src);
  Node* child = MakeChild(src_node->data, side);
  child->red = src_node->red;
  return child;
}

#if 0
template <typename Key, typename T, typename Compare>
void tree<Key, T, Compare>::PrintTree(Node* root) {
  if (root == fake_node_) {
    return;
  }
  PrintTree(root->left);
  std::cout << root->data.first << " " << root->data.second << " " << root->red
            << std::endl;
  PrintTree(root->right);
}

#endif

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::Node* tree<Key, T, Compare>::GetRoot() {
  return fake_node_->left;
}

}  // namespace s21

#endif