/*
 * Filename        Your filename
 * Date            The Date
 * Author          Mohammad Faisal Khan
 * Email           mxk177030@utdallas.edu
 * Course          CS 3377.502 Spring 2019
 * Version         1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 *
 *     A (possibly multi-line)description of
 *     the file contents. 
 */

%union
{
  char* str;
  int value;
}



%type	<str>	NAMETOKEN
%type	<str>	IDENTIFIERTOKEN
%type	<str>	NAME_INITIAL_TOKEN
%type	<str>	ROMANTOKEN
%type	<value>	INTTOKEN

%token	NAMETOKEN
%token	IDENTIFIERTOKEN
%token	NAME_INITIAL_TOKEN
%token	ROMANTOKEN
%token	SRTOKEN
%token	JRTOKEN
%token	EOLTOKEN
%token	INTTOKEN
%token	COMMATOKEN
%token	DASHTOKEN
%token	HASHTOKEN

%start postal_addresses

%%

postal_addresses:
		address_block EOLTOKEN postal_addresses
		|address_block;
address_block:
		name_part street_address location_part;
name_part:
		personal_part last_name suffix_part EOLTOKEN
		|personal_part last_name EOLTOKEN
		|error;
personal_part:
		NAMETOKEN|NAME_INITIAL_TOKEN;
last_name:
		NAMETOKEN;
suffix_part:
		SRTOKEN|JRTOKEN|ROMANTOKEN;
street_address:
		street_name street_name INTTOKEN EOLTOKEN
		|street_number street_name HASHTOKEN INTTOKEN EOLTOKEN
		|street_number street_name EOLTOKEN
		|error;
street_number:
		INTTOKEN
		|IDENTIFIERTOKEN;
street_name:
		NAMETOKEN;
location_part:
		town_name COMMATOKEN state_code zip_code EOLTOKEN
		|error;
town_name:
		NAMETOKEN;
state_code:
		NAMETOKEN;
zip_code:
		INTTOKEN DASHTOKEN INTTOKEN
		|INTTOKEN;
