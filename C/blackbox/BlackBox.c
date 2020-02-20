/*************************************************************************
	> File Name: BlackBox.c
	> Author: 
	> Mail: 
	> Created Time: Thu 30 Jun 2016 02:40:31 PM CST
 ************************************************************************/

/*黑匣子-Linux信号应用*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <execinfo.h>

#define NAMESIZE 15

/* 定义一个数据结构用来保存信号,kill -l可以查看系统中所有信号与其值*/
typedef struct sigInfo
{
    int signum;
    char signame[NAMESIZE];
}sigInfo;

/* 增加我们想要捕捉的异常信号，这里列举了6个 */
sigInfo sigCatch[] = {
    {1,"SIGHUP"}, {2,"SIGINT"}, {3,"SIGQUIT"}, 
    {6,"SIGABRT"}, {8,"SIGFPE"}, {11,"SIGSEGV"} 
};

/* 我们自定义的信号处理函数 */
void blackbox_handler(int sig)
{
    printf("Enter blackbox_handler: ");
    
    //获取信号名字
    printf("SIG name is %s, SIG num is %d\n", strsignal(sig), sig);
    
    // 打印堆栈信息
    printf("Stack information:\n");
    
    int j, nptrs;
#define SIZE 100
    void *buffer[100];
    char **strings;
    
    //保存进程调用栈信息,size是最大帧数目,如果超过了保存最近的,返回保存的帧数
    nptrs = backtrace(buffer, SIZE);
    printf("backtrace() returned %d addresses\n", nptrs);
    
    //将地址信息翻译为符号描述的信息
    strings = backtrace_symbols(buffer, nptrs);
    if (!strings)
    {
        perror("backtrace_symbol");
        exit(EXIT_FAILURE);
    }
    
    for(j = 0; j < nptrs; j++)
           printf("%s\n", strings[j]);
    
    //我们只负责定义指针和释放,malloc由backtrace_symbols调用
    free(strings);
    
    _exit(EXIT_SUCCESS);
}

/* 有bug的程序，调用该程序，将随机产生一些异常信号 */
void bug_func()
{
    //取得进程识别码
    pid_t my_pid = getpid();
    
    // 产生随机数,这里使用秒数作为随机数种子,若使用微妙级的,伪随机数会更分布均匀
    srand((unsigned int)time(NULL));
    switch(rand()%6)
    {
        case 0:
        {
            // SIGHUP
            kill(my_pid, SIGHUP);
            break;
        }
        case 1:
        {
            // SIGINT
            kill(my_pid, SIGINT);
            break;
        }
        case 2:
        {
            // SIGQUIT
            kill(my_pid, SIGQUIT);
            break;
        }
        case 3:
        {
            // SIGABRT
            abort();
            break;
        }
        case 4:
        {
            // SIGFPE
            int a = 6 / 0;
            break;
        }
        case 5:
        {
            // SIGSEGV
            kill(my_pid, SIGSEGV);
            break;
        }
        default:
            return;
    }
    
}

int main(int argc,const char *argv[])
{
    if(argc!=1)
    {
        fprintf(stderr,"Usage:./blackbox\n");
        return EXIT_FAILURE;
            
    }

    int i;
    struct sigaction sa;
    stack_t ss;

    ss.ss_sp = malloc(SIGSTKSZ);
    ss.ss_size = SIGSTKSZ;
    ss.ss_flags = 0;

    //在堆中为函数分配一块区域,作为改函数的栈使用
    if(sigaltstack(&ss,NULL) == -1)
    {
        return EXIT_FAILURE;
    }
    
    // 初始化信号处理函数数据结构
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = blackbox_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_ONSTACK;
    
    for (i = 0; i < sizeof(sigCatch)/sizeof(sigInfo); i++)
    {
        // 注册信号处理函数
        if(sigaction(sigCatch[i].signum, &sa, NULL) < 0)
        {
            return EXIT_FAILURE;
        }
    }

    bug_func();
    
    while(1);
    
    return EXIT_SUCCESS; 
}
