#include <stdlib.h>
#include "../include/LinkedList.h"

// Append Node to end of linked list
void LinkedList::append(int data) {
    // Create new Node
    Node* node = new Node(data);

    // If linked list is empty
    if (head == NULL) {
        // Set head and tail to Node
        head = node;
    } else {
        // Append Node to tail
        tail->next = node;
    }

    // Set new tail of the linked list
    size++;
    tail = node;
}