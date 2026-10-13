/*
 * Problem: Unique Binary Search Trees
 * Problem ID: 96
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.1 MB
 * Synced From: LeetCode
 * Date: 2026-10-13
 */


class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};
