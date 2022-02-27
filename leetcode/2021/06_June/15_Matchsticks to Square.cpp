/*
Leetcode

problem- Matchsticks to Square

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/605/week-3-june-15th-june-21st/3780/

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
    bool findSum(map<int,int> &msmap,int sum)
    {
        if(sum==0)
            return true;
   
        auto it = msmap.rbegin();
        for (; it != msmap.rend(); ++it)
        {
            int n = it->first;
            if(n <= sum && msmap[n]>0)
            {
                --msmap[n];
                if(findSum(msmap,sum-n))
                    return true;
                ++msmap[n];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& ms) {
        
        if(ms.size()<4)
            return false;
        int sum=0;
        //int len[16] = {};
        map<int,int> msmap;
        for(const auto& m:ms)
        {
            sum+=m;
            ++msmap[m];
        }
        if(sum%4!=0)
            return false;
        
        int side = sum/4;
        
        for(int i=0;i<4;i++)
        {
            if(!findSum(msmap,side))
                return false;
        }

        return true;
    }
    bool solve(int index, vector<int> &nums, bitset<32> &visited, int target){
      if(target == 0){
        return true;
      }
      for(int i = index; i < (int)nums.size(); i++){
        if(!visited[i] and target - nums[i] >= 0){
             visited[i] = 1;
          if(solve(i, nums, visited, target - nums[i]))
              return true;
          visited[i] = 0;
        }
      }
    return false;
    }

    bool makesquare2(vector<int> &nums){
      int n = nums.size(), sum = 0;
      for(auto x : nums){
        sum += x;
      }
      if(sum % 4 != 0){
        return false;
      }
      bitset<32>visited;
      for(int i = 0; i < 32; i++){
          visited[i] = 0;
      }
      sort(nums.begin(),nums.end(),greater<int>());
        for(int i = 0; i < 3; i++){
            if(!solve(0, nums, visited, sum / 4))
                return false;
        }
     return true;
    }
};
