/*
 * Filename:    histogram.c
 * Author:      beihai-chang
 * Date:        19-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a program to print a histogram of the lengths of words in its 
 * input. It is easy to draw the histogram with the bars horizontal; a 
 * vertical orientation is more challenging.
 */

#include <stdio.h>

#define IN 1
#define OUT 0
#define LEN 7

int main(void)
{
    int wordl[LEN];
    int c, status, cnt, upper;

    printf("Please enter %d words: ", LEN);

    status = OUT;
    cnt = 0;
    upper = 0;
    for (int i = 0; i < LEN; i++)
        wordl[i] = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (status == IN)
            {
                if (wordl[cnt] > upper)
                    upper = wordl[cnt];
                ++cnt;
                status = OUT;
            }
        }
        else
        {
            ++wordl[cnt];
            if (status == OUT)
                status = IN;
        }
    }

    printf("\n");
    for (int i = upper; i > 0; i--)
    {
        printf("%2d", i);
        for (int j = 0; j < LEN; j++)
        {
            if (i <= wordl[j])
                printf("\t***");
            else
                printf("\t   ");
        }
        printf("\n");
    }

    return 0;
}
/* Output Example:
Please enter 7 words: rage anainst the dying of the light
 7	   	***	   	   	   	   	   
 6	   	***	   	   	   	   	   
 5	   	***	   	***	   	   	***
 4	***	***	   	***	   	   	***
 3	***	***	***	***	   	***	***
 2	***	***	***	***	***	***	***
 1	***	***	***	***	***	***	***
 */