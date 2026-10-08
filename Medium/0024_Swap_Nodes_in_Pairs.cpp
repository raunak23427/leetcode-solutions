/*
 * Problem: Swap Nodes in Pairs
 * Problem ID: 24
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 10.9 MB
 * Synced From: LeetCode
 * Date: 2026-10-08
 */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL) {

            ListNode* first = curr;
            ListNode* second = curr->next;

            // connect previous pair to second
            if(prev != NULL)
                prev->next = second;
            else
                head = second;

            // swap
            first->next = second->next;
            second->next = first;

            // move forward
            prev = first;
            curr = first->next;
        }

        return head;
    }
};