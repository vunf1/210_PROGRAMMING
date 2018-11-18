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

/*
questions:
where tree is saved?
*/




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

/*

Pseudo-code 

Insert node

BIN-TREE-INSERT(tree,item)
IF tree = Ø
	tree ← Node(item)
ELSE IF tree.value > item
	IF tree.left = 0
		tree.left ← Node(item)
	ELSE BIN-TREE-INSERT(tree.left,item)
ELSE IF tree.right = 0
	tree.right ← Node(item)
ELSE BIN-TREE-INSERT(tree.right,item)
RETURN r 


Finding node

BIN-TREE-FIND(tree,target)
R ← tree
WHILE r ≠ Ø
	IF r.value = target
		RETURN r (or TRUE)
	ELSE IF r.value > target
		r ← r.left
		ELSE
			r ← r.right
RETURN FALSE 

*/

bool bin_tree_find(BinTreeNode* tree, string target){
	while(tree!=NULL){
		if(tree->value==target){
			return true;		
		}else if(tree->value>target){
			tree=tree->left;
			}
			else{
				tree=tree->right;
			}
		
	}
	return false;
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
	    		if(counter==0){
	    			BinTreeNode* t = tree_insert(0, word);
	    			counter=counter+1;

  				}else{
					
					tree_insert(t, word);
	    			counter=counter+1;

  				}

	    		cout<<word<<endl;
	 		}

    		//cout<<path[0]<<endl;;
		}
  	file.close();
  	//in_order(t);
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
