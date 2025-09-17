#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>

void main()
{
int csd, cport, len, len1;
char sendmsg[30], recvmsg[20];
struct sockaddr_in cliaddr, servaddr;

csd = socket(AF_INET, SOCK_DGRAM, 0);

    cliaddr.sin_family = AF_INET;
    cliaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    cliaddr.sin_port = htons(12345);

    len1 = sizeof(cliaddr);

    printf("\nclient says:\n");
    fgets(sendmsg, 20, stdin);

    len = strlen(sendmsg);
    sendmsg[len-1] = '\0';

    sendto(csd, sendmsg, len, 0, (struct sockaddr*)&cliaddr, len1);
}
