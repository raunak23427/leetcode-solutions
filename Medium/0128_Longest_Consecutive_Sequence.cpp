/*
 * Problem: Longest Consecutive Sequence
 * Problem ID: 128
 * Difficulty: Medium
 * Language: C++
 * Runtime: 84 ms
 * Memory: 88.9 MB
 * Synced From: LeetCode
 * Date: 2026-10-13
 */


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for (auto it = st.begin(); it != st.end(); it++) {
            int x = *it;

            if (st.find(x - 1) == st.end()) {
                int count = 1;
                int num = x;

                while (st.find(num + 1) != st.end()) {
                    count++;
                    num++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};
