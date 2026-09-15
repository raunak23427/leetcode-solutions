/*
 * Problem: Subarray Sum Equals K
 * Problem ID: 560
 * Difficulty: Medium
 * Language: C++
 * Runtime: 2531 ms
 * Memory: 34.2 MB
 * Synced From: LeetCode
 * Date: 2026-09-15
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int total=0;
        int n=nums.size();
       for(int i=0;i<n;i++){
        int sum =0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
             if(sum==k){
            total+=1;
        }

        }
       
       }
       return total;

        
    }
};