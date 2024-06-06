#pragma once
#include "vector"
#include <iostream>

struct VectorException {};

struct TreeElem {
	int data;
	TreeElem* left;
	TreeElem* right;
	TreeElem(int data, TreeElem* left, TreeElem* rigth);
};

class tree
{
private:
	TreeElem* root;
	int size;
	void delTree(TreeElem* root);
	//void writeTree(std::ostream& os, TreeElem* root);
	void writeTree(std::ostream& os, TreeElem* root, int step);
	int countEven(TreeElem* root);
	bool positiveElem(TreeElem* root);
	double middle(TreeElem* root);
	bool findElem(int x, TreeElem* root, std::vector<int>& vect);
public:
	tree();
	
	~tree();
	void operator=(tree& x);
	void pasteElem(int elem, std::vector<int> vector);
	int countEven();
	bool positiveElem();
	double middle();
	std::vector<int> findElem(int x);
	friend std::ostream& operator<<(std::ostream& stream, tree& tree);
	void delLeaves(TreeElem*& root);
};

