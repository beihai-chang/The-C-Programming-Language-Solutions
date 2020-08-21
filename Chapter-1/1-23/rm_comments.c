/*
 * Filename:    rm_comments.c
 * Author:      beihai-chang
 * Date:        21-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write a program to remove all comments from a C program. 
 * Don't forget to handle quoted strings and character 
 * constants properly. C comments don't nest.
 */

#include <stdio.h>

int main()
{
    int c, isliteral, blockcomment, linecomment, isreverse;

    isliteral = 0;
    blockcomment = 0;
    linecomment = 0;
    isreverse = 0;

    printf("Input code:\n");
    while ((c = getchar()) != EOF)
    {
        if (isreverse)
        {
            isreverse = 0;
            printf("%c", c);
        }
        else if (isliteral)
        {
            if (c == '"')
                isliteral = 0;
            else if (c == '\\')
                isreverse = 1;
            printf("%c", c);
        }
        else if (blockcomment)
        {
            if (c == '*')
                if ((c = getchar()) == '/')
                    blockcomment = 0;
        }
        else if (linecomment)
        {
            if (c == '\n')
            {
                linecomment = 0;
                printf("%c", c);
            }
        }
        else if (c == '/')
        {
            if ((c = getchar()) == '/')
                linecomment = 1;
            else if (c == '*')
                blockcomment = 1;
        }
        else if (c == '"')
        {
            isliteral = 1;
            printf("%c", c);
        }
        else
            printf("%c", c);
    }

    return 0;
}