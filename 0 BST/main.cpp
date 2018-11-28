//Dev:Joao Maia
/* Version Control :
		KIS Design [x]
		read/understand txt file [x]
		cout pre-order node on tree [x]
		improve add node to tree [x]
		implement find node on tree [x]
		implement remove node to tree [x]
		
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
/*
	//
	//Title: 210CT - Programming, Algorithms and Data Structures ,Week 5 - Binary Search Trees, 'Binary Search Tree in C++ File'
	//Provider by:  Dr. Diana Hintea
	//Availability: https://cumoodle.coventry.ac.uk/course/view.php?id=53609&section=13
	//
	//
	*/
class BinTreeNode {
	public:
		//TreeNode Data member
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


struct treeStruct{


	bool checkFreq(auto& path,string word){

		for(int x=0; x <= path.size();x++){
			if(path[x]==word){
				return true;
			}

		}
		return false;
	}

	bool freqList(auto& dupli,auto& list){

		string matrixWords [list.size()][1];
		for(int x=0; x<list.size()-1;x++){

			matrixWords[x][0]=list[x];
			matrixWords[x][1]="1";
			for(int y=0; y<=dupli.size()-1;y++){

				if(dupli[y]==matrixWords[x][0]){

					matrixWords[x][1]=to_string(stoi(matrixWords[x][1])+1);

				}
			}
		cout<<string(2,' ')<<matrixWords[x][0]<<BLUE_TEXT(" = ")<<matrixWords[x][1]<<endl;
		}
		return true;
	}





	
	/*
	//
	//Title: 210CT - Programming, Algorithms and Data Structures ,Week 5 - Binary Search Trees, Lecture Slide(13)
	//Provider by:  Dr. Diana Hintea
	//Availability: https://cumoodle.coventry.ac.uk/course/view.php?id=53609&section=13
	//
	//
	*/
	string bin_tree_find(BinTreeNode* tree, string target){
		vector<string> pathInLine;
		pathInLine.clear();
		cout<<endl;
		cout<<YELLOW_TEXT("Checking path: ")<<target<<endl;
		while(tree!=NULL){
			pathInLine.push_back(tree->value);
			if(tree->value==target){
				cout<<endl;	
				for (int x = 0; x < pathInLine.size(); x++){
					if(x!=pathInLine.size()-1){
						cout<<"->"<<YELLOW_TEXT(<<pathInLine[x]<<);
					}else{
						cout<<"->"<<GREEN_TEXT(<<pathInLine[x]<<);

					}
					cin.clear();
				}
				cout<<endl<<GREEN_TEXT("Yes")<<", Found : "<<tree->value<<endl;
				return tree->value;		
			}else if(tree->value>target){

				cout<<target<<GREEN_TEXT(" < ")<<tree->value<<endl;
				tree=tree->left;
				}else{
					cout<<target<<GREEN_TEXT(" > ")<<tree->value<<endl;
					tree=tree->right;
				}
			
		}

		for (int x = 0; x < pathInLine.size(); x++){
			cout<<"->"<<YELLOW_TEXT(<<pathInLine[x]<<);
		}
		cout<<endl;
		cout<<RED_TEXT("Not")<<" Found :"<<target<<endl;
		return "false";
	}
	/*Pseudo-code 

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



	
	/*
	//
	//Title: 210CT - Programming, Algorithms and Data Structures ,Week 5 - Binary Search Trees, Slide (22)
	//Author:  Dr. Diana Hintea
	//Availability: https://cumoodle.coventry.ac.uk/mod/resource/view.php?id=1916803
	//
	*/
	void in_order(BinTreeNode* tree) {
		if (tree->left != NULL)
			in_order(tree->left);

		cout<<GREEN_TEXT(<<tree->value<<)<<endl;

		if (tree->right != NULL)
			in_order(tree->right);
	}




