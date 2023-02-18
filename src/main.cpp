#include <iostream>
#include "../include/Sort.h"
#include "../include/LinkedList.h"
#include "../include/Time.h"

using namespace std;

// Parse cin into a Linked List and sort
int main() {
    // Singley linked list data structure
    LinkedList* list = new LinkedList();

    // Parse cin into a linked list
    int item;
    while (cin >> item) {
        (*list).append(item);
    }

    // Perform inplace sort
    sort(list);

    cout << "done" << endl;
    return 0;
}