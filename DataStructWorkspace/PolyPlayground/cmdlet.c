/*
 * cmdlet.c
 *
 *  Created on: Mar 2, 2016
 *      Author: David Culbreth
 */

#include "cmdlet.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

cmdlet * newCMD(char * name, action cmd){
	cmdlet * commandlet = (cmdlet *)malloc(sizeof(cmdlet));
	commandlet->act = cmd;
	commandlet->name = name;
	commandlet->description = "";
	return commandlet;
}

cmdlet * newCMDdetail(char * name, action cmd, char * desc){
	cmdlet * commandlet = (cmdlet *)malloc(sizeof(cmdlet));
	commandlet->act = cmd;
	commandlet->name = name;
	commandlet->description = desc;
	return commandlet;
}

cmdlist newCMDList(){
	cmdlist list;
	list.CMDHead = NULL;
	return list;
}

void addCMDtoList(cmdlet * cmd, cmdlist * list){
	if(list->CMDHead==NULL){
		list->CMDHead = cmd;
		return;
	}
	cmdlet * current = list->CMDHead;
	while(current->nextcmd != NULL && strcmp(current->name, cmd->name)>0){
		current = current->nextcmd;
	}
	cmd->nextcmd = current->nextcmd;
	current->nextcmd = cmd;
}

void printCMDList(cmdlist list){
	if(list.CMDHead == NULL){
		printf("NO COMMANDS: LIST EMPTY");
		return;
	}
	cmdlet * current = list.CMDHead;
	while(current != NULL){
		printCMD(current, 1);
		current = current->nextcmd;
	}


}

void printCMD(cmdlet * cmd, int detail){
	switch(detail){
	case 0:
		printf(cmd->name);
		break;
	case 1:
		printf("%s<%s>:\n", "", cmd->name);
		printf("%s\n", cmd->description);
		printf("%s<%s>\n%s", "END ",cmd->name,"");
		break;
	default:
		break;
	}

}

