//
/* Copyright  (C) LS, 2014-2015                                                                   */
/* FILE NAME             :  linktable.c                                                           */
/* PRINCIPAL AUTHOR      :  ls                                                                    */
/* SUBSYSTEM NAME        :  menu                                                                  */
/* MODULE NAME           :  linktalbe                                                             */
/* LANGUAGE              :  C                                                                     */
/* TAGRGET ENVIRONMENT   :  ANY                                                                   */
/* DATE OF FIRST RELEASE :  2014/12/28                                                            */
/* DESCRIPTION           :  interface of Link Table                                               */
//

/*
 * Revision log:
 * 
 * Created by ls, 2014/12/28
 *
 */

#include "linktable.h"

/*
 * Create a LinkTable
 */
tLinkTable * CreateLinkTable()
{
     tLinkTable *pTable = (tLinkTable*)malloc(sizeof(tLinkTable));
     if(pTable == NULL){
          return NULL;
     }
     pTable->pHead = NULL;
     pTable->pTail = NULL;
     pTable->SumOfNode = 0;

     return pTable;
}

/*
 * Delete a LinkTable
 */
int DeleteLinkTable(tLinkTable *pLinkTable)
{
     if(pLinkTable == NULL)
          return NULL;
     while(pLinkTable -> pHead != NULL){
          tLinkTableNode * pNode = pLinkTable -> pHead;
          pLinkTable -> pHead = pLinkTable -> pHead -> pNext;
          free(pNode);
          pLinkTable -> SumOfNode--;
     }
     pLinkTable -> pHead = NULL;
     pLinkTable -> pTail = NULL;
     free(pLinkTable);
     return 0; 
}

/*
 * Add LinkTableNode to LinkTable
 */
int AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
     if (pLinkTable == NULL) 
     {
          printf("The table is empty and cannot add this node!\n");
	     exit(0); 
     }

     if (pNode == NULL)
     {
          printf("The node is empty and cannot add this node!\n");
	     return 0;
     }

     if (pLinkTable->pHead == NULL)
     {
          pLinkTable->pHead = pNode;
	     pLinkTable->SumOfNode = 1;
     }
     if (pLinktable -> pTail == NULL){
          pLinkTable -> pTail = pNode;
     }
     else
     {
          pLinkTable->pTail->pNext = pNode;
	     pLinkTable->pTail = pLinkTable -> pTail -> pNext;
     }
     pLinkTable->SumOfNode++; 
     return 0;
}

/*
 * Delete a LinkTableNode from LinkTable
 */
int DelLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
    /* if (pLinkTable == NULL) 
     {
          printf("The table is empty and cannot delete this node!\n");
	  exit(0); 
     }

     if (pNode == NULL)
     {
          printf("The node is empty and cannot delete this node!\n");
	  return 0;
     }
    
     tLinkTableNode *p = pLinkTable->pHead;
     while */ 
}

/*
 * Get LinkTableHead
 */
tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable)
{
     if (pLinkTable == NULL || pLinkTable -> pHead == NULL) 
     {
          return NULL; 
     }
     return pLinkTable->pHead;
}

/*
 * Get Next LinkTableNode
 */
tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
     if (pLinkTable == NULL || pNode == NULL) 
     {
          return NULL;
     }
     tLinkTableNode * p = pLinkTable -> pHead;
     while(p != NULL){
          if(p == pNode)
               return p -> pNext;
          p = p -> pNext;
     }
     return NULL;
}