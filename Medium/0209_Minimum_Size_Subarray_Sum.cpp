/*
 * Problem: Minimum Size Subarray Sum
 * Problem ID: 209
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 42 MB
 * Synced From: LeetCode
 * Date: 2026-09-16
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0;int end=0;int total=INT_MAX;
        int prefixsum=0;
        while(end<nums.size()){
            prefixsum+=nums[end];
            while(prefixsum>=target){
                total=min(total,end-start+1);
                prefixsum-=nums[start++];
                
            }
        end++;
        }
        if(total==INT_MAX){
            return 0;
        }
        return total;
    }
};