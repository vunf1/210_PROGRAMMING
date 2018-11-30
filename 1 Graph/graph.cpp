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

	

stringstream stringToTxT;

void sendToTxT(){
	string text;
	text=stringToTxT.str();

	ofstream file;
	file.open("travelOutput.txt", ofstream::app);
		file<<text;
		file<<"\n";
	file.close();
	stringToTxT.clear();
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
    list <int> *adjAsList;
    vector <int> pathToVertice;
    
    
    /*
    // Title: Pointer-to-pointer dynamic two-dimensional array
    // Author: Alexander Shukaev
    // Date: Apr 13/14 at 05:52pm 
    // Availability: https://stackoverflow.com/a/16001894/10700835
    */	
	void matrixGraph(){
		adjAsList = new list<int> [vert_node.size()];
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


								return true;	
							}
						}
					}

				}
	}


	bool creatAdjList(){
		cout<<GREEN_TEXT("Creating")<<" Adjacency List..."<<endl;

	  	adjList_ = new int* [vert_node.size()];

      	for (int x = 0; x < vert_node.size(); x++){

            adjList_[x] = new int [vert_node.size()];
            
            for(int y = 0; y < vert_node.size(); y++){

				adjList_[x][y]=0; 

            	if(matrix[x][y]!=0 && matrix[x][y]!=-1 ){
            		adjList_[x][y]=vert_node[y]; 

					this->adjAsList[x].push_back(vert_node[y]);

					cout<<"Vertice "<<vert_node[x]<<RED_TEXT(" connected ")<<"to Vertice "<<vert_node[y]<<YELLOW_TEXT(" Weight")<<"->"<<matrix[x][y]<<endl;
				}
            }cout<<endl;
        }

	}

	void showAdjVector(){
	
		cout<<"Adjacency List[vector]:"<<endl;

        for (int x = 0; x < vert_node.size(); ++x){
        	cout<<" Vertice "<<vert_node[x]<<" -> ";
        	for (int y = 0; y < vert_node.size(); ++y){
        		if(this->adjList_[x][y]){
        			cout<<this->adjList_[x][y]<<" ";
        		}

        	
        	}cout<<endl;
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
		        	if(found>0){
			        	this->vert_node.push_back(found);
			        }else if(found<0){
		        		return false;
			        }

		        }else{return false;}

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

	    if(op==0){
	    	return true;
	    }
	    if(op==1){





    		if(find(vert_node.begin(), vert_node.end(), send2Add[0]) != vert_node.end() 											&& find(vert_node.begin(), vert_node.end(), send2Add[1]) != vert_node.end() ) {

    			//send2Add[Vert_Ori][Vert_End][edge]
	    			
	    			if(send2Add[0]==send2Add[1]){

						cout<<string(getmaxWidth()/10,' ')<<RED_TEXT("NOT CONNECTED - Same Vertice")<<endl;

	    			}else{

				    	if(addEdge(send2Add[0],send2Add[1],send2Add[2])==true){

		    				cout<<string(getmaxWidth()/10,' ')<<GREEN_TEXT("Connect Vertice ")<<send2Add[0]<<" to Vertice "<<send2Add[1]<<" with weight of "<<send2Add[2]<<endl;
				    		
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

		    								cout<<string(getmaxWidth()/10,' ')<<GREEN_TEXT("Connect Vertice ")<<send2Add[0]<<" to Vertice "<<send2Add[1]<<" with weight of "<<send2Add[2]<<endl;
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
	void isPath(int sVert,int eVert){
		//Path missing , do 
		bool check;

		for (int x = 0; x < pathToVertice.size(); ++x)
		{
			cout<<" -> "<<pathToVertice[x];
		}
		cout<<" :: "<<check<<endl;
	}

	bool isBFSlogic(int startVert){
		if(sendIndex(startVert)==-1){
			//no valid vertice
			return false;
		}
		pathToVertice.clear();
	    bool *visited = new bool[vert_node.size()]; 
	    for(int i = 0; i < vert_node.size(); i++){visited[i] = false;}
	    //all vertices as unvisited - all false;
	    list<int> queue;// 
	  
	    visited[sendIndex(startVert)] = true; 
	    //insert on queue;
	    queue.push_back(startVert);
	    //cout<<"QUEUE: "<<startVert<<endl;  
	    list<int>::iterator i;  

	    while(!queue.empty()) 
	    { 
	        // Dequeue a vertice from queue
	        startVert = queue.front(); 

	        queue.pop_front();
	        visited[sendIndex(startVert)]=true;

	    	pathToVertice.push_back(startVert);  

	        //cout<<"QUEUE: "<<startVert<<endl;
	  
	        // Get all adjacent vertices of the dequeued 
	        // vertice startVert. If a adjacent has not been visited,  
	        // then mark it visited and enqueue it 
	        for (i = adjAsList[sendIndex(startVert)].begin(); i != adjAsList[sendIndex(startVert)].end(); ++i){
	        	//cout<<"Vertice "<<*i<<" visited ->"<<visited[sendIndex(*i)]<<endl;
	        	if (!visited[sendIndex(*i)]){ 

	                visited[sendIndex(*i)] = true; 
	                queue.push_back(*i);
	            } 
	        }

	    }
	    for (int x = 0; x < vert_node.size(); ++x){
	    	if(visited[x]==0){
	    		return false;
	    	}
	    }
	    return true;
	} 


	bool isConnected(int vert){
		if(vert<0){
			return false;
		}

		bool checkCon=isBFSlogic(vert);




		if(checkCon==0){
			cout<<RED_TEXT("NO ")<<","<<RED_TEXT("The graph isn't strongly connected")<<endl;


     		stringToTxT<<"BFS Method - Graph isn't strongly connected missing connection\n";
     		stringToTxT<<"All Vertices -> ";

			for (int x = 0; x < vert_node.size(); ++x)
			{
				stringToTxT<<vert_node[x]<<" ";
			}stringToTxT<<"\n";

		    for (int x = 0; x < pathToVertice.size(); ++x){
		    	if(x==0){
		    	stringToTxT<<" start| "<<x<<" - "<<pathToVertice[x];

		    	}else{
		    	stringToTxT<<" | "<<x<<" - "<<pathToVertice[x];

		    	}
				
			}
			stringToTxT<<"\n------------\n";sendToTxT();
			return true;
     	}else{
     		cout<<GREEN_TEXT("YES")<<","<<GREEN_TEXT("The graph is strongly connected")<<endl;
		    stringToTxT<<"BFS Method - Graph is strongly connected\n";

		    stringToTxT<<"All Vertices -> ";
			for (int x = 0; x < vert_node.size(); ++x)
			{
				stringToTxT<<vert_node[x]<<" ";
			}stringToTxT<<"\n";


		    for (int x = 0; x < pathToVertice.size(); ++x){

		    	if(x==0){
		    		stringToTxT<<" start| "<<x<<" - "<<pathToVertice[x];

			    }else{
			    	stringToTxT<<" | "<<x<<" - "<<pathToVertice[x];

				}
					
			}
			stringToTxT<<"\n------------\n";sendToTxT();
			cout<<endl;
			return true;
     	}


	}



	bool isDFSnext(int actVert, bool visited[]){
		pathToVertice.push_back(actVert);
	    visited[sendIndex(actVert)] = true; 	  

	    list<int>::iterator i; 
	    
	    for (i = adjAsList[sendIndex(actVert)].begin(); i != adjAsList[sendIndex(actVert)].end(); ++i){
	    	if (!visited[sendIndex(*i)]){
	    		isDFSnext(*i, visited);
	    	}
	    }
	    return visited; 
	} 

	void isDFSlogic(int actVert){
		pathToVertice.clear();//clear previous path 

	    bool *visited = new bool[vert_node.size()];

	    for (int x = 0; x < vert_node.size(); x++){
	    	visited[x] = false;
	    }

	    isDFSnext(actVert, visited); 
	    stringToTxT<<"DFS Method - \n";
	    stringToTxT<<"All Vertices -> ";
	    for (int x = 0; x < vert_node.size(); ++x)
			{
				stringToTxT<<vert_node[x]<<" ";
			}stringToTxT<<"\n";

	    for (int x = 0; x < vert_node.size(); ++x){
	    	if(visited[x]==0){
	    		stringToTxT<<"\n not reached| "<<x<<" - "<<vert_node[x]<<"\n";
	    	}else{
	    	stringToTxT<<" | "<<x<<" - "<<pathToVertice[x];

	    	}
		}
		stringToTxT<<"\n------------\n";sendToTxT(); 
	} 






	void showMatrix(){
		cout<<"Show Actual Graph"<<endl;
		for(int x=0;x<=this->vert_node.size()-1;x++){
			//cout<<string((getmaxWidth()/getmaxWidth())+1,' ')<<vert_node[x];
			for(int y=0;y<=this->vert_node.size()-1;y++){
				cout<<string((getmaxWidth()/getmaxWidth())+1,' ')<<GREEN_TEXT(<<matrix[x][y]<<);
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
	void showlist(){ 
	    list <int> :: iterator connectedVert; 
	    cout<<YELLOW_TEXT("Adjacency List:")<<endl;
		for (int x = 0; x < vert_node.size(); ++x){
			cout<<RED_TEXT("Vertice ")<< vert_node[x]<<" |";
		    for(connectedVert = adjAsList[x].begin(); connectedVert != adjAsList[x].end(); connectedVert++){
		    	cout<<" " << *connectedVert;
		    }
		    cout<<endl;
		}
	}



	int sendIndex(int value){
		for (int x = 0; x < vert_node.size(); x++){
			if(value==vert_node[x]){
				return x;
			}
		}
		return -1;
	}



};

int main(){
	string numVert;	
	graph gra;


	//Identify Vertices
	cout<<string((getmaxWidth()/2)-9,' ')<<GREEN_TEXT("Identify the vertices")<<endl;
	cout<<string((getmaxWidth()/3)-2,' ')<<GREEN_TEXT("Seperate by space example -> ")<<RED_TEXT("1 2 3 4 5 6")<<endl;
	

	
	//DINAMIC
	getline(cin,numVert);



	
	//STATIC
	//gra.splitInputStr("11 22 33 44 55 66 77",0);	
	while(gra.splitInputStr(numVert,0)!=true){

		cin.clear();
		cout<<string((getmaxWidth()/2)-9,' ')<<RED_TEXT("Identify valid vertices(non-negative)")<<endl;
		//gra.splitInputStr(numVert,0);
		getline(cin,numVert);
		gra.splitInputStr(numVert,0);

	}



	cout<<GREEN_TEXT("Creating graph ")<<gra.vert_node.size()<<"x"<<gra.vert_node.size()<<endl<<"..."<<endl;
	gra.matrixGraph();

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

	getline(cin,numVert);

	//gra.splitVertice2Edge(numVert);

	while(numVert!=""){
		cin.clear();

		gra.splitInputStr(numVert,1);
		cout<<"Other: ";
		getline(cin,numVert);

	}

	cout<<endl;
	//grab 
	//create edges to the vertices
	/*
	gra.splitInputStr("11 44 5",1);
	gra.splitInputStr("22 33 10",1); 
	gra.splitInputStr("66 33 10",1);
	gra.splitInputStr("44 66 5",1);
	gra.splitInputStr("44 22 5",1);
	gra.splitInputStr("44 55 20",1);
	gra.splitInputStr("55 77 20",1);
	cout<<endl;
	*/

	cout<<endl;
	cout<<"Actual Graph"<<endl;
	gra.showMatrix();
	cout<<endl;
	//cout<<"Creating Adjacency List :"<<endl;
	gra.creatAdjList();
	//cout<<"Adjacency List :"<<endl;
	//gra.showAdjVector();
	gra.showlist();

	//Give vertice and from there say if graph is all connected
	//context fifo
	int chooseVerti;
	cout<<string((getmaxWidth()/2)-10,' ')<<RED_TEXT("Check if the graph is strong")<<endl;
	cout<<string((getmaxWidth()/2)-10,' ')<<GREEN_TEXT("Input a vertice")<<endl;
	cin>>chooseVerti;
	while(cin.fail()|| gra.isConnected(chooseVerti)==false){
		cin.clear();
		cout<<string((getmaxWidth()/2)-10,' ')<<RED_TEXT("Wrong Vertice")<<endl;
		cout<<string((getmaxWidth()/2)-10,' ')<<RED_TEXT("Other: \t")<<endl;
		cin>>chooseVerti;
		gra.isConnected(chooseVerti);
	}
cout<<"----"<<endl;
	gra.isConnected(chooseVerti);//BFS Method
	//gra.isPath(22,44);
	
	//gra.isDFSlogic(22);


	return 0;
}