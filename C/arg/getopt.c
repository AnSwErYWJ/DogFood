/*************************************************************************
	> File Name: getopt.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Mon 06 Feb 2017 11:55:40 AM CST
 ************************************************************************/

//references: http://blog.csdn.net/cashey1991/article/details/7942809

#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

static int opt = 0;

/*
 * Usage: ./a.out -a 100 -b -c admin -d
 */
static int my_getopt(int argc, char * const argv[], const char *optstring)
{
    while ((opt = getopt(argc, argv, optstring)) != -1)
    {
        printf("opt = %c\n",opt);
        printf("optarg = %s\n", optarg);
        printf("optind = %d\n", optind); // optind: next arg's argc
        printf("argv[optind -1] = %s\n\n", argv[optind -1]);
    }
}

/*
 * Usage: ./a.out -a 100 --reqarg 100 --nonarg
 */
static int my_getopt_long(int argc, char * const argv[],  const char *optstring,const struct option *longopts, int *longindex)
{
    while ((opt = getopt_long(argc, argv, optstring, longopts, longindex)) != -1)  
    {  
        printf("opt = %c\n", opt);  
        printf("optarg = %s\n", optarg);  
        printf("optind = %d\n", optind);  
        printf("argv[optind - 1] = %s\n",  argv[optind - 1]);  
        printf("option_index = %d\n\n", *longindex);  
    }

}

//int getopt_long_only(int argc, char * const argv[], const char *optstring,const struct option *longopts,int *longindex); 

int main(int argc, char *argv[])
{
    char *optstring = "a:bc:d"; // : express that param can be followed by a value
    int option_index = 0;

    static struct option long_options[] = {  
           {"reqarg", required_argument, NULL, 'r'},  
           {"noarg",  no_argument,       NULL, 'n'},  
           {"optarg", optional_argument, NULL, 'o'},  
           {0, 0, 0, 0}  
    };

    //my_getopt(argc,argv,optstring);
    my_getopt_long(argc,argv,optstring,long_options,&option_index);

    return 0;
}
