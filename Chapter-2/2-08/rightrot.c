/*
 * Filename:    rightrot.c
 * Author:      beihai-chang
 * Date:        23-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a function rightrot(x,n) that returns the value 
 * of the integer x rotated to the right by n positions.
 */

#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(void)
{
    printf("%d\n", rightrot(37, 2));

    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    unsigned right, len, temp;

    temp = x;
    while (temp > 0)
    {
        temp = temp / 2;
        len++;
    }
    for (int i = 0; i < n; i++)
    {
        right = x & 1;
        if (right)
            x = x | (1 << len);
        x = x >> 1;
    }
    return x;
}
/*
x = 37(100101)
n = 2
output: 25(011001)
*/