/*
spoj
problem- https://www.spoj.com/problems/TDPRIMES/
Link- 
tags -

*/
//#include <bit/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>
using namespace std;
typedef unsigned int uint;      //u
typedef unsigned long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
const int N = 1e8;

bool SolveCase(ulong CaseNo)
{

    vector<bool> s(N+1,true);
    vector<int> primes;
    s[0] = s[1] = false;

    for(int i=2;(long long)i*i<=N;++i)
    {
        if(s[i])
        {
            for(int j = i*i;j<=N;j+=i)
            {
                s[j] = false;
            }
        }
    }
    cout<<2<<"\n";
    int count = 1;
    int k=101;
    for (int i = 3; i < N; i+=2)
    {
        if(s[i] && ++count==k)
        {
            k+=100;
            printf("%d\n",i);
        }
        
    }

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
