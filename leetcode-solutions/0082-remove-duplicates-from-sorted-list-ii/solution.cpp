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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;  // If the list is empty or has only one node, return as is
        }
        
        // Use a dummy node to handle edge cases where the head itself is part of duplicates
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;  // The node before the current sequence of possible duplicates
        ListNode* curr = head;   // Current node we're checking for duplicates
        
        while (curr != nullptr) {
            // Check if we have a duplicate sequence
            if (curr->next != nullptr && curr->val == curr->next->val) {
                // Skip all nodes with the same value
                while (curr->next != nullptr && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                // Move prev's next to skip over the entire sequence of duplicates
                prev->next = curr->next;
            } else {
                // No duplicates, move prev to the current node
                prev = curr;
            }
            curr = curr->next;  // Move to the next node
        }
        
        return dummy->next;  // Return the updated list (skip dummy node)
    }
};

