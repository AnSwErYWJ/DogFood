/*************************************************************************
	> File Name: t_cond.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Tue 12 Dec 2017 08:39:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int condition;
    pthread_t pid;
    pthread_mutex_t mut;
    pthread_cond_t cond;
}test_t;

/* 静态初始化 */
//static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
//static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static void *_run(void *arg)
{
    test_t *test = arg;
    pthread_mutex_lock(&(test->mut));

    while (test->condition == 0)
    {
        printf("test _run is to wait\n");
        pthread_cond_wait(&(test->cond), &(test->mut));
    }
    
    test->condition = -1;
    printf("test modify test->condition to %d\n", test->condition);
    pthread_mutex_unlock(&(test->mut));
}


int main(void)
{
    printf("test start\n");
    
    test_t *test = (test_t *)calloc(1, sizeof(test_t));
    if (!test)
    {
        fprintf(stderr,"calloc error\n");
        exit(EXIT_FAILURE);
    }

    int ret;
    test->condition = 0;

    ret = pthread_mutex_init(&(test->mut), NULL);
    if (ret != 0)
    {
        fprintf(stderr,"pthread_mutex_init error, errno is %d\n", ret);
        exit(EXIT_FAILURE);
    }
    
    ret = pthread_cond_init(&(test->cond), NULL);
    if (ret != 0)
    {
        fprintf(stderr,"pthread_cond_init error, errno is %d\n", ret);
        exit(EXIT_FAILURE);
    }

    ret = pthread_create(&(test->pid), NULL, _run, test);
    if (ret != 0)
    {
        fprintf(stderr,"pthread_create error, errno is %d\n", ret);
        exit(EXIT_FAILURE);
    }

    sleep(1); 
    pthread_mutex_lock(&(test->mut));
    test->condition = 1;
    printf("test modify test->condition to %d\n", test->condition);
    pthread_cond_signal(&(test->cond));
    pthread_mutex_unlock(&(test->mut));
 

    ret = pthread_join(test->pid, NULL);
    if (ret != 0)
    {
        fprintf(stderr,"pthread_join error, errno is %d\n", ret);
        exit(EXIT_FAILURE);
    }

    ret = pthread_mutex_destroy(&(test->mut));
    if (ret != 0)
    {
        fprintf(stderr,"pthread_mutex_destroy error, errno is %d\n", ret);
        exit(EXIT_FAILURE);
    }
    ret = pthread_cond_destroy(&(test->cond));
    if (ret != 0)
    {
        fprintf(stderr,"pthread_cond_destroy error, errno is %d\n", ret);
        exit(EXIT_FAILURE);
    }

    free(test);
    test = NULL;
    
    printf("test end\n");

    return 0;
}

