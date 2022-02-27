/*

problem- https://www.codechef.com/MAY20B/problems/CHANDF
tags -

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef unsigned int uint;      //u
typedef unsigned long long ullong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

int Rmsb(int n)
{
    int i;
    for(i=1;n/i;i*=2);
    return n^i/2;
};
int fn(int x,int y,int z)
{
    return (x & z) * (y & z);
}

int bruteForce(int x,int y,int l,int r)
{
    size_t z(0),sum(0);
    size_t _x = x,_y = y;
    size_t temp;
    for (int i = r; i >= l; i--)
    {
        temp = (x & i) * (y & i);
        if(temp>=sum)
        {
            z = i;
            sum = temp;
        }
    }
    return z;
}


bool SolveCase(ullong CaseNo)
{
    int x,y,l,r;
    scanf("%d %d %d %d",&x,&y,&l,&r);

    uint sol = x | y;

    int ans = sol;
    while(ans>r)
    {
        ans = Rmsb(ans);
    }
    //printf("%d\n",ans);
    //if((x & r) != 0 && (y & r) != 0)
    //    ans = ((r & sol)>ans)?r & sol : ans;
    ans = (fn(x,y,ans) > fn(x,y,r & sol)?ans:r& sol);
        
    
    //printf("%d\n",ans);
    int brute = bruteForce(x,y,l,r);
    printf("result-> %d | brute-> %d  ---%d - %d\n",ans,brute,fn(x,y,ans),fn(x,y,brute));

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
    scanf("%d",&TestCases);
    ullong T=1;

    while(TestCases--/*true*/)
    {
        if(!SolveCase(T))
            break;
        T++;
    }
    return 0;
}