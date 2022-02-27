/*
Leetcode
problem-   Construct Binary Search Tree from Preorder Traversal
Link - https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3305/
        https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;

 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void PrintTreeNode(TreeNode* root){
    if(root==NULL)
        return;
    cout<<root->val<<" ";
    PrintTreeNode(root->left);
    PrintTreeNode(root->right);
} 

class Solution
{
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=NULL;

        int len = preorder.size();
        for (int i = 0; i < len; i++)
        {
            TreeNode* temp = new TreeNode(preorder[i]);
            if(root==NULL)
                root = temp;
            else{
                TreeNode* currNode = root;
                while(true){
                    if(currNode->val< preorder[i])
                    {
                        if(currNode->right==NULL){
                            currNode->right=temp;
                            break;
                        }
                        else
                            currNode = currNode->right;
                    }
                    else{
                        if(currNode->left==NULL){
                            currNode->left=temp;
                            break;
                        }
                        else
                            currNode = currNode->left;
                    }
                }
            }
        }
        return root;
        
    }
};

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    // disable buffering on stdout completely
    setbuf(stdout, NULL);
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);

#endif
    Solution *obj = new Solution();
    //vector<vector<int>> myVec = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<int> myVec = {8,5,1,7,10,12};
    string str = "((()))*";
    auto ans = obj->bstFromPreorder(myVec);
    //cout << "\n ans -> " << ans;
    //print BST
    cout<<"\n Tree -> ";
    PrintTreeNode(ans);
    return 0;
}