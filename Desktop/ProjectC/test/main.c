/*
 *	This is the main file.
 *	Autroritied by Riderppp
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "LinkListOP.h"

extern void switchFunc();
extern void showMenu();
#define MAX_SIZE 128

tLinkTable * pHead = NULL;

typedef struct dataNode{
	tLinkTableNode * pNext;
	char * cmd;
	char * desc;
	int (*handler)();
}tdataNode;

int main(){
	/*showMenu();
	switchFunc();*/
	initMenuData(&pHead);
	showAllCmd(pHead);
	while(1){
        char cmd[MAX_SIZE] = {0};
		printf("Enter a cmd number: ");
		scanf("%3s",cmd);
		cmd[3] = '\0';
		tdataNode * pNode = findCmd(pHead, cmd);
		if(pNode == NULL){
			printf("This is a wrong cmd!\n");
			continue;
		}
		printf("#%s-------%s\n", pNode -> cmd, pNode -> desc);
		if(pNode -> handler != NULL){
			pNode -> handler();
		}
	}
	return 0;
}
