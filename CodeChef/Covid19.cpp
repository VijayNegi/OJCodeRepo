/*
Codechef
problem- https://www.codechef.com/MAY20B/problems/COVID19
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
int x[10];
bool SolveCase(ullong CaseNo)
{
    int n;
    scanf("%d",&n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
    int min=10, max=0;

    int streak=1;
    for (size_t i = 0; i < n-1; i++)
    {
        if(x[i+1]-x[i]>2){
                min = MIN(min,streak);
                max = MAX(max,streak);
                streak = 1;
        }
        else
           streak++;
    }
    min = MIN(min,streak);
    max = MAX(max,streak);
    
    printf("%d %d\n",min,max);
     
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