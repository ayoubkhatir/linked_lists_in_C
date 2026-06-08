#include "linkedlist.h"

int main() {
  int k = 1, size, value, i, index, newValue, oldValue;
  Node *ptr = NULL;
  Node *other = NULL;

  while (k != 0) {
    printf("\n========== MENU ==========\n");
    printf("  0. Exit\n");
    printf("  --- Basic ---\n");
    printf("  1. Create Node\n");
    printf("  2. Print List\n");
    printf("  3. Insert Front\n");
    printf("  4. Insert Back\n");
    printf("  5. List Size\n");
    printf("  6. Empty List Check\n");
    printf("  7. Search value\n");
    printf("  8. Get value at index\n");
    printf("  --- Delete ---\n");
    printf("  9. Delete first\n");
    printf(" 10. Delete last\n");
    printf(" 11. Delete by value\n");
    printf(" 12. Delete by index\n");
    printf(" 13. Clear list\n");
    printf("  --- Update ---\n");
    printf(" 14. Update value at index\n");
    printf(" 15. Replace value\n");
    printf(" 16. Swap two nodes\n");
    printf(" 17. Reverse list\n");
    printf("  --- Statistics ---\n");
    printf(" 18. Find maximum\n");
    printf(" 19. Find minimum\n");
    printf(" 20. Calculate sum\n");
    printf(" 21. Calculate average\n");
    printf(" 22. Count occurrences\n");
    printf("  --- Advanced ---\n");
    printf(" 23. Find middle\n");
    printf(" 24. Find nth from end\n");
    printf(" 25. Find last node\n");
    printf(" 26. Detect loop\n");
    printf("  --- Sort / Merge ---\n");
    printf(" 27. Sort ascending\n");
    printf(" 28. Sort descending\n");
    printf(" 29. Insert sorted\n");
    printf(" 30. Remove duplicates\n");
    printf(" 31. Merge with another list\n");
    printf("  --- Copy ---\n");
    printf(" 32. Deep copy\n");
    printf(" 33. Clone list\n");
    printf("Enter your choice: ");
    scanf("%d", &k);

    switch (k) {
    case 0:
      break;

    case 1:
      printf("enter the desired value : ");
      scanf("%d", &value);
      ptr = createNode(value);
      break;

    case 2:
      printList(ptr);
      break;

    case 3:
      printf("enter the desired value : ");
      scanf("%d", &value);
      insertFirst(&ptr, value);
      break;

    case 4:
      printf("enter the desired value : ");
      scanf("%d", &value);
      insertLast(&ptr, value);
      break;

    case 5:
      size = listSize(ptr);
      printf("the list size is : %d\n", size);
      break;

    case 6:
      isEmpty(ptr) ? printf("the list is empty\n")
                   : printf("the list is not empty\n");
      break;

    case 7:
      printf("enter the desired value for search : ");
      scanf("%d", &value);
      i = search(ptr, value);
      i == -1 ? printf("the value doesn't exist or the list is empty\n")
              : printf("the value exists at index : %d\n", i);
      break;

    case 8:
      printf("enter the desired node index (1-based): ");
      scanf("%d", &i);
      value = getValueAt(ptr, i);
      printf("the value at node %d is : %d\n", i, value);
      break;

    case 9:
      deleteFirst(&ptr);
      break;

    case 10:
      deleteLast(&ptr);
      break;

    case 11:
      printf("enter the value to delete : ");
      scanf("%d", &value);
      deleteByValue(&ptr, value);
      break;

    case 12:
      printf("enter the index to delete (1-based): ");
      scanf("%d", &i);
      deleteByIndex(&ptr, i);
      break;

    case 13:
      clearList(&ptr);
      printf("list cleared\n");
      break;

    case 14:
      printf("enter the index (1-based) : ");
      scanf("%d", &index);
      printf("enter the new value : ");
      scanf("%d", &newValue);
      updateValueAt(ptr, index, newValue);
      break;

    case 15:
      printf("enter the old value : ");
      scanf("%d", &oldValue);
      printf("enter the new value : ");
      scanf("%d", &newValue);
      i = replaceValue(ptr, oldValue, newValue);
      if (i == -1) printf("value not found\n");
      else         printf("replaced 1 occurrence\n");
      break;

    case 16:
      printf("enter first index (1-based): ");
      scanf("%d", &i);
      printf("enter second index (1-based): ");
      scanf("%d", &index);
      swapNodes(&ptr, i, index);
      break;

    case 17:
      reverseList(&ptr);
      printf("list reversed\n");
      break;

    case 18: {
      int mx = findMax(ptr);
      if (mx != INT_MIN) printf("maximum value is : %d\n", mx);
      break;
    }

    case 19: {
      int mn = findMin(ptr);
      if (mn != INT_MAX) printf("minimum value is : %d\n", mn);
      break;
    }

    case 20: {
      long s = calculateSum(ptr);
      printf("sum of all values is : %ld\n", s);
      break;
    }

    case 21: {
      double avg = calculateAverage(ptr);
      printf("average of all values is : %.2f\n", avg);
      break;
    }

    case 22:
      printf("enter the value to count : ");
      scanf("%d", &value);
      printf("occurrences : %d\n", countOccurrences(ptr, value));
      break;

    case 23:
      value = findMiddle(ptr);
      printf("middle node value is : %d\n", value);
      break;

    case 24:
      printf("enter n (1-based from end): ");
      scanf("%d", &i);
      value = findNthFromEnd(ptr, i);
      printf("the %dth node from end is : %d\n", i, value);
      break;

    case 25: {
      Node *last = findLast(ptr);
      if (last) printf("last node value is : %d\n", last->data);
      break;
    }

    case 26:
      detectLoop(ptr) ? printf("loop detected\n")
                      : printf("no loop detected\n");
      break;

    case 27:
      sortAscending(&ptr);
      printf("list sorted ascending\n");
      break;

    case 28:
      sortDescending(&ptr);
      printf("list sorted descending\n");
      break;

    case 29:
      printf("enter value to insert in sorted order : ");
      scanf("%d", &value);
      insertSorted(&ptr, value);
      break;

    case 30:
      removeDuplicates(&ptr);
      printf("duplicates removed\n");
      break;

    case 31:
      printf("building a second list with values 10,20,30...\n");
      other = NULL;
      insertLast(&other, 10);
      insertLast(&other, 20);
      insertLast(&other, 30);
      printf("second list: ");
      printList(other);
      ptr = mergeSortedLists(ptr, other);
      printf("merged result: ");
      printList(ptr);
      break;

    case 32:
      destroyList(&ptr);
      ptr = deepCopy(ptr);
      printf("deep copy done\n");
      break;

    case 33: {
      Node *cloned = cloneList(ptr);
      printf("clone: ");
      printList(cloned);
      freeList(&cloned);
      break;
    }

    default:
      printf("enter a valid operation number !\n");
      break;
    }
  }
  freeList(&ptr);
  return 0;
}
