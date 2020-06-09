#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList :: LinkedList() {
    head = NULL;
    tail = NULL;
}

void LinkedList :: insertNode(int val) {
    Node* newNode = new Node();
    newNode->val = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = tail->next;
    }
}

void LinkedList :: deleteNode(Node* node) { 
    if (head == NULL)
        return;

    if (head == node){
        head = NULL;
        tail = NULL;
        return;
    }

    Node* temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    delete(temp);    
}

void LinkedList :: showList() {
    Node* curr = head;

    while(curr != NULL){
        std::cout << curr->val;

        if(curr->next != NULL)
            std::cout << "->";
            
        curr = curr->next;
    }
    
    std::cout << std::endl;
}