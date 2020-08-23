/*
 * Filename:    squeeze.c
 * Author:      beihai-chang
 * Date:        23-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write an alternative version of squeeze(s1,s2) that 
 * deletes each character in s1 that matches any character 
 * in the string s2.
 */

#include <stdio.h>

#define MAXLEN 1000

void squeeze(char s1[], char s2[]);

int main(void)
{
    char s1[MAXLEN];
    char s2[MAXLEN];

    printf("Enter the string of characters to be deleted:\n");
    gets(s2);
    printf("Enter some strings:\n");
    while (gets(s1))
    {
        squeeze(s1, s2);
        printf("%s\n", s1);
    }

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, in;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        in = 0;
        for (int k = 0; s2[k] != '\0'; k++)
            if (s1[i] == s2[k])
            {
                in = 1;
                break;
            }
        if (!in)
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}
/*
Output example:
Enter the string of characters to be deleted:
ad
Enter some strings:
(input)
they learned to drink lizard broth and eat spider eggs without Ursula's knowing it
(output)
they lerne to rink lizr broth n et spier eggs without Ursul's knowing it
*/