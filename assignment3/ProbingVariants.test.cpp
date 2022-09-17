#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "ProbingVariants.hpp"
#include "doctest/doctest.h"
#include <vector>

using namespace assignment3;

std::vector<int> entries = {10, 22, 31, 4, 15, 28, 17, 88, 59};

TEST_CASE("Tables overflow when they run out of capacity") {
  LinearProbingHashTable table = LinearProbingHashTable(2);
  table.HashInsert(1, 1);
  table.HashInsert(2, 2);
  CHECK_THROWS_AS(table.HashInsert(3, 3), std::overflow_error);
}

TEST_CASE("Tables underflow when we delete something nonexistent") {
  LinearProbingHashTable table = LinearProbingHashTable(3);
  CHECK_THROWS_AS(table.HashDelete(7), std::underflow_error);
}

TEST_CASE("Exercise 11.4-1") {
  LinearProbingHashTable linear_table = LinearProbingHashTable(11);
  QuadraticProbingHashTable quadratic_table =
      QuadraticProbingHashTable(11, 1, 3);
  DoubleHashingHashTable double_table = DoubleHashingHashTable(11);
  for (int i = 0; i < 9; i++) {
    linear_table.HashInsert(entries.at(i), entries.at(i));
    quadratic_table.HashInsert(entries.at(i), entries.at(i));
    double_table.HashInsert(entries.at(i), entries.at(i));
  }

  SUBCASE("Baseline -- 10 always goes into index 10") {
    CHECK(linear_table.Get(10) == 10);
    CHECK(quadratic_table.Get(10) == 10);
    CHECK(double_table.Get(10) == 10);
  }

  SUBCASE("Linear Probing") {
    std::vector<int> indices = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < 9; i++) {
      CHECK(linear_table.Get(indices.at(i)) == entries.at(i));
    }
  }

  SUBCASE("Quadratic Probing") {
    std::vector<int> indices = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < 9; i++) {
      CHECK(quadratic_table.Get(indices.at(i)) == entries.at(i));
    }
  }

  SUBCASE("Double Probing") {
    std::vector<int> indices = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < 9; i++) {
      CHECK(double_table.Get(indices.at(i)) == entries.at(i));
    }
  }
}

TEST_CASE("11.4-2") {
  SUBCASE("Insert and delete leaves tombstone") {
    LinearProbingHashTable table = LinearProbingHashTable(5);
    table.HashInsert(3, 3);
    table.HashDelete(3);

    CHECK(table.IsTombStone(3));
  }

  SUBCASE("Make sure we delete the correct thing I") {
    LinearProbingHashTable table = LinearProbingHashTable(5);
    table.HashInsert(1, 1);
    table.HashInsert(6, 6);
    table.HashDelete(1);

    CHECK(table.IsTombStone(1));
    CHECK(table.HashSearch(6) == 6);
  }

  SUBCASE("Make sure we delete the correct thing II") {
    LinearProbingHashTable table = LinearProbingHashTable(5);
    table.HashInsert(1, 1);
    table.HashInsert(6, 6);
    table.HashDelete(6);

    CHECK_FALSE(table.IsTombStone(1));
    CHECK_THROWS_AS(table.HashSearch(6), std::underflow_error);
  }
}
