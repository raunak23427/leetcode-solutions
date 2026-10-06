/*
 * Problem: Remove All Adjacent Duplicates In String
 * Problem ID: 1128
 * Difficulty: Easy
 * Language: C++
 * Runtime: 1 ms
 * Memory: 14.4 MB
 * Synced From: LeetCode
 * Date: 2026-10-06
 */

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> temp;
        for(int i =0;i<s.size();i++){
            if(temp.size()==0){
                temp.push(s[i]);
            }
            else if(temp.top()==s[i]){
                temp.pop();
            }
            else{
                temp.push(s[i]);
            }
        }
        string ans ;
        while(!temp.empty()){
            ans+=temp.top();
            temp.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};