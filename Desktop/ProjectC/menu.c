//
/* Copyright  (C) LS, 2014-2015                                                                   */
/* FILE NAME             :  menu.c                                                                */
/* PRINCIPAL AUTHOR      :  ls                                                                 */
/* SUBSYSTEM NAME        :  menu                                                                  */
/* MODULE NAME           :  menu                                                                  */
/* LANGUAGE              :  C                                                                     */
/* TAGRGET ENVIRONMENT   :  ANY                                                                   */
/* DATE OF FIRST RELEASE :  2014/12/21                                                            */
/* DESCRIPTION           :  This is a menu progrom                                                */
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
#include "linktable.h"


int Help();
int Quit();


#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

typedef struct DataNode{
    tLinkTableNode * pNext;
    char * cmd;
    char * desc;
}DataNode;

int InitMenuData(tLinkTable ** ppLinkTable)
{
     *ppLinkTable = CreateLinkTable();
     tDataNode * pNode = (tDataNode*)malloc(sizeof(tDataNode));
     pNode->cmd = "help";
     pNode->desc = "Menu List:";
     pNode->handler = Help;
     AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);
     
     pNode = (tDataNode*)(tDataNode*)malloc(sizeof(tDataNode));
     pNode->cmd = "version";
     pNode->desc = "Menu Program V2.5";
     pNode->handler = NULL;
     AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);
     
     pNode = (tDataNode*)malloc(sizeof(tDataNode));
     pNode->cmd = "quit";
     pNode->desc = "Bye~";
     pNode->handler = Quit;
     AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);
     
     pNode = (tDataNode*)malloc(sizeof(tDataNode));
     pNode->cmd = "hello";
     pNode->desc = "hello :)";
     pNode->handler = NULL;
     AddLinkTableNode(*ppLinkTable, (tLinkTableNode*)pNode);
   
     return 0; 
}

tLinkTable * head = NULL;
int main ()
{
    InitMenuData(&head);
    /* cmd line begins */
    while (1)
    {
     char cmd[CMD_MAX_LEN];
	 printf("Input a cmd number > ");
	 scanf("%s", cmd);
	 tDataNode *p = FindCmd(head, cmd);
         if (p == NULL)
	 {
	      printf("This is a wrong cmd!\n");
	      continue;
	 }

	 printf("%s - %s\n", p->cmd, p->desc);
         if (p->handler != NULL)
	 {
	      p->handler();
	 }

    }
}

int Help()
{
     ShowAllCmd(head);
     return 0;
}

int Quit()
{
    exit(0);
    return 0;
}