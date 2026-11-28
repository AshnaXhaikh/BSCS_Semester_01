# C++ Array Practice & Modular Software Design

A collection of structured C++ programs demonstrating fundamental array operations, top-down modular function design, parameter data safety, and memory pass-by-reference mechanics in C++.

---

## 📋 Table of Contents

1. [Overview](#overview)
2. [Key Programming Principles Covered](#key-programming-principles-covered)
3. [Program 1: Modular Linear Search (`modular_search.cpp`)](#program-1-modular-linear-search-modular_searchcpp)
4. [Program 2: Array Statistics & Analysis (`array_stats.cpp`)](#program-2-array-statistics--analysis-array_statscpp)
5. [Program 3: Array Filtering & Pass-by-Reference (`array_filter.cpp`)](#program-3-array-filtering--pass-by-reference-array_filtercpp)
6. [Compilation & Execution Guide](#compilation--execution-guide)
7. [Core Rules for C++ Array Handling](#core-rules-for-c-array-handling)

---

## 🎯 Overview

This repository contains three foundational C++ practice programs designed to build and reinforce clean, structured programming habits. Each program isolates specific software engineering principles:

* **Modular Function Design:** Separating code into clear prototypes, main execution logic, and distinct helper functions.
* **Data Safety:** Using `const` array parameters to enforce read-only memory access.
* **Memory Mechanics:** Understanding how C++ arrays pass memory addresses (references) to functions, allowing in-place data modification without returning array objects.

---

## 🛠️ Key Programming Principles Covered

| Principle | Description |
| :--- | :--- |
| **Top-Down Design** | Function prototypes declared at top, `main()` kept clean as an overview, and detailed function definitions placed below `main()`. |
| **Single Responsibility** | Every function does exactly one job (e.g., input, calculation, or display) without mixing concerns. |
| **Read-Only Protection (`const`)** | Passing arrays as `const int arr[]` to prevent accidental modification during read operations. |
| **Pass-by-Address / Reference** | Recognizing that passing `arr` to a function sends its memory address, modifying the original array in place. |

---

## 🔍 Program 1: Modular Linear Search (`modular_search.cpp`)

### Purpose
Demonstrates how to decouple user input, array iteration, and searching logic using a standalone, reusable `linearSearch` function.

### Key Concepts
* Returning `-1` to indicate a target is not found in the array.
* Early function exit (`return i;`) upon finding a match.
* Reusable display helper function (`printArray`).

### Source Code
```cpp
#include <iostream>
using namespace std;

const int SIZE = 5;

// Function Prototypes
void printArray(const int arr[], int size);
int linearSearch(const int arr[], int size, int target);

int main() {
    int numbers[SIZE] = {12, 45, 7, 89, 23};
    int target;

    cout << "Dataset: ";
    printArray(numbers, SIZE);

    cout << "Enter a number to search: ";
    cin >> target;

    int foundIndex = linearSearch(numbers, SIZE, target);

    if (foundIndex != -1) {
        cout << "Success: " << target << " found at index [" << foundIndex << "]" << endl;
    } else {
        cout << "Notice: " << target << " is not in the array." << endl;
    }

    return 0;
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Early exit on match
        }
    }
    return -1; // Target not found
}
```

### Sample Output
```text
Dataset: 12 45 7 89 23 
Enter a number to search: 89
Success: 89 found at index [3]
```

---

## 📊 Program 2: Array Statistics & Analysis (`array_stats.cpp`)

### Purpose
Demonstrates the **Separation of Concerns** principle. Mathematical analysis functions (`findMax`, `calculateSum`) perform pure computation and return values back to `main()` without mixing in `cout` or user prompts.

### Key Concepts
* Pure calculation functions that return scalar values (`int`).
* Computing derived values (such as class averages) inside `main()` using returned totals.

### Source Code
```cpp
#include <iostream>
using namespace std;

const int CAPACITY = 6;

// Function Prototypes
int findMax(const int arr[], int size);
int calculateSum(const int arr[], int size);

int main() {
    int scores[CAPACITY] = {88, 92, 79, 95, 61, 84};

    int highestScore = findMax(scores, CAPACITY);
    int totalScore = calculateSum(scores, CAPACITY);
    double averageScore = static_cast<double>(totalScore) / CAPACITY;

    cout << "=== Test Score Analysis ===" << endl;
    cout << "Highest Score : " << highestScore << endl;
    cout << "Total Sum     : " << totalScore << endl;
    cout << "Class Average : " << averageScore << endl;

    return 0;
}

int findMax(const int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int calculateSum(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
```

### Sample Output
```text
=== Test Score Analysis ===
Highest Score : 95
Total Sum     : 499
Class Average : 83.1667
```

---

## ⚙️ Program 3: Array Filtering & Pass-by-Reference (`array_filter.cpp`)

### Purpose
Illustrates how arrays are passed to functions by memory address (reference). The function `extractEvens` populates a secondary destination array (`evensOnly`) declared in `main()` while returning the count of valid elements copied.

### Key Concepts
* **Source (`src`) vs. Destination (`dest`) Arrays:** Passing a read-only source array alongside a writable destination array.
* **Separate Destination Indexing (`destIndex`):** Maintaining an independent tracker for the destination array to prevent gaps in copied data.
* **In-Place Modification:** Modifying `dest[]` inside the function directly alters `evensOnly` in `main()` because both point to the same RAM address.

### Source Code
```cpp
#include <iostream>
using namespace std;

const int MAX = 6;

// Function Prototypes
void printArray(const int arr[], int size);
int extractEvens(const int src[], int srcSize, int dest[]);

int main() {
    int original[MAX] = {7, 14, 21, 28, 35, 42};
    int evensOnly[MAX]; // Destination array

    cout << "Original Array: ";
    printArray(original, MAX);

    // Filter elements and populate evensOnly
    int count = extractEvens(original, MAX, evensOnly);

    cout << "Destination Array (Evens Only): ";
    printArray(evensOnly, count); // Print only the valid copied count

    return 0;
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int extractEvens(const int src[], int srcSize, int dest[]) {
    int destIndex = 0;

    for (int i = 0; i < srcSize; i++) {
        if (src[i] % 2 == 0) {
            dest[destIndex] = src[i]; // Writes directly to main's evensOnly memory
            destIndex++;
        }
    }

    return destIndex; // Return total copied count
}
```

### Sample Output
```text
Original Array: 7 14 21 28 35 42 
Destination Array (Evens Only): 14 28 42 
```

---

## 💻 Compilation & Execution Guide

To compile and run any of these programs using a standard C++ compiler (such as `g++` or within an IDE like Dev-C++ / Code::Blocks):

### Using Terminal / Command Line (`g++`)

```bash
# Compile Program 1
g++ -o modular_search modular_search.cpp
./modular_search

# Compile Program 2
g++ -o array_stats array_stats.cpp
./array_stats

# Compile Program 3
g++ -o array_filter array_filter.cpp
./array_filter
```

---

## 📌 Core Rules for C++ Array Handling

1. **Never use `[]` when calling a function:**
   * **Declaration/Prototype:** `void printArray(const int arr[], int size);`
   * **Function Call:** `printArray(numbers, SIZE);` *(Pass array name only!)*
2. **Always pass the array size:** C++ functions do not inherently know an array's length; always pass `size` as an additional parameter.
3. **Use `const` for read-only access:** Always qualify array parameters with `const` unless the function is explicitly intended to modify array contents.
4. **Arrays pass by reference:** Modifications made to array elements inside a function directly alter the original array in `main()`.
