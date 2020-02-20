/*************************************************************************
	> File Name: test.c
	> Author: weijie.yuan
	> Mail: 
	> Created Time: Wed 24 Aug 2016 10:06:26 AM CST
 ************************************************************************/

#include<stdio.h>
#include"log.h"

int main()
{
    LOGV("verbose");
    LOGD("debug");
    LOGI("info");
    LOGW("warn");
    LOGE("error");

    return 0;
}

