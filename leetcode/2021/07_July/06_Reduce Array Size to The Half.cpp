/*
Leetcode

problem- Reduce Array Size to The Half

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3804/

tags - Medium
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
    int minSetSize1(vector<int>& arr) {
        unordered_map<int,int> cnt;
        int len = arr.size();
        for(const auto& n:arr)
            cnt[n]++;
        vector<int> v;
        for(const auto it: cnt)
        {
            v.push_back(it.second);
        }
        
        sort(v.begin(),v.end(),greater<int>());
        for_each(v.begin(),v.end(),[](int i){cout<<i<<" ";});
        int result = 0;
        int sum=0;
        while(result<v.size())
        {
            
            sum += v[result++];
            if(sum >= len/2)
                break;
        }
        
        return result ;
    }
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int result=0;
        int max_element = arr[0];
        int max_count = 0;
        for(const auto& n: arr)
        {
            if(max_element==n)
            {
                max_count++;
            }
            else
            {
                if(max_count)
                    --max_count;
                else
                {
                    max_element = n;
                    ++max_count;
                    ++result;
                }
            }
            
        }
        return result;
    }
};
