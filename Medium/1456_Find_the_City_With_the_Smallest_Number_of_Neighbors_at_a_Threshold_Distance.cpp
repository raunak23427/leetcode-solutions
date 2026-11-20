/*
 * Problem: Find the City With the Smallest Number of Neighbors at a Threshold Distance
 * Problem ID: 1456
 * Difficulty: Medium
 * Language: C++
 * Runtime: 12 ms
 * Memory: 16.8 MB
 * Synced From: LeetCode
 * Date: 2026-11-20
 */

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) {
                        continue;
                    }
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int mincount = INT_MAX;
        int ans = -1;
        vector<int>neigh(n);

        for (int i = 0; i < n; i++) {
            int count = 0; // Reset count for each city

            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if(mincount==count){
                if(ans<i){
                    ans=i;
                }
            }
            if(count<mincount){
                mincount=count;
                ans=i;
            }
            

            // Now compare this city's count with the minimum.
        }
        return ans;
    }
};