/*
 * Filename:    detap.c
 * Author:      beihai-chang
 * Date:        20-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a program detab that replaces tabs in the input with 
 * the proper number of blanks to space to the next tab stop. 
 * Assume a fixed set of tab stops, say every n columns. 
 * Should n be a variable or a symbolic parameter?
 */

#include <stdio.h>

#define TABWID 4

int main(void)
{
    int c, cnt, dist;

    cnt = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            printf("%c", c);
            cnt = 0;
        }
        else if (c == '\t')
        {
            dist = TABWID - cnt % TABWID;
            for (int i = 0; i < dist; i++)
                printf(" ");
            cnt += dist;
        }
        else
        {
            printf("%c", c);
            cnt++;
        }
    }

    return 0;
}