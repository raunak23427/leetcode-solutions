/*
 * Problem: Maximum Depth of Binary Tree
 * Problem ID: 104
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 22.1 MB
 * Synced From: LeetCode
 * Date: 2026-08-15
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
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
        return 0;

        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};