/*
 * Problem: Subarray Sum Equals K
 * Problem ID: 560
 * Difficulty: Medium
 * Language: C++
 * Runtime: 36 ms
 * Memory: 45.5 MB
 * Synced From: LeetCode
 * Date: 2026-09-15
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int total = 0;
        int prefixsum=0;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            if(m.count(prefixsum-k)){
                total+=m[prefixsum-k];
                m[prefixsum]++;
            }
            else if(m.count(prefixsum)){
               
                m[prefixsum]++;
            }
            else{
                m[prefixsum]=1;
            }
        }
        return total;
    }
};