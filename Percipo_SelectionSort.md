# Selection Sort - Knowledge Summary

## Core Concept
Selection Sort works by repeatedly **selecting the minimum element** from the unsorted portion and placing it at the beginning of the sorted portion.

## Algorithm Steps
1. Divide array into sorted (left) and unsorted (right) portions
2. Find minimum element in unsorted portion
3. Swap it with first element of unsorted portion
4. Move boundary between sorted/unsorted one position right
5. Repeat until entire array is sorted

## Time & Space Complexity
- **Time Complexity:** 
  - Best Case: O(n²) 
  - Average Case: O(n²)
  - Worst Case: O(n²)
- **Space Complexity:** O(1) - In-place sorting

## Performance Characteristics
- **Number of Comparisons:** Always (n-1) + (n-2) + ... + 1 = n(n-1)/2
- **Number of Swaps:** At most n-1 (better than bubble sort!)
- **Stable:** No (relative order of equal elements may change)
- **Adaptive:** No (doesn't take advantage of existing order)

## Advantages
✅ Simple to understand and implement
✅ Performs well on small lists
✅ Minimal number of swaps (good for expensive swap operations)
✅ In-place sorting (O(1) space)
✅ No worst case degradation

## Disadvantages
❌ O(n²) time complexity - inefficient for large datasets
❌ Not stable
❌ Not adaptive - always does full scan
❌ Poor cache performance

## When to Use
- Small datasets (< 10-20 elements)
- When swap operations are expensive
- When memory is limited (in-place)
- When simplicity is preferred

## Common Pitfalls
❌ Forgetting to check if minIndex != i before swapping
❌ Loop bounds: outer loop should be i < n-1, not i < n
❌ Starting inner loop from 0 instead of i+1

## Key Insight
Selection Sort makes exactly **n-1 passes** through the array. On each pass, it finds the minimum in the unsorted portion and places it in its final position. Unlike bubble sort, it minimizes the number of swaps.

## Comparison with Other O(n²) Sorts
- **vs Bubble Sort:** Fewer swaps, similar comparisons
- **vs Insertion Sort:** Insertion sort is adaptive and stable, selection sort is not
- **Selection sort is best when:** Swap cost is high

## Practice Problems
1. Implement selection sort with custom comparator
2. Count number of swaps in selection sort
3. Selection sort on linked list
4. Find kth smallest using selection sort idea