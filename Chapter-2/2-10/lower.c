/*
 * Filename:    lower.c
 * Author:      beihai-chang
 * Date:        24-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Rewrite the function lower, which converts upper 
 * case letters to lower case, with a conditional 
 * expression instead of if-else.
 */

#include <stdio.h>

char lower(char c);

int main(void)
{
    for (char c = 'A'; c < 'Z'; c++)
        printf("%c%c", lower(c), (c - 'A') / 10 == 9 || c == 'Z' ? '\n' : ' ');

    return 0;
}

char lower(char c)
{
    return (c >= 'A' && c <= 'Z') ? ('a' + c - 'A') : c;
}