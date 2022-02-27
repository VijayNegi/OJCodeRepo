/*
codeChef
problem- https://www.codechef.com/MAY21C/problems/LKDNGOLF
tags -

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef unsigned int uint;      //u
typedef unsigned long long ullong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

bool SolveCase(ullong CaseNo)
{
    int x,n,k;
    scanf("%d %d %d",&n,&x,&k);

    int ans = 0;
    if(x%k==0 || x%k==((n+1)%k))
        ans=1;
    
    
    printf("%s\n",ans?"Yes":"No");
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