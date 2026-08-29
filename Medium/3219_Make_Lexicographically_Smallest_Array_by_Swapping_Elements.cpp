/*
 * Problem: Make Lexicographically Smallest Array by Swapping Elements
 * Problem ID: 3219
 * Difficulty: Medium
 * Language: C++
 * Runtime: 178 ms
 * Memory: 165.9 MB
 * Synced From: LeetCode
 * Date: 2026-08-29
 */

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();

        // Store {value, original index}
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort according to value
        sort(arr.begin(), arr.end());

        vector<int> ans(n);

        int i = 0;

        while (i < n) {
            
            int j = i;

            // Find all values belonging to the same group
            while (j + 1 < n &&
                   arr[j + 1].first - arr[j].first <= limit) {
                j++;
            }

            // Values in this group
            vector<int> values;
            vector<int> indices;

            for (int k = i; k <= j; k++) {
                values.push_back(arr[k].first);
                indices.push_back(arr[k].second);
            }

            // Put values in smallest indices
            sort(indices.begin(), indices.end());

            for (int k = 0; k < values.size(); k++) {
                ans[indices[k]] = values[k];
            }

            i = j + 1;
        }

        return ans;
    }
};