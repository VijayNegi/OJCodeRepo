/*
Leetcode
problem-  Binary Tree Maximum Path Sum
Link - https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/532/week-5/3314/
tags -

*/
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
    int maxPathSum(TreeNode* root) {
        int Depth,Solution;
        if(!root)
            return 0;
        helperFunc(root,Depth,Solution);
        return Solution ;
    }
    
    void helperFunc(TreeNode* root,int &maxSum, int &currentSol)
    {
        
        int rSum=0,lSum=0,rSol=INT_MIN,lSol=INT_MIN;
        currentSol=0;
        if(root->left){
            helperFunc(root->left,lSum,lSol);
            currentSol+=lSum;
        }
        if(root->right){
            helperFunc(root->right,rSum,rSol);
            currentSol+=rSum;
        }
        
        maxSum = max(max(lSum,rSum) + root->val,root->val);
        
        currentSol += root->val;
        currentSol = max(max(max(lSol,rSol),currentSol ),maxSum);
        return;
        
    }
    
};