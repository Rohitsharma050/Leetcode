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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* currNode = head;
        ListNode* preNode = NULL;
        while(currNode->next!=NULL)
        {
            preNode=currNode;
            currNode=currNode->next;
            ListNode* temp = new ListNode(gcd(preNode->val,currNode->val));
            temp->next=currNode;
            preNode->next =temp;
        }
        return head;
    }
};
