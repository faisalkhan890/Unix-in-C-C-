/*
 * Filename        main.cc
 * Date            02/26/2019
 * Author          Mohammad Faisal Khan
 * Email           mxk177030@utdallas.edu
 * Course          CS 3377.502 Spring 2019
 * Version         1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 *
 * The main function calling the gawk function using the popen/pclose
 * functions to print the sum of two different columns and printing their sum
 *    
 */

#include <stdio.h>
#include <iostream>
#include <sstream>
#include "stdlib.h"
using namespace std;

int BUFFER_SIZE = 1024;

int main(int argc, char *argv[])
{
  cout << "\ngawk at: /home/013/m/mx/mxk177030/Program3/bin/gawk" << endl;
  cout << "Shellcmd1: /home/013/m/mx/mxk177030/Program3/bin/gawk --version " << endl;
  cout << "Shellcmd2: /home/013/m/mx/mxk177030/Program3/bin/gawk -f gawk.code numbers.txt " << endl;

  cout << "\nFirst call to gawk returned:" << endl << endl;

  char buff[BUFFER_SIZE]; // buffer for reading 
  FILE *theInPipe = popen("gawk --version", "r");

  theInPipe = popen("/home/013/m/mx/mxk177030/Program3/bin/gawk --version", "r");

  if(theInPipe == NULL)//checking if the pipe exists or not
    {
      cout << "Error creating pipe stream ";
      return -1;
    }

  // read from pipe till EOF 
   while(fgets(buff, BUFFER_SIZE , theInPipe))//while to read from the pipe until it reaches end of file
     {
            cout << buff;
     }

  // Close the pipe stream 
  pclose(theInPipe);

  // Opening the  pipe stream again to print get the data from the file 
  theInPipe = popen("gawk -f gawk.code numbers.txt", "r");
  
  if(theInPipe == NULL)// checking if the inpipe exists
    {
      cout << "Error creating pipe stream ";
      return -1;
    }

  if(fgets(buff, BUFFER_SIZE , theInPipe) == NULL)
    {
      cout << "Error receiving data on pipe ";
      pclose(theInPipe);
      return -3;
    }

  //  Closing the pipe
  pclose(theInPipe);

  //parsing the output
  istringstream istream(buff);

  // Declaring variables
   int sum1, sum4;
  istream >> sum1 >> sum4;

   // outputting everything
  cout << "\nThe second call to gawk returned: "<< buff << endl; 

  cout << "The sum of Column 1 is: "<< sum1 << endl;
  cout << "The sum of Column 4 is: "<< sum4 << endl;

  sum1 = sum1 + sum4;
  cout << "The Sum of the two numbers is: " << sum1 << endl << endl;

  return 0;
}
 
