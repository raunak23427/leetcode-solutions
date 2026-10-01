/*
 * Problem: Evaluate the Bracket Pairs of a String
 * Problem ID: 1934
 * Difficulty: Medium
 * Language: C++
 * Runtime: 81 ms
 * Memory: 122.7 MB
 * Synced From: LeetCode
 * Date: 2026-10-01
 */

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (auto &x : knowledge) {
            mp[x[0]] = x[1];
        }

        string ans;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                string key;
                i++;

                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                if (mp.count(key))
                    ans += mp[key];
                else
                    ans += "?";
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};