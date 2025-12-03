# 🎯 Queue Quick Reference Card

## Core Operations (All O(1))

```c
// ENQUEUE - Add to rear
void enqueue(Queue* q, int value) {
    if (isFull(q)) return;
    rear = (rear + 1) % capacity;  // Circular!
    items[rear] = value;
    size++;
}

// DEQUEUE - Remove from front
int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    int value = items[front];
    front = (front + 1) % capacity;  // Circular!
    size--;
    return value;
}

// PEEK - View front
int peek(Queue* q) {
    return isEmpty(q) ? -1 : items[front];
}
```

---

## Three Implementation Types

| Type | Space | Advantage | Disadvantage | Use Case |
|------|-------|-----------|--------------|----------|
| **Array** | O(n) fixed | Simple, fast | Wastes space | Short-lived queues |
| **Circular** | O(n) fixed | No waste | Still fixed | Bounded buffers |
| **Linked** | O(n) dynamic | Unlimited | Pointer overhead | General purpose |

---

## Critical Formulas

### Circular Queue Modulo Magic:
```c
rear = (rear + 1) % capacity;   // Wrap to beginning
front = (front + 1) % capacity;  // Wrap to beginning
```

### Full/Empty Checks:
```c
isEmpty: size == 0
isFull:  size == capacity
```

---

## Common Pitfalls ⚠️

1. **Array Queue Waste**: ❌ Don't use → ✅ Use Circular Queue
2. **Forgot Modulo**: ❌ `rear++` → ✅ `rear = (rear + 1) % capacity`
3. **Memory Leak**: ❌ `front = front->next` → ✅ Free old node first
4. **Empty rear**: ❌ Dangling → ✅ Set `rear = NULL` when empty

---

## Implementation Template

### Circular Queue (Most Common in Interviews):
```c
typedef struct {
    int* items;
    int front, rear, size, capacity;
} CircularQueue;

// Initialize: front=0, rear=-1, size=0
// Enqueue: rear = (rear+1) % cap, size++
// Dequeue: front = (front+1) % cap, size--
// Full: size == capacity
// Empty: size == 0
```

---

## Real-World Uses

- **OS**: Process scheduling, I/O buffering
- **Network**: Router packet queues
- **Algorithm**: BFS traversal
- **System**: Print spooler, call center

---

## Key Interview Points

1. **FIFO Principle**: First In First Out
2. **O(1) All Operations**: Constant time!
3. **Circular Advantage**: Reuses space with modulo
4. **BFS Connection**: Queue = level-order traversal
5. **When to Use**: Fair scheduling, buffering

---

## LeetCode Must-Do

- ⭐ **LeetCode 622**: Design Circular Queue
- **LeetCode 232**: Implement Queue using Stacks  
- **LeetCode 102**: Binary Tree Level Order (BFS)
- **LeetCode 200**: Number of Islands (BFS)

---

## Complexity Cheat Sheet

| Operation | Time | Space |
|-----------|------|-------|
| Enqueue | O(1) | - |
| Dequeue | O(1) | - |
| Peek | O(1) | - |
| isEmpty | O(1) | - |
| isFull | O(1) | - |
| **Total Space** | - | **O(n)** |

---

## Decision Tree: Which Queue?

```
Do you know max size?
├─ No → Linked Queue (dynamic)
└─ Yes → Is it long-lived?
    ├─ Yes → Circular Queue (efficient)
    └─ No → Array Queue (simple)
```

---

## Code Patterns to Memorize

### Pattern 1: BFS Template
```c
Queue* q = createQueue();
enqueue(q, startNode);

while (!isEmpty(q)) {
    Node* current = dequeue(q);
    // Process current
    
    // Add neighbors to queue
    for (each neighbor of current) {
        enqueue(q, neighbor);
    }
}
```

### Pattern 2: Level Order Traversal
```c
Queue* q = createQueue();
enqueue(q, root);

while (!isEmpty(q)) {
    int levelSize = q->size;
    
    for (int i = 0; i < levelSize; i++) {
        Node* node = dequeue(q);
        // Process node
        
        if (node->left) enqueue(q, node->left);
        if (node->right) enqueue(q, node->right);
    }
}
```

---

## Debugging Checklist

- [ ] Print: front, rear, size after each operation
- [ ] Test: empty dequeue, full enqueue
- [ ] Verify: modulo calculation correct
- [ ] Check: memory freed (linked queue)
- [ ] Confirm: rear = NULL when empty (linked)

---

## One-Minute Elevator Pitch

"Queue is a FIFO data structure with O(1) enqueue and dequeue. Three implementations: simple array (wastes space), circular queue (uses modulo to reuse space), and linked list (dynamic size). Circular queue is most common in interviews. Used everywhere: OS scheduling, BFS, networking, system design."

---

## Master These and You're Golden! 🏆

1. Implement circular queue from memory
2. Explain why circular > simple array
3. Solve LeetCode 622
4. Write BFS using queue
5. Know when to use which implementation

---

**Remember**: Queue is fundamental. Master it once, use it forever! 🚀