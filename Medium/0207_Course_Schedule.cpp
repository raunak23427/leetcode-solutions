/*
 * Problem: Course Schedule
 * Problem ID: 207
 * Difficulty: Medium
 * Language: C++
 * Runtime: 2 ms
 * Memory: 18.5 MB
 * Synced From: LeetCode
 * Date: 2026-10-22
 */

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indeg(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        queue<int> q;
        for (int i = 0; i < indeg.size(); i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (int i = 0; i < adj[node].size(); i++) {
                indeg[adj[node][i]]--;
                if (indeg[adj[node][i]] == 0) {
                    q.push(adj[node][i]);
                }
            }
        }
        if (count == numCourses) {
            return true;
        }
        return false;
    }
};