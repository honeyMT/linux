/*************************************************************************
	> File Name: server.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Thu 22 Jun 2017 01:21:27 AM PDT
 ************************************************************************/

#include"comm.h"

int main()
{
	char buf[1024];
	int msgid = getMsgQueue();
	while(1)
	{
		printf("Please Enter# ");
		fflush(stdout);
		ssize_t s = read(0,buf,sizeof(buf)-1);
		if(s>0)
		{
			buf[s-1] = 0;
			sendMsg(msgid,CLIENT_TYPE,buf);
		}
		recvMsg(msgid,SERVER_TYPE,buf);
		printf("srver sat# %s\n",buf);
	}
	return 0;
}
