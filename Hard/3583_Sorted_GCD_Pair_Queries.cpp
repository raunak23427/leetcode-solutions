/*
 * Problem: Sorted GCD Pair Queries
 * Problem ID: 3583
 * Difficulty: Hard
 * Language: C++
 * Runtime: 27 ms
 * Memory: 134.2 MB
 * Synced From: LeetCode
 * Date: 2026-07-17
 */

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> cnt(mx + 1, 0);

        // cnt[g] = number of elements divisible by g
        for (int g = 1; g <= mx; g++) {
            long long c = 0;
            for (int j = g; j <= mx; j += g)
                c += freq[j];
            cnt[g] = c * (c - 1) / 2;
        }

        // exact[g] = pairs having gcd exactly g
        vector<long long> exact = cnt;

        for (int g = mx; g >= 1; g--) {
            for (int j = 2 * g; j <= mx; j += g)
                exact[g] -= exact[j];
        }

        // prefix counts
        vector<long long> prefix(mx + 1, 0);
        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exact[g];

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};