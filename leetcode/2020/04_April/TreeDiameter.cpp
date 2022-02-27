/*
Leetcode
problem-  Diameter of Binary Tree
Link - https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/529/week-2/3293/
tags -

*/
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
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int Depth,Solution;
        if(!root)
            return 0;
        helperFunc(root,Depth,Solution);
        return Solution -1;
    }
    
    void helperFunc(TreeNode* root,int &maxDepth, int &currentSol)
    {
        if(!root)
        {
            maxDepth=0;currentSol=0;
            return;
        }
        int rDepth,lDepth,rSol,lSol;
        helperFunc(root->left,lDepth,lSol);
        helperFunc(root->right,rDepth,rSol);
        
        maxDepth = max(lDepth,rDepth)+ 1;
        currentSol = lDepth + rDepth + 1;
        currentSol = max(max(lSol,rSol),currentSol );
        return;
        
    }
    
};