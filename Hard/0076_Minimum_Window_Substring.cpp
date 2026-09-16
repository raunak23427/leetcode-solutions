/*
 * Problem: Minimum Window Substring
 * Problem ID: 76
 * Difficulty: Hard
 * Language: C++
 * Runtime: 9 ms
 * Memory: 11.5 MB
 * Synced From: LeetCode
 * Date: 2026-09-16
 */

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for (int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }
        int start = 0;
        int end = 0;
        int ans = INT_MAX;
        int index = -1;
        int total = t.size();
        while (end < s.size()) {
            m[s[end]]--;
            if (m[s[end]] >= 0) {
                total--;
            }
            while (total == 0) {
                if (end - start + 1 < ans) {
                    ans = end - start + 1;
                    index = start;
                }
                m[s[start]]++;
                if (m[s[start]] > 0) {
                    total++;
                }
                start++;
            }
            end++;
        }
        if (index == -1) {
            return "";
        }
        string str = "";
        
         return s.substr(index, ans);
    }
};