#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
int main()
{
int c_sock;
char buf[20]="hello server";
c_sock=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in client;
memset(&client,0,sizeof(client));
client.sin_family=AF_INET;
client.sin_port=htons(9000);
client.sin_addr.s_addr=INADDR_ANY;
if(connect(c_sock,(struct sockaddr*)&client,sizeof(client))==-1)
{
printf("server is busy connection failure");
return 0;
}
recv(c_sock,buf,sizeof(buf),0);
printf("msg from server: %s",buf);
close(c_sock);
return 0;
}
