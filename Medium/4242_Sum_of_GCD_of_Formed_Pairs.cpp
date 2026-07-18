/*
 * Problem: Sum of GCD of Formed Pairs
 * Problem ID: 4242
 * Difficulty: Medium
 * Language: C++
 * Runtime: 81 ms
 * Memory: 155.6 MB
 * Synced From: LeetCode
 * Date: 2026-07-18
 */

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefix(nums.size());
        int mx = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mx) {
                mx = nums[i];
            }
            prefix[i] = gcd(nums[i], mx);
        }
        sort(prefix.begin(), prefix.end());

        int i = 0;
        int j = prefix.size() - 1;
        long long ans=0;

        while (i < j) {
            ans += gcd(prefix[i], prefix[j]);
            i++;
            j--;
        }
        return ans;
    }
};