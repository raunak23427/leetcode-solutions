/*
 * Problem: Subarray Sum Equals K
 * Problem ID: 560
 * Difficulty: Medium
 * Language: C++
 * Runtime: 43 ms
 * Memory: 45.6 MB
 * Synced From: LeetCode
 * Date: 2026-09-11
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0, ans = 0;

        for (int x : nums) {
            sum += x;

            if (mp.find(sum - k) != mp.end())
                ans += mp[sum - k];

            mp[sum]++;
        }

        return ans;
    }
};