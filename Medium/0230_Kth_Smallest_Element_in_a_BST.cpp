/*
 * Problem: Kth Smallest Element in a BST
 * Problem ID: 230
 * Difficulty: Medium
 * Language: C++
 * Runtime: 3 ms
 * Memory: 24.4 MB
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
void kth(TreeNode * root ,int &count,int k,int & ans){
    if(root==nullptr)return ;
      kth(root->left,count ,k,ans);
      count++;
      if(count <=k){
          ans=root->val;
      }
      
      kth(root->right ,count ,k,ans);
}
    int kthSmallest(TreeNode* root, int k) {
         int count =0;
        int ans=0;
        kth(root,count,k,ans);
        return ans;
    }
};