/*
 * Filename:    eof.c
 * Author:      beihai-chang
 * Date:        18-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Verify that the expression getchar() != EOF is 0 or 1
 */

#include <stdio.h>

int main(void)
{
    printf("Please enter a character: ");
    printf("The value of expression \"getchar() != EOF\" is %d\n", getchar() != EOF);
    return 0;
}