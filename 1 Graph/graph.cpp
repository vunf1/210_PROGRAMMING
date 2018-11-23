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

	

class graph{
public:
	vector<int> vert_node;	
	/*
	https://www.geeksforgeeks.org/extract-integers-string-c/
	Author:  Prakhar Agrawal

	*/
	void extractIntegerWords(string str) 
	{ 
	    stringstream ss;     
	  
	    /* Storing the whole string into string stream */
	    ss << str; 
	  
	    string temp; 
	    int found; 
	 	
	    /* Running loop till the end of the stream */
	    while (!ss.eof()) { 
	  
	        /* extracting word by word from stream */
	        ss >> temp; 
	  
	        /* Checking the given word is integer or not */
	        if (stringstream(temp) >> found) {
	        	this->vert_node.push_back(found);
	          }
	        temp = ""; 
	    } 
	} 




/*
// ADjancyList or Matrix - Probably implemnt second
//
*/
	void splitVertice2Edge(auto& inputVerList){

	stringstream ss;
	int matrix[vert_node.size()][vert_node.size()];

	

		ss << inputVerList; 
	  
	    char temp[2]; 

	 	
	    /* Running loop till the end of the stream(string) */
	    while (!ss.eof()) { 
	  
	        /* extracting char by char to the stream */
	        ss >> temp; 
	        cout<<"TEMP[0]:"<<temp[0]<<endl;
	        cout<<"TEMP[1]:"<<temp[1]<<endl;
	        cout<<"TEMP[2]:"<<temp[2]<<endl;
	        matrix[temp[0]][temp[2]]=1;

	  		
	  		for(int x=0;x<=2;x++ ){
	  		temp[x]=' ';
	  		}
	    }



	for(int x=0;x<=this->vert_node.size()-1;x++ ){

		for(int y=0;y<=this->vert_node.size()-1;y++ ){
			cout<<matrix[x][y];		
		}
		cout<<endl;
	}





	}



	void splitIntoVert(auto& vertList, auto& delimiter ){


		/*
		/	split the string use [SPACE](iss) to create substrings and then add to the vector 
		/	Problem found:
		/		Difficult to manipulate after insert into a vector to find duplicate values
		//https://www.geeksforgeeks.org/program-extract-words-given-string/


	unsigned int counter=0;
	istringstream iss(vertList);
	    copy(istream_iterator<unsigned int>(iss),
	    istream_iterator<unsigned int>(),
	    back_inserter(this->vert_node));
		*/



	    	for(int x=0;x<=this->vert_node.size()-1;x++){
	    		cout<<this->vert_node[x]<<endl;


	    	}
	    /*
	    http://www.cplusplus.com/forum/beginner/147920/
	    Author: Esslercuffi
		Nov 15, 2014 at 7:45pm
			'Before pushing the name and scores inside the while loop, insert another loop that will run through the current vectors and check if the entered name already exists. If it exists, display error message. If it doesn't, push the new values onto vectors.'
	    */



	}



};



int main(){

	string numVert;	
	graph gra;
	cout<<string(10,' ')<<GREEN_TEXT("Identify the vertices")<<endl;
	cout<<string(5,' ')<<GREEN_TEXT("Seperate by space example -> ")<<RED_TEXT("1 2 3 4 5 6")<<endl;
	getline(cin,numVert);

	gra.extractIntegerWords(numVert);

	int graphMatrix[gra.vert_node.size()-1][gra.vert_node.size()-1];

	

	cout<<string(10,' ')<<GREEN_TEXT("Vertices Identified")<<endl;
	cout<<string(10,' ')<<GREEN_TEXT(" -> ");
	for(int x=0;x<=gra.vert_node.size()-1;x++ ){
		cout<<gra.vert_node[x]<<" ";
	}
	cout<<endl;
	numVert.empty();
	cout<<string(10,' ')<<GREEN_TEXT("Identify the edges")<<endl;
	cout<<string(5,' ')<<GREEN_TEXT("Seperate by space (Vertice),(Edge) -> ")<<RED_TEXT("1,2 2,3")<<endl;

	getline(cin,numVert);
	/*
	for(int x=0;x<=gra.vert_node.size()-1;x++){
		
		for(int y=0;y<=gra.vert_node.size()-1;y++){

			graphMatrix[x][y]=0;
			cout<<graphMatrix[x][y];
		}cout<<endl;
	}*/
	gra.splitVertice2Edge(numVert);

/*
	for(int x=0;x<=this->vert_node.size()-1;x++){
		
		for(int y=0;y<=this->vert_node.size()-1;y++){
			cout<<graphMatrix[x][y];


		}

		cout<<endl;
	}

*/








	return 0;
}