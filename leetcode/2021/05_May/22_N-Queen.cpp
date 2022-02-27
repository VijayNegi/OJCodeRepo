/*
Leetcode

problem- N-Queen

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3752/

tags - Hard, DP, Backtrack
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

class Solution {
    vector<vector<string>> result;
    int size;
    bool isSafe(vector<string>& board,int row, int col)
    {
        //1. check col
        for(int r=row-1;r>=0;r--)
        {
            if(board[r][col] =='Q')
                return false;
        }
        //2. check diag 1  '/'
        for(int r=row-1,c=col+1; r>=0 && c<board.size() ;r--,c++)
        {
            if(board[r][c] =='Q')
                return false;
        }
        
        //3. check diag 2  '\'
        for(int r=row-1,c=col-1; r>=0 && c>=0 ;r--,c--)
        {
            if(board[r][c] =='Q')
                return false;
        }
        return true;
    }
    void helper(vector<string>& board,int row)
    {
        if(row>board.size())
            return;
        //cout<<"row->"<<row<<endl;
        for(int col = 0;col< board.size();col++)
        {
            if(!isSafe(board,row,col))
                continue;
            if(row == board.size()-1)
            {
                board[row][col] = 'Q';
                result.push_back(board);
                board[row][col] = '.';
            }
            else
            {
                board[row][col] = 'Q';
                helper(board, row+1);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        size = n;
        vector<string> board(n,string(n,'.'));
        helper(board,0);
        return result;
    }
};
