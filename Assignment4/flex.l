/*
 * Filename        flex.l
 * Date            03/25/2019
 * Author          Mohammad Faisal Khan
 * Email           mxk177030@utdallas.edu
 * Course          CS 3377.502 Spring 2019
 * Version         1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 *
 *     a lex file 
 *Terminal Saved Output
 */

%option noyywrap
%option nounput
%option noinput

%{
#include <stdlib.h>
#include "y.tab.h"
void yyerror (char const *s){fprintf(stderr,"%s\n",s);}
%}

%%

[\t\r]+			{/* eat up whitespace*/}
[IVXLCDM]+		{return ROMANTOKEN;}
[0-9]+			{yylval.value = atoi (yytext); return INTTOKEN;}
[A-Za-z]{2,}	    	{return NAMETOKEN;}
[A-Za-z0-9]+		{return IDENTIFIERTOKEN;}
[a-zA-Z]\.|[a-zA-Z]	{return NAME_INITIAL_TOKEN;}

"Sr."			{return SRTOKEN;}
"Jr."			{return JRTOKEN;}
[\n]			{return EOLTOKEN;}

","			{return COMMATOKEN;}
"-"			{return DASHTOKEN;}
"#"			{return HASHTOKEN;}

%%
