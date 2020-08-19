/*
 * Filename:    replace.c
 * Author:      beihai-chang
 * Date:        19-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a program to copy its input to its output, replacing each 
 * tab by \t, each backspace by \b, and each backslash by \\. This 
 * makes tabs and backspaces visible in an unambiguous way.
 */

#include <stdio.h>

int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\b')
            printf("\\b");
        else if (c == '\t')
            printf("\\t");
        else if (c == '\\')
            printf("\\\\");
        else
            printf("%c", c);
    }

    return 0;
}