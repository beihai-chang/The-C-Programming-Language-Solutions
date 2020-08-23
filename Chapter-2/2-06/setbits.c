/*
 * Filename:    setbits.c
 * Author:      beihai-chang
 * Date:        23-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a function setbits(x,p,n,y) that returns x 
 * with the n bits that begin at position p set to 
 * the rightmost n bits of y, leaving the other bits 
 * unchanged.
 */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
    printf("%u\n", setbits(37, 3, 3, 13));

    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return (x & (~0 << (p + 1)) | ~(~0 << (p + 1 - n))) | ((y & ~(~0 << n)) << (p + 1 - n));
}
/*
x = 37(100101)
y = 13(1101)
p = 3, n = 3
output: 43(101011)
*/