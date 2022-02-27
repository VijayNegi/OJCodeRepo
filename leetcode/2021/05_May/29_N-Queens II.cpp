/*
Leetcode

problem- N-Queens II

Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/602/week-5-may-29th-may-31st/3760/

tags - Easy
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
    bool valid(vector<vector<int>>& board,int row,int col)
    {
        int n = board.size();
        //check col
        for(int r=0;r<row;++r)
        {
            if(board[r][col])
                return false;
        }
        //diag /
        for(int r=row-1,c=col+1; r>=0 && c<n; --r,++c)
        {
            if(board[r][c])
                return false;
        }
        //diag
        // int r=0;
        // int c=0;
        for(int r=row-1,c=col-1; r>=0 && c>=0; --r,--c)
        {
                if(board[r][c])
                    return false;
        }
        return true;
    }
    void nQueen(vector<vector<int>>& board,int row,int &result)
    {
        int n = board.size();
        for(int i=0;i<n;++i)
        {
            if(valid(board,row,i))
            {
                if(row==n-1)
                {
                    ++result;
                }
                else
                {
                    board[row][i] = 1;
                    nQueen(board,row+1,result);
                    board[row][i] = 0;
                }
            }
        }
    }
    vector<int> cols;
    vector<int> ldiag;
    vector<int> rdiag;
    
    void nQueenAlt(int row, int &result)
    {
        int n = cols.size();
        for(int i=0;i<n;++i)
        {
            if(!cols[i] && !ldiag[n+ row - i] && !rdiag[row+i])
            {
                if(row==n-1)
                {
                    ++result;
                }
                else
                {
                    cols[i] = ldiag[n+ row - i] = rdiag[row+i] = 1;
                    nQueenAlt(row+1,result);
                    cols[i] = ldiag[n+ row - i] = rdiag[row+i] = 0;
                }
            }
        }
    }
public:
    int totalNQueens(int n) {
        
        int result=0;
        
        cols = std::move(vector<int>(n,0));
        ldiag = std::move(vector<int>(2*n,0));
        rdiag = std::move(vector<int>(2*n,0));
        nQueenAlt(0,result);
        return result;
        
        
        //vector<vector<int>> board(n,vector<int>(n,0));
        //nQueen(board,0,result);
        //return result;
        
    }
};
