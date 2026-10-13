/*
 * Problem: Path Sum
 * Problem ID: 112
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 21.6 MB
 * Synced From: LeetCode
 * Date: 2026-10-13
 */


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;

        if (root->left == NULL && root->right == NULL) {
            return targetSum == root->val;
        }

        targetSum -= root->val;

        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};
