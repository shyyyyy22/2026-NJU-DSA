#ifndef ALGORITHMS
#define ALGORITHMS
#include <iostream>
#include <string.h>
int BF(const char *T, const char *P);
void GetNext(const char *P, int next[]);
int KMP(const char *T, const char *P, int next[]);
#ifdef ALGO_STRING_IMPLEMENTATION
int BF(const char *T, const char *P)
{
    int len = strlen(T);
    int p_len = strlen(P);
    int i = 0, j = 0;
    for (i = 0; i < len - p_len + 1; ++i)
    {
        for (j = 0; j < p_len; ++j)
        {
            if (T[i + j] != P[j])
            {
                break;
            }
        }
        if (j == p_len)
        {
            return i;
        }
    }
    return -1;
}
void GetNext(const char *P, int next[])
{
    next[0] = -1;
    int i = 0, k = -1;
    int len = strlen(P);
    while (i < len)
    {
        if (k == -1 || P[i] == P[k])
        {
            i++;
            k++;
            if (i < len)
            {
                next[i] = k;
            }
        }
        else
        {
            k = next[k];
        }
    }
}
int KMP(const char *T, const char *P, int next[])
{
    int len = strlen(T);
    int p_len = strlen(P);
    int i = 0, j = 0;
    while (i < len && j < p_len)
    {
        if (j == -1 || T[i] == P[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j < p_len)
    {
        return -1;
    }
    else
    {
        return i - p_len;
    }
}
#endif
#endif // ALGORITHMS