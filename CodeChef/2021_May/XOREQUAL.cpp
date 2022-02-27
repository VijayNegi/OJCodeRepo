/*
codeChef
problem- https://www.codechef.com/MAY21C/problems/XOREQUAL
tags -

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
typedef unsigned int uint;      //u
typedef unsigned long long ullong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
#define MOD 1000000007

bool SolveCase(ullong CaseNo)
{
    int n;
    scanf("%d",&n);
    ullong ans=1;
    --n;
    ullong x = 2;
    while (n>0)
    {

        if (n & 1) {
            ans = (ans*x)%MOD;
        }
        n = n >> 1;
        x = (x * x)%MOD;
    }

 //---------------
    // if(n>31)
    // {
    //     int c = n/31;
        
    //     int r = n%31;
    //     ans = ans*pow(2,31);
    //     ans%=MOD;
    //     ans*=c;
    //     ans%=MOD;
    //     ans = ans*pow(2,r);
    //     ans%=MOD;
    //     printf("%d %d %llu\n",c,r,ans);
    // }
    // else
    // {
    //     ans = ans*pow(2,n);
    //     ans%=MOD;
    // }
    
    printf("%llu\n",ans);
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
    scanf("%d",&TestCases);
    ullong T=1;

    while(TestCases--/*true*/)
    {
        if(!SolveCase(T))
            break;
        T++;
    }
    return 0;
}