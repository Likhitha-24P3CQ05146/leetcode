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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (curr != nullptr) {
            next = curr->next; //preserve the next node add, so that we can reach
            curr->next = prev; //Replace the current next with prev node address
            prev = curr; //for the nxt node current will be the prev
            curr = next; //move current to the next node to repeat the process
        }

        return prev;
    }
};