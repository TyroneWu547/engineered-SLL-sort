#include <iostream>
#include "../include/Sort.h"
#include "../include/LinkedList.h"

void split(Node* list, Node** refFront, Node** refBack)
{
    Node* fast;
    Node* slow;
    slow = list;
    fast = list->next;

    while(fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *refFront = list;
    *refBack = slow->next;
    slow->next = NULL;
}

Node* merge(Node* listA, Node* listB)
{
    Node* ret = NULL;

    // Base cases
    if (listA == NULL)
    {
        return listB;
    }
    else if (listB == NULL)
    {
        return listA;
    }

    if (listA->data <= listB->data)
    {
        ret = listA;
        ret->next = merge(listA->next, listB);
    }
    else
    {
        ret = listB;
        ret->next = merge(listA, listB->next);
    }

    return ret;
}

void sort(LinkedList* list) {
    Node* front = list->head;
    std::cout << front->data << " " << front->next->data << std::endl;
    LinkedList* x;
    LinkedList* y;

    // Base case
    if ((front == NULL) || (front->next == NULL))
    {
        return;
    }

    // Split into sublists
    split(front, &x->head, &y->head);

    //Recurse
    sort(x);
    sort(y);

    // Merge the lists together
    list->head = merge(x->head, y->head);
}