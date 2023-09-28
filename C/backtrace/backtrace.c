// gcc -g -rdynamic backtrace.c

#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>
#include <signal.h>

/* stack's max depth to print */
#define DUMP_STACK_DEPTH_MAX 20

#define BACKTRACE() \
        do {\
            void *array[DUMP_STACK_DEPTH_MAX];\
            char **strings = NULL;\
            size_t depth = 0;\
            size_t i = 0;\
            \
            /* get function address from stack */\
            depth = backtrace(array,DUMP_STACK_DEPTH_MAX);\
            \
            /* address transform to information to print */\
            strings = (char **)backtrace_symbols(array,depth);\
            if (!strings)\
            {\
                perror("backtrace_symbols");\
                exit(EXIT_FAILURE);\
            }\
            \
            /* print */\
            printf("Obtained %zd stack frames:\n",depth);\
            for(i = 0;i < depth;i++)\
            {\
                printf("%s \n",strings[i]);\
            }\
            \
            free(strings);\
            strings = NULL;\
            \
        } while(0)



void two()
{
    BACKTRACE();
}

void one()
{
    two();
}

void signal_handler(int sig)
{
    switch(sig)
    {
        case SIGSEGV: // segmentation fault
        case SIGFPE: // errnoeous arithmetic operation
        case SIGBUS: // bus error
            BACKTRACE();
            exit(EXIT_FAILURE);
            break;
        default:
            break;
    }
}

int main(int argc, char **argv)
{
    signal(SIGSEGV, signal_handler);
    signal(SIGFPE, signal_handler);
    signal(SIGBUS, signal_handler);

    one();
    
    return 0;
}
