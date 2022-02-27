/*
Leetcode

problem- Maximum Points You Can Obtain from Cards

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3739/

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
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        int sum=0;
        sum = accumulate(cardPoints.begin(),cardPoints.begin()+k,sum);
        
        if(len<=k)
            return sum;
        int ans=sum;
        for(int i=0;i<k;i++)
        {
            sum-=cardPoints[k-i-1];
            sum+=cardPoints[len-i-1];
            ans = max(ans,sum);
        }
        return ans;
    }
};
