//Dev
/* Version Control : Nothing done , only sample from moodle , add / delete nodes on the BST
		KIS Design [x]
		read/understand this sample [x]
		implement add node to tree [ ]
		implement remove node to tree [ ]
		
*/ 


//#include "stdafx.h"

#include <iostream>
#include <string> // String Library
#include <string.h>// string functions
#include <climits> //can fix possible bugs from User Input
#include <limits>
#include <vector>
#include <fstream>

#include "colors.h"

using namespace std;

class BinTreeNode {
	//class provided by Dr.Diana
public:
	BinTreeNode(auto value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
	string value;
	BinTreeNode* left;
	BinTreeNode* right;

};






BinTreeNode* tree_insert(BinTreeNode* tree, auto item) {
	//function provided by Dr.Diana
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
	//function provided by Dr.Diana
	if (tree->left != NULL)
		postorder(tree->left);
	if (tree->right != NULL)
		postorder(tree->right);


}







/**
	* function provided by Dr.Diana
	* Order input in the tree
	*/
void in_order(BinTreeNode* tree) {
	
	if (tree->left != NULL)
		in_order(tree->left);

	if (tree->right != NULL)
		in_order(tree->right);
}








int main(int argc, char *argv[])
{

	string word;
	int counter=0;
	BinTreeNode* t;
	//http://www.cplusplus.com/reference/fstream/ifstream/
	ifstream file;
  	file.open ("text.txt");
  		if (file.is_open()) 
  		{
  			while (!file.eof()) {
  				
	    		file>>word;
	    		//path.push_back(word);
	    		cout<<word<<endl;
	    		if(counter==0){

					tree_insert(0, word);
	    			counter=counter+1;

  				}else{
					
					tree_insert(t, word);
	    			counter=counter+1;

  				}
	 		}

    		//cout<<path[0]<<endl;;
		}
  	file.close();
  	in_order(t);
  	cout<<counter<<endl;
/*
	BinTreeNode* t = tree_insert(0, 7);
	tree_insert(t, 10);
	tree_insert(t, 5);
	tree_insert(t, 2);
	tree_insert(t, 35);
	tree_insert(t, 3);
	tree_insert(t, 4);
	tree_insert(t, 11);
	in_order(t);*/
	return 0;
}
