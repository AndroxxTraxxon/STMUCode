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

typedef void (*action)(char*);

typedef struct cmdlet{
	action act;
	char * name;
	struct cmdlet * nextcmd;

}cmdlet;

typedef struct cmdlist{
	cmdlet* heads[24]; // one head for each letter of the alphabet

}cmdlist;

cmdlet * newCMD(char * name, action cmd);



#endif /* CMDLET_H_ */
