/*
 * Problem: Keys and Rooms
 * Problem ID: 871
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 14.7 MB
 * Synced From: LeetCode
 * Date: 2026-10-03
 */

class Solution {
public:
    void ddfs(int node, vector<int>& visited, vector<vector<int>>& rooms) {
        visited[node] = 1;

        for (int i = 0; i < rooms[node].size(); i++) {
            if (visited[rooms[node][i]] == 0) {
                ddfs(rooms[node][i], visited, rooms);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int> visited(n, 0);

        ddfs(0, visited, rooms);

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                return false;
            }
        }

        return true;
    }
};