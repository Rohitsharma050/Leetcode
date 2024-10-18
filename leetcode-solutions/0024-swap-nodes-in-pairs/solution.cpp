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
 /*   // Recursive helper function to swap nodes in pairs
    ListNode* getAnswer(ListNode* curr, ListNode* forward) {
        // Base case: if we reach the end of the list or there's no pair to swap
        if (curr == NULL || forward == NULL) {
            return curr;
        }

        // Save the next pair's starting node
        ListNode* nextpair = forward->next;

        // Reverse the current pair: point the second node (forward) to the first node (curr)
        forward->next = curr;

        // Recursively process the next pairs and link them to the current pair
        curr->next = getAnswer(nextpair, nextpair ? nextpair->next : nullptr);

        // Return the new head of the swapped pair, which is the second node of the current pair
        return forward;
    }*/

    // Function to initiate the swap operation for the linked list
    ListNode* swapPairs(ListNode* head) {
       /* // If the list is empty or has only one node, no swapping is needed
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Initialize the two pointers for the first pair to be swapped
        ListNode* curr = head;            // The first node of the pair
        ListNode* forward = head->next;   // The second node of the pair

        // Call the recursive function to swap pairs and return the new head of the list
        return getAnswer(curr, forward);*/
          if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* forward = head->next;
        ListNode* nextpair = head->next->next;
        head->next = swapPairs(nextpair);
        forward->next = head;
        return forward;

    }
};

