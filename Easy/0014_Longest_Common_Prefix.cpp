/*
 * Problem: Longest Common Prefix
 * Problem ID: 14
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 11.4 MB
 * Synced From: LeetCode
 * Date: 2026-11-13
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix.pop_back();

                if (prefix.empty())
                    return "";
            }
        }

        return prefix;
    }
};