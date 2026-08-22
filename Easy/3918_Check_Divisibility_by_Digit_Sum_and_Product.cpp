/*
 * Problem: Check Divisibility by Digit Sum and Product
 * Problem ID: 3918
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 7.8 MB
 * Synced From: LeetCode
 * Date: 2026-08-22
 */

class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int sum = 0;
        int product = 1;

        while (n > 0) {
            int digit = n % 10;
            sum += digit;
            product *= digit;
            n /= 10;
        }

        return original % (sum + product) == 0;
    }
};