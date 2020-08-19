/*
 * Filename:    blank.c
 * Author:      beihai-chang
 * Date:        18-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a program to copy its input to its output, replacing each 
 * string of one or more blanks by a single blank.
 */

#include <stdio.h>

int main(void)
{
    int c, cnt;

    cnt = 0;
    while ((c = getchar()) != EOF)
    {
        if (c != ' ')
        {
            putchar(c);
            cnt = 0;
        }
        else if (cnt++ == 0)
        {
            putchar(c);
        }
        else
            ++cnt;
    }

    return 0;
}