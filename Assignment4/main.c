/*
 * Filename        Your main.c
 * Date            03/28/2019
 * Author          Mohammad Faisal Khan
 * Email           mxk177030@utdallas.edu
 * Course          CS 3377.502 Spring 2019
 * Version         1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 *
 *    the main file which is driving everything.
 *     
 */

#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
#include <stdio.h>

extern int yylex(void);
extern int yyparse() ;
extern char* yytext;

int main(int argc, char* argv[])
{
  if (strcmp(argv[0], "./scanner"))
      {
	printf("Operating in scan mode"); 
	int temp = yylex();
	       while(yylex)
		 {
		 switch(temp)
		   {
		   case NAMETOKEN:
		   printf("yylex returned NAMESTOKEN token (%s)\n", yytext);
		   break;

		   case IDENTIFIERTOKEN:
		   printf("yylex returned IDENTIFIERTOKEN (%s)\n", yytext);
		   break;

		   case NAME_INITIAL_TOKEN:
		   printf("yylex returned NAME_INITIAL_TOKEN (%s)\n", yytext);
		   break;

		   case ROMANTOKEN:
		   printf("yylex returned ROMANTOKEN (%s)\n", ROMANTOKEN);
		   break;

		   case SRTOKEN:
		   printf("yylex returned SRTOKEN (%s)\n", yytext);
		   break;

		   case JRTOKEN:
		   printf("yylex returned JRTOKEN (%s)\n", yytext);
		   break;

		   case EOLTOKEN:
		   printf("yylex returned EOLTOKEN (%s)\n", EOLTOKEN);
		   break;

		   case INTTOKEN:
		   printf("yylex returned INTTOKEN (%s)\n", yytext);
		   break;

		   case COMMATOKEN:
		   printf("yylex returned COMMATOKEN (%s)\n", COMMATOKEN);
		   break;

		   case DASHTOKEN:
		   printf("yylex returned DASHTOKEN (%s)\n", DASHTOKEN);
		   break;

		   case HASHTOKEN:
		   printf("yylex returned HASHTOKEN (%s)\n", HASHTOKEN);
		   break;
		   }
		 temp = yylex();
	       }
      }
  else if (strcmp(argv[0], "./parser"))
      {
	printf("Operating in parse mode");
	yyparse();
	printf("parse successful");
       }

      else 
	printf("invalid option entered");


  return 0;
}
