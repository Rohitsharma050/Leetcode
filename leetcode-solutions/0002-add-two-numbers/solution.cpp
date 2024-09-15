/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}  // Default constructor initializing val to 0 and next to nullptr
 *     ListNode(int x) : val(x), next(nullptr) {}  // Constructor initializing val to x and next to nullptr
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}  // Constructor initializing val to x and next to a given node
 * };
 */
class Solution {
public:
    // Function to insert a new node at the tail of the linked list
    ListNode* insertAtTail(ListNode* &tail, int data) {
        ListNode* temp = new ListNode(data);  // Create a new node with the provided data
        
        // Check if the tail is nullptr (i.e., the list is empty)
        if (tail == nullptr) {
            // If empty, set the tail to the new node
            tail = temp;
        } else {
            // If not empty, link the new node to the end of the list
            tail->next = temp;
            tail = temp;  // Update the tail to point to the new node
        }

        return tail;
    }

    // Recursive function to calculate the sum of two linked lists and the carry
    ListNode* getsum(ListNode* l1, ListNode* l2, int carry) {
        // Base case: If both lists are fully processed and no carry is left, return NULL
        ListNode* result = nullptr;
        if (l1 == nullptr && l2 == nullptr && carry == 0) {
            return nullptr;
        }

        int sum = carry;  // Start the sum with the carry value
        
        // Add the value from the first list node (if it exists)
        if (l1 != nullptr) {
            sum += l1->val;
        }
        
        // Add the value from the second list node (if it exists)
        if (l2 != nullptr) {
            sum += l2->val;
        }
        
        // Calculate the current digit and the new carry
        int ans = sum % 10;
        carry = sum / 10;
        
        // Insert the current digit into the result list
        insertAtTail(result, ans);
        
        // Prepare the next pointers for recursion
        ListNode* nextL1 = nullptr;
        ListNode* nextL2 = nullptr;

        // Set the nextL1 to the next node of l1 if it exists
        if (l1 != nullptr) {
            nextL1 = l1->next;
        }

        // Set the nextL2 to the next node of l2 if it exists
        if (l2 != nullptr) {
            nextL2 = l2->next;
        }

        // Recursively call getsum for the next digits and link it to the current result's next pointer
        result->next = getsum(nextL1, nextL2, carry);

        return result;  // Return the result node (head of the result list)
    }

    // Main function that initiates the sum operation of two numbers represented by linked lists
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Call the recursive getsum function, passing the two lists and the initial carry (0)
        return getsum(l1, l2, 0);
    }
};

