/*
 * Problem: Find the Distance Value Between Two Arrays
 * Problem ID: 1486
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 16.5 MB
 * Synced From: LeetCode
 * Date: 2026-11-05
 */

#include <vector>
#include <cmath>

class Solution {
public:
    int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d) {
        int distanceValue = 0;
        
        for (int i = 0; i < arr1.size(); ++i) {
            bool isValid = true;
            for (int j = 0; j < arr2.size(); ++j) {
                if (std::abs(arr1[i] - arr2[j]) <= d) {
                    isValid = false;
                    break; 
                }
            } 
            if (isValid) {
                distanceValue++;
            }
        }
        
        return distanceValue;
    }
};