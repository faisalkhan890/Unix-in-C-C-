/*
 * Filename        program5.cc
 * Date            4/23/2019
 * Author          Srihaas Saripalli
 * Email           sxs172532@utdallas.edu
 * Course          CS 3377.502 Spring 2019
 * Version         1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 * The main is the driver for this project and call all other functions.
 * It first parses the command line and parses the config file and
 * executes it either in daemon mode of in foreground.
 * 
 */
#include "handler.h"

// Initialize the map
map <int, string> argMap;

int main(int argc, char *argv[]){
  
  // Parse the command line
  parseCommandLine(argc, argv);
  
  // Parse the config file
  parseConfigFile();

  // Initialize signal checking
  signal(SIGINT, signalHandler);
  signal(SIGTERM, signalHandler);
  signal(SIGHUP, signalHandler);

  // Check if the process should be a daemon
  if(argMap[daemonArg] == "True"){ 
    // Run as daemon
    // Check to see if .pid exists and only run a daemon if it doesn't
    if(!fileExists("cs3376dirmond.pid"))
      processControl();
    else
      cout << "The daemon process is in progress. Cannot start another process\n"; 
  }
  else{
    // Run in foreground
    inotifyFunctions();
  }

return 0;
}

// Checks whether the .pid file is already open
bool fileExists(const string& file) {
  struct stat buf;
  return (stat(file.c_str(), &buf) == 0);
}

------------------------------------------------------------------------------------------

