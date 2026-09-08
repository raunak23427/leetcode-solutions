/*
 * Problem: Count Commas in Range
 * Problem ID: 4245
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.5 MB
 * Synced From: LeetCode
 * Date: 2026-09-08
 */

class Solution {
public:
    long long countCommas(int n) {
        long long ans = 0;

        if (n >= 1000) {
            ans += n - 999;
        }

        if (n >= 1000000) {
            ans += (long long)(n - 999999) * 2;
        }

        return ans;
    }
};