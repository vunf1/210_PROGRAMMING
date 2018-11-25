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
#include <algorithm>
#include <string> // String Library
#include <string.h>// string functions
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input
#include <limits>
#include <vector>


// ioctrl provides device-specific low-level control
//need for get max width and height
#include <sys/ioctl.h>
#include <stdio.h> //Library outdated from C, helps preprocessor the compiler
//function getMax...

using namespace std;


#include "colors.h"

	

/*
// Author: John T
//  Jun 21 2009 at 1:40
//	link: https://stackoverflow.com/a/1022961
*/
int getmaxHeight(){


    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w); 
	return w.ws_row;

}
int getmaxWidth(){
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
	return w.ws_col;

}

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
                	if(x==y){
                
                    	matrix[x][y] = -1;


                	}else{
                
                    	matrix[x][y] = 0;

                	}
                }
            }
	}





	
	bool addEdge(int oriVertice,int edgeVertice){
		if(oriVertice == edgeVertice){
			return false;
		}

		for(int x=0;x<=this->vert_node.size()-1;x++){	
					for(int y=0;y<=this->vert_node.size()-1;y++){
						//cout<<"WOW:"<<vert_node[x]<<"-"<<vert_node[y]<<endl;
						if(oriVertice==this->vert_node[x] && edgeVertice==this->vert_node[y]){
							//cout<<"addEdge:"<<vert_node[x]<<"-"<<vert_node[y]<<endl;
							if(this->matrix[x][y]==1){
								return false;
							}
							//unweight graph
							this->matrix[x][y]=1;
							this->matrix[y][x]=1;
						}

					}
			}
		return true;
	}





	/*
	//https://www.geeksforgeeks.org/extract-integers-string-c/
	//Author:  Prakhar Agrawal
	//
	//Use this function for identify edges - 1 more argument as 'Option'=1(activateExtractionInt4Vector) 0(activateExtractionInt2Edges==1)
	*/
	bool extractIntegerWords(string str,int op) 
	{ 
	    stringstream ss;     
	  
	    /* Storing the whole string into string stream */
	    ss << str; 
	  
	    string temp; 
	    int found; 
	    vector <int> send2Add;
	 	
	    /* Running loop till the end of the stream */
	    while (!ss.eof()) { 
	  
	  
	        /* Checking the given word is integer or not */
	        if(op==0){
	        /* extracting word by word from stream */
	        	ss >> temp; 
		        if (stringstream(temp) >> found) {
		        	this->vert_node.push_back(found);
		          }
		        temp = "";

	        }
	        if(op==1){
	        /* extracting word by word from stream */
	        	ss >> temp; 
		        if (stringstream(temp) >> found) {

		        	send2Add.push_back(found);
		          }

		        temp = "";
	        	
	        } 
	    }
	    if(op==1){

    		if(find(vert_node.begin(), vert_node.end(), send2Add[0]) != vert_node.end() && find(vert_node.begin(), vert_node.end(), send2Add[1]) != vert_node.end() ) {
	    			if(send2Add[0]==send2Add[1]){

						cout<<RED_TEXT("NOT ADDED - Same Vertice")<<endl;
	    			}else{
				    	if(addEdge(send2Add[0],send2Add[1])==true){

		    				cout<<GREEN_TEXT("ADDED")<<endl;
				    		
				    	}else{
				    		cout<<RED_TEXT("ALREADY CONNECTED")<<endl;
				    	}	

	    			}
		    	} else {
					cout<<RED_TEXT("NOT ADDED - Not a Vertice")<<endl;
				    return false;
			}
	    } 
	} 

