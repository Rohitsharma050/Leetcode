class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newhead = nullptr; // Head of the new list
        ListNode* tail = nullptr;    // Tail of the new list
        int currentSum = 0;          // To store the sum between two zeros
        
        // Start traversing from head->next, as the first node is always 0
        ListNode* temp = head->next;

        while (temp != nullptr) {
            if (temp->val != 0) {
                // Add the value to the current sum if it's not zero
                currentSum += temp->val;
            } else if (currentSum > 0) {
                // When a zero is encountered, and we have a sum, add it to the new list
                ListNode* newNode = new ListNode(currentSum);
                
                // If newhead is null, initialize it
                if (newhead == nullptr) {
                    newhead = newNode;
                    tail = newhead;
                } else {
                    // Otherwise, add to the tail
                    tail->next = newNode;
                    tail = newNode;
                }
                
                // Reset the current sum after adding it to the new list
                currentSum = 0;
            }

            // Move to the next node
            temp = temp->next;
        }

        return newhead;
    }
};

