/*
 * Problem: Rotting Oranges
 * Problem ID: 1036
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 16.4 MB
 * Synced From: LeetCode
 * Date: 2026-10-15
 */


class Solution {
public:
    int row[4] = {-1, +1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    int r;
    int c;

    bool valid(int i, int j) {
        if (i >= 0 && i < r && j >= 0 && j < c) {
            return 1;
        }
        return 0;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();

        queue<pair<int, int>> q;
        int count = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }

        if (q.size() == 0 && count > 0) {
            return -1;
        }

        if (q.size() == 0) {
            return 0;
        }

        int timer = 0;

        while (!q.empty()) {
            timer++;
            int current = q.size();

            while (current--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    if (valid(i + row[k], j + col[k]) &&
                        grid[i + row[k]][j + col[k]] == 1) {
                        grid[i + row[k]][j + col[k]] = 2;
                        q.push(make_pair(i + row[k], j + col[k]));
                    }
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return timer - 1;
    }
};
