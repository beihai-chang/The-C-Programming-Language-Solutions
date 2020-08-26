/*
 * Filename:    atof.c
 * Author:      beihai-chang
 * Date:        26-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Extend atof to handle scientific notation of the form
 * 123.45e-6
 * where a floating-point number may be followed by e or E 
 * and an optionally signed exponent.
 */

#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1000

int mygetline(char s[], int lim);
double atof(char s[]);

int main(void)
{
    char literal[MAXLEN];
    double sum, atof(char s[]);

    sum = 0;
    printf("Input some number literals, press Ctrl+D to stop:\n");
    while (mygetline(literal, MAXLEN))
        sum += atof(literal);
    printf("Sum: %.8f\n", sum);

    return 0;
}

int mygetline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

double atof(char s[])
{
    double sign, power, val, exp;
    int i, c;
    i = 0;
    sign = 1;
    val = 0.0;
    power = 1.0;
    for (i = 0; isspace(s[i]); i++)
        ;
    while ((c = s[i++]) != '.' && c != 'e' && c != '\0')
        if (c == '-')
            sign = -1;
        else
            val = val * 10 + c - '0';
    if (c == '.')
        while ((c = s[i++]) != '\0' && c != 'e')
        {
            val = val * 10 + c - '0';
            power *= 10;
        }
    if (c == 'e')
    {
        exp = 1;
        while ((c = s[i++]) != '\0')
            if (c == '-')
                exp = 0;
            else
                for (int j = 0; j < c - '0'; j++)
                    power *= exp ? 0.1 : 10;
    }
    return sign * val / power;
}
/*
Output Example:
Input some number literals, press Ctrl+D to stop:
   -123.45e-6
-10
-12.2
0
1e0
Sum: -21.20012345
*/