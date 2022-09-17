#include "BaseHashTable.hpp"
#include <stdexcept>
namespace assignment3 {

void BaseHashTable::HashInsert(int key, int value) { // NOLINT(bugprone-easily-swappable-parameters)
    throw std::runtime_error("Not implemented!");
}

auto BaseHashTable::HashSearch(int key) -> int {
    throw std::runtime_error("Not implemented!");
}

void BaseHashTable::HashDelete(int key) {
    throw std::runtime_error("Not implemented!");
}

BaseHashTable::BaseHashTable(int capacity) {
  capacity_ = capacity;
  arr_.resize(capacity);
  tombstone_ = Node();
}
BaseHashTable::~BaseHashTable() {
  // make sure we delete all the stuff in our vector
  for (int i = 0; i < capacity_; i++) {
    // make sure we don't try to delete the nullptr or free the tombstone
    // prematurely
    if (arr_.at(i) != nullptr && !IsTombStone(i)) {
      delete arr_.at(i);
    }
  }
}
auto BaseHashTable::Get(int idx) -> int { return arr_.at(idx)->value; }
auto BaseHashTable::IsTombStone(int idx) -> bool { return arr_.at(idx) == &tombstone_; }
} // namespace assignment3
