/*
 * Problem: GCD of Odd and Even Sums
 * Problem ID: 3995
 * Difficulty: Easy
 * Language: C++
 * Runtime: 3 ms
 * Memory: 8.5 MB
 * Synced From: LeetCode
 * Date: 2026-07-15
 */

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumeven=0;
        int sumodd=0;
        int i=1;int m=n;
        while(n!=0){
        if(i%2==0){
           sumeven+=i;
           n--;
        }
        i++;
        }
        i=1;
        while(m!=0){
        if(i%2!=0){
           sumodd+=i;
           m--;
        }
        i++;
        }
        
        return __gcd(sumodd, sumeven);
    }
};