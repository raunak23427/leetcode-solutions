/*
 * Problem: Minimum Number of Pushes to Type Word I
 * Problem ID: 3275
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.4 MB
 * Synced From: LeetCode
 * Date: 2026-07-30
 */

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += i / 8 + 1;
        }

        return ans;
    }
};