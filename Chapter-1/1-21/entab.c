/*
 * Filename:    entap.c
 * Author:      beihai-chang
 * Date:        20-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a program entab that replaces strings of blanks 
 * by the minimum number of tabs and blanks to achieve 
 * the same spacing. Use the same tab stops as for detab. 
 * When either a tab or a single blank would suffice to 
 * reach a tab stop, which should be given preference?
 */

#include <stdio.h>

#define TABWID 4

int main(void)
{
    int c, cnt, bcnt, dist;

    cnt = 0;
    bcnt = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            printf("%c", c);
            cnt = 0;
        }
        else if (c == ' ')
        {
            if (!bcnt)
                dist = TABWID - cnt % TABWID;
            bcnt++;
        }
        else
        {
            if (bcnt < dist)
                for (int i = 0; i < bcnt; i++)
                    printf(" ");
            else
            {
                printf("\t");
                for (int j = 0; j < (bcnt - dist) / TABWID; j++)
                    printf("\t");
                for (int k = 0; k < (bcnt - dist) % TABWID; k++)
                    printf(" ");
            }
            printf("%c", c);
            cnt += bcnt + 1;
            bcnt = 0;
        }
    }

    return 0;
}
/*Output example:
(If the tab width in your text editor is set to 4 columns)
(Then the next two lines should be identical)
(Input)
a      b   cd   e     f        r   h   s
(Output)
a	   b   cd	e	  f		   r   h   s
*/