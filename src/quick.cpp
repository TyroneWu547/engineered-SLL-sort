/**
 * @file quick.cpp
 * @author Andrew Sauerbrei
 *         AJ Bulthuis
 *         Tyrone Wu
 * @brief The quicksort implementation.
 * 
 */

#include <iostream>
#include "../include/Sort.h"
#include "../include/LinkedList.h"

using namespace std;

/**
 * @brief Gets the pivot using the median of the head, middle, and tail. 
 * 
 * @param head the head of the list
 * @return Node* the pivot
 */
Node* getPivot(Node* head) {
    // First set middle and tail to same node as head
    Node* middle = head;
    Node* tail = head;

    // Iterate tail twice as fast as middle to find the middle of the list
    while (tail->next != nullptr) {
        tail = tail->next;
        if (tail->next != nullptr) {
            middle = middle->next;
            tail = tail->next;
        }
    }

    // Return the median value of head, middle, and tail
    if (middle->data < tail->data && tail->data < head->data)
        return tail;
    else if (middle->data < head->data && head->data < tail->data)
        return head;
    else
        return middle;
}

/**
 * @brief Gets the tail of the list.
 * 
 * @param head the nead of the list
 * @return Node* the tail of the list
 */
Node* findEnd(Node* head) {
    // Iterates through the list until it reaches the tail
    Node* tail = head;
    while (tail->next != nullptr)
        tail = tail->next;
    return tail; 
}

/**
 * @brief Combines the left and right sub-list, and returns new head of the combined list.
 * 
 * @param left the left sub-list to combine
 * @param right the right sub-list to combine
 * @return Node* the head of the combined list
 */
Node* combine(Node* left, Node* right) {
    // If left is not empty, attach the end of left to the front of right
    if (left != nullptr) {
        findEnd(left)->next = right;
        return left;
    }
    // Otherwise, return the right
    return right;
}

/**
 * @brief Performs recursive quicksort on the list with the given pivot and combine the sub-lists. 
 * 
 * @param head the head of the list to quicksort on
 * @param pivot the pivot to use
 * @return Node* the head of the sorted list
 */
Node* quick(Node* head, Node* pivot) {
    // If list has more than one node
    if (head->next != nullptr) {
        // Track left sub-list, middle sub-list, and right sub-list of list
        Node* left = nullptr;
        Node* right = nullptr;
        Node* middle = nullptr;

        // Move nodes < pivot to left, nodes > pivot to right, and nodes == pivot to middle
        Node* tail = head;
        Node* hold;
        do {
            hold = tail->next;
            if (*tail < *pivot) {
                tail->next = left;
                left = tail;
            } else if (*tail > *pivot) {
                tail->next = right;
                right = tail;
            } else {
                tail->next = middle;
                middle = tail;   
            } 
            tail = hold;
        } while (tail != nullptr);

        // If left is not empty, recursive quicksort on left sub-list
        if (left != nullptr)
            left = quick(left, getPivot(left));

        // Combine left and middle sub-list into left
        left = combine(left, middle);

        // If right is not empty, recursive quicksort on right sub-list
        if (right != nullptr)
            right = quick(right, getPivot(right));

        // Combine left and right sub-list
        return combine(left, right);
    }

    return head;
}

/**
 * @brief Runs the quick function to perform in-place quicksort.
 * 
 * @param list the list to sort
 */
void sort(LinkedList* list) {
    // Base case if list empty
    if (list->head == nullptr) {
        return;
    }
    // Otherwise, perform quicksort
    list->head = quick(list->head, getPivot(list->head));
}