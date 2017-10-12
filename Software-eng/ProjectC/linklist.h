//
/* Copyright  (C) LS, 2014-2015                                                                   */
/* FILE NAME             :  linklist.h                                                            */
/* PRINCIPAL AUTHOR      :  ls                                                                    */
/* SUBSYSTEM NAME        :  menu                                                                  */
/* MODULE NAME           :  linklist                                                              */
/* LANGUAGE              :  C                                                                     */
/* TAGRGET ENVIRONMENT   :  ANY                                                                   */
/* DATE OF FIRST RELEASE :  2014/12/21                                                            */
/* DESCRIPTION           :  linklist for menu progrom                                             */
//

/*
 * Revision log:
 * 
 * Created by ls, 2014/12/28
 *
 */

#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
#include "linktable.h" 

/* data struct and its operations */

typedef struct DataNode
{
    tLinkTableNode *pNext;
    char*    cmd;
    char*    desc;
    int      (*handler)();
} tDataNode;

/* find a cmd in the linklist and return the data node pointer */
tDataNode * FindCmd(tLinkTable *head, char *cmd);
/* show all cmd in linklist */
int ShowAllCmd(tLinkTable *head);

#endif /*_Link_LIST_H_*/