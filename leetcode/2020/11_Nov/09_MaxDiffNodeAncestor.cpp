/*
Leetcode

 problem-     Maximum Difference Between Node and Ancestor

Link - https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3525/

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,int minval, int maxval,int& val)
    {
        if(!root)
            return;
        minval = min(minval,root->val);
        maxval = max(maxval,root->val);
        
        int mval = max(abs(root->val-minval),abs(root->val-maxval));
        val = max(mval,val);
        
        dfs(root->left,minval,maxval,val);
        dfs(root->right,minval,maxval,val);
    }
    int maxAncestorDiff(TreeNode* root) {
        
        int val=0;
        int minval = INT_MAX;
        int maxval = INT_MIN;
        dfs(root,minval,maxval,val);
        return val;
    }
};
