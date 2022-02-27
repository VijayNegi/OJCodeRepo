/*
Leetcode

problem- Minimum Number of Refueling Stops

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/604/week-2-june-8th-june-14th/3776/

tags - Hard
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

typedef pair<int,int> pii;
typedef long long ll;
class Solution {
public:
    int minRefuelStops1(int target, int startFuel, vector<vector<int>>& ss) {
        if(target<=startFuel)
            return 0;
        int stops = ss.size();
        vector<ll> dp(stops+1,-1);
        int result = INT_MAX;
        dp[0] = startFuel;
        for(int s=0;s<stops;++s )
        {
            //cout<<"station="<<s<<endl;
            for(int i=s;i>=0;--i)
            {
                
                //cout<<"dp["<<i<<"]="<<dp[i]<<endl;
                if(dp[i]<0)
                    break;
                if(dp[i]>= ss[s][0]) // can reach this station
                {
                    dp[i+1] = max(dp[i] + ss[s][1], dp[i+1]); // update max range;
                    if(dp[i+1]>=target)
                        result = min(result, i+1);
                    //cout<<s+1<<"="<<dp[s+1]<<endl;
                }
            }
        }
        
        // for(int i=0;i<stops;++i)
        // {
        //     if(dp[i]<0)
        //         break;
        //     //cout<<i<<"="<<dp[i]<<endl;
        // }
        return result>stops? -1: result;
    }
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
            priority_queue<int> q;
        int i=0,res=0,n=stations.size();
        while(startFuel<target) {
            while(i<n && stations[i][0]<=startFuel)
                q.push(stations[i++][1]);
            if(q.empty())   return -1;
            startFuel+=q.top();
            q.pop();
            res++;
        }
        return res;
    }
};
