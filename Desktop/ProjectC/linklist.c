//
/* Copyright  (C) LS, 2014-2015                                                                   */
/* FILE NAME             :  linklist.c                                                            */
/* PRINCIPAL AUTHOR      :  LISUN                                                                 */
/* SUBSYSTEM NAME        :  menu                                                                  */
/* MODULE NAME           :  linklist                                                                  */
/* LANGUAGE              :  C                                                                     */
/* TAGRGET ENVIRONMENT   :  ANY                                                                   */
/* DATE OF FIRST RELEASE :  2014/12/21                                                            */
/* DESCRIPTION           :  linklist for the  menu progrom                                                */
//

/*
 * Revision log:
 * 
 * Created by ls, 2014/12/28
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"


tDataNode* FindCmd(tLinkTable * head, char* cmd)
{
     if (head == NULL || cmd == NULL)
     {
          return NULL;
     }
     tDataNode *pNode = (tDataNode*)GetLinkTableHead(head);
     while (pNode != NULL)
     {
          if (strcmp(p->cmd, cmd) == 0)
          {
               return pNode;
          }
          p = (tDataNode*)GetNextLinkTableNode(head, (tLinkTableNode*)pNode);
      }
      return NULL;
} 

/* Show all the cmd in Listlist */
int ShowAllCmd(tLinkTable * head)
{
     printf("Menu List:\n");
     tDataNode *pNode = (tDataNode*)GetLinkTableHead(head);
     while (pNode != NULL)
     {
          printf("%s - %s\n", p->cmd, p->desc);
	  pNode = (tDataNode*)GetNextLinkTableNode(head, (tLinkTableNode*)pNode);
     }

     return 0;

}