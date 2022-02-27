/*
codechef    -  Triple Sort
problem-  https://www.codechef.com/MAY20B/problems/TRPLSRT
tags -

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>
typedef unsigned int uint;      //u
typedef unsigned long long ullong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
using namespace std;

struct rtriplet{
    int a,b,c;
};
void tshort(int& a,int& b,int& c)
{
        int temp = c;
        c = b;
        b = a;
        a = temp;
        return;
}
void tswap(int& a,int& b,int& c)
{
        int temp = a;
        a = b;
        b = c;
        c = temp;
        return;
}

void printVec(vector<int>& _in)
{
    printf("vector -> ");
    for (size_t i = 0; i < _in.size(); i++)
    {
        printf("%d ",_in[i]);
    }
    printf("\n");
}

bool SolveCase(ullong CaseNo)
{
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> vec(n+1,0);
    vector<int> pos(n+1,0);
    int temp;
    for (size_t i = 1; i <= n; i++)
    {
        scanf("%d",&vec[i]);
        pos[vec[i]]=i;
    }
    //printVec(vec);
    vector<rtriplet> solution;

    for (int i = 1; i <= n-2; i++)
    {
        if(i!=vec[i])
        {
            rtriplet op,opPos;
            if(i==pos[pos[i]])    // swaped??
            {
                int newop = 0;
                for (int j = i+1; j <= n; j++)
                {
                    if(j!=pos[i] && pos[j] !=j)
                    {
                        newop = j;
                        break;
                    }
                }
                if(newop==0)
                {
                     printf("-1\n");
                    return true;
                }
                op={i,newop,pos[i]};
                opPos={i,vec[newop],vec[i]};

            }
            else
            {
                op={i,pos[pos[i]],pos[i]};
                opPos={i,pos[i],vec[i]};
            }
            //rtriplet opPos{i,pos[i],vec[i]};
            //rtriplet opPos{i,op.b,vec[i]};
            tshort(vec[op.a],vec[op.b],vec[op.c]);
            tshort(pos[opPos.a],pos[opPos.b],pos[opPos.c]);
            //printf("op -> %d %d %d\n",op.a,op.b,op.c);
            //printVec(vec);
            solution.push_back(op);
        }
    }
    int len = solution.size();
    //printVec(vec);
    if(vec[n]== n)
    {
        if(len<=k)
        {
            printf("%d\n",len);
            for(auto m : solution)
            {
                printf("%d %d %d\n",m.a,m.b,m.c);
            }
            return true;
        }
    }
    printf("-1\n");
    return true;
    

    
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

/*
5
6 3
2 1 5 4 3 6
3 1
2 1 3
4 2
2 1 4 3
4 2
2 1 3 4
6 2
1 5 3 2 4 6



8
7 3
6 1 7 2 4 3 5
4 2
3 2 4 1
6 3
5 1 4 2 3 6
8 4
2 1 4 3 6 5 8 7
4 1
1 2 3 4
4 2
2 1 4 3
3 1
1 3 2
3 1
2 1 3
*/