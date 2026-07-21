/*
 * Problem: Count Complete Tree Nodes
 * Problem ID: 222
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 31.4 MB
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
int  binarytree(TreeNode* root,int &n){
    if(root==nullptr){
        return 0;
    }
    n++;
    binarytree(root->left,n);
    binarytree(root->right,n);
    return n;

}
    int countNodes(TreeNode* root) {
        
       int n=0;
       binarytree(root,n);
       return n;

    }
};