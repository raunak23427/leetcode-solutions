/*
 * Problem: Maximum Nesting Depth of the Parentheses
 * Problem ID: 1737
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.4 MB
 * Synced From: LeetCode
 * Date: 2026-09-28
 */

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxDepth = 0;
        for(char ch : s){
            if(ch == '('){
                depth++;
                maxDepth = max(depth, maxDepth);
            }
            else if(ch == ')'){
                depth--;
            }
        }
        return maxDepth;
    }
};