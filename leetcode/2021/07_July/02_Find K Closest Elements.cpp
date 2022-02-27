/*
Leetcode

problem- Find K Closest Elements

Link - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3800/

tags - Medium, Binary Search
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

//https://leetcode.com/problems/find-k-closest-elements/discuss/106426/JavaC%2B%2BPython-Binary-Search-O(log(N-K)-%2B-K)
//basically you are finding a point from which a[i] and a[i+k] has same distance from x through binary search
class Solution {
public:
    vector<int> findClosestElements1(vector<int>& arr, int k, int x) {
        
        int l=0,r=k-1;
        int maxdis = max (abs(arr[l]-x), abs(arr[r]-x));
        for(int i=k;i<arr.size();++i)
        {
            if(arr[i]-x>=maxdis)
                break;
            
            if(abs(arr[i]-x) < maxdis)
            {
                r=i;
                l=i-k+1;
                maxdis = max(abs(arr[l]-x), abs(arr[r]-x));
            }
           
        }
        vector<int> result(begin(arr)+l,begin(arr)+r+1);
        return result;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left=0,right=arr.size()-k;
        while(left<right)
        {
            int mid = (left+right)/2;
            if(x-arr[mid] > arr[mid+k]-x)
                left=mid+1;
            else
                right = mid;
        }
        return vector<int>(arr.begin()+left,arr.begin()+left+k);
    }
};
