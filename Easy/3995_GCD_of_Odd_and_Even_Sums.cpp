/*
 * Problem: GCD of Odd and Even Sums
 * Problem ID: 3995
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.5 MB
 * Synced From: LeetCode
 * Date: 2026-07-15
 */

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumeven=n*(n+1);
        int sumodd=n*n;
        
        return __gcd(sumodd, sumeven);
    }
};