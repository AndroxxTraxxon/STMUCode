/*
 * main.c
 *
 *  Created on: Feb 29, 2016
 *      Author: David Culbreth
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Poly.h"
#include "debug.h"
#include "cmdlet.h"

void Help(int argc, char* args);
void initCommands();

cmdlist commands;
int die;
const char DELIMITERS[] = " .,;:!-";

int main(){
	initCommands();
	char inputBuffer[1024];
	char * firstWord;
	die = 0;


	while(!die){
		printf("\n>>>");
		fgets(inputBuffer, 1024, stdin);

		firstWord = strtok(inputBuffer, DELIMITERS);
		//printf("\n%s",firstWord);
		printf(firstWord);
		printf(inputBuffer);

		cmdlet * currentcmd = commands.CMDHead;
		//check list of commands to see if it is
		while(currentcmd != NULL){
			if(firstWord == currentcmd->name){
					currentcmd->act(strlen(inputBuffer), inputBuffer);
				break;
			}
			currentcmd = currentcmd->nextcmd;
		}

	}



	return 0;
}

void Help(int argc, char* args){
	//TODO: ADD THE HELP FUNCTION
	printf("\nThis is the Help function!");
}

void Instantiate(int argc, char * args){
	printf("\nMaking a new variable");
}

void initCommands(void){
	commands.CMDHead = NULL;
	addCMDtoList(newCMD("help", Help),&commands);
	addCMDtoList(newCMD("var", Instantiate), &commands);
	//printCMDList(commands);
}

void Exit(int argc, char * args){
	die = 1;
	printf("Press Enter to End...");
	getch();
}



