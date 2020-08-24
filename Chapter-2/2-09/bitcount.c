/*
 * Filename:    bitcount.c
 * Author:      beihai-chang
 * Date:        24-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * In a two's complement number system, x &= (x-1) 
 * deletes the rightmost 1-bit in x. Explain why. 
 * Use this observation to write a faster version 
 * of bitcount.
 */

#include <stdio.h>

int bitcount(unsigned x);

int main(void)
{
    printf("bitcount: count 1 bits in x\n");
    for (unsigned i = 0; i < 10; i++)
        printf("x = %u:\t%d\n", i, bitcount(i));

    return 0;
}

int bitcount(unsigned x)
{
    int cnt;
    for (cnt = 0; x > 0; x &= x - 1)
        cnt++;
    return cnt;
}
/*
bitcount: count 1 bits in x
x = 0:	0
x = 1:	1
x = 2:	1
x = 3:	2
x = 4:	1
x = 5:	2
x = 6:	2
x = 7:	3
x = 8:	1
x = 9:	2
*/