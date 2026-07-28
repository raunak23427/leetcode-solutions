/*
 * Problem: Smallest Palindromic Rearrangement I
 * Problem ID: 3812
 * Difficulty: Medium
 * Language: C++
 * Runtime: 37 ms
 * Memory: 80.6 MB
 * Synced From: LeetCode
 * Date: 2026-07-28
 */

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        string firstHalf = "";
        string middle = "";
        
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                middle = char(i + 'a');
            }
            firstHalf += string(freq[i] / 2, char(i + 'a'));
        }
        
        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());
        
        return firstHalf + middle + secondHalf;
    }
};