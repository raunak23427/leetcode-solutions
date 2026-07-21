/*
 * Problem: Construct Binary Search Tree from Preorder Traversal
 * Problem ID: 1050
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 16.4 MB
 * Synced From: LeetCode
 * Date: 2026-07-21
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 TreeNode * bst( vector<int>&nums,int low ,int high ){
    if(low>high){
        return nullptr;
    }
    int idx=low+1;
    TreeNode* root=new TreeNode(nums[low]);
    while(idx<=high &&nums[idx]<nums[low]){
        idx++;
    }
    root->left=bst(nums,low+1,idx-1);
    root->right=bst(nums,idx,high);
    return root ;
 }
    TreeNode* bstFromPreorder(vector<int>& nums) {
        return bst(nums,0,nums.size()-1);
    }
};