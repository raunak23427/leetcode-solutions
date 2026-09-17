/*
 * Problem: Find Two Non-overlapping Sub-arrays Each With Target Sum
 * Problem ID: 1573
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 88.9 MB
 * Synced From: LeetCode
 * Date: 2026-09-17
 */

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;
        int mini = INT_MAX;

        vector<int> best(n, INT_MAX);

        for(int right = 0; right < n; right++){
            sum += arr[right];

            while(sum > target){
                sum -= arr[left];
                left++;
            }

            if(sum == target){
                int len = right - left + 1;

                if(left > 0 && best[left - 1] != INT_MAX){
                    ans = min(ans, len + best[left - 1]);
                }

                mini = min(mini, len);
            }

            best[right] = mini;
        }

        if(ans == INT_MAX){
            return -1;
        }

        return ans;
    }
};