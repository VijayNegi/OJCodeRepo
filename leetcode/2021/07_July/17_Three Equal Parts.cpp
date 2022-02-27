/*
Leetcode

problem- Three Equal Parts

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3817/

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

class Solution {
public:
    vector<int> threeEqualParts1(vector<int>& arr) {
        int ones =0;
        int n = arr.size();
        for(auto& i:arr)
            if(i==1) ++ones;
        vector<int> result(2,-1);
        if(ones%3!=0)
            return result;
        if(ones==0)
            return {0,n-1};
        
        int trailingzero = 0;
        for(int i=n-1; i>=0 && arr[i]==0;++i)
            ++trailingzero;
        
        // find position of ones/3;
        int t = ones/3;
        
        //int boundries[2];
        //int b=0
        vector<int> boundries;
        int o = 0;
        
        
        //for(int i=0;i<n;++i)
        int i=0;
        while(i<n)
        {
          
            if(arr[i]==1)
                ++o;
            if(o==t)
            {
                int z = trailingzero;
                while(z > 0 && arr[i]==0)
                    --z,++i;
                if(z>0)
                    return result;
                if(boundries.size()==0)
                    boundries.push_back(i);
                else
                    boundries.push_back(i+1);
                if(boundries.size()==2)
                    break;
                o=0;
            }
            ++i;
        }
        int l=boundries[0],r=boundries[1]-1;
        //o=t;
        while(l>=0 && r> boundries[0])
        {
            if(arr[l--]!=arr[r--])
                return result;
        }
        
        l=boundries[0],r=n-1;
        //o=t;
        while(l>=0 && r>= boundries[1])
        {
            if(arr[l--]!=arr[r--])
                return result;
        }
            
        return boundries;
    }
//https://leetcode.com/problems/three-equal-parts/discuss/183922/C%2B%2B-O(n)-time-O(1)-space-12-ms-with-explanation-and-comments
    vector<int> threeEqualParts(vector<int>& A) {
        int n = A.size();
        
        int Ones = accumulate(A.begin(), A.end(), 0);
        
        if (Ones == 0) return {0, n - 1};
        if (Ones % 3 != 0) return {-1, -1};

        int OneThird = Ones/3;
        int p[3];
        int count = 0;
        for (int i = 0; i < n; i++) {
            if(A[i] == 1) {
                if(count % OneThird == 0) {
                    p[count/OneThird] = i;
                }
                count++;
            }
        }
        
        while (p[2] != n) {
            if (A[p[0]] != A[p[1]] || A[p[1]] != A[p[2]])
                return {-1,-1};
            p[0]++; p[1]++; p[2]++;
        }
        
        return {p[0]-1, p[1]};
    }

};
