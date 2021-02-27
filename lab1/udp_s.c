#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
int main()
{
 struct sockaddr_in client,server;
    int s_sock;
    char buf1[20],buf2[20];
    s_sock=socket(AF_INET,SOCK_DGRAM,0);
    server.sin_family=AF_INET;
    server.sin_port=htons(9009);
    server.sin_addr.s_addr=INADDR_ANY;
    bind(s_sock,(struct sockaddr *)&server,sizeof(server));
    printf("\nServer ready,waiting for client\n");
socklen_t n;
    n=sizeof(client);
    while(1)
    {
        recvfrom(s_sock,buf1,sizeof(buf1),0,(struct sockaddr *) &client,&n);
        if(!(strcmp(buf1,"end")))
            break;
        printf("\nmsg from Client:%s",buf1);
        printf("\nServer:");
        gets(buf2);
        sendto(s_sock,buf2,sizeof(buf2),0,(struct sockaddr *) &client,n);
              
    }

close(s_sock);
return 0;
 
}
