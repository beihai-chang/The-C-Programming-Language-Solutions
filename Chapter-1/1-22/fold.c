/*
 * Filename:    fold.c
 * Author:      beihai-chang
 * Date:        21-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a program to “fold” long input lines into two or more 
 * shorter lines after the last non-blank character that occurs 
 * before the n-th column of input. Make sure your program does 
 * something intelligent with very long lines, and if there are 
 * no blanks or tabs before the specified column.
 */

#include <stdio.h>

#define LINE 30
#define TABWID 4

int main(void)
{
    int c, cnt, dist;
    char temp[LINE + 6];

    cnt = 0;
    while ((c = getchar()) != EOF)
    {
        if (cnt >= LINE)
        {
            for (int i = LINE - 1; i >= 0; i--)
                if (temp[i] != ' ')
                {
                    if (i == LINE - 1)      // If a word is truncated
                        temp[++i] = '-';    // then add a '-' to it
                    temp[i + 1] = '\n';
                    temp[i + 2] = '\0';
                    break;
                }
            printf("%s", temp);
            cnt = 0;
        }
        else if (c == '\n')
        {
            temp[cnt++] = c;
            temp[cnt] = '\0';
            printf("%s", temp);
            cnt = 0;
            continue;
        }
        else if (c == '\t')
        {
            // Replace tabs with blanks 
            dist = TABWID - cnt % TABWID;
            for (int i = 0; i < dist; i++)
                temp[cnt + i] = ' ';
            cnt += dist;
            continue;
        }
        temp[cnt++] = c;
    }
    temp[cnt++] = '\n';
    temp[cnt] = '\0';
    printf("%s", temp);

    return 0;
}
/* Output Example:
(Input)
By the way, there is a tendency to make everything in sight an extern variable because it appears to simplify communications - argument lists are short and variables are always there when you want them. But external variables are always there even when you don't want them. Relying too heavily on external variables is fraught with peril since it leads to programs whose data connections are not all obvious - variables can be changed in unexpected and even inadvertent ways, and the program is hard to modify. The second version of the longest-line program is inferior to the first, partly for these reasons, and partly because it destroys the generality of two useful functions by writing into them the names of the variables they manipulate.        At this point we have covered what might be called the conventional core of C.	These exercises suggest programs of somewhat greater complexity than the ones earlier in this chapter.
(Output)
By the way, there is a tendenc-
y to make everything in sight
an extern variable because it
appears to simplify communicat-
ions - argument lists are shor-
t and variables are always the-
re when you want them. But ext-
ernal variables are always the-
re even when you don't want th-
em. Relying too heavily on ext-
ernal variables is fraught wit-
h peril since it leads to prog-
rams whose data connections ar-
e not all obvious - variables
can be changed in unexpected a-
nd even inadvertent ways, and
the program is hard to modify.-
 The second version of the lon-
gest-line program is inferior
to the first, partly for these-
 reasons, and partly because i-
t destroys the generality of t-
wo useful functions by writing-
 into them the names of the va-
riables they manipulate.    At-
 this point we have covered wh-
at might be called the convent-
ional core of C.    These exer-
cises suggest programs of some-
what greater complexity than t-
he ones earlier in this chapte-
r.
*/