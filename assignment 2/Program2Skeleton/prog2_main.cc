/*
 * Filename        prog2_main.cc
 * Date		   02/06/2019
 * Author          Stephen Perkins
 * Email           stephen.perkins@utdallas.edu
 * Course          CS 3377.501 and 502 Spring 2019
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

#include <map>
#include <iostream>
#include "prog2.h"

using namespace std;

// Define the global variable in exactly 1 file.  We choose the file with main()
// You only use the "extern" keyword in the header file

map<int, string> myMap;


//  Main entry point

int main(int argc, char **argv)
{

  cout << "Hello World" << endl;
  
  // map should be empty at this point
  print_map(myMap);

  // Parse the command line arguments
  parse_command_line(argc, argv);

  // print the map again
  print_map(myMap);

  return 0;
}

void print_map(map<int, string> themap)
{
  cout << "Map Contents:" << endl;
  cout << "\tOutfile Name:\t\t" << themap[OUTFILENAME] << endl;
  cout << "\tInfile Name:\t\t" << themap[INFILENAME] << endl;
  cout << "\tl Flag Present Name:\t\t" << themap[LFLAGPRESENT] << endl;
  cout << "\tu Flag Present Name:\t\t" << themap[UFLAGPRESENT] << endl ;
  cout << "\tThe Demo Flag is: \t\t"<< themap[DEMOFLAG] << endl << endl;
  cout << "Printing Map Done" << endl;

  return;
}
