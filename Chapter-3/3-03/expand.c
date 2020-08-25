/*
 * Filename:    expand.c
 * Author:      beihai-chang
 * Date:        25-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a function expand(s1,s2) that expands shorthand 
 * notations like a-z in the string s1 into the equivalent 
 * complete list abc...xyz in s2. Allow for letters of 
 * either case and digits, and be prepared to handle cases 
 * like a-b-c and a-z0-9 and -a-z. Arrange that a leading 
 * or trailing - is taken literally.
 */

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

void expand(char s1[], char s2[]);

int main(void)
{
    char s1[MAXLEN];
    char s2[MAXLEN];

    printf("Input some strings with shorthand notations:\n");
    while (gets(s1))
    {
        expand(s1, s2);
        printf("%s\n", s2);
    }

    return 0;
}

void expand(char s1[], char s2[])
{
    int len, c1, c2, i, k;
    len = strlen(s1);
    for (i = 0, k = 0; i <= len - 3; i++)
    {
        c1 = s1[i];
        if (c1 >= 'a' && (c2 = s1[i + 1]) == '-' && (c2 = s1[i + 2]) >= c1 && c2 <= 'z' ||
            c1 >= 'A' && (c2 = s1[i + 1]) == '-' && (c2 = s1[i + 2]) >= c1 && c2 <= 'Z' ||
            c1 >= '0' && (c2 = s1[i + 1]) == '-' && (c2 = s1[i + 2]) >= c1 && c2 <= '9')
        {
            for (int c3 = c1; c3 <= c2; c3++)
                s2[k++] = c3;
            i += 2;
        }
        else
            s2[k++] = c1;
    }
    while ((c1 = s1[i++]) != '\0')
        s2[k++] = c1;
    s2[k] = '\0';
}
/*
Output Example:
Input some strings with shorthand notations:
(input)-a-z- a-b-c A-Z0-9-
(output)-abcdefghijklmnopqrstuvwxyz- ab-c ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-
*/