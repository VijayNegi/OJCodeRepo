/*
Leetcode
problem- 844. Backspace String Compare
tags -

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <iostream>
typedef unsigned int uint;      //u
typedef unsigned long long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
using namespace std;

bool SolveCase(ulong CaseNo)
{
    std::string S,T;
    std::cin>>S>>T;
    
    cout<<"Case - "<<CaseNo<<" -> ";
    const char* pS = S.c_str();
    const char* pT = T.c_str();
    int slen = S.length();
    int tlen = T.length();

    int scount = 0;
    int tcount = 0;
    slen--;
    tlen--;
    bool same = true;
    while (true)
    {
        //cout<<"in loup\n";
        if(slen >= 0)
        {
            if(pS[slen]== '#' )
            {
                slen--;
                scount--;
                continue;
            }
            else if(scount< 0 )
            {
                slen--;
                scount++;
                continue;
            }
        }
        if(tlen>=0)
        {
            if(pT[tlen]== '#' )
            {
                tlen--;
                tcount--;
                continue;
            }
            else if(tcount< 0 )
            {
                tlen--;
                tcount++;
                continue;
            }
        }

        if(slen<0 && tlen<0)
            break;
        if(slen<0 || tlen<0)
        {
            same= false;
            break;
        }
        if(pS[slen] != pT[tlen])
        {
            //cout<<"comparison failed\n";
            same = false;
            break;
        }
        slen--;
        tlen--;
        
    }
    cout<<(same?"true\n":"false\n");
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
    int TestCases = 4;
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