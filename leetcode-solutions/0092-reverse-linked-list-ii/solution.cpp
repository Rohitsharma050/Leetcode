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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // If left and right are the same, no need to reverse
        if (left == right) {
            return head;
        }

        // Dummy node to simplify edge cases where reversal starts at the head
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        // Set up pointers to find the `left` position
        ListNode* leftPrev = dummy; // The node before `left` position
        for (int i = 1; i < left; ++i) {
            leftPrev = leftPrev->next;
        }

        // `curr` starts at the `left` position and will be reversed up to `right`
        ListNode* curr = leftPrev->next;
        ListNode* prev = nullptr;

        // Reverse the sublist between `left` and `right`
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode* next = curr->next; // Temporarily store the next node
            curr->next = prev;           // Reverse the link
            prev = curr;                 // Move `prev` forward
            curr = next;                 // Move `curr` forward
        }

        // Connect the end of the reversed sublist to the rest of the list
        leftPrev->next->next = curr; // The `left` node's `next` should point to `curr`
        leftPrev->next = prev;       // Connect `leftPrev` to the `prev` node (new head of reversed part)

        return dummy->next; // Return the new head of the modified list
    }
};

