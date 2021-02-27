#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
int main()
{
    struct sockaddr_in client;
    int c_sock;
    char buf1[20],buf2[20];
    c_sock=socket(AF_INET,SOCK_DGRAM,0);
    client.sin_family=AF_INET;
    client.sin_port=htons(9009);
    client.sin_addr.s_addr=INADDR_ANY;
    printf("\nClient ready....\n");
    socklen_t n;
    n=sizeof(client);
    while(1)
    {
        printf("\nClient:");
        gets(buf2);
        sendto(c_sock,buf2,sizeof(buf2),0,(struct sockaddr *) &client,n);
        if(strcmp(buf2,"end")==0)
            break;
        recvfrom(c_sock,buf1,sizeof(buf1),0,NULL,NULL);
        printf("\nclient:%s",buf1);
    }

close(c_sock);
return 0;

}


