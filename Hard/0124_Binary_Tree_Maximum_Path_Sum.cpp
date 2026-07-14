/*
 * Problem: Binary Tree Maximum Path Sum
 * Problem ID: 124
 * Difficulty: Hard
 * Language: C++
 * Runtime: 0 ms
 * Memory: 27.9 MB
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int pathsum(TreeNode* root, int& sum) {
        if (root == nullptr) {
            return 0;
        }
        
        int left = max(0, pathsum(root->left, sum));
        int right = max(0, pathsum(root->right, sum));
        sum = max(sum, root->val + left + right);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        int value = pathsum(root, sum);
        return max(value, sum);
    }
};