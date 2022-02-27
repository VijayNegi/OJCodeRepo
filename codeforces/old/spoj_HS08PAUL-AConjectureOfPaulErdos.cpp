/*
spoj
problem- https://www.spoj.com/problems/HS08PAUL/
Link- 
tags -

*/
//#include <bit/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <math.h>
using namespace std;
typedef unsigned int uint;      //u
typedef unsigned long ulong;  //use %I64d for read/write
typedef long long ll;
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

unordered_set<int> x2;
vector<int> x4;
vector<int> primes;
set<int> ReqPrimes;
const int L = 1e7;
inline ll form(const int i, const int j) {
    return (i * i) + (j * j * j * j);
}

bool SolveCase(ulong CaseNo)
{
    int n;
    scanf("%d",&n);
    static bool pre = true;
    
    
    if(pre)
    {
        pre = false;
        // for(int i=1;(long long)i*i<L;++i)
        // {
        //     int i2 = i*i;
        //     x2.insert(i2);
        //     long long i4 = (long long)i2*i2;
        //     if(i4<L)
        //         x4.push_back(i4);
        // }
        //cout<<"x4size="<<x4.size()<<endl;
        int sqrtL = sqrt(L);
        vector<bool> s(L+1,true);
        s[0] = s[1] = false;
        int i = 2;
        for(;i<=sqrtL;++i)
        {
            if(s[i])
            {
                //primes.push_back(i);
                for(int j = i*i;j<=L;j+=i)
                {
                    s[j] = false;
                }
            }
        }
        // primes.push_back(2);
        // for (int i = 3; i < L+1; i+=2)
        // {
        //     if(s[i] )
        //     {
        //         primes.push_back(i);
        //     }
        // }
        
        // if(!(i%2))
        //     ++i;
        // for (; i < L; i+=2)
        // {
        //     if(s[i])
        //     {
        //         primes.push_back(i);
        //     }
        // }
        
        int x = 1;
       
        for (int x = 1; x <= sqrtL; ++x) {
            for (int y = 1; form(x, y) <= L; ++y) {

                ll formula = form(x, y);
                if (s[formula]) {
                    ReqPrimes.insert(formula);
                }

                                                // almost forgot to increment (while loops are dangerous)
            }
        }

    }
    int count=0;
    // for(const auto& p:primes)
    // {
    //     if(p>n)
    //         break;

    //     for(int k=0;k<x4.size() && x4[k]<p;++k)
    //     {
    //         if(x2.count(p-x4[k]))
    //         {
    //                 ++count;
    //         }
                
    //     }
 
    // }
    int counter = 0;

    bool flag = true;
    for (int Paul : ReqPrimes) {
        if (Paul > n) {
            cout << counter << "\n";
            flag = false;
            break;
        }
        ++counter;
    }
    if (flag)
        cout << ReqPrimes.size() << "\n";


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
