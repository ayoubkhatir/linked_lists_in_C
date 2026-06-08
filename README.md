# Linked List Library — C

A complete singly-linked list implementation with 28 operations.

## Files

| File | Purpose |
|------|---------|
| `linkedlist.h` | Header — struct definition, function prototypes |
| `LinkedLists.c` | Implementation + interactive menu |

## Operations

- **Basic**: createNode, printList, insertFirst, insertLast, listSize, isEmpty, freeList, search, getValueAt
- **Delete**: deleteFirst, deleteLast, deleteByValue, deleteByIndex, clearList
- **Update**: updateValueAt, replaceValue, swapNodes, reverseList
- **Statistics**: findMax, findMin, calculateSum, calculateAverage, countOccurrences
- **Advanced**: findMiddle, findNthFromEnd, findLast, detectLoop
- **Sort / Merge**: sortAscending, sortDescending, insertSorted, removeDuplicates, mergeSortedLists
- **Copy / Lifetime**: destroyList, deepCopy, cloneList

## Build & Run

```bash
gcc LinkedLists.c -o LinkedLists -std=c17
./LinkedLists
```
