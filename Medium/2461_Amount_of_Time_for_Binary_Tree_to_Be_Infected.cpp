/*
 * Problem: Amount of Time for Binary Tree to Be Infected
 * Problem ID: 2461
 * Difficulty: Medium
 * Language: C++
 * Runtime: 8 ms
 * Memory: 129.6 MB
 * Synced From: LeetCode
 * Date: 2026-07-13
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
    void targetnode(TreeNode* root, int start, TreeNode*& targetnde) {
        if (root == nullptr)
            return;
        if ((root->val) == start){targetnde = root;
             return;}
             
        
        targetnode(root->left, start, targetnde);
        if(targetnde != nullptr)
    return;
        targetnode(root->right, start, targetnde);
    }
    int burn(TreeNode* root, int& target, int& timer) {
        // FOR THE UPPER PART ;
        if (root == nullptr)
            return 0;
        if (root->val == target)
            return -1;
        int left = burn(root->left, target, timer);
        int right = burn(root->right, target, timer);
        if (left < 0) {
            timer = max(timer, -(left) + right);
            return left - 1;
        }
        if (right < 0) {
            timer = max(timer, -(right) + left);
            return right - 1;
        }
        return 1 + max(left, right);
    }
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    int amountOfTime(TreeNode* root, int start) {
        int timer = 0;
        burn(root, start, timer);
        // now for the lower part ;
        TreeNode* targetnde = nullptr;
        targetnode(root, start, targetnde);

        int lowerheight = height(targetnde);
        return max(lowerheight - 1, timer);
    }
};