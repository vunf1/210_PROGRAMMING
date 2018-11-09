
#include <ncurses.h>
#include <string> // String Library
#include <string.h>// string functions
#include <climits> // for INT_MAX limits that can fix possible bugs from User Input
#include <limits>
#include <vector>

string sentence;
short int x,y;











void INTRO()
{

 	char mesg[]="Enter a string: ";
	char str[80];

 	char title[]="BST - BINARY SEARCH TREE ";
	getmaxyx(stdscr,y,x);
	refresh();
	noecho();

			mvprintw((y/10)+2,x/2-(strlen(title)/2),"%s",title);


      			attron(COLOR_PAIR(4));
			mvprintw(y/2,x/2-(strlen(mesg)/2),"%s",mesg);
                 attroff(COLOR_PAIR(4));    		



	getch();
	clear();
	refresh();
	//echo();



}


void loadGrafic() 
{
	bool run=true;

  	initscr();

    start_color();

    init_pair(0,COLOR_RED,-1);
    init_pair(1,COLOR_GREEN,-1);
    init_pair(2,COLOR_RED,-1 );
    init_pair(3,COLOR_CYAN,-1 );
    init_pair(4,COLOR_MAGENTA,-1);
    init_pair(5,COLOR_GREEN,-1);
    init_pair(6,COLOR_BLUE,-1);
    init_pair(7,COLOR_WHITE,-1);
/*
while(true){
//keycode();
	    string sentence;
	   
	   	   //move(13+4, 3); 
	   	   mvprintw(14,0,"Insert your command: \n");
	   	   sentence=get_line();

	   	   mvprintw(16,0,"%s",sentence.c_str());
	   	  // mvprintw(17,0,"%s",keywordChecker4children(sentence).c_str());
	   	   if(keywordChecker4children(sentence)=="look"){
	   	   	mvprintw(17,0,"OKOKOKOK");
	   	   }


}*/

  //endFloor();
  //curs_set(0); //Cursor visibility , 0 none - 1 visible - 2 barely visible
  
  while( run == true ) 
  {

    	INTRO();
 

   }
  endwin();
  // End nCurses display
}