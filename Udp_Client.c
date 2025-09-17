#include<stdio.h>

#include<sys/types.h>

#include<netinet/in.h>

#include<sys/socket.h>

#include<string.h>

void main()

int csd.len:

charsendmsg[30],recvmsg[20];

structsockaddr_incliaddr,servaddr;

csd=socket(AF INET,SOCK STREAM,0);

servaddr.sin_family=AF_INET;

servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

servaddr.sin_port=htons(33345);

connect(csd, (structsockaddr*) &servaddr,sizeof(servaddr));

printf("\nEnter the message:\n");

fgets(sendmsg,20,stdin);

len=strlen(sendmsg);

sendmsg[len-1]=\0';

send(csd,sendmsg,20,0);

}
