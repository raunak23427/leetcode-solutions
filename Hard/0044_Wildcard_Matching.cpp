/*
 * Problem: Wildcard Matching
 * Problem ID: 44
 * Difficulty: Hard
 * Language: C++
 * Runtime: 139 ms
 * Memory: 54.9 MB
 * Synced From: LeetCode
 * Date: 2026-07-08
 */

class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int i, int j, string &s, string &p) {
        if (i == s.size() && j == p.size())
            return true;

        if (j == p.size())
            return false;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == s.size()) {
            while (j < p.size()) {
                if (p[j] != '*')
                    return dp[i][j] = false;
                j++;
            }
            return dp[i][j] = true;
        }

        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = solve(i + 1, j + 1, s, p);

        if (p[j] == '*') {
            return dp[i][j] =
                solve(i, j + 1, s, p) ||   // '*' matches empty
                solve(i + 1, j, s, p);     // '*' matches one or more chars
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        dp.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(0, 0, s, p);
    }
};