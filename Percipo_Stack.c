/*
 * Valid Parentheses - C Implementation with Stack from Scratch
 * LeetCode Problem #20
 * 
 * This implementation builds a Stack data structure from scratch using arrays
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE                10000

/*
 * Stack Structure Definition
 * - data: Array to store stack elements
 * - top: Index of the top element (-1 means empty stack)
 */
typedef struct 
{
    char data[MAX_SIZE];
    int top;
} Stack;

/*
 * Initialize a new stack
 * Sets top to -1 to indicate empty stack
 */
void initStack(Stack *s)
{
    s->top = -1;
}

/*
 * Check if stack is empty
 * Returns true if top is -1
 */
bool isEmpty(Stack *s)
{
    return s->top == -1;
}

/*
 * Check if stack is full
 * Returns true if top reaches MAX_SIZE - 1
 */
bool isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

// Peek at top element without removing it
char peek(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->data[s->top];
    }

    return '\0';
}
// Get current size of stack
int getSize(Stack *s)
{
    return s->top + 1;
}

// Print stack contents for debugging
void displayStack(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty \n");
        return;
    }

    printf("Stack: ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%c ", s->data[i]);
    }
    printf("\n");
}

/**
 * PUSH (LECTURE NOTES)
 *
 * IDEA / INTUITION:
 * - Push adds a new element to the top of the stack (LIFO: Last-In-First-Out).
 *   The top pointer increments to the next free position, and the element is
 *   stored there.
 *
 * ALGORITHM:
 * 1. Check if stack is full. If full, cannot push (handle gracefully).
 * 2. Increment top pointer: top++.
 * 3. Store the character at s->data[top].
 *
 * COMPLEXITY:
 * - Time: O(1) — single assignment and pointer increment.
 * - Space: O(1) — no extra memory beyond the stack itself.
 *
 * WORKED EXAMPLE:
 * - Stack state: [_, _, _], top = -1 (empty)
 * - push(stack, 'A'): top becomes 0, data[0] = 'A' → ['A', _, _], top = 0
 * - push(stack, 'B'): top becomes 1, data[1] = 'B' → ['A', 'B', _], top = 1
 * - push(stack, 'C'): top becomes 2, data[2] = 'C' → ['A', 'B', 'C'], top = 2
 *
 * @param s: pointer to the stack structure
 * @param c: character to push onto the stack
 */
void push(Stack *s, char c)
{
    if (!isFull(s))
    {
        s->data[++(s->top)] = c;
    }
}

/**
 * POP (LECTURE NOTES)
 *
 * IDEA / INTUITION:
 * - Pop removes and returns the element at the top of the stack. The top
 *   pointer decrements, effectively removing the element from the stack.
 *   LIFO principle: the most recently added element is removed first.
 *
 * ALGORITHM:
 * 1. Check if stack is empty. If empty, return sentinel value (\0).
 * 2. Retrieve the element at s->data[top].
 * 3. Decrement top pointer: top--.
 * 4. Return the retrieved element.
 *
 * COMPLEXITY:
 * - Time: O(1) — single retrieval and pointer decrement.
 * - Space: O(1) — no extra memory.
 *
 * WORKED EXAMPLE:
 * - Stack state: ['A', 'B', 'C'], top = 2
 * - pop(stack): return data[2]='C', top becomes 1 → ['A', 'B', _], top = 1
 * - pop(stack): return data[1]='B', top becomes 0 → ['A', _, _], top = 0
 * - pop(stack): return data[0]='A', top becomes -1 → [_, _, _], top = -1
 * - pop(stack): stack is empty, return '\0'
 *
 * @param s: pointer to the stack structure
 * @return: character removed from top; '\0' if stack is empty
 */
char pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->data[(s->top)--];
    }

    return '\0';
}

// Check if two brackets are matching pairs
bool isMatchingPair(char opening, char closing)
{
    return  (opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']');
}

/**
 * ISVALID (LECTURE NOTES - Bracket Matching Application)
 *
 * IDEA / INTUITION:
 * - Use a stack to validate matching brackets. For each opening bracket, push
 *   it onto the stack. For each closing bracket, pop from the stack and check
 *   if it matches. If any mismatch or stack is non-empty at end, invalid.
 *
 * ALGORITHM:
 * 1. Initialize an empty stack.
 * 2. For each character in the string:
 *    a. If opening bracket ('(', '{', '['), push to stack.
 *    b. If closing bracket (')', '}', ']'):
 *       - If stack is empty, return false (no matching opening).
 *       - Pop from stack and check if it matches current closing bracket.
 *       - If no match, return false.
 * 3. After loop, return true only if stack is empty (all brackets matched).
 *
 * COMPLEXITY:
 * - Time: O(n) where n is the length of the string (single pass).
 * - Space: O(n) in worst case (all opening brackets → stack fills to n/2).
 *
 * WORKED EXAMPLE 1 - Valid: "({[]})"
 *   i=0: '(' → push '(' → stack=['('], top=0
 *   i=1: '{' → push '{' → stack=['(', '{'], top=1
 *   i=2: '[' → push '[' → stack=['(', '{', '['], top=2
 *   i=3: ']' → pop '[', match ']' ✓ → stack=['(', '{'], top=1
 *   i=4: '}' → pop '{', match '}' ✓ → stack=['('], top=0
 *   i=5: ')' → pop '(', match ')' ✓ → stack=[], top=-1
 *   End: stack empty → return true ✓
 *
 * WORKED EXAMPLE 2 - Invalid mismatch: "(]"
 *   i=0: '(' → push '(' → stack=['('], top=0
 *   i=1: ']' → pop '(', '(' doesn't match ']' → return false ✗
 *
 * WORKED EXAMPLE 3 - Invalid no opening: ")"
 *   i=0: ')' → stack is empty, no opening bracket → return false ✗
 *
 * @param s: pointer to the string containing brackets
 * @return: true if all brackets are properly matched; false otherwise
 */
bool isValid(char *s)
{
    Stack stack;
    initStack(&stack);

    int len = strlen(s);

    // Iterate through each character in the string
    for (int i = 0; i < len; i++)
    {
        char current = s[i];

        // If opening bracket, push to stack
        if (current == '(' || current == '{' || current == '[')
        {
            push(&stack, current);
        }
        // If closing bracket
        else if (current == ')' || current == '}' || current == ']')
        {
            // If stack is empty, no matching opening bracket
            if (isEmpty(&stack))
            {
                return false;
            }

            // Pop the top and check if it matches
            char top = pop(&stack);
            if(!isMatchingPair(top, current))
            {
                return false;
            }
        }
    }

    // Valid only if stack is empty (all brackets matched)
    return isEmpty(&stack);
}

// Main function to test the solution
int main() {
    // Test cases
    char* testCases[] = {
        "()",           // true
        "()[]{}",       // true
        "{[]}",         // true
        "(]",           // false
        "([)]",         // false
        "]",            // false
        "",             // true
        "((()))",       // true
        "({[()]})"      // true
    };
    
    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    printf("Valid Parentheses Test Results:\n");
    printf("================================\n\n");
    
    for (int i = 0; i < numTests; i++) {
        bool result = isValid(testCases[i]);
        printf("Input: \"%s\"\n", testCases[i]);
        printf("Output: %s\n\n", result ? "true" : "false");
    }
    
    return 0;
}