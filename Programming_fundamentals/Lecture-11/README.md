# CS201 – Lecture 11: Arrays, Linear Search & Pseudo-Random Numbers

## Overview
In **CS201 Lecture 11**, the focus transitions from simple individual variables to composite data structures. This module introduces **one-dimensional arrays**, **loop-driven array processing**, **sentinel-controlled input**, **linear search algorithms**, **pseudo-random number generation**, and best practices using **`const` identifiers** in C++.

---

## Key Concepts Covered

1. **Motivation for Arrays**
   * Declaring individual variables for large datasets (e.g., `age1`, `age2`, ..., `age100`) is inefficient and error-prone.
   * Arrays store collections of identical data types under a single identifier in contiguous memory locations.
   * **Syntax:** `dataType arrayName[SIZE];` (e.g., `int age[100];`).
   * **Zero-Based Indexing:** An array of size $N$ uses indices from $0$ to $N - 1$.

2. **Loop-Driven Operations**
   * Using `for` and `while` loops to initialize arrays, read user input, compute sums/averages, and copy elements between arrays.

3. **Sentinel-Controlled Array Input**
   * Dynamically populating an array until a special sentinel value (e.g., `-1`) is entered or the maximum array capacity is reached.

4. **Linear Search**
   * Scanning an array sequentially from index `0` to `SIZE - 1` to find a target value, updating a boolean flag (`isFound`), and terminating early with `break`.

5. **Pseudo-Random Numbers (`<cstdlib>` / `rand()`)**
   * `rand()` returns a pseudo-random integer between `0` and `RAND_MAX` (typically `32767`).
   * Modulo arithmetic (`rand() % N`) restricts output to the range `0` through `N - 1`.
   * Scaling expressions such as `(rand() % 6) + 1` simulate real-world events like rolling a 6-sided die.

6. **Constant Identifiers (`const`)**
   * Replacing "magic numbers" with named constants (e.g., `const int SIZE = 100;`) to safely manage array bounds across loops and functions.

---

## Included Practice Programs

| # | Program Title | Key Concepts Demonstrated |
| :--- | :--- | :--- |
| **1** | **Student Age & Average Processor** | Array declaration, `const` bounds, `for` loop input/summation, `static_cast<double>` |
| **2** | **Sentinel-Controlled Array Input** | `do-while` loop, sentinel termination (`-1`), capacity bounds checking |
| **3** | **Linear Search Demo** | Sequential traversal, boolean flag (`isFound`), index tracking, early exit with `break` |
| **4** | **Array Copying & Sum of Squares** | Element-by-element array copying (`dest[i] = src[i]`), mathematical accumulation |
| **5** | **Pseudo-Random Die Roll Simulation** | `<cstdlib>`, `rand()`, modulo scaling `(rand() % 6) + 1`, frequency counter array |

---

## Program Details

### 1. Array Declaration, Loop Input, and Average Calculation
* **File:** `program1_average_age.cpp`
* **Description:** Replaces 10 separate variables with a single `ages[MAX_STUDENTS]` array. Uses two `for` loops to collect student ages and compute their sum and formatted average.

### 2. Sentinel-Controlled Array Input & Bounds Checking
* **File:** `program2_sentinel_input.cpp`
* **Description:** Continuously reads positive integers into an array of capacity `100` using a `do-while` loop until the user enters `-1` or the array reaches full capacity.

### 3. Linear Search in an Array
* **File:** `program3_linear_search.cpp`
* **Description:** Searches a pre-populated integer array for a user-specified target value. Uses a boolean flag and `break` statement to halt execution as soon as a match is found.

### 4. Array Copying & Sum of Squares Computation
* **File:** `program4_array_copy.cpp`
* **Description:** Demonstrates that C++ arrays cannot be copied with a single assignment statement (`dest = src`), instead copying elements one by one via a loop before calculating the sum of their squares.

### 5. Pseudo-Random Die Roll Simulation
* **File:** `program5_die_simulation.cpp`
* **Description:** Simulates 6,000 rolls of a 6-sided die using `(rand() % 6) + 1` and tracks how often each face (`1`–`6`) appears using a frequency array (`int frequency[7] = {0};`).

---

## How to Compile and Run

Use any standard C++ compiler (such as `g++`):

```bash
# Compile a program
g++ program1_average_age.cpp -o program1

# Run the executable (Linux/macOS)
./program1

# Run the executable (Windows)
program1.exe
```

---

## Notes & Best Practices
* **Array Initialization:** When using an array as a frequency counter (as in Program 5), always initialize all elements to zero (`int frequency[7] = {0};`) to prevent garbage values.
* **Out-of-Bounds Safety:** Always ensure loop conditions stay strictly less than the array size (`i < SIZE`) to prevent undefined behavior.