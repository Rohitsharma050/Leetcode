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
    ListNode* sortList(ListNode* head) {
        vector<int> tempList;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            tempList.push_back(temp->val);
            temp=temp->next;
        }
        sort(tempList.begin(),tempList.end());
        temp = head;
        for(int i = 0;i<tempList.size();i++){
            temp->val = tempList[i];
            temp = temp->next;
        }
        return head;
    }
};
