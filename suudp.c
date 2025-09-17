#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
main()
{
    int sd, sport, len;
    char sendmsg[30], recvmsg[20];
    struct sockaddr_in servaddr, cliaddr;

    sd = socket(AF_INET, SOCK_DGRAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(12345);

    bind(sd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    len = sizeof(cliaddr);
    printf("\nClient says:");
    wait(20);
    recvfrom(sd, recvmsg, 20, 0, (struct sockaddr*)&cliaddr, &len);
    printf("%s", recvmsg);
}
