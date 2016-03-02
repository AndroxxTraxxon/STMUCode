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

cmdlet * newCMD(char * name, action cmd){
	cmdlet * commandlet = (cmdlet *)malloc(sizeof(cmdlet));
	commandlet->act = cmd;
	commandlet->name = name;

	return commandlet;
}


