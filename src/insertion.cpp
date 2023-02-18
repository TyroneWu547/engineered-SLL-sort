#include <iostream>
#include "../include/Sort.h"
#include "../include/LinkedList.h"

Node* tail;

//This method inserts a node into the sorted portion of the list
Node* insert(Node* h, Node* spot){
    //Case where we have found where we want to insert the node and we are not at the end of the list
    if(spot->data <= h->data){
        spot->next = h;
        return spot;
    //Case where the node needs to go at the end of the list
    } else if (h->next == nullptr){
        spot->next = nullptr;
        h->next = spot;
        tail = spot;
        return h;
    //Case where we need to keep iterating to find the insert point
    } else {
        h->next = insert(h->next, spot);
        return h;
    }
};

//This method iterates through the unsorted portion of the list
Node* insertionRec(Node* h, Node* spot) {
    Node* temp = spot->next;
    h = insert(h, spot);
    //Checks to see if we have run out of unsorted list nodes
    if (temp != nullptr){
        return insertionRec(h, temp);
    } else {
        return h;
    }
};

//Runs through the method to run insertion sort on the list and then allocates the head and tail afterwards
void sort(LinkedList* list) {
    Node* spot = list->head->next;
    list->head->next = nullptr;
    list->head = insertionRec(list->head, spot);
    list->tail = tail;
    std::cout << "insertion sort with " << (*list).size << " nodes" << std::endl;
};