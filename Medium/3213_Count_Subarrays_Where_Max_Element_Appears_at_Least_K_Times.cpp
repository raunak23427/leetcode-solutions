/*
 * Problem: Count Subarrays Where Max Element Appears at Least K Times
 * Problem ID: 3213
 * Difficulty: Medium
 * Language: C++
 * Runtime: 11 ms
 * Memory: 131.5 MB
 * Synced From: LeetCode
 * Date: 2026-09-16
 */

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
       
        //find the max eleemnt ;
        int maxelement=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxelement=max(maxelement,nums[i]);
        }
        int start=0;int end=0;long long total=0;int count=0; 
        while(end<nums.size()){
            if(nums[end]==maxelement){
                 count++;
            }
            while(count==k){
                if(nums[start]==maxelement){
                    count--;
                }
                total+=nums.size()-end;
                start++;
            }
            end++;
        }
        return total;
    }
};