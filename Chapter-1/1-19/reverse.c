/*
 * Filename:    reverse.c
 * Author:      beihai-chang
 * Date:        20-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a function reverse(s) that reverses the character 
 * string s. Use it to write a program that reverses its 
 * input a line at a time.
 */

#include <stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int maxline);
void reverse(char s[]);

int main(void)
{
    char line[MAXLINE];
    int len;

    line[0] = '\0';

    while (len = mygetline(line, MAXLINE))
    {
        reverse(line);
        printf("%s", line);
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

void reverse(char s[])
{
    int i, c, upper, temp;

    for (i = 0; (c = s[i]) != '\n' && c != '\0'; i++)
        ;
    upper = i - 1;
    for (int j = 0; j <= (upper - 1) / 2; j++)
    {
        temp = s[upper - j];
        s[upper - j] = s[j];
        s[j] = temp;
    }
}