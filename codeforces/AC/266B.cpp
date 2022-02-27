/*
codeforce
problem-266B Queue at the school
tags - constructive algorithms,graph matchings,implementation,shortest paths

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef unsigned int uint;
typedef unsigned long long ulong;
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)
char queue[51];
int commulative[51];
int canMove[51];
void swap(char* c1,char* c2)
{
    char temp;
    temp= *c1;
    *c1=*c2;
    *c2=temp;
};
bool SolveCase(ulong CaseNo)
{
    int n,t;
    scanf("%d %d",&n,&t);
    scanf("%s",queue);
    int len= strlen(queue);
    while(t--)
    {
        for (int i = 0; i < n-1; ++i)
        {
            if(queue[i]=='B' && queue[i+1]=='G')
            {
                queue[i]='G'; 
                queue[i+1]='B';
                i++;
            }
        }
    }
#if 0
    //precalculate how much each boy can move,i.e. count girls in range t;
    // Note - as Girls will move forward and boys will move backwords ,so how much each boy can move will be 
    // girls in range T+x (where x is no of girls in range T)
    uint MoveGirls=0;
    int mT=t;
    //printf("t- %u\n",t );
    for (int ii = len-1;  ii>=0; --ii)
    {
        commulative[ii]=MoveGirls;
        if(ii >= len-1-mT)
        {
            canMove[ii]=MoveGirls;
        }
        else
        {
            canMove[ii]= commulative[ii]-commulative[ii+mT];//canMove[ii+1]+((queue[ii+1]=='G')?1:0)-((queue[ii+mT+1]=='G')?1:0);
            int start = ii+mT;
            int end = start+canMove[ii];
            if(end>len-1)
                end = len-1;
            canMove[ii]+= commulative[start]-commulative[end];
        }
        
        if(queue[ii]=='G')
            MoveGirls++;
        
    }
    //printf("n-%u\n",n );
    // if(len>2)
    // {
    // for (int i = len-1-mT-1; i >= 0; --i)
    // {
    //     if(queue[i]=='B')
    //     {
    //         //canMove[i]=canMove[i+1]-((queue[i+t+1]=='G' && canMove[i+1]>0)?1:0);
    //         canMove[i]=canMove[i+1]+((queue[i+1]=='G')?1:0)-((queue[i+mT+1]=='G')?1:0);
    //         int MoveinT = canMove[i];
    //         canMove[i]+=canMove[i+MoveinT]
    //     }
    //     else
    //     {
    //         //canMove[i]=canMove[i+1]-((queue[i+t+1]=='G' && canMove[i+1]>0)?1:0);
    //         canMove[i]=canMove[i+1]+((queue[i+1]=='G')?1:0)-((queue[i+mT+1]=='G')?1:0);
    //         //MoveGirls++;
    //     }
    // }
    // }
    for (int i = 0; i < len; ++i)
    {
        printf("%u",commulative[i] );
    }
    printf("\n");
    for (int i = 0; i < len; ++i)
    {
        printf("%u",canMove[i] );
    }
     printf("\n");
     //fflush(stdout);
    // now move boys based on canMove count
    for (int i = len-1; i >= 0 ; --i)
    {
        if(queue[i]=='B')
        {
            swap(&queue[i],&queue[i+(canMove[i]>t?t:canMove[i])]);
        }
    }
#endif
#if 0
    //shift Boys back by t places
    
    uint lastboy=len;
    uint uT=0;
    int ConBoys=0;
    for (int i = len-1; i >=0; --i)
    {
        if(queue[i]=='B')
        {
            uT-=ConBoys;
            if((i+t)>=lastboy && (i+1)!=lastboy)
            {
                swap(&queue[i],&queue[lastboy-1]);
                lastboy--;
            }
            else if((i+t)<lastboy)
            {
                swap(&queue[i],&queue[i+t]);
                lastboy=i+t;
            }
            else
                lastboy--;
            ConBoys++;
        }
        else
            ConBoys=0;
        
    }
#endif
    printf("%s\n",queue );
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
        if(!SolveCase(T));
            break;
        T++;
    }
    return 0;
}