#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
int main()
{
int s_sock,c_sock;
char buf[20]="hello client";
s_sock=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in server,other;
memset(&server,0,sizeof(server));
memset(&other,0,sizeof(other));
server.sin_family=AF_INET;
server.sin_port=htons(9000);
server.sin_addr.s_addr=INADDR_ANY;
socklen_t add;
bind(s_sock,(struct sockaddr*)&server,sizeof(server));
listen(s_sock,10);
add=sizeof(other);
c_sock=accept(s_sock,(struct sockaddr*)&other,&add);
send(c_sock,buf,sizeof(buf),0);
close(s_sock);
return 0;
}
