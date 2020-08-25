/*
 * Filename:    itob.c
 * Author:      beihai-chang
 * Date:        25-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Write the function itob(n,s,b) that converts the 
 * integer n into a base b character representation 
 * in the string s. In particular, itob(n,s,16) 
 * formats s as a hexadecimal integer in s.
 */

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
    char s[MAXLEN];

    printf("bin\tdec\thex\n");
    for (int i = -32; i < 64; i++)
    {
        itob(i, s, 2);
        printf("%s\t", s);
        itob(i, s, 10);
        printf("%s\t", s);
        itob(i, s, 16);
        printf("%s\n", s);
    }

    return 0;
}

void itob(int n, char s[], int b)
{
    int i, sign, remainder;
    sign = n;
    i = 0;
    do
    {
        remainder = sign < 0 ? -n % b : n % b;
        s[i++] = remainder > 9 ? remainder - 10 + 'a' : remainder + '0';
    } while (n /= b);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int i, j, temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}
/*
Output:
bin	dec	hex
-100000	-32	-20
-11111	-31	-1f
-11110	-30	-1e
-11101	-29	-1d
-11100	-28	-1c
-11011	-27	-1b
-11010	-26	-1a
-11001	-25	-19
-11000	-24	-18
-10111	-23	-17
-10110	-22	-16
-10101	-21	-15
-10100	-20	-14
-10011	-19	-13
-10010	-18	-12
-10001	-17	-11
-10000	-16	-10
-1111	-15	-f
-1110	-14	-e
-1101	-13	-d
-1100	-12	-c
-1011	-11	-b
-1010	-10	-a
-1001	-9	-9
-1000	-8	-8
-111	-7	-7
-110	-6	-6
-101	-5	-5
-100	-4	-4
-11	-3	-3
-10	-2	-2
-1	-1	-1
0	0	0
1	1	1
10	2	2
11	3	3
100	4	4
101	5	5
110	6	6
111	7	7
1000	8	8
1001	9	9
1010	10	a
1011	11	b
1100	12	c
1101	13	d
1110	14	e
1111	15	f
10000	16	10
10001	17	11
10010	18	12
10011	19	13
10100	20	14
10101	21	15
10110	22	16
10111	23	17
11000	24	18
11001	25	19
11010	26	1a
11011	27	1b
11100	28	1c
11101	29	1d
11110	30	1e
11111	31	1f
100000	32	20
100001	33	21
100010	34	22
100011	35	23
100100	36	24
100101	37	25
100110	38	26
100111	39	27
101000	40	28
101001	41	29
101010	42	2a
101011	43	2b
101100	44	2c
101101	45	2d
101110	46	2e
101111	47	2f
110000	48	30
110001	49	31
110010	50	32
110011	51	33
110100	52	34
110101	53	35
110110	54	36
110111	55	37
111000	56	38
111001	57	39
111010	58	3a
111011	59	3b
111100	60	3c
111101	61	3d
111110	62	3e
111111	63	3f
*/