/*************************************************************************
	> File Name: io.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年09月02日 星期三 22时09分24秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<errno.h>

/*
 * 安全读写函数
 */

ssize_t	safe_write(int fd, const void *vptr, size_t n)
{
    size_t  nleft;
    ssize_t nwritten;
    const char *ptr;

    ptr = vptr;
    nleft = n;
    
    while(nleft > 0)
    {
    	if((nwritten = write(fd, ptr, nleft)) <= 0)
        {
            if(nwritten < 0 && errno == EINTR) //被信号中断，重写
                nwritten = 0;
            else //error
                return -1;
        }
		nleft -= nwritten;
		ptr   += nwritten;
     }
	return(n);
}

ssize_t safe_read(int fd,void *vptr,size_t n)
{
    size_t nleft;
    ssize_t nread;
    char *ptr;

    ptr=vptr;
    nleft=n;

    while(nleft > 0)
    {
        if((nread = read(fd,ptr,nleft)) < 0)
        {
            if(errno == EINTR) //被信号中断，重读
                nread = 0;
            else //出错
                return -1;
        }
        else if(nread == 0) //EOF
        	break;
        	
        nleft -= nread;
        ptr += nread;
    }
    return (n-nleft);
}
