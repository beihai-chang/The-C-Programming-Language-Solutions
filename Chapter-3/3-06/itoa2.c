/*
 * Filename:    itoa2.c
 * Author:      beihai-chang
 * Date:        25-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a version of itoa that accepts three arguments 
 * instead of two. The third argument is a minimum field 
 * width; the converted number must be padded with blanks 
 * on the left if necessary to make it wide enough.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLEN 1000

void itoa(int n, char s[], int fw);
void reverse(char s[]);

int main(void)
{
    char s[MAXLEN];

    for (int i = -10; i < 10; i++)
    {
        itoa(i, s, 4);
        printf("%s\n", s);
    }

    return 0;
}

void itoa(int n, char s[], int fw)
{
    int i, sign, remainder;
    sign = n;
    i = 0;
    do
    {
        remainder = n % 10;
        s[i++] = (sign < 0 ? -remainder : remainder) + '0';
    } while (n /= 10);
    if (sign < 0)
        s[i++] = '-';
    while (i < fw)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int i, j, temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}