# Bubble Sort - Knowledge Summary

## Core Concept
Bubble Sort works by repeatedly **comparing adjacent elements** and swapping them if they're in the wrong order. Larger elements "bubble up" to their correct positions at the end of the array.

## Algorithm Steps
1. Compare each pair of adjacent elements
2. Swap them if they're in wrong order
3. After each pass, the largest unsorted element is in its final position
4. Repeat for remaining unsorted elements
5. Stop when no swaps occur (array is sorted)

## Time & Space Complexity
- **Time Complexity:** 
  - Best Case: O(n) - when array is already sorted (with optimization)
  - Average Case: O(n²)
  - Worst Case: O(n²) - when array is reverse sorted
- **Space Complexity:** O(1) - In-place sorting

## Performance Characteristics
- **Number of Comparisons:** Up to n(n-1)/2
- **Number of Swaps:** Up to n(n-1)/2 (worst case - reverse sorted)
- **Stable:** Yes (relative order of equal elements preserved)
- **Adaptive:** Yes (with optimization flag - O(n) for sorted arrays)

## Optimization: The Swapped Flag
```c
bool swapped = false;
// ... do swaps ...
if (!swapped) break;  // Already sorted!
```
This optimization makes bubble sort **adaptive** - it can detect when the array is already sorted and terminate early.

## Advantages
✅ Simple to understand and implement
✅ Stable sorting algorithm
✅ Adaptive (with optimization)
✅ In-place sorting (O(1) space)
✅ Good for detecting if array is already sorted

## Disadvantages
❌ O(n²) time complexity - very inefficient for large datasets
❌ Many unnecessary comparisons
❌ Poor cache performance
❌ Generally slower than other O(n²) algorithms in practice

## When to Use
- Educational purposes (teaching sorting concepts)
- Very small datasets (< 10 elements)
- When detecting nearly-sorted arrays
- When simplicity is more important than efficiency

## Common Pitfalls
❌ Forgetting the optimization flag (makes it non-adaptive)
❌ Wrong loop bounds: inner loop should be j < n-i-1
❌ Not understanding why it's called "bubble" sort
❌ Using it for large datasets (use quicksort/mergesort instead!)

## Why "Bubble"?
The name comes from how larger elements "bubble up" to the end of the array, like bubbles rising in water. After each pass, the largest unsorted element is guaranteed to be in its final position.

## Key Insight
Bubble Sort makes up to **n-1 passes**. Each pass guarantees one more element is in its final position (at the end). The optimization flag allows early termination when array becomes sorted.

## Comparison with Other O(n²) Sorts
- **vs Selection Sort:** More swaps but stable and adaptive
- **vs Insertion Sort:** Insertion sort is usually faster in practice
- **Bubble sort is best when:** Array is nearly sorted or you need stability

## Variations
1. **Cocktail Shaker Sort:** Bidirectional bubble sort (alternates left-to-right and right-to-left)
2. **Comb Sort:** Improves bubble sort by comparing elements with larger gaps

## Practice Problems
1. Optimize bubble sort to work in both directions
2. Count number of swaps in bubble sort
3. Implement bubble sort on linked list
4. Detect if array can be sorted with one swap (bubble sort application)

## Interview Tip
If asked to implement bubble sort in an interview, ALWAYS add the optimization flag - it shows you understand adaptive algorithms!