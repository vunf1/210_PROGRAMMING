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
	int node;

	vector<string> vert_edges;

	cout<<string(10,' ')<<GREEN_TEXT("Identify the nodes ?")<<endl;
	cout<<string(5,' ')<<GREEN_TEXT("Seperate by space example -> ")<<RED_TEXT("1 2 3 4 5 6")<<endl;
	cin>>node;
	while (cin.fail())
	{
		cin.clear(); // clear input buffer to restore cin to a usable state
		cin.ignore(INT_MAX, '\n'); // ignore last input
		cout<<string(10,' ')<<GREEN_TEXT("Identify the nodes ?")<<endl;
		cout<<string(5,' ')<<GREEN_TEXT("Seperate by space example -> ")<<RED_TEXT("1 2 3 4 5 6")<<endl;

	}
	




	return 0;
}