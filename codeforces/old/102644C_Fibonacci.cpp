/*
codeforce
problem- https://codeforces.com/gym/102644/problem/C
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
typedef unsigned int uint;      //u
typedef unsigned long long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
using vi = std::vector<int>;
using vii = std::vector<vi>;
using namespace std;
const int mod = 1e9 + 7;

vii matMul(vii mat1,vii mat2)
{
    int s = mat1.size();
    vii res(s,vi(s,0));
    // multiply mat
    for(int i=0;i<s;++i)
    {
        for(int j=0;j<s;++j)
        {
            for(int k=0;k<s;++k)            
            {
                res[i][j] = (res[i][j] + (long long)mat1[i][k] * mat2[k][j]) % mod ;
            }
        }
    }
    return res;
}

vii matExp(vii mat,long long n)
{
    int s = mat.size();
    vii res(s,vi(s,0));
    for(int i=0;i<s;++i)
        res[i][i] = 1;

    while(n>0)
    {
        if(n%2)
            res  = matMul(res,mat);
        mat = matMul(mat,mat);
        n = n>>1;
    }
    return res;
}

bool SolveCase(ulong CaseNo)
{
    long long n;
    cin>>n;
    //scanf("%d",&n);
    vii mat(2,vi(2,1));
    mat[0][0] = 0; //reset it
    vii fib(2,vi(2,0));
    fib[0][1] = 1;
    cout<<"before-"<<endl;
    cout<<fib[0][0]<<"-"<<fib[0][1]<<endl;
    cout<<fib[1][0]<<"-"<<fib[1][1]<<endl;

    mat = matExp(mat,n);
    cout<<"matExp-"<<endl;
    cout<<mat[0][0]<<"-"<<mat[0][1]<<endl;
    cout<<mat[1][0]<<"-"<<mat[1][1]<<endl;
     fib = matMul(fib, mat); // Note order matters 
    
    cout<<"res-"<<endl;
    cout<<fib[0][0]<<"-"<<fib[0][1]<<endl;
    cout<<fib[1][0]<<"-"<<fib[1][1]<<endl;
    cout<<"----------"<<endl;
    cout<<fib[0][0]<<endl;
    // if(n%2==0)
    //     printf("%d",fib[0][0]);
    // else
    //     printf("%d",fib[0][1]);


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
