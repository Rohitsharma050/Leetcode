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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* ans = dummyNode;
        unordered_map<int,int>mp;
        for(int i= 0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        ListNode* temp = head;
        while(temp)
        {
            if(mp.find(temp->val)==mp.end())
            {
                dummyNode->next = temp;
                dummyNode = dummyNode->next;
            }
            temp = temp->next;
        }
        dummyNode->next=NULL;
        return ans->next;

    }
};
