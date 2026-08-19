/*
 * Problem: Merge k Sorted Lists
 * Problem ID: 23
 * Difficulty: Hard
 * Language: C++
 * Runtime: 3 ms
 * Memory: 18.4 MB
 * Synced From: LeetCode
 * Date: 2026-08-19
 */

class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> p;

        // Put the first node of every list into the heap
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                p.push(lists[i]);
            }
        }

        // Dummy node
        ListNode* root = new ListNode(0);
        ListNode* tail = root;

        while (!p.empty()) {

            ListNode* temp = p.top();
            p.pop();

            // Attach smallest node
            tail->next = temp;

            // Move tail forward
            tail = tail->next;

            // Put next node from the same list into heap
            if (temp->next != nullptr) {
                p.push(temp->next);
            }
        }

        return root->next;
    }
};