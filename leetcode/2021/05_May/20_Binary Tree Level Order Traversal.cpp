/*
Leetcode

problem- Binary Tree Level Order Traversal

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3749/

tags - Tree
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr)
            return result;
        deque<TreeNode*> q;
        q.push_back(root);
        int level=0;
        int count = 1;
        int childcount = 0;
        while(count>0)
        {
            TreeNode* node = q.front();
            q.pop_front();
            if(result.size()<level+1)
                result.push_back({node->val});
            else
                result[level].push_back(node->val);
            if(node->left)
            {
                //childcount++;
                q.push_back(node->left);
            }
            if(node->right)
            {
                //childcount++;
                q.push_back(node->right);
            }
            if(count==1)
            {
                count = q.size(); //childcount;
                //childcount=0;
                ++level;
                
            }
            else
                count--;
             
        }
        return result;
    }
};
