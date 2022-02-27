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
typedef long long ll;
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
ulong factorial(ulong n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
int kcount[101]={0};
ulong treeVisit(ll sum,uint k,uint min,uint start)
{
    if(sum < 0)
        return 0;
    else if( sum==0)
    {
        //check condition
        bool flg = false;
        for (int i = min; i <= k; ++i)
        {
            if(kcount[i]>0)
                flg=true;
        }
        if(!flg)
            return 0;

        // calulate possibilites
        ulong num=0,den=0;
        for (int i = 1; i < k; ++i)
        {
            num+=kcount[i];
            den+=factorial(kcount[i]);
        }
        ulong ways = factorial(num)/den;
        return ways;
    }
    ulong ways=0;
    for (int i = start; i <= k; ++i) 
    {
        kcount[i]++;
        ways+=treeVisit(sum-i,k,min,i);
        kcount[i]--;
    }
  
    return ways;
}

bool SolveCase(ulong CaseNo)
{
    uint n,k,d;
    scanf("%u %u %u",&n,&k,&d);

    //brutefoce tree
    ulong ways = treeVisit(n,k,d,1);

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