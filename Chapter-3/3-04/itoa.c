/*
 * Filename:    itoa.c
 * Author:      beihai-chang
 * Date:        25-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * In a two's complement number representation, our version 
 * of itoa does not handle the largest negative number, that 
 * is, the value of n equal to -(2wordsize-1). Explain why 
 * not. Modify it to print that value correctly, regardless 
 * of the machine on which it runs.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLEN 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
    char s[MAXLEN];
    int n;

    itoa(INT_MIN, s);
    printf("%s\n", s);

    return 0;
}

// The origin itoa will make the largest negative number positive
// which will overflow the upper limit of int
void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0)
        n = -n - 1;
    i = 0;
    s[i++] = n % 10 + 1 + '0';
    while ((n /= 10) > 0)
        s[i++] = n % 10 + '0';
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* Another possible solution:
void itoa(int n, char s[])
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
    s[i] = '\0';
    reverse(s);
}
*/

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