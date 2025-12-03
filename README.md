# LeetCode & Algorithm Solutions

A comprehensive collection of algorithm and data structure implementations with detailed lecture-style comments for learning and review.

## Overview

This repository contains solutions to LeetCode problems and implementations of fundamental algorithms (searching, sorting) in both C and C++. Each solution includes:
- **Detailed comments** explaining the algorithm idea, invariant, step-by-step process
- **Worked examples** showing how the algorithm executes
- **Complexity analysis** (time and space)
- **Tips and pitfalls** to avoid common mistakes

## Problem Solutions

### LeetCode Problems

| # | Problem | Language | Solution | Notes |
|---|---------|----------|----------|-------|
| 1 | [Two Sum](https://leetcode.com/problems/two-sum/) | C | `1_TwoSum.c` | Hash map / brute force approaches |
| 2 | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | C, C++ | `2_AddTwoNumbers.c`, `2_AddTwoNumbers.cpp` | Linked list manipulation |
| 3 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | C, C++ | `3_LongestSubstringWithoutRepeatingCharacters.c`, `.cpp` | Sliding window technique |
| 4 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | C | `4_MedianofTwoSortedArrays.c` | Binary search, O(log(min(m,n))) |

## Algorithm Implementations

### Searching

- **Binary Search** (`Percipo_BinarySearch.c`, `.cpp`)
  - Time: O(log n)
  - Space: O(1)
  - Lecture notes include: intuition, invariant, proof sketch, worked examples, pitfalls, variations
  - Requirements: array must be sorted

### Sorting

- **Selection Sort** (`Percipo_SelectionSort.c`, `.cpp`)
  - Time: O(n²)
  - Space: O(1) in-place
  - Lecture notes include: invariant, step-by-step process, worked example, stability notes
  - Advantage: fewer writes than other O(n²) sorts (useful for expensive write operations)

## File Structure

```
.
├── README.md
├── 1_TwoSum.c
├── 1_TwoSum.exe
├── 1_TwoSum_Sol.txt
├── 2_AddTwoNumbers.c
├── 2_AddTwoNumbers.cpp
├── 2_AddTwoNumbers.exe
├── 2_AddTwoNumbers.txt
├── 3_LongestSubstringWithoutRepeatingCharacters.c
├── 3_LongestSubstringWithoutRepeatingCharacters.cpp
├── 3_LongestSubstringWithoutRepeatingCharacters.exe
├── 4_MedianofTwoSortedArrays.c
├── Percipo_BinarySearch.c
├── Percipo_BinarySearch.cpp
├── Percipo_BinarySearch.exe
├── Percipo_SelectionSort.c
├── Percipo_SelectionSort.cpp
└── Percipo_SelectionSort.exe
```

## How to Compile and Run

### Windows (with g++ or MinGW)

```powershell
# Compile C solution
gcc -o solution_name solution_name.c

# Compile C++ solution
g++ -o solution_name solution_name.cpp

# Run the executable
.\solution_name.exe
```

### Linux/macOS

```bash
# Compile C solution
gcc -o solution_name solution_name.c

# Compile C++ solution
g++ -o solution_name solution_name.cpp

# Run the executable
./solution_name
```

## Learning Approach

Each solution and algorithm includes comprehensive comment sections:

1. **IDEA / INTUITION**: The core concept and why the approach works
2. **KEY INVARIANT**: What property is maintained throughout execution
3. **ALGORITHM**: Step-by-step breakdown of the process
4. **WORKED EXAMPLE**: Detailed trace showing the algorithm in action
5. **COMPLEXITY ANALYSIS**: Time and space complexity with reasoning
6. **TIPS & PITFALLS**: Common mistakes and edge cases to watch for
7. **VARIATIONS**: Alternative approaches or optimizations

This structure makes the files excellent for:
- Learning fundamental algorithms
- Interview preparation
- Code review and understanding
- Reference during algorithm design

## Complexity Cheat Sheet

| Algorithm | Best | Average | Worst | Space |
|-----------|------|---------|-------|-------|
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) |

## Notes

- Solutions are primarily in **C** for low-level understanding and performance awareness
- Some problems include **C++ versions** for comparison and STL usage
- Focus is on **algorithmic understanding** rather than competitive coding tricks
- All code is **in-place** when possible to minimize space complexity

## Resources

- [LeetCode](https://leetcode.com) - Problem source
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/) - Complexity reference

## Future Additions

- More sorting algorithms (Merge Sort, Quick Sort, Heap Sort)
- More searching techniques (Linear Search, Jump Search)
- Dynamic Programming problems
- Graph algorithms
- Additional LeetCode problems

---

**Last Updated**: November 26, 2025
