//#define _GNU_SOURCE // for pthread_getname_np/pthread_setname_np

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#ifndef  _GNU_SOURCE 
#include <sys/prctl.h>
#endif

#define NAME_MAX_LEN    (16)
#define MAIN_PTHREAD_NAME    "MAIN_PTHREAD"
#define SUB_PTHREAD_NAME     "SUB_PTHREAD"

static void *threadFunc(void *parm)
{
    int ret;
    char pthread_name[NAME_MAX_LEN] = {0};

#ifndef  _GNU_SOURCE 
    ret = prctl(PR_GET_NAME, pthread_name);
    if (ret != 0)
    {
        fprintf(stderr, "get sub pthread name failed: %d.\n", ret);
        return NULL;
    }
 
    printf("sub pthread default name before setting is: %s\n", pthread_name);

    ret = prctl(PR_SET_NAME, SUB_PTHREAD_NAME);
    if (ret != 0)
    {
        fprintf(stderr, "set sub pthread name failed: %d.\n", ret);
        return NULL;
    }
 
    ret = prctl(PR_GET_NAME, pthread_name);
    if (ret != 0)
    {
        fprintf(stderr, "get sub pthread name failed: %d.\n", ret);
        return NULL;
    }

    printf("sub pthread name after setting is: %s\n", pthread_name);
#endif

    sleep(2);

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t thread;
    int ret;
    char pthread_name[NAME_MAX_LEN] = {0};

#ifdef  _GNU_SOURCE 
    ret = pthread_getname_np(pthread_self(), pthread_name, NAME_MAX_LEN);
#else
    ret = prctl(PR_GET_NAME, pthread_name);
#endif
    if (ret != 0)
    {
        fprintf(stderr, "get main pthread name failed: %d.\n", ret);
        return -1;
    }
 
    printf("main pthread default name before setting is: %s\n", pthread_name);
 
#ifdef  _GNU_SOURCE 
    ret = pthread_setname_np(pthread_self(), MAIN_PTHREAD_NAME);
#else
    ret = prctl(PR_SET_NAME, MAIN_PTHREAD_NAME);
#endif
    if (ret != 0)
    {
        fprintf(stderr, "set main pthread name failed: %d.\n", ret);
        return -1;
    }
 
#ifdef  _GNU_SOURCE 
    ret = pthread_getname_np(pthread_self(), pthread_name, NAME_MAX_LEN);
#else
    ret = prctl(PR_GET_NAME, pthread_name);
#endif
    if (ret != 0)
    {
        fprintf(stderr, "get main pthread name failed: %d.\n", ret);
        return -1;
    }
 
    printf("main pthread default name after setting is: %s\n", pthread_name);

    ret = pthread_create(&thread, NULL, threadFunc, NULL);
    if (ret != 0)
    {
        fprintf(stderr, "pthread_create failed: %d.\n", ret);
        return -1;
    }

#ifdef  _GNU_SOURCE 
    ret = pthread_getname_np(thread, pthread_name, NAME_MAX_LEN);
    if (ret != 0)
    {
        fprintf(stderr, "get sub pthread name failed: %d.\n", ret);
        return -1;
    }
 
    printf("sub pthread default name before setting is: %s\n", pthread_name);

    ret = pthread_setname_np(thread, SUB_PTHREAD_NAME);
    if (ret != 0)
    {
        fprintf(stderr, "set sub pthread name failed: %d.\n", ret);
        return -1;
    }
 
    ret = pthread_getname_np(thread, pthread_name, NAME_MAX_LEN);
    if (ret != 0)
    {
        fprintf(stderr, "get sub pthread name failed: %d.\n", ret);
        return -1;
    }

    printf("sub pthread name after setting is: %s\n", pthread_name);
#endif

    ret = pthread_join(thread, NULL);
    if (ret != 0)
    {
        fprintf(stderr, "pthread_join failed: %d.\n", ret);
        return -1;
    }
 
    return 0;
}