/*
 * Filename        handler.h
 * Date            4/23/2019
 * Author          Srihaas Saripalli
 * Email           sxs172532@utdallas.edu
 * Course          CS 3377.502 Spring 2019
 * Version         1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 * It has all the libraries needed to execute this and also tells the other files
 * which it is included into that there are other global variables called argMap and
 * loggingFile. The enums to use in the map are also located here.
 */

#ifndef HANDLER_H
#define HANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdlib.h>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <rude/config.h>
#include <dirent.h>
using namespace std;
using namespace rude;

// Global variables
extern map <int, string> argMap;
extern ofstream loggingFile;
// Function prototypes
void processControl();
bool fileExists(const string& file);
void parseCommandLine(int argc, char *argv[]);
void parseConfigFile();
void signalHandler(int signum);
void inotifyFunctions();

// The enums
enum argNames {daemonArg, confFile, verbose, logFile, password, numVersions, watchDir};

#endif
