#include <stdio.h>

// 0 is even, 1 is odd
int determineOddEven(int x)
{
	if ( (x & 1) == 1) return 1;
	else return 0;
}

/*
 * 0 is not
 * 1 is 
 */ 
int isPowerOfTwo(int x) 
{
    if (x <= 0) return 0;
    return ((x & (x - 1)) == 0);
}

int countNumberOfZero(int x)
{
    int counts = 0;

    while (x + 1)
    {
        counts++;
        x = x | (x + 1);
    }

    return counts;
}

int countNumberOfOne(int x)
{
	int counts = 0;

    while(x)
    {
		counts++;
        x = x & (x-1);
    }

    return counts;	
}

// x ^ y ^ y = x
void swap(int *x, int *y) 
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

/*
 * n>>31 取得n的符号
 * 若n为正数，n>>31等于0
 * 若n为负数，n>>31等于-1
 * 若n为正数 n^0=0,数不变
 * 若n为负数,有n^-1 需要计算n和-1的补码，然后进行异或运算，结果n变符号并且为n的绝对值减1，再减去-1就是绝对值
 */
int abs(int x)
{
	return (x >> 31) == 0 ? x : (~x + 1);
}

int main(void)
{
	int x, y;

	x = 1024;
	y = 513;

	// determineOddEven
	printf("determineOddEven(%d): %d\n", x, determineOddEven(x));


	// read bytes
	printf("read bytes:\n");
	printf("  byte 0: %d\n", ((x >>  0) & 0x000000ff));	// 获取第0个字节
	printf("  byte 1: %d\n", ((x >>  8) & 0x000000ff));	// 获取第1个字节
	printf("  byte 2: %d\n", ((x >> 16) & 0x000000ff));	// 获取第2个字节
	printf("  byte 3: %d\n", ((x >> 24) & 0x000000ff));	// 获取第3个字节

	// isPowerOfTwo
	printf("isPowerOfTwo(%d): %d\n", x, isPowerOfTwo(x));

	// countNumberOfOne
	printf("countNumberOfOne(%d): %d\n", x, countNumberOfOne(x));
	printf("countNumberOfZero(%d): %d\n", x, countNumberOfZero(x));

	// swap
	printf("swap x: %d, y: %d:\n", x, y);
	swap(&x, &y);
	printf("    x: %d\n", x);
	printf("    y: %d\n", y);

	// abs
	x = 87;
	y = -78;
	printf("abs(%d): %d\n", x, abs(x));
	printf("abs(%d): %d\n", y, abs(y));

	return 0;
}
