/*
 * Problem: Kth Largest Element in an Array
 * Problem ID: 215
 * Difficulty: Medium
 * Language: C++
 * Runtime: 27 ms
 * Memory: 72.6 MB
 * Synced From: LeetCode
 * Date: 2026-08-16
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int,vector<int>,greater<int>>p;
      for(int i=0;i<k;i++){
        p.push(nums[i]);
      }  
      for(int i=k;i<nums.size();i++){
        if(nums[i]>p.top()){
            p.pop();
            p.push(nums[i]);
        }
      }
      return p.top();
    }
};