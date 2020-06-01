/*
 * Filename        processControl.cc
 * Date            4/23/2019
 * Author          Srihaas Saripalli
 * Email           sxs172532@utdallas.edu
 * Course          CS 3377.502 Spring 2019
 * Version         1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 * This file opens the the daemon and the calls inotify
 */


#include "handler.h"

ofstream loggingFile;

void processControl(){
  
  pid_t pid, sid;

  /* Fork off the parent process */
  pid = fork();
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }
  /* If we got a good PID, then
     we can exit the parent process. */
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  /* Change the file mode mask */
  umask(0);

  /* Open any logs here */
  ofstream pidFile;
  pidFile.open("cs3376dirmond.pid");
  pidFile << pid;
  pidFile.close();

  loggingFile.open(argMap[logFile].c_str());
  /* Create a new SID for the child process */
  sid = setsid();
  if (sid < 0) {
    /* Log any failures here */
    exit(EXIT_FAILURE);
  }


  /* Close out the standard file descriptors */
  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  /* Daemon-specific initialization goes here */

  inotifyFunctions();
}

