/*
 * Filename:    ftoc_rev.c
 * Author:      beihai-chang
 * Date:        17-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Modify the temperature conversion program to print the table in reverse 
 * order, that is, from 300 degrees to 0
 */

#include <stdio.h>

int main(void)
{
    printf("Fahr\tCelsius\n");
    for (float fahr = 300; fahr >= 0; fahr -= 20)
        printf("%3.0f\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    return 0;
}