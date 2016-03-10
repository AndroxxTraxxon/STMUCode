/*
 * main.c
 *
 *  Created on: Feb 29, 2016
 *      Author: David Culbreth
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Poly.h"
#include "debug.h"
#include "cmdlet.h"

void Help(int argc, char* args);
void initCommands();
char * toSUpper(char * c);
char * toSLower(char * c);

cmdlist commands;
var * vars = NULL;
int die, cmdFound, varFound;
const char DELIMITERS[] = {' ', '.', ',', ';', ':', '!', '\n', '\0'};

int maintwo(){
	poly p = NewPoly();
	AddTerm(35, 3, &p);
	AddTerm(25, 2, &p);
	AddTerm(15, 1, &p);
	AddTerm(5, 0, &p);


	poly q = NewPoly();

	printPoly(p);
	return 0;
}

int main(){
	initCommands();
	char inputBuffer[1024];
	char * firstWord;
	die = 0;
	int len;
	char * args;

	while(!die){
		cmdFound = 0;
		varFound = 0;
		fflush(stdout);

		printf("\n>>> ");
		fflush(stdout);
		fgets(inputBuffer, 1024, stdin);
		len = strlen(inputBuffer);
		firstWord = strtok(inputBuffer, DELIMITERS);


		cmdlet * currentcmd = commands.CMDHead;
		//check list of commands to see if it is
		while(currentcmd != NULL){
			if(strcmp(toSUpper(currentcmd->name), toSUpper(firstWord))==0){
				printf("Found a Command!");
				len -= sizeof(currentcmd->name);
				args =inputBuffer+sizeof(currentcmd->name);
				if(len == 0){
					args = "";
				}
				currentcmd->act(len, args);
				cmdFound = 1;
				break;
			}
			currentcmd = currentcmd->nextcmd;
		}
		if(cmdFound){
			//if there was a command found, start the loop again
			continue;
		}
		//looking for the variables.
		var * curVar = vars;
		while(curVar != NULL){
			if(strcmp(curVar->name, firstWord) == 0){
				printf("Found a variable!");
				varFound = 1;
				break;
			}
		}

		if(cmdFound == 0 && varFound == 0){
			printf("\n%s", "COMMAND OR VARIABLE NOT FOUND. REFORMAT ENTRY AND TRY AGAIN.");
		}

	}
	exit(0);
	return 0;
}

void Help(int argc, char* args){
	//TODO: ADD THE HELP FUNCTION
	printf("\nThis is the Help function!");
	printf("\nINPUT: <%s>", args);
}

void Instantiate(int argc, char * args){
	printf("\nMaking a new variable");

	char * name;
	name = strtok(NULL, DELIMITERS);

	if(vars == NULL){
		vars = NewPolyVar(name);
	}
}

void initCommands(void){
	commands.CMDHead = NULL;
	addCMDtoList(newCMD("help", Help),&commands);
	addCMDtoList(newCMD("var", Instantiate), &commands);
	//printCMDList(commands);
}

void Exit(int argc, char * args){
	cmdlet * cmds = commands.CMDHead;
	cmdlet * nextCMD;
	var * nextVar;
	var * curVar = vars;
	while(cmds != NULL){
		nextCMD = cmds->nextcmd;
		freeCMD(cmds);
		cmds = nextCMD;
	}
	while(curVar != NULL){
		nextVar = curVar->next;
		FreePoly(curVar->nomial);
		free(curVar);
		curVar = nextVar;
	}
	die = 1;
	printf("Press Enter to End...");
}

char toUpper(char c){
	char d = c;
	if (d >= 'a' && d <='z')
		d += ('A'-'a');
	return d;
}

char toLower(char c){
	char d = c;
	if (d >= 'A' && d <='Z')
		d += ('a'-'A');
	return d;
}

char * toSUpper(char * c){
	int len = strlen(c);
	char * output = (char *)malloc(len * sizeof(char));
	int i;
	for(i = 0; i < len; i++){
		output[i] = c[i];
		if (output[i] >= 'a' && output[i] <='z')
				output[i] += ('A'-'a');
	}
	return output;
}

char * toSLower(char * c){
	int len = strlen(c);
	char *  output = (char *)malloc(len * sizeof(char));
	int i;
	for(i = 0; i < len; i++){
		output[i] = c[i];
		if (output[i] >= 'A' && output[i] <='Z')
				output[i] += ('a'-'A');
	}
	return output;
}

void declareVar(char * name){
	var * variable = NewPolyVar(name);
	if(vars == NULL){
		vars = variable;
		return;
	}
	var * curVar = vars;
	while(curVar->next != NULL && strcmp(curVar->name, variable->name)>0/* <<<if the list shows flip the '>' to '<' and vice versa*/){
		//looking through the list to sort them alphabetically
		if(curVar->next != NULL){
			variable->next = curVar->next;
			variable->next->prev = variable;
			return;
		}



	}
}


