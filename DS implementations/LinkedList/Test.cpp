// CPP to test data structures implementations
#include <iostream>
#include "LinkedList.cpp"
using namespace std;

int main() {
    int arr[5] = {0, 1, 2, 3, 4};
    LinkedList list;

    for (int i = 0; i < 5; i++) {
        list.insertNode(arr[i]);
    }

    list.showList();
    return 0;
}