# Assignment 3

This assignment is slightly different than our previous assignments in that it's adapted from
two textbook exercises: 11.4-1 and 11.4-2.

## What's included?
- `Node.hpp` contains a `Node` struct that will hold the entries of our table.
- `BaseHashTable` is a base hash table class. You'll need to implement `HashInsert`, `HashSearch` and `HashDelete`. You'll notice that the header file specifies the existence of an additional "pure virtual" method `Index`. You're going to implement this in the classes that extend `BaseHashTable` *not* in `BaseHashTable` itself.
- `ProbingVariants.hpp` and `ProbingVariants.cpp` contain three classes:
    - LinearProbingHashTable
    - QuadraticProbingHashTable
    - DoubleHashingHashTable
  each implementing a different probing strategy and extending `BaseHashTable`.
  I've implemented the constructors.
  You'll need to implement the Index method for each of these classes.

## Instructions

1. Complete exercise 11.4-1 on a piece of paper. You don't need to hand this in.
2. For each open addressing strategy (linear, quadratic, double) in, copy your answer (i.e. the resulting state of the array)
from 11.4-1 into the appropriate `indices` vector in `ProbingVariants.test.cpp` (lines 41, 48, 55).
3. Implement `Index` in each of `LinearProbingHashTable`, `QuadraticProbingHashTable` and `DoubleHashingHashTable`
4. Implement `HashInsert`, `HashDelete` and `HashSearch` in `BaseHashTable.cpp`. (`HashDelete` is 11.4-2.)

