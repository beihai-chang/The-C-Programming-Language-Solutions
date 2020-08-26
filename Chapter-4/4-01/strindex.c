/*
 * Filename:    strindex.c
 * Author:      beihai-chang
 * Date:        26-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write the function strindex(s,t) which returns the 
 * position of the rightmost occurrence of t in s, or 
 * -1 if there is none.
 */

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

int mygetline(char s[], int lim);
int strindex(char s[], char t[]);

int main(void)
{
    char pattern[MAXLEN];
    char line[MAXLEN];

    printf("Input the pattern: ");
    mygetline(pattern, MAXLEN);
    printf("Input some strings:\n");
    while (mygetline(line, MAXLEN))
        printf("Result: %d\n", strindex(line, pattern));

    return 0;
}

int mygetline(char s[], int lim)
{
    int i, c;
    i = 0;
    while (--lim && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[])
{
    int ls, lt, i, j, k;

    ls = strlen(s);
    lt = strlen(t);
    for (i = ls - 1; i > 0; i--)
    {
        for (j = lt - 1, k = 0; j >= 0 && s[i - k] == t[j]; j--, k++)
            ;
        if (j == -1)
            return i - lt + 1;
    }
    return -1;
}
/*
Output Example:
Input the pattern: ould
Input some strings:
(Input)Would not we shatter it to bits -- and then re-mould it nearer to the Heart's Desire!
Result: 48
(Input)To grasp this sorry Scheme of Things entire
Result: -1
*/