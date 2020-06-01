/*
 * Filename        signalHandler.cc
 * Date            4/23/2019
 * Author          Srihaas Saripalli
 * Email           sxs172532@utdallas.edu
 * Course          CS 3377.502 Spring 2019
 * Version         1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 * This file implements signal handling and checks for the required signals
 */


#include "handler.h"

void signalHandler(int signum){
	cout << "Interrupt signal (" << signum << ") received.\n";

	if(signum == SIGINT || signum == SIGTERM){
		// Remove pid file
		system("rm -f cs3376dirmond.pid");
		// close logging
		loggingFile.close();

		exit(signum);
	}
	else if(signum == SIGHUP){
		Config config;
		// Open the file
		if(config.load( argMap[confFile].c_str() )){
		// Check if section is present
			if(config.setSection("Parameters",false)){
				argMap[verbose] = config.getStringValue("Verbose");
  				argMap[logFile] = config.getStringValue("LogFile");
  				argMap[numVersions] = config.getStringValue("NumVersions");

  				if(argMap[daemonArg] == "False")
						cout << "Successfully read in values from the config file.\n";
				else
					loggingFile << "Successfully read in values from the config file.\n";
			}
		    else{
				// Unsuccessful section name read
				if(argMap[daemonArg] == "False")
						cout << "Parameters section is not present in the file.\n";
				else
					loggingFile << "Parameters section is not present in the file.\n";
		
		      exit (EXIT_FAILURE);
		    }
		}
		else{
		// Unsuccessful file opening
		if(argMap[daemonArg] == "False")
				cout << "Error loading the \".conf\" file.\n";
		else
			loggingFile << "Error loading the \".conf\" file.\n";
		exit (EXIT_FAILURE);
		}
	}
}