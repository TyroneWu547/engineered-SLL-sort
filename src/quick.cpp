#include <iostream>
#include "../include/Sort.h"
#include "../include/LinkedList.h"

Node* getPivot(Node* m, Node* t, Node* h){
    if(t->next == nullptr || t->next->next == nullptr){
        if(m->data < t->data && t->data < h->data)
            return t;
        else if(m->data < h->data && h->data < t->data)
            return h;
        else
            return m;
    } 
    return getPivot(m->next, t->next->next, h);
}

Node* getPivot(Node* h){
    if(h->next == nullptr || h->next->next == nullptr)
        return h;
    return getPivot(h->next, h->next->next, h);
}

Node* findEnd(Node* h) {
    if (h->next != nullptr)
        return findEnd(h->next);
    return h; 
}

Node* combine(Node* l, Node* m, Node* r){
    findEnd(m)->next = r;
    if (l != nullptr){
        findEnd(l)->next = m;
        return l;
    }
    return m;
    
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
            if(t->data < p->data){
                t->next = l;
                l = t;
            } else if(t->data > p->data) {
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
        if(r != nullptr)
            r = quick(r, getPivot(r));

        return combine(l, m, r);
    }
    return h;
}

void sort(LinkedList* list) {
    quick(list->head, getPivot(list->head));
}