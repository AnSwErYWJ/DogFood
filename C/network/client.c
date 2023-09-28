#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/tcp.h>
#include<strings.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>

#define MAXSLEEP 128
#define PORT 80
#define MAXSIZE 4096

static struct sockaddr_in servaddr;
static int ret,fd;

/*Set client opt*/
int client_init(const unsigned short int port,const char *hostname)
{
    int sockfd;
    struct hostent *h;
    char ip[16];

    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
    {
        perror("Socket Error");
        exit(EXIT_FAILURE);
    }

    int flags = fcntl(sockfd,F_GETFL,0);
    if(fcntl(sockfd,F_SETFL,flags|O_NONBLOCK) < 0)
    {
        fprintf(stderr,"Error:fcntl failed!");
        exit(EXIT_FAILURE);
    }

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);

    if (inet_pton(servaddr.sin_family,hostname,(void *)&servaddr.sin_addr) > 0)
    {
        printf("Server ip is %s\n",hostname);
    }
    else if ((h = gethostbyname(hostname)) != NULL)
    {
        inet_ntop(servaddr.sin_family,h->h_addr,ip,sizeof(ip));
        printf("%s's ip is %s\n",hostname,ip);
        inet_pton(servaddr.sin_family,ip,(void *)&servaddr.sin_addr);
    }
    else
    {
        fprintf(stderr,"Hostname is invailed: %s\n",hostname);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

int my_connect(int sockfd,const struct sockaddr *servaddr,socklen_t addrlen)
{
    int nsec;
    for(nsec = 1;nsec <= MAXSLEEP;nsec <<= 1)
    {
        if(connect(sockfd,servaddr,addrlen) == 0)
        return 0;
        if(nsec <= MAXSLEEP/2)
        sleep(nsec);
    }
    return -1;   
}

int main(int argc ,const char *argv[])
{

    if(argc != 2)
    {
        fprintf(stderr,"Usage: Please input ServerName!\n");
        exit(EXIT_FAILURE);
    }

    if((fd = client_init(PORT,argv[1])) < 0)
    {
        fprintf(stderr,"Client Init Error\n");
        exit(EXIT_FAILURE);
    }

    ret = my_connect(fd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    fd_set rset,wset;
    FD_ZERO(&rset);
    FD_ZERO(&wset);
    FD_SET(fd,&rset);
    FD_SET(fd,&wset);


    if(ret == 0)
        printf("Connect succeed!\n");
    else
    {
        if(errno == EINPROGRESS)
        {
            if(select(fd+1,&rset,&wset,NULL,NULL) < 1)
            {
                fprintf(stderr,"Select Error\n");
                exit(EXIT_FAILURE);
            }
            if(FD_ISSET(fd,&rset) && FD_ISSET(fd,&wset))
            {
                int error = 0;
                socklen_t len = sizeof(error);
                if(getsockopt(fd,SOL_SOCKET,SO_ERROR,&error,&len)<0)
                    exit(EXIT_FAILURE);
                printf("error = %d\n",error);
                if(error != 0)// not connect
                {
                    fprintf(stderr,"Error:Connect failed\n");
                    exit(EXIT_FAILURE);
                }
            }
            if((!FD_ISSET(fd,&rset)) && FD_ISSET(fd,&wset))
                printf("Connect succeed!!\n");
        }
        else
        {
            fprintf(stderr,"Error:Connect failed\n");
            exit(EXIT_FAILURE);
        }
    }
   
    char http_req[1024];
    memset(http_req,0,sizeof(char)*1024);
    sprintf(http_req,"GET /index.html HTTP/1.1\nHost:%s\nConnection:close\n\n",argv[1]);


    ret = send(fd,http_req,strlen(http_req)+1,0);
    if(ret < 0)
    {
        fprintf(stderr,"Send Error\n");
        exit(EXIT_FAILURE);
    }
    printf("Send succeed\n");
    
    FILE *fp = fopen("response.txt","wb");
    if(!fp)
    {
        fprintf(stderr,"File Open Error\n");
        exit(EXIT_FAILURE);
    }
    
    while(1)
    {
        char http_res[MAXSIZE];
        memset(http_res,0,sizeof(char)*MAXSIZE);

        FD_ZERO(&rset);
        FD_ZERO(&wset);
        FD_SET(fd,&rset);

        if(select(fd+1,&rset,NULL,NULL,NULL) < 1)
        {
            fprintf(stderr,"Select Error\n");
            exit(EXIT_FAILURE);
        }
        
        if(FD_ISSET(fd,&rset))
        {
            ret = recv(fd,http_res,sizeof(char)*MAXSIZE,0);

            /*receive error*/
            if(ret < 0)
            {
                /*no data in buffer*/
                if(errno == EAGAIN || errno == EINTR || errno == EWOULDBLOCK)
                    continue;
                else
                {
                    fprintf(stderr,"RECV ERROR\n");
                    exit(EXIT_FAILURE);
                }
            }

            /*receive over,server close the connection*/
            if(ret == 0)
            {
                fprintf(stderr,"Server close the connection\n");
                break;
            }
            fputs(http_res,fp);
        }
    }

    printf("Write done\n");
    fclose(fp);
    close(fd);
    return 0;
}
