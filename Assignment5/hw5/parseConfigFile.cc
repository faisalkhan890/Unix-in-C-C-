/*
 * Filename        parseConfigFile.h
 * Date            4/23/2019
 * Author          Srihaas Saripalli
 * Email           sxs172532@utdallas.edu
 * Course          CS 3377.502 Spring 2019
 * Version         1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 * Uses the rudeconfig library to parse the config file and stores
 * it into a map
 */

#include "handler.h"

void parseConfigFile(){

  // Creating the config object
  Config config;

  // Open the file
  if(config.load( argMap[confFile].c_str() )){

    // Check if section is present
    if(config.setSection("Parameters",false)){
      
      // Check if all the required keys are present
      if(config.exists("Verbose") && config.exists("LogFile") && config.exists("Password") && config.exists("NumVersions") && config.exists("WatchDir")){
      // Read and store data into the map
      argMap[verbose] = config.getStringValue("Verbose");
      argMap[logFile] = config.getStringValue("LogFile");
      argMap[password] = config.getStringValue("Password");
      argMap[numVersions] = config.getStringValue("NumVersions");
      argMap[watchDir] = config.getStringValue("WatchDir");
      cout << argMap[verbose] << endl << argMap[logFile] << endl <<argMap[password] << endl << argMap[numVersions] << endl << argMap[watchDir] << endl;
      cout << "Successfully read in values from the config file.\n";

      }
      else{
	// Unsuccessful section read
	cout << "One or more values in Parameters is/are missing.\n"; 
	exit (EXIT_FAILURE);
      }
    }
    else{
      // Unsuccessful section name read
      cout << "Parameters section is not present in the file.\n";
      exit (EXIT_FAILURE);
    }
  } 
  else{
    // Unsuccessful file opening
    cout << "Error loading the \".conf\" file.\n";
    exit (EXIT_FAILURE);
  }
}
