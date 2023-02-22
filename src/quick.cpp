#include <iostream>
#include "../include/Sort.h"
#include "../include/LinkedList.h"

using namespace std;

Node* getPivot(Node* h) {
    Node* m = h;
    Node* t = h;

    while (t->next != nullptr) {
        t = t->next;
        if (t->next != nullptr) {
            m = m->next;
            t = t->next;
        }
    }

    if(m->data < t->data && t->data < h->data)
        return t;
    else if(m->data < h->data && h->data < t->data)
        return h;
    else
        return m;
}

// Node* getPivot(Node* m, Node* t, Node* h){
//     if(t->next == nullptr || t->next->next == nullptr){
//         if(m->data < t->data && t->data < h->data)
//             return t;
//         else if(m->data < h->data && h->data < t->data)
//             return h;
//         else
//             return m;
//     } 
//     return getPivot(m->next, t->next->next, h);
// }

// Node* getPivot(Node* h){
//     if(h->next == nullptr || h->next->next == nullptr)
//         return h;
//     return getPivot(h->next, h->next->next, h);
// }

Node* findEnd(Node* h) {
    Node* t = h;
    while (t->next != nullptr)
        t= t->next;
    return t; 
}

// Node* combine(Node* l, Node* m, Node* r){
//     findEnd(m)->next = r;
//     if (l != nullptr){
//         findEnd(l)->next = m;
//         return l;
//     }
//     return m;

// }

Node* combine(Node* l, Node* r){
    if (l != nullptr){
        findEnd(l)->next = r;
        return l;
    }
    return r;
}

Node* quick(Node* h, Node* p){
    if(h->next != nullptr){
        Node* l = nullptr;
        Node* r = nullptr;
        Node* m = nullptr;

        Node* t = h;
        Node* hold;
        do{
            hold = t->next;
            if(t < p){
                t->next = l;
                l = t;
            } else if(t > p) {
                t->next = r;
                r = t;
            } else {
                t->next = m;
                m = t;   
            } 
            t = hold;
        } while (t != nullptr);

        if(l != nullptr)
            l = quick(l, getPivot(l));   

        l = combine(l, m); 

        if(r != nullptr)
            r = quick(r, getPivot(r));

        return combine(l, r);
    }
    return h;
}

void sort(LinkedList* list) {
    list->head = quick(list->head, getPivot(list->head));
}