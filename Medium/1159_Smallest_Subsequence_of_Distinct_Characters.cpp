/*
 * Problem: Smallest Subsequence of Distinct Characters
 * Problem ID: 1159
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.8 MB
 * Synced From: LeetCode
 * Date: 2026-07-21
 */

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);

        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        vector<bool> vis(26, false);
        string st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (vis[c - 'a'])
                continue;

            while (!st.empty() &&
                   st.back() > c &&
                   last[st.back() - 'a'] > i) {
                vis[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            vis[c - 'a'] = true;
        }

        return st;
    }
};