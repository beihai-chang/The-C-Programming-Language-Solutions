/*
 * Filename:    escape.c
 * Author:      beihai-chang
 * Date:        24-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a function escape(s,t) that converts characters 
 * like newline and tab into visible escape sequences like 
 * \n and \t as it copies the string t to s. Use a switch. 
 * Write a function for the other direction as well, 
 * converting escape sequences into the real characters.
 */

#include <stdio.h>

#define MAXLEN 1000

int mygetline(char s[], int lim);
void escape(char s[], char t[]);
void rescape(char s[], char t[]);

int main(void)
{
    char line[MAXLEN];
    char escaped[MAXLEN];
    char rescaped[MAXLEN];

    printf("Input some lines(Enter Ctrl+D to quit):\n");
    while (mygetline(line, MAXLEN))
    {
        printf("Make sccape sequences visible:\n");
        escape(escaped, line);
        printf("%s\n", escaped);
        rescape(rescaped, escaped);
        printf("Convert escape esquences into real characters:\n");
        printf("%s", rescaped);
    }

    return 0;
}

int mygetline(char s[], int lim)
{
    int c, i;

    for (i = 0; (i < lim - 1) * ((c = getchar()) != EOF) * (c != '\n'); ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void escape(char s[], char t[])
{
    int c, i, j;
    for (i = j = 0; (c = t[i]) != '\0'; i++)
    {
        switch (c)
        {
        case ' ':
            s[j++] = '\\';
            s[j++] = 'b';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        default:
            s[j++] = c;
            break;
        }
    }
    s[j] = '\0';
}

void rescape(char s[], char t[])
{
    int c, i, j;
    for (i = j = 0; (c = t[i]) != '\0'; i++)
    {
        if (c == '\\')
        {
            c = t[++i];
            switch (c)
            {
            case 'b':
                s[j++] = ' ';
                break;
            case 't':
                s[j++] = '\t';
                break;
            case 'n':
                s[j++] = '\n';
                break;
            default:
                s[j++] = '\\';
                s[j++] = c;
                break;
            }
        }
        else
            s[j++] = c;
    }
    s[j] = '\0';
}
/*
Output Example:
Input some lines(Enter Ctrl+D to quit):
Marcondo	is  surrounded by waters on all		sides.
Make sccape sequences visible:
Marcondo\tis\b\bsurrounded\bby\bwaters\bon\ball\t\tsides.\n
Convert escape esquences into real characters:
Marcondo	is  surrounded by waters on all		sides.
*/