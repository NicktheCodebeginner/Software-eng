
/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  Mengning                                                             */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/08/31                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Mengning, 2014/08/31
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "linktable.h"
#include "menu.h"

int Help();
//int Quit();


#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10
#define CMD_MAX_ARGV_NUM 32

char cmd[CMD_MAX_LEN];

/* data struct and its operations */

typedef struct DataNode
{
    tLinkTableNode * pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)(int argc, char * argv[]);
} tDataNode;

int SearchCondition(tLinkTableNode * pLinkTableNode, void * cmd)
{
    tDataNode * pNode = (tDataNode *)pLinkTableNode;
    if(strcmp(pNode->cmd, cmd) == 0)
    {
        return  SUCCESS;
    }
    return FAILURE;
}

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tLinkTable * head, char * cmd)
{
    if(head == NULL)
    {
        printf("Don't exist this table!");
        return NULL;
    }
    return  (tDataNode*)SearchLinkTableNode(head,SearchCondition,(void *)cmd);
}

/* show all cmd in listlist */
int ShowAllCmd(tLinkTable * head)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}

/*int InitMenuData(tLinkTable ** ppLinktable)
{
    *ppLinktable = CreateLinkTable();
    tDataNode* pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "help";
    pNode->desc = "Menu List:";
    pNode->handler = Help;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "version";
    pNode->desc = "Menu Program V1.0";
    pNode->handler = NULL;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    /*pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "quit";
    pNode->desc = "Quit from Menu Program V1.0";
    pNode->handler = Quit;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);

    return 0;
}
*/
/* menu program */

tLinkTable * head = NULL;

int MenuConfig(char *cmd, char *desc, int (*handler)(int argc, char *argv[]))
{
    tDataNode* pNode = NULL;
    if (head == NULL)
    {
        head = CreateLinkTable();
        pNode = (tDataNode*)malloc(sizeof(tDataNode));
        pNode->cmd = "help";
        pNode->desc = "Menu List:";
        pNode->handler = Help;
        AddLinkTableNode(head, (tLinkTableNode*)pNode);
    }
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = cmd;
    pNode->desc = desc;
    pNode->handler = handler;
    AddLinkTableNode(head, (tLinkTableNode*)pNode);
    return 0;
}

int RecvCmd(char *cmd, int *argc, char *argv[])
{
    char *pcmd = NULL;
    pcmd = fgets(cmd, CMD_MAX_LEN, stdin);

    int len = strlen(cmd);
    *(cmd + len - 1) = '\0';
    pcmd = cmd;

    //Get the argument's number and vector from the user input
    pcmd = strtok(pcmd, " ");

    //If the user doesn't input anything, turn to next loop
    if (pcmd == NULL)
    {
        //printf("Hi, -1 is here.\n");
        return -1;
    }

    while (pcmd != NULL && (*argc) < CMD_MAX_ARGV_NUM)
    {
        //printf("%s\n", pcmd);
        argv[*argc] = pcmd;
        (*argc)++;
        pcmd = strtok(NULL, " ");
    }

    return 0;
}

/* menu program */
int ExecuteMenu()
{
    int argc;
    char cmd[CMD_MAX_LEN];
    char *pcmd = NULL;
    char *argv[CMD_MAX_ARGV_NUM];

    while(1)
    {
        argc = 0;
        printf("Please input a cmd >");

        if (RecvCmd(cmd, &argc, argv) == -1)
            continue;
        tDataNode* p = FindCmd(head, argv[0]);
        if (p == NULL)
        {
            printf("You have entered a wrong cmd.\n");
            printf("Please use 'help' to get the command!\n");
            continue;
        }
        printf("%s\t - \t%s\n", p -> cmd, p -> desc);
        if (p -> handler != NULL)
            p -> handler(argc, argv);
        printf("\n");
    }

    return 0;
}

int Help(int argc, char** argv)
{
    const char *optString = "at";
    int whileflag = 0, deflag = 0;
    int opt, len;

    optind = 0;
    opterr = 0;
    if (argc == 1)
    {
        ShowAllCmd(head);
        return 0;
    }
    //printf("optind: %d, opterr: %d\n", optind, opterr);
    while ((opt = getopt(argc, argv, optString)) != -1)
    {
        ++whileflag;
        //Use for -t option for specific cmd help search
        char *scmd;
        if (deflag == 1)  break;
        tDataNode *pscmd;
        //printf("optind: %d, argc: %d, argv[%d]: %s\n", optind, argc, optind - 1, argv[optind - 1]);
        switch (opt)
        {
            case '-':
                break;
            case 'a':
                printf("This is -a option of help to show all commands.\n");
                printf("It's also the default one.\n");
                ShowAllCmd(head);
                deflag = 1;
                break;
            case 't':
                //scmd = optarg;
                printf("This is -t option of help to show one specific command in our command system.\n");
                printf("please input the command you want to see its help.\n");
                fgets(scmd, CMD_MAX_ARGV_NUM, stdin);
                printf("%s", scmd);
                len = strlen(scmd);
                scmd[len - 1] = '\0';
                pscmd = FindCmd(head, scmd);
                if (pscmd == NULL)
                    printf("No such command!\n");
                else
                    printf("The '%s' command's help is:\n%s\n", scmd, pscmd -> desc);
                deflag = 1;
                break;
            default:
                printf("Wrong option! please check the help.\n");
                deflag = 1;
                break;
        }
    }
    if (whileflag ==0 && argc > 1)
        printf("Wrong option! Please check the help.\n");
    //printf("opt is %d\n", opt);
    return 0;
}

