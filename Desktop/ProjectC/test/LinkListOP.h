#ifndef LINKLISTOP_H_INCLUDED
#define LINKLISTOP_H_INCLUDED

typedef struct linkTableNode{
	struct linkTableNode * pNext;
}tLinkTableNode;

typedef struct linkTable
{
	tLinkTableNode * pHead;
	tLinkTableNode * pTail;
	int numOfNode;
}tLinkTable;

tLinkTable * createLinkTable();

tLinkTableNode * getLinkTableHead(tLinkTable * pLinkTable);

tLinkTableNode * getNextLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);

int addLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);

#endif // LINKLISTOP_H_INCLUDED
