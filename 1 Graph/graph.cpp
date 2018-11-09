/*GRAPH
DEV:
	Version Control:
		txt file handle, features(add,read)
		user input [x]
		handle user input [ ]
		create adjant table for user path input [ ]
		function saying if that vertice is connect to other [ ]
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

	bool addVert(){

	}
};

string checkInput(auto& path2)
{

	/*Accept input and separate unique numbers and create a vector for them(vertices)
	for edges check on many times the vertice colapsa com outros */

	vector<string> pathFix;
	int counter=0;

	istringstream iss(path2);
	    copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter(pathFix));

	vector<string> pathNum={};
	for(int x=0; x <= pathFix.size();x++)
	{
		cout<<pathFix[x]<<endl;

	}




/*
	for(int x=0; x <= 5;x++)
	{
		if(find(path2G.begin(), path2G.end(), possiblePath[x]) != path2G.end())
		{
			counter=1;
			return possiblePath[x].c_str();
		}

	}
	if(counter==0){
		return string("false");
	}*/
}

void addTXT(int text,string desc){

	fstream file;
	  file.open ("log.txt",ios::app);


	  // Writing on file
	  file << text << endl;
	  file <<"Desc: "<<desc << endl;


	  file.close();
}

bool splitInput(auto% numberTxt){



}

int main(){
	int numPath;
	int number_VE;
	vector<string> vert_edges;
	cout<<string(10,' ')<<"How many path will you insert?"<<endl;
	cin>>numPath;
	while (cin.fail())
	{
		cin.clear(); // clear input buffer to restore cin to a usable state
		cin.ignore(INT_MAX, '\n'); // ignore last input
		cout<<RED_TEXT("You can only input a single number.")<<endl;
		cout<<string(10,' ')<<"How many path will you insert?"<<endl;
		cin>>numPath;
	}
		cin.clear(); 
		cin.ignore(INT_MAX, '\n');
	for (int x=0; x<=numPath-1;x++){


		cout<<string(10,' ')<<"Insert the "<<x+1<<" path"<<endl;
		cin.getline(number_VE, sizeof(number_VE));

		while(splitInput()==false){
			

			cout<<RED_TEXT("You can only input a two single number.")<<endl;
			cout<<RED_TEXT("Use Space beetwen the numbers e.g -> 2 3")<<endl;
			cout<<string(10,' ')<<"Insert the "<<x+1<<" path"<<endl;
			cin.getline(number_VE, sizeof(number_VE));



		}
		//vert_edges.emplace_back(number_VE);

	}
		for (int x=0; x<=vert_edges.size();x++){


				cout<<string(10,' ')<<vert_edges[x]<<endl;

			}
	return 0;
}