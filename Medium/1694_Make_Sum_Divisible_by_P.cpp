/*
 * Problem: Make Sum Divisible by P
 * Problem ID: 1694
 * Difficulty: Medium
 * Language: C++
 * Runtime: 67 ms
 * Memory: 87.7 MB
 * Synced From: LeetCode
 * Date: 2026-09-08
 */

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;

        for (int x : nums) {
            total += x;
        }

        int target = total % p;

        // Already divisible
        if (target == 0)
            return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        long long prefix = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];

            int current = prefix % p;

            int needed = (current - target + p) % p;

            if (mp.count(needed)) {
                ans = min(ans, i - mp[needed]);
            }

            // Store the latest index
            mp[current] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};