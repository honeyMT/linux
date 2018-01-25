/*************************************************************************
	> File Name: comm.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Wed 21 Jun 2017 11:50:33 PM PDT
 ************************************************************************/

#include"comm.h"

static int commMsgQueue(int flags)
{
	key_t _key = ftok(PATHNAME,PROJ_ID);
	if(_key < 0){
		perror("ftok");
		return -1;
	}
	int msgid = 0;
	if(msgid = msgget(_key, flags)<0){
		perror("msgget");
		return -2;
	}
	return msgid;
}

int creatMsgQueue()
{
	return commMsgQueue(IPC_CREAT|IPC_EXCL|0666);
}

int getMsgQueue()
{
	return commMsgQueue(IPC_CREAT);
}

int destroyMsgQueue(int msgid)
{
	if(msgctl(msgid,IPC_RMID,NULL) < 0){
		perror("msgctl");
		return -1;
    }
}

int recvMsg(int msgid, int type,char* _outMsg)
{
	struct msgbuf _mb;
	if(msgrcv(msgid,&_mb,sizeof(_mb.mtext),type,0)< 0){
		perror("msgrcv");
		return -1;
	}
	strcpy(_outMsg,_mb.mtext);
	return 0;
}

int sendMsg(int msgid,int who,const char *msg)
{
	struct msgbuf _mb;
	_mb.mtype = who;
	strcpy(_mb.mtext,msg);
	if(msgsnd(msgid,(void*)&_mb,sizeof(_mb.mtext),0) < 0)
	{
		perror("msgsnd");
		return -1;
	}
	return 0;
}

