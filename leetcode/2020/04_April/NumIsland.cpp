/*
Leetcode
problem-   Number of Islands
Link - https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3302/
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

class Solution
{
public:
    bool getNextElem(vector<vector<char>> &grid, pair<int, int> &island)
    {
         int i = 0, j = 0;
        int rows = grid.size();
        int cols = 0;
        if(rows>0 && !grid[0].empty())
             cols = grid[0].size();
        //find next elem in graph
        for (i=0; i < rows; i++)
        {
            for (j=0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {
                    island = make_pair(i, j);
                    return true;
                }
            }
            j=0;
        }
        return false;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        vector<pair<int, int>> queue;
        int numOfIslands = 0;
        // int i = 0, j = 0;
        int rows = grid.size();
        int cols = 0;
        if(rows>0 && !grid[0].empty())
             cols = grid[0].size();
        pair<int, int> nextIsland, tempIsland;
        //get next land
        //traverse that land
        while (getNextElem(grid, nextIsland))
        {
            //check surrounding places and mark this visited

            queue.push_back(nextIsland);
            // mark as visited
            grid[nextIsland.first][nextIsland.second] = '0';
            numOfIslands++;
            while (!queue.empty())
            {
                tempIsland = queue.back();
                queue.pop_back();
                int i = tempIsland.first;
                int j = tempIsland.second;
                //uppder
                
                if ((i - 1) >= 0)
                {
                    if (grid[i - 1][j] == '1'){
                        grid[i - 1][j] = '0';
                        queue.push_back(make_pair(i - 1, j));
                    }
                }
                //lower
                if ((i + 1) < rows)
                {
                    if (grid[i + 1][j] == '1'){
                        grid[i + 1][j] = '0';
                        queue.push_back(make_pair(i + 1, j));
                    }
                }
                //left
                if ((j - 1) >= 0)
                {
                    if (grid[i][j - 1] == '1'){
                        grid[i][j - 1] = '0';
                        queue.push_back(make_pair(i, j - 1));
                    }
                }
                //right
                if ((j + 1) < cols)
                {
                    if (grid[i][j + 1] == '1'){
                        grid[i][j + 1] = '0';
                        queue.push_back(make_pair(i, j + 1));
                    }
                }
            }
        }
        return numOfIslands;
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
    vector<vector<char>> myVec = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    string str = "((()))*";
    auto ans = obj->numIslands(myVec);
    cout << "\n ans -> " << ans;

    return 0;
}