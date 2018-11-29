/*GRAPH weighted
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
#include<bits/stdc++.h> 

// ioctrl provides device-specific low-level control
//need for get max width and height
#include <sys/ioctl.h>
#include <stdio.h> //Library outdated from C, helps preprocessor the compiler
//function getMax...

using namespace std;


#include "colors.h"

	


void sendToTxT(string text){
	fstream file;
	file.open("travelOutput.txt", fstream::app);
		file<<text<<"\n";

	file.close();
}

/*
// 	Author: John T
//  Date:Jun 21 2009 at 1:40
//	Availability: https://stackoverflow.com/a/1022961
*/
int getmaxHeight(){

    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w); 
	return w.ws_row;

}
/*
// 	Author: John T
//  Date:Jun 21 2009 at 1:40
//	Availability: https://stackoverflow.com/a/1022961
*/
int getmaxWidth(){
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
	return w.ws_col;

}

vector <int> send2Add;

class graph{
public:
	vector<int> vert_node;//Vertice Unique List
    int **matrix;
    int **adjList_;
    //look lists and see ig possible list[x] can be identify to then usa as adjancylist[x]-[y(size variable)]
    
    
    /*
    // Title: Pointer-to-pointer dynamic two-dimensional array
    // Author: Alexander Shukaev
    // Date: Apr 13/14 at 05:52pm 
    // Availability: https://stackoverflow.com/a/16001894/10700835
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





	
	bool addEdge(int oriVertice,int edgeVertice, int weight){

		//indirected way and weight
		//this type of graph is weighted/undirected 2--[w]--1 && 1--[w]--2

		for(int x=0;x<=this->vert_node.size()-1;x++){	
					for(int y=0;y<=this->vert_node.size()-1;y++){
						//cout<<"WOW:"<<vert_node[x]<<"-"<<vert_node[y]<<endl;
						if(oriVertice==this->vert_node[x] && edgeVertice==this->vert_node[y]){
							//cout<<"addEdge:"<<vert_node[x]<<"-"<<vert_node[y]<<endl;
							if(matrix[x][y]!=0){
								return false;
							}else{
								//weight graph/ indirected
								this->matrix[x][y]=weight;
								this->matrix[y][x]=weight;

							    cout<<"adj["<<x<<"].push_back("<<vert_node[y]<<")"<<endl; 
							    cout<<"adj["<<y<<"].push_back("<<vert_node[x]<<")"<<endl;

								return true;	
							}
						}
					}

				}
	}


	bool creatAdjList(){
		cout<<"Creating Adjacency List"<<endl;

	  	adjList_ = new int* [vert_node.size()];

      	for (int x = 0; x < vert_node.size(); x++){

            adjList_[x] = new int [vert_node.size()];
            
            for(int y = 0; y < vert_node.size(); y++){

				adjList_[x][y]=0; 

            	if(matrix[x][y]!=0 && matrix[x][y]!=-1 ){
            		adjList_[x][y]=vert_node[y]; 

					cout<<"Vertice "<<vert_node[x]<<RED_TEXT(" connected to Vertice ")<<vert_node[y]<<" Y Po.->"<<y<<endl;
				}
            }
            cout<<endl;
        }

	}
 void showAdjList(){

		cout<<"Adjacency List:"<<endl;

        for (int x = 0; x < vert_node.size(); ++x){
        	cout<<" Vertice "<<vert_node[x]<<" -> ";
        	for (int y = 0; y < vert_node.size(); ++y){
        		if(this->adjList_[x][y]){
        			cout<<this->adjList_[x][y]<<" ";
        		}

        	
        	}
        	cout<<endl;
        }
 }




	/*
	//
	//Title: Extract all integers from string in C++ - GeeksforGeeks
	//Author:  Prakhar Agrawal
	//Availability: https://www.geeksforgeeks.org/extract-integers-string-c/
	//
	//
	//Use this function to handle user input
	*/
	bool splitInputStr(string str,int op) 
	{ 

	    stringstream ss;     
	  
	    ss << str; 
	  
	    string temp; 
	    int found; 
	 	
		string ans;

	 	send2Add.clear();
	    /* Handle Input*/
	    // operation
	    // 0 -  Input vertices list / matrix size
	    // 1 - 	Input weight input handle true vertices / expected to have 3 int's
	 	// 		--0 (Vertice Ori)	--1 (Vertice End)	--2 (Weight)			
	    // 2 -	Input 2 vertices
	    while (!ss.eof()) { 
	  
	  
	        if(op==0){
	        	ss >> temp; 
		        if (stringstream(temp) >> found){
		        	if(found<0){
		        		return false;
			        }else if(found>0 ){
			        		this->vert_node.push_back(found);
			        	}else{
			        		return true;
			        	}
		        }
		        temp = "";

	        }
	        if(op==1){
	        	ss >> temp; 
		        if (stringstream(temp) >> found){
		        	if(found<0){
		        		
			        }else if(found>0 || send2Add.size()<=2){
			        		send2Add.push_back(found);
			        	}
		          }

		        temp = "";
	        	
	        }
 
	        if(op==2){
	        	ss >> temp; 
	        	if(send2Add.size()>=3){
	        		return false;
	        	}
		        if (stringstream(temp) >> found){
		        	send2Add.push_back(found);
		          }
		        temp = "";
	        	
	        } 
	    }


	    if(op==1){





    		if(find(vert_node.begin(), vert_node.end(), send2Add[0]) != vert_node.end() 											&& find(vert_node.begin(), vert_node.end(), send2Add[1]) != vert_node.end() ) {

    			//send2Add[Vert_Ori][Vert_End][edge]
	    			
	    			if(send2Add[0]==send2Add[1]){

						cout<<string(getmaxWidth()/10,' ')<<RED_TEXT("NOT CONNECTED - Same Vertice")<<endl;

	    			}else{

				    	if(addEdge(send2Add[0],send2Add[1],send2Add[2])==true){

		    				cout<<string(getmaxWidth()/10,' ')<<GREEN_TEXT("Connected Vertice ")<<send2Add[0]<<" to Vertice "<<send2Add[1]<<" with weight of "<<send2Add[2]<<endl;
				    		
				    	}else{
				    		cout<<string(getmaxWidth()/10,' ')<<RED_TEXT("ALREADY CONNECTED")<<endl;
				    		cout<<string(getmaxWidth()/10,' ')<<RED_TEXT("Do you want to ")<<YELLOW_TEXT("overwrite")<<RED_TEXT(" the edge value? (y)")<<endl;

							for(int x=0;x<=this->vert_node.size()-1;x++){	
								for(int y=0;y<=this->vert_node.size()-1;y++){


									if(send2Add[0]==vert_node[x] && send2Add[1]==vert_node[y]){

										if(this->matrix[x][y]!=0){						
											cout<<"Actual Value: "<<BLUE_TEXT(<<matrix[x][y]<<)<<endl;
											cin>>ans;
											while(ans.size()>1){
												cin.clear();
												cin.ignore(INT_MAX,'\n');
												cout<<RED_TEXT("Wrong answer -> too many charaters")<<endl;
				    							cout<<string(getmaxWidth()/10,' ')<<RED_TEXT("Do you want to ")<<YELLOW_TEXT("overwrite")<<RED_TEXT(" the edge value? (y/n)")<<endl;
												cin>>ans;
											}
										if(ans=="y"){
											this->matrix[x][y]=send2Add[2];
											this->matrix[y][x]=send2Add[2];
											}else if(ans=="n"){}


										}

										cin.clear();
										cin.ignore(INT_MAX,'\n');
									}


								}
							}

				    	}	

	    			}
		    } else{
					cout<<string(getmaxWidth()/10,' ')<<RED_TEXT("NOT ADDED - Not a Vertice")<<endl;
				    return false;
				}
	    }
	    if(op==2){

		
	        	if(send2Add[0]==send2Add[1]){
	        		return false;
	        	}else{
	        		for (int x = 0; x <= vert_node.size()-1; ++x)
					{
						if(send2Add[0]==vert_node[x]){
							send2Add[0]=x;
						}
						else if(send2Add[1]==vert_node[x]){
							send2Add[1]=x;
						}else{

						}
					}
	        		return true;
	        	}}

	} 



