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
    ListNode* partition(ListNode* head, int x) {
        // Create two dummy nodes for two partitions
        ListNode* smallListHead = new ListNode(-1); // List to store nodes with values less than x
        ListNode* largeListHead = new ListNode(-1); // List to store nodes with values greater than or equal to x

        // Pointers to traverse both partition lists
        ListNode* smallListPtr = smallListHead; 
        ListNode* largeListPtr = largeListHead;

        // Traverse the original list
        while (head) {
            // If the current node's value is less than x, add it to the small list
            if (head->val < x) {
                smallListPtr->next = head;          // Link the current node to the small list
                smallListPtr = smallListPtr->next;  // Move the pointer to the next node in the small list
            } 
            // Otherwise, add it to the large list
            else {
                largeListPtr->next = head;          // Link the current node to the large list
                largeListPtr = largeListPtr->next;  // Move the pointer to the next node in the large list
            }
            head = head->next; // Move to the next node in the original list
        }

        // Connect the small list with the large list
        smallListPtr->next = largeListHead->next;
        
        // Ensure the end of the large list points to null to avoid a circular reference
        largeListPtr->next = nullptr;

        // Return the partitioned list starting from the first node in the small list (after the dummy node)
        return smallListHead->next;
    }
};

