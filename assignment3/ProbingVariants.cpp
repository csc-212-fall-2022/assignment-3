#include "ProbingVariants.hpp"
namespace assignment3 {

LinearProbingHashTable::LinearProbingHashTable(int capacity)
    : BaseHashTable(capacity) {}

auto LinearProbingHashTable::Index(int key, int i)->int {
    return 0;
}

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
QuadraticProbingHashTable::QuadraticProbingHashTable(int capacity, int c1,
                                                     int c2)
    : BaseHashTable(capacity) {
  c1_ = c1;
  c2_ = c2;
}

auto QuadraticProbingHashTable::Index(int key, int i) -> int {
    return 0;
}

DoubleHashingHashTable::DoubleHashingHashTable(int capacity)
    : BaseHashTable(capacity) {}

auto DoubleHashingHashTable::Index(int key, int i) -> int {
    return 0;
}
} // namespace assignment3
