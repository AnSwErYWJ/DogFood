#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

static int _is_file_exist(const char *filepath)
{
    if(access(filepath,F_OK) == 0)
        printf("%s is exist.\n",filepath);
    else
        printf("%s is not exist.\n",filepath);
}

static int _is_file_readable(const char *filepath)
{  
    if(access(filepath,R_OK) == 0)
        printf("%s is readable.\n",filepath);
    else
        printf("%s is not readable.\n",filepath);
    
}

static int _is_file_writeable(const char *filepath)
{  
    if(access(filepath,W_OK) == 0)
        printf("%s is writeable.\n",filepath);
    else
        printf("%s is not writeable.\n",filepath);
    
}

static int _is_file_executable(const char *filepath)
{  
    if(access(filepath,X_OK) == 0)
        printf("%s is executable.\n",filepath);
    else
        printf("%s is not executable.\n",filepath);
    
}

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr,"Usage: ./a.out filepath\n");
        exit(1);
    }

    _is_file_exist(argv[1]);
    _is_file_readable(argv[1]);
    _is_file_writeable(argv[1]);
    _is_file_executable(argv[1]);

    return 0;
    
}
