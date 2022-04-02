/*
problem-  d1000000 (9pts, 11pts)
Link- 
tags -

*/
//#include <bit/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <algorithm>
typedef unsigned int uint;      //u
typedef unsigned long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
using namespace std;
int v[100001];
bool SolveCase(ulong CaseNo)
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>v[i];
    
    sort(begin(v),begin(v)+n);
    int result=0;
    for(int i=0;i<n;++i)
    {
        ++result;
        result = min(result,v[i]);
    }
    cout<<"Case #"<<CaseNo<<": "<<result<<"\n";
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
