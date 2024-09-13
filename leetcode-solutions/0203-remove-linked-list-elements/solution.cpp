class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        while (head != NULL && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

   
        ListNode* cur = head;
        ListNode* prev = NULL;
        while (cur != NULL) {
            if (cur->val == val) {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;  
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

