/*
 * Problem: Cousins in Binary Tree
 * Problem ID: 1035
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 14.1 MB
 * Synced From: LeetCode
 * Date: 2026-07-09
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;

        TreeNode* temp;
        if (root == nullptr) {
            return false;
        }
        q.push(root);
        bool foundX = false;
        bool foundY = false;
        TreeNode* parentX=nullptr;
        TreeNode* parentY=nullptr;
        while (!q.empty()) {

            int n = q.size();

            for (int i = 0; i < n; i++) {
                temp = q.front();
                q.pop();
                if (temp->val == x) {
                    foundX = true;
                }
                if (temp->val == y) {
                    foundY = true;
                }
                if (temp->left != nullptr) {
                    q.push(temp->left);
                    if (temp->left->val == x) {
                        parentX = temp;
                    }
                    if (temp->left->val == y) {
                        parentY = temp;
                    }
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);

                    if (temp->right->val == x) {
                        parentX = temp;
                    }

                    if (temp->right->val == y) {
                        parentY = temp;
                    }
                }
            }
            if (foundX == true && foundY == true && parentX != parentY) {
                return true;
            }
            if (foundX == true && foundY == true && parentX == parentY) {
                return false;
            }
            if (foundX == true && foundY == false) {
                return false;
            }
            if (foundX == false && foundY == true) {
                return false;
            }
            foundX = false;
            foundY = false;
        }
        return false;
    }
};