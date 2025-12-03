# Queue Input/Output Analysis

## Basic Queue Operations

### 1. Enqueue Operation
**Input**: 
- Element to add (any data type)
- Current queue state

**Output**: 
- Updated queue with element at rear
- Success/Failure status
- Error: "Queue Overflow" if full

**Example**:
```
Initial Queue: [10, 20, 30] (front → rear)
Enqueue(40)
Result Queue: [10, 20, 30, 40]
```

---

### 2. Dequeue Operation
**Input**: 
- Current queue state

**Output**: 
- Removed element from front
- Updated queue
- Error: "Queue Underflow" if empty

**Example**:
```
Initial Queue: [10, 20, 30, 40]
Dequeue() → Returns 10
Result Queue: [20, 30, 40]
```

---

### 3. Peek/Front Operation
**Input**: 
- Current queue state

**Output**: 
- Front element value (without removing)
- Error: "Queue is empty" if empty

**Example**:
```
Queue: [10, 20, 30]
Peek() → Returns 10
Queue remains: [10, 20, 30]
```

---

### 4. isEmpty Operation
**Input**: 
- Current queue state

**Output**: 
- Boolean: true if empty, false otherwise

**Example**:
```
Queue: []
isEmpty() → true

Queue: [10]
isEmpty() → false
```

---

### 5. isFull Operation (Array-based)
**Input**: 
- Current queue state
- Maximum capacity

**Output**: 
- Boolean: true if full, false otherwise

**Example**:
```
Queue: [10, 20, 30] with capacity 3
isFull() → true

Queue: [10, 20] with capacity 5
isFull() → false
```

---

## Queue Implementation Types

### 1. Simple Array Queue
- Fixed size
- Front pointer moves forward
- **Problem**: Wasted space at front

### 2. Circular Queue
- Fixed size
- Reuses front space using modulo operation
- **Advantage**: No wasted space

### 3. Linked List Queue
- Dynamic size
- No size limitation (until memory exhausted)
- **Advantage**: No overflow (practically)

---

## Time Complexity Analysis

| Operation | Array Queue | Circular Queue | Linked List Queue |
|-----------|-------------|----------------|-------------------|
| Enqueue   | O(1)        | O(1)           | O(1)              |
| Dequeue   | O(1)        | O(1)           | O(1)              |
| Peek      | O(1)        | O(1)           | O(1)              |
| isEmpty   | O(1)        | O(1)           | O(1)              |
| isFull    | O(1)        | O(1)           | N/A               |

**Space Complexity**: O(n) for all implementations