/*
 * Filename:    one-word-per-line.c
 * Author:      beihai-chang
 * Date:        19-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a program that prints its input one word per line.
 */

#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
    int c, status;

    status = OUT;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (status == IN)
            {
                putchar('\n');
                status = OUT;
            }
        }
        else
        {
            putchar(c);
            if (status == OUT)
                status = IN;
        }
    }

    return 0;
}