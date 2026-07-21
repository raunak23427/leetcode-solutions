/*
 * Problem: Minimum Distance Between BST Nodes
 * Problem ID: 799
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 12.4 MB
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void diff(TreeNode* root, int& prev, int& ans) {
        if(!root)return;
        diff(root->left, prev, ans);
        if (prev != INT_MIN) {
            ans = min(ans, root->val - prev);
        }
        prev = root->val;
        diff(root->right, prev, ans);
    }
    int minDiffInBST(TreeNode* root) {
        int prev=INT_MIN;
        int ans=INT_MAX;
        diff(root,prev,ans);
        return ans;
    }
};