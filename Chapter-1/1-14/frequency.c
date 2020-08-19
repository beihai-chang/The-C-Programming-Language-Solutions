/*
 * Filename:    frequency.c
 * Author:      beihai-chang
 * Date:        19-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a program to print a histogram of the frequencies 
 * of different characters in its input.
 */

#include <stdio.h>

#define LEN 26

int main(void)
{
    int freq[LEN];
    int c, upper, index;

    for (int i = 0; i < LEN; i++)
        freq[i] = 0;
    upper = 0;
    index = 0;

    printf("Please enter some sentences: ");
    while ((c = getchar()) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            index = c - 'a';
            ++freq[index];
            if (freq[index] > upper)
                upper = freq[index];
        }
        else if (c >= 'A' && c <= 'Z')
        {
            index = c - 'A';
            ++freq[index];
            if (freq[index] > upper)
                upper = freq[index];
        }
    }

    printf("\n");
    for (int i = upper; i > 0; i--)
    {
        printf("%2d", i);
        for (int j = 0; j < LEN; j++)
        {
            if (freq[j] == 0)
                continue;
            if (i <= freq[j])
                printf("\t**");
            else
                printf("\t  ");
        }
        printf("\n");
    }
    printf("  ");
    for (int k = 0; k < LEN; k++)
    {
        if (freq[k] == 0)
            continue;
        else
            printf("\t%c%c", k + 'A', k + 'a');
    }
    printf("\n");

    return 0;
}/* Output Example:
Please enter some sentences: do not go gentle into that good night.
Rage, rage against the dying of the light.                
10	  	  	  	  	  	  	  	  	  	  	  	  	**	  
 9	  	  	  	  	**	  	  	  	  	  	  	  	**	  
 8	  	  	  	  	**	  	  	  	  	  	  	  	**	  
 7	  	  	  	  	**	  	  	  	  	**	  	  	**	  
 6	  	  	**	  	**	  	  	  	**	**	  	  	**	  
 5	**	  	**	  	**	**	**	  	**	**	  	  	**	  
 4	**	  	**	  	**	**	**	  	**	**	  	  	**	  
 3	**	**	**	  	**	**	**	  	**	**	  	  	**	  
 2	**	**	**	  	**	**	**	**	**	**	**	  	**	  
 1	**	**	**	**	**	**	**	**	**	**	**	**	**	**
  	Aa	Dd	Ee	Ff	Gg	Hh	Ii	Ll	Nn	Oo	Rr	Ss	Tt	Yy
*/