/*
 * Problem: Count and Say
 * Problem ID: 38
 * Difficulty: Medium
 * Language: C++
 * Runtime: 4 ms
 * Memory: 9.9 MB
 * Synced From: LeetCode
 * Date: 2026-07-25
 */

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for (int i = 2; i <= n; i++) {
            string temp = "";
            int cnt = 1;

            for (int j = 1; j <= ans.size(); j++) {
                if (j < ans.size() && ans[j] == ans[j - 1]) {
                    cnt++;
                } else {
                    temp += to_string(cnt);
                    temp += ans[j - 1];
                    cnt = 1;
                }
            }

            ans = temp;
        }

        return ans;
    }
};