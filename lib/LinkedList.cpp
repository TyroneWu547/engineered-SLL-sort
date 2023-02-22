/**
 * @file LinkedList.cpp
 * @author Andrew Sauerbrei
 *         AJ Bulthuis
 *         Tyrone Wu
 * @brief Class that implements the operators of node and funcitons of linked list. 
 * 
 */

#include <stdlib.h>
#include "../include/LinkedList.h"

/** Global counter for number of comparison operators performed. */
extern unsigned long long compares;

/**
 * @brief Defines == operator for comparing nodes.
 * 
 * @param other the other node to compare to
 * @return true if both nodes data are equal
 * @return false if both nodes data are not equal
 */
bool Node::operator == (const Node& other) const {
    // Increment counter and compare if ==
    compares++;
    return data == other.data;
}

/**
 * @brief Defines < operator for comparing nodes.
 * 
 * @param other the other node to compare to
 * @return true if this node's data is less than other node's data
 * @return false if this node's data is not less than other node's data
 */
bool Node::operator < (const Node& other) const {
    // Increment counter and compare if <
    compares++;
    return data < other.data;
}

/**
 * @brief Defines != operator for comparing nodes. (derives from !operator==)
 * 
 * @param other the other node to compare to
 * @return true if both nodes data are not equal
 * @return false if both nodes data are equal
 */
bool Node::operator != (const Node& other) const {
    // // Use operator== to implicity increment counter and compare if !=
    // return !(*this == other);

    // Increment counter and compare if !=
    compares++;
    return data != other.data;
}

/**
 * @brief Defines <= operator for comparing nodes. (derives from operator< || operator==)
 * 
 * @param other the other node to compare to
 * @return true if this node's data is less than or equal to other node's data
 * @return false if this node's data is not less than or equal to other node's data
 */
bool Node::operator <= (const Node& other) const {
    // // Use operator< to implicity increment counter and compare if <
    // if (*this < other) {
    //     return true;
    // } else {
    //     // If operator< false, undo counter increment and try operator== if ==
    //     compares--;
    //     return *this == other;
    // }

    // Increment counter and compare if <=
    compares++;
    return data <= other.data;
}

/**
 * @brief Defines > operator for comparing nodes. (derives from !operator< && !operator==)
 * 
 * @param other the other node to compare to
 * @return true if this node's data is greater than other node's data
 * @return false if this node's data is not greater than other node's data
 */
bool Node::operator > (const Node& other) const {
    // // Use operator< and operator== to compare if >
    // // since it increments twice from operator< && operator==, decrement counter
    // compares--;
    // return !(*this < other) && !(*this == other);

    // Increment counter and compare if >
    compares++;
    return data > other.data;
}

/**
 * @brief Defines >= operator for comparing nodes. (derives from !operator<)
 * 
 * @param other the other node to compare to
 * @return true if this node's data is greater than or equal to other node's data
 * @return false if this node's data is not greater than or equal to other node's data
 */
bool Node::operator >= (const Node& other) const {
    // // Use operator< to implicity increment counter and compare if >=
    // return !(*this < other);

    // Increment counter and compare if >=
    compares++;
    return data >= other.data;
}

/**
 * @brief Append the new node to the front of the SLL.
 * 
 * @param data the data of the new node
 */
void LinkedList::append(int data) {
    // Create new node with the data
    Node* node = new Node(data);
    size++;

    // If linked list is empty
    if (this->head == nullptr) {
        // set head and tail to Node
        this->head = node;
        this->tail = node;
    } else {
        // otherwise, append node to head
        pushHead(node);
    }
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
    pop->next = nullptr;

    // If tail if last node is popped
    if (this->head->next == nullptr) {
        this->tail = nullptr;
    }

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