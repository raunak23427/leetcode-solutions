/*
 * Problem: Symmetric Tree
 * Problem ID: 101
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 18.4 MB
 * Synced From: LeetCode
 * Date: 2026-10-13
 */


class Solution {
public:
    bool check(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL)
            return true;

        if (left == NULL || right == NULL)
            return false;

        if (left->val != right->val)
            return false;

        return check(left->left, right->right) &&
               check(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};
