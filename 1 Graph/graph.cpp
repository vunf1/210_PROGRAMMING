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
    int **matrix;
    
    /*
    // Inicialize matrix4Graph
    //
    */	
	void matrixGraph(){

            matrix = new int* [vert_node.size()];
            for (int x = 0; x < vert_node.size(); x++){

                matrix[x] = new int [vert_node.size()];
                
                for(int y = 0; y < vert_node.size(); y++){
                
                    matrix[x][y] = 0;
                }
            }
	}

	/*
	//https://www.geeksforgeeks.org/extract-integers-string-c/
	//Author:  Prakhar Agrawal
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
// extract from 
//
*/
	void splitVertice2Edge(auto& inputVerList){

	stringstream userInput;


		userInput << inputVerList; 
	  
	    char temp[2]; 
	 	
	    /* Run loop until eo(f)->stream(string) */
	    while (!userInput.eof()) { 
	  
	        /* extract char by char to the stream */
	        userInput >> temp; 
	        cout<<"TEMP[0]:"<<temp[0]<<endl;
	        cout<<"TEMP[1]:"<<temp[1]<<endl;
	        cout<<"TEMP[2]:"<<temp[2]<<endl;

	  		
	  		for(int x=0;x<=2;x++ ){
	  		temp[x]=' ';
	  		}
	    }


	}
	bool addEdge(int oriVertice,int edgeVertice){
		if(oriVertice<0 || edgeVertice<0){
			return false;
		}else{
			for(int x=1;x<=this->vert_node.size();x++){
					if(oriVertice==this->vert_node[x]){
						for(int y=1;y<=this->vert_node.size();y++){
							if(edgeVertice==this->vert_node[y]){
								matrix[x][y]=1;
							}

						}
					}
				}

			}




	}


	void showMatrix(){

		for(int x=0;x<=this->vert_node.size()-1;x++){
			for(int y=0;y<=this->vert_node.size()-1;y++){
				cout<<matrix[x][y];
			}
			cout<<endl;
		}

	}
	void isConnected(int target){

	}	




	void splitIntoVert(auto& vertList, auto& delimiter ){
		/*
		// Not in use.
		// This reference helps me a with logic for the graph.
		*/

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
	gra.matrixGraph();
	gra.showMatrix();

	cout<<string(10,' ')<<GREEN_TEXT("Vertices Identified")<<endl;
	cout<<string(10,' ')<<GREEN_TEXT(" -> ");
	for (int x=0;x<=gra.vert_node.size()-1; x++)
	{
		cout<<" "<<gra.vert_node[x];
	}
	cout<<endl;
	numVert.empty();
	cout<<string(10,' ')<<GREEN_TEXT("Identify the edges")<<endl;
	cout<<string(5,' ')<<GREEN_TEXT("Seperate by space (Origin_Vertice),(Vertice_Edge) -> ")<<RED_TEXT("1,2 2,3")<<endl;
	getline(cin,numVert);
	gra.splitVertice2Edge(numVert);
	//while(gra.splitVertice2Edge(numVert)==false){
	

		//getline(cin,numVert);

	//}






	return 0;
}