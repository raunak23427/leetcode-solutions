/*
 * Problem: Lowest Common Ancestor of a Binary Search Tree
 * Problem ID: 235
 * Difficulty: Medium
 * Language: C++
 * Runtime: 20 ms
 * Memory: 23.4 MB
 * Synced From: LeetCode
 * Date: 2026-07-22
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
        if (root == nullptr)
            return nullptr;
        if (root->val < n1->val && root->val < n2->val) {
            return lowestCommonAncestor(root->right, n1, n2);
        } else if (root->val > n1->val && root->val > n2->val) {
            return lowestCommonAncestor(root->left, n1, n2);
        } else
            return root;
    }
};