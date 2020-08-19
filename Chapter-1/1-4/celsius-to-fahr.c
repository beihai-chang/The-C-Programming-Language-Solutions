/*
 * Filename:    celsius-to-fahr.c
 * Author:      beihai-chang
 * Date:        17-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a program to print the corresponding Celsius to Fahrenheit table
 */

#include <stdio.h>

int main(void)
{
    float celsius, fahr;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    celsius = lower;

    printf("Celsius\tFahr\n");
    while (celsius <= upper)
    {
        printf("%5.0f\t%4.1f\n", celsius, (9.0 / 5.0) * celsius + 32.0);
        celsius += step;
    }

    return 0;
}