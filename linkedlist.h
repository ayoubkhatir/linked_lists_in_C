#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef uint8_t u8;

// Basic
Node *createNode(int value);
void printList(Node *ptr);
void insertFirst(Node **pptr, int value);
void insertLast(Node **pptr, int value);
int listSize(Node *ptr);
bool isEmpty(Node *ptr);
void freeList(Node **pptr);
int search(Node *ptr, int value);
int getValueAt(Node *ptr, int index);

// Delete
void deleteFirst(Node **pptr);
void deleteLast(Node **pptr);
void deleteByValue(Node **pptr, int value);
void deleteByIndex(Node **pptr, int index);
void clearList(Node **pptr);

// Update
void updateValueAt(Node *ptr, int index, int newValue);
int  replaceValue(Node *ptr, int oldValue, int newValue);
void swapNodes(Node **pptr, int index1, int index2);
void reverseList(Node **pptr);

// Statistics
int  findMax(Node *ptr);
int  findMin(Node *ptr);
long calculateSum(Node *ptr);
double calculateAverage(Node *ptr);
int  countOccurrences(Node *ptr, int value);

// Advanced
int  findMiddle(Node *ptr);
int  findNthFromEnd(Node *ptr, int n);
Node *findLast(Node *ptr);
bool detectLoop(Node *ptr);

// Sort / merge
void sortAscending(Node **pptr);
void sortDescending(Node **pptr);
void insertSorted(Node **pptr, int value);
void removeDuplicates(Node **pptr);
Node *mergeSortedLists(Node *a, Node *b);

// Copy / lifetime
void destroyList(Node **pptr);
Node *deepCopy(Node *ptr);
Node *cloneList(Node *ptr);

#endif
