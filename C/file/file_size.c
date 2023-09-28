#include <stdio.h>
#include <sys/stat.h>

int file_size(const char *filepath)
{
    struct stat statbuf;

    stat(filepath,&statbuf);

    int size = statbuf.st_size;
    
    return size;
}

int main(int argc,const char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr,"Usage: ./file_size filepath\n");
        return -1;
    }

    printf("size : %d\n",file_size(argv[0]));

    return 0;
}