	void showMatrix(){
		for(int x=0;x<=this->vert_node.size()-1;x++){
			//cout<<string((getmaxWidth()/getmaxWidth())+1,' ')<<vert_node[x];
			for(int y=0;y<=this->vert_node.size()-1;y++){
				cout<<string((getmaxWidth()/getmaxWidth())+1,' ')<<matrix[x][y];
			}
			cout<<endl;
		}

	}

	int isConnectedEdge(int vertice,int edgeTarget){
		//Check if vertices are connected;
		//
		//
		cout<<endl;
		cout<<YELLOW_TEXT("Checking")<<" if vertice:"<<vertice<<" is connect with vertice:"<<edgeTarget<<endl;
		for(int x=0;x<=this->vert_node.size()-1;x++){	
					for(int y=0;y<=this->vert_node.size()-1;y++){
						//cout<<"WOW:"<<vert_node[x]<<"-"<<vert_node[y]<<endl;
						if(vertice==this->vert_node[x] && edgeTarget==this->vert_node[y]){
							//cout<<"addEdge:"<<vert_node[x]<<"-"<<vert_node[y]<<endl;
							if(this->matrix[x][y]==-1){

								cout<<GREEN_TEXT("Same")<<" vertice "<<RED_TEXT("no edge")<<"-> "<<matrix[x][y]<<endl;
								return matrix[x][y];

							}

							if(this->matrix[x][y]!=0 ){
								cout<<GREEN_TEXT("Found")<<" with "<<GREEN_TEXT("a edge ")<<"weight of "<<YELLOW_TEXT(<<matrix[x][y]<<)<<endl;
								return matrix[x][y];
							}else{

								cout<<GREEN_TEXT("Found")<<" but with "<<RED_TEXT("no edge")<<" weight -> "<<matrix[x][y]<<endl;
								return matrix[x][y];

							}
						}

					}
			}
			cout<<RED_TEXT("Not a vertice")<<endl;
		

	}


