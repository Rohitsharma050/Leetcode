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
int getLen(ListNode* head)
{
    int cnt = 0;
    while(head!=NULL)
    {
        cnt++;
        head= head->next;
    }
    return cnt;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next ==NULL && n==0)
        {
            return head;
        }
        if(head->next == NULL && n==1)
        {
            return NULL;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        int cnt = 0;
        int len = getLen(head);
        while(cnt<(len-n))
        {   
            prev=curr; 
            curr = curr->next;
           
            cnt++;

        }
        if(cnt==0)
        {
            curr=head->next;
            delete head;
            return curr;
        }
        prev->next = curr->next;
        delete curr;
        return head;

    }
};
