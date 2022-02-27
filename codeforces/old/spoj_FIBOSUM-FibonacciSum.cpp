/*
spoj 
problem- FIBOSUM - Fibonacci Sum
Link- https://www.spoj.com/problems/FIBOSUM/
tags -

*/
//#include <bit/stdc++.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef unsigned int uint;      //u
typedef long long ll;
//typedef unsigned long long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
#define REP(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
const int mod = 1e9 + 7;

vii matMul(vii mat1, vii mat2)
{
    // we should check for matrix multiplication here
    int n = mat1.size();
    vii res(n,vi(n,0));
    REP(i,n)
    {
        REP(j,n)
        {
            REP(k,n)
            {
                res[i][j] = (res[i][j] + (ll)mat1[i][k]*mat2[k][j])%mod;
            }
        }
    }
    return res;
}

vii matExp(vii mat, ll n)
{
    int s = mat.size();
    vii res(s, vi(s,0));
    REP(i,s)
        res[i][i] = 1;
    while(n)
    {
        if(n%2)
            res = matMul(res,mat);
        mat = matMul(mat,mat);
        n/=2;
    }
    return res;
}

bool SolveCase(ll CaseNo)
{
    ll n,m;
    cin>>n>>m;

    vii mat(2,vi(2,1));
    mat[0][0] = 0;
    auto res = matExp(mat,n+1);
    auto res1 = matExp(mat,m+2);
    ll a = (res1[0][1] - 1)%mod;
    ll b = (res[0][1] - 1)%mod;

    ll sum = ((a - b)%mod + mod)%mod;
    
    // ll sum = res[0][1];
    // ll a = res[0][1];
    // ll b = res[1][1];
    // while(n!=m)
    // {
    //     sum = (sum + b)%mod;
    //     ++n;
    //     int temp = a;
    //     a = b;
    //     b = (b + temp)%mod;
    // }
    cout<<sum<<"\n";
    //int sum = ((long long)res[0][0] + res[0][1])%mod;
   

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
    ll T=1;

    while(TestCases--/*true*/)
    {
        if(!SolveCase(T))
            break;
        T++;
    }
    return 0;
}
