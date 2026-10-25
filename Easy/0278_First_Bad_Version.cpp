/*
 * Problem: First Bad Version
 * Problem ID: 278
 * Difficulty: Easy
 * Language: C++
 * Runtime: 1 ms
 * Memory: 8.1 MB
 * Synced From: LeetCode
 * Date: 2026-10-25
 */


class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
