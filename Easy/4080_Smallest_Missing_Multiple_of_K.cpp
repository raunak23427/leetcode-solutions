/*
 * Problem: Smallest Missing Multiple of K
 * Problem ID: 4080
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 25.1 MB
 * Synced From: LeetCode
 * Date: 2026-08-26
 */

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());

        int multiple = k;

        while (s.count(multiple)) {
            multiple += k;
        }

        return multiple;
    }
};