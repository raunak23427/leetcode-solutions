/*
 * Problem: Sum Game
 * Problem ID: 2039
 * Difficulty: Medium
 * Language: C++
 * Runtime: 3 ms
 * Memory: 14 MB
 * Synced From: LeetCode
 * Date: 2026-08-23
 */

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int sum = 0;
        int q = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                q++;
            else
                sum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                q--;
            else
                sum -= num[i] - '0';
        }

        return 2 * sum != -9 * q;
    }
};