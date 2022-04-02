/*

problem- 3D Printing (13pts)
Link- 
tags -

*/
//#include <bit/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef unsigned int uint;      //u
typedef unsigned long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
using namespace std;
bool SolveCase(ulong CaseNo)
{
    int prt[3][4];
    for(int i=0;i<3;++i)
        for(int j=0;j<4;++j)
            cin>>prt[i][j];
    for(int i=1;i<3;++i)
        for(int j=0;j<4;++j)
            prt[0][j] = min(prt[0][j],prt[i][j]);
    int ink = 1000000;
    cout<<"Case #"<<CaseNo<<": ";
    for(int j=0;j<4;++j)
    {
        if(ink > prt[0][j])
        {
            ink -= prt[0][j];
        }
        else
        {
            prt[0][j] = ink;
            ink=0;
        }
        //cout<<prt[0][j]<<((j<3)?" ":"\n");
    }
    if(ink>0)
    {
        cout<<"IMPOSSIBLE\n";
        return true;
    }
    for(int j=0;j<4;++j)
    {
        cout<<prt[0][j]<<((j<3)?" ":"\n");
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
