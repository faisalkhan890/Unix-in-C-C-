/*
 * Filename        inotifyFunctions
 * Date            4/23/2019
 * Author          Srihaas Saripalli
 * Email           sxs172532@utdallas.edu
 * Course          CS 3377.502 Spring 2019
 * Version         1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 * It implements all the functions for the inotify library.
 * It checks the watch directory for any modifications.
 */


#include "handler.h"
#include <sstream>
#include <sys/inotify.h>

#define MAX_EVENT_MONITOR 2048
#define NAME_LEN 32				// Filename length
#define MONITOR_EVENT_SIZE (sizeof(struct inotify_event))  // size of 1 event
#define BUFFER_LEN MAX_EVENT_MONITOR*(MONITOR_EVENT_SIZE+NAME_LEN) // buffer length


void inotifyFunctions(){

	if(opendir((argMap[watchDir] + "/.versions").c_str()) == NULL){
		system(("mkdir " + argMap[watchDir] + "/.versions").c_str());
	}

	int fd, watch_desc;
	char buffer[BUFFER_LEN];

	fd = inotify_init();
	if(fd<0){
		cout << "Inotify not initialized\n";
	}

	watch_desc = inotify_add_watch(fd,argMap[watchDir].c_str(), IN_MODIFY);

	if(watch_desc== -1){
		cout << "Couldn't add watch directory \"" << argMap[watchDir].c_str() << "\"\n";
	}	

	int i =0;
	while(1){
		i = 0;
		int total_read = read(fd, buffer, BUFFER_LEN);
		if(total_read < 0){
			cout << "Read error\n";
		}

		while(i < total_read){
			struct inotify_event *event = (struct inotify_event*)&buffer;
			if(event->len){
				if(event->mask & IN_MODIFY){
					if(argMap[daemonArg] == "False")
						cout << "File " << event->name << " was modified\n";
					else
						loggingFile << "File " << event->name << " was modified\n";

					// Make a copy of the modified file and store it into the .versions file
					FILE *fp;
					char dateChar[100];
					fp = popen("date +%Y.%m.%d-%H:%M:%s", "r");
  					if(fgets(dateChar, 100, fp) != NULL){
  						system(("cp " + argMap[watchDir] + "/" + event->name + " " + argMap[watchDir] + "/.versions/" + event->name + "." + dateChar).c_str());	
  					}
  					pclose(fp);


				}
			}
				i+= MONITOR_EVENT_SIZE+event->len;
		}
	}
}