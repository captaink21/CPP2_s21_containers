#ifndef S21_VECTOR_MODIFIERS_CC
#define S21_VECTOR_MODIFIERS_CC

#include "s21_vector.h"

namespace s21 {

template <typename T>
void vector<T>::clear() {
  DestroyerElements();
}

template <typename T>
T* vector<T>::insert(iterator pos, const_reference value) {
  iterator return_pos = pos;
  if (vb_.extra == vb_.outside) {
    VectorBase<value_type> new_vb(empty() ? 1 : 2 * size());
    return_pos = new_vb.first + (pos - vb_.first);
    ::new (return_pos) T(value);
    iterator tmp = return_pos;
    try {
      if constexpr (std::is_nothrow_move_constructible<T>::value) {
        std::uninitialized_move(vb_.first, pos, new_vb.first);
      } else {
        std::uninitialized_copy(vb_.first, pos, new_vb.first);
      }
      tmp = new_vb.first;
      if constexpr (std::is_nothrow_move_constructible<T>::value) {
        std::uninitialized_move(pos, vb_.extra, return_pos + 1);
      } else {
        std::uninitialized_copy(pos, vb_.extra, return_pos + 1);
      }
    } catch (...) {
      DestroyerElements(tmp, return_pos + 1);
      throw;
    }
    new_vb.extra = new_vb.first + size() + 1;
    std::swap(vb_, new_vb);
  } else if (empty() || pos == end()) {
    ::new (vb_.extra) T(value);
    ++vb_.extra;
  } else {
    ::new (end()) T(std::move(*(end() - 1)));
    ++vb_.extra;
    for (iterator it = vb_.extra - 2; it != pos; it--) {
      *it = std::move(*(it - 1));
    }
    *pos = value;
  }

  return return_pos;
}

template <typename T>
T* vector<T>::insert(iterator pos, T&& value) {
  iterator return_pos = pos;
  if (vb_.extra == vb_.outside) {
    VectorBase<value_type> new_vb(empty() ? 1 : 2 * size());
    return_pos = new_vb.first + (pos - vb_.first);
    ::new (return_pos) T(std::move(value));
    iterator tmp = return_pos;
    try {
      if constexpr (std::is_nothrow_move_constructible<T>::value) {
        std::uninitialized_move(vb_.first, pos, new_vb.first);
      } else {
        std::uninitialized_copy(vb_.first, pos, new_vb.first);
      }
      tmp = new_vb.first;
      if constexpr (std::is_nothrow_move_constructible<T>::value) {
        std::uninitialized_move(pos, vb_.extra, return_pos + 1);
      } else {
        std::uninitialized_copy(pos, vb_.extra, return_pos + 1);
      }
    } catch (...) {
      DestroyerElements(tmp, return_pos + 1);
      throw;
    }
    new_vb.extra = new_vb.first + size() + 1;
    std::swap(vb_, new_vb);
  } else if (empty() || pos == end()) {
    ::new (vb_.extra) T(std::move(value));
    ++vb_.extra;
  } else {
    ::new (end()) T(std::move(*(end() - 1)));
    ++vb_.extra;
    for (iterator it = vb_.extra - 2; it != pos; it--) {
      *it = std::move(*(it - 1));
    }
    *pos = std::move(value);
  }

  return return_pos;
}

template <typename T>
void vector<T>::erase(iterator pos) {
  for (; pos != end() - 1; ++pos) {
    *pos = std::move(*(pos + 1));
  }
  pos->~value_type();
  --vb_.extra;
}

template <typename T>
void vector<T>::push_back(const_reference value) {
  if (vb_.extra == vb_.outside) {
    size_type new_size = (empty() ? 1 : 2 * size());
    if (new_size > max_size()) {
      throw std::out_of_range("Number of elements more than max_size");
    }
    VectorBase<value_type> new_vb(new_size);
    ::new (new_vb.first + size()) T(value);
    try {
      if constexpr (std::is_nothrow_move_constructible<T>::value) {
        std::uninitialized_move(vb_.first, vb_.extra, new_vb.first);
      } else {
        std::uninitialized_copy(vb_.first, vb_.extra, new_vb.first);
      }
    } catch (...) {
      (new_vb.first + size())->~value_type();
      throw;
    }
    new_vb.extra = new_vb.first + size() + 1;
    DestroyerElements();
    std::swap(vb_, new_vb);
  } else {
    ::new (vb_.extra) T(value);
    ++vb_.extra;
  }
}

template <typename T>
void vector<T>::pop_back() {
  erase(vb_.extra - 1);
}

template <typename T>
void vector<T>::swap(vector& other) {
  std::swap(vb_, other.vb_);
}

template <typename T>
template <typename... Args>
T* vector<T>::insert_many(const_iterator pos, Args&&... args) {
  iterator return_pos = const_cast<iterator>(pos);
  size_t count = return_pos - begin();
  size_type new_size = size() + sizeof...(args);

  if (new_size > capacity()) {
    reserve(new_size);
  }
  return_pos = begin() + count;
  (insert(return_pos++, std::forward<Args>(args)), ...);
  return_pos = begin() + count;
  return return_pos;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args&&... args) {
  size_type new_size = size() + sizeof...(args);
  if (new_size > capacity()) {
    reserve(new_size);
  }

  (insert(end(), std::forward<Args>(args)), ...);
}

}  // namespace s21

#endif
