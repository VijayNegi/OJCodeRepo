/*
Leetcode

problem- Lowest Common Ancestor of a Binary Tree

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/607/week-5-june-29th-june-30th/3797/

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
    TreeNode* helper(TreeNode* root,TreeNode* p, TreeNode* q)
    {
        if(root==nullptr)
            return nullptr;
        
        if( root->val == p->val || root->val == q->val )
            return root;
        
        TreeNode* lhs = helper(root->left, p,q);
        TreeNode* rhs = helper(root->right, p,q);
        
        if(lhs && rhs)
            return root;
        
        return lhs?lhs:rhs;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
        
    }
};
