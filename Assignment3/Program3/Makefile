#
# Filename        makeFile
# Date            The Date 
# Author          Mohammad Faisal Khan
# Email           mxk177030@utdallas.edu
# Course          CS 3377.502 Spring 2019
# Version         1.0
# Copyright 2019, All Rights Reserved
#
# Description
#
# make file which compiles the files to executable file and cleans unnecessary stuff   
# Set up info for C++ implicit rule
CXX = g++			
CXXFLAGS = -Wall	
OBJS = main.o	

.PHONY: all clean

all: myProj

	$(CXX) -o myProj $(OBJS)

clean:		
	 rm –f  $(OBJS) *~ main

myProj: $(OBJS)
	$(CXX) -o Mymain  $(OBJS)
