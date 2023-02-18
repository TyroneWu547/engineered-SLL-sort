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

    // Perform benchmark on sort
    Timer timer;
    timer.start();
    sort(list);
    timer.stop();

    // Print the sorted list
    Node* cursor = (*list).head;
    while (cursor) {
        cout << (*cursor).data << endl;
        cursor = cursor->next;
    }

    cerr << "runtime     " << timer.getTotalTime() << endl;
    cerr << "comparisons " << "TODO" << endl;
    return 0;
}