	bool isConnectedFull(){
		//DO
		//Check if graph is strongly connected (all vertices have a edge)
		//create variable to check a bool for each vertice if found a 1 mean have connection with other and push to the variable as visited and go next to other vertice if a vertice is missing(value 0/but the edge can have 0 as value ...) mean the graph is not strongly connected so compare at the end the variable with vert_node to see if is some vertice is missing

		//send2Add[0] - Vertice Origin
		//send2Add[1] - Vertice Target


		//Create List



		string vertOriTar;
		cout<<string(getmaxWidth()/4,' ')<<GREEN_TEXT("Check Graph 'Strong' ")<<endl;
		cout<<string(getmaxWidth()/6,' ')<<GREEN_TEXT("Identify the Origin vertices and Target vertice -> ")<<endl;
		cout<<string(getmaxWidth()/4,' ')<<GREEN_TEXT("Separate them by Space -> ex. 5 1\t");
		getline(cin,vertOriTar);
		while(splitInputStr(vertOriTar,2)!=true){

			cout<<string(getmaxWidth()/8,' ')<<RED_TEXT("ERROR too many vertices or equal")<<endl;
			cout<<string(getmaxWidth()/4,' ')<<GREEN_TEXT("Separate them by Space -> ex. 5 1\t");
			getline(cin,vertOriTar);
			splitInputStr(vertOriTar,2);


		}

		cout<<"position on vert_node: "<<send2Add[0]<<" - "<<send2Add[1]<<endl;
		cout<<"value on vert_node: "<<vert_node[send2Add[0]]<<" - "<<vert_node[send2Add[1]]<<endl;

		vector <int> unVisited;
		vector <int> visited;







	}




};

