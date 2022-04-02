/*

problem- 1A Punched Cards
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
    // int n,t;
    // scanf("%d %d",&n,&t);
    int rows,cols;
    cin>>rows>>cols;
    cout<<"Case #"<<CaseNo<<":\n";
    string dotrow,brow;
    for(int i=0;i<cols;++i)
        dotrow+= "|.";
    dotrow += "|\n";
    for(int i=0;i<cols;++i)
        brow += "+-";
    brow += "+\n";
    brow[0] = brow[1] = dotrow[0] = '.';
    cout<<brow<<dotrow;
    brow[0]='+';brow[1] = '-';dotrow[0]='|';
    cout<<brow;
    for(int i=1;i<rows;++i)
    {
        cout<<dotrow<<brow;
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
