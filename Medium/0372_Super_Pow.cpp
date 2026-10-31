/*
 * Problem: Super Pow
 * Problem ID: 372
 * Difficulty: Medium
 * Language: C++
 * Runtime: 3 ms
 * Memory: 15.2 MB
 * Synced From: LeetCode
 * Date: 2026-10-31
 */

class Solution {
private:
    const int MOD = 1337;

   
    int modPow(int base, int exp) {
        base %= MOD;
        int res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (int digit : b) {
            
            res = (modPow(res, 10) * modPow(a, digit)) % MOD;
        }
        return res;
    }
};