/*
 *	This is a function file.
 *	Autroritied by Riderppp
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "LinkListOP.h"
#include "header.h"

/*void showMenu(){
    char options[][20] = {{"Print some star"},{"Calculate 3 + 4"}, {"Calculate 7 * 4"}, {"Give some words"},
{"Print some @"}, {"Calculate 8 / 2"}, {"Calculate 4 - 1"}, {"Draw a box"}, {"Q to quit"}, {"For help enter h"}};
	for(int i = 0; i < 10; i++)
	{
		printf("#%d: ", i+1);
		for(int j = 0; j < 20; j++)
			printf("%c", options[i][j]);
		printf("\n");
	}
}
*/
void printSomeStar(){
	for(int i = 0; i < 5; i++)
		printf("* ");
	printf("\n");
}

void calculateAdd(){
	printf("%d\n", 3+4);
}

void calculateMulti(){
	printf("%d\n", 7*4);
}

void giveSomeWords(){
	printf("Software engineering.\n");
}

void printSomeAt(){
	for(int i = 0; i< 10; i++)
		printf("@");
	printf("\n");
}

void calculateDivide(){
	printf("%d\n", 8/2);
}

void calculateSub(){
	printf("%d\n", 4-1);
}

void drawBox(){
	for(int i = 0; i < 10; i++){
		printf("*********\n");
	}
}

void help(){
	printf("Enter your options and see the result.\n");
}

void quit(){
	exit(0);
}

/*void switchFunc(){
	int option = 0;
	printf("Enter your option(Only numbers): ");
	while(scanf("%c", &option) != EOF){
		switch(option)
		{
			case '1': printSomeStar();
				break;
			case '2': calculateAdd();
				break;
			case '3': calculateMulti();
				break;
			case '4': giveSomeWords();
				break;
			case '5': printSomeAt();
				break;
			case '6': calculateDivide();
				break;
			case '7': calculateSub();
				break;
			case '8': drawBox();
				break;
			case 'h': help();
				break;
			case 'q': return 0;
			default: printf("Enter again: ");
		}
	}
}*/

typedef struct dataNode{
	tLinkTableNode * pNext;
	char * cmd;
	char * desc;
	int (*handler)();
}tdataNode;

tdataNode * findCmd(tLinkTable * head, char * cmd){
    if(head == NULL || cmd == NULL){
        return NULL;
    }
	tdataNode * pNode = (tdataNode*)getLinkTableHead(head);
	while(pNode != NULL){
		if (strcmp(pNode -> cmd, cmd) == 0){
			return pNode;
		}
		pNode = (tdataNode *)getNextLinkTableNode(head, (tLinkTableNode *)pNode);
	}
	return NULL;
}

int showAllCmd(tLinkTable * head){
	printf("Menu List:\n");
	tdataNode * pNode = (tdataNode *)getLinkTableHead(head);
	while(pNode != NULL){
		printf("#%s---------%s\n", pNode -> cmd, pNode -> desc);
		pNode = (tdataNode *)getNextLinkTableNode(head, (tLinkTableNode *)pNode);
	}
	return 0;
}

int initMenuData(tLinkTable ** pLinkTable){
	*pLinkTable = createLinkTable();
	tdataNode * pNode = (tdataNode *)malloc(sizeof(tdataNode));
	if(pNode != NULL){
        pNode -> cmd = "1";
        pNode -> desc = "Print some star";
        pNode -> handler = printSomeStar;
        addLinkTableNode(* pLinkTable, pNode);
    }
	else{
        printf("mallor error");
	}
    pNode = (tdataNode *)malloc(sizeof(tdataNode));
	pNode -> cmd = "2";
	pNode -> desc = "Calculate 3 + 4";
	pNode -> handler = calculateAdd;
	addLinkTableNode(* pLinkTable, pNode);
    pNode = (tdataNode *)malloc(sizeof(tdataNode));
	pNode -> cmd = "3";
	pNode -> desc = "Calculate 7 * 4";
	pNode -> handler = calculateMulti;
	addLinkTableNode(* pLinkTable, pNode);
    pNode = (tdataNode *)malloc(sizeof(tdataNode));
	pNode -> cmd = "4";
	pNode -> desc = "Give some words";
	pNode -> handler = giveSomeWords;
	addLinkTableNode(* pLinkTable, pNode);
    pNode = (tdataNode *)malloc(sizeof(tdataNode));
	pNode -> cmd = "5";
	pNode -> desc = "Print some @";
	pNode -> handler = printSomeAt;
	addLinkTableNode(* pLinkTable, pNode);
    pNode = (tdataNode *)malloc(sizeof(tdataNode));
	pNode -> cmd = "6";
	pNode -> desc = "Calculate 8 / 2";
	pNode -> handler = calculateDivide;
	addLinkTableNode(* pLinkTable, pNode);
	pNode = (tdataNode *)malloc(sizeof(tdataNode));
	pNode -> cmd = "7";
	pNode -> desc = "Calculate 4 - 1";
	pNode -> handler = calculateSub;
	addLinkTableNode(* pLinkTable, pNode);
	pNode = (tdataNode *)malloc(sizeof(tdataNode));
	pNode -> cmd = "8";
	pNode -> desc = "Draw a box";
	pNode -> handler = drawBox;
	addLinkTableNode(* pLinkTable, pNode);
	pNode = (tdataNode *)malloc(sizeof(tdataNode));
	pNode -> cmd = "q";
	pNode -> desc = "Q to quit";
	pNode -> handler = quit;
	addLinkTableNode(* pLinkTable, pNode);
	pNode = (tdataNode *)malloc(sizeof(tdataNode));
	pNode -> cmd = "h";
	pNode -> desc = "For help enter h";
	pNode -> handler = help;
	addLinkTableNode(* pLinkTable, pNode);

	return 0;
}

tLinkTable * createLinkTable(){
	tLinkTable * pTable = (tLinkTable *)malloc(sizeof(tLinkTable));
	pTable -> pHead = NULL;
	pTable -> pTail = NULL;
	pTable -> numOfNode = 0;
	return pTable;
}

tLinkTableNode * getLinkTableHead(tLinkTable * pLinkTable){
	if(pLinkTable == NULL){
		printf("The table is empty!\n");
		exit(0);
	}
	return pLinkTable -> pHead;
}

tLinkTableNode * getNextLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode){
	if(pLinkTable == NULL){
		printf("The table is empty!\n");
		exit(0);
	}
	if(pNode == NULL){
		printf("The node is empty and cannot get next node!\n");
		exit(0);
	}
	return pNode -> pNext;
}

int addLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode){
	if(pLinkTable == NULL){
		printf("The table is empty and cannot add this node!\n");
		exit(0);
	}
	if(pNode == NULL){
		printf("The node is empty and cannot add this node!\n");
		return 0;
	}
	if(pLinkTable -> pHead == NULL){
		pLinkTable -> pHead = pNode;
		pLinkTable -> pTail = pNode;
		pLinkTable -> numOfNode = 1;
	}
	else{
		pLinkTable -> pTail -> pNext = pNode;
		pLinkTable -> pTail = pNode;
		pLinkTable -> numOfNode++;
	}
	return 0;
}
