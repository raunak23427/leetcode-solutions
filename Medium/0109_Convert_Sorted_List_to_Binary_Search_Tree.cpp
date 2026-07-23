/*
 * Problem: Convert Sorted List to Binary Search Tree
 * Problem ID: 109
 * Difficulty: Medium
 * Language: C++
 * Runtime: 5 ms
 * Memory: 33.3 MB
 * Synced From: LeetCode
 * Date: 2026-07-23
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
TreeNode *bst(vector<int>&tree,int low,int high){
    if(low>high)return nullptr;
    
    int mid=low+(high-low)/2;
    TreeNode * root=new TreeNode(tree[mid]);
    root->left=bst(tree,low,mid-1);
    root->right=bst(tree,mid+1,high);
    return root;
}
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>tree;
        while(head!=nullptr){
            tree.push_back(head->val);
            head=head->next;
        }
        int low=0;
        int high=tree.size()-1;
        return bst(tree,low,high);
    }
};