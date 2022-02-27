/*
codeforce
problem-71A - way too long words
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>
typedef unsigned int uint;
typedef unsigned long long ulong;
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
char word[101];
bool SolveCase(ulong CaseNo)
{
    fprintf(stderr, "%d\n", CaseNo);
    //printf("case -%d -",CaseNo);
    scanf("%s",word);
    //fprintf(stderr, "%s\n", word);
    uint lenth = strlen(word);
    if(lenth>10)
    {
        //printf("%d\n",lenth );
        sprintf(word+1,"%d%c",lenth-2,word[lenth-1]);
    }
    printf("%s\n",word);
    return true;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
    freopen("err.txt","w",stderr);
#endif
    int TestCases = 0;
    scanf("%d",&TestCases);
    //printf("Total cases - %d\n",TestCases);
    ulong T=1;
    while(TestCases--/*true*/)
    {
        if(!SolveCase(T))
            break;
        T++;
    }
    return 0;
}