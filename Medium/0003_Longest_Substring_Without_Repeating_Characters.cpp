/*
 * Problem: Longest Substring Without Repeating Characters
 * Problem ID: 3
 * Difficulty: Medium
 * Language: C++
 * Runtime: 15 ms
 * Memory: 19 MB
 * Synced From: LeetCode
 * Date: 2026-08-21
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>count(256,0);
        int second =0;
        int first=0;
        int length=0;
        while(second<s.size()){
            while(count[s[second]]){
                count[s[first]]=0;
                first++;
            }
            count[s[second]]=1;
            length=max(length,second-first+1);
            second++;
        }
        return length;

        
    }
};