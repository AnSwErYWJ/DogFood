/*************************************************************************
	> File Name: log.h
	> Author: weijie.yuan
	> Mail: 
	> Created Time: Tue 23 Aug 2016 11:39:23 AM CST
 ************************************************************************/

/*
 *反斜线宏定义延续到下一行,define遇到换行符就结束；
 * 使用do{...}while(0)构造后的宏定义不会受到大括号、分号等的影响，而且可以定义空宏而不受警告。
 * ##__VA_ARGS__ ,可变参数宏,##可以支持0个参数.
 */

#ifndef _LOG_H
#define _LOG_H

#define VA_SIZE 1024

/* log print func */
void print_log(const char level, const char *fmt, ...);

#define	LEVEL_VERBOSE 0
#define	LEVEL_DEBUG   1  //develop
#define	LEVEL_INFO    2  //release
#define	LEVEL_WARN    3
#define	LEVEL_ERROR   4

#define PROJECT "MyProject"
/*
 * __LINE__：在源代码中插入当前源代码行号；
 * __FILE__：在源文件中插入当前源文件名；
 * __DATE__：在源文件中插入当前的编译日期
 * __TIME__：在源文件中插入当前编译时间；
 * __func__：输出函数名称,与_Function_相同。
 */

#if defined(LEVEL_VERBOSE)
#define LOG_VERBOSE(...)\
        do{\
            print_log('V', ##__VA_ARGS__);\
        }while(0)
#endif

#if defined(LEVEL_DEBUG)
#define LOG_DEBUG(...)\
        do{\
            print_log('D', ##__VA_ARGS__);\
        }while(0)
#endif

#if defined(LEVEL_INFO)
#define LOG_INFO(...)\
        do{\
            print_log('I', ##__VA_ARGS__);\
        }while(0)
#endif

#if defined(LEVEL_WARN)
#define LOG_WRAN(...)\
        do{\
            print_log('W', ##__VA_ARGS__);\
        }while(0)
#endif

#if defined(LEVEL_ERROR)
#define LOG_ERROR(...)\
        do{\
            print_log('E', ##__VA_ARGS__);\
        }while(0)
#endif

//---------------------------------------------------------------------------

/* set log level */
#define LEVEL_DEFAULT LEVEL_INFO

/* api for users*/
#if LEVEL_DEFAULT == LEVEL_VERBOSE
    #define LOGV(...) LOG_VERBOSE(__VA_ARGS__)
    #define LOGD(...) LOG_DEBUG(__VA_ARGS__)
    #define LOGI(...) LOG_INFO(__VA_ARGS__)
    #define LOGW(...) LOG_WRAN(__VA_ARGS__)
    #define LOGE(...) LOG_ERROR(__VA_ARGS__)
#elif LEVEL_DEFAULT == LEVEL_DEBUG
    #define LOGV(...) do{}while(0)
    #define LOGD(...) LOG_DEBUG(__VA_ARGS__)
    #define LOGI(...) LOG_INFO(__VA_ARGS__)
    #define LOGW(...) LOG_WRAN(__VA_ARGS__)
    #define LOGE(...) LOG_ERROR(__VA_ARGS__)
#elif LEVEL_DEFAULT == LEVEL_INFO
    #define LOGV(...) do{}while(0)
    #define LOGD(...) do{}while(0)
    #define LOGI(...) LOG_INFO(__VA_ARGS__)
    #define LOGW(...) LOG_WRAN(__VA_ARGS__)
    #define LOGE(...) LOG_ERROR(__VA_ARGS__)
#elif LEVEL_DEFAULT == LEVEL_WARN
    #define LOGV(...) do{}while(0)
    #define LOGD(...) do{}while(0)
    #define LOGI(...) do{}while(0)
    #define LOGW(...) LOG_WRAN(__VA_ARGS__)
    #define LOGE(...) LOG_ERROR(__VA_ARGS__)
#elif LEVEL_DEFAULT == LEVEL_ERROR
    #define LOGV(...) do{}while(0)
    #define LOGD(...) do{}while(0)
    #define LOGI(...) do{}while(0)
    #define LOGW(...) do{}while(0)
    #define LOGE(...) LOG_ERROR(__VA_ARGS__)
#else
    #define LOGV(...) do{}while(0)
    #define LOGD(...) do{}while(0)
    #define LOGI(...) do{}while(0)
    #define LOGW(...) do{}while(0)
    #define LOGE(...) do{}while(0)
#endif

#endif