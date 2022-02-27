/*
codeforce
problem-279B - Books
tags - binary search , brute force , implementation, two pointers

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef unsigned int uint;      //u
typedef unsigned long long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
uint a[100001];
uint b[100001];
bool SolveCase(ulong CaseNo)
{
    uint n,t;
    scanf("%u %u",&n,&t);
    a[0]=b[0]=0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%u",&a[i]);
        b[i]= b[i-1]+a[i];
    }
    uint max=0;
    uint lastj = 0;
    for (int i = 1; i <= n; ++i)
    {
        lastj=(lastj>(i-1))?lastj:i-1;
        for (; (b[lastj]-b[i-1] <= t) && ( lastj<=n); lastj++);
        if(max<(lastj-i))
            max = lastj-i;
        lastj--;
    }
    printf("%u\n",max);
    return true;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    // disable buffering on stdout completely
    setbuf(stdout, NULL);
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
   
#endif
    int TestCases = 1;
    //scanf("%d",&TestCases);
    ulong T=1;

    while(TestCases--/*true*/)
    {
        if(!SolveCase(T));
            break;
        T++;
    }
    return 0;
}