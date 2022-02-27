/*
spoj
problem-
Link-  https://www.spoj.com/problems/VECTAR8/
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
const int L = 1e6+5;
vector<bool> s;
vector<int> primes;
bool SolveCase(ulong CaseNo)
{
    int n,t;
    scanf("%d",&n);
    static bool pre = true;
    
    
    if(pre)
    {
        pre = false;
        int sqrtL = sqrt(L);
        s = vector<bool>(L+1,true);
        s[0] = s[1] = false;
        int i = 2;
        for(;i<=sqrtL;++i)
        {
            if(s[i])
            {

                for(int j = i*i;j<=L;j+=i)
                {
                    s[j] = false;
                }
            }
        }
        for(int i=2;i<10;++i)
        {
            if(s[i])
                primes.push_back(i);
        }

        for(int i=11;i<L;i+=2)
        {
            if(s[i])
            {
                //cout<<"i="<<i<<"\n";
                int num = i;
                int pri=0;
                int multiplier = 1;
                while(num>9)
                {
                    num /=10;
                    multiplier*=10;
                }
                num*=multiplier;
                num = i - num;
                //cout<<"num="<<num<<"\n";
                if(s[num])
                    primes.push_back(i);
                else
                    s[i] = false;
               
                // while(num>9)
                // {
                //     pri += num%10 * multiplier;
                //     //cout<<"pri="<<pri<<"\n";
                //     // if(pri>L)
                //     //     cout<<"pri>L="<<pri<<",i="<<i<<"\n";
                //     if(!s[pri])
                //     {
                //         s[pri] = false;
                //         break;
                //     }
                //     multiplier*=10;
                //     num /=10;
                // }
                // if(s[i])
                //     primes.push_back(i);
                }
        }
    }
    int count=0;
    int sz = primes.size();
    int lo = 0,hi = sz - 1,mi;
            
    while(lo < hi){
        mi = (lo + hi + 1) / 2;
        
        if(primes[mi] > n) hi = mi - 1;
        else lo = mi;
    }
            
    printf("%d\n",lo + 1);
    // for(auto& p:primes)
    // {
    //     if(p<=n)
    //         ++count;
    //     else
    //         break;
    // }

    // for(int i=0;i<=n;++i)
    // {
    //     if(s[i])
    //     {
    //         int num = i;
    //         int pri=0;
    //         int multiplier = 1;
    //         while(num)
    //         {
    //             pri += num%10 * multiplier;
    //             if(!s[pri])
    //             {
    //                 s[pri] = false;
    //                 continue;
    //             }
    //             multiplier*=10;
    //             num /=10;
    //         }
    //         ++count;
    //     }
    // }
    //cout<<count<<"\n";

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
