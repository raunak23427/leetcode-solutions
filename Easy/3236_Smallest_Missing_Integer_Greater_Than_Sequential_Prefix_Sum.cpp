/*
 * Problem: Smallest Missing Integer Greater Than Sequential Prefix Sum
 * Problem ID: 3236
 * Difficulty: Easy
 * Language: C++
 * Runtime: 3 ms
 * Memory: 23.1 MB
 * Synced From: LeetCode
 * Date: 2026-08-11
 */

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        // Find sum of longest sequential prefix
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }

        // Find smallest missing integer >= sum
        unordered_set<int> st(nums.begin(), nums.end());

        while (st.count(sum))
            sum++;

        return sum;
    }
};