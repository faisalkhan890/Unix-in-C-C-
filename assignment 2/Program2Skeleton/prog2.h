/*
 * Filename        prog2.h
 * Date		   02/06/2019
 * Author          Stephen Perkins
 * Email           stephen.perkins@utdallas.edu
 * Course          CS 3377.501 and 502 Spring 2019
 * Version         1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 *
 *     Header file for CS3377 Program 2 skeleton code
 *
 *     Specifically contains function prototypes, enums, global var defs.
 *     While global vars are frowned upon, they are specifically allowed
 *     for this assignment.
 *
 */

#ifndef __PROG2_H__    /* This is the start of the include guard */
#define __PROG2_H__

#include <map>   	/* needed for myMap global */
#include <string>	/* needed for myMap global */

using namespace std;


// Enumerated Types

enum _mapKeys {OUTFILENAME, INFILENAME, LFLAGPRESENT, UFLAGPRESENT, DEMOFLAG};

// Global Variables

extern map<int, string> myMap;

// Function Prototypes

void parse_command_line(int, char **);
void do_file_work();
void print_map(map<int, string>);

#endif /* __PROG2_H__  */
