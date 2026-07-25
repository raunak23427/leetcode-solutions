/*
 * Problem: Maximum Product of Two Digits
 * Problem ID: 3859
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.6 MB
 * Synced From: LeetCode
 * Date: 2026-07-25
 */

class Solution {
public:
    int maxProduct(int n) {
        int mx1=-1;
        int mx2=-1;
        while(n){
            int digit=n%10;
            if(digit>=mx1){
                mx2=mx1;
                mx1=digit;
            }
            else if(digit>mx2){
                mx2=digit;
            }
             n /= 10;
           
        }
        return mx1*mx2;

    }
};