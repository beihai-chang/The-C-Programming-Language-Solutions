/*
 * Filename:    rm_blanks.c
 * Author:      beihai-chang
 * Date:        20-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a program to remove trailing blanks and tabs from 
 * each line of input, and to delete entirely blank lines.
 */

#include <stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int maxline);

int main(void)
{
    int len, isempty, c;
    char line[MAXLINE];

    printf("Enter some lines:\n");
    while (len = mygetline(line, MAXLINE))
    {
        isempty = 1;
        for (int i = len - 2; i >= 0; i--)
        {
            // remove trailing blanks and tabs
            if (line[i] != ' ' && line[i] != '\t')
            {
                line[i + 1] = '\n';
                line[i + 2] = '\0';
                isempty = 0;
                break;
            }
        }
        if (isempty)
        {
            line[0] = '\0';
            printf("Empty line%s\n", line);
            continue;
        }
        // to make the '\n' character visible
        for (int j = 0; (c = line[j]) != '\0'; j++)
        {
            if (c == '\n')
                printf("\\n");
            else
                printf("%c", c);
        }
        printf("\n");
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
    {
        line[i] = '\0';
    }
    else if (i <= maxline - 2)
    {
        line[i++] = '\n';
        line[i] = '\0';
    }

    return i;
}