/*************************************************************************
> File Name: backtrace.h
> Author: weijie.yuan
> Mail: yuanweijie1993@gmail.com
> Created Time: Tue 11 Apr 2017 09:31:34 PM CST
************************************************************************/

#ifndef _BRACKTRACE_H
#define _BRACKTRACE_H

#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>

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

#endif
