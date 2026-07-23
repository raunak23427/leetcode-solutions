/*
 * Problem: Maximize Active Section with Trade II
 * Problem ID: 3804
 * Difficulty: Hard
 * Language: C++
 * Runtime: 223 ms
 * Memory: 255.7 MB
 * Synced From: LeetCode
 * Date: 2026-07-23
 */

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    struct SegmentTree {
        int n;
        vector<int> tree;

        SegmentTree(const vector<int>& arr) {
            n = arr.size();
            if (n > 0) {
                tree.resize(4 * n, 0);
                build(0, 0, n - 1, arr);
            }
        }

        void build(int node, int start, int end, const vector<int>& arr) {
            if (start == end) {
                tree[node] = arr[start];
                return;
            }
            int mid = start + (end - start) / 2;
            build(2 * node + 1, start, mid, arr);
            build(2 * node + 2, mid + 1, end, arr);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }

        int query(int node, int start, int end, int l, int r) {
            if (r < start || end < l) return 0;
            if (l <= start && end <= r) return tree[node];
            int mid = start + (end - start) / 2;
            return max(query(2 * node + 1, start, mid, l, r),
                       query(2 * node + 2, mid + 1, end, l, r));
        }

        int query(int l, int r) {
            if (l > r || n == 0) return 0;
            return query(0, 0, n - 1, l, r);
        }
    };

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();

        // 1. Total '1's in the ENTIRE string initially
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }

        // 2. Identify all contiguous '0' blocks in the string
        vector<int> bStart, bEnd, bSize;
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0') i++;
                bStart.push_back(start);
                bEnd.push_back(i - 1);
                bSize.push_back(i - start);
            } else {
                i++;
            }
        }

        // 3. Precompute adjacent '0' blocks length sums for RMQ
        int m = bSize.size();
        vector<int> pairSum;
        if (m >= 2) {
            pairSum.resize(m - 1);
            for (int k = 0; k < m - 1; ++k) {
                pairSum[k] = bSize[k] + bSize[k + 1];
            }
        }

        SegmentTree st(pairSum);
        vector<int> ans;
        ans.reserve(queries.size());

        // 4. Process each query independently
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            
            // Find range of '0'-blocks that overlap with substring [l, r]
            int low = lower_bound(bEnd.begin(), bEnd.end(), l) - bEnd.begin();
            int high = upper_bound(bStart.begin(), bStart.end(), r) - bStart.begin() - 1;

            int maxPairSum = 0;

            // A valid trade REQUIRES at least 2 zero blocks separated by '1's
            if (low < high) {
                // Compute clamped lengths for the boundary '0' blocks inside [l, r]
                int firstLen = bEnd[low] - max(bStart[low], l) + 1;
                int lastLen = min(bEnd[high], r) - bStart[high] + 1;

                if (high - low == 1) {
                    // Exactly 2 zero blocks intersecting the query
                    maxPairSum = firstLen + lastLen;
                } else {
                    // 3 or more zero blocks: calculate max gain over all valid pairs in range
                    int pair1 = firstLen + bSize[low + 1];
                    int pair2 = bSize[high - 1] + lastLen;
                    int rmqMax = st.query(low + 1, high - 2);

                    maxPairSum = max({pair1, pair2, rmqMax});
                }
            }

            // Since the trade only affects the substring, total '1's naturally increases by maxPairSum
            ans.push_back(totalOnes + maxPairSum);
        }

        return ans;
    }
};