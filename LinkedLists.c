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
// ============================================================
// Basic operations
// ============================================================

Node *createNode(int value) {
  Node *ptr = malloc(sizeof(*ptr));
  if (ptr == NULL) {
    printf("memory allocation failed !");
    return NULL;
  }
  ptr->data = value;
  ptr->next = NULL;
  return ptr;
}

void printList(Node *ptr) {
  if (ptr == NULL) {
    printf("the list is empty\n");
    return;
  }
  int index = 0;
  while (ptr != NULL) {
    printf("[%d] %d\n", index, ptr->data);
    ptr = ptr->next;
    index++;
  }
}

void insertFirst(Node **pptr, int value) {
  Node *p = createNode(value);
  if (p != NULL) {
    p->next = *pptr;
    *pptr = p;
  }
}

void insertLast(Node **pptr, int value) {
  if (*pptr == NULL) {
    *pptr = createNode(value);
  } else {
    Node *current = *pptr;
    while (current->next != NULL) {
      current = current->next;
    }
    Node *p = createNode(value);
    if (p != NULL) {
      current->next = p;
    }
  }
}

int listSize(Node *ptr) {
  int size = 0;
  while (ptr != NULL) {
    size++;
    ptr = ptr->next;
  }
  return size;
}

bool isEmpty(Node *ptr) { return ptr == NULL; }

void freeList(Node **pptr) {
  Node *current = *pptr;
  while (current != NULL) {
    Node *next = current->next;
    free(current);
    current = next;
  }
  *pptr = NULL;
}

int search(Node *ptr, int value) {
  int i = 0;
  while (ptr != NULL) {
    if (ptr->data == value) {
      return i;
    }
    i++;
    ptr = ptr->next;
  }
  return -1;
}

int getValueAt(Node *ptr, int index) {
  if (index <= 0) {
    printf("invalid index (use 1-based indexing)\n");
    return -1;
  }
  int count = 1;
  while (ptr != NULL) {
    if (count == index) {
      return ptr->data;
    }
    ptr = ptr->next;
    count++;
  }
  printf("index out of range\n");
  return -1;
}

// ============================================================
// Delete operations
// ============================================================

void deleteFirst(Node **pptr) {
  if (*pptr == NULL) {
    printf("list is empty, nothing to delete\n");
    return;
  }
  Node *toDelete = *pptr;
  *pptr = toDelete->next;
  free(toDelete);
}

void deleteLast(Node **pptr) {
  if (*pptr == NULL) {
    printf("list is empty, nothing to delete\n");
    return;
  }
  if ((*pptr)->next == NULL) {
    free(*pptr);
    *pptr = NULL;
    return;
  }
  Node *current = *pptr;
  while (current->next->next != NULL) {
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
}

void deleteByValue(Node **pptr, int value) {
  if (*pptr == NULL) {
    printf("list is empty\n");
    return;
  }
  if ((*pptr)->data == value) {
    Node *toDelete = *pptr;
    *pptr = (*pptr)->next;
    free(toDelete);
    return;
  }
  Node *current = *pptr;
  while (current->next != NULL && current->next->data != value) {
    current = current->next;
  }
  if (current->next == NULL) {
    printf("value %d not found\n", value);
    return;
  }
  Node *toDelete = current->next;
  current->next = toDelete->next;
  free(toDelete);
}

void deleteByIndex(Node **pptr, int index) {
  if (*pptr == NULL) {
    printf("list is empty\n");
    return;
  }
  if (index <= 0) {
    printf("invalid index (use 1-based indexing)\n");
    return;
  }
  if (index == 1) {
    Node *toDelete = *pptr;
    *pptr = (*pptr)->next;
    free(toDelete);
    return;
  }
  Node *current = *pptr;
  int count = 1;
  while (current->next != NULL && count < index - 1) {
    current = current->next;
    count++;
  }
  if (current->next == NULL) {
    printf("index out of range\n");
    return;
  }
  Node *toDelete = current->next;
  current->next = toDelete->next;
  free(toDelete);
}

void clearList(Node **pptr) {
  freeList(pptr);
}

// ============================================================
// Update / Mutation
// ============================================================

void updateValueAt(Node *ptr, int index, int newValue) {
  if (index <= 0) {
    printf("invalid index (use 1-based indexing)\n");
    return;
  }
  int count = 1;
  while (ptr != NULL && count < index) {
    ptr = ptr->next;
    count++;
  }
  if (ptr == NULL) {
    printf("index out of range\n");
    return;
  }
  ptr->data = newValue;
}

int replaceValue(Node *ptr, int oldValue, int newValue) {
  while (ptr != NULL) {
    if (ptr->data == oldValue) {
      ptr->data = newValue;
      return 1;
    }
    ptr = ptr->next;
  }
  return -1;
}

void swapNodes(Node **pptr, int index1, int index2) {
  if (*pptr == NULL || index1 <= 0 || index2 <= 0 || index1 == index2) return;

  if (index1 > index2) {
    int tmp = index1; index1 = index2; index2 = tmp;
  }

  Node *prev1 = NULL, *node1 = *pptr;
  int count = 1;
  while (node1 != NULL && count < index1) {
    prev1 = node1;
    node1 = node1->next;
    count++;
  }

  Node *prev2 = NULL, *node2 = *pptr;
  count = 1;
  while (node2 != NULL && count < index2) {
    prev2 = node2;
    node2 = node2->next;
    count++;
  }

  if (node1 == NULL || node2 == NULL) {
    printf("index out of range\n");
    return;
  }

  if (prev1 != NULL) prev1->next = node2;
  else               *pptr = node2;

  if (prev2 != NULL) prev2->next = node1;
  else               *pptr = node1;

  Node *temp = node1->next;
  node1->next = node2->next;
  node2->next = temp;
}

void reverseList(Node **pptr) {
  Node *prev = NULL;
  Node *current = *pptr;
  Node *next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *pptr = prev;
}

// ============================================================
// Statistics
// ============================================================

int findMax(Node *ptr) {
  if (ptr == NULL) {
    printf("list is empty\n");
    return INT_MIN;
  }
  int mx = ptr->data;
  while (ptr != NULL) {
    if (ptr->data > mx) mx = ptr->data;
    ptr = ptr->next;
  }
  return mx;
}

int findMin(Node *ptr) {
  if (ptr == NULL) {
    printf("list is empty\n");
    return INT_MAX;
  }
  int mn = ptr->data;
  while (ptr != NULL) {
    if (ptr->data < mn) mn = ptr->data;
    ptr = ptr->next;
  }
  return mn;
}

long calculateSum(Node *ptr) {
  long sum = 0;
  while (ptr != NULL) {
    sum += ptr->data;
    ptr = ptr->next;
  }
  return sum;
}

double calculateAverage(Node *ptr) {
  long sum = calculateSum(ptr);
  int size = listSize(ptr);
  if (size == 0) return 0.0;
  return (double)sum / size;
}

int countOccurrences(Node *ptr, int value) {
  int count = 0;
  while (ptr != NULL) {
    if (ptr->data == value) count++;
    ptr = ptr->next;
  }
  return count;
}

// ============================================================
// Advanced queries
// ============================================================

int findMiddle(Node *ptr) {
  if (ptr == NULL) {
    printf("list is empty\n");
    return -1;
  }
  Node *slow = ptr;
  Node *fast = ptr;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}

int findNthFromEnd(Node *ptr, int n) {
  if (ptr == NULL || n <= 0) {
    printf("invalid input\n");
    return -1;
  }
  Node *main = ptr;
  Node *ref = ptr;
  int count = 0;
  while (count < n) {
    if (ref == NULL) {
      printf("n is larger than list size\n");
      return -1;
    }
    ref = ref->next;
    count++;
  }
  while (ref != NULL) {
    main = main->next;
    ref = ref->next;
  }
  return main->data;
}

Node *findLast(Node *ptr) {
  if (ptr == NULL) return NULL;
  while (ptr->next != NULL) ptr = ptr->next;
  return ptr;
}

bool detectLoop(Node *ptr) {
  Node *slow = ptr;
  Node *fast = ptr;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true;
  }
  return false;
}

