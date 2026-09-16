/*
 * Problem: Length of Longest Subarray With at Most K Frequency
 * Problem ID: 3225
 * Difficulty: Medium
 * Language: C++
 * Runtime: 71 ms
 * Memory: 149.3 MB
 * Synced From: LeetCode
 * Date: 2026-09-16
 */


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int start=0;int end=0;int len=0;
        while(end<nums.size()){
            m[nums[end]]++;
            while(m[nums[end]]>k){
                m[nums[start]]--;
                start++;
            }
            len=max(len,end-start+1);
            end++;
        }
        return len;
    }
};