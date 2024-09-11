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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
        //ListNode* forward = NULL;
        ListNode* prev = NULL;
        ListNode* currNode = head;
        reverse(head,currNode,prev);
       /* while(currNode!=NULL)
        {
            forward = currNode->next;
            
            currNode->next = prev;
            prev = currNode;
            currNode = forward;
        }*/

        return head;
    }
    
};
