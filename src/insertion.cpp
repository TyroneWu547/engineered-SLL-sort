#include <iostream>
#include "../include/Sort.h"
#include "../include/LinkedList.h"

//This method inserts a node into the sorted portion of the array
void insertedIntoSorted(LinkedList* list, Node* pointToSort){
    Node* sortedItr = list->head;
    if (*pointToSort <= *(list->head)){
        pointToSort->next = list->head;
        list->head = pointToSort;
    } else {
        do{
            if(sortedItr->next == nullptr){
                pointToSort->next = sortedItr->next;
                sortedItr->next = pointToSort;
                list->tail = pointToSort;
                break;
            } else if(*pointToSort <= *(sortedItr->next)){
                pointToSort->next = sortedItr->next;
                sortedItr->next = pointToSort;
                break;
            }
            sortedItr = sortedItr->next; 
        } while (sortedItr != nullptr);
    }
}

//This method iterates through the unsorted portion of the list and calls insertedIntoSorted to add each to the sorted portion of the list
void insertionSort(LinkedList* list) {
    Node* pointToSort = list->head->next;
    Node* nextPointToSort;
    list->head->next = nullptr;
    while (pointToSort != nullptr) {
        nextPointToSort = pointToSort->next;
        insertedIntoSorted(list, pointToSort);
        pointToSort = nextPointToSort;
    }
    return;
};

//This runs the insertion function, updates the the list with the new node values, and outputs the sorted list
void sort(LinkedList* list) {
    insertionSort(list);
};