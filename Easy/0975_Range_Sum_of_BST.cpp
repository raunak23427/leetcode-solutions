/*
 * Problem: Range Sum of BST
 * Problem ID: 975
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 64.9 MB
 * Synced From: LeetCode
 * Date: 2026-07-22
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
void bst(TreeNode* root ,int low ,int high,int & sum){
    if(root==nullptr)return;
    if(root->val<low && root->val<high){
        bst(root->right,low,high,sum);
    }
    else if(root->val>low && root->val>high){
        bst(root->left,low,high,sum);
    }
    else{
        bst(root->left,low,high,sum);
        sum+=root->val;
        bst(root->right,low,high,sum);
    }
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum =0;
        bst(root,low,high,sum);
        return sum;
    }
};