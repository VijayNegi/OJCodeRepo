/*
Leetcode

problem- Candy

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3793/

tags - Two way traversal
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <utility>
#include <vector>
#include <deque>
#include <map>
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int result = 1;
        int start = 0;
        int n = ratings.size();
        bool up = true;
        int peak = 0;
        int count=1;
        for(int i=1;i<n;++i)
        {
            if(ratings[i]>ratings[i-1])
            {
                if(!up)
                {
                    //cout<<" sub="<<min(peak,count) - 1 <<endl;
                    result -= min(peak,count) -1 ;
                    count=1;
                    up = true;
                    peak = 0;
                }
                ++count;
                //cout<<" add="<<count<<endl;
                result +=count;
            }
            else if(ratings[i]<ratings[i-1])
            {
                if(up)
                {
                    peak = count;
                    count = 1;
                    up = false;
                }
                ++count;
                //cout<<" add="<<count<<endl;
                result +=count;
            }
            else
            {
                if(!up)
                {
                    //cout<<" sub="<<min(peak,count) -1<<endl;
                    result -= min(peak,count) -1;
                }
                count =1;
                //cout<<" add="<<count<<endl;
                result +=count;
                up = true;
                peak = 0;
            }
        }
        if(!up)
        {
            //cout<<" sub="<<min(peak,count)-1<<endl;
            result -= min(peak,count) -1;
        }
        return result;
    }
};
