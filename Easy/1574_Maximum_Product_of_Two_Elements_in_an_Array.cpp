/*
 * Problem: Maximum Product of Two Elements in an Array
 * Problem ID: 1574
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 13.3 MB
 * Synced From: LeetCode
 * Date: 2026-07-27
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max=0;
        int second =0;
        for(int i =0;i<=nums.size()-1;i++){
            if(nums[i]>=max){
                second=max;
                max=nums[i];
                
            }
            else if(nums[i]>=second){
                second=nums[i];
            }

        }
        return( max-1)*(second-1);
    }
};