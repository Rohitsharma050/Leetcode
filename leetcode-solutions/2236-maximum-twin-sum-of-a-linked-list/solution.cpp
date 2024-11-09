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
    int pairSum(ListNode* head) {
        if (!head) return 0;

        // Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list from 'slow' onward
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Calculate the maximum twin sum
        int maxTwinSum = 0;
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;  // Start of reversed second half

        while (secondHalf) {
            int currSum = firstHalf->val + secondHalf->val;
            maxTwinSum = std::max(maxTwinSum, currSum);
            
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return maxTwinSum;
    }
};

