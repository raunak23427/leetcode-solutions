/*
 * Problem: Predict the Winner
 * Problem ID: 486
 * Difficulty: Medium
 * Language: C++
 * Runtime: 2 ms
 * Memory: 10.3 MB
 * Synced From: LeetCode
 * Date: 2026-08-01
 */

class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == j)
            return nums[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        int takeLeft = nums[i] - solve(i + 1, j, nums, dp);
        int takeRight = nums[j] - solve(i, j - 1, nums, dp);

        return dp[i][j] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n - 1, nums, dp) >= 0;
    }
};