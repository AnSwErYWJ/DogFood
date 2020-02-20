/*************************************************************************
	> File Name: memory_application.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月23日 星期四 21时29分39秒
 ************************************************************************/
/*
 *动态分配内存实例
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* 按字节对齐 */
static size_t round_up(size_t size)
{
    return (((size)+7) &~ 7);// 按8字节对齐
}

static void *MALLOC(size_t size)
{
    void *mem;
    mem = (void *)malloc(size);//类型指派可选
    if(!mem)
    {
        fprintf(stderr,"MALLOC failed!\n");
        exit(EXIT_FAILURE);
    }
    
    //memset(men,'\0',size);
    memset(mem,0x00,size);

    return mem;
}

static void *CALLOC(size_t n,size_t size)
{
    void *mem;
    mem = (void *)calloc(n,size);//类型指派可选
    if(!mem)
    {
        fprintf(stderr,"CALLOC failed!\n");
        exit(EXIT_FAILURE);
    }
    
    return mem;
}

static void *REALLOC(void *mem,size_t new_size)
{
	void *tmp_mem = realloc(mem, new_size);
	if (!tmp_mem)
	{
		fprintf(stderr,"REALLOC failed!\n");
		exit(EXIT_FAILURE);
	}
	mem = tmp_mem;

	return mem;
}

static void FREE(void *mem)
{
    if (mem)
    {
        free(mem);
        mem = NULL;
    }
}

int main(void)
{
    int *array;
    char *str;
    
    array = (int *)MALLOC(8*sizeof(int));
    str = (char *)CALLOC(8,sizeof(char));
    
    str = (char *)REALLOC(str,20*sizeof(char));

    printf("%ld round up is %ld\n",8,round_up(8));

    FREE(array);
    FREE(str);

    return 0;
}
