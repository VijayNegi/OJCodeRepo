/*
codeforce
problem-
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
int corona[26];
bool SolveCase(ullong CaseNo)
{
    int n,t;
    scanf("%d %d",&n,&t);
    memset(corona,0,sizeof(int)*26);
    char c;
    scanf("%c",&c);// extra
    for (size_t i = 0; i < n; i++)
    {
        scanf("%c",&c);
        corona[c-'a']++;
        
    }
    int isoc;
    
    for (size_t j = 0; j < t; j++)
    {
        int queue=0;
        scanf("%d", &isoc);
        for (size_t i = 0; i < 26; i++)
        {
            queue+= (corona[i]>isoc)?corona[i]-isoc:0;
        }
        printf("%d\n",queue);
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