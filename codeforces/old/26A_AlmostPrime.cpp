/*
codeforce
problem- A. Almost Prime
Link-  http://codeforces.com/contest/26/problem/A
tags -

*/
//#include <bit/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;
typedef unsigned int uint;      //u
typedef unsigned long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

bool SolveCase(ulong CaseNo)
{
    int n;
    scanf("%d",&n);
    int sqrtL = sqrt(n);
    vector<int> s = vector<int>(n+1,0);
    s[0] = s[1] = 1;
    int i = 2;
    for(;i<=n;++i)
    {
        if(s[i]==0)
        {

            for(int j = i*2;j<=n;j+=i)
            {
                ++s[j];
            }
        }
    }
    int count=0;
    for(int i=0;i<=n;++i)
    {
        if(s[i]==2)
            ++count;
    }
    cout<<count<<"\n";

    return true;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    // disable buffering on stdout completely
    setbuf(stdout, NULL);
    //for io streams
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
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
        if(!SolveCase(T))
            break;
        T++;
    }
    return 0;
}
