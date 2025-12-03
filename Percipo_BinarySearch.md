# Binary Search - Knowledge Summary

## Core Concept
Binary Search is a **divide-and-conquer** algorithm that efficiently finds a target value in a **sorted** array by repeatedly dividing the search interval in half.

## Key Requirements
✅ Array MUST be sorted
✅ Random access to elements (array/vector)

## Time & Space Complexity
- **Time:** O(log n) - Halves search space each iteration
- **Space:** O(1) - Only uses a few variables

## Algorithm Steps
1. Set left pointer to start, right pointer to end
2. Calculate mid = left + (right - left) / 2
3. Compare arr[mid] with target:
   - If equal → Found! Return mid
   - If arr[mid] < target → Search right half (left = mid + 1)
   - If arr[mid] > target → Search left half (right = mid - 1)
4. Repeat until left > right (not found)

## Common Pitfalls
❌ Forgetting array must be sorted
❌ Using (left + right) / 2 → Can overflow!
✅ Use left + (right - left) / 2 instead

❌ Wrong loop condition (left < right vs left <= right)
✅ Use left <= right to check all elements

❌ Not handling empty array or single element

## Variations
- **Lower Bound:** Find first position >= target
- **Upper Bound:** Find first position > target
- **Binary Search on Answer:** Find optimal value in range

## Real-World Applications
- Dictionary lookups
- Database indexing
- Finding insertion points
- Debugging (git bisect)
- Library search systems

## Practice Problems
1. LeetCode 704 - Binary Search
2. LeetCode 35 - Search Insert Position
3. LeetCode 74 - Search a 2D Matrix
4. LeetCode 33 - Search in Rotated Sorted Array

## Key Insight
Binary Search reduces O(n) linear search to O(log n) by eliminating half the possibilities at each step - this is the power of divide-and-conquer on sorted data!