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
ListNode* solve(ListNode* curr,ListNode* forward)
{
    if(curr==NULL || forward==NULL)
    {
        return curr; 
    }
    ListNode* nextpair = forward->next;
    forward->next = curr;
    curr->next = solve(nextpair,nextpair?nextpair->next:nullptr);
    return forward;
}
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* curr = head;
        ListNode* forward = head->next;
        
        return solve(curr,forward);
    }
};
