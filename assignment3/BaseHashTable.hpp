#include "Node.hpp"
#include <functional>
#include <string>
#include <vector>

#ifndef ASSIGNMENT_3_BASEHASHTABLE_HPP
#define ASSIGNMENT_3_BASEHASHTABLE_HPP

namespace assignment3 {
class BaseHashTable {
protected:
  int capacity_;
  Node tombstone_ = Node();
  std::vector<Node *> arr_;

public:
  explicit BaseHashTable(int);
  ~BaseHashTable();

  // Get the value at index x of arr_. This is a convenience for the tests.
  auto Get(int) -> int;

  // Check whether an index contains the tombstone.
  auto IsTombStone(int) -> bool;

  void HashInsert(int, int);

  auto HashSearch(int) -> int;

  void HashDelete(int);

  virtual auto Index(int, int) -> int = 0;
};
} // namespace assignment3

#endif // ASSIGNMENT_3_BASEHASHTABLE_HPP
