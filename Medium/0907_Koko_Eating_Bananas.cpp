/*
 * Problem: Koko Eating Bananas
 * Problem ID: 907
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 22.8 MB
 * Synced From: LeetCode
 * Date: 2026-10-25
 */


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long hours = 0;

            for (int pile : piles) {
                hours += (pile + (long long)mid - 1) / mid;
            }

            if (hours <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
