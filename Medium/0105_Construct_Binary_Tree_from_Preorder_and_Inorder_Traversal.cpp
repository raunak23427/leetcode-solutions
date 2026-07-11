/*
 * Problem: Construct Binary Tree from Preorder and Inorder Traversal
 * Problem ID: 105
 * Difficulty: Medium
 * Language: C++
 * Runtime: 11 ms
 * Memory: 27.1 MB
 * Synced From: LeetCode
 * Date: 2026-07-11
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
int find(vector<int>&inorder,int target,int start,int end){
    for(int i=start;i<=end;i++){
        if(inorder[i]==target){
            return i;
        }
    }
    return -1;
}
TreeNode * tree(vector<int>&preorder,vector<int>&inorder,int start,int end,int index){
    if(start>end){
        return nullptr;
    }
    TreeNode *temp=new TreeNode(preorder[index]);
    int pos=find(inorder,preorder[index],start,end);
    temp->left=tree(preorder,inorder,start,pos-1,index+1);
    temp->right=tree(preorder,inorder,pos+1,end,index+(pos-start)+1);
    return temp;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start=0;
        int end =inorder.size()-1;
        int index=0;
        TreeNode* root =tree(preorder,inorder,start,end,index);
        return root;
    }
};