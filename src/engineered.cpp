/**
 * @file engineer.cpp
 * @author Andrew Sauerbrei
 *         AJ Bulthuis
 *         Tyrone Wu
 * @brief The engineered implementation.
 * 
 */

#include <iostream>
#include <tgmath.h>
#include "../include/Sort.h"
#include "../include/LinkedList.h"

/**
 * @brief Inserts the node to sort into the sorted portion of the list.
 * 
 * @param list the list the node is inserting into
 * @param nodeToSort the node to insert into the sorted portion
 * @return Node* head of the newlt sorted list
 */
Node* insertIntoSorted(Node* head, Node* nodeToSort) {
    // First check if the nodeToSort should be inserted into the front of the sorted portion
    if (*nodeToSort <= *head) {
        // Inserted node at the front
        nodeToSort->next = head;
        head = nodeToSort;
    } else {
        // Cursor that tracks where the nodeToSort should be inserted
        Node* cursor = head;

        // Iterate cursor (from head of the sorted portion) to the position where nodeToSort should be inserted
        bool notInserted = true;
        while (notInserted) {
            // If cursor reached end of the sorted portion
            if (cursor->next == nullptr) {
                // Insert nodeToSort at the end of the sorted portion
                nodeToSort->next = nullptr;
                cursor->next = nodeToSort;

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
    return head;
}

/**
 * @brief Iterates through the unsorted portion of the list and calls insertIntoSorted to add each to the sorted portion of the list.
 * 
 * @param head the list perform insertion sort on
 * @return Node* head of the newlt sorted list
 */
Node* insertionSort(Node* head) {

    // Extract the node to sort
    Node* nodeToSort = head->next;
    head->next = nullptr;

    // Iterate until all nodes are in the sorted portion
    while (nodeToSort != nullptr) {
        // Track next node to sort
        Node* nextToSort = nodeToSort->next;
        // Insert node into sorted position
        head = insertIntoSorted(head, nodeToSort);
        // Iterate to next node to sort
        nodeToSort = nextToSort;
    }
    return head;
}

/**
 * @brief Sets the head of the left and right half of the list and separates the sub-lists. 
 * 
 * @param head the head of the original list
 * @param leftHead the head of the left half of the list
 * @param rightHead the head of the right half of the list
 */
void split(Node* head, Node** leftHead, Node** rightHead) {
    // Use a fast and slow pointer to find the middle of the original list
    Node* fast = head->next;
    Node* slow = head;
    while (fast != nullptr) {
        // Fast iterates twice as fast as slow
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Set the left and right heads of the lists
    *leftHead = head;
    *rightHead = slow->next;
    // Separate the left and right lists
    slow->next = nullptr;
}

/**
 * @brief Merge the left and right lists in sorted order and returns the new head of the sorted list.
 * 
 * @param leftHead the left sub-list to merge
 * @param rightHead the right sub-list to merge
 * @return Node* the new head of the merged and sorted list
 */
Node* merge(Node* leftHead, Node* rightHead) {
    // Return the left or right if the opposite is empty
    if (leftHead == nullptr) {
        return rightHead;
    } else if (rightHead == nullptr) {
        return leftHead;
    }

    // Cursor of left sub-list
    Node* leftCursor = leftHead;
    // Cursor of right sub-list
    Node* rightCursor = rightHead;
    // Cursor of the final merged list
    Node* cursor;

    // First identify the head of the merged list
    if (*leftCursor <= *rightCursor) {
        cursor = leftCursor;
        leftCursor = leftCursor->next;
    } else {
        cursor = rightCursor;
        rightCursor = rightCursor->next;
    }
    Node* newHead = cursor;

    // Iterator left and right cursor until one can no longer iterate
    while (leftCursor != nullptr && rightCursor != nullptr) {
        // Merge left/right cursor node so it is sorted and iterate left/right cursor
        if (*leftCursor <= *rightCursor) {
            cursor->next = leftCursor;
            leftCursor = leftCursor->next;
        } else {
            cursor->next = rightCursor;
            rightCursor = rightCursor->next;
        }

        // Iterate cursor of merged list
        cursor = cursor->next;
    }

    // If left/right still has nodes left, merge the rest
    if (leftCursor == nullptr) {
        cursor->next = rightCursor;
    } else {
        cursor->next = leftCursor;
    }

    return newHead;
}

/**
 * @brief Performs recursive merge sort until counter is 0, then switch to insertion sort on the leaves of the recursive calls. 
 * 
 * @param head the head of the list to merge sort on
 * @param counter keeps track of when to switch to insertion sort
 * @return Node* the head of the sorted list
 */
Node* engineeredSort(Node* head, int counter) {
    // Base case if list is empty or contains one node
    if ((head == nullptr) || (head->next == nullptr)) {
        return head;
    }

    // Recursievly split and merge if the list size is > k
    if(counter > 0){
        // Split into left and right sub-lists
        Node* leftHead;
        Node* rightHead;

        split(head, &leftHead, &rightHead);

        leftHead = engineeredSort(leftHead, counter-1);
        rightHead = engineeredSort(rightHead, counter-1);

        // Merge the left and right sub-lists in sorted order
        return merge(leftHead, rightHead);

    // Otherwise just run insertion sort and return that
    } else {
        return insertionSort(head);
    }
}

/**
 * @brief Runs the engineeredSort function, which uses a a hybrid of merge sort and inseriton sort. 
 *        The number of times to execute merge sort is pre-computing, and insertion sort is executed on the leaves of the recursive calls. 
 * 
 * @param list the list to sort
 * @param k the block size of when to switch to insertion sort
 */
void sort(LinkedList* list, int k) {
    list->head = engineeredSort(list->head, ceil(log2(((double)list->size) / k)));
}