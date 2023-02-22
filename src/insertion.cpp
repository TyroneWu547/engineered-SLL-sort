/**
 * @file insertion.cpp
 * @author Andrew Sauerbrei
 *         AJ Bulthuis
 *         Tyrone Wu
 * @brief The insertion sort implementation using the iterative approach. 
 * 
 */

#include <iostream>
#include "../include/Sort.h"
#include "../include/LinkedList.h"

/**
 * @brief Inserts the node to sort into the sorted portion of the list.
 * 
 * @param list the list the node is inserting into
 * @param nodeToSort the node to insert into the sorted portion
 */
void insertIntoSorted(LinkedList* list, Node* nodeToSort) {
    // First check if the nodeToSort should be inserted into the front of the sorted portion
    if (*nodeToSort <= *(list->head)) {
        // Inserted node at the front
        nodeToSort->next = list->head;
        list->head = nodeToSort;
    } else {
        // Cursor that tracks where the nodeToSort should be inserted
        Node* cursor = list->head;

        // Iterate cursor (from head of the sorted portion) to the position where nodeToSort should be inserted
        bool notInserted = true;
        while (notInserted) {
            // If cursor reached end of the sorted portion
            if (cursor->next == nullptr) {
                // Insert nodeToSort at the end of the sorted portion
                nodeToSort->next = nullptr;
                cursor->next = nodeToSort;

                // Set tail of list to be the inserted node
                list->tail = nodeToSort;

                // Flag to exit loop
                notInserted = false;
            } else if (*nodeToSort <= *(cursor->next)) {
                // If cursor is where the nodeToSort should be inserted, insert nodeToSort
                nodeToSort->next = cursor->next;
                cursor->next = nodeToSort;

                // Flag to exit loop
                notInserted = false;
            }

            // Otherwise, iterate cursor
            cursor = cursor->next;
        }
    }
}

/**
 * @brief Iterates through the unsorted portion of the list and calls insertIntoSorted to add each to the sorted portion of the list.
 * 
 * @param list the list perform insertion sort on
 */
void insertionSort(LinkedList* list) {
    // Base case case if list is empty
    if (list->head == nullptr) {
        return;
    }

    // Extract the node to sort
    Node* nodeToSort = list->head->next;
    list->head->next = nullptr;
    list->tail = list->head;

    // Iterate until all nodes are in the sorted portion
    while (nodeToSort != nullptr) {
        // Track next node to sort
        Node* nextToSort = nodeToSort->next;
        // Insert node into sorted position
        insertIntoSorted(list, nodeToSort);
        // Iterate to next node to sort
        nodeToSort = nextToSort;
    }
}

/**
 * @brief Runs the insertion sort function to perform in-place insertion sort.
 * 
 * @param list the list to sort
 */
void sort(LinkedList* list) {
    insertionSort(list);
}