class Solution {
public:
    void insertAtTail(ListNode* &ans, ListNode* &tail, int val) {
        ListNode* temp = new ListNode(val);
        if (tail == NULL) {
            ans = temp;
            tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Correcting the condition here
        if (list1 == NULL && list2 == NULL)  // Check if both lists are NULL
            return NULL;
        
        if (list1 == NULL)  // If list1 is NULL, return list2
            return list2;
        
        if (list2 == NULL)  // If list2 is NULL, return list1
            return list1;
        
        ListNode* ans = NULL;
        ListNode* tail = ans;

        // Merging the two lists
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                insertAtTail(ans, tail, list1->val);
                list1 = list1->next;
            } else {
                insertAtTail(ans, tail, list2->val);
                list2 = list2->next;
            }
        }

        // If list1 still has remaining elements
        while (list1 != NULL) {
            insertAtTail(ans, tail, list1->val);
            list1 = list1->next;
        }

        // If list2 still has remaining elements
        while (list2 != NULL) {
            insertAtTail(ans, tail, list2->val);
            list2 = list2->next;
        }

        return ans;
    }
};

