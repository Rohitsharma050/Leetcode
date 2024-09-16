/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
        return NULL;
        map< ListNode* ,bool> check;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            if(check[temp]==true)
            {
                return temp;
            }
            check[temp] = true;
            temp=temp->next;
        }
        return NULL;
    }
};
