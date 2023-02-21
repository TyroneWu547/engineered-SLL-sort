/**
 * @file merge.cpp
 * @author your name (you@domain.com)
 * @brief 
 * 
 */

#include <iostream>
#include "../include/Sort.h"
#include "../include/LinkedList.h"

void split(Node* head, Node** leftHead, Node** rightHead) {
    Node* fast = head;
    Node* slow = head;

    while (fast->next != nullptr) {
        fast = fast->next;
        if (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *leftHead = head;
    *rightHead = slow->next;
    slow->next = nullptr;
}

Node* merge(Node* leftHead, Node* rightHead) {
    // Return the left or right if the opposite split is empty
    if (leftHead == nullptr) {
        return rightHead;
    } else if (rightHead == nullptr) {
        return leftHead;
    }

    Node* leftCursor = leftHead;
    Node* rightCursor = rightHead;
    Node* cursor;
    if (*leftCursor <= *rightCursor) {
        cursor = leftCursor;
        leftCursor = leftCursor->next;
    } else {
        cursor = rightCursor;
        rightCursor = rightCursor->next;
    }
    Node* newHead = cursor;

    while (leftCursor != nullptr && rightCursor != nullptr) {
        if (*leftCursor <= *rightCursor) {
            cursor->next = leftCursor;
            leftCursor = leftCursor->next;
        } else {
            cursor->next = rightCursor;
            rightCursor = rightCursor->next;
        }
        cursor = cursor->next;
    }

    if (leftCursor == nullptr) {
        cursor->next = rightCursor;
    } else {
        cursor->next = leftCursor;
    }

    return newHead;
}

Node* mergeSort(Node* head) {
    // Base case
    if ((head == nullptr) || (head->next == nullptr)) {
        return head;
    }

    // Split into sublists
    Node* leftHead;
    Node* rightHead;
    split(head, &leftHead, &rightHead);

    // Recursively split the linked list in half
    leftHead = mergeSort(leftHead);
    rightHead = mergeSort(rightHead);

    // Merge the lists together
    return merge(leftHead, rightHead);
}

void sort(LinkedList* list) {
    list->head = mergeSort(list->head);
}