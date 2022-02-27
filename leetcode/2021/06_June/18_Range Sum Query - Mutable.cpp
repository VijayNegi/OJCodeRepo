/*
Leetcode

problem- Range Sum Query - Mutable

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/605/week-3-june-15th-june-21st/3783/

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

struct sumTree
{
    int sum;
    int l,r;
    sumTree *ltree,*rtree;
    sumTree(vector<int>& nums,int left,int right)
    {
        l= left;
        r = right;
        insert(nums,l,r);
    }
    void insert(vector<int>& nums,int left,int right)
    {
        if(left == right)
        {
            ltree = rtree = nullptr;
            sum = nums[left];
        }
        else
        {
            int mid = (left+right)/2;
            ltree = new sumTree(nums,left, mid);
            rtree = new sumTree(nums,mid+1,right);
            sum = ltree->sum + rtree->sum;
        }
    }
    void update(int index,int val)
    {
        if(l==r && index==l)
            sum = val;
        else
        {
            int mid = (l+r)/2;
            if(index>=l && index<=mid)
                ltree->update(index,val);
            else
                rtree->update(index,val);
            sum = ltree->sum + rtree->sum;
        }
        
    }
    int sumRange(int left,int right)
    {
        int result=0;
        if(l==left && r==right)
            result = sum;
        else
        {
            int mid = (l+r)/2;
            int ll = left;
            int lr = min(right,mid);
            if(ll<=lr)
                result = ltree->sumRange(ll,lr);
            int rl = max(left,mid+1);
            int rr = right;
            if(rl<=rr)
                result += rtree->sumRange(rl,rr);
        }
        return result;
    }
};
class NumArray {
    sumTree* root;
public:
    NumArray(vector<int>& nums) {
        root = new sumTree(nums,0,nums.size()-1);
    }
    
    void update(int index, int val) {
        root->update(index,val);
    }
    
    int sumRange(int left, int right) {
        return root->sumRange(left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
