#include <stdio.h>
#include <stdlib.h>

// ========================= APPROACH 1: BRUTER FORCE =========================
// Time Complexity: O(n²)
// Space Complexity: O(1)
int *twoSum_bruteforce(int *nums, int numsSize, int target, int *returnSize)
{
    // allocate memory for result array (2 indices)
    int *result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    // check every pair of elements
    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    // should never reach here based on problem constraints
    *returnSize = 0;
    free(result);
    return NULL;
}

// ========================= APPROACH 2: HASH MAP =========================
// Time Complexity: O(n)
// Space Complexity: O(n)

// hash table structure for better organization
typedef struct 
{
    int value;
    int index;
    int used;
} HashEntry;

int *twoSum_hashmap(int *nums, int numsSize, int target, int *returnSize)
{
    // create a hash table (using array for simplicity)
    // size should be larger than numsSize for better distribution
    int hashSize = numsSize * 2;
    HashEntry *hashTable = (HashEntry*)calloc(hashSize, sizeof(HashEntry));

    int *result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];

        // simple hash function (can be improved)
        int hashIndex = abs(complement) % hashSize;

        // linear probing to find the complement
        int originalIndex = hashIndex;
        while (hashTable[hashIndex].used)
        {
            if (hashTable[hashIndex].value == complement)
            {
                // found the complement
                result[0] = hashTable[hashIndex].index;
                result[1] = i;
                return result;
            }
            hashIndex = (hashIndex + 1) % hashSize;

            // prevent infinite loop
            if (hashIndex == originalIndex) break;
        }

        // store current number in hash table
        hashIndex = abs(nums[i]) % hashSize;
        while (hashTable[hashIndex].used)
        {
            hashIndex = (hashIndex +1) % hashSize;
        }
        hashTable[hashIndex].value = nums[i];
        hashTable[hashIndex].index = i;
        hashTable[hashIndex].used = 1;
    }

    // should never reach here based on problem constraints
    free(hashTable);
    free(result);
    *returnSize = 0;
    return NULL;
}

// ========================= APPROACH 3: SORTING + TWO POINTERS =========================
// Time Complexity: O(n log n)
// Space Complexity: O(n)

typedef struct 
{
    int value;
    int originalIndex;
} NumWithIndex;

int compare(const void *a, const void *b)
{
    NumWithIndex *numA = (NumWithIndex*)a;
    NumWithIndex *numB = (NumWithIndex*)b;
    return numA->value - numB->value;
}

int *twoSum_sorting(int *nums, int numsSize, int target, int *returnSize)
{
    // create array of value-index pairs
    NumWithIndex *sortedNums = (NumWithIndex*)malloc(numsSize * sizeof(NumWithIndex));

    for (int i = 0; i < numsSize; i++)
    {
        sortedNums[i].value = nums[i];
        sortedNums[i].originalIndex = i;
    }

    // sort by value
    qsort(sortedNums, numsSize, sizeof(NumWithIndex), compare);

    int *result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    // two pointers approach
    int left = 0;
    int right = numsSize - 1;

    while (left < right)
    {
        int sum = sortedNums[left].value + sortedNums[right].value;
        if (sum == target)
        {
            result[0] = sortedNums[left].originalIndex;
            result[1] = sortedNums[right].originalIndex;

            // ensure smaller index comes first
            if (result[0] > result[1])
            {
                int temp = result[0];
                result[0] = result[1];
                result[1] = temp;
            }

            free(sortedNums);
            return result;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    // should never reach here
    free(sortedNums);
    free(result);
    *returnSize = 0;
    return NULL;
}

// =================================== HELPER FUNCTION ===================================
void printArray(int *arr, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

void testTwoSum(int *nums, int numsSize, int target, const char *testName)
{
    printf("\n====== %s ======", testName);
    printf("Input: nums = ");
    printArray(nums, numsSize);
    printf("Target: %d\n", target);

    int returnSize;

    // test brute force
    int *result1 = twoSum_bruteforce(nums, numsSize, target, &returnSize);
    printf("Brute Force result: ");
    printArray(result1, returnSize);

    // test hash map
    int *result2 = twoSum_hashmap(nums, numsSize, target, &returnSize);
    printf("Hash Map result: ");
    printArray(result2, returnSize);

    // test sorting 
    int *result3 = twoSum_sorting(nums, numsSize, target, &returnSize);
    printf("Sorting result: ");
    printArray(result3, returnSize);

    // verify results
    if (result1 && nums[result1[0]] + nums[result1[1]] == target)
    {
        printf("Verification: %d + %d = %d\n", nums[result1[0]], nums[result1[1]], target);
    }

    free(result1);
    free(result2);
    free(result3);
}

// ================================ MAIN FUNCNTION ================================
int main()
{
    printf("Two Sum Problem - Multiple Approaches\n");
    printf("=====================================\n");

    // test case 1
    int nums1[] = {2, 7, 11, 15};
    testTwoSum(nums1, 4, 9, "Test case 1");

    // test case 2
    int nums2[] = {3, 2, 4};
    testTwoSum(nums2, 3, 6, "Test case 2");

    // test case 3
    int nums3[] = {3, 3};
    testTwoSum(nums3, 2, 6, "Test case 3");

    // additional test case
    int nums4[] = {-1, -2, -3, -4, -5};
    testTwoSum(nums4, 5, -8, "Test case 4");

    return 0;
}