// ============================================================
// Sorting & merging
// ============================================================

static void swapData(Node *a, Node *b) {
  int temp = a->data;
  a->data = b->data;
  b->data = temp;
}

void sortAscending(Node **pptr) {
  if (*pptr == NULL) return;
  int swapped;
  Node *curr;
  Node *last = NULL;
  do {
    swapped = 0;
    curr = *pptr;
    while (curr->next != last) {
      if (curr->data > curr->next->data) {
        swapData(curr, curr->next);
        swapped = 1;
      }
      curr = curr->next;
    }
    last = curr;
  } while (swapped);
}

void sortDescending(Node **pptr) {
  if (*pptr == NULL) return;
  int swapped;
  Node *curr;
  Node *last = NULL;
  do {
    swapped = 0;
    curr = *pptr;
    while (curr->next != last) {
      if (curr->data < curr->next->data) {
        swapData(curr, curr->next);
        swapped = 1;
      }
      curr = curr->next;
    }
    last = curr;
  } while (swapped);
}

void insertSorted(Node **pptr, int value) {
  Node *newNode = createNode(value);
  if (newNode == NULL) return;

  if (*pptr == NULL || (*pptr)->data >= value) {
    newNode->next = *pptr;
    *pptr = newNode;
    return;
  }

  Node *current = *pptr;
  while (current->next != NULL && current->next->data < value) {
    current = current->next;
  }
  newNode->next = current->next;
  current->next = newNode;
}

void removeDuplicates(Node **pptr) {
  Node *current = *pptr;
  while (current != NULL && current->next != NULL) {
    if (current->data == current->next->data) {
      Node *toDelete = current->next;
      current->next = toDelete->next;
      free(toDelete);
    } else {
      current = current->next;
    }
  }
}

Node *mergeSortedLists(Node *a, Node *b) {
  Node dummy;
  Node *tail = &dummy;
  dummy.next = NULL;

  while (a != NULL && b != NULL) {
    if (a->data <= b->data) {
      tail->next = a;
      a = a->next;
    } else {
      tail->next = b;
      b = b->next;
    }
    tail = tail->next;
  }
  tail->next = (a != NULL) ? a : b;
  return dummy.next;
}

// ============================================================
// Copy / lifetime
// ============================================================

void destroyList(Node **pptr) {
  freeList(pptr);
}

Node *deepCopy(Node *ptr) {
  if (ptr == NULL) return NULL;
  Node *newHead = createNode(ptr->data);
  if (newHead == NULL) return NULL;
  Node *newCurr = newHead;
  ptr = ptr->next;
  while (ptr != NULL) {
    Node *newNode = createNode(ptr->data);
    if (newNode == NULL) {
      freeList(&newHead);
      return NULL;
    }
    newCurr->next = newNode;
    newCurr = newNode;
    ptr = ptr->next;
  }
  return newHead;
}

Node *cloneList(Node *ptr) {
  return deepCopy(ptr);
}
