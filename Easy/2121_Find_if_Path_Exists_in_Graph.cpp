/*
 * Problem: Find if Path Exists in Graph
 * Problem ID: 2121
 * Difficulty: Easy
 * Language: C++
 * Runtime: 394 ms
 * Memory: 267.6 MB
 * Synced From: LeetCode
 * Date: 2026-10-22
 */

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>visited(n,0);
        queue<int>q;
        if(source==destination){
            return true;
        }

        vector<int>adj[n];
        //create the adjacency list
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        q.push(source);
        visited[source]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++){
                if(visited[adj[node][i]]==0){
                    q.push(adj[node][i]);
                    visited[adj[node][i]]=1;
                    if(visited[destination]==1){
                    return true;
                }
                
                }
                
                
            }
        }
        return false;
    }
};