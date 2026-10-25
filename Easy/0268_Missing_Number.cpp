/*
 * Problem: Missing Number
 * Problem ID: 268
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 21.8 MB
 * Synced From: LeetCode
 * Date: 2026-10-25
 */


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expected = n * (n + 1) / 2;
        int actual = 0;

        for (int num : nums) {
            actual += num;
        }

        return expected - actual;
    }
};
