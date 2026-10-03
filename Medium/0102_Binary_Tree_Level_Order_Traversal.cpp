/*
 * Problem: Binary Tree Level Order Traversal
 * Problem ID: 102
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 17.2 MB
 * Synced From: LeetCode
 * Date: 2026-10-03
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if (root == nullptr) {
            return {};
        }
        q.push(root);
        TreeNode* temp;

        while (!q.empty()) {
            int size = q.size();
            vector<int> ans1;
            for (int i = 0; i < size; i++) {
                temp = q.front();
                q.pop();
                ans1.push_back(temp->val);
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
            ans.push_back(ans1);
        }
        return ans;
    }
};