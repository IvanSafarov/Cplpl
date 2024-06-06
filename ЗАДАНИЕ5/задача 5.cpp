#include "tree.h"
using namespace std;
int main()
{
	tree* treeOne = new tree();

	treeOne->pasteElem(1, {});
	treeOne->pasteElem(2, { 0 });
	treeOne->pasteElem(3, { 1 });
	treeOne->pasteElem(4, { 0,1 });
	treeOne->pasteElem(5, { 0, 0 });
	treeOne->pasteElem(6, { 1,0 });
	treeOne->pasteElem(7, { 1,1 });
	cout << *treeOne << endl;
	cout << "Count even " << endl << treeOne->countEven() << endl;
	cout << "Positive elem " << endl << treeOne->positiveElem() << endl;
	cout << "Middle arifmetic " << endl << treeOne->middle() << endl;
	vector<int> vec = treeOne->findElem(5);
	cout << "Vector way " << endl;
	for ( int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	delete treeOne;
}