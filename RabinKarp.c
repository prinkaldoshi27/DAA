// Rabin-Karp algorithm in C

#include <stdio.h>
#include <string.h>

#define d 10

void rabinKarp(char pattern[], char text[], int q)
{
    int m = strlen(pattern);
    int n = strlen(text);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    // Calculate hash value for pattern and text
    for (i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Find the match
    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m)
                printf("Pattern is found at position:  %d \n", i + 1);
        }
    }
}

int main()
{
    char text[] = "ABCCDDAEFG";
    char pattern[] = "CDD";
    int q = 13;
    rabinKarp(pattern, text, q);
}