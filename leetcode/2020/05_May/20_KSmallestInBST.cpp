/*
Leetcode
problem-    Kth Smallest Element in a BST
Link - https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3335/
        
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
#include <map>
#include <list>
#include <utility>
#include <deque>
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
    bool helper(TreeNode* root,int k,int& count,int& ans)
    {
        if(root==NULL)
            return false;
        
        if(root->left != NULL)
        {
            if(helper(root->left,k,count,ans))
                return true;
        }
        
        count++; // visit current node
        if(count==k)
        {
            ans= root->val;
            return true;
        }
        
        if(root->right != NULL)
            return helper(root->right,k,count,ans);
        
        return false;
            
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0,ans=0;
        helper(root,k,count,ans);
        return ans;
    }
};