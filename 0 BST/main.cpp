//Dev
/* Version Control :
		KIS Design [x]
		read/understand this sample [x]
		implement add node to tree [x]
		implement find node on tree [x]
		implement remove node to tree [ ]
		
*/ 


//#include "stdafx.h" no work on linux - windows library

#include <iostream>
#include <string> // String Library
#include <string.h>// string functions
#include <climits> //can fix possible bugs from User Input
#include <limits>
#include <array>
#include <vector>
#include <fstream>

#include "colors.h"

using namespace std;

class BinTreeNode {
	//class provided by Dr.Diana
	public:
		BinTreeNode(auto& value) {
			this->value = value;
			this->left = NULL;
			this->right = NULL;
		}
		string value;
		BinTreeNode* left;
		BinTreeNode* right;
		vector <string> listWord;


};


struct wordCss{


	bool checkFreq(auto& path,string word)
	{

		for(int x=0; x <= path.size();x++)
		{
			if(path[x]==word)
			{
				return true;
			}

		}
		return false;
	}

	bool freqList(auto& dupli,auto& list){


		string matrixWords [list.size()][1];

		for(int x=0; x<list.size();x++){

			matrixWords[x][0]=list[x];
			matrixWords[x][1]="1";
			for(int y=0; y<=dupli.size()-1;y++){

				if(dupli[y]==matrixWords[x][0]){

					matrixWords[x][1]=to_string(stoi(matrixWords[x][1])+1);

				}
			}
			//Segment fault in - need for solution -
		cout<<matrixWords[x][0]<<BLUE_TEXT("=")<<matrixWords[x][1]<<endl;
		}
		return true;
	}

	// travel until found correct
	string bin_tree_find(BinTreeNode* tree, string target){
		cout<<"Find: "<<target<<endl;
		while(tree!=NULL){
			cout<<"->"<<YELLOW_TEXT(<<tree->value<<);
			if(tree->value==target){
				cout<<endl;
				cout<<GREEN_TEXT("Found :")<<tree->value<<endl;
				return tree->value;		
			}else if(tree->value>target){
				tree=tree->left;
				}
				else{
					tree=tree->right;
				}
			
		}

		cout<<endl;
		cout<<RED_TEXT("Not Found :")<<target<<endl;
		return "false";
	}



	/**
		* function provided by Dr.Diana
		* Order input in the tree
		*/
	void in_order(BinTreeNode* tree) {
		if (tree->left != NULL)
			in_order(tree->left);

		cout<<GREEN_TEXT(<<tree->value<<)<<endl;

		if (tree->right != NULL)
			in_order(tree->right);
	}




	void postorder(BinTreeNode* tree) {
		//function provided by Dr.Diana

		if (tree->left != NULL)
			postorder(tree->left);

		if (tree->right != NULL)
			postorder(tree->right);

		cout<<MAGENTA_TEXT(<<tree->value<<)<<endl;


	}

	void preorder(BinTreeNode* tree) {
		//function provided by Dr.Diana
		cout<<MAGENTA_TEXT(<<tree->value<<)<<endl;

		if (tree->left != NULL)
			postorder(tree->left);

		if (tree->right != NULL)
			postorder(tree->right);


	}

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




void pressENTER2continue(){

	cin.clear();
	cin.get();

}


int main(int argc, char *argv[])
{
	int op;
	string word;
	ifstream file;
	wordCss funcWord;
	vector<string> dupliWord;

  	file.open ("text.txt");
		file>>word;
		BinTreeNode* t = tree_insert(0, word);

		t->listWord.push_back(word);

		while(file>>word){
			cout<<BLUE_TEXT("Inserting ->")<<word<<endl;

			if(funcWord.checkFreq(t->listWord,word)==true){
				cout<<RED_TEXT("Duplicate word found: ")<<word<<endl;
				dupliWord.push_back(word);
			}else{

				t->listWord.push_back(word);
				tree_insert(t,word);
				}
		}
  	file.close();


	pressENTER2continue();

  	//Menu choosing 
  	//Preorder of words
  	//Inorder of words
  	//Postorder of words
  	//Frequency of words
  	//Find word and out path travel

  	cout<<RED_TEXT("Pre Order : ")<<endl;
  	funcWord.preorder(t);


	pressENTER2continue();
	//not needed
  	cout<<RED_TEXT("In Order : ")<<endl;
  	funcWord.in_order(t);

	pressENTER2continue();
	//not needed
  	cout<<RED_TEXT("Post Order : ")<<endl;
  	funcWord.postorder(t);

	pressENTER2continue();
  	funcWord.bin_tree_find(t,"traversal");
  	funcWord.bin_tree_find(t,"cynical");

	pressENTER2continue();
  	cout<<RED_TEXT("Frequency List : ")<<endl;
  	funcWord.freqList(dupliWord,t->listWord);

	return 0;
}
