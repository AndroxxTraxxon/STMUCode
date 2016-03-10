/*
 * cmdlet.h
 *
 *  Created on: Mar 2, 2016
 *      Author: david
 */

#ifndef CMDLET_H_
#define CMDLET_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef void (*action)(int argc, char* args);

typedef struct cmdlet{
	action act;
	char * name;
	char * description;
	struct cmdlet * nextcmd;
}cmdlet;

typedef struct cmdlist{
	cmdlet * CMDHead; // one head for each letter of the alphabet

}cmdlist;

cmdlet * newCMD(char * name, action cmd);
void printCMDList(cmdlist list);
void addCMDtoList(cmdlet * cmd, cmdlist * list);
void freeCMD(cmdlet * cmd);


#endif /* CMDLET_H_ */
