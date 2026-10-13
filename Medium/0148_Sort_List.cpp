/*
 * Problem: Sort List
 * Problem ID: 148
 * Difficulty: Medium
 * Language: C++
 * Runtime: 48 ms
 * Memory: 75.8 MB
 * Synced From: LeetCode
 * Date: 2026-10-13
 */


class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (a != NULL && b != NULL) {
            if (a->val <= b->val) {
                curr->next = a;
                a = a->next;
            } else {
                curr->next = b;
                b = b->next;
            }

            curr = curr->next;
        }

        if (a != NULL)
            curr->next = a;

        if (b != NULL)
            curr->next = b;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(second);

        return merge(left, right);
    }
};
