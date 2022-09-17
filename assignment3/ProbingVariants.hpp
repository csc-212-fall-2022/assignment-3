#ifndef SOME_ASSIGNMENT_PROBINGVARIANTS_HPP
#define SOME_ASSIGNMENT_PROBINGVARIANTS_HPP

#include "BaseHashTable.hpp"

namespace assignment3 {
class LinearProbingHashTable : public BaseHashTable {
public:
  explicit LinearProbingHashTable(int);
  auto Index(int key, int i) -> int override;
  ~LinearProbingHashTable() = default;
};

class QuadraticProbingHashTable : public BaseHashTable {
private:
  int c1_;
  int c2_;

public:
  explicit QuadraticProbingHashTable(int, int, int);
  auto Index(int key, int i) -> int override;
};

class DoubleHashingHashTable : public BaseHashTable {
public:
  explicit DoubleHashingHashTable(int);
  auto Index(int key, int i) -> int override;
};
} // namespace assignment3

#endif // SOME_ASSIGNMENT_PROBINGVARIANTS_HPP
