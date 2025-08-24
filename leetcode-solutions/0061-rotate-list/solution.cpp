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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)
        return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next)
        {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        k = k%len;
        int steps = len-k;
        for(int i = 1;i<=steps;i++)
        {
            tail = tail->next;
        }
        ListNode* newhead = tail->next;
        tail->next = NULL;
        return newhead;
    }
};
