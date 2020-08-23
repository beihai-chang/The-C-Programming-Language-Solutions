/*
 * Filename:    any.c
 * Author:      beihai-chang
 * Date:        23-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write the function any(s1,s2), which returns the 
 * first location in a string s1 where any character 
 * from the string s2 occurs, or -1 if s1 contains no 
 * characters from s2. (The standard library function 
 * strpbrk does the same job but returns a pointer to 
 * the location.)
 */

#include <stdio.h>

#define MAXLEN 1000

int any(char s1[], char s2[]);

int main(void)
{
    char s1[MAXLEN];
    char s2[MAXLEN];

    printf("s1: ");
    while (gets(s1))
    {
        printf("s2: ");
        gets(s2);
        printf("%d\n", any(s1, s2));
        printf("s1: ");
    }
    printf("quit.\n");

    return 0;
}

int any(char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\0'; i++)
        for (int j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                return i;
    return -1;
}
/*
Output example:
s1: immediate
s2: abcde
(output)3
s1: consider
s2: idiot
(output)1
*/