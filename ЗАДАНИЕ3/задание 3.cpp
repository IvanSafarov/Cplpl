#include <iostream>
#include "BufferList.h"

using namespace std;
int main()
{
	BufferList* buffer = new BufferList();
	BufferList::ListIterator itr(buffer);
	buffer->addElem(1, itr);
	itr.next();
	buffer->addElem(2, itr);
	itr.next();
	buffer->addElem(3, itr);
	itr.next();
	buffer->addElem(4, itr);
	
	itr.start();
	while (!itr.finish())
	{
		itr.next();
		cout << itr.getElement() << endl;
	}

	cout << "---" << endl;
	Iterator* itr1 = buffer->getIterator();
	itr1->next();
	cout << itr1->getElement() << endl;
	cout << "---" << endl;

	Iterator* itr2 = buffer->findElem(3);
	buffer->deleteElem(*itr2);
	itr.start();
	while (!itr.finish())
	{
		itr.next();
		cout << itr.getElement() << endl;
	}
	cout << "Size" << endl << buffer->getSize() << endl;
	cout << "isEmpty" << endl << buffer->isEmpty() << endl;
	buffer->makeEmpty();
	cout << "isEmpty" << endl << buffer->isEmpty() << endl;
}