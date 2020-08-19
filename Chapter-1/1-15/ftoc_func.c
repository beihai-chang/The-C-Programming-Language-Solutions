/*
 * Filename:    ftoc_func.c
 * Author:      beihai-chang
 * Date:        19-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Rewrite the temperature conversion program of Section 
 * 1.2 to use a function for conversion.
 */

#include <stdio.h>

float celsius(float fahr);

int main(void)
{
    printf("Fahr\tCelsius\n");
    for (float fahr = 0; fahr <= 300; fahr += 20)
        printf("%3.0f\t%6.1f\n", fahr, celsius(fahr));

    return 0;
}

float celsius(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32);
}