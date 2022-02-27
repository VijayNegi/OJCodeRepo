/*
Leetcode

problem- Binary Tree Cameras

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3745/

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
    int cam;
    int helper(TreeNode* root)
    {
        int depth=0;
        int depthR=1;
        int depthL=1;
        if(root->right)
            depthR = helper(root->right);
        if(root->left)
            depthL = helper(root->left);
        depth = max(depthL, depthR);
        if(depth >= 2)
        {
            cam++;
            return 0; // reset depth to 0;
        }
        depth = min(depthL,depthR);
        if(depth<=1) // 0
            ++depth;
        //cout<<"l-"<<depthL<<" r-"<<depthR<<endl;
            
        return depth;
    }
public:
    int minCameraCover(TreeNode* root) {
        cam=0;
        int depth = helper(root);
        if(depth>1)
            cam++;
            
        return cam;
    }
};
