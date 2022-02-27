/*
Leetcode

 problem-     Binary Tree Tilt

Link - https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3524/

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
    int result;
    int inorder(TreeNode* root)
    {
        int lef=0;
        int rit=0;
        if(root->left)
            lef= inorder(root->left);
        if(root->right)
            rit = inorder(root->right);
        
        result+= (lef>rit)? lef-rit:rit-lef;
        
        return root->val+lef+rit;
        
        
    }
    int findTilt(TreeNode* root) {
        
        if(!root)
            return 0;
        result=0;
        inorder(root);
        return result;
    }
};
