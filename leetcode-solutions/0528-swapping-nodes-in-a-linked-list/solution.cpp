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
    int Size(ListNode* head)
    {
        ListNode* temp=head;
        int sz=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            sz++;
        }
        return sz;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp1=head;
        ListNode* temp2=head;
        int sz=Size(head);
        int m=sz-k+1;
        for(int i=1;i<k;i++)
        {
            temp1=temp1->next;
        }
        for(int i=1;i<m;i++)
        {
            temp2=temp2->next;
        }
        int x=temp1->val;
        temp1->val=temp2->val;
        temp2->val=x;
        return head;
    }
};
