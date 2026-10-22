/*
 * Problem: Course Schedule II
 * Problem ID: 210
 * Difficulty: Medium
 * Language: C++
 * Runtime: 3 ms
 * Memory: 17.5 MB
 * Synced From: LeetCode
 * Date: 2026-10-22
 */

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<int>ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int i = 0; i < adj[node].size(); i++) {
                indeg[adj[node][i]]--;
                if (indeg[adj[node][i]] == 0) {
                    q.push(adj[node][i]);
                }
            }
        }
        if (ans.size() == numCourses) {
            return ans;
        }
        return {};



    }
};