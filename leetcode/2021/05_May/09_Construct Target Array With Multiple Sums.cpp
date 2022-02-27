/*
Leetcode

problem- Construct Target Array With Multiple Sums

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3737/

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

typedef long long ll;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        bool result = true;
        int len = target.size();
        if(len==1 && target[0]!=1)
            return false;
            
        make_heap(target.begin(),target.end());
        ll sum = 0;
        sum = std::accumulate(target.begin(), target.end(), sum);
        while(true)
        {
            
            //cout<<"max-"<<target.front()<<endl;
            sum -= target.front();
            if(target.front()==1 || sum==1)
                break;
            
            if(target.front()<=sum)
            {
                result = false;
                break;
            }
            
            int diff = target.front() % sum; // new element
            sum += diff;
            //cout<<"new ele-"<<diff<<" sum-"<<sum<<endl;
            if(diff<1)
            {
                result = false;
                break;
            }
            pop_heap(target.begin(),target.end());
            target[len-1] = diff;
            push_heap(target.begin(),target.end());
        }
        return result;
    }
};
