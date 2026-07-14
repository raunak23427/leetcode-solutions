/*
 * Problem: Search in a Binary Search Tree
 * Problem ID: 783
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 35.5 MB
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
    TreeNode* searchBST(TreeNode* root, int target) {
        if (root == nullptr)
            return nullptr;
        if (root->val == target)
            return root;
        if (root->val < target) {
           return  searchBST(root->right, target);
        } else {
            return searchBST(root->left, target);
        }
    }
};