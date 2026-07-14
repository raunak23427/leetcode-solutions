/*
 * Problem: Insert into a Binary Search Tree
 * Problem ID: 784
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 59.3 MB
 * Synced From: LeetCode
 * Date: 2026-07-14
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
    TreeNode* insertIntoBST(TreeNode* root, int value) {
        if(root==nullptr){
            TreeNode * temp = new TreeNode(value);
            return temp;
        }
        if(root->val>value){
            root->left=insertIntoBST(root->left,value);
        }
        else{
            root->right=insertIntoBST(root->right,value);
        }
        return root;
    }
};