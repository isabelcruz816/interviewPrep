#ifndef HashTable
#include <iostream>
#include "../LinkedList/LinkedList.cpp"

class HashTable {
    int BUCKET; // number of buckets
    LinkedList *table;

    public:
        HashTable(int n);
        void insert(int n);
        void pop(int n);
        int hashFunction();
        void showHash();
};
#endif /* HashTable.hpp */