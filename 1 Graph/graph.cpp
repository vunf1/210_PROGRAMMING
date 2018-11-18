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
	while(){


		cout<<string(10,' ')<<"Insert the "<<x+1<<" path"<<endl;
		cin.getline(number_VE, sizeof(number_VE));

	}




	return 0;
}