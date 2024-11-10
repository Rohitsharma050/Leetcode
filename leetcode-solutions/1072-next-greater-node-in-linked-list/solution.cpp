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
    // Helper function to reverse the linked list
    ListNode* reversel(ListNode* reverseList) {
        ListNode* curr = reverseList;
        ListNode* prev = NULL;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> ans;

        // Reverse the list to process it from the end
        ListNode* reverseList = reversel(head);

        // Traverse the reversed list
        while (reverseList) {  
            // Remove elements from the stack that are not greater than the current node value
            while (!st.empty() && st.top() <= reverseList->val) {
                st.pop();
            }

            // If stack is empty, no greater element exists
            if (st.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(st.top());
            }

            // Push the current value onto the stack
            st.push(reverseList->val);

            // Move to the next node in the reversed list
            reverseList = reverseList->next;
        }

        // Reverse the answer vector to get results in the original order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

