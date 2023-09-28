#include <stdio.h>
#include <stdlib.h>

// shift ties to even
int shiftRightA(int a, int q)
{
    if (q == 0) return a;

    int b = 1 << q;
    int c = a / b;
    int d = a % b;

    if (a > 0)
    {
        if (d + d == b)
        {
            if (c % 2 != 0)
            {
                c++;
            }
        }
        else if (d + d > b)
        {
            c++;
        }
    }
    else if (a < 0)
    {
        if (d + d == -b)
        {
            if (c % 2 != 0)
            {
                c--;
            }
        }
        else if (d + d < -b)
        {
            c--;
        }
    }

    return c;
}

static int shiftRightB(int a, int q)
{
    if (q == 0) return a;
    
    if (a >= 0)
    {
        return ((a + (1 << (q - 1))) >> q);
    }
    else
    {
        return ((a + (1 << (q - 1)) - 1) >> q);
    }
}

int main(int argc, const char *argv[])
{
    if (argc < 3) 
	{
    	printf("Usage: %s input_a input_q\n", argv[0]);
		return -1;
	}

    int input_a = atoi(argv[1]);
    int input_q = atoi(argv[2]);

    printf("shiftRightA a: %d, q: %d, ret: %d\n", input_a, input_q, shiftRightA(input_a, input_q));
    printf("shiftRightB a: %d, q: %d, ret: %d\n", input_a, input_q, shiftRightB(input_a, input_q));

    return 0;
}