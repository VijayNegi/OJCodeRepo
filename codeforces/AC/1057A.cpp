/*
codeforce 
problem- 1057A - Bmail Computer Network
tags - live contest

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef unsigned int uint;      //u
typedef unsigned long long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
uint r[200001];
bool SolveCase(ulong CaseNo)
{
    uint n;
    scanf("%u",&n);
    for (int i = 1; i < n; ++i)
    {
        scanf("%u",&r[i]);
    }
    uint temp=0;
    int rIndex=n;
    uint index=n-1;
    while(rIndex>1)
    {
        temp=r[rIndex-1];
        r[index]=rIndex;
        rIndex=temp;
        index--;
    }
    printf("1 ");
    for (int i = ++index; i < n; ++i)
    {
        printf("%u ",r[i] );
    }
    //printf("%u\n",n);
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