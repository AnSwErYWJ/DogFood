/*
 * judge host byteorder
 */

#include <stdio.h>
#include <stdlib.h>

union _byteorder
{
    short s;
    char c[2];
};

int main(void)
{
    union _byteorder un;

    un.s = 0x0102;
    
    if(sizeof(short) == 2)
    {
        if(un.c[0] == 2 && un.c[1] == 1)
            printf("little-endian\n");
        else if(un.c[0] == 1 && un.c[1] == 2)
            printf("big-endian\n");
        else
            fprintf(stderr,"Error:can not judge host byte order.\n");
    }
    else
        printf("sizeof(short) = %ld\n",sizeof(short));
    
    exit(EXIT_SUCCESS);
}
