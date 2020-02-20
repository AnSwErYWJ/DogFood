/*************************************************************************
	> File Name: io2stream.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Wed 07 Dec 2016 08:59:15 AM CST
 ************************************************************************/

/* input and output of words */

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "./tmplog"

static FILE *fp = NULL;

//static int num[2] = {-2147483648,2147483647};
static unsigned int num[2] = {4294967295,0};

static unsigned int get_uint(FILE *fp)
{
    unsigned char *s;
    unsigned int i;
    s = (unsigned char *)&i;
    s[0]=getc(fp);
    printf("%x\n",s[0]);
    s[1]=getc(fp);
    printf("%x\n",s[1]);
    s[2]=getc(fp);
    printf("%x\n",s[2]);
    s[3]=getc(fp);
    printf("%x\n",s[3]);
    return i;
}

static unsigned int put_uint(unsigned int i,FILE *fp)
{
    unsigned char *s;
    s=(unsigned char *)&i;
    putc(s[0],fp);
    //printf("%x\n",s[0]);
    putc(s[1],fp);
    //printf("%x\n",s[1]);
    putc(s[2],fp);
    //printf("%x\n",s[2]);
    putc(s[3],fp);
    //printf("%x\n",s[3]);
    return i;
}


int main(int argc,char *argv[])
{
    fp = fopen(FILENAME, "wb");
    if (!fp)
    {
        fprintf(stderr,"Error:open file: %s failed!\n",FILENAME);
        exit(EXIT_FAILURE);
    }

    if (num[0] != put_uint(num[0],fp)) //uint
    {
    	fprintf(stderr,"Error:put_uint failed!\n");
    	exit(EXIT_FAILURE);
    }
    if (num[1] != put_uint(num[1],fp)) //uint
    {
    	fprintf(stderr,"Error:put_uint failed!\n");
    	exit(EXIT_FAILURE);
    }

    //if (238 != putw(238,fp)) //int
    //{
    //	fprintf(stderr,"Error:putw failed!\n");
    //	exit(EXIT_FAILURE);
    //}

    fclose(fp);

    fp = fopen(FILENAME, "rb");
    if (!fp)
    {
        fprintf(stderr,"Error:open file: %s failed!\n",FILENAME);
        exit(EXIT_FAILURE);
    }

    //printf("%d\n",getw(fp)); //int


    unsigned int a = get_uint(fp);
    if( ferror(fp) )
    	printf("Error reading file\n");
    else
    	printf("%u\n",a); //uint

    unsigned int b = get_uint(fp);
    if( ferror(fp) )
    	printf("Error reading file\n");
    else
       	printf("%u\n",b); //uint

    fclose(fp);

    /* remove tmp file */
    if (remove(FILENAME) != 0)
    	fprintf(stderr,"Error:remove file: %s failed!\n",FILENAME);

    return 0;
}
