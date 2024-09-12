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
int lent(ListNode* head)
{   int cnt=0;
    while(head!=NULL)
    {   cnt++;
        head=head->next;
    }
    return cnt;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        //Base case
        if(head==NULL)
        return head;
        int len = lent(head);
        int count=0;
        //first step
        ListNode* forward = NULL;
        ListNode* curr = head;
        ListNode*prev = NULL;
        
        while(curr!=NULL && count<k)
        {   
            
                forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward ;
                count++;
            
        }
        if(forward!=NULL && (len-count)>=k)
        {
            head->next = reverseKGroup(forward,k);
        }
        else
        {
            head->next = curr;
        }
      
        return prev;
    }
};
