#include <iostream>
#include "../include/Sort.h"
#include "../include/LinkedList.h"

using namespace std;
Node* tail;
Node* spot;
Node* nextSpot;

//This recursive method inserts a node into the sorted portion of the list
Node* insert(Node* h, Node* spot){
    if(spot->data <= h->data){
        spot->next = h;
        return spot;
    } else if (h->next == nullptr) {
        spot->next = nullptr;
        h->next = spot;
        tail = spot;
        return h;
    }
    h->next = insert(h->next, spot);
    return h;
};

//This method iterates through the unsorted portion of the list
Node* insertionRec(Node* h) {
    spot = h->next;
    h->next = nullptr;
    while (spot != nullptr) {
        nextSpot = spot->next;
        h = insert(h, spot);
        spot = nextSpot;
    }
    return h;
};

//Runs through the method to run insertion sort on the list and then allocates the head and tail afterwards
void sort(LinkedList* list) {
    list->head = insertionRec(list->head);
    list->tail = tail;
};