/*
 * Problem: Perfect Number
 * Problem ID: 507
 * Difficulty: Easy
 * Language: C++
 * Runtime: 2082 ms
 * Memory: 7.7 MB
 * Synced From: LeetCode
 * Date: 2026-09-23
 */

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for(int i = 1; i<num; i++){
            if(num % i == 0){
                sum += i;
            }
        }
        return sum == num;
    }
};