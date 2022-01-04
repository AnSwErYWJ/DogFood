/*************************************************************************
	> File Name: test-explicit.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Mon 10 Oct 2016 02:32:35 PM CST
 ************************************************************************/

#include<stdio.h>
#include<dlfcn.h>

#define LIB "./libwelcome.so"

int main(void)
{
    /*
     * RTLD_NOW：将共享库中的所有函数加载到内存 
     * RTLD_LAZY：会推后共享库中的函数的加载操作，直到调用dlsym()时方加载某函数
     */

    void *dl = dlopen(LIB,RTLD_LAZY); //打开动态库

    if (!dl)
        fprintf(stderr,"Error:failed to load libary.\n");

    char *error = dlerror(); //检测错误
    if (error)
    {
        fprintf(stderr,"%s\n",error);
        return -1;
    }

    void (*func)() = dlsym(dl,"welcome"); // 获取函数地址
    error = dlerror(); //检测错误
    if (error)
    {
        fprintf(stderr,"%s\n",error);
        return -1;
    }

    func(); //调用动态库中的函数

    dlclose(dl); //关闭动态库
    error = dlerror(); //检测错误
    if (error)
    {
        fprintf(stderr,"%s\n",error);
        return -1;
    }
   
    return 0;
}
