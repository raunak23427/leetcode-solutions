/*
 * Problem: Kth Smallest Element in a Sorted Matrix
 * Problem ID: 378
 * Difficulty: Medium
 * Language: C++
 * Runtime: 12 ms
 * Memory: 17.6 MB
 * Synced From: LeetCode
 * Date: 2026-08-18
 */

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector < pair<int, pair<int, int>> >temp;

        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            temp.push_back(make_pair(matrix[i][0], make_pair(i, 0)));
        }
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            p(temp.begin(), temp.end());
        pair<int, pair<int, int>> element;
        int i, j;
        int ans;
        while (k--) {
            element = p.top();
            p.pop();
            ans = element.first;
            i = element.second.first;
            j = element.second.second;
            if (j + 1 < n) {
                p.push(make_pair(matrix[i][j + 1], make_pair(i, j + 1)));
            }
        }
        return ans;
    }
};