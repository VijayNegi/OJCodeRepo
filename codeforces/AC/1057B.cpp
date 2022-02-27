/*
codeforce
problem- DDoS
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

uint r[5000];
ulong sum[5001];
bool SolveCase(ulong CaseNo)
{
    uint t;
    scanf("%u",&t);
    sum[0]=0;
    for (int i = 0; i < t; ++i)
    {
        scanf("%u" , &r[i]);
        sum[i+1] = sum[i]+r[i];
    }

    uint minS=0;
    uint tempS=0;
    uint tempI=0;
    for (int i = 0; i < t; ++i)
    {
        tempS=0;
        tempI=i;
        while(tempI<t && r[tempI++]>100 )
            tempS++;
        minS= (minS<tempS)? tempS: minS;
    }
    if (minS!=0)
    {
        for (int i = 1; i <= t; ++i)
        {
            tempS = 0;
            uint tt=0;
            uint k =i+minS;
            while(k<=t)
            {
                tt=k-i+1;
                if(sum[k]-sum[i-1] > tt*100)
                    tempS = tt;
                k++;
            }
            minS= (minS<tempS)? tempS: minS;
        }
    }
    printf("%u\n",minS);
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