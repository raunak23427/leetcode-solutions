/*
 * Problem: Find the Duplicate Number
 * Problem ID: 287
 * Difficulty: Medium
 * Language: C++
 * Runtime: 2 ms
 * Memory: 65.1 MB
 * Synced From: LeetCode
 * Date: 2026-10-25
 */


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
