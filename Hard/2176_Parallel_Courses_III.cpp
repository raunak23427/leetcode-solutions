/*
 * Problem: Parallel Courses III
 * Problem ID: 2176
 * Difficulty: Hard
 * Language: C++
 * Runtime: 56 ms
 * Memory: 132.9 MB
 * Synced From: LeetCode
 * Date: 2026-10-26
 */

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // create the adjacency list
        vector<int> adj[n];
        vector<int> indeg(n, 0);
        for (int i = 0; i < relations.size(); i++) {
            adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
        }
        for (int i = 0; i < n; i++){
            for (int j =0; j < adj[i].size(); j++) {
               indeg[ adj[i][j]]++;
            }
        }

        queue<int> q;
        for(int i=0;i<indeg.size();i++){
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        vector<int>coursetime(n,0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for (int i = 0; i < adj[node].size(); i++) {
                indeg[adj[node][i]]--;
                if (indeg[adj[node][i]] == 0) {
                    q.push(adj[node][i]);
                }
                coursetime[adj[node][i]]=max(coursetime[adj[node][i]],coursetime[node]+time[node]);
            }
          
        }int ans=0;
        for(int i=0;i<coursetime.size();i++){
            ans=max(ans,coursetime[i]+time[i]);

        }
        return ans;
    }
};