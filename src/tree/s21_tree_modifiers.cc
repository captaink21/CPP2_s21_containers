#ifndef S21_TREE_MODIFIERS_CC
#define S21_TREE_MODIFIERS_CC

#include "s21_tree.h"

namespace s21 {

template <typename Key, typename T, typename Compare>
void tree<Key, T, Compare>::DeleteTree(BaseNode* node) {
  if (node == fake_node_) {
    return;
  }
  Node* current = static_cast<Node*>(node);
  DeleteTree(current->left);
  DeleteTree(current->right);
  current->data.~value_type();
  ::operator delete(current);
}

template <typename Key, typename T, typename Compare>
void tree<Key, T, Compare>::clear() {
  if (!empty()) {
    DeleteTree(fake_node_->left);
  }
  size_ = 0;
  delete (fake_node_);
  fake_node_ = begin_ = nullptr;
}

template <typename Key, typename T, typename Compare>
std::pair<typename tree<Key, T, Compare>::iterator, bool>
tree<Key, T, Compare>::Insert(const_reference value) {
  if (fake_node_ == nullptr) {
    fake_node_ = AllocBaseNode();
    try {
      fake_node_->MakeChild(value, Dir::kLeft);
      begin_ = fake_node_->left;
      fake_node_->left->red = false;
    } catch (...) {
      delete (fake_node_);
      fake_node_ = nullptr;
    }
    size_ = 1;
    return std::pair<iterator, bool>(fake_node_->left, true);
  }
  auto [it, is_found] = Find(value.first);
  Node* node = it;
  if (!is_found) {
    if (comp_(value.first, node->data.first)) {
      node = node->MakeChild(value, Dir::kLeft);
      if (node->parent == begin_) {
        begin_ = node;
      }
    } else {
      node = node->MakeChild(value, Dir::kRight);
    }
    BalanceTree(node);
    ++size_;
  }
  return std::pair<iterator, bool>(node, !is_found);
}

template <typename Key, typename T, typename Compare>
std::pair<typename tree<Key, T, Compare>::iterator, bool>
tree<Key, T, Compare>::Insert(value_type&& value) {
  if (fake_node_ == nullptr) {
    fake_node_ = AllocBaseNode();
    try {
      fake_node_->MakeChild(std::move(value), Dir::kLeft);
      begin_ = fake_node_->left;
      fake_node_->left->red = false;
    } catch (...) {
      delete (fake_node_);
      fake_node_ = nullptr;
    }
    size_ = 1;
    return std::pair<iterator, bool>(fake_node_->left, true);
  }
  auto [it, is_found] = Find(value.first);
  Node* node = it;
  if (!is_found) {
    if (comp_(value.first, node->data.first)) {
      node = node->MakeChild(std::move(value), Dir::kLeft);
      if (node->parent == begin_) {
        begin_ = node;
      }
    } else {
      node = node->MakeChild(std::move(value), Dir::kRight);
    }
    BalanceTree(node);
    ++size_;
  }
  return std::pair<iterator, bool>(node, !is_found);
}

template <typename Key, typename T, typename Compare>
void tree<Key, T, Compare>::BalanceTree(Node* inserted) {
  Node* parent = inserted->parent;
  Node* uncle = nullptr;
  while (parent != fake_node_ && parent->red) {
    if (parent == parent->parent->left) {
      uncle = parent->parent->right;
      if (uncle != fake_node_ && uncle->red) {
        uncle->red = false;
        parent->red = false;
        parent->parent->red = true;
        inserted = parent->parent;
        parent = parent->parent->parent;
      } else {
        if (parent->right == inserted) {
          parent = LeftRotate(parent)->parent;
        }
        parent->red = false;
        parent->parent->red = true;

        RightRotate(parent->parent);
      }
    } else {
      uncle = parent->parent->left;
      if (uncle != fake_node_ && uncle->red) {
        uncle->red = false;
        parent->red = false;
        parent->parent->red = true;
        inserted = parent->parent;
        parent = parent->parent->parent;
      } else {
        if (parent->left == inserted) {
          parent = RightRotate(parent)->parent;
        }
        parent->red = false;
        parent->parent->red = true;
        LeftRotate(parent->parent);
      }
    }
    fake_node_->left->red = false;
  }
  fake_node_->left->red = false;
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::Node* tree<Key, T, Compare>::LeftRotate(
    Node* node) {
  Node* parent = node->parent;
  Node* right_node = node->right;
  if (parent->left == node) {
    parent->left = right_node;
  } else {
    parent->right = right_node;
  }
  right_node->parent = parent;
  node->right = right_node->left;
  right_node->left->parent = node;
  right_node->left = node;
  node->parent = right_node;

  return node;
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::Node* tree<Key, T, Compare>::RightRotate(
    Node* node) {
  Node* parent = node->parent;
  Node* left_node = node->left;
  if (parent->left == node) {
    parent->left = left_node;
  } else {
    parent->right = left_node;
  }
  left_node->parent = parent;
  node->left = left_node->right;
  left_node->right->parent = node;
  left_node->right = node;
  node->parent = left_node;

  return node;
}

template <typename Key, typename T, typename Compare>
void tree<Key, T, Compare>::Erase(iterator pos, bool is_delete) {
  Node* node = pos;
  // Deleting root with no children
  if (fake_node_->left == node && size_ == 1) {
    if (is_delete) {
      DeleteTree(fake_node_->left);
    }
    size_ = 0;
    delete (fake_node_);
    fake_node_ = begin_ = nullptr;
    return;
  }
  // Deleting node with 2 children
  if (node->left != fake_node_ && node->right != fake_node_) {
    Node* replaced = ++pos;
    ReplaceNode(node, replaced);
  }
  if (node == begin_) {
    begin_ = ++iterator(node);
  }
  Node** ptr_from =
      (node->Side() == Dir::kLeft) ? &node->parent->left : &node->parent->right;
  // Deleting node with 1 child
  if (node->right != fake_node_) {
    node->right->parent = node->parent;
    *ptr_from = node->right;
    node->right->red = false;
  } else if (node->left != fake_node_) {
    node->left->parent = node->parent;
    *ptr_from = node->left;
    node->left->red = false;
  } else {
    if (!node->red) {
      BalanceDeleteTree(node);
    } else {
      *ptr_from = static_cast<Node*>(fake_node_);
    }
  }
  if (is_delete) {
    node->data.~value_type();
    ::operator delete(node);
  }
  --size_;
}

template <typename Key, typename T, typename Compare>
void tree<Key, T, Compare>::erase(iterator pos) {
  Erase(pos);
}

template <typename Key, typename T, typename Compare>
void tree<Key, T, Compare>::BalanceDeleteTree(Node* node) {
  while (node != fake_node_->left && !node->red) {
    Dir side = node->Side();
    Dir opposite_side = ReverseSide(side);
    node->parent->SetChild(static_cast<Node*>(fake_node_), side);
    Node* sibling = node->parent->GetChild(opposite_side);
    // Red sibling
    if (sibling->red) {
      sibling->red = false;
      node->parent->red = true;
      RotateDirRoot(node->parent, side);
      sibling = node->parent->GetChild(opposite_side);
    }
    Node* close_nephew = sibling->GetChild(side);
    Node* distant_nephew = sibling->GetChild(opposite_side);
    // Black sibling, nephews are leaf or black
    if (close_nephew->IsBlack() && distant_nephew->IsBlack()) {
      sibling->red = true;
      node = node->parent;
    } else {
      // Black sibling, close nephew is red, distant_nephew is leaf or black
      if (distant_nephew->IsBlack()) {
        close_nephew->red = false;
        sibling->red = true;
        RotateDirRoot(sibling, opposite_side);
        distant_nephew = sibling;
        sibling = close_nephew;
      }
      // Black sibling, distant_nephew is red
      sibling->red = node->parent->red;
      node->parent->red = distant_nephew->red = false;
      RotateDirRoot(node->parent, side);
      node = fake_node_->left;
    }
  }
  node->red = false;
}

template <typename Key, typename T, typename Compare>
typename tree<Key, T, Compare>::Node* tree<Key, T, Compare>::RotateDirRoot(
    Node* node, Dir side) {
  assert(node != fake_node_ && node != nullptr);
  Dir opposite_side = ReverseSide(side);
  Node* parent = node->parent;                    // G
  Node* old_son = node->GetChild(opposite_side);  // S
  Node* new_son = old_son->GetChild(side);        // C
  node->SetChild(new_son, opposite_side);
  if (new_son != fake_node_) {
    new_son->parent = node;
  }
  old_son->SetChild(node, side);
  parent->SetChild(old_son, node->Side());
  node->parent = old_son;
  old_son->parent = parent;
  return old_son;
}

template <typename Key, typename T, typename Compare>
void tree<Key, T, Compare>::ReplaceNode(Node* lhs, Node* rhs) {
  if (lhs == rhs) {
    return;
  }
  bool is_usual = true;
  if (lhs->left != rhs) {
    if (lhs->left != fake_node_) {
      lhs->left->parent = rhs;
    }
    if (rhs->left != fake_node_) {
      rhs->left->parent = lhs;
    }
    std::swap(lhs->left, rhs->left);
  } else {
    // rhs - left son of lhs
    is_usual = false;
    rhs->left->parent = lhs;
    lhs->left = rhs->left;
    rhs->left = lhs;
  }

  if (lhs->right != rhs) {
    if (lhs->right != fake_node_) {
      lhs->right->parent = rhs;
    }
    if (rhs->right != fake_node_) {
      rhs->right->parent = lhs;
    }
    std::swap(lhs->right, rhs->right);
  } else {
    // rhs - right son of lhs
    is_usual = false;
    rhs->right->parent = lhs;
    lhs->right = rhs->right;
    rhs->right = lhs;
  }

  if (is_usual) {
    lhs->parent->SetChild(rhs, lhs->Side());
    rhs->parent->SetChild(lhs, rhs->Side());
    std::swap(lhs->parent, rhs->parent);
  } else {
    lhs->parent->SetChild(rhs, lhs->Side());
    rhs->parent = lhs->parent;
    lhs->parent = rhs;
  }
  std::swap(lhs->red, rhs->red);
}

template <typename Key, typename T, typename Compare>
void tree<Key, T, Compare>::merge(tree& other) {
  if (empty()) {
    swap(other);
    return;
  }
  iterator it(other.begin_);
  Node* node = other.begin_;
  while (other.fake_node_ != nullptr && node != other.fake_node_) {
    auto cur_it = it++;
    auto [it_parent, is_found] = Find(node->data.first);
    if (!is_found) {
      other.Erase(cur_it, false);
      Node* parent = it_parent;
      node->red = true;
      node->parent = parent;
      node->left = node->right = static_cast<Node*>(fake_node_);
      if (comp_(node->data.first, parent->data.first)) {
        parent->SetChild(node, Dir::kLeft);
        if (parent == begin_) {
          begin_ = node;
        }
      } else {
        parent->SetChild(node, Dir::kRight);
      }
      BalanceTree(node);
      ++size_;
    }
    node = it;
  }
}

template <typename Key, typename T, typename Compare>
void tree<Key, T, Compare>::swap(tree& other) {
  std::swap(fake_node_, other.fake_node_);
  std::swap(begin_, other.begin_);
  std::swap(size_, other.size_);
  std::swap(comp_, other.comp_);
}

template <typename Key, typename T, typename Compare>
template <typename... Args>
vector<std::pair<typename tree<Key, T, Compare>::iterator, bool>>
tree<Key, T, Compare>::insert_many(Args&&... args) {
  vector<std::pair<typename tree<Key, T, Compare>::iterator, bool>> res;
  (res.push_back(Insert(std::forward<Args>(args))), ...);
  return res;
}

}  // namespace s21

#endif