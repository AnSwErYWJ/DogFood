#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

static unsigned int is_finished = 0;

void *new_thread(void *arg)
{
    pthread_t newtid = pthread_self();

    printf("new_thread: pid is %lu.\n", newtid);
    
    sleep(3);

    is_finished = 1;

    pthread_exit(NULL);
}

int main(void)
{
    pthread_t tid;
    pthread_attr_t attr;
    int ret;

    /* calloc memory space and init */
	ret = pthread_attr_init(&attr);
    if (ret != 0)
    {
        fprintf(stderr,"Error pthread_attr_init.\n");
        exit(EXIT_FAILURE);
    }
	
    /* set detach state */
    ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (ret != 0)
    {
        fprintf(stderr,"Error pthread_attr_setdetachstate.\n");
        exit(EXIT_FAILURE);
    }

	ret = pthread_create(&tid, &attr, new_thread, NULL); // note: new_thread may be finished when pthread_create is not return !!!
    if (ret != 0)
    {
        fprintf(stderr,"Error pthread_create.\n");
        exit(EXIT_FAILURE);
    }

    /* free memory space */
	pthread_attr_destroy(&attr);

    /* to show new_thread is not finished */
    while(!is_finished)
    {
        printf("new_thread is not finished.\n");
        sleep(1);
    }

    return 0;
}