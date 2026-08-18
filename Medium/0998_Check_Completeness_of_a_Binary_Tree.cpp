/*
 * Problem: Check Completeness of a Binary Tree
 * Problem ID: 998
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 13.6 MB
 * Synced From: LeetCode
 * Date: 2026-08-18
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
int countNode(TreeNode * root ){
    if(root==nullptr){
        return 0;
    }
    return 1+countNode(root->left)+countNode(root->right);
}
bool CBT(TreeNode * root ,int index,int nums){
    if(root==nullptr){
          return 1;
      }
    if(index>=nums){
        return 0;

    }
    return CBT(root->left,2*index+1,nums)&& CBT(root->right,2*index+2,nums);
}
    bool isCompleteTree(TreeNode* root) {
        int nums=countNode(root);
        bool ans=CBT(root,0,nums);
        return ans;

    }
};