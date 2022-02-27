/*
Leetcode
problem-   Cousins in Binary Tree
Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/
        
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
#include <map>
#include <list>
#include <utility>
#include <deque>
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
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
     deque<TreeNode*> que;
     int level, currentlevelNodes,NextLevelNodes;
     level=currentlevelNodes=NextLevelNodes=0;
     if (root==NULL)
        return false;
     que.push_back(root);
     level=0;
     currentlevelNodes = 1;
     TreeNode* temp = NULL;
     bool foundX(false),foundY(false);
     while (!que.empty())
     {
         temp = que.front();
         que.pop_front();
         currentlevelNodes--;
        if(foundX || foundY)
        {
            if(temp->left)
            {
                if(temp->left->val == x )
                    foundX=true;
                if(temp->left->val == y )
                    foundY=true;
            }
            if(temp->right)
            {
                if(temp->right->val == x )
                    foundX=true;
                if(temp->right->val == y )
                    foundY=true;
            }
            if(foundX & foundY)
                return true;
        }
        else
        {
             if(temp->left)
            {
                if(temp->left->val == x )
                    foundX=true;
                if(temp->left->val == y )
                    foundY=true;
            }
            if(temp->right)
            {
                if(temp->right->val == x )
                    foundX=true;
                if(temp->right->val == y )
                    foundY=true;
            }
            if(foundX & foundY)
                return false;
        }
        

        if (temp->left)
        {
            que.push_back(temp->left);
            NextLevelNodes++;
        }
        if (temp->right)
        {
            que.push_back(temp->right);
            NextLevelNodes++;
        }

         if(currentlevelNodes==0)
         {
            currentlevelNodes = NextLevelNodes;
            NextLevelNodes = 0;
            if(foundX || foundY)
                return false;
         }
     }
     
    return false;

    }
    bool isCousins2(TreeNode* root, int x, int y) {
     deque<TreeNode*> que;
     int level, currentlevelNodes,NextLevelNodes;
     level=currentlevelNodes=NextLevelNodes=0;
     if (root==NULL)
        return false;
     que.push_back(root);
     level=0;
     currentlevelNodes = 1;
     TreeNode* temp = NULL;
     TreeNode* temp1 = NULL;
     bool foundX(false),foundY(false);
     while (!que.empty())
     {
         if(level==0)
         {
            temp = que.front();
            que.pop_front();
            currentlevelNodes--;
            que.push_back(temp->left);
            que.push_back(temp->right);
            NextLevelNodes+=2;
         }
         else
         {
            temp = que.front();
            que.pop_front();
            temp1 = que.front();
            que.pop_front();
            currentlevelNodes-=2;

            if(temp && temp1)
            {
                if(temp->val == x && temp1->val== y)
                    return false;
                if(temp->val == y && temp1->val== x)
                    return false;
            }
            if(temp)
            {   
                if (temp->val == x )
                    foundX = true;
                else if(temp->val== y)
                    foundY = true;
                que.push_back(temp->left);
                que.push_back(temp->right);
                NextLevelNodes+=2;
            }
            if(temp1)
            {   
                if (temp1->val == x )
                    foundX = true;
                else if(temp1->val== y)
                    foundY = true;
                que.push_back(temp1->left);
                que.push_back(temp1->right);
                NextLevelNodes+=2;
            }
             
         }
         if(foundX && foundY)
            return true;

         if(currentlevelNodes==0)
         {
            currentlevelNodes = NextLevelNodes;
            NextLevelNodes = 0;
            level++;
            if(foundX || foundY)
                return false;
         }
     }
     
    return false;

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
    vector<vector<int>> myVec = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    vector<vector<char>> myVecChar = {{'1','0','1','0','0'},
                                        {'1','0','1','1','1'},
                                        {'1','1','1','1','1'},
                                        {'1','0','0','1','0'}};
                   
                                      
    //vector<int> myVec = {2,3,1,1,4};
    // string str = "((()))*";
    map<vector<int>,int> testCases{ {{1, 3, 1},1},
                            {{1, 3, 3},3},
                            {{1, 3, 3,1,3},3}
                        
                                            };

    for(auto test:testCases)
    {
        //vector<int>& cvec = const_cast<vector<int>&>(test.first);
        TreeNode* root=NULL;
        auto ans = obj->isCousins( root, 3, 4) ;

        cout << "\n ans -> " << ans << " | expected->"<< test.second;
    }
    
    
  
    return 0;
}