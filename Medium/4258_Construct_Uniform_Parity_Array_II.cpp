/*
 * Problem: Construct Uniform Parity Array II
 * Problem ID: 4258
 * Difficulty: Medium
 * Language: C++
 * Runtime: 16 ms
 * Memory: 166 MB
 * Synced From: LeetCode
 * Date: 2026-09-03
 */

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int mn = INT_MAX;
        
        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 != 0){
                mn = min(mn, nums1[i]);
            }
        }
        if(mn == INT_MAX)
            return true;
        
       
        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 == 0){
                if(mn >= nums1[i])
                    return false;
            }
        }
        
        return true;
    }
};