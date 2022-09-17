#include <string>

namespace assignment3 {
struct Node {
  int key;
  int value;

  Node() = default;
  Node(int k, int v) {
    key = k;
    value = v;
  }
};
} // namespace assignment3
