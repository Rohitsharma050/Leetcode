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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL && headB == NULL)
        return NULL;
        map<ListNode* ,bool> check;
        while(headA!=NULL)
        {   //if(check[headA]==true )
        //     {
        //         return headA;
        //     }
            check[headA] = true;

            headA = headA->next;
           // headB = headB->next;

        }
        while(headB!=NULL)
        {
            if(check[headB]==true )
            {
                return headB;
            }
            check[headB] = true;

            headB = headB->next;
        }
        return NULL;
    }
};
