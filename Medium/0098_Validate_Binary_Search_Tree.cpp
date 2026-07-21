/*
 * Problem: Validate Binary Search Tree
 * Problem ID: 98
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 21.8 MB
 * Synced From: LeetCode
 * Date: 2026-07-21
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
bool bst(TreeNode* root,long long &prev){
    if(root==nullptr)return 1;
        bool l=bst(root->left,prev);
        if(l==0)return 0;
        if(root->val<= prev)return 0;
        prev=root->val;
       bool r=bst(root->right,prev);
        if(r==0)return 0;
        return 1;

}
    bool isValidBST(TreeNode* root) {
          long long prev = LLONG_MIN;
        return bst(root,prev);
        
    }
};