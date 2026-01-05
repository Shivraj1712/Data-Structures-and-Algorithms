# C++ Data Structures and Algorithms (DSA) Library

A collection of high-performance, clean-code implementations of fundamental Data Structures and Algorithms in C++. This repository serves as a technical reference for memory-efficient programming and algorithmic logic.

## 🛠️ Implemented Data Structures

### 1. Linked Lists (`linkedlist.cpp`)
Modular implementations of linear data structures with optimized pointer management.

* **Singly Linked List (SLL)**
    * **Tail Optimization:** $O(1)$ insertions at both ends using `head` and `tail` pointers.
    * **Features:** Positional insertion, linear search, and automated memory cleanup via destructor.
* **Doubly Linked List (DLL)**
    * **Bi-directional Traversal:** $O(1)$ deletion from the tail (`pop_back`) facilitated by `prev` pointers.
    * **Memory Safety:** Strict pointer nullification to prevent dangling references.



### 2. Stacks (`stack.cpp`)
Implementations of the LIFO (Last-In, First-Out) principle using varied underlying memory architectures.

* **Vector-Based (`StackUV`):** Leverages dynamic arrays for cache-friendly access and amortized $O(1)$ operations.
* **List-Based (`StackLL`):** Uses linked nodes to ensure strictly $O(1)$ insertions without the overhead of array reallocations.
* **STL Comparison:** Benchmarked against `std::stack` for logic verification.



---

## 📂 Repository Structure
Adhering to a clean, scalable project architecture:
* `linkedlist.cpp` - Comprehensive Node and List class definitions.
* `stack.cpp` - Container-based stack implementations.
* `main()` - Unit tests and driver code for each structure.