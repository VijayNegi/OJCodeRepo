/*
Leetcode

problem- Construct Binary Tree from Preorder and Inorder Traversal

Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/604/week-2-june-8th-june-14th/3772/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder,0,preorder.size()-1,inorder,0,preorder.size()-1);
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder,int pi,int pj, vector<int>& inorder,int ii,int ij)
    {
        if(pi>pj || ii>ij)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[pi]);
        int pos=0;
        
        for(int i=ii;i<=ij;i++)
        {
            if(inorder[i] == preorder[pi])
            {
                pos= i;
                break;
            }
        }
        int len = pos-ii;
        root->left =  buildTreeHelper(preorder, pi+1,     pi+len, inorder, ii,       ii+len-1);
        root->right = buildTreeHelper(preorder, pi+1+len, pj,     inorder, ii+1+len, ij);
        
        return root;
    }

};
