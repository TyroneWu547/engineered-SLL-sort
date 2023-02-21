/**
 * @file LinkedList.h
 * @author Andrew Sauerbrei
 *         AJ Bulthuis
 *         Tyrone Wu
 * @brief Classes that defines the linked list data structure and node object.
 * 
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdlib.h>

/**
 * @brief Node object that hold the data and the next node in sequence.
 * 
 */
class Node {
public:

    /** The data to hold. */
    int data;
    /** Pointer to the next node in sequence. */
    Node* next;

    /**
     * @brief Construct a new Node object with the data and no next.
     * 
     * @param data the data for the node to store
     */
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    /**
     * @brief Defines == operator for comparing nodes.
     * 
     * @param other the other node to compare to
     * @return true if both nodes data are equal
     * @return false if both nodes data are not equal
     */
    bool operator == (const Node& other) const;

    /**
     * @brief Defines < operator for comparing nodes.
     * 
     * @param other the other node to compare to
     * @return true if this node's data is less than other node's data
     * @return false if this node's data is not less than other node's data
     */
    bool operator < (const Node& other) const;

    /**
     * @brief Defines != operator for comparing nodes. (derives from !operator==)
     * 
     * @param other the other node to compare to
     * @return true if both nodes data are not equal
     * @return false if both nodes data are equal
     */
    bool operator != (const Node& other) const;

    /**
     * @brief Defines <= operator for comparing nodes. (derives from operator< || operator==)
     * 
     * @param other the other node to compare to
     * @return true if this node's data is less than or equal to other node's data
     * @return false if this node's data is not less than or equal to other node's data
     */
    bool operator <= (const Node& other) const;

    /**
     * @brief Defines > operator for comparing nodes. (derives from !operator< && !operator==)
     * 
     * @param other the other node to compare to
     * @return true if this node's data is greater than other node's data
     * @return false if this node's data is not greater than other node's data
     */
    bool operator > (const Node& other) const;

    /**
     * @brief Defines >= operator for comparing nodes. (derives from !operator<)
     * 
     * @param other the other node to compare to
     * @return true if this node's data is greater than or equal to other node's data
     * @return false if this node's data is not greater than or equal to other node's data
     */
    bool operator >= (const Node& other) const;

    // /**
    //  * @brief Defines if this node is NULL or not.
    //  * 
    //  * @return true if this node is NULL
    //  * @return false if this node is not NULL
    //  */
    // bool operator == (std::nullptr_t) {
    //     return *this == nullptr;
    // }

    // /**
    //  * @brief Defines if this node is NULL or not.
    //  * 
    //  * @return true if this node is not NULL
    //  * @return false if this node is NULL
    //  */
    // bool operator != (std::nullptr_t) {
    //     return !(*this == nullptr);
    // }
};

/**
 * @brief Class that defines the singly linked list data structure. 
 * 
 */
class LinkedList {
public:

    /** Pointer to the head Node of the SLL. */
    Node* head;
    /** Pointer to the tail Node of the SLL. */
    Node* tail;

    /**
     * @brief Construct a new Linked List object with the following head and tail.
     * 
     * @param head the head of the SLL
     * @param tail the tail of the SLL
     */
    LinkedList(Node* head, Node* tail) { 
        this->head = head;
        this->tail = tail;
    }

    /**
     * @brief Construct a new Linked List object that is empty.
     * 
     */
    LinkedList() {
        LinkedList(NULL, NULL);
    }

    /**
     * @brief Append the new node to the end of the SLL.
     * 
     * @param data the data of the new node
     */
    void append(int data);

    /**
     * @brief Removes and returns the node at the head of the SLL.
     * 
     * @return Node* the pointer to the removed/popped node
     */
    Node* popHead();

    /**
     * @brief Adds the node to the head of the SLL.
     * 
     * @param newHead the node to push
     */
    void pushHead(Node* newHead);
};

#endif // LINKEDLIST_H