#include <iostream>
#include "../include/Sort.h"
#include "../include/Time.h"

using namespace std;

int main() {
    int item;
    int count = 0;
    while (cin >> item) {
        count++;
    }
    cout << sort(count) << endl;
    return 0;
}