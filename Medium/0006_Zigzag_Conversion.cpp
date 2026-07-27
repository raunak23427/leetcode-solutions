/*
 * Problem: Zigzag Conversion
 * Problem ID: 6
 * Difficulty: Medium
 * Language: C++
 * Runtime: 4 ms
 * Memory: 14 MB
 * Synced From: LeetCode
 * Date: 2026-07-27
 */

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> rows(numRows);

        int currRow = 0;
        bool goingDown = true;

        for (char c : s) {
            rows[currRow] += c;

            if (currRow == 0)
                goingDown = true;
            else if (currRow == numRows - 1)
                goingDown = false;

            currRow += goingDown ? 1 : -1;
        }

        string ans;
        for (string &row : rows)
            ans += row;

        return ans;
    }
};