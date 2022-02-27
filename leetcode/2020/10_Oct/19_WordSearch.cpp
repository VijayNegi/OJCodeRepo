/*
Leetcode

 problem-     79. Word Search

Link - https://leetcode.com/problems/word-search/

tags - dfs

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
    int dirx[4] = {-1,0,1,0};
    int diry[4] = {0,-1,0,1};
    int _boardWidth;
    int _boardHeight;
    int sti,stj;
    
public:
    bool find(vector<vector<char>>& board,char str, int& x, int& y)
    {
        while(sti < _boardHeight)
        {
            x=sti;y=stj;
            
            ++stj;
            if(stj==_boardWidth)
            {
                sti++;
                stj=0;
            }
            if(board[x][y]== str)
                 return true;
        }
        
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int wId,vector<vector<int>>& visited , int x , int  y )
    {
        bool result(false);
        int width(0),height(0);
        height = board.size();
        width = board[0].size();
        
        
        for(int i=0;i<4;i++)
        {
            int xi = x+dirx[i];
            int yi = y+diry[i];
            if(xi>=0 && xi<height && yi>=0 && yi<width)
            {
                
                if(!visited[xi][yi] && word[wId] == board[xi][yi])
                {
                    //cout<<" match- "<< yi<<" "<<xi<<endl;
                    visited[xi][yi] = 1;
                    if(wId == (word.size()-1))
                        return true;
                    result = dfs(board,word,wId+1,visited, xi,yi);
                    if(result)
                        return true;
                    visited[xi][yi] = 0;
                }
            }
            
        }
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        bool result(false);
        _boardHeight = board.size();
        if(_boardHeight)
            _boardWidth = board[0].size();
        //if(_boardWidth == 0 || _boardHeight == 0)
        //    return result;
        
        int length = word.size();
        //if(length==0)
        //    return false;
        
        sti=stj=0;
        int x(0),y(0);
        vector<vector<int>> visited(_boardHeight, vector<int>(_boardWidth,0));
        while(find(board, word[0],x,y))
        {
            if(length==1)
                return true;
            visited[x][y]=1;
            result = dfs(board,word,1,visited, x,y );
            visited[x][y]=0;
           
            if(result)
                break;
        }
       
        return result;
    }
};
