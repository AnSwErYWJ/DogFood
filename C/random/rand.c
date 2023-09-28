#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int random;

    // srand() + rand()    
    srand((unsigned)time(NULL));

    random = rand() % 11 + 14; // 14 ~ 24

    printf("rand: %d\n", random);

    // random() unspoort VC/VS

    // arc4random() support ios 

    return 0;
}