/*
 * Problem: Take Gifts From the Richest Pile
 * Problem ID: 2692
 * Difficulty: Easy
 * Language: C++
 * Runtime: 3 ms
 * Memory: 13.1 MB
 * Synced From: LeetCode
 * Date: 2026-08-16
 */

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for (int x : gifts) {
            pq.push(x);
        }

        while (k--) {
            int x = pq.top();
            pq.pop();

            int remaining = sqrt(x);

            pq.push(remaining);
        }

        long long ans = 0;

        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};