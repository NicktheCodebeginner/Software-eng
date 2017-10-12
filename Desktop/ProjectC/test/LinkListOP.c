#include <stdio.h>
#include "LinkListOP.h"

/*tlinkTableNode * createLinkTable(){
	tLinkTable * pTable = (tLinkTable *)malloc(sizeof(tLinkTable));
	pTable -> pHead = NULL;
	pTable -> pTail = NULL;
	pTable -> numOfNode = 0;
	return pTable;
}

int delLinkTable(tLinkTable * pLinkTable){
	free(pLinkTable);
	return 0;
}

tLinkTableNode * getLinkTableHead(tLinkTable * pLinkTable){
	if(pLinkTable == NULL){
		printf("The table is empty!\n");
		exit(0);
	}
	return pLinkTable -> pHead;
}

tlinkTableNode * getNextLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode){
	if(pLinkTable == NULL){
		printf("The table is empty!\n");
		exit(0);
	}
	if(pNode == NULL){
		printf("The node is empty and cannot get next node!\n");
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
		pLlinkTable -> numOfNode++;
	}
	return 0;
}
