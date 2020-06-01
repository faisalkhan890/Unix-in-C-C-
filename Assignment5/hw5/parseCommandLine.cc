/*
 * Filename        parseCommandLine.cc
 * Date            4/23/2019
 * Author          Srihaas Saripalli
 * Email           sxs172532@utdallas.edu
 * Course          CS 3377.502 Spring 2019
 * Version         1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 * This file parses the command line arguments and stores it into a map.
 */


#include "handler.h"
#include <tclap/CmdLine.h>


void parseCommandLine(int argc, char *argv[]){

  try{
    //Instantiate the TCLAP object
    TCLAP::CmdLine cmd("cs3376dirmond Directory Monitor Daemon", ' ', "1.0");

    TCLAP::SwitchArg daemonSwitch("d", "daemon", "Run in daemon mode (forks to r\
un as a daemon).", cmd, false);

    TCLAP::UnlabeledValueArg<string> confArg("config_file",
                                               "The name of the configuration fi\
le. Defaults to cs3376dirmond.conf ",
					     false, "cs3376dirmond.conf", "con\
fig filename", false);
    cmd.add(confArg);

    // Parse the cmd line arguments
    cmd.parse(argc, argv);


    // If all comamand line inputs are valid
    // Defining the map
    if(daemonSwitch.getValue())
      argMap[daemonArg] = "True";

    else
      argMap[daemonArg] = "False";
    argMap[confFile] = confArg.getValue();

  }
  catch (TCLAP::ArgException &e){ // Catch any exception
    cerr << "error: " << e.error() << " for arg " << e.argId() << endl;
  }

}
