/*
 * Filename:    longest_line.c
 * Author:      beihai-chang
 * Date:        19-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Revise the main routine of the longest-line program so it 
 * will correctly print the length of arbitrary long input 
 * lines, and as much as possible of the text.
 */

#include <stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len, maxlen;
    char line[MAXLINE];
    char longest[MAXLINE];

    maxlen = 0;
    longest[0] = '\0';

    while (len = mygetline(line, MAXLINE))
    {
        if (len > maxlen)
        {
            copy(longest, line);
            maxlen = len;
        }
    }

    printf("\nThe longest line is: %sThe maximum length is:%d\n", longest, maxlen);

    return 0;
}

// Any input that overflowed the size limit will be truncated
// and a new line char followed by a '\0' will be added to its end
// by force. However the process of counting its length will continue.
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

void copy(char to[], char from[])
{
    for (int i = 0; (to[i] = from[i]) != '\0'; i++)
        ;
}
/* Output Example(MAXLINE was set to 8):
(Input)
functional
generic
technical committee
object
since
next
(Output)
The longest line is: techni
The maximum length is:20
*/