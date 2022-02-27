/*
codeforce
problem- J. Once Upon A Time
Link- http://codeforces.com/gym/100963
tags -

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef unsigned int uint;      //u
typedef unsigned long long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}

bool SolveCase(ulong CaseNo)
{
    int n,m,a,k;
    scanf("%d %d %d %d",&n,&m,&a,&k);
    if(n==0 && m==0 && a==k && k==0)
        return false;
    //printf("Impos\n");
    int w_start =   n;
    int m_start = a + k;
    if(w_start == m_start)
        printf("%d\n",w_start);
    else
    {
        int g = gcd(m,k);
        if(g>=0)
            printf("%d\n",g);
        else
            printf("Impossible\n");
    }

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
    int TestCases = 50;
    //scanf("%d",&TestCases);
    ulong T=1;

    while(TestCases--/*true*/)
    {
        if(!SolveCase(T))
            break;
        T++;
    }
    return 0;
}
