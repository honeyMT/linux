/*************************************************************************
	> File Name: comm.h
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Wed 21 Jun 2017 11:45:19 PM PDT
 ************************************************************************/

#ifndef _COMM_H__
#define _COMM_H__

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<string.h>
#include<time.h>
#define SERVER_TYPE 1
#define CLIENT_TYPE 2
#define PATHNAME "."
#define PROJ_ID 0x6666

struct msgbuf{
	long mtype;
	char mtext[1024];
};

int creatMsgQueue();
int getMsgQueue();
int destroyMsgQueue(int msgid);
int recvMsg(int msgid, int who,char* _outMsg);
int sendMsg(int msgid,int who,const char *msg);

#endif // _COMM_H__
