/*
 * Filename:    fahr-to-celsius.c
 * Author:      beihai-chang
 * Date:        17-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Modify the temparature conversion program to print a heading above
 * the table.
 */

#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;

    printf("Fahr\tCelsius\n");
    while (fahr <= upper)
    {
        printf("%3.0f\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
        fahr += step;
    }

    return 0;
}