/*
// extract from 
//
*/
	bool splitVertice2Edge(auto& inputVerList){

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
	        
	        //addEdge(temp[0],temp[2]);

	        /*if(addEdge(temp[0],temp[2])==true){continue;}else{cout<<temp[0]<<" or "<<temp[2]<<" is invalid for this matrix"<<endl; return false;}
	  		*/
	  		for(int x=0;x<=2;x++ ){
	  		temp[x]=' ';
	  		}
	    }


	}



	void showMatrix(){

		/*for(int x=0;x<=this->vert_node.size()-1;x++){
			if(vert_node[0]){
			cout<<string((getmaxWidth()/getmaxWidth())+3,' ')<<vert_node[x];

			}else{

			cout<<string((getmaxWidth()/getmaxWidth())+1,' ')<<vert_node[x];

			}
		}
		cout<<endl;
*/
		for(int x=0;x<=this->vert_node.size()-1;x++){
			//cout<<string((getmaxWidth()/getmaxWidth())+1,' ')<<vert_node[x];
			for(int y=0;y<=this->vert_node.size()-1;y++){
				cout<<string((getmaxWidth()/getmaxWidth())+1,' ')<<matrix[x][y];
			}
			cout<<endl;
		}

	}




	bool isConnectedEdge(int vertice,int edgeTarget){
		//Check if vertices are connected;


		for(int x=0;x<=this->vert_node.size()-1;x++){	
					for(int y=0;y<=this->vert_node.size()-1;y++){
						//cout<<"WOW:"<<vert_node[x]<<"-"<<vert_node[y]<<endl;
						if(vertice==this->vert_node[x] && edgeTarget==this->vert_node[y]){
							//cout<<"addEdge:"<<vert_node[x]<<"-"<<vert_node[y]<<endl;
							if(this->matrix[x][y]==1){
								return true;
							}
						}

					}
			}
		return false;

	}


	bool isConnectedFull(){
		//DO
		//Check if grapg is strongly connected (all vertices have a edge)
		//create variable to check a bool for each vertice if found a 1 mean have connection with other and push to the variable as visited and go next to other vertice if a vertice is missing mean the graph is not strongly connected so compare at the end the variable with vert_node to see if is some vertice is missing


		for(int x=0;x<=this->vert_node.size()-1;x++){	
					for(int y=0;y<=this->vert_node.size()-1;y++){
						//cout<<"WOW:"<<vert_node[x]<<"-"<<vert_node[y]<<endl;
						if(vertice==this->vert_node[x] && edgeTarget==this->vert_node[y]){
							//cout<<"addEdge:"<<vert_node[x]<<"-"<<vert_node[y]<<endl;
							if(this->matrix[x][y]==1){
								return true;
							}
						}

					}
			}
		return false;

	}



};



int main(){


	string numVert;	
	graph gra;
	cout<<string(getmaxWidth()/3,' ')<<GREEN_TEXT("Identify the vertices")<<endl;
	cout<<string(getmaxWidth()/4,' ')<<GREEN_TEXT("Seperate by space example -> ")<<RED_TEXT("1 2 3 4 5 6")<<endl;
	getline(cin,numVert);

	
	//DINAMIC
	gra.extractIntegerWords(numVert,0);
	
	//STATIC
	//gra.extractIntegerWords("11 22 33",0);

	gra.matrixGraph();
	gra.showMatrix();

	cout<<string(getmaxWidth()/3,' ')<<GREEN_TEXT("Vertices Identified")<<endl;
	cout<<string(getmaxWidth()/4,' ')<<GREEN_TEXT(" -> ");
	for (int x=0;x<=gra.vert_node.size()-1; x++)
	{
		cout<<" "<<gra.vert_node[x];
	}
	cout<<endl;
	cout<<string(getmaxWidth()/3,' ')<<GREEN_TEXT("Identify the edges")<<endl;
	cout<<string(getmaxWidth()/6,' ')<<GREEN_TEXT("Seperate by space (Origin_Vertice) (Vertice_Edge) -> ")<<RED_TEXT("1 2")<<endl;
	cout<<string(getmaxWidth()/3,' ')<<GREEN_TEXT("then press ENTER")<<endl;



	numVert.empty();

	getline(cin,numVert);

	//gra.splitVertice2Edge(numVert);
	while(numVert!=""){

		gra.extractIntegerWords(numVert,1);
		getline(cin,numVert);

	}


	
	gra.showMatrix();
	if(gra.isConnectedEdge(2,1)==true){

		cout<<GREEN_TEXT("Yes, That vertice is connected")<<endl;
	}else{

		cout<<RED_TEXT("No, That vertice isn't connected")<<endl;
	}

	if(gra.isConnectedFull()==true){

		cout<<GREEN_TEXT("Yes, This graph is strongly connected")<<endl;
	}else{

		cout<<RED_TEXT("No, This graph isn't strongly connected")<<endl;
	}





	return 0;
}