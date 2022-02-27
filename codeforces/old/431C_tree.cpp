/*
codeforce
problem-k-Tree
tags - dp, implementation, trees

*/
//#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
//#include <math.h>
typedef unsigned int uint;      //u
typedef unsigned long long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

ulong treeVisit(uint sum,uint k,uint min)
{

    if(sum==min || sum==0)
        return 1;
    ulong ways=0;
    uint upper = MIN(sum-min,min-1);
    for (int i = 1; i <= upper; ++i) // 1 to (min -1) branch 
    {
        ways+=treeVisit(sum-i,k,min);
    }
    upper =MIN(sum,k);
    for (int i = min; i <= upper; ++i)
    {
        ways+=treeVisit(sum-i,k,1);
    }
    return ways;
}

bool SolveCase(ulong CaseNo)
{
    uint n,k,d;
    scanf("%u %u %u",&n,&k,&d);

    //brutefoce tree
    ulong ways = treeVisit(n,k,d);

    ulong mod = (ways% 1000000007);
    printf("%I64d\n",mod);
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