/*
 * Filename:    count.c
 * Author:      beihai-chang
 * Date:        18-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a program to count blanks, tabs, and newlines.
 */

#include <stdio.h>

int main(void)
{
    long c, bl, tb, nl;

    bl = 0;
    tb = 0;
    nl = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++bl;
        if (c == '\t')
            ++tb;
        if (c == '\n')
            ++nl;
    }
    printf("Count of blanks: %ld\n", bl);
    printf("Count of tabs: %ld\n", tb);
    printf("Count of newlines: %ld\n", nl);

    return 0;
}