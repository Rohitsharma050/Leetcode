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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(-1);
        ListNode* even = new ListNode(-1);
        ListNode* oddhead = odd;
        ListNode* evenhead = even;
        int idx  = 1;
        while(head)
        {
            if(idx&1)
            {
                oddhead->next = head;
                oddhead = oddhead->next;
            }
            else{
                evenhead->next = head;
                evenhead = evenhead->next;
            }
            head = head->next;
            idx++;
        }
        oddhead->next = even->next;
        evenhead->next = NULL;
        return odd->next;
    }
};
