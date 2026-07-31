/*
 * Problem: Jump Game II
 * Problem ID: 45
 * Difficulty: Medium
 * Language: C++
 * Runtime: 2 ms
 * Memory: 20.6 MB
 * Synced From: LeetCode
 * Date: 2026-07-31
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {

            farthest = max(farthest, i + nums[i]);

            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};