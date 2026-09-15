/*
 * Problem: Subarray Product Less Than K
 * Problem ID: 713
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 45 MB
 * Synced From: LeetCode
 * Date: 2026-09-15
 */

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }
        int start =0;
        int end=0;
        int product=1;int count=0;
        while(end<nums.size() && start<=end){
            product*=nums[end];
            while(product>=k){
                product /= nums[start];
                start++;
            }
            count+=end-start+1;
            end++;
        }
        return count;
    }
};