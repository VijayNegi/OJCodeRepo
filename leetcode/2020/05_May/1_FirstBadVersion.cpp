/*
Leetcode
problem-  First Bad Version
Link - https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3316/
tags -

*/


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n;
        int bad =0;
        int mid;
        while(end>=start){
            // if(start==end)
            //     return start;
            mid = start+ (end-start+1)/2; // avoid overflow
            if(isBadVersion(mid)){
                bad = mid;
                end = mid-1;
            }
            else{
                start = mid + 1;
            }
        }
        return bad;
    }
};