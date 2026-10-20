/*
 * Problem: Surrounded Regions
 * Problem ID: 130
 * Difficulty: Medium
 * Language: C++
 * Runtime: 1 ms
 * Memory: 14.4 MB
 * Synced From: LeetCode
 * Date: 2026-10-20
 */

class Solution {
public:
    int r;
    int c;
    int row[4] = {0, -1, 0, 1};
    int col[4] = {-1, 0, 1, 0};

    bool valid(int i, int j) {
        if (i >= 0 && i < r && j >= 0 && j < c) {
            return 1;
        }
        return 0;
    }

    void solve(vector<vector<char>>& board) {
        r = board.size();
        c = board[0].size();

        queue<pair<int, int>> q;

        // First row
        for (int j = 0; j < c; j++) {
            if (board[0][j] == 'O') {
                q.push(make_pair(0, j));
                board[0][j] = 'T';
            }
        }

        // Last column
        for (int i = 1; i < r; i++) {
            if (board[i][c - 1] == 'O') {
                q.push(make_pair(i, c - 1));
                board[i][c - 1] = 'T';
            }
        }

        // Last row
        if (r > 1) {
            for (int j = c - 2; j >= 0; j--) {
                if (board[r - 1][j] == 'O') {
                    q.push(make_pair(r - 1, j));
                    board[r - 1][j] = 'T';
                }
            }
        }

        // First column
        for (int i = 1; i < r - 1; i++) {
            if (board[i][0] == 'O') {
                q.push(make_pair(i, 0));
                board[i][0] = 'T';
            }
        }

        // BFS
        while (!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                if (valid(u + row[k], v + col[k]) &&
                    board[u + row[k]][v + col[k]] == 'O') {
                    q.push(make_pair(u + row[k], v + col[k]));
                    board[u + row[k]][v + col[k]] = 'T';
                }
            }
        }

        // Final conversion
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};