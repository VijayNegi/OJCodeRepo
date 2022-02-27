/*
codeforce
problem- 476B - Dreamoon and WiFi
tags - bitmasks, brute force ,combinatorics, dp, math ,probabilitie

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef unsigned int uint;      //u
typedef unsigned long long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
char a[11];
char b[11];
int locA = 0,locB=0;
int Space = 0;
int fav = 0;
bool recurseHelp(int currentloc, int count)
{
    if(count == 0)
    {
        if(currentloc == locA) 
            fav++;
        Space++;
    }
    else
    {
        recurseHelp(currentloc+1, count-1);
        recurseHelp(currentloc-1,count-1);
    }
    return true;
}
bool SolveCase(ulong CaseNo)
{
    int n,t;
    scanf("%s",&a);
    scanf("%s",&b);
    int lenA = strlen(a);
    int lenB = strlen(b);
    locA = 0,locB = 0;
    Space = 0; fav=0;
    int UnknownB=0;
    for (int i = 0; i < lenA; ++i)
    {
        if(a[i]=='+')
            locA++;
        else
            locA--;
        if(b[i]=='+')
            locB++;
        else if (b[i]=='-')
            locB--;
        else
            UnknownB++;
    }

    // locA is final location of A
    recurseHelp(locB,UnknownB);
     float prob = (fav)/(float)Space;
    //printf("%d\n",lenA );
    //printf("%s\n", a);
    //printf("%d\n",fav );
    //printf("%d\n",Space );
    printf("%.12f\n", prob);
    
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