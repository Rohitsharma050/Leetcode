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
void reverse(ListNode* &head,ListNode* currNode,ListNode* prev)  
{
        if(currNode == NULL)
        {   head = prev;
            return;
        }
        ListNode* forward = currNode->next;
        reverse(head,forward,currNode);
        currNode->next = prev;

}
    ListNode* doubleIt(ListNode* head) {
       ListNode* currNode=head;
       ListNode* prev= NULL;
       int carry = 0;
       reverse(head,currNode,prev);
        currNode=head;
       while(currNode!=NULL)
       {
            int sum = (currNode->val*2);
            currNode->val = sum%10+carry;
            carry = sum/10;
            prev = currNode;
            currNode = currNode->next;
       } 
       if(carry)
       {
            ListNode* carryNode = new ListNode(carry);
            prev->next = carryNode;
       }
        reverse(head,head,NULL);
        return head;
    }
};
