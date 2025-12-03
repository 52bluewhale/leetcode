# Merge Sort - Knowledge Summary

## Core Concept
Merge Sort is a **divide-and-conquer** algorithm that divides the array into two halves, recursively sorts them, and then **merges** the sorted halves back together. It guarantees O(n log n) performance in ALL cases!

## Algorithm Steps (Divide-and-Conquer)

### DIVIDE Phase:
1. Find the middle point to divide array into two halves
2. Recursively sort the left half
3. Recursively sort the right half
4. Base case: Single element (already sorted)

### CONQUER Phase (Merge):
1. Create temporary arrays for left and right halves
2. Compare elements from both arrays
3. Place smaller element into result array
4. Copy any remaining elements

## Time & Space Complexity
- **Time Complexity:** 
  - Best Case: O(n log n)
  - Average Case: O(n log n)
  - Worst Case: O(n log n)
  - **Consistent performance!**
- **Space Complexity:** O(n) - requires temporary arrays

## Why O(n log n)?
- **Divide:** log n levels (halving each time)
- **Merge:** n operations per level (comparing/copying all elements)
- **Total:** n × log n = O(n log n)

Example: Array of 8 elements
- Levels: log₂(8) = 3 levels
- Work per level: 8 comparisons
- Total: 8 × 3 = 24 operations ≈ n log n

## Performance Characteristics
- **Number of Comparisons:** O(n log n)
- **Number of Copies:** O(n log n)
- **Stable:** Yes (equal elements maintain relative order)
- **Adaptive:** No (always does same work)
- **Predictable:** Yes (consistent O(n log n) performance)

## Advantages
✅ **Guaranteed O(n log n)** - no worst-case degradation
✅ Stable sorting algorithm
✅ Predictable performance
✅ Excellent for linked lists (O(1) space!)
✅ Parallelizable (can sort halves independently)
✅ External sorting (works with data too large for memory)

## Disadvantages
❌ O(n) extra space required
❌ Not adaptive (doesn't optimize for sorted data)
❌ Slower than quicksort in practice (constant factors)
❌ Not in-place (requires extra memory)
❌ Recursive overhead

## When to Use
✅ When you need **guaranteed O(n log n)** performance
✅ Sorting linked lists (best choice!)
✅ External sorting (sorting large files)
✅ When stability is required
✅ Parallel processing environments
✅ When worst-case matters more than average-case

## Common Pitfalls
❌ Forgetting base case (left < right, not left <= right)
❌ Wrong mid calculation: Use left + (right-left)/2 not (left+right)/2
❌ Not freeing temporary arrays in C (memory leak!)
❌ Forgetting to copy remaining elements after merge loop
❌ Using leftArr[i] < rightArr[j] instead of <= (breaks stability!)

## Merge Process - The Key!
The merge is where the magic happens:
```
Left:  [3, 5, 7]    Right: [2, 4, 6]
       ↓                    ↓
Compare 3 vs 2 → Take 2    [2]
Compare 3 vs 4 → Take 3    [2, 3]
Compare 5 vs 4 → Take 4    [2, 3, 4]
Compare 5 vs 6 → Take 5    [2, 3, 4, 5]
Compare 7 vs 6 → Take 6    [2, 3, 4, 5, 6]
Take remaining 7           [2, 3, 4, 5, 6, 7]
```

## Recursion Tree Example
```
         [38,27,43,3]
        /            \
    [38,27]        [43,3]
    /    \         /    \
  [38]  [27]    [43]   [3]
    \    /         \    /
   [27,38]        [3,43]
        \          /
      [3,27,38,43]
```

## Real-World Applications
- **Java's Arrays.sort()** for objects (stable sort needed)
- **External sorting** - sorting huge files that don't fit in memory
- **Sorting linked lists** - best algorithm (O(1) space)
- **Database systems** - external merge sort for large datasets
- **Version control systems** - merging changes

## Variations
1. **Bottom-Up Merge Sort:** Iterative version (no recursion)
2. **Natural Merge Sort:** Optimized for partially sorted data
3. **3-Way Merge Sort:** Divides into 3 parts instead of 2
4. **In-Place Merge Sort:** Reduces space to O(1) but complex

## Key Insight
Merge Sort is the **most predictable sorting algorithm** - it always performs O(n log n) operations regardless of input. This consistency makes it ideal when worst-case performance matters or when you need stability.

## Comparison with QuickSort
| Feature | Merge Sort | Quick Sort |
|---------|-----------|------------|
| Average | O(n log n) | O(n log n) |
| Worst | O(n log n) ✅ | O(n²) ❌ |
| Space | O(n) ❌ | O(log n) ✅ |
| Stable | Yes ✅ | No ❌ |
| Cache | Poor ❌ | Good ✅ |

## Practice Problems
1. LeetCode 148 - Sort List (merge sort on linked list)
2. LeetCode 912 - Sort an Array
3. Count inversions using merge sort
4. Merge K sorted arrays
5. External sorting implementation

## Interview Tips
When to mention Merge Sort:
- "I need **guaranteed O(n log n)** performance"
- "The data is in a **linked list**"
- "I need a **stable** sort"
- "I'm doing **external sorting**"
- "I want to **parallelize** the sorting"

These show you understand practical algorithm selection!

## Memory Management (C)
Always remember to:
```c
int* leftArr = (int*)malloc(n1 * sizeof(int));
// ... use array ...
free(leftArr);  // DON'T FORGET THIS!
```

## The Big Picture
Merge Sort represents a fundamental computer science principle: **Divide and Conquer**
1. **Divide** problem into smaller subproblems
2. **Conquer** subproblems recursively
3. **Combine** solutions to solve original problem

This pattern appears everywhere: binary search, quicksort, FFT, matrix multiplication, and more!