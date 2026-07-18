/*
 * Problem: Find Greatest Common Divisor of Array
 * Problem ID: 2106
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 16.4 MB
 * Synced From: LeetCode
 * Date: 2026-07-18
 */

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxelement = INT_MIN;
        int minelement = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxelement) {
                maxelement = nums[i];
            }
            if(nums[i]<minelement){
                minelement=nums[i];
            }
        }
        return gcd(maxelement,minelement);
    }
};