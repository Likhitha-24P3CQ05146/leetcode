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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // Find middle
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse second half
        ListNode* prev = NULL;
        while(slow != NULL) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        // Compare both halves
        ListNode* first = head;
        ListNode* second = prev;
        while(second != NULL) {
            if(first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};
