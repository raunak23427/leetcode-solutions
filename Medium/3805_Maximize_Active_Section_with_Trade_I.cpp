/*
 * Problem: Maximize Active Section with Trade I
 * Problem ID: 3805
 * Difficulty: Medium
 * Language: C++
 * Runtime: 182 ms
 * Memory: 175.9 MB
 * Synced From: LeetCode
 * Date: 2026-07-21
 */

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            if (c == '1') ones++;

        string t = "1" + s + "1";

        vector<pair<char, int>> runs;

        for (char c : t) {
            if (runs.empty() || runs.back().first != c)
                runs.push_back({c, 1});
            else
                runs.back().second++;
        }

        int ans = ones;

        for (int i = 1; i + 1 < runs.size(); i++) {
            if (runs[i].first == '1') {
                int gain = runs[i - 1].second + runs[i + 1].second;
                ans = max(ans, ones + gain);
            }
        }

        return ans;
    }
};