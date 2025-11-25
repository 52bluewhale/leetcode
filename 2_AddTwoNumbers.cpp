/**
 * LeetCode Problem 2: Add Two Numbers
 * Language: C++
 * 
 * Definition for singly-linked list.
 */

// #include <iostream.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(0), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    public:
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
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            // Dummy head to simplify list construction
            ListNode *dummyHead = new ListNode(0);
            ListNode *current = dummyHead;

            int carry = 0;      // Initialize carry to 0

            // Continue while there are digits to process or carry exists
            while (l1 != nullptr || l2 != nullptr || carry != 0)
            {
                // Get values from current nodes (0 if list is exhausted)
                int val1 = (l1 != nullptr) ? l1->val : 0;
                int val2 = (l2 != nullptr) ? l2->val : 0;

                // Calculate sum current digits
                int sum = val1 + val2 + carry;

                // Extract the digit to store (sum % 10)
                int digit = sum % 10;

                // Calculate new carry (sum / 10)
                carry = sum / 10;

                // Create new node with the digit
                current->next = new ListNode (digit);
                current = current->next;

                // Move to next nodes of they exist
                if (l1 != nullptr) l1 = l1->next;
                if (l2 != nullptr) l2 = l2->next;
            }

            // Return actual head (skip dummy)
            ListNode *result = dummyHead->next;
            delete dummyHead;

            return result;
        }
};

/**
 * Helper class for testing and utility functions
 */
class ListHelper
{
    public:
        /**
         * Creates a linked list from a vector of integers
         * @param values: Vector containing node values
         * @return: Pointer to head of created list
         */
        static ListNode *createList(const std::vector<int> &values)
        {
            if (values.empty()) return nullptr;

            ListNode *head = new ListNode(values[0]);
            ListNode *current = head;

            for (size_t i = 1; i < values.size(); i++)
            {
                current->next = new ListNode(values[i]);
                current = current->next;
            }

            return head;
        }

        /**
         * Prints a linked list
         * @param head: Pointer to the head of the list
         */
        static void printList(ListNode *head)
        {
            while (head != nullptr)
            {
                std::cout << head->val;
                if (head->next != nullptr) std::cout << " -> ";
                head = head->next;
            }
            std::cout << std::endl;
        }

        /**
         * Frees memory allocated for linked list
         * @param head: Pointer to the head of the list
         */
        static void freeList(ListNode *head)
        {
            while (head != nullptr)
            {
                ListNode *temp = head;
                head = head->next;
                delete temp;
            }
        }

        /**
         * Converts linked list to integer (for verification)
         * @param head: Pointer to the head of the list
         * @return: Integer representation of the number
         */
        static long long listToNumber(ListNode *head)
        {
            long long number = 0;
            long long multiplier = 1;

            while (head != nullptr)
            {
                number += head->val * multiplier;
                multiplier *= 10;
                head = head->next;
            }

            return number;
        }
};

