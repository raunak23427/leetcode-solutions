/*
 * Problem: Subarray Sums Divisible by K
 * Problem ID: 1016
 * Difficulty: Medium
 * Language: C++
 * Runtime: 16 ms
 * Memory: 35.7 MB
 * Synced From: LeetCode
 * Date: 2026-09-15
 */

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      unordered_map<int,int>m;
      int total=0;
      m[0]=1;
    int prefixsum=0;
      for(int i=0;i<nums.size();i++){
        prefixsum+=nums[i];
        int mod=prefixsum%k;
        if(mod<0){
            mod+=k;
        }
        if(m.count(mod)){
            total+=m[mod];
            m[mod]++;
        }
        else{
            m[mod]=1;
        }
      }
      return total;
    }
};