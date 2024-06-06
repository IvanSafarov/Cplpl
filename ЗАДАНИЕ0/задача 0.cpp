#include <iostream>
#include "BoxContainer.h"

using namespace std;
using namespace BoxContainer;

int main() {
	Box box;
	Box box1(1, 1, 1, 10, 10);
	Box box2(2, 2, 2, 11, 20);
	Box box3(3, 3, 3, 20, 30);
	Box box4(4, 4, 4, 25, 40);
	Box box5(4, 4, 4, 25, 40);
	Box arr[4] = { box1, box2, box3, box4 };
	Container container(100, 100, 100, 1000);
	Container container1(1, 1, 1, 10);
	container.setBox(box1);
	container.setBox(box2);
	container.setBox(box3);
	container.setBox(box4);
	container.setBox(box5);
	cout << "sumValue" << endl;
	cout << box.sumValue(arr, 4) << endl;
	cout << "compareSum" << endl;
	cout << box.compareSum(arr, 50, 4) << endl;
	cout << "maxWeight" << endl;
	cout << box.maxWeight(arr, 8, 4) << endl;
	cout << "matryoshka" << endl;
	if (box.matryoshka(arr, 4)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	cout << "==" << endl;
	if (box4 == box5) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	cout << ">>" << endl;
	cin >> box;
	cout << "<<" << endl;
	cout << box << endl;

	cout << "<< container" << endl;
	cout << container << endl;
	cout << "<< container del 4" << endl;
	container.deleteBox(4);
	cout << container << endl;
	cout << "size container" << endl;
	cout << container.getSize() << endl;
	cout << "SumWeight container" << endl;
	cout << container.sumWeight() << endl;
	cout << "sumValue container" << endl;
	cout << container.sumValue() << endl;
	cout << "getBox(0) container" << endl;
	cout << container.getBox(0) << endl;
	cout << ">> container1" << endl;
	cin >> container1;
	cout << "<< container1" << endl;
	cout << container1 << endl;
	cout << "<< container[0]" << endl;
	cout << container[0] << endl;
	//Container(int _length, int _width, int _height, double _weight)
	//Box(int _length, int _width, int _height, int _value, double _weight)

}