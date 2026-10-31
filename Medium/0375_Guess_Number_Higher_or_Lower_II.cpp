/*
 * Problem: Guess Number Higher or Lower II
 * Problem ID: 375
 * Difficulty: Medium
 * Language: C++
 * Runtime: 90 ms
 * Memory: 8.1 MB
 * Synced From: LeetCode
 * Date: 2026-10-31
 */

class Solution {
private:
    int memo[201][201];

    int solve(int start, int end) {
        if (start >= end) return 0;
        if (memo[start][end] != 0) return memo[start][end];

        int minCost = INT_MAX;
        for (int x = start; x <= end; x++) {
            int cost = x + max(solve(start, x - 1), solve(x + 1, end));
            minCost = min(minCost, cost);
        }

        return memo[start][end] = minCost;
    }

public:
    int getMoneyAmount(int n) {
        memset(memo, 0, sizeof(memo));
        return solve(1, n);
    }
};