int main(){
	string numVert;	
	graph gra;


	//Identify Vertices
	cout<<string((getmaxWidth()/2)-9,' ')<<GREEN_TEXT("Identify the vertices")<<endl;
	cout<<string((getmaxWidth()/3)-2,' ')<<GREEN_TEXT("Seperate by space example -> ")<<RED_TEXT("1 2 3 4 5 6")<<endl;
	

	
	//DINAMIC
	//getline(cin,numVert);
		


	//gra.splitInputStr(numVert,0);



	
	//STATIC
	gra.splitInputStr("11 22 33 44 55 66",0);	
/*
	while(gra.splitInputStr("11 22 33 44 55 66",0)!=true){

		cin.clear();
		cout<<string((getmaxWidth()/2)-9,' ')<<RED_TEXT("Identify valid vertices(non-negative)")<<endl;
		//gra.splitInputStr(numVert,0);
		getline(cin,numVert);
		gra.splitInputStr(numVert,0);

	}
*/
	gra.matrixGraph();
	cout<<GREEN_TEXT("Creating graph ")<<gra.vert_node.size()<<"x"<<gra.vert_node.size()<<endl<<"..."<<endl;
	cout<<"Show Actual Graph"<<endl;
	gra.showMatrix();






	//Identify Vertices edges
	cout<<string((getmaxWidth()/2)-9,' ')<<GREEN_TEXT("Vertices Identified")<<endl;
	cout<<string((getmaxWidth()/2)-15,' ')<<GREEN_TEXT(" -> ");
	for (int x=0;x<=gra.vert_node.size()-1; x++)
	{
		cout<<" "<<gra.vert_node[x];
	}
	cout<<endl;
	cout<<string((getmaxWidth()/2)-9,' ')<<GREEN_TEXT("Identify the edges")<<endl;
	cout<<string((getmaxWidth()/3)-15,' ')<<GREEN_TEXT("Seperate by space (Origin_Vertice) (Vertice_Edge) (Edge Weight) -> ")<<RED_TEXT("1 2 20")<<endl;
	cout<<string((getmaxWidth()/3)-10,' ')<<RED_TEXT("complex example of input: ")<<" 1 2 10 3 2 25 5 3 10 "<<endl;
	cout<<string((getmaxWidth()/2)-9,' ')<<GREEN_TEXT("then press ENTER")<<endl;

	cout<<string((getmaxWidth()/2)-10,' ')<<RED_TEXT("Send nothing to finish ")<<endl;

	cout<<"Insert: ";
	
	// Dinamic

	numVert.empty();
/*
	getline(cin,numVert);

	//gra.splitVertice2Edge(numVert);

	while(numVert!=""){
		cin.clear();

		gra.splitInputStr(numVert,1);
		cout<<"Other: ";
		getline(cin,numVert);

	}
*/

	

	cout<<endl;
	//grab 
	gra.splitInputStr("11 44 5",1);
	gra.splitInputStr("22 33 10",1); 
	gra.splitInputStr("33 66 10",1);
	gra.splitInputStr("44 55 5",1);
	gra.splitInputStr("44 66 20",1);
	cout<<endl;

	cout<<endl;
	cout<<"Actual Graph"<<endl;
	gra.showMatrix();
	cout<<endl;
	cout<<"Creating Adjacency List :"<<endl;
	gra.creatAdjList();
	cout<<"Adjacency List :"<<endl;
	gra.showAdjList();
	//cout<<"DPS Imple:"<<endl;
	//gra.DFS(22);


	//gra.path2Vertice();

	//gra.isConnectedFull();
	/*
	if(gra.isConnectedEdge(66,66)>0){
		cout<<GREEN_TEXT("Connected")<<endl;
	}else{cout<<RED_TEXT("Not connected")<<endl;}
	*/
	//gra.dijkstraAlgorithm();
/* 

	if(gra.isConnectedFull()==true){
		cout<<GREEN_TEXT("Yes, This graph is strongly connected")<<endl;
	}else{
		cout<<RED_TEXT("No, This graph isn't strongly connected")<<endl;
	}
*/


	//gra.deletePossiLeaks();

	return 0;
}