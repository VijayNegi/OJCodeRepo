/*
codeforce
problem- Shandom Ruffle
Link - https://codeforces.com/gym/102787/problem/A
tags -

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <list>
#include <iostream>
#include <math.h>
using namespace std;
typedef unsigned int uint;      //u
typedef unsigned long long ulong;  //use %I64d for read/write
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

template<typename T>
std::ostream& operator<<(std::ostream& s, const std::list<T>& v) 
{
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto& e : v) {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}

void printBuff(int* buff,int size)
{
    for (size_t i = 0; i < size; i++)
    {
       printf("%d ",buff[i]);
    }
    printf("\n");
}

void swap(int& a, int& b)
{
    int temp=a;
    a=b;
    b=temp;
}
void shandom_ruffle(int a, int b, int* array,int arrlen) {
  int bStart=b;
  while (a<bStart && b<arrlen) {
    //swap(array[a], array[b]); //swap the values at indeces a and b
    array[a]-= array[b];
    array[b]+= array[a];
    array[a]= array[b] - array[a];
    //printf("%d %d \n",a,b);
    //printBuff(array,arrlen);
    a++;
    b++;
  }
}
int buff[1000000];
void shandom_ruffleMemCopy(int a, int b, int* array,int arrlen) {
  //int bStart=b;
  int count = min(b-a,arrlen- b );
  if(count < 1)
    return;

  while(count>0)
  {
      int len = min(count,1000000);
      //printf("len - %d \n",len);
      int size = len* sizeof(int);
      memcpy(buff,array+a,size);
      memcpy(&array[a],&array[b],size);
      memcpy(&array[b],buff,size);
      a+=len;
      b+=len;
      count -=len;

  }
}

// void shandom_ruffleList(int a, int b, list<int>& data,int arrlen) {
//   int bStart=b;
//   int count = min(b-a,arrlen- b );
//   if(count < 1)
//     return;
//   while (a<bStart && b<arrlen) {
//     //swap(array[a], array[b]); //swap the values at indeces a and b
//     array[a]-= array[b];
//     array[b]+= array[a];
//     array[a]= array[b] - array[a];
//     //printf("%d %d \n",a,b);
//     //printBuff(array,arrlen);
//     a++;
//     b++;
//   }
// }

bool SolveCase(ulong CaseNo)
{
    int n;
    scanf("%d",&n);
    int *a = new int[n];
    int *b = new int[n];
    int *data = new int[n];
    for(int i = 0;i<n;++i)
    {
        scanf("%d %d",&a[i],&b[i]);
        data[i]=i+1;
    }

    for (size_t i = 0; i < n; i++)
    {
       shandom_ruffleMemCopy(a[i]-1,b[i]-1,data,n);
       //printBuff(data,n);
    }
    printBuff(data,n);
    return true;
}
/*
bool SolveCaseList(ulong CaseNo)
{
    int n;
    scanf("%d",&n);
    int *a = new int[n];
    int *b = new int[n];
    list<int> data;
    //int *data = new int[n];
    for(int i = 0;i<n;++i)
    {
        scanf("%d %d",&a[i],&b[i]);
        data.push_back(i+1);
    }

    for (size_t i = 0; i < n; i++)
    {
       shandom_ruffle(a[i]-1,b[i]-1,data,n);
       //printBuff(data,n);
    }
    printBuff(data,n);
    return true;
}
*/
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
