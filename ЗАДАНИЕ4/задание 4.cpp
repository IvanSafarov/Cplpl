#include <iostream>
#include "hashtable.h"
#include "iterator.h"
using namespace std;

int main()
{
    HashTable table;

    table.add(1, 10);
    table.add(2, 20);
    table.add(10, 15);
    table.add(17, 30);
    table.add(16, 40);

    cout << "key 1 " << endl << table.findElem(1)->value << endl;
    
    table.remove(1);
    cout << "deleted key 1 " << endl << (table.findElem(1) == nullptr) << endl;
    
    cout << "key 16 " << endl << table.findElem(16)->value << endl;
    
    table.add(31, 41);
    cout << "key 31 " << endl << table.findElem(31)->value << endl;

    Iterator* iter = new Iterator(table);
    iter->start();
    cout << iter->getValue() << " ";
    while (!iter->finish()) {
        iter->next();
        cout << iter->getValue() << " ";
    }
    cout << endl;

    cout << "Is empty " << endl << table.isEmpty() << endl;

    table.empty();
    cout << "Is empty " << endl << table.isEmpty() << endl;


}