/*
 * Problem: Binary Tree Right Side View
 * Problem ID: 199
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 14.9 MB
 * Synced From: LeetCode
 * Date: 2026-07-10
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        vector<int> level;
        TreeNode* temp;
        if (root == nullptr) {
            return {};
        }
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
            ans.push_back(level.back());
            level.clear();
        }
        return ans;
    }
};