/*
 * Filename:    invert.c
 * Author:      beihai-chang
 * Date:        23-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a function invert(x,p,n) that returns x 
 * with the n bits that begin at position p inverted 
 * (i.e., 1 changed into 0 and vice versa), leaving 
 * the others unchanged.
 */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void)
{
    printf("%d\n", invert(37, 4, 4));

    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    return x ^ ((~(~0 << n)) << (p + 1 - n));
}
/*
x = 37(100101)
p = 4
n = 4
output: 59(111011)
*/