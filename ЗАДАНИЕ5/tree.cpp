#include "tree.h"

#include <iostream>
//1
tree::tree() {
	root = nullptr;
	size = 0;
}

TreeElem::TreeElem(int data, TreeElem* left, TreeElem* rigth) {
	this->data = data;
	this->left = left;
	this->right = rigth;
}

void tree::delTree(TreeElem* root)
{
	if (!root) { return; }
	delTree(root->left);
	delTree(root->right);
	delete root;
}

tree::~tree()
{
	delTree(root);
	root = nullptr;

}

void tree::operator=(tree& x) {
	size = x.size;
	root = x.root;
}

void tree::pasteElem(int elem, std::vector<int> vector) {
	TreeElem* node;
	if (vector.size() == 0) {
		if (root) {
			root->data = elem;
		}
		else {
			root = new TreeElem(elem, nullptr, nullptr);
			size++;
		}
	}
	else {
		node = root;
		for (int i = 0; i < vector.size() - 1; i++) {
			if (!node) { throw VectorException(); }
			if (vector[i] == 0) {
				node = node->left;
			}
			if (vector[i] == 1) {
				node = node->right;
			}
		}
		if (vector.back() == 0) {
			if (node->left) {
				node->left->data = elem;
			}
			else {
				node->left = new TreeElem(elem, nullptr, nullptr);
				size++;
			}
		}
		else {
			if (node->right) {
				node->right->data = elem;
			}
			else {
				node->right = new TreeElem(elem, nullptr, nullptr);
				size++;
			}
		}
	}

}
/*
std::ostream& operator<<(std::ostream& stream, tree& tree) {
	tree.writeTree(stream, tree.root);
	return stream;
}

void tree::writeTree(std::ostream& os, TreeElem* root) {
	if (!root) { return; }
	os << root->data << " ";
	writeTree(os, root->left);
	writeTree(os, root->right);
}*/

std::ostream& operator<<(std::ostream& stream, tree& tree) {
	tree.writeTree(stream, tree.root, 0);
	return stream;
}


void tree::writeTree(std::ostream& os, TreeElem* root, int step) {
	if (!root) { return; }
	for (int i = 0; i < step; i++) {
		os << "\t";
	}
	os << root->data << "\n";
	writeTree(os, root->left, step + 1);
	writeTree(os, root->right, step + 1);
}



//2
int tree::countEven(TreeElem* root) {

	if (!root) { return 0; }
	if (root->data % 2 == 0) { return 1 + countEven(root->left) + countEven(root->right); }
	return countEven(root->left) + countEven(root->right);
}

int tree::countEven() {
	return countEven(root);
}


bool tree::positiveElem(TreeElem* root) {
	if (!root) { return true; }
	if (root->data >= 0) { return positiveElem(root->left) && positiveElem(root->right); }
	return false;
}

bool tree::positiveElem() {
	return positiveElem(root);

}


void tree::delLeaves(TreeElem*& root)
{
	if (!root) { return; }
	if (!root->left && !root->right) {
		delete root;
		root = nullptr;
	}
	else {
		delLeaves(root->left);
		delLeaves(root->right);
	}
}
//
double tree::middle(TreeElem* root) {
	if (!root) { return 0; }
	return root->data + middle(root->left) + middle(root->right);
}

double tree::middle() {
	return middle(root) / size;
}

bool tree::findElem(int x, TreeElem* root, std::vector<int>& vect) {
	if (!root) { return false; }
	if (root->data == x) { return true; }
	vect.push_back(0);
	if (findElem(x, root->left, vect)) {
		return true;
	}
	vect.pop_back();
	vect.push_back(1);
	if (findElem(x, root->right, vect)) {
		return true;
	}
	vect.pop_back();
	return false;
}

std::vector<int> tree::findElem(int x) {
	std::vector<int> res = {};

	if (findElem(x, root, res)) {
		return res;
	}
}




