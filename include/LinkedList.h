#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

// Node of a linked list
class Node {
public:
    // Data of the node
    int data;
    // Next node
    Node* next;

    // Node constructor with item
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Linked list class
class LinkedList {
public:
    // Pointer to the head Node of the linked list
    Node* head;
    // Pointer to the tail Node of the linked list
    Node* tail;
    // Number of Nodes in the list
    int size;

    // Linked list constructor for setting the head and tail
    LinkedList(Node* head, Node* tail) { 
        this->head = head;
        this->tail = tail;
    }

    // Default constructor for empty linked list
    LinkedList() { 
        LinkedList(NULL, NULL);
    }

    // Append Node to end of linked list
    void append(int);
};

#endif // LINKEDLIST_H