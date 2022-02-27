/*
Leetcode
problem-   Maximal Square
Link - https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3312/
        
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
#include <deque>
typedef unsigned int uint;        //u
typedef unsigned long long ulong; //use %I64d for read/write
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)
using namespace std;


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int area =0;
        if(matrix.size()==0)
            return area;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> memC(cols,0);
        //vector<int> memR(rows,0);
        unordered_map<int,int> _map;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if(matrix[i][j]=='1')
                {
                    //mem update
                    memC[j]++;
                    if(area==0)
                        area=1;
                    //auto search = _map.find(memC[j]); // find it was somewhere
                    //if (search == _map.end()) {
                        // search all pints greater then memC[j] in map remove them
                        int minr = INT_MAX;
                        
                        for(auto it = _map.begin(); it != _map.end(); ) {
                            if(it->first >= memC[j]){
                                minr = min(minr, it->second);
                                it = _map.erase(it);
                            }
                            else
                                ++it;
                        }
                        // for(auto m : _map){
                        //     if(m.first > memC[j])
                        //         minr = min(minr, m.second);
                        //     _map.erase(m.first);
                        // } 
                        _map[memC[j]] = min(j,minr); // start point
                    //}
                      // check current area for all entries
                    //   int r = j - _map[memC[j]]+1;
                    //         int c = memC[j];
                    //         int a = min(r,c) * min(r,c);
                            
                    //         if(a>area){
                    //             area = a;
                    //             cout<<endl<<"i->"<<i<<" j->"<<j<<" r->"<<r<<" c->"<<c<<" a->"<<a;
                    //         }
                      for(auto m : _map){
                            int r = j - m.second+1;
                            int c = m.first;
                            int a = min(r,c) * min(r,c);
                            
                            if(a>area){
                                area = a;
                                cout<<endl<<"i->"<<i<<" j->"<<j<<" r->"<<r<<" c->"<<c<<" a->"<<a;
                            }
                      }
                    
                    
                }
                else
                {
                    //reset mem
                    memC[j]=0;
                    _map.clear();
                }
                
            }
            _map.clear();
        }
        return area;
        
    }
    int maximalSquare2(vector<vector<char>>& matrix) {
        int area = 0;
        if(matrix.size()==0)
            return area;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> vec(2,vector(cols,0));
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if(i==0 || j==0){
                    vec[1][j] = matrix[i][j]-'0';
                    area = max(area,vec[1][j]);
                    
                }
                else{
                    if(matrix[i][j]-'0'){
                        int minMat = min(min(vec[0][j-1],vec[0][j]),vec[1][j-1]);
                        vec[1][j]=minMat+1;
                        area = max(area,vec[1][j]);
                    }
                    else{
                        vec[1][j]=0;
                    }
                }
            }
            vec[0].swap(vec[1]);
        }
        return area*area;
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
    // vector<vector<char>> myVecChar = {{'1','1'},
    //                                     {'1','1'}};
    //  vector<vector<char>> myVecChar = {{'1','0','1','0'},
    //                                     {'1','0','1','1'},
    //                                     {'1','0','1','1'},
    //                                     {'1','1','1','1'}} ;  

    // vector<vector<char>> myVecChar = {{'0','0','0','1'},
    //                                     {'1','1','0','1'},
    //                                     {'1','1','1','1'},
    //                                     {'0','1','1','1'},
    //                                     {'0','1','1','1'}} ;     
    //   vector<vector<char>> myVecChar = {{'0','0','0','1','0','1','1','1'},
    //                                     {'0','1','1','0','0','1','0','1'},
    //                                     {'1','0','1','1','1','1','0','1'},
    //                                     {'0','0','0','1','0','0','0','0'},
    //                                     {'0','0','1','0','0','0','1','0'},
    //                                     {'1','1','1','0','0','1','1','1'},
    //                                     {'1','0','0','1','1','0','0','1'},
    //                                     {'0','1','0','0','1','1','0','0'},
    //                                     {'1','0','0','1','0','0','0','0'}};                     
                                      
    //vector<int> myVec = {2,3,1,1,4};
    // string str = "((()))*";
    auto ans = obj->maximalSquare2(myVecChar);
     cout << "\n ans -> " << ans;
    
  
    return 0;
}