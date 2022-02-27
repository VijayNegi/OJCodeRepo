/*
Leetcode

 problem-     Number of Longest Increasing Subsequence

Link - https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/563/week-5-october-29th-october-31st/3513/

tags -

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
    void printvec(vector<int>& vec,string name)
    {
        cout<< name<< " - ";
        for(auto a: vec)
        {
            cout<<a<<" ,";
        }
        cout<<endl;
    }
    
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> len(nums.size(),1);
        vector<int> count(nums.size(),1);
        //len[0]=1;
        //count[0]=1;
        int MaxLen =1;
        int Maxcount = 1;
        int preM=0;
        
        for(int i=1;i<nums.size();++i)
        {
            int lent=0;
            int countt=0;
            int j=i;
            while(--j>=0)
            {
                if(nums[i]>nums[j])
                {
                    if(len[i]<=len[j])
                    {
                        len[i] = len[j]+1;
                        count[i] = count[j];
                    }
                    else if (len[i] == len[j]+1)
                        count[i]+=count[j];
                }
 
            }
            if(len[i]==MaxLen)
                Maxcount+=count[i];
            else if(len[i]> MaxLen)
            {
                MaxLen = len[i];
                Maxcount = count[i];
                preM=i;
            }
                
        }
        //cout<<MaxLen<<" "<< Maxcount<<endl;
        //printvec(len, "len");
        //printvec(count, "cnt");
        return Maxcount;
    }
};
