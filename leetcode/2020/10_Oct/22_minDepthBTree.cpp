/*
Leetcode

 problem-     Minimum Depth of Binary Tree

Link - https://leetcode.com/explore/featured/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3504/

tags - DFS, BFS

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
    int minDepth(TreeNode* root) {
        //try BFS
        if(root==NULL)
            return 0;
        list<TreeNode*> queue;
        int ChildNodes;
        int CurrNodes;
        int depth;
        queue.push_back(root);
        CurrNodes = 1;
        ChildNodes = 0;
        depth=1;
        while(!queue.empty())
        {
            TreeNode* node = queue.front();
            queue.pop_front();
            --CurrNodes;
            if(!node->left && !node->right)
                break;
            if(node->left)
            {
                queue.push_back(node->left);
                ++ChildNodes;
            }
            if(node->right)
            {
                queue.push_back(node->right);
                ++ChildNodes;
            }
            
            if(CurrNodes==0)
            {
                CurrNodes = ChildNodes;
                ChildNodes = 0;
                depth++;
            }
        }
        
        return depth;
    }
};
