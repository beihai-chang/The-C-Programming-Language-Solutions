/*
 * Filename:    htoi.c
 * Author:      beihai-chang
 * Date:        22-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a function htoi(s), which converts a string 
 * of hexadecimal digits (including an optional 0x 
 * or 0X) into its equivalent integer value. The 
 * allowable digits are 0 through 9, a through f, 
 * and A through F.
 */

#include <stdio.h>
#include <ctype.h>

#define MAXLEN 16

int htoi(char s[]);

int main(void)
{
    char hex[MAXLEN];

    printf("Enter a hexadecimal number(start with 0x or 0X):\n");
    while (gets(hex))
        printf("%d\n", htoi(hex));

    return 0;
}

int htoi(char s[])
{
    int c, res, positive;

    res = 0;
    positive = 1;
    for (int i = 2; (c = s[i]) != '\0'; i++)
    {
        if (c == '-')
            positive = 0;
        else if (isalpha(c))
        {
            c = tolower(c);
            res = res * 16 + (10 + c - 'a');
        }
        else
            res = res * 16 + (c - '0');
    }
    if (positive)
        return res;
    else
        return -res;
}
/*
Output example:
Enter a hexadecimal number(start with 0x or 0X):
0xfff
4095
0X-f207E
-991358
0x0
0
*/