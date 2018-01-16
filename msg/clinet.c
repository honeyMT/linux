/*************************************************************************
	> File Name: client.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Thu 22 Jun 2017 01:02:10 AM PDT
 ************************************************************************/

#include"comm.h"

int main()
{
	char buf[1024];
	int msgid = getMsgQueue();
	while(1)
	{
		recvMsg(msgid,CLIENT_TYPE,buf);
		printf("client say# %s\n",buf);

		printf("Please Enter# ");
		fflush(stdout);
		ssize_t s = read(0,buf,sizeof(buf)-1);
		if(s > 0)
		{
			buf[s-1] = 0;
			sendMsg(msgid,SERVER_TYPE,buf);
		}
	}
	return 0;
}
