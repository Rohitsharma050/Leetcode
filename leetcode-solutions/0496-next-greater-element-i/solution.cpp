class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans; // Initialize ans with the same size as nums2 and default value -1
        stack<int> s;
        map<int,int>mpp;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop(); // Pop smaller elements from the stack
            }
            
            if (!s.empty()) {
                mpp[nums2[i]]=s.top();
                //ans[i] = s.top(); // The next greater element is at the top of the stack
            }
            else
            {
                mpp[nums2[i]]=-1;
            } 
            s.push(nums2[i]); // Push the current element to the stack
        }
        for(int x=0;x<nums1.size();x++)
        {
            ans.push_back(mpp[nums1[x]]);
        }
        return ans;
    }
};

