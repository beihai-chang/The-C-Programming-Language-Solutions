/*
 * Filename:    binsearch.c
 * Author:      beihai-chang
 * Date:        24-AUG-2020
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 * Our binary search makes two tests inside the loop, 
 * when one would suffice (at the price of more tests 
 * outside.) Write a version with only one test inside 
 * the loop and measure the difference in run-time.
 */

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void)
{
    int v[] = {1, 3, 5, 7, 10, 12, 13, 16, 19};
    printf("Array: [1, 3, 5, 7, 10, 12, 13, 16, 19]\n");
    for (int i = 0; i <= 20; i++)
        printf("%d: %d\n", i, binsearch(i, v, 9));
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return x == v[low] ? low : -1;
}
/*
Output:
Array: [1, 3, 5, 7, 10, 12, 13, 16, 19]
0: -1
1: 0
2: -1
3: 1
4: -1
5: 2
6: -1
7: 3
8: -1
9: -1
10: 4
11: -1
12: 5
13: 6
14: -1
15: -1
16: 7
17: -1
18: -1
19: 8
20: -1
*/