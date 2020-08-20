/*
 * Filename:    lines.c
 * Author:      beihai-chang
 * Date:        20-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a program to print all input lines that 
 * are longer than 80 characters.
 */

#include <stdio.h>

#define MAXLINE 8
#define UPPERLEN 4

int mygetline(char line[], int maxline);

int main(void)
{
    int len;
    char line[MAXLINE];

    line[0] = '\0';
    while (len = mygetline(line, MAXLINE))
    {
        if (len > UPPERLEN)
            printf("%d: %s", len, line);
    }

    return 0;
}

int mygetline(char line[], int maxline)
{
    int i, c;

    for (i = 0; (c = getchar()) != '\n' && c != EOF; i++)
    {
        if (i < maxline - 2)
            line[i] = c;
        else if (i == maxline - 2)
        {
            line[i++] = '\n';
            line[i] = '\0';
        }
    }
    if (i == 0 && c == EOF)
        return i;
    else if (i <= maxline - 2)
    {
        line[i++] = '\n';
        line[i] = '\0';
    }

    return i;
}