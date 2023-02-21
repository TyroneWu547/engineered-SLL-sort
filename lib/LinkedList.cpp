/**
 * @file LinkedList.cpp
 * @author Andrew Sauerbrei
 *         AJ Bulthuis
 *         Tyrone Wu
 * @brief Class that implements the funcitons of linked list. 
 * 
 */

#include <stdlib.h>
#include "../include/LinkedList.h"

/**
 * @brief Append the new node to the end of the SLL.
 * 
 * @param data the data of the new node
 */
void LinkedList::append(int data) {
    // Create new node with the data
    Node* node = new Node(data);

    // If linked list is empty
    if (!this->head) {
        // set head and tail to Node
        this->head = node;
    } else {
        // otherwise, append node to tail
        this->tail->next = node;
    }

    // Set new tail of the linked list
    this->tail = node;
}

/**
 * @brief Removes and returns the node at the head of the SLL.
 * 
 * @return Node* the pointer to the removed/popped node
 */
Node* LinkedList::popHead() {
    // Get head of the SLL
    Node* pop = this->head;
    // Shift head to next node
    this->head = this->head->next;
    // Detach popped node from list
    pop->next = NULL;

    return pop;
}

/**
 * @brief Adds the node to the head of the SLL.
 * 
 * @param newHead the node to push
 */
void LinkedList::pushHead(Node* newHead) {
    newHead->next = this->head;
    this->head = newHead;
}