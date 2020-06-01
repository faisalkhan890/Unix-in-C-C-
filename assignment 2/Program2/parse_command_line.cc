/*
 * Filename        prog2_parse_comnmand_line.cc
 * Date            02/06/2019
 * Author          Mohammad Faisal Khan
 * Email           mxk177030@utdallas.edu
 * Course          CS 3377.502 Spring 2019
 * Version         0.9
 * Copyright 2019, All Rights Reserved
 *
 * Description
 *
 *     This file is the ONLY file that contains TCLAP stuff.  Within this file,
 *     we perform TCLAP parsing of the command line and then we take the results
 *     out of TCLAP and place them into a MAP that we will use moving foward.
 *
 *
 */

#include <map>
#include <iostream>

#include <tclap/CmdLine.h> // for this to work, you must correctly install TCLAP
// and use the -I compiler option 

#include "prog2.h"

using namespace std;


void parse_command_line(int argc, char **argv)
{

  // Wrap everything in a try block.  Do this every time,
  // because exceptions will be thrown for problems.
  try {

    // Define the command line object, and insert a message
    // that describes the program. The "Command description message"
    // is printed last in the help text. The second argument is the
    // delimiter (usually space) and the last one is the version number.
    // The CmdLine object parses the argv array based on the Arg objects
    // that it contains.
    TCLAP::CmdLine cmd("CS3377 Assignment 2 ", ' ', "0.9");

    TCLAP::SwitchArg toUpperCase("u","upper","Convert all text to uppercase.", cmd, false); 

    TCLAP::SwitchArg toLowerCase("l","lower","Convert all text to lowercase.", cmd, false); 

    TCLAP::ValueArg <string> outFileArg("o","outfile","The name of the output file",false,"output.txt","output filename"); 
    cmd.add(outFileArg);
    TCLAP::UnlabeledValueArg <string> inFileArg("infile", "The Input file name.", true, "infile.txt", "input filename");
    cmd.add(inFileArg);


     // Parse the argv array.
    cmd.parse( argc, argv );
      
   // We only get here if the parse was successful.  If it failed, we will exit the program
    // in the above statement.   In Assignment 2, you will need to perform extra checks
    // here to test for mutually exclusive arguments.

    // putting the values if they are changed
    myMap[OUTFILENAME]  = outFileArg.getValue();
    myMap[INFILENAME]   = inFileArg.getValue();
    myMap[LFLAGPRESENT] = toLowerCase.getValue()?"true":"false";
    myMap[UFLAGPRESENT] = toUpperCase.getValue()?"true":"false";

  }

  catch (TCLAP::ArgException &e)  // catch any exceptions
    {
      cerr << "error: " << e.error() << " for arg " << e.argId() << endl;
    }


  return;
}
