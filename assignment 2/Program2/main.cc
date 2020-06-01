/*
 * Filename        prog2_main.cc
 * Date            02/06/2019
 * Author          Mohammad Faisal Khan
 * Email           mxk177030@utdallas.edu
 * Course          CS 3377.502 Spring 2019
 * Version         1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 *
 *     Main starting point for for CS3377 Program 2 skeleton code
 *
 *     Specifically contains main() and declares global variables
 *
 */
#include <fstream>
#include <map>
#include <iostream>
#include "prog2.h"
#include <ctype.h>
#include <string.h>

using namespace std;


map<int, string> myMap; // global variable

//  Main entry point

int main(int argc, char **argv)
{
  
  // map should be empty at this point
  print_map(myMap);

  // Parse the command line arguments
  parse_command_line(argc, argv);

  // checking if the user asked for both upper case and lower case at the same time
  if (myMap[LFLAGPRESENT]=="true" && myMap[UFLAGPRESENT]=="true")
    {
      cout << "It cannot be both uppercase and lowercase at the same time"<< endl;
      return 0; // end of the program
    }

  // print the map again with the updated entries
  print_map(myMap);

  do_file_work(); //calling function to read in from a file and outputting to output file and changing to uppercase or lower case if asked

  return 0;// end of the progran
}


// function to display all the values using the maps
void print_map(map<int, string> themap)
{
  cout << "Map Contents:" << endl;
  cout << "\tOutfile Name:\t\t\t" << themap[OUTFILENAME] << endl;
  cout << "\tInfile Name:\t\t\t" << themap[INFILENAME] << endl;
  cout << "\tl Flag Present Name:\t\t" << themap[LFLAGPRESENT] << endl;
  cout << "\tu Flag Present Name:\t\t" << themap[UFLAGPRESENT] << endl ;
  cout << "\tThe Demo Flag is: \t\t"<< themap[DEMOFLAG] << endl << endl;
  cout << "Printing Map Done" << endl;

  return;
}

void do_file_work() // function to move contents from input file to output file and changing it to uppercase or lowercase if asked
{

  char ch;
  ofstream myOutputFile(myMap[OUTFILENAME].c_str()); // output file
  ifstream myInputFile(myMap[INFILENAME].c_str());// input file
  if (myInputFile.is_open()) //getting value from the input file
  {
    while(!myInputFile.eof())
      {
	ch = myInputFile.get();
      
	if(myMap[UFLAGPRESENT]=="true") //converting to upper case
          {
	    ch=toupper(ch);
          }
	else  if(myMap[LFLAGPRESENT]=="true")//converting to lower case
          {
	    ch=tolower(ch);
	  }
	myOutputFile <<(char) ch;//outputting the calculated data in the output file
      }
   
  }
  myOutputFile.close();//closing input and output file
  myInputFile.close();
}
