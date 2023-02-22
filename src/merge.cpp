/**
 * @file merge.cpp
 * @author Andrew Sauerbrei
 *         AJ Bulthuis
 *         Tyrone Wu
 * @brief The merge sort implementation. 
 * 
 */

#include <iostream>
#include "../include/Sort.h"
#include "../include/LinkedList.h"

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
 * @brief Performs recursive merge sort on the list until all nodes are merged. 
 * 
 * @param head the head of the list to merge sort on
 * @return Node* the head of the sorted and merged list
 */
Node* mergeSort(Node* head) {
    // Base case if list is empty or contains one node
    if ((head == nullptr) || (head->next == nullptr)) {
        return head;
    }

    // Split into left and right sub-lists
    Node* leftHead;
    Node* rightHead;
    split(head, &leftHead, &rightHead);

    // Recursively split the left and right sub-lists in half
    leftHead = mergeSort(leftHead);
    rightHead = mergeSort(rightHead);

    // Merge the left and right sub-lists in sorted order
    return merge(leftHead, rightHead);
}

/**
 * @brief Runs the merge sort function to perform in-place merge sort.
 * 
 * @param list the list to sort
 */
void sort(LinkedList* list) {
    list->head = mergeSort(list->head);
}