/*
spoj 
problem- CEQU - Crucial Equation
Link- https://www.spoj.com/problems/CEQU/
tags -

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef unsigned int uint;      //u
typedef unsigned long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

bool SolveCase(ulong CaseNo)
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int g = gcd(a,b);
    if(c%g == 0 )
        printf("Case %d: Yes\n",static_cast<int>(CaseNo));
    else
        printf("Case %d: No\n",static_cast<int>(CaseNo));

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
    ulong T=1;

    while(TestCases--/*true*/)
    {
        if(!SolveCase(T))
            break;
        T++;
    }
    return 0;
}
