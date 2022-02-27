/*
codechef
problem- Golu and Sweetness
Link- https://www.codechef.com/problems/COZIE
tags -

*/
//#include <bit/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
using namespace std;
typedef unsigned int uint;      //u
typedef unsigned long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
const int M = 1000001;
int arr[100001];
int pre[100001];
int phi[M];

bool SolveCase(ulong CaseNo)
{
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;++i)
    {
        cin>>arr[i];
    }
    for (size_t i = 1; i <= n; i++)
    {
        if(arr[i]==3 || arr[i]==4 || arr[i]==6 )
            pre[i]=1;
    }
    for (size_t i = 2; i <= n; i++)
    {
        pre[i] += pre[i-1];
    }
    
    

    int l,r;
    for (size_t i = 0; i < q; i++)
    {
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<"\n";
        //int count=0;
        // for(int j=l;j<=r;++j)
        // {
        //     if(phi[arr[j]] > 1  &&  phi[arr[j]] == arr[j]-1)
        //         ++count;
        // }
        //cout<<count<<"\n";
    }
    


    return true;
}
void phi_fill();
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
    
    //phi_fill();
    
    ulong T=1;
    while(TestCases--/*true*/)
    {
        if(!SolveCase(T))
            break;
        T++;
    }
    return 0;
}

void phi_fill()
{
    phi[0] = 0;
    phi[1] = 1;
    for(int i=2;i<M;++i)
        phi[i] = i;
    for(int i=2;i<M;++i)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<M;j+=i)
            {
                phi[j] -= phi[j]/i;
            }
        }
    }

}