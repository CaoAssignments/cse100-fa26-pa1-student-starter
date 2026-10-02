# PA1: Binary Search Tree in C++ (FA26 starter)

The course syllabus and Gradescope assignment provide the release date, due date, points, and AI-use rules.

## Overview

Implement a templated binary search tree (BST), its iterator, deletion, and a balanced copy constructor. The tree stores unique values. Iterating from `begin()` to `end()` must visit values in ascending order. Implement the BST in `src/bst/BSTNode.hpp`, `src/bst/BSTIterator.hpp`, and `src/bst/BST.hpp`. **You must also write and submit your own tests under `test/bst/`.**

Read the starter code and its tests before editing. The public method signatures in the starter are the interface: preserve them. For comparisons between `Data` values, use only `<`; do not assume that `Data` supports `==`, `>`, `<=`, or `>=`. You may compare iterators and pointers as their types permit.

## Methods to implement

### `src/bst/BSTNode.hpp`

| Method | Input | Required result |
| --- | --- | --- |
| `BSTNode(const Data& d)` | One value `d` | Store `d`; initialize `left`, `right`, and `parent` to null. |
| `BSTNode<Data>* successor()` | Called on a node already in a BST | Return the next node in ascending order, or null if this node is last. Do not change the tree. |

`getData()` and `setData()` are provided.

### `src/bst/BSTIterator.hpp`

| Method | Input | Required result |
| --- | --- | --- |
| `bool operator==(const BSTIterator<Data>& other) const` | Another iterator | `true` when both refer to the same node; otherwise `false`. Two end iterators compare equal. |
| `bool operator!=(const BSTIterator<Data>& other) const` | Another iterator | Logical opposite of `operator==`. |

Dereference and increment operators are provided; increment relies on `successor()`.

### `src/bst/BST.hpp`

| Method | Input | Required result |
| --- | --- | --- |
| `BST(const BST<Data>& bst)` | Another BST | Make an independent **balanced** copy containing the same values. Its nodes must not be shared with `bst`. |
| `~BST()` | This tree | Free every owned node. |
| `bool insert(const Data& item)` | Value to add | Add it in BST order and return `true`; if already present, leave the tree unchanged and return `false`. Update size, height, and parent pointers. |
| `iterator find(const Data& item) const` | Value to look up | Return an iterator to it, or `end()` if absent. |
| `bool deleteNode(const Data& item)` | Value to remove | Remove it and return `true`; if absent, return `false` without changing the tree. Preserve BST order, parent pointers, size, and height. Handle leaves, one child, two children, and the root. |
| `unsigned int size() const` | None | Number of stored values. |
| `int height() const` | None | Longest root-to-leaf path measured in edges: empty tree `-1`, one-node tree `0`. |
| `bool empty() const` | None | Whether the tree has no values. |
| `iterator begin() const` | None | Iterator to the smallest value, or `end()` for an empty tree. |
| `vector<Data> inorder() const` | None | All stored values in ascending order; empty vector for an empty tree. |
| `static BSTNode<Data>* first(BSTNode<Data>* root)` | Root of a subtree, possibly null | Its smallest node, or null if the subtree is empty. |
| `static void deleteAll(BSTNode<Data>* n)` | Root of a subtree, possibly null | Delete all nodes in that subtree; handle null safely. |
| `BSTNode<Data>* buildSubtree(vector<Data>& data, int start, int end, int depth)` | Sorted values and half-open range `[start, end)` | Build a balanced subtree from that range, with correct parent pointers and tree height; return its root. An empty range returns null. |

`end()` and `print()` are provided. Do not change `print()`. You may add private helpers. Preserve the visible behavior of all methods and avoid memory leaks.

## Write and submit tests

The provided GoogleTest files in `test/bst/` are starting examples. Add cases that check empty trees, insertion and duplicates, iteration, deletion, and balanced copying. You can extend the existing test files; if you add a new test file, add it to `test/bst/meson.build` so Meson will run it. Your tests should pass on your implementation. Run `ninja -C build test` to check them and `ninja -C build cov` to view their line coverage. The autograder runs the submitted tests and checks for **at least 90% line coverage**. Submit the entire `test/` directory with your `src/` directory.

## Build and run

This project uses **Meson + Ninja + a C++14 compiler**. In a terminal at the repository root:

```sh
meson setup build
ninja -C build
ninja -C build test
```

The first command configures the build, the second compiles all executables, and the third runs the GoogleTest unit tests. After editing code, rerun the Ninja commands; you do not need to configure again unless build files change. To start clean, delete the `build/` directory and repeat all three commands.

After implementing the BST methods, run the integer BST command-line tester with:

```sh
./build/test/bst/mainInt.cpp.executable < data/mainIntInput/mainIntExample.txt
```

The coverage report is under `build/meson-logs/coveragereport/`. For memory checks, run `meson test -C build --wrapper=valgrind`. Do not print extra debugging text to standard output from BST methods, because command-line output is compared with expected output.

The included devcontainer installs the compiler, Meson, Ninja, GoogleTest, and the testing tools. If building outside the devcontainer, install equivalent packages first. See [README.md](README.md) for setup details and [COMMANDS_CHEATSHEET.md](COMMANDS_CHEATSHEET.md) for common commands.

## Debugging tips

When a test fails, start with a small example you can reproduce. To investigate a crash, run a test executable in GDB:

```sh
gdb ./build/test/bst/test_BST.cpp.executable
```

At the `(gdb)` prompt, type `run` to start the test and `bt` to see the call stack if it crashes. You can set a breakpoint in your code and use `print variable_name` to inspect a value. To check for memory leaks, run `valgrind --leak-check=full ./build/test/bst/test_BST.cpp.executable` and look for **definitely lost** bytes in the leak summary. Rebuild with `ninja -C build` after changing your code.

## Submission

Before submitting, compile and test in a fresh checkout. **Submit both your BST implementation and your own tests.** The Gradescope programming assignment accepts a zip whose root contains `src/` and `test/`; create it from the repository root with `./create_submission_zip.sh`. The autograder builds the submitted code with Meson/Ninja and may replace the two command-line test entry points. Keep the required BST header paths and method signatures unchanged. Follow the current course syllabus and Gradescope assignment for the deadline, grading, redo, and AI-use rules.
