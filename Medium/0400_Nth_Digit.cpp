/*
 * Problem: Nth Digit
 * Problem ID: 400
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 7.7 MB
 * Synced From: LeetCode
 * Date: 2026-10-31
 */

class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1;
        long long count = 9;
        long long start = 1;
        
        while (n > len * count) {
            n -= len * count;
            len++;
            count *= 10;
            start *= 10;
        }
        
        start += (n - 1) / len;
        string s = to_string(start);
        return s[(n - 1) % len] - '0';
    }
};
