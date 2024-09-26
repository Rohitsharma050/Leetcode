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
std::vector<int> findMinMaxDifference(const std::vector<int>& position) {
    if (position.size() < 2) {
            return {-1, -1};  // If there are fewer than two critical points
        }
    vector<int>ans;
    // Find maximum difference
    int max_diff = *max_element(position.begin(), position.end()) - *min_element(position.begin(), position.end());
    
    // Sort the vector to find minimum difference
    std::vector<int> sorted_position = position; // Copy the original vector to avoid modifying it
    std::sort(sorted_position.begin(), sorted_position.end());

    // Find minimum difference by comparing adjacent elements
    int min_diff = INT_MAX;
    for (size_t i = 0; i < sorted_position.size() - 1; ++i) {
        int diff = abs(sorted_position[i+1] - sorted_position[i]);
        min_diff = std::min(min_diff, diff);
    }
    ans.push_back(min_diff);
    ans.push_back(max_diff);
    // Return a vector containing both min_diff and max_diff
    return ans;
}
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        if(head->next->next==NULL)
        return {-1,-1};
        ListNode* curr = head->next;
        ListNode* prev=head;
        int count = 2;
        vector<int> position;
        // static int first;
        while(curr->next!=NULL)
        {
            if(((curr->val<curr->next->val && curr->val<prev->val) || (curr->val>curr->next->val && curr->val>prev->val) ) && curr->next!=NULL)
            {
                position.push_back(count);
            }
            count++;
            curr=curr->next;
            prev = prev->next;
        }
        ans = findMinMaxDifference(position);
        if(ans.size()<2)
        return {-1,-1};
        else
        return ans;

    }
};
