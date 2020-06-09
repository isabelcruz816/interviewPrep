#ifndef LinkedList
#include <iostream>

struct Node {
    int val;
    Node* next;
};

class LinkedList {
        Node* head;
        Node* tail;

    public:
        LinkedList(); // Constructor
        void insertNode(int n);
        void deleteNode(Node* node);
        void showList();
};
#endif /* LinkedList.h */
