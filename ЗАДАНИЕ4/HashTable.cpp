#include "hashtable.h"
#include <iostream>

using namespace std;

HashTable::HashTable() {
    buffer = 15;
    size = 0;
    arr = new Node[buffer];
    for (int i = 0; i < buffer; i++) {
        arr[i].next = nullptr;
    }
}

HashTable::HashTable(const HashTable& hashTable) {
    buffer = 15;
    size = 0;
    arr = new Node[buffer];
    for (int i = 0; i < buffer; i++) {
        arr[i].next = nullptr;
    }
    Node* p;
    for (int i = 0; i < buffer; i++) {
        p = hashTable.arr[i].next;
        while (p != nullptr) {
            add(p->key, p->value);
            p = p->next;
        }
    }
}

HashTable::HashTable(HashTable&& hashTable) {
    buffer = hashTable.buffer;
    size = hashTable.size;
    arr = hashTable.arr;
    hashTable.arr = nullptr;
    hashTable.size = 0;
    hashTable.buffer = 0;
}

HashTable::~HashTable() {
    empty();
    delete[] arr;
}

bool HashTable::isEmpty() {
    return size == 0;
}

Node* HashTable::getArr() {
    return arr;
}

int HashTable::getLength() {
    return size;
}

int HashTable::getBuffer() {
    return buffer;
}

void HashTable::add(int key, int value) {
    Node* elem = new Node;
    elem->key = key;
    elem->value = value;
    elem->next = nullptr;
    Node* p = &arr[hashFunc(key)];
    while (p->next != nullptr) {
        p = p->next;
        if (p->key == key) {
            p->value = value;
        }
    }
    p->next = elem;
    size++;
}

void HashTable::remove(int key) {
    Node* p = &arr[hashFunc(key)];
    while (p->next->key != key) {
        p = p->next;
    }
    Node* temp = p->next;
    p->next = temp->next;
    delete temp;
    size--;
}

Node* HashTable::findElem(int key) {
    bool isFind = false;
    Node* p = &arr[hashFunc(key)];
    while (p->next != nullptr) {
        p = p->next;
        if (p->key == key) {
            isFind = true;
            break;
        }
    }
    if (isFind)
        return p;
    return nullptr;
}

void HashTable::empty() {
    if (size != 0) {
        Node* p;
        Node* t;
        for (int i = 0; i < buffer; i++) {
            p = arr[i].next;
            while (p != nullptr) {
                t = p;
                p = p->next;
                delete t;
            }
        }
    }
    size = 0;
}
