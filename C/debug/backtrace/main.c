/*************************************************************************
	> File Name: main.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Wed 28 Dec 2016 04:11:45 PM CST
 ************************************************************************/

#include "backtrace.h"
#include <signal.h>

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