	/*
	//
	//Title: 210CT - Programming, Algorithms and Data Structures ,Week 5 Lecture - Trees, Slide(24)
	//Author:  Dr. Diana Hintea
	//Availability: https://cumoodle.coventry.ac.uk/mod/resource/view.php?id=1916803
	//
	*/
	void postorder(BinTreeNode* tree) {
		//function provided by Dr.Diana

		if (tree->left != NULL)
			postorder(tree->left);

		if (tree->right != NULL)
			postorder(tree->right);

		cout<<MAGENTA_TEXT(<<tree->value<<)<<endl;


	}

	/*
	//
	//Title: 210CT - Programming, Algorithms and Data Structures ,Week 5 Lecture - Trees, Slide(20)
	//Author:  Dr. Diana Hintea
	//Availability: https://cumoodle.coventry.ac.uk/mod/resource/view.php?id=1916803
	//
	*/
	void preorder(BinTreeNode* tree) {
		//function provided by Dr.Diana
		cout<<MAGENTA_TEXT(<<tree->value<<)<<endl;

		if (tree->left != NULL)
			postorder(tree->left);

		if (tree->right != NULL)
			postorder(tree->right);


	}

};


/*
//
//Title: 210CT - Programming, Algorithms and Data Structures ,Week 5 - Binary Search Trees, 'Binary Search Tree in C++ File'
//Provider by:  Dr. Diana Hintea
//Availability: https://cumoodle.coventry.ac.uk/mod/resource/view.php?id=1791107
//
*/
BinTreeNode* tree_insert(BinTreeNode* tree, auto item) {
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
/*Pseudo-code 

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

*/





/*
//	findMinMax()	deleteNode()
//
//Title: 210CT - Programming, Algorithms and Data Structures ,Week 5 Lecture - Trees, Slide(30-34)
//Author:  Dr. Diana Hintea
//Availability: https://cumoodle.coventry.ac.uk/mod/resource/view.php?id=1916803
//
*/
BinTreeNode* findMinMax(BinTreeNode* tree){
    if(tree==NULL){
    	return NULL;
    }

    while(tree->right != NULL){
        tree = tree->right;
    }
    return tree;
}

BinTreeNode* deleteNode(BinTreeNode* tree, string targetNode){

	cout<<YELLOW_TEXT("Checking ")<<tree->value<<endl;
    if(tree==NULL){
    	return tree;
    }else if(targetNode < tree->value){
    	cout<<RED_TEXT(<<targetNode<<)<<" < "<<tree->value<<endl;
    	tree->left = deleteNode(tree->left, targetNode);}
    else if (targetNode> tree->value){
    	cout<<RED_TEXT(<<targetNode<<)<<YELLOW_TEXT(" > ")<<tree->value<<endl;
    	tree->right = deleteNode(tree->right, targetNode);
    }
    else{

		if(tree->right == NULL && tree->left == NULL){ //Node R L NULL
			cout<<RED_TEXT("Replaced by ")<<tree->value<<endl;
	        delete tree;
	        tree = NULL;
	    }else if(tree->right == NULL){//Node R NULL
	        BinTreeNode* temp = tree;
	        tree= tree->left;
	        
	        delete temp;
	    }else if(tree->left == NULL){//Node L NULL
	        BinTreeNode* temp = tree;
	        tree= tree->right;
	        delete temp;
	    }else{
	    		cout<<GREEN_TEXT("Word found and deleted.")<<endl;
	    		cout<<"Find new minMax Node from "<<RED_TEXT(<<tree->value<<)<<endl;
	            BinTreeNode* temp = findMinMax(tree->left);
	            tree->value = temp->value;
	    		cout<<GREEN_TEXT("New node founded: ")<<tree->value<<endl;
	            tree->left = deleteNode(tree->left, temp->value);
	        }
	}
    return tree;
}



void pressENTER2continue(){
	cin.ignore(INT_MAX,'\n');	
	cout<<endl;
	cout<<" Press "<<GREEN_TEXT("ENTER")" to continue\r";
	cin.clear();
	if (cin.get() == '\n') {}else{cin.ignore(INT_MAX,'\n'); pressENTER2continue();};

}


int main()
{
	int op;
	string word;
	ifstream file;
	treeStruct tree;
	vector<string> dupliWord;

  	file.open ("text.txt");
		file>>word;
		BinTreeNode* t = tree_insert(0, word);

		t->listWord.push_back(word);

		while(file>>word){
			cout<<BLUE_TEXT("Inserting ->")<<word<<endl;

			if(tree.checkFreq(t->listWord,word)==true){
				cout<<RED_TEXT("Duplicate word found: ")<<word<<endl;
				dupliWord.push_back(word);
			}else{

				t->listWord.push_back(word);
				tree_insert(t,word);
				}
		}
  	file.close();

	pressENTER2continue();
  	cout<<RED_TEXT("Frequency List : ")<<endl;
  	tree.freqList(dupliWord,t->listWord);

  	pressENTER2continue();
  	cout<<RED_TEXT("Pre Order : ")<<endl;
  	tree.preorder(t);

	pressENTER2continue();
  	cout<<RED_TEXT("Find Node : ");
  	word.clear();
  	getline(cin,word);
  	tree.bin_tree_find(t,word);

	pressENTER2continue();
  	cout<<RED_TEXT("DELETE Node : ")<<endl;
  	word.clear();
  	getline(cin,word);
  	deleteNode(t,word);
	pressENTER2continue();


  	//Menu choosing 
  	//Frequency of words
  	//orders of words
  	//Find word and output path travel
  	//Delete word and output path travel
  	bool exit=false;
  	while(exit!=true){
	  	cout<<endl;
			cout<<BLUE_TEXT("		  BST ALGORITHM ")<<endl;
			cout<<YELLOW_TEXT("		▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄")<<endl;
			cout<<endl;
			cout<<endl;
			cout<<CYAN_TEXT("		0 - Frequency List")<<endl;
			cout<<GREEN_TEXT("		1 - Pre Order")<<endl;
			cout<<GREEN_TEXT("		2 - Post Order")<<endl;
			cout<<GREEN_TEXT("		3 - In Order")<<endl;
			cout<<BLUE_TEXT("		4 - Find Node")<<endl;
			cout<<RED_TEXT("		5 - Delete Node")<<endl;
			cout<<YELLOW_TEXT("		6 - Quit")<<endl;
			cout<<endl;
			cout<<YELLOW_TEXT("		▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄")<<endl;
			cout<<endl;
			cout<<"Choose an option. \t";
		cin>>op;
		while (cin.fail() || op>7){

	        cin.clear(); // clear input buffer to restore cin to a usable state
	        cin.ignore(INT_MAX, '\n'); // ignore last input
	        cout << RED_TEXT("Not Available")<<endl;
	        cout << "Choose "<<GREEN_TEXT("valid")<<" an option"<<endl;
	        cin >> op;
		}
		switch(op){


			case 0:{
			  	cout<<RED_TEXT("Frequency List : ")<<endl;
			  	tree.freqList(dupliWord,t->listWord);
				pressENTER2continue();

				break;}
			case 1:{

			  	cout<<RED_TEXT("Pre Order : ")<<endl;
			  	tree.preorder(t);
				pressENTER2continue();
				break;
			}
			case 2:{

			  	cout<<RED_TEXT("Post Order : ")<<endl;
			  	tree.postorder(t);
				pressENTER2continue();
				
				break;
			}
			case 3:{

			  	cout<<RED_TEXT("In Order : ")<<endl;
			  	tree.in_order(t);
				pressENTER2continue();
				
				break;
			}
			case 4:{
				cin.ignore(INT_MAX,'\n');	
			  	cout<<RED_TEXT("Find Node : ");
			  	word.clear();
			  	getline(cin,word);
			  	tree.bin_tree_find(t,word);
				pressENTER2continue();
				
				break;
			}
			case 5:{
				cin.ignore(INT_MAX,'\n');	
			  	cout<<RED_TEXT("DELETE Node : ")<<endl;
			  	word.clear();
			  	getline(cin,word);
			  	deleteNode(t,word);
				pressENTER2continue();
				break;
			}
			case 6:{
				exit=true;break;
			}
			default:{
				break;
			}
		}

  	}





  	delete t;
	return 0;
}
