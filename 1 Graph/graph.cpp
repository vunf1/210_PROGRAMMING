/*GRAPH
DEV:
	Version Control:
		user input [x]
		handle user input [x]
		create adjant table for user path input [ ]
		function saying if that vertice is connect to other [ ]



		some bugus, output of same thing dont know yet -> tomorrow fix 
 */

#include <iostream>
#include <fstream> //filestram

#include <iterator>//for split string into words separelaty to compare with a vector
#include <sstream>//pre-'function' (make iterator easy to read) 
#include <cstring>

#include <string> // String Library
#include <string.h>// string functions
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input
#include <limits>
#include <vector>
using namespace std;


#include "colors.h"
vector<int> vert_node;
class graph{
public:




	void splitVert(auto& vertList ){

	//https://www.geeksforgeeks.org/program-extract-words-given-string/
	istringstream iss(vertList);
	    copy(istream_iterator<unsigned int>(iss),
	    istream_iterator<unsigned int>(),
	    back_inserter(vert_node));

	    

		/*for(int x=0;x<=vert_node.size()-1;x++){
	    	cout<<vert_node[x]<<endl;
	    }*/

	}



};




int main(){
	unsigned int node;
	string numVert;
	graph gra;
	cout<<string(10,' ')<<GREEN_TEXT("Identify the vertices")<<endl;
	cout<<string(5,' ')<<GREEN_TEXT("Seperate by space example -> ")<<RED_TEXT("1 2 3 4 5 6")<<endl;
	getline(cin,numVert);

	while (cin.fail())
	{
		cin.clear(); // clear input buffer to restore cin to a usable state
		cin.ignore(INT_MAX, '\n'); // ignore last input
		cout<<string(10,' ')<<GREEN_TEXT("Identify the nodes ?")<<endl;
		cout<<string(5,' ')<<GREEN_TEXT("Seperate by space example -> ")<<RED_TEXT("1 2 3 4 5 6")<<endl;
		getline(cin,numVert);
	}

	gra.splitVert(numVert);

	int graphMatrix[vert_node.size()][vert_node.size()];

	for(int x=0;x<=vert_node.size();x++){

		graphMatrix[x+1][0]=vert_node[x];

		for(int y=0;y<=vert_node.size();y++){

			graphMatrix[0][y+1]=vert_node[y];
		}

	}


	for(int x=0;x<=vert_node.size();x++){

		for(int y=0;y<=vert_node.size();y++){

			cout<<graphMatrix[x][y]<<endl;
		}

	}






	return 0;
}