/*
codeforce
problem-158A Next Round
tags - implimentation
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef unsigned int uint;
typedef unsigned long long ulong;
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
uint scores[100];
bool SolveCase(ulong CaseNo)
{
    uint k,n;
    scanf("%u %u",&n,&k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%u",&scores[i]);
    }
    uint advance=k-1;
    while(advance<n-1)
    {
        if(scores[advance]>scores[advance+1])
            break;
        advance++;
    }
    uint nonZero=0;
    for (int i = 0; i <= advance; ++i)
    {
        if(scores[i]>0)
            ++nonZero;
        /* code */
    }
    printf("%u\n",nonZero);
    // solve case here
    return true;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif
    int TestCases = 0;
    //scanf("%d",&TestCases);
    ulong T=1;

    while(/*TestCases--*/true)
    {
        if(!SolveCase(T));
            break;
        T++;
    }
    return 0;
}