#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ============================================
// SIMPLE ARRAY-BASED QUEUE IMPLEMENTATION
// ============================================

#define MAX_SIZE                100

typedef struct 
{
    int items[MAX_SIZE];
    int front;
    int rear;
    int size;
} ArrayQueue;

/**
 * Initialize an empty array-based queue
 * Sets front to 0, rear to -1, and size to 0
 */
void initArrayQueue(ArrayQueue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

/**
 * Check if array queue is empty
 * Returns true if size is 0
 */
bool isArrayQueueEmpty(ArrayQueue *q)
{
    return q->size == 0;
}

/**
 * Check if array queue is full
 * Returns true if size equals MAX_SIZE
 */
bool isArrayQueueFull(ArrayQueue *q)
{
    return q->size == MAX_SIZE;
}

/**
 * ENQUEUE ARRAY (LECTURE NOTES)
 *
 * IDEA / INTUITION:
 * - Enqueue adds an element to the rear (back) of the queue following FIFO
 *   (First-In-First-Out). Increment rear pointer and store the value.
 *
 * ALGORITHM:
 * 1. Check if queue is full. If full, print overflow error and return false.
 * 2. Increment rear pointer: rear++.
 * 3. Store value at items[rear].
 * 4. Increment size.
 * 5. Return true on success.
 *
 * COMPLEXITY:
 * - Time: O(1) — single assignment and pointer increment.
 * - Space: O(1) — no extra memory.
 *
 * WORKED EXAMPLE:
 * - Initial: front=0, rear=-1, size=0, items=[]
 * - enqueue(10): rear becomes 0, items[0]=10 → front=0, rear=0, size=1
 * - enqueue(20): rear becomes 1, items[1]=20 → front=0, rear=1, size=2
 * - enqueue(30): rear becomes 2, items[2]=30 → front=0, rear=2, size=3
 * - Queue state: items=[10, 20, 30], front=0, rear=2, size=3
 *
 * LIMITATION:
 * - Simple array queue doesn't reuse dequeued space; front only advances.
 * - After many dequeues, wasted space builds up (use circular queue to fix).
 *
 * @param q: pointer to the array queue
 * @param value: integer to enqueue
 * @return: true if successful; false if queue is full
 */
bool enqueueArray(ArrayQueue *q, int value)
{
    if (isArrayQueueFull(q))
    {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return false;
    }

    q->rear++;
    q->items[q->rear] = value;
    q->size++;
    
    return true;
}

/**
 * DEQUEUE ARRAY (LECTURE NOTES)
 *
 * IDEA / INTUITION:
 * - Dequeue removes and returns the element at the front (FIFO principle).
 *   Increment front pointer to skip dequeued element. Size decreases.
 *
 * ALGORITHM:
 * 1. Check if queue is empty. If empty, print error and return -1.
 * 2. Retrieve value at items[front].
 * 3. Increment front pointer: front++.
 * 4. Decrement size.
 * 5. Return the retrieved value.
 *
 * COMPLEXITY:
 * - Time: O(1) — single retrieval and pointer increment.
 * - Space: O(1) — no extra memory.
 *
 * WORKED EXAMPLE (continuing from enqueue):
 * - Queue before: items=[10, 20, 30], front=0, rear=2, size=3
 * - dequeue(): return items[0]=10, front becomes 1, size becomes 2
 *   → items=[10, 20, 30], front=1, rear=2, size=2 (10 is logically removed)
 * - dequeue(): return items[1]=20, front becomes 2, size becomes 1
 *   → items=[10, 20, 30], front=2, rear=2, size=1 (20 is logically removed)
 * - Queue now contains only 30 (at items[2])
 * - Note: items[0] and items[1] are wasted space; not reused until new enqueues
 *
 * @param q: pointer to the array queue
 * @return: the dequeued integer; -1 if queue is empty
 */
int dequeueArray(ArrayQueue *q)
{
    if (isArrayQueueEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }

    int value = q->items[q->front];
    q->front++;
    q->size--;

    return value;
}

/**
 * Get front element without removing it
 * Time Complexity: O(1)
 */
int peekArray(ArrayQueue *q)
{
    if (isArrayQueueEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }

    return q->items[q->front];
}

/**
 * Display all elements in array queue
 */
void displayArrayQueue(ArrayQueue *q)
{
    if (isArrayQueueEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: [");
    for (int i = 0; i <= q->rear; i++)
    {
        printf("%d", q->items[i]);
        if (i < q->rear) printf(", ");
    }
    printf("]\n");
}

// ============================================
// CIRCULAR QUEUE IMPLEMENTATION
// ============================================

typedef struct 
{
    int items[MAX_SIZE];
    int front;
    int rear;
    int size;
    int capacity;
} CircularQueue;

/**
 * Initialize an empty circular queue
 * front and rear are set to -1 initially
 */
void initCircularQueue(CircularQueue *q, int capacity)
{
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    q->capacity = capacity;
}

/**
 * Check if circular queue is empty
 */
bool isCircularQueueEmpty(CircularQueue *q)
{
    return q->size == 0;
}

/**
 * Check if circular queue is full
 */
bool isCircularQueueFull(CircularQueue *q)
{
    return q->size == q->capacity;
}

/**
 * ENQUEUE CIRCULAR (LECTURE NOTES)
 *
 * IDEA / INTUITION:
 * - Circular queue wraps around using modulo arithmetic, reusing dequeued space.
 * - Treat the array as circular: after the last position, wrap to position 0.
 * - Enables space efficiency when front and rear can "overlap" circularly.
 *
 * ALGORITHM:
 * 1. If queue is empty (first element), set front=0.
 * 2. Compute rear = (rear + 1) % capacity (wrap around).
 * 3. Store value at items[rear].
 * 4. Increment size.
 * 5. Return true.
 *
 * COMPLEXITY:
 * - Time: O(1) — single assignment and modulo operation.
 * - Space: O(1) — no extra memory.
 *
 * WORKED EXAMPLE:
 * - Initial: front=-1, rear=-1, size=0, capacity=5
 * - enqueue(10): front=0, rear=(−1+1)%5=0, items[0]=10 → [10,_,_,_,_], size=1
 * - enqueue(20): rear=(0+1)%5=1, items[1]=20 → [10,20,_,_,_], size=2
 * - enqueue(30): rear=(1+1)%5=2, items[2]=30 → [10,20,30,_,_], size=3
 * - enqueue(40): rear=(2+1)%5=3, items[3]=40 → [10,20,30,40,_], size=4
 * - enqueue(50): rear=(3+1)%5=4, items[4]=50 → [10,20,30,40,50], size=5
 * - Queue is now FULL (size == capacity)
 * - dequeue(): return 10, front=(0+1)%5=1, size=4
 *   → [10,20,30,40,50], front=1, rear=4, size=4
 * - dequeue(): return 20, front=(1+1)%5=2, size=3
 *   → [10,20,30,40,50], front=2, rear=4, size=3
 * - Now we can reuse the circular space:
 * - enqueue(60): rear=(4+1)%5=0, items[0]=60 → [60,20,30,40,50], size=4
 *   (position 0 and 1 are now reused in the circular wrap)
 * - enqueue(70): rear=(0+1)%5=1, items[1]=70 → [60,70,30,40,50], size=5
 *
 * @param q: pointer to the circular queue
 * @param value: integer to enqueue
 * @return: true if successful; false if queue is full
 */
bool enqueueCircular(CircularQueue *q, int value)
{
    if (isCircularQueueEmpty(q))
    {
        printf("Circular Queue Overflow! Cannot enqueue %d\n", value);
        return false;
    }

    // First element case
    if (q->front == -1)
    {
        q->front = 0;
    }

    // Circular increament using module
    q->rear = (q->rear + 1) % q->capacity;
    q->items[q->rear] = value;
    q->size++;

    return true;
}

/**
 * DEQUEUE CIRCULAR (LECTURE NOTES)
 *
 * IDEA / INTUITION:
 * - Remove from front using modulo to wrap around. Handle edge case where
 *   dequeuing the last element resets front and rear to -1.
 *
 * ALGORITHM:
 * 1. Check if queue is empty. If empty, print error and return -1.
 * 2. Retrieve value at items[front].
 * 3. If this was the last element (front == rear), reset front=-1, rear=-1.
 * 4. Otherwise, compute front = (front + 1) % capacity.
 * 5. Decrement size.
 * 6. Return the retrieved value.
 *
 * COMPLEXITY:
 * - Time: O(1) — single retrieval and modulo operation.
 * - Space: O(1) — no extra memory.
 *
 * WORKED EXAMPLE (continuing from enqueue):
 * - Queue: [60, 70, 30, 40, 50], front=2, rear=1, size=5
 * - dequeue(): return items[2]=30, front=(2+1)%5=3, size=4
 *   → [60,70,30,40,50], front=3, rear=1, size=4
 * - dequeue(): return items[3]=40, front=(3+1)%5=4, size=3
 *   → [60,70,30,40,50], front=4, rear=1, size=3
 * - dequeue(): return items[4]=50, front=(4+1)%5=0, size=2
 *   → [60,70,30,40,50], front=0, rear=1, size=2
 * - dequeue(): return items[0]=60, front=(0+1)%5=1, size=1
 *   → [60,70,30,40,50], front=1, rear=1, size=1
 * - dequeue(): return items[1]=70, front==rear (both 1), reset front=-1, rear=-1, size=0
 *   → Queue is now EMPTY
 *
 * @param q: pointer to the circular queue
 * @return: the dequeued integer; -1 if queue is empty
 */
int dequeueCircular(CircularQueue *q)
{
    if (isCircularQueueEmpty(q))
    {
        printf("Circular Queue Underflow! Queue is empty\n");
        return -1;
    }

    int value = q->items[q->front];

    // Reset queue if this was the last element
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else 
    {
        // Circular increment
        q->front = (q->front + 1) % q->capacity;
    }

    q->size--;
    
    return value;
}

/**
 * Get front element of circular queue without removing it
 * Time Complexity: O(1)
 */
int peekCircular(CircularQueue *q)
{
    if (isCircularQueueEmpty(q))
    {
        printf("Circular Queue is empty\n");
        return -1;
    }

    return q->items[q->front];
}

/**
 * Display all elements in circular queue
 */
void displayCircularQueue(CircularQueue *q)
{
    if (isCircularQueueEmpty(q))
    {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Circular Queue: [");
    int i = q->front;
    int count = 0;

    while (count < q->size)
    {
        printf("%d", q->items[i]);
        if (count < q->size - 1) printf(", ");
        i = (i + 1) % q->capacity;
        count++;
    }
    printf("]\n");
}

// ============================================
// LINKED LIST-BASED QUEUE IMPLEMENTATION
// ============================================

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct 
{
    Node *front;
    Node *rear;
    int size;
} LinkedQueue;

/**
 * Initialize an empty linked list queue
 */
void initLinkedQueue(LinkedQueue *q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

/**
 * Check if linked queue is empty
 */
bool isLinkedQueueEmpty(LinkedQueue *q)
{
    return q->front == NULL;
}

/**
 * ENQUEUE LINKED (LECTURE NOTES)
 *
 * IDEA / INTUITION:
 * - Linked list queue dynamically allocates memory for each element. No size
 *   limit (until memory runs out). Add new node to rear and update rear pointer.
 *
 * ALGORITHM:
 * 1. Allocate memory for new node. If allocation fails, return false.
 * 2. Initialize newNode->data = value, newNode->next = NULL.
 * 3. If queue is empty, set front = rear = newNode.
 * 4. Otherwise, attach newNode to rear->next and update rear = newNode.
 * 5. Increment size.
 * 6. Return true.
 *
 * COMPLEXITY:
 * - Time: O(1) — single allocation and pointer updates.
 * - Space: O(1) per enqueue (but total grows with queue size).
 *
 * WORKED EXAMPLE:
 * - Initial: front=NULL, rear=NULL, size=0
 * - enqueue(10): allocate node(10), front=rear=node(10), size=1
 *   → front→[10|NULL], size=1
 * - enqueue(20): allocate node(20), rear->next=node(20), rear=node(20), size=2
 *   → front→[10|•]→[20|NULL], size=2
 * - enqueue(30): allocate node(30), rear->next=node(30), rear=node(30), size=3
 *   → front→[10|•]→[20|•]→[30|NULL], size=3
 * - enqueue(40): allocate node(40), rear->next=node(40), rear=node(40), size=4
 *   → front→[10|•]→[20|•]→[30|•]→[40|NULL], size=4
 *
 * ADVANTAGE: No size limit (unlike array/circular queue with MAX_SIZE).
 * DISADVANTAGE: Extra memory per node for pointers + potential memory fragmentation.
 *
 * @param q: pointer to the linked queue
 * @param value: integer to enqueue
 * @return: true if successful; false if memory allocation fails
 */
bool enqueueLinked(LinkedQueue *q, int value)
{
    // Create new node
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return false;
    }

    newNode->data = value;
    newNode->next = NULL;

    // If queue is emptym both front and rear point to new node
    if (isLinkedQueueEmpty(q))
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else 
    {
        // Add to rear and update rear pointer
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
    return true;
}

/**
 * DEQUEUE LINKED (LECTURE NOTES)
 *
 * IDEA / INTUITION:
 * - Remove the front node from the linked queue. Save the front value,
 *   advance front pointer, free the node, and decrement size.
 *   Handle edge case: if queue becomes empty after dequeue, rear = NULL.
 *
 * ALGORITHM:\n * 1. Check if queue is empty. If empty, return -1.
 * 2. Save pointer to front node: temp = front.
 * 3. Extract value from temp->data.
 * 4. Advance front: front = front->next.
 * 5. If new front is NULL (queue became empty), set rear = NULL.
 * 6. Free the temp node.
 * 7. Decrement size.
 * 8. Return the extracted value.
 *
 * COMPLEXITY:
 * - Time: O(1) — single pointer navigation and memory deallocation.
 * - Space: O(1) — no extra memory (deallocation frees one node).
 *
 * WORKED EXAMPLE (continuing from enqueue):
 * - Queue: front→[10|•]→[20|•]→[30|•]→[40|NULL], rear=node(40), size=4
 * - dequeue(): return 10, front=front->next (points to 20), free node(10), size=3
 *   → front→[20|•]→[30|•]→[40|NULL], rear=node(40), size=3
 * - dequeue(): return 20, front=front->next (points to 30), free node(20), size=2
 *   → front→[30|•]→[40|NULL], rear=node(40), size=2
 * - dequeue(): return 30, front=front->next (points to 40), free node(30), size=1
 *   → front→[40|NULL], rear=node(40), size=1
 * - dequeue(): return 40, front=front->next (NULL), front==NULL so rear=NULL, free node(40), size=0
 *   → front=NULL, rear=NULL, size=0 (queue is now EMPTY)
 *
 * MEMORY MANAGEMENT: Each dequeue frees one node; must call freeLinkedQueue()
 *   at the end to clean up any remaining nodes.
 *
 * @param q: pointer to the linked queue
 * @return: the dequeued integer; -1 if queue is empty
 */
int dequeueLinked(LinkedQueue *q)
{
    if (isLinkedQueueEmpty(q))
    {
        printf("Linked Queue is empty\n");
        return -1;
    }

    Node *temp = q->front;
    int value = temp->data;

    q->front = q->front->next;

    // If queue becomes empty, update rear to NULL
    if (q->front == NULL) q->rear = NULL;

    free(temp);
    q->size--;

    return value;
}

/**
 * Get front element of linked queue without removing it
 * Time Complexity: O(1)
 */
int peekLinked(LinkedQueue *q)
{
    if (isLinkedQueueEmpty(q))
    {
        printf("Linked Queue is empty\n");
        return -1;
    }

    return q->front->data;
}

/**
 * Display all elements in linked queue
 */
void displayLinkedQueue(LinkedQueue *q)
{
    if (isLinkedQueueEmpty(q))
    {
        printf("Linked Queue is empty\n");
        return;
    }

    printf("Linked Queue: [");
    Node* current = q->front;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf(", ");
        current = current->next;
    }
    printf("]\n");
}

/**
 * Free all memory used by linked queue
 */
void freeLinkedQueue(LinkedQueue *q)
{
    while (!isLinkedQueueEmpty(q))
    {
        dequeueLinked(q);
    }   
}

// ============================================
// TEST FUNCTIONS
// ============================================

/**
 * Test array-based queue implementation
 */
void testArrayQueue() {
    printf("\n========== TESTING ARRAY QUEUE ==========\n");
    ArrayQueue q;
    initArrayQueue(&q);
    
    // Test enqueue
    printf("\nEnqueuing: 10, 20, 30, 40, 50\n");
    enqueueArray(&q, 10);
    enqueueArray(&q, 20);
    enqueueArray(&q, 30);
    enqueueArray(&q, 40);
    enqueueArray(&q, 50);
    displayArrayQueue(&q);
    
    // Test peek
    printf("\nPeek front: %d\n", peekArray(&q));
    
    // Test dequeue
    printf("\nDequeuing two elements:\n");
    printf("Dequeued: %d\n", dequeueArray(&q));
    printf("Dequeued: %d\n", dequeueArray(&q));
    displayArrayQueue(&q);
    
    // Test isEmpty
    printf("\nIs queue empty? %s\n", isArrayQueueEmpty(&q) ? "Yes" : "No");
}

/**
 * Test circular queue implementation
 */
void testCircularQueue() {
    printf("\n========== TESTING CIRCULAR QUEUE ==========\n");
    CircularQueue q;
    initCircularQueue(&q, 5);
    
    // Test enqueue
    printf("\nEnqueuing: 10, 20, 30, 40, 50\n");
    enqueueCircular(&q, 10);
    enqueueCircular(&q, 20);
    enqueueCircular(&q, 30);
    enqueueCircular(&q, 40);
    enqueueCircular(&q, 50);
    displayCircularQueue(&q);
    
    // Test overflow
    printf("\nAttempting to enqueue when full:\n");
    enqueueCircular(&q, 60);
    
    // Test dequeue and circular behavior
    printf("\nDequeuing two elements:\n");
    printf("Dequeued: %d\n", dequeueCircular(&q));
    printf("Dequeued: %d\n", dequeueCircular(&q));
    displayCircularQueue(&q);
    
    // Now we can add more elements (circular reuse)
    printf("\nEnqueuing 60 and 70 (circular reuse):\n");
    enqueueCircular(&q, 60);
    enqueueCircular(&q, 70);
    displayCircularQueue(&q);
}

/**
 * Test linked list queue implementation
 */
void testLinkedQueue() {
    printf("\n========== TESTING LINKED QUEUE ==========\n");
    LinkedQueue q;
    initLinkedQueue(&q);
    
    // Test enqueue
    printf("\nEnqueuing: 10, 20, 30, 40, 50\n");
    enqueueLinked(&q, 10);
    enqueueLinked(&q, 20);
    enqueueLinked(&q, 30);
    enqueueLinked(&q, 40);
    enqueueLinked(&q, 50);
    displayLinkedQueue(&q);
    
    // Test peek
    printf("\nPeek front: %d\n", peekLinked(&q));
    printf("Queue size: %d\n", q.size);
    
    // Test dequeue
    printf("\nDequeuing three elements:\n");
    printf("Dequeued: %d\n", dequeueLinked(&q));
    printf("Dequeued: %d\n", dequeueLinked(&q));
    printf("Dequeued: %d\n", dequeueLinked(&q));
    displayLinkedQueue(&q);
    
    // Test isEmpty
    printf("\nIs queue empty? %s\n", isLinkedQueueEmpty(&q) ? "Yes" : "No");
    
    // Clean up
    freeLinkedQueue(&q);
    printf("\nMemory freed successfully\n");
}

// ============================================
// MAIN FUNCTION
// ============================================

int main() {
    printf("========================================\n");
    printf("   QUEUE IMPLEMENTATION IN C\n");
    printf("   (Array, Circular, Linked List)\n");
    printf("========================================\n");
    
    testArrayQueue();
    testCircularQueue();
    testLinkedQueue();
    
    printf("\n========================================\n");
    printf("   ALL TESTS COMPLETED SUCCESSFULLY\n");
    printf("========================================\n");
    
    return 0;
}
