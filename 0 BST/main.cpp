//Dev
/* Version Control : Nothing done , only sample from moodle , add / delete nodes on the BST
		KIS Design [x]
		read/understand this sample [x]
		implement add node to tree [ ]
		implement remove node to tree [ ]
		
*/ 


//#include "stdafx.h"

#include <iostream>
using namespace std;
#include <string> // String Library
#include <string.h>// string functions
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input
#include <limits>
#include <vector>

#include <ctype.h>
#include "colors.h"

class BinTreeNode {
public:
	BinTreeNode(int value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
	int value;
	BinTreeNode* left;
	BinTreeNode* right;

};






BinTreeNode* tree_insert(BinTreeNode* tree, int item) {
	if (tree == NULL)
		tree = new BinTreeNode(item);

	else
		if (item < tree->value)
			if (tree->left == NULL)
				tree->left = new BinTreeNode(item);
			else
				tree_insert(tree->left, item);
		else
			if (tree->right == NULL)
				tree->right = new BinTreeNode(item);
			else
				tree_insert(tree->right, item);
	return tree;

}






void postorder(BinTreeNode* tree) {
	if (tree->left != NULL)
		postorder(tree->left);
	if (tree->right != NULL)
		postorder(tree->right);
	cout << tree->value <<" POST ORDER" << endl;

}








void in_order(BinTreeNode* tree) {
	if (tree->left != NULL)
		in_order(tree->left);
	cout << tree->value <<" IN ORDER" << endl;
	if (tree->right != NULL)
		in_order(tree->right);
}








int main(int argc, char *argv[])
{
	//loadGrafic();

	BinTreeNode* t = tree_insert(0, 7);
	cout<<t->value<<endl;
	tree_insert(t, 10);
	cout<<t->value<<endl;
	tree_insert(t, 5);
	cout<<t->value<<endl;
	tree_insert(t, 2);
	cout<<t->value<<endl;
	tree_insert(t, 35);
	cout<<t->value<<endl;
	tree_insert(t, 3);
	cout<<t->value<<endl;
	tree_insert(t, 4);
	cout<<t->value<<endl;
	tree_insert(t, 11);
	cout<<t->value<<endl;
	in_order(t);
	return 0;
}
