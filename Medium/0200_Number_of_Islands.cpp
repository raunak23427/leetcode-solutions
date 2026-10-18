/*
 * Problem: Number of Islands
 * Problem ID: 200
 * Difficulty: Medium
 * Language: C++
 * Runtime: 22 ms
 * Memory: 18.2 MB
 * Synced From: LeetCode
 * Date: 2026-10-18
 */

class Solution {
public:
    int r;
    int c;

    int row[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    bool valid(int i, int j) {
        if (i >= 0 && i < r && j >= 0 && j < c) {
            return true;
        }
        return false;
    }

    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        c = grid[0].size();

        int count = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    q.push(make_pair(i, j));
                    grid[i][j] = '0';
                    count++;

                    while (!q.empty()) {
                        int u = q.front().first;
                        int v = q.front().second;
                        q.pop();

                        for (int k = 0; k < 8; k++) {
                            if (k == 1 || k == 3 || k == 5 || k == 7)
                                continue;

                            if (valid(u + row[k], v + col[k]) &&
                                grid[u + row[k]][v + col[k]] == '1') {
                                grid[u + row[k]][v + col[k]] = '0';
                                q.push(make_pair(u + row[k], v + col[k]));
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};