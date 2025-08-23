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
int findLength(ListNode* head)
{
    if(head==NULL)
    return 0;
    return 1+findLength(head->next);
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        int len = findLength(head);
        ListNode* curr = head;
        ListNode* forward = NULL;
        ListNode* prev = NULL;
        int cnt =0;
        while(curr && cnt<k )
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            cnt++;
        }
        if(forward!=NULL && (len-cnt)>=k)
        head->next = reverseKGroup(forward,k);
        else{
            head->next = curr;
        }
        return prev;
    }   
};
