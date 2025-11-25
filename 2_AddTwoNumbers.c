/**
 * LeetCode Problem 2: Add Two Numbers
 * Language: C
 * 
 * Definition for singly-linked list.
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

/**
 * Creates a new ListNode with given value
 * @param val: The integer value to store in the node
 * @return: Pointer to newly created node
 */
struct ListNode *createNode(int val)
{
    struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    
    return node;
}

/**
 * Adds two numbers represented as linked lists in reverse order
 * 
 * Algorithm:
 * 1. Traverse both lists simultaneously
 * 2. Add corresponding digits along with carry
 * 3. Create new node for each sum digit
 * 4. Handle remaining digits and final carry
 * 
 * @param l1: First linked list (least significant digit first)
 * @param l2: Second linked list (least significant digit first)
 * @return: New linked list representing the sum
 * 
 * Time Complexity: O(max(m, n)) where m, n are lengths of l1, l2
 * Space Complexity: O(max(m, n)) for the result list
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    // Dummy head to simplify list construction
    struct ListNode *dummyHead = createNode(0);
    struct ListNode *current = dummyHead;

    // Initialize carry to 0
    int carry = 0;

    // Continue while there are digits to process or carry exists
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        // Get values from current node (0 if list is exhausted)
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;

        // Calculate sum of current digits and carry 
        int sum = val1 + val2 + carry;

        // Extract the digit to store (sum%10)
        int digit = sum % 10;

        // Calculate new carry (sum/10)
        carry = sum / 10;

        // Create new node with the digit
        current->next = createNode(digit);
        current = current->next;

        // Move to next nodes if they exist 
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    // Return the actual head (skip dummy)
    struct ListNode *result = dummyHead->next;
    free(dummyHead);

    return result;
}

/**
 * Helper function to print a linked list
 * @param head: Pointer to the head of the list
 */
void printList(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("%d", head->val);
        if(head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

/**
 * Helper function to free the linked list
 * @param head: Pointer to the head of the list
 */
void freeList(struct ListNode *head)
{
    struct ListNode *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/**
 * Example usage and test cases
 */
int main(void)
{
    // Test Case 1: [2,4,3] + [5,6,4] = [7,0,8]
    struct ListNode *l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode (3);

    struct ListNode *l2 = createNode(5);
    l1->next = createNode(6);
    l1->next->next = createNode (4);

    printf("==============Test case 1==============\n");
    printf("l1: ");
    printList(l1);
    printf("l2: ");
    printList(l2);

    struct ListNode *result = addTwoNumbers(l1, l2);
    printf("SUM: ");
    printList(result);
    printf("(342 + 465 = 807)\n\n");

    freeList(l1);
    freeList(l2);
    freeList(result);

    // Test Case 2: [9,9,9] + [1] = [0,0,0,1]
    l1 = createNode(9);
    l1->next = createNode(9);
    l1->next->next = createNode (9);

    l2 = createNode(1);
    
    printf("==============Test case 2==============\n");
    printf("l1: ");
    printList(l1);
    printf("l2: ");
    printList(l2);

    result = addTwoNumbers(l1, l2);
    printf("SUM: ");
    printList(result);
    printf("(999 + 1 = 1000)\n\n");

    freeList(l1);
    freeList(l2);
    freeList(result);
}