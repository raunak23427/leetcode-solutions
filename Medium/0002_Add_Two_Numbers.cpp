/*
 * Problem: Add Two Numbers
 * Problem ID: 2
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 77.1 MB
 * Synced From: LeetCode
 * Date: 2026-10-12
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
class Solution {
public:

    ListNode* reverse(ListNode* l1){
        ListNode *curr = l1, *prev = nullptr, *fut;

        while(curr != nullptr){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

      

        ListNode *curr1 = l1;
        ListNode *curr2 = l2;

        ListNode* head = new ListNode(0);
        ListNode* tail = head;

        int carry = 0;

        while(curr1 != nullptr && curr2 != nullptr){
            int sum = curr1->val + curr2->val + carry;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            curr1 = curr1->next;
            curr2 = curr2->next;

            carry = sum / 10;
        }

        while(curr2 != nullptr){
            int sum = curr2->val + carry;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            curr2 = curr2->next;
            carry = sum / 10;
        }

        while(curr1 != nullptr){
            int sum = curr1->val + carry;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            curr1 = curr1->next;
            carry = sum / 10;
        }

        while(carry != 0){
            tail->next = new ListNode(carry % 10);
            tail = tail->next;  // 🔥 important
            carry /= 10;
        }

         ListNode *temp=head;
        head=temp->next;
        delete temp;
        return head;
    }
};

