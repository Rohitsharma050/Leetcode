class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
        int i=0;
        int mid = n;
        while(i<n && mid<2*n)
        {
            ans.push_back(nums[i++]);
            ans.push_back(nums[mid++]);
        }
        return ans;
    }
};
