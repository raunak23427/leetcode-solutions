/*
 * Problem: Stone Game VIII
 * Problem ID: 2002
 * Difficulty: Hard
 * Language: C++
 * Runtime: 107 ms
 * Memory: 87.1 MB
 * Synced From: LeetCode
 * Date: 2026-08-25
 */

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Prefix sum
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // Base case: only two stones remain
        int dp = stones[n - 1];

        // Calculate from right to left
        for (int i = n - 2; i >= 1; i--) {
            dp = max(dp, stones[i] - dp);
        }

        return dp;
    }
};