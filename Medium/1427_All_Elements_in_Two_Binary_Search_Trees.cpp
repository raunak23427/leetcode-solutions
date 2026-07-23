/*
 * Problem: All Elements in Two Binary Search Trees
 * Problem ID: 1427
 * Difficulty: Medium
 * Language: C++
 * Runtime: 13 ms
 * Memory: 86.4 MB
 * Synced From: LeetCode
 * Date: 2026-07-23
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        vector<int> ans;
        stack<TreeNode*> s1, s2;

        while (root1 != nullptr) {
            s1.push(root1);
            root1 = root1->left;
        }

        while (root2 != nullptr) {
            s2.push(root2);
            root2 = root2->left;
        }

        while (!s1.empty() && !s2.empty()) {

            if (s1.top()->val <= s2.top()->val) {

                TreeNode* temp = s1.top();
                s1.pop();

                ans.push_back(temp->val);

                root1 = temp->right;

                while (root1 != nullptr) {
                    s1.push(root1);
                    root1 = root1->left;
                }
            }
            else {

                TreeNode* temp = s2.top();
                s2.pop();

                ans.push_back(temp->val);

                root2 = temp->right;

                while (root2 != nullptr) {
                    s2.push(root2);
                    root2 = root2->left;
                }
            }
        }

        while (!s1.empty()) {

            TreeNode* temp = s1.top();
            s1.pop();

            ans.push_back(temp->val);

            root1 = temp->right;

            while (root1 != nullptr) {
                s1.push(root1);
                root1 = root1->left;
            }
        }

        while (!s2.empty()) {

            TreeNode* temp = s2.top();
            s2.pop();

            ans.push_back(temp->val);

            root2 = temp->right;

            while (root2 != nullptr) {
                s2.push(root2);
                root2 = root2->left;
            }
        }

        return ans;
    }
};