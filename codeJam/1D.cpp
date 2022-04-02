/*

problem-  Chain Reactions (10pts, 12pts, 5pts)
Link- 
tags -

*/
//#include <bit/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <queue>
#include <set>
#include <algorithm>
#include <numeric>
typedef unsigned int uint;      //u
typedef unsigned long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
using namespace std;
//int f[100001];
//int indegree[100001];
//int out[100000];
bool SolveCase(ulong CaseNo)
{
    int n;
    cin>>n;
    vector<int> indegree(n,0);
    //fill(begin(indegree), begin(indegree)+n,0);
    vector<multiset<int> > vs(n);
    vector<int> out(n+1,0);
    int fun;
    for(int i=0;i<n;++i)
    {
        cin>>fun;
        vs[i].insert(fun);
    }
    for(int i=0;i<n;++i)
    {
        cin>>out[i];
        out[i]--;  // indexing zero
        if(out[i]>=0)
        indegree[out[i]]++;
    }
    queue<int> q;
    for(int i=0;i<n;++i)
    {
       if(indegree[i]==0)
            q.push(i);
    }
    long result=0;
    while(!q.empty())
    {
        int t = q.front();
        //cout<<t<<endl;
        q.pop();
        int to = out[t];
        if(to<0)
        {
            // if(vs[t].size()>1)
            //     vs[t].erase(vs[t].begin());
            result += accumulate(begin(vs[t]),end(vs[t]),0);
            //cout<<"r="<<result<<endl;
            continue;
        }
        vs[to].insert(vs[t].begin(),vs[t].end());
        vs[t].clear();
        --indegree[to];
        if(indegree[to]==0)
        {
            q.push(to);
            vs[to].erase(vs[to].begin());
        }   
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
