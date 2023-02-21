/**
 * @file main.cpp
 * @author Andrew Sauerbrei
 *         AJ Bulthuis
 *         Tyrone Wu
 * @brief The main class that parses the input and sorts it.
 * 
 */

#include <iostream>
#include "../include/Sort.h"
#include "../include/LinkedList.h"
#include "../include/Time.h"

using namespace std;

/** Global counter for number of comparison operators performed. */
unsigned long long compares;

/**
 * @brief Parse cin into a Linked List and performs sort + benchmark
 * 
 * @return int the return status of the execution
 */
int main() {
    // Singley linked list data structure
    LinkedList* list = new LinkedList();
    // Parse cin into a linked list
    int item;
    while (cin >> item) {
        list->append(item);
    }
    // Initialize comparison counter
    compares = 0;

    // Perform benchmark on the sort
    Timer timer;
    timer.start();
    sort(list);
    timer.stop();

    // Print the sorted list to standard output
    Node* cursor = (*list).head;
    while (cursor) {
        cout << (*cursor).data << endl;
        cursor = cursor->next;
    }

    // Print the benchmark to standard error
    cerr << "runtime     " << timer.getTotalTime() << endl;
    cerr << "comparisons " << compares << endl;
    return 0;
}