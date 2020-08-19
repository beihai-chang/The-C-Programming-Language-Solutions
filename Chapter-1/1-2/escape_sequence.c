/*
 * Filename:    escape-sequence.c
 * Author:      beihai-chang
 * Date:        17-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * RExperiment to find out what happens when printf's argument string
 * contains \c, where c is some character not listed above.
 */

#include <stdio.h>

int main(void)
{
    printf("\c\n"); // warning: unknown escape sequence: '\c'
    // the output is "c"
    return 0;
}