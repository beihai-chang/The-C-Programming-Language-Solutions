/*
 * Filename:    ranges.c
 * Author:      beihai-chang
 * Date:        22-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a program to determine the ranges of char, 
 * short, int, and long variables, both signed and 
 * unsigned, by printing appropriate values from 
 * standard headers and by direct computation. 
 * Harder if you compute them: determine the ranges
 * of the various floating-point types.
 */

#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("Ranges of data types in C:\n");

    printf("char            %d - %d\n", CHAR_MIN, CHAR_MAX);
    printf("short           %d - %d\n", SHRT_MIN, SHRT_MAX);
    printf("int             %d - %d\n", INT_MIN, INT_MAX);
    printf("long            %ld - %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned char   0 - %u\n", UCHAR_MAX);
    printf("unsigned short  0 - %u\n", USHRT_MAX);
    printf("unsigned int    0 - %u\n", UINT_MAX);
    printf("unsigned long   0 - %lu\n", ULONG_MAX);

    return 0;
}
/*
Output example(machine-dependent):
Ranges of data types in C:
char            -128 - 127
short           -32768 - 32767
int             -2147483648 - 2147483647
long            -9223372036854775808 - 9223372036854775807
unsigned char   0 - 255
unsigned short  0 - 65535
unsigned int    0 - 4294967295
unsigned long   0 - 18446744073709551615

*/