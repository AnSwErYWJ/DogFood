#include <stdio.h>

int check_argument(int argc, const char *argv[])
{
    int i;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s arguments\n", argv[0]);
        return -1;
    }

    for (i = 0; argv[i] != NULL; i++)
        printf("argv[%d]:%s\n", i, argv[i]);

    return 0;
}