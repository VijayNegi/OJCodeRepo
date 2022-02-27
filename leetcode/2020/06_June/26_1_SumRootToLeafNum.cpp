/*
Leetcode
 problem-   Sum Root to Leaf Numbers

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3372/
        
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
    int _sum;
    void helper(TreeNode* root,int num)
    {
        num=num*10;
        num += root->val;
        //cout<<"\nO-"<<num;
        if(root->left == NULL && root->right == NULL)
        {
            _sum += num;
            //cout<<"\nN-"<<num;
        }
        if(root->left != NULL)
        {
            helper(root->left,num);
        }
        if(root->right != NULL)
        {
            helper(root->right,num);
        }
        
        return;
    }
    int sumNumbers(TreeNode* root) {
        _sum=0;
        if(root != NULL)
            helper(root,0);
        return _sum;
    }
};
