#include <iostream>
#include "RingBuffer.h"
#include "Iterator.h"

using namespace std;
int main()
{
    RingBuffer* a = new RingBuffer(7);
    a->addElement(11);
    a->addElement(22);
    a->addElement(33);
    a->addElement(44);
    a->addElement(55);
    a->addElement(66);
    a->addElement(77);

    cout << "getElem()" << endl;
    cout << a->getElem() << endl;

    cout << "seeElem()" << endl;
    cout << a->seeElem() << endl;

    RingBuffer* b = new RingBuffer(*a);

    a->doEmptyQueue();
    cout << "checkEmpty" << endl;
    if (a->checkEmpty()) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    Iterator iter = Iterator(b);

    while (!iter.finish()) {
        iter.next();
        cout << iter.getValue() << endl;
    }
    cout << endl;
    iter.start();
    while (!iter.finish()) {
        iter.next();
        cout << iter.getValue() << endl;

    }
}