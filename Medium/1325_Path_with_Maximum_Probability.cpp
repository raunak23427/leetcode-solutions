/*
 * Problem: Path with Maximum Probability
 * Problem ID: 1325
 * Difficulty: Medium
 * Language: C++
 * Runtime: 59 ms
 * Memory: 71.3 MB
 * Synced From: LeetCode
 * Date: 2026-11-10
 */

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int src, int dest) {
        vector<vector<pair<double, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({prob, v});
            adj[v].push_back({prob, u});
        }
        // use the dij algo but in reverse
        vector<int> explore(n, 0);
        vector<double> dist(n, 0.0);
        vector<int> parent(n, -1);
        parent[src] = -1;
        // make the priority queuel
        priority_queue<pair<double, int>> p;
        p.push({1.0, src});
        dist[src] = 1.0;
        while (!p.empty()) {
            double prob=p.top().first;

            int node = p.top().second;
            p.pop();
            if (explore[node] == 1) {
                continue;
            }
            explore[node] = 1;
            for (int j = 0; j < adj[node].size(); j++) {
                int neighbour = adj[node][j].second;
                double weight = adj[node][j].first;
                if (dist[node] * weight > dist[neighbour]) {
                    dist[neighbour] = dist[node] * weight;
                    p.push({dist[neighbour], neighbour});
                    parent[neighbour] = node;
                }
            }
        }
        
        
        return dist[dest];
    }
};