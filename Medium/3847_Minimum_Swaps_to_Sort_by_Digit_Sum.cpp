/*
 * Problem: Minimum Swaps to Sort by Digit Sum
 * Problem ID: 3847
 * Difficulty: Medium
 * Language: C++
 * Runtime: 455 ms
 * Memory: 237.2 MB
 * Synced From: LeetCode
 * Date: 2026-10-17
 */


class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        auto digitSum = [](int x) {
            int sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            return sum;
        };

        vector<pair<int, int>> arr;
        for (int x : nums) {
            arr.push_back({x, digitSum(x)});
        }

        sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
            if (a.second != b.second)
                return a.second < b.second;
            return a.first < b.first;
        });

        vector<int> target(n);
        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            target[i] = arr[i].first;
            pos[target[i]] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || pos[nums[i]] == i)
                continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = pos[nums[j]];